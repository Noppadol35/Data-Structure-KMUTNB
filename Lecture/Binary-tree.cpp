#include <iostream>
using namespace std;

class NODE {
public:
    NODE(int new_data) {
        left = nullptr;  // Use nullptr instead of NULL
        right = nullptr; // Use nullptr instead of NULL
        data = new_data;
    }
    int data;
    NODE *left;
    NODE *right;
};

bool add_node(NODE **currentnode, int new_data) {
    if (*currentnode == nullptr) {
        *currentnode = new NODE(new_data);
        cout << "Create new node " << new_data << endl<< endl;
        return true;
    }
    else {
        if (new_data < (*currentnode)->data) {
            cout << "Move " << new_data << " to the left of " << (*currentnode)->data << endl;
            add_node(&((*currentnode)->left), new_data);
        }
        else if (new_data > (*currentnode)->data) {
            cout << "Move " << new_data << " to the right of " << (*currentnode)->data << endl;
            add_node(&((*currentnode)->right), new_data);
        }
    }
    return false; // Data already exists
}

void preorder(NODE *node) {
    if (node != nullptr) {
        cout << node->data << " "; //center
        preorder(node->left); // left
        preorder(node->right); // right
    }
}

void inorder(NODE *node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void postorder(NODE *node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

bool search(NODE *node, int new_data) {
    if (node != nullptr) {
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

NODE* find_maximum(NODE* node) {
    while (node && node->right != nullptr) {
        node = node->right;
    }
    return node;
}

NODE* delete_node(NODE* root, int data) {
    if (root == nullptr) {
        return root; // Tree is empty
    }

    // Traverse the tree to find the node to delete
    if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    }
    // Found the node to be deleted  (data == root->data)
    else {
        if (root->left == nullptr && root->right == nullptr) {// Node with no child
            return nullptr;
        }
        // Node with only one child
        else if (root->left == nullptr) {
            NODE* temp = root->right;
            return temp;
        }
        else if (root->right == nullptr) {
            NODE* temp = root->left;
            return temp;
        }

        // Node with two children: Get the largest node in the left subtree
        NODE* temp = find_maximum(root->left);
        root->data = temp->data; // Copy value in the node
        root->left = delete_node(root->left, temp->data); // Delete the inorder predecessor
    }

    return root;
}

int main (){
    NODE *root = nullptr;
    add_node(&root, 64);
    add_node(&root, 35);
    add_node(&root, 111);
    add_node(&root, 67);
    add_node(&root, 10);
    add_node(&root, 20);
    add_node(&root, 60);
    add_node(&root, 30);
    add_node(&root, 70);
    add_node(&root, 40);
    add_node(&root, 50);

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Search 20: ";
    if (search(root, 20)) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "Search 100: ";
    if (search(root, 100)) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "Delete 20" << endl;
    root = delete_node(root, 20);
    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Delete 30" << endl;
    root = delete_node(root, 30);
    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Delete 50" << endl;
    root = delete_node(root, 50);
    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}