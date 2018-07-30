//i need to do it in constant extra space and this function should be without a queue

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "tree.h"
using namespace std;
#define qt queue<TreeNode*>
#define del NULL
void check(TreeNode *a){
  qt q;
  q.push(a);
  q.push(del);

  while(!q.empty()){
      TreeNode *temp = q.front();
      q.pop();

      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);

      if(q.front() == del){
          q.pop();
          temp->next = NULL;
          if(!q.empty()) q.push(del);

      }else{
          temp->next = q.front();
      }

  }
}



//1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

int main(){
  TreeNode *a = createTree();
  check(a);

}
