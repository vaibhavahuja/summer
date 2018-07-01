#include <iostream>
using namespace std;

class TreeNode{
public:
  int data;
  TreeNode *left, *right;

  TreeNode(int x){
    data = x;
    left = NULL;
    right = NULL;
  }
};

TreeNode *createTree(){
  int x;
  cin>>x;
  if(x == -1) return NULL;

  TreeNode *root = new TreeNode(x);
  // cout<<"left child of "<<root->data<<" ";
  root->left = createTree();
  // cout<<"right child of "<<root->data<<" ";
  root->right = createTree();
  return root;
}

//use 1 2 3 4 -1 -1 5 -1 -1 6 7 -1 -1 8 -1 -1 9 -1 -1 for above




void preOrderPrint(TreeNode *root){
  if(!root) return;
  cout<<root->data<<" ";
  preOrderPrint(root->left);
  preOrderPrint(root->right);
}

void postOrderPrint(TreeNode *root){
  if(!root) return;
  postOrderPrint(root->left);
  postOrderPrint(root->right);
  cout<<root->data<<" ";
}

void inOrderPrint(TreeNode *root){
  if(!root) return;
  inOrderPrint(root->left);
  cout<<root->data<<" ";
  inOrderPrint(root->right);
}

int height(TreeNode* root){
  if(!root) return 0;
  return 1+max(height(root->left), height(root->right));
}


int numberOfNodes(TreeNode *root){
  if(!root) return 0;
  return 1+numberOfNodes(root->left)+numberOfNodes(root->right);
}

int sumOfNodes(TreeNode *root){
  if(!root) return 0;
  return root->data+sumOfNodes(root->left)+sumOfNodes(root->right);
}

TreeNode *createLevel(){
  queue<TreeNode*>q;
  int x;
  cin>>x;
  if(x==-1) return NULL;
  TreeNode *root = new TreeNode(x);
  q.push(root);
  while(!q.empty()){
    TreeNode *cur = q.front();
    q.pop();
    cin>>x;
    if(x!=-1){
      cur->left= new TreeNode(x);
      q.push(cur->left);
    }
    cin>>x;
    if(x!=-1){
      cur->right = new TreeNode(x);
      q.push(cur->right);
    }
  }
  return root;

}


TreeNode *printLevel(TreeNode *root){
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()){
    TreeNode *temp = q.front();
    cout<<temp->data<<" ";
    q.pop();
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }
}
