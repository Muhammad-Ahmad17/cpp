/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-12-30.  
           
  TIME: 6:16 PM.
*/
#include <iostream>
using namespace std;
class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->left= nullptr;
        this->data=val;
        this->right= nullptr;
    }
};
class BinaryTree{
public:
    TreeNode* root;
    BinaryTree(TreeNode *root) : root(nullptr) {}
    /* INSERTION */
    TreeNode* insert(int val , TreeNode* root){
        if(root== nullptr) {
            return new TreeNode(val);
        }else if (root->data>val){
            root->left = insert(val,root->left);
        } else {
            root->right = insert(val, root->right);
        }
        return root;
    }
    /* TRAVERSALS */
    void inOrderTraversal(TreeNode* root){
        if(!root){
            return;
        }
        inOrderTraversal(root->left);
        cout << root->data << "\n";
        inOrderTraversal(root->right);
    }
    void preOrderTraversal(TreeNode* root){
        if(!root){
            return;
        }
        cout << root->data << "\n";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    void postOrderTraversal(TreeNode* root){
        if(!root){
            return;
        }
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << "\n";
    }
    /* Search */
    bool search(TreeNode* root, int toFind) {
        if(!root) return false;
        if(root->data == toFind){
            return true;
        } else if (root->data > toFind){
            return search(root->left, toFind);
        } else {
            return search(root->right, toFind);
        }
    }
    /* TOTAL NODES IN BST*/
    int noOfNodes(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+ noOfNodes(root->left)+noOfNodes(root->right);
    }
    /* HEIGHT*/
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+ max(height(root->left),height(root->right));
    }
    /* TOTAL leaves NODES IN BST*/
    int noOfLeavesNodes(TreeNode* root){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        return noOfLeavesNodes(root->left)+noOfLeavesNodes(root->right);
    }
    /* MIN NODE */
    // iterative
    int min1Node(TreeNode* root){
        TreeNode* temp= root;
        while(temp->left){
            temp= temp->left;
        }
        return temp->data;
    }
    // recursive
    int minNode(TreeNode* root){
        if(!root) return -1;
        if(root->left==NULL){
            return root->data;
        }
        return minNode(root->left);
    }
    /* MAX NODE */
    // iterative
    int max1Node(TreeNode* root){
        TreeNode* temp= root;
        while(temp->right){
            temp= temp->right;
        }
        return temp->data;
    }
    // recursive
    int maxNode(TreeNode* root){
        if(!root) return -1;
        if(root->right==NULL){
            return root->data;
        }
        return maxNode(root->right);
    }
    /* DELETE IN BST*/
    void deleteNode(TreeNode*& root, int key) {
        if (!root) return; // Base case: Node not found

        if (key < root->data) {
             deleteNode(root->left, key); // Traverse left
        } else if (key > root->data) {
            deleteNode(root->right, key); // Traverse right
        } else {
            //no child
            if(!root->left && !root->right){
                delete root;
                root = nullptr;
            }
            //one child
            else if(!root->left || !root->right){
                TreeNode *temp = (root->right ? root->right : root->left);
                delete root;
                root = temp;
            }
            //two child
            else {
                int temp1 = maxNode(root->left);
                root->data = temp1;
                deleteNode(root->left, temp1);
            }
        }
    }
    /*Construction of Binary tree with In-order & Post-order*/
    int findIndex(string str,char ch){
        for (int i = 0; i < str.size() ; ++i) {
            if (str[i]==ch){
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTree(string inorder,string preorder, int& index_preorder){
        if (index_preorder >= preorder.size()) {
            return nullptr;
        }
        TreeNode* mintre = new TreeNode(preorder[index_preorder]);
        int findingMid= findIndex(inorder,preorder[index_preorder]);
        index_preorder++;

        mintre->left=buildTree(inorder.substr(0, findingMid),preorder,index_preorder);
        mintre->right=buildTree(inorder.substr(findingMid + 1),preorder,index_preorder);

        return mintre ;
    }

};
int main (){
    TreeNode* root= nullptr;
    BinaryTree BT(root);
    root = BT.insert(12,root);
    root = BT.insert(9,root);
    root = BT.insert(10,root);
    root = BT.insert(6,root);
    root = BT.insert(36,root);
    root = BT.insert(23,root);
    root = BT.insert(45,root);
    root = BT.insert(55,root);



//    BT.inOrderTraversal(root);
//    BT.postOrderTraversal(root);
    BT.preOrderTraversal(root);

//    cout << BT.search(root,5);
//    cout << BT.search(root,6);
//    cout << BT.search(root,8);

//    cout << BT.noOfNodes(root);

//    cout << BT.height(root);

//    cout << BT.noOfLeavesNodes(root);

//    cout << BT.minNode(root);
//    cout << BT.maxNode(root);
    BT.deleteNode(root,12);

    cout << endl;
    BT.preOrderTraversal(root);

    return 0;
}