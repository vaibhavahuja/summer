#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "tree.h"
using namespace std;

#define qt queue<TreeNode*>
#define vi vector<int>
#define vvi vector<vi>

void show(vi a){
  int i = 0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}


void show2(vvi a){
  int i = 0;
  while(i < a.size()){
    show(a[i]);
    i++;
  }
  cout<<endl;
}

#define del NULL
vvi zigZag(TreeNode *a){
  qt q;
  q.push(a);
  q.push(del);
  int p = 0;
  vvi d;
  vi qw;
  while(!q.empty()){
    TreeNode *temp = q.front();
    q.pop();
    if(temp == del){
      // q.pop();
      p++;
      if(p % 2 != 0){
        d.push_back(qw);
      }else{
        reverse(qw.begin(), qw.end());
        d.push_back(qw);
      }
      qw.clear();
      if(!q.empty()) q.push(del);
    }else{
      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);

      qw.push_back(temp->val);
    }
  }
  return d;
  // show2(d);
}

int main(){
  TreeNode *a = createTree();
  show2(zigZag(a));
}
