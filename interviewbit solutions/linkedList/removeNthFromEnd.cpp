#include <iostream>
#include <vector>
#include <algorithm>
#include "basic.h"
using namespace std;

ListNode *answer(ListNode *head, int n){
  // ListNode *n = head;
  ListNode *pre = head;
  ListNode *temp = head;
  if(n==0) return head;
  if(head->next == NULL) return NULL;
  while(n-- && temp){temp=temp->next;}
  if(temp == NULL) return head->next;
  while(temp->next){
    temp = temp->next;
    pre = pre->next;
  }
  pre->next = pre->next->next;
  // cout<<pre->val<<" "<<temp->val;

  return head;

}

int main(){
  ListNode *a = create();
  int n;
  cin>>n;
  // answer(a, 2);
  display(answer(a,n));

}

// 1 2 3 4 5 6 7 8 9 10 -1
