#include <iostream>
#include <vector>
#include <algorithm>
#include "basic.h"
using namespace std;

int isCycle(ListNode *head){
  ListNode *fast = head;
  ListNode *slow = head;
  while(fast->next && fast && slow){
    fast = fast->next->next;
    slow = slow->next;
    if(!slow || !fast) return 0;
    if(slow==fast){
      int k = 1;
      fast = fast->next;
      while(slow!=fast){
        fast = fast->next;
        k++;
      }
      return k;
    }
  }
  return 0;
}

ListNode *detectNode(ListNode *head){
  if(isCycle(head) == 0) return NULL;
  else{
    int k = isCycle(head);
    ListNode *temp1 = head;
    ListNode *temp2 = head;
    while(k--) temp2 = temp2->next;

    while(temp1!=temp2){
      temp1 = temp1->next;
      temp2=temp2->next;
    }
    return temp2;
  }
}


int main(){
  ListNode *a = create();
  cout<<isCycle(a)<<endl;

}
