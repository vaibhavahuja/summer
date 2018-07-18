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


ListNode *rev(ListNode *head){
	ListNode *pre = NULL;
	ListNode *cur = head;
	while(cur){
		ListNode *nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur=nxt;
	}
	return pre;
}


ListNode *reverse(ListNode *head, int s, int e){
	ListNode *start = head;
	ListNode *end = head;
	ListNode *before = head;
	int k = max(0,s-2);
	while(k--){
		before = before->next;
	}
	// cout<<before->val<<endl;
	if(s==1) start = head;
	else if(before) start = before->next;
	else start = head;

	int p = e-1;
	p = max(0,p);
	while(p--){
		end = end->next;
	}
	// end->next = after;
	// cout<<after->val<<" yad "<<endl;

	ListNode *after;
	after = end->next;

	end->next = NULL;
	start = rev(start);


	if(s!=1) before->next = start;
	else before = start;

	ListNode *tep = before;
	while(tep->next) tep=tep->next;
	tep->next = after;

	if(s!=1)return head;
	else return start;


}



int main(){
	ListNode *a = create();
	// display(rev(a));
	display(reverse(a,1,2));
}
