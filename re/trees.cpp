#include <iostream>
#include <queue>
#include <map>
#include <stack>
using namespace std;

#define qt queue<TreeNode*>
#define st stack<TreeNode*>

class TreeNode{
public:
  TreeNode *left, *right;
  int data;

  TreeNode(int d){
    data = d;
    left = NULL;
    right = NULL;
  }
};

TreeNode *createTree(){
  int x;
  cin>>x;
  if(x==-1) return NULL;
  TreeNode *root = new TreeNode(x);
  root->left = createTree();
  root->right = createTree();
  return root;
}


void inOrder(TreeNode *root){
  if(!root) return;
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

void preOrder(TreeNode *root){
  if(!root) return;
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(TreeNode *root){
  if(!root) return;
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";
}


int countNum(TreeNode *root){
  if(!root) return 0;
  return 1 + countNum(root->left) + countNum(root->right);
}

int sum(TreeNode *root){
  if(!root) return 0;
  return root->data + sum(root->left) + sum(root->right);
}

void levelOrder(TreeNode *root){
  if(!root) return;

  TreeNode* const DELIMITER = NULL;
  st p;
  qt q;
  q.push(root);
  q.push(DELIMITER);
  int c = 0;
  while(!q.empty()){
    TreeNode *temp = q.front();
    q.pop();

    if(temp == DELIMITER){
      c++;
      cout<<endl;
      if(!q.empty()){
        q.push(DELIMITER);
      }
      continue;
    }
    else cout<<temp->data<<" ";

    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);


  }
}






int main(){
  //my INPUT
  //1 2 7 -1 -1 6 -1 -1 3 5 -1 -1 4 -1 -1
  TreeNode *x = createTree();
  levelOrder(x);
  // cout<<countNum(x)<<endl;
  // cout<<sum(x)<<endl;



  // inOrder(x);
  // cout<<endl;
  // preOrder(x);
  // cout<<endl;
  // postOrder(x);
  // cout<<endl;



}
