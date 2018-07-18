#include <iostream>
using namespace std;

class ListNode{
public:
  int val;
  ListNode *next;

  ListNode(int d){
    val = d;
    next = NULL;
  }
};

ListNode *create(){
  ListNode *head = NULL;
  ListNode *tail = NULL;
  while(true){
    int x;
    cin>>x;
    if(x==-1) break;

    ListNode *temp = new ListNode(x);
    if(head==NULL){
      head = temp;
      tail = temp;
    }else{
      tail->next = temp;
      tail = tail->next;
    }
  }
  return head;
}

void display(ListNode *head){
  ListNode *temp = head;
  while(temp){
    cout<<temp->val<<"->";
    temp=temp->next;
  }
  cout<<endl;
}
