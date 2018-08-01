#include <iostream>
#include <vector>
#include <algorithm>
#include "tree.h"
using namespace std;

bool find(TreeNode* root, int val)
{
    if (!root)
        return false;
    if (root->val == val)
        return true;
    if ((root->left && find(root->left, val)) ||
        (root->right && find(root->right, val)))
        return true;
    return false;
}
TreeNode *ca(TreeNode *root, int a, int b){
  if(!root) return NULL;
  if(root->val == a || root->val == b) return root;
  TreeNode *left = ca(root->left, a, b);
  TreeNode *right = ca(root->right, a, b);
  if(left && right) return root;
  else{
    if(!left) return right;
    if(!right) return left;
  }
}
int answer(TreeNode *a, int b, int c){
  if(!find(a, c) || !find(a, d)){
  return -1;
}
  TreeNode *temp = ca(a, c, d);
  return temp->val;
}



//3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1
int main(){
  TreeNode *a = createTree();
  int b, c;
  cin>>b>>c;
  // cout<<find(a, b)<<" "<<find(a,c);
  // cout<<answer(a, b, c);
}
