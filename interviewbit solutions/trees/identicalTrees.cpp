#include <iostream>
#include <vector>
#include <algorithm>
#include "tree.h"
using namespace std;

int isSameTree(TreeNode *a, TreeNode *b){
  if(!a && !b) return 1;

  if(a && b){
    return a->val == b->val && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
  }
  return 0;
}



int main(){
  TreeNode *a = createTree();
  TreeNode *b = createTree();
  cout<<isSameTree(a,b);


}
