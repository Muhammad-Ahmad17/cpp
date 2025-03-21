/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-11-16.  
           
  TIME: 12:52 AM.
*/
#include <iostream>
#include <queue>
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
void printPreorder(Node* root) {
    if (root == nullptr) return;
    cout << char(root->data) << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << char(root->data) << " ";
    printInorder(root->right);
}
void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);  // Push root node into the queue

    while (!q.empty()) {
        Node* current = q.front();  // Get the front element of the queue
        cout << char (current->data) << " "; // Print the data of the current node
        q.pop();  // Remove the node from the queue

        // Push left and right children into the queue
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
}
int findIndex(string str,char ch){
    for (int i = 0; i < str.size() ; ++i) {
        if (str[i]==ch){
            return i;
        }
    }
    return -1;
}

Node* buildTree(string inorder,string preorder, int& index_preorder){
    if (index_preorder >= preorder.size()) {
        return nullptr;
    }
    Node* mintre = new Node(preorder[index_preorder]);
    int findingMid= findIndex(inorder,preorder[index_preorder]);
    index_preorder++;

    mintre->left=buildTree(inorder.substr(0, findingMid),preorder,index_preorder);
    mintre->right=buildTree(inorder.substr(findingMid + 1),preorder,index_preorder);

    return mintre ;
}

int main(){
// Example inorder and preorder traversal of a binary tree
    string inorder = "A+B*C";
    string preorder = "+A*BC";

    int index_preorder = 0;

    // Build the tree
    Node* root = buildTree(inorder, preorder, index_preorder);

    // Print the tree traversals
    cout << "Preorder Traversal: ";
    printPreorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    printInorder(root);
    cout << endl;

    cout << "level order Traversal: ";
   levelOrderTraversal(root);
    cout << endl;

    return 0;
}




