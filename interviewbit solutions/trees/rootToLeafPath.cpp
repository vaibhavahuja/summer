#include <iostream>
#include <vector>
#include <algorithm>
#include "tree.h"
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

void show(vi a){
  int i =0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}


void answer(TreeNode *a, vi &t){
  if(!a) return;
  t.push_back(a->val);
  if(!a->left && !a->right) {show(t); t.empty();}
  else{
    answer(a->left, t);
    answer(a->right, t);
  }
}

//5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 -1 1 -1 -1

int main(){
  TreeNode *a = createTree();
  vi t;
  answer(a,t);
  // cout<<answer(a, t)<<endl;

}
