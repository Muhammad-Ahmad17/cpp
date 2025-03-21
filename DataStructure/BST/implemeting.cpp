#include "iostream"
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* insert(int val, Node* node) {
        if (node == nullptr) {
            return new Node(val);
        } else if (node->data < val) {
            node->right = insert(val, node->right);
        } else {
            node->left = insert(val, node->left);
        }
        return node;
    }

    void insert(int val) {
        root = insert(val, root); // Insert into the root
    }

    // Optional: To display the tree in-order for testing
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
// -------------------------------------------------------------
    int smallestInBST(Node* node) {  // pass root in actual
        Node *temp = node;
        for (; temp->left != nullptr; temp = temp->left) {

        }
        return temp->data;
    }
// -------------------------------------------------------------
    int largestInBST(Node* node) {  // pass root in actual
        Node *temp = node;
        for (; temp->right != nullptr; temp = temp->right) {

        }
        return temp->data;
    }
// -------------------------------------------------------------
    int noOfLeaveNodes(Node* node){
        if(!node){
            return 0;
        }
        if(!node->left && !node->right){
            return 1;
        }
        return noOfLeaveNodes(node->left) + noOfLeaveNodes(node->right);
    }
// -------------------------------------------------------------
    int noOfNodes(Node* node){
        if (!node){
            return 0;
        }
        return 1 + noOfNodes(node->left)+noOfNodes(node->right);
    }
// -------------------------------------------------------------
    bool isAvailable (Node* node,int x){
        if(!node){
            return false;
        }
        if(node->data == x){
            return true;
        } else if ( node->data < x) {
            return isAvailable(node->right,x);
        } else {
            return isAvailable(node->left,x);
        }
    }
// -------------------------------------------------------------
    int heightOfTree (Node* node){
        if(!node){return 0;}
        return 1 +( max((heightOfTree(node->left)), (heightOfTree(node->right))));
    }
// -------------------------------------------------------------
    Node* deleteNode(Node* root, int key) {
        if (!root) return nullptr; // Base case: Node not found

        if (key < root->data) {
            root->left = deleteNode(root->left, key); // Traverse left
        } else if (key > root->data) {
            root->right = deleteNode(root->right, key); // Traverse right
        } else {
            // Node to delete found
            if (!root->left && !root->right) {
                delete root;
                return nullptr; // No child case
            } else if (!root->left || !root->right) {
                Node* temp = (root->left ? root->left : root->right); // if root.left hay then root.left ni to root.right
                delete root;
                return temp;
            } else {
                Node* successor = findMin(root->right); // Two children: Find successor
                root->data = successor->data; // Copy successor's data
                root->right = deleteNode(root->right, successor->data); // Delete successor
            }
        }
        return root;
    }
    // Helper to find the minimum value root in a tree (used for two-child case)
    Node* findMin(Node* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

// -------------------------------------------------------------

    void display() {
        inorder(root); // Start with root
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    tree.insert(21);
    tree.insert(1);


    cout << "In-order traversal: ";
    tree.display();  // To verify the tree structure
    cout << "min val in BST ";
    cout << tree.smallestInBST(tree.root);  // To verify the tree structure
    cout << "\nmax val in BST ";
    cout << tree.largestInBST(tree.root);  // To verify the tree structure

    cout << "\nno of nodes in tree ";
    cout << tree.noOfNodes(tree.root);  // To verify the tree structure

    cout << "\nno of leave nodes in tree ";
    cout << tree.noOfLeaveNodes(tree.root);  // To verify the tree structure

    cout << "\nis present in tree ";
    cout << tree.isAvailable(tree.root,70);  // To verify the tree structure

    cout << "\nheight tree ";
    cout << tree.heightOfTree(tree.root);  // To verify the tree structure

    cout << "\ndelete node";
    tree.deleteNode(tree.root,20);  // To verify the tree structure
    cout << "In-order traversal: ";
    tree.display();
    return 0;
}
