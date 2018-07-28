#include <iostream>
#include <vector>
#include <algorithm>
#include "tree.h"
using namespace std;

int hasPathSum(TreeNode *a, int sum){
  if(!a) return 0;

  if(a->val == sum  && a->left == NULL && a->right == NULL) return 1;

  return max(hasPathSum(a->left, sum - a->val), hasPathSum(a->right, sum-a->val));
}

//5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 -1 1 -1 -1

int main(){
  TreeNode *a = createTree();

  cout<<hasPathSum(a, 22);

}
