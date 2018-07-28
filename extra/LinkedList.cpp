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

Node *create(){
  Node *head = NULL;
  Node *tail = NULL;
  while(true){
    int x;
    cin>>x;
    if(x==-1) break;

    Node *temp = new Node(x);
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

void display(Node *head){
  Node *temp = head;
  while(temp){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<endl;
}

Node *displayReverseRecur(Node *head){    //ps: this does not reverses just displays in reverse order;
  if(!head){
    return head;
  }
  displayReverseRecur(head->next);
  cout<<head->data<<"->";
}

void deleteNode(Node* &head, int key){
  if(key == 1){
    Node *temp = head;
    head = temp->next;
    delete temp;
  }
  else{
    Node *pre = NULL;
    Node *temp = head;
    int a = key-1;
    while(a--){
      pre = temp;
      temp = temp->next;
    }
    pre->next = temp->next;
    delete temp;
  }
}

Node *reverseLL_iter(Node *head){
  Node *pre = NULL;
  Node *cur = head;
  Node *nxt = head->next;
  while(cur){
    nxt = cur->next;
    cur->next = pre;
    pre = cur;
    cur = nxt;
  }
  return pre;
}

Node *reverseLL_recur(Node *head){
  if(!head || !head->next) return head;

  Node *temp = reverseLL_recur(head->next);
  head->next->next = head;
  head->next = NULL;

  return temp;
}

//merge two linked lists iteratively
Node *mergeLL(Node *a, Node *b){
  Node *tail = new Node(1);
  Node *temp = tail;
  while(a && b){
    if(a->data<b->data){
      tail->next = a;
      a = a->next;
      tail = tail->next;
    }else{
      tail->next = b;
      b = b->next;
      tail = tail->next;
    }
  }
  if(a){
    while(a){
      tail->next = a;
      a = a->next;
      tail=tail->next;
    }
  }
  if(b){
    while(b){
      tail->next = b;
      b = b->next;
      tail=tail->next;
    }
  }
  return temp->next;
}



//merging two linked lists using recursion
Node *mergeLLRecur(Node *a, Node *b){
  if(!a) return b;
  if(!b) return a;
  if(a->data<b->data){
    a->next = mergeLLRecur(a->next,b);
    return a;
  }else{
    b->next = mergeLLRecur(a,b->next);
    return b;
  }
}


Node *midElem(Node *head){
  Node *temp = head;
  Node *fast = head;
  while(fast && fast->next && fast->next->next){
    temp = temp->next;
    fast = fast->next->next;
  }
  return temp;
}

void nfromLast(Node *head, int n){
  Node *temp = head;
  Node *fast = head;
  while(n--){
    fast = fast->next;
  }
  while(fast && fast->next){
    temp = temp->next;
    fast = fast->next;
  }
  cout<<temp->data<<endl;
}
//
// Node* mergeSort(Node* a){
//     if (a == NULL || a->next == NULL) return a;
//     // if (!a or !a->next) return a;
//
//     Node* midNode = midElem(a);
//     Node* b = midNode->next;
//     midNode->next = NULL;
//
//     a = mergeSort(a);
//     b = mergeSort(b);
//     Node* ans = mergeLL(a, b);
// }


Node *mergeSort(Node *head){
  if(!head || !head->next){
    return head;
  }
  Node *mid = midElem(head);
  Node *mid2 = mid->next;
  mid->next = NULL;

  Node *a = mergeSort(head);
  Node *b = mergeSort(mid2);
  Node *c = mergeLL(a,b);
}

//TO DO:
// 1. Add two numbers
// 2. Add one to a linked list
// 3. Find cycle
// 4. Remove Cycle


Node *reverseK(Node *a, int k){
  int c = 0;
  Node *pre = NULL;
  Node *cur = a;
  Node *nxt = NULL;
  while(c<k && cur){
    nxt = cur->next;
    cur->next = pre;
    pre = cur;
    cur = nxt;
    c++;
  }
  if(nxt) a->next = reverseK(nxt, k);

  return pre;
}



int main(){
  Node *a = create();
  // a = mergeSort(a);
  display(reverseK(a, 3));
  // display(a);
  // int n;
  // cin>>n;
  // nfromLast(a,n);
  // midElem(a);
  // Node *b = create();
  // display(b);
  // Node *c = mergeLL(a,b);
  // Node *c = mergeLLRecur(a,b);
  // display(c);
}
