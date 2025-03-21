#include "iostream"
#include "queue"
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

class BinaryTree {
public:
    Node* node;
    BinaryTree() : node(nullptr) {}

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

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void levelOrderTraversal(Node* root) {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);
        q.push(nullptr);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp == nullptr) {
                cout << endl;
                if (!q.empty()) {
                    q.push(nullptr);
                }
            } else {
                cout << temp->data << " ";
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
    }

    void buildFromLevelOrder(Node*& root) {
        queue<Node*> q;
        cout << "Enter data for root: ";
        int data;
        cin >> data;
        root = new Node(data);
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            cout << "Enter left node for " << temp->data << " (-1 for no left child): ";
            int leftData;
            cin >> leftData;
            if (leftData != -1) {
                temp->left = new Node(leftData);
                q.push(temp->left);
            }

            cout << "Enter right node for " << temp->data << " (-1 for no right child): ";
            int rightData;
            cin >> rightData;
            if (rightData != -1) {
                temp->right = new Node(rightData);
                q.push(temp->right);
            }
        }
    }
};

int main() {
    BinaryTree bt;
    Node* root = nullptr;

    cout << "Choose an operation:\n";
    cout << "1. Insert elements into the Binary Tree\n";
    cout << "2. Inorder Traversal\n";
    cout << "3. Preorder Traversal\n";
    cout << "4. Postorder Traversal\n";
    cout << "5. Level Order Traversal\n";
    cout << "6. Build Tree from Level Order Input\n";
    cout << "0. Exit\n";

    int choice;
    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter values to insert into the tree (-1 to stop): ";
                while (true) {
                    cin >> val;
                    if (val == -1) break;
                    root = bt.insert(val, root);
                }
                break;
            }

            case 2:
                cout << "Inorder Traversal: ";
                bt.inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder Traversal: ";
                bt.preorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder Traversal: ";
                bt.postorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Level Order Traversal:\n";
                bt.levelOrderTraversal(root);
                cout << endl;
                break;

            case 6:
                cout << "Build tree using Level Order Input:\n";
                bt.buildFromLevelOrder(root);
                cout << "Level Order Traversal of the constructed tree:\n";
                bt.levelOrderTraversal(root);
                cout << endl;
                break;

            case 0:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
