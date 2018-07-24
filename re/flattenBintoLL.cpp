#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "tree.h"
using namespace std;
//1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
#define qt queue<TreeNode*>
#define vi vector<int>

void preOrder(TreeNode *a){
  if(!a) return;
  cout<<a->data<<" ";
  if(a->left) preOrder(a->left);
  if(a->right) preOrder(a->right);
}

void flatten(TreeNode *root){
  if(!root || !root->left && !root->right) return;
  if(root->left){
    flatten(root->left);
    TreeNode *temp = root->right;
    root->right = root->left;
    root->left = NULL;
  }
}

int main(){
  TreeNode *root = createTree();
  preOrder(root);

}
