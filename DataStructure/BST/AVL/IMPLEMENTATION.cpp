/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-12-07.  
           
  TIME: 9:12 PM.
*/
#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

// Node structure for AVL Tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Function to get the height of a node
int height(Node* n) {
    return n ? n->height : 0;
}

// Function to create a new node
Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1; // New node is initially added at height 1
    return node;
}

// Function to get the balance factor of a node
int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // New root
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // New root
}

// Insert a key into the AVL tree
Node* insert(Node* node, int key) {
    if (!node)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in AVL Tree
        return node;

    // Update height of this node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor
    int balance = getBalance(node);

    // Balance the tree if needed
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // Return unchanged node pointer
}

// In-order traversal to verify the tree
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// Level-order traversal to display tree structure
void displayTree(Node* root) {
    if (!root) {
        cout << "Tree is empty.\n";
        return;
    }

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        while (levelSize--) {
            Node* node = q.front();
            q.pop();
            if (node) {
                cout << setw(4) << node->key << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "   - ";
            }
        }
        cout << endl;
    }
}

// Menu-driven main
int main() {
    Node* root = nullptr;
    int choice, key;

    do {
        cout << "\n--- AVL Tree Menu ---\n";
        cout << "1. Insert a key\n";
        cout << "2. Display tree (level-order)\n";
        cout << "3. In-order traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the key to insert: ";
                cin >> key;
                root = insert(root, key);
                cout << "Tree after insertion:\n";
                displayTree(root);
                break;
            case 2:
                cout << "Tree (level-order display):\n";
                displayTree(root);
                break;
            case 3:
                cout << "In-order traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
// 50,30,80,25,40,98,55,52,58,70,65,48,110,85