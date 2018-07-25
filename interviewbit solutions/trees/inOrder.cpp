#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "tree.h"
using namespace std;

#define st stack<TreeNode*>
#define vi vector<int>

void show(st b){
  st a = b;
  while(!a.empty()){
    cout<<a.top()->val<<" ";
    a.pop();
  }
  cout<<endl;
}

vi inOrder(TreeNode *a){
  st s;
  vi ans;
  TreeNode *cur = a;
  while(cur || !s.empty()){
    while(cur){
      s.push(cur);
      cur=cur->left;
    }
    ans.push_back(s.top()->val);
    // cout<<s.top()->val<<" ";
    cur = s.top()->right;
    s.pop();
  }
  return ans;
}


int main(){
  TreeNode *a = createTree();
  inOrder(a);
  //my input
  //1 2 4 -1 -1 5 -1 -1 3 -1 -1
}
