#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class NODE
{
public:
    NODE(int new_data)
    {
        left = nullptr;
        right = nullptr;
        data = new_data;
    }
    int data;
    NODE *left;
    NODE *right;
};

bool add_node(NODE **currentnode, int new_data)
{
    if (*currentnode == nullptr)
    {
        *currentnode = new NODE(new_data);
        return true;
    }
    else
    {
        if (new_data < (*currentnode)->data)
        {
            add_node(&((*currentnode)->left), new_data);
        }
        else if (new_data > (*currentnode)->data)
        {
            add_node(&((*currentnode)->right), new_data);
        }
    }
    return false; // Data already exists
}

void preorder(NODE *node)
{
    if (node != nullptr)
    {
        cout << node->data << ","; // center
        preorder(node->left);      // left
        preorder(node->right);     // right
    }
}

void inorder(NODE *node)
{
    if (node != nullptr)
    {
        inorder(node->left);       // left
        cout << node->data << ","; // center
        inorder(node->right);      // right
    }
}

void postorder(NODE *node)
{
    if (node != nullptr)
    {
        postorder(node->left);     // left
        postorder(node->right);    // right
        cout << node->data << ","; // center
    }
}

void BreadthFirst(NODE *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<NODE *> q;
    q.push(root);

    while (!q.empty())
    {
        int level_size = q.size();
        for (int i = 0; i < level_size; ++i)
        {
            NODE *node = q.front();
            q.pop();
            cout << node->data << ",";
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
        cout << "|";
    }
}

NODE *find_maximum(NODE *node)
{
    while (node && node->left != nullptr)
    {
        node = node->left;
    }
    return node;
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
        { // Node with no child
            return nullptr;
        }
        // Node with only one child
        else if (root->left == nullptr)
        {
            NODE *temp = root->right;
            return temp;
        }
        else if (root->right == nullptr)
        {
            NODE *temp = root->left;
            return temp;
        }

        // Node with two children: Get the largest node in the left subtree
        NODE *temp = find_maximum(root->right);
        root->data = temp->data;                            // Copy value in the node
        root->right = delete_node(root->right, temp->data); // Delete the inorder predecessor
    }

    return root;
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
            add_node(&root, data);
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
        else if (cmd == 'i')
        {
            inorder(root);
            cout << endl;
        }
        else if (cmd == 't')
        {
            postorder(root);
            cout << endl;
        }
        else if (cmd == 'b')
        {
            BreadthFirst(root);
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