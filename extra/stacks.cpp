#include <iostream>
using namespace std;

class Stack{
  class Node{
  public:
    int data;
    Node *next;
    Node(int d){
      data = d;
      next = NULL;
    }
  };
  Node *head;
public:
  Stack(){
    head = NULL;
  }

  bool isEmpty(){
    return head==NULL;
  }

  int top(){
    if(head==NULL) return -1;
    return head->data;
  }

  void push(int x){
    Node *tmp = new Node(x);
    tmp->next = head;
    tmp = head;
  }

  void pop(){
    if(!empty()){
      Node *tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  ~Stack(){
    cout<<"deconstructor called"<<endl;
    Node *tmp = NULL;
    while(head){
      tmp = head->next;
      delete head;
      head = tmp;
    }
  }
};

int main(){

}
