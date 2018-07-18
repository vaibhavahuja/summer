#include <iostream>
#include <vector>
#include <algorithm>
#include "basic.h"
using namespace std;

ListNode *rotate(ListNode *head, int k){
  ListNode *temp1 = head;
  ListNode *temp2 = head;

  int len = 0;
  ListNode *leng = head;
  while(leng){
    len++;
    leng=leng->next;
  }
  if(len==1) return head;
  if(k>len) k = k%len;


  while(k--) temp2=temp2->next;

  while(temp2 && temp2->next){
    temp1=temp1->next;
    temp2=temp2->next;
  }

  ListNode *ok = temp1->next;
  temp1->next = NULL;
  temp2->next = head;


  // cout<<temp1->val<<endl;
  // cout<<temp2->val;
  return ok;

}

int main(){
  ListNode *a = create();
  display(a);
  ListNode *ok = rotate(a,90);
  display(ok);


}
