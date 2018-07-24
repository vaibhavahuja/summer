#include <iostream>
using namespace std;


class Node{
public:
  int data;
  Node *next;

  Node(int d){
    data = d;
    next = NULL;
  }
};

Node *createLL(){
  Node *head = NULL, *tail = NULL;

  int a;
  cin>>a;

  if(a != -1){
    Node *temp = new Node(a);
    head = temp;
    tail = head;
  }else return NULL;

  while(1){
    cin>>a;
    if(a == -1) break;
    tail->next = new Node(a);
    tail = tail->next;
  }
  tail->next = NULL;

  return head;
}

void display(Node *a){
  Node *temp = a;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<endl;
}


//reverse LL iteratively

Node *reverse(Node *head){
  Node *pre = NULL;
  Node *cur = head;

  while(cur){
    Node *nxt = cur->next;
    cur->next = pre;
    pre = cur;
    cur = nxt;
  }
  return pre;
}


// reverse LL recursively
Node *reverse2(Node *head){
  if(!head || !head->next) return head;
  Node *rev = reverse2(head->next);
  head->next->next = head;
  head->next = NULL;
  return rev;

}

//merge two sorted iteratively

Node *merge(Node *a, Node *b){
  Node *temp1 = a;
  Node *temp2 = b;
  Node *answer = new Node(0);
  Node *ansTail = answer;

  while(temp1 && temp2){
    if(temp1->data<temp2->data){
      ansTail->next = temp1;
      temp1 = temp1->next;
      ansTail = ansTail->next;
    }else{
      ansTail->next = temp2;
      temp2 = temp2->next;
      ansTail = ansTail->next;
    }
  }

  if(!temp1){
    while(temp2){
      ansTail->next = temp2;
      temp2 = temp2->next;
      ansTail = ansTail->next;
    }
  }else if(!temp2){
    while(temp1){
      ansTail->next = temp1;
      temp1 = temp1->next;
      ansTail = ansTail->next;
    }
  }
  return answer->next;
}

//merge two lists recursively

// Node *mergeLL(Node *a, Node *b){
//   if(a == NULL) return b;
//   if(b==NULL) return a;
//
//   if(a->data < b->data){
//     a->next = mergeLL(a->next, b);
//     return a;
//   }else{
//     b->next = mergeLL(a,b->next);
//     return b;
//   }
// }

Node *mergeLL(Node *a, Node *b){
  if(a==NULL) return b;
  if(b==NULL) return a;

  if(a->data < b->data){
    a->next = mergeLL(a->next, b);
    return a;
  }else{
    b->next = mergeLL(a,b->next);
    return b;
  }
}

Node *findMid(Node *a){
  Node *slow = a;
  Node *fast = a;
  while(fast->next && fast->next->next){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

void kthFromLast(Node *a, int k){
  Node *slow = a;
  Node *fast = a;
  while(k--) fast = fast->next;
  while(fast){
    fast = fast->next;
    slow = slow->next;
  }
  cout<<slow->data<<endl;
}


Node *bubbleSort(Node* head){
  Node *i = head;
  Node *j = head;
  while(i){
    j = head;
    while(j && j->next){
      if(j->data > j->next->data) swap(j->data, j->next->data);
      j = j->next;
    }
    i = i->next;
  }
  return head;
}

Node *mergeSort(Node *head){
  if(head==NULL || head->next == NULL) return head;

  Node *mid = findMid(head);
  Node *head2 = mid->next;
  mid->next = NULL;

  // display(head);
  // display(head2);

  head = mergeSort(head);
  head2 = mergeSort(head2);
  //
  Node *c = mergeLL(head,head2);
}







int main(){
  Node *head = createLL();
  // Node *a = createLL();
  // Node *b = createLL();

  // addtwo(a,b);
  // mergeSort(head);
  // display(mergeSort(head));
  // kthFromLast(head,4);
  // display(bubbleSort(head));
  // findMid(head);
  // display(head);
  // display(reverse(head));
  display(reverse2(head));
  // Node *head2 = createLL();
  // findMid(head2);


  // display(merge(head,head2));
  // display(mergeLL(head,head2));


}
