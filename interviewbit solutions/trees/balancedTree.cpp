#include <iostream>
#include <vector>
#include <algorithm>
#include "tree.h"
using namespace std;
#define vi vector<int>

void show(vi a){
  int i = 0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

int depth(TreeNode *a){
  if(!a) return 0;
  return max(depth(a->left) + 1, depth(a->right) + 1);
}

void answer(TreeNode *a, vi &t){
  if(!a) return;
  // cout<<
  t.push_back(abs(depth(a->left) - depth(a->right)));
  answer(a->left, t);
  answer(a->right, t);
}

int isBalanced(TreeNode *a){
  vi t;
  answer(a, t);
  int i = 0;
  while(i < t.size()){
    if(t[i] > 1) return 0;
    i++;
  }
  return 1;
}


int main(){
  TreeNode *a = createTree();
  cout<<isBalanced(a);
  // cout<<depth(a);
  // vi t;
  // answer(a, t);
  // show(t);
}
