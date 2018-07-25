#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TreeNode{
public:
  TreeNode *left, *right;
  int val;
  TreeNode(int d){
    left = NULL;
    right = NULL;
    val  = d;
  }
};

TreeNode *createTree(){
  int x;
  cin>>x;
  if(x == -1) return NULL;
  TreeNode *root = new TreeNode(x);
  root->left = createTree();
  root->right = createTree();

  return root;
}
