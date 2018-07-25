#include <iostream>
#include <vector>
#include <algorithm>
#include "tree.h"
using namespace std;


int maxDepth(TreeNode *a){
  // int c = 0;
  if(!a) return -1;
  return max(1+maxDepth(a->left), 1+maxDepth(a->right));
  // return c;
}

int main(){
  TreeNode *c = createTree();
  cout<<maxDepth(c);

}
