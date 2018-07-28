#include <iostream>
#include <vector>
#include <algorithm>
#include "tree.h"
using namespace std;

int minDepth(TreeNode *a){
  if(!a) return 0;
  if(!a->left && !a->right) return 1;

  if(!a->left) return minDepth(a->right) + 1;
  if(!a->right) return minDepth(a->left) + 1;

  return min(minDepth(a->left), minDepth(a->right)) + 1;


}

int main(){
    TreeNode *a = createTree();
    cout<<minDepth(a);
}
