#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include "tree.h"
using namespace std;

#define mt map<TreeNode*, int>
#define qt queue<TreeNode*>
#define vi vector<int>
#define vvi vector<vi>
#define mp map<int, vi>


void show3(vi a){
  int i =0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}


void finalcheck(vvi a){
    int i = 0;
    while(i < a.size()){
      show3(a[i]);
      i++;
    }
    cout<<endl;
}

void show2(mp a){
  mp::iterator it;
  for(it = a.begin(); it != a.end(); it++){
    cout<<it->first<<" ";
    show3(it->second);
  }
  cout<<endl;
}

void show(mt a){
  mt::iterator it;
  for(it = a.begin(); it != a.end(); it++){
    cout<<it->first->val<<" "<<it->second<<endl;
  }
  cout<<endl;
}


void verticalOrder(TreeNode *root, mt &map){
  qt q;
  q.push(root);
  map[root] = 0;

  while(!q.empty()){
    TreeNode *n = q.front();
    q.pop();
    if(n->left){
      q.push(n->left);
      map[n->left] = map[n] - 1;
    }
    if(n->right){
      q.push(n->right);
      map[n->right] = map[n] + 1;
    }
  }
}


vvi answer(TreeNode *a){
  mt qw;
  verticalOrder(a,qw);
  mp tab;

  qt q;
  q.push(a);

  while(!q.empty()){
    TreeNode *cur = q.front();
    q.pop();
    tab[qw[cur]].push_back(cur->val);
    if(cur->left) q.push(cur->left);
    if(cur->right) q.push(cur->right);
  }
  // show2(map);

  mp::iterator it;
  vvi z;
  for(it = tab.begin(); it != tab.end(); it++){
    z.push_back(it->second);
  }
  // finalcheck(z);
  return z;

}


//6 3 2 -1 -1 5 -1 -1 7 -1 9 -1 -1
int main(){
  TreeNode *a = createTree();
  mt map;
  answer(a);
}
