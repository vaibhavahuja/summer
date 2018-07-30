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

void show1(vvi a){
  int i = 0;
  while( i < a.size()){
    // cout<<a[i]<<" ";
    show(a[i]);
    i++;
  }
  cout<<endl;
}


int sumOf(vi a){
  int i =0;
  int sum = 0;
  while(i < a.size()){
    sum += a[i];
    i++;
  }
  return sum;
}


void answer(TreeNode *a, vi t, vvi &z, int k){
  if(!a) return;
  if(!a->left && !a->right){
    t.push_back(a->val);
    if(sumOf(t) == k) z.push_back(t);
    // show(t);
    t.pop_back();
  }

  t.push_back(a->val);
  answer(a->left, t, z, k);
  answer(a->right, t, z, k);
  t.pop_back();

}

// 5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 5 -1 -1 1 -1 -1

int main(){
  TreeNode *a = createTree();
  vi t;
  vvi z;

  answer(a,t, z, 22);
  show1(z);
  // cout<<answer(a, t)<<endl;

}
