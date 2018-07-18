#include <iostream>
#include <vector>
#include <algorithm>
#include "basic.h"
using namespace std;

Node *answer(Node *head){
  Node *a = new Node(head->data);
  Node *temp = a;
  Node *temp2 = head;
  while(temp2){
    if(temp->data != temp2->data){
      temp->next = new Node(temp2->data);
      temp = temp->next;
      temp2 = temp2->next;
    }else{
      temp2 = temp2->next;
    }
  }
  return a;
}

int main(){
  Node *a = create();
  display(a);
  Node *b = answer(a);
  display(b);
}
