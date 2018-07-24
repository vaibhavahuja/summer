#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "tree.h"
using namespace std;
//1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
#define qt queue<TreeNode*>
#define vi vector<int>


//returns the sum of last row nodes.
void sumNodes(TreeNode *a){
  // if(!a) return;
  TreeNode *const del = NULL;
  int sum = 0;
  qt q;
  q.push(a);
  q.push(del);
  vi sm;
  while(!q.empty()){
    TreeNode *curElem = q.front();
    q.pop();
    if(curElem == del){
      sm.push_back(sum);
      sum = 0;
      if(!q.empty())q.push(del);
      continue;
    }
    sum+= curElem->data;
    // cout<<curElem->data<<" ";
    if(curElem->left) q.push(curElem->left);
    if(curElem->right) q.push(curElem->right);
  }
  cout<<sm[sm.size() - 1]<<endl;;
}
int main(){
  TreeNode *x = createTree();

  sumNodes(x);

}
