#include <bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};


class BST{
public:
    Node *root;

    BST(){
        root = nullptr;
    }

    Node* insert(Node *root, int x){
        if(!root)
            root = new Node(x);
        else if(root->data<x)
            root->right = insert(root->right,x);
        else
            root->left = insert(root->left,x);
        return root;
    }

    Node* search(Node *root, int x){
        if(!root)
            return nullptr;
        if(root->data == x)
            return root;
        if(root->data < x)
            return search(root->right,x);
        return search(root->left,x);
    }

    Node* deleteNode(Node *root, int x){
        if(!root)
            return root;
        if(root->data < x)
            root->right = deleteNode(root->right,x);
        else if(root->data > x)
            root->left = deleteNode(root->left,x);
        else{
            if(!root->left && !root->right)
                return nullptr;
            else if(!root->left)
                return root->right;
            else if(!root->right)
                return root->left;
            else{
                // delete the node and insert the max value from the left sub-tree and deleting the max value
                // int x = findMax(root->left);
                // root->data = x;
                // root->left = deleteNode(root->left,x);

                // delete the node and insert the min value from the right sub-tree and deleting the min value
                int x = findMin(root->right);
                root->data = x;
                root->right = deleteNode(root->right,x);
            }
        }
        return root;
    }

    void insert(int x){
        root = insert(root,x);
    }

    bool search(int x){
        Node *node = search(root,x);
        return node!=nullptr;
    }

    bool deleteNode(int x){
        Node *node = search(root,x);
        if(!node){
            cerr<<x<<" does not exist in BST\n";
            return false;
        }
        root = deleteNode(root,x);
        return true;
    }
    
    void inOrder(Node *root){
        if(!root)
            return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

    void preOrder(Node *root){
        if(!root)
            return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(Node *root){
        if(!root)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }


    int findMax(Node *root){
        if(!root)
            return INT_MIN;
        if(!root->right)
            return root->data;
        return findMax(root->right);
    }

    int findMin(Node *root){
        if(!root)
            return INT_MAX;
        if(!root->left)
            return root->data;
        return findMin(root->left);
    }

    /* height of a node = no.of edges from the node to the deepest node in the sub-tree where that node exists*/
    int height(Node *root){
        if(!root)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }

    int height(int x){
        Node *node = search(root,x);
        if(!node){
            cerr<<x<<" does not exist in BST\n";
            return -1;
        }
        return height(node)-1;
    }

    int depth(Node *root, int x){
        if(root->data < x)
            return 1+depth(root->right,x);
        else if(root->data > x)
            return 1+depth(root->left,x);
        return 0;
    }

    int depth(int x){
        Node *node = search(root,x);
        if(!node){
            cerr<<x<<" does not exist in BST\n";
            return -1;
        }
        return depth(root,x);
    }

};


int main(){
    int n = 11;
    // cin>>n; // no.of nodes to be inserted in a tree

    vector<int> nodes = {6,4,8,3,5,7,9,10,11,12,13};
    BST bst;

    for(int i=0;i<n;i++){
        int x = nodes[i];
        // cin>>x;
        bst.insert(x);
    }

    Node *root = bst.root;

    /* inorder traversal */
    // bst.inOrder(root);
    // cout<<endl;

    /* preorder traversal */ 
    // bst.preOrder(root);
    // cout<<endl;

    /* postorder traversal */
    // bst.postOrder(root);
    // cout<<endl;

    /* search for a val */
    // int val;
    // cin>>val;
    // if(bst.search(val))
    //     cout<<val<<" exists in BST\n";
    // else
    //     cout<<val<<" does not exists in BST\n";

    /* delete a node with a value*/
    // int value;
    // cin>>value;
    // if(bst.deleteNode(value)){
    //     cout<<value<<" is deleted from the BST\n";
    //     cout<<"The new tree is: ";
    //     bst.inOrder(bst.root);
    //     cout<<endl;
    // }

    /* height of tree */
    /* no.of edges between the root and the deepest leaf node*/
    cout<<bst.height(bst.root)-1<<endl;

    /* height of a node with particular value*/
    cout<<bst.height(10)<<endl;
    cout<<bst.depth(10)<<endl;
    // cout<<bst.height(100)<<endl;
    return 0;
}