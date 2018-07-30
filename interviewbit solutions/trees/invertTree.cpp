#include <iostream>
#include <vector>
#include <algorithm>
#include "tree.h"
using namespace std;

void invert(TreeNode *a){
  if(!a) return;
  invert(a->left);
  invert(a->right);
  TreeNode *temp = a->left;
  a->left = a->right;
  a->right = temp;
}

int main(){

}
