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


ListNode *answer(ListNode *head, int x){
	ListNode *a = new ListNode(0);
	ListNode *b = new ListNode(0);
	ListNode *heada = a;
	ListNode *headb = b;

	ListNode *temp = head;
	while(temp){
		if(temp->val<x){
			a->next = new ListNode(temp->val);
			a = a->next;
		}
		else {
			b->next = new ListNode(temp->val);
			b = b->next;
		}
		temp = temp->next;
	}
	a->next = headb->next;
	return heada->next;

}

int main() {
	ListNode *a = create();
	display(a);
	display(answer(a,3));
}





 
