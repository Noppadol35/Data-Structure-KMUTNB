#include <iostream>
using namespace std;

class NODE
{
public:
    NODE(int new_data)
    {
        left = nullptr;  // Use nullptr instead of NULL
        right = nullptr; // Use nullptr instead of NULL
        data = new_data;
        height = 1;
    }
    int data;
    int height;
    NODE *left;
    NODE *right;
};

int height(NODE *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

void preorder(NODE *node)
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(NODE *node)
{
    if (node != nullptr)
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void postorder(NODE *node)
{
    if (node != nullptr)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

bool search(NODE *node, int new_data)
{
    if (node != nullptr)
    {
        cout << "# ";
        if (new_data > node->data)
            return search(node->right, new_data);
        else if (new_data < node->data)
            return search(node->left, new_data);
        else
            return true; // Found
    }
    return false; // Not found
}

NODE *find_maximum(NODE *node)
{
    while (node && node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}

NODE *find_minimum(NODE *node)
{
    while (node && node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

NODE *right_rotate(NODE *y)
{
    NODE *x = y->left;
    NODE *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

NODE *left_rotate(NODE *x)
{
    NODE *y = x->right;
    NODE *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int get_balance(NODE *node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

NODE *balance_tree(NODE *node)
{
    int balance = get_balance(node);

    if (balance > 1 && get_balance(node->left) >= 0) // Left Case
        return right_rotate(node);

    if (balance < -1 && get_balance(node->right) <= 0) // Right Case
        return left_rotate(node);

    if (balance > 1 && get_balance(node->left) < 0)
    { // Left-Right Case
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (balance < -1 && get_balance(node->right) > 0)
    { // Right-Left Case
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

NODE *add_node(NODE *node, int new_data)
{
    if (node == nullptr)
        return new NODE(new_data);

    if (new_data < node->data) // move to the left
        node->left = add_node(node->left, new_data);
    else if (new_data > node->data) // move to the right
        node->right = add_node(node->right, new_data);
    else
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;
    return balance_tree(node);
}

NODE *delete_node(NODE *root, int data)
{
    if (root == nullptr)
    {
        return root; // Tree is empty
    }

    // Traverse the tree to find the node to delete
    if (data < root->data)
    {
        root->left = delete_node(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete_node(root->right, data);
    }
    // Found the node to be deleted  (data == root->data)
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {                // Node with no child
            delete root; // Deallocate memory
            return nullptr;
        }
        else if (root->left == nullptr)
        { // Node with only right child
            NODE *temp = root->right;
            delete root; // Deallocate memory
            return temp;
        }
        else if (root->right == nullptr)
        { // Node with only left child
            NODE *temp = root->left;
            delete root; // Deallocate memory
            return temp;
        }

        // Node with two children: Get the largest node in the left subtree
        NODE *temp = find_minimum(root->right);
        root->data = temp->data;                            // Copy value to the current node
        root->right = delete_node(root->right, temp->data); // Delete the inorder predecessor
    }
    return balance_tree(root);
}

void command()
{
    NODE *root = nullptr;
    char cmd;
    int data;

    while (true)
    {
        cin >> cmd;
        if (cmd == 'a')
        {
            cin >> data;
            root = add_node(root, data);
        }
        else if (cmd == 'd')
        {
            cin >> data;
            root = delete_node(root, data);
        }
        else if (cmd == 'p')
        {
            preorder(root);
            cout << endl;
        }
        else if (cmd == 'x')
        {
            break;
        }
    }
}

int main()
{
    command();
    return 0;
}