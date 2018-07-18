#include <iostream>
#include <vector>
#include <algorithm>
#include "basic.h"
using namespace std;

ListNode *swap(ListNode *head){
  ListNode *temp = head;
  while(temp && temp->next){
    swap(temp->val, temp->next->val);
    temp=temp->next->next;
  }
  return head;

}


int main(){
  ListNode *a = create();
  display(a);
  display(swap(a));
  // display(a);
}
