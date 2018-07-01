#include <iostream>
#include <stack>
using namespace std;

void showstack(stack <int> gq){
  stack <int> g = gq;
  while(!g.empty()){
    cout<<g.top()<<" ";
    g.pop();
  }
  cout<<endl;
}

//using 2 extra stacks
void reverseStack2(stack <int> a){
  stack <int> b;
  stack <int> c;

  while(!a.empty()){
    b.push(a.top());
    a.pop();
  }
  while(!b.empty()){
    c.push(b.top());
    b.pop();
  }

  while(!c.empty()){
    a.push(c.top());
    c.pop();
  }

  showstack(a);
}

//reverse using 1 extra stack
void reverseStack1(stack <int> a){
  stack <int> b;
  int n = a.size();
  while(n--){
    int count = n;
    int c = a.top();
    a.pop();
    while(count--){
      b.push(a.top());
      a.pop();
    }
    a.push(c);
    while(!b.empty()){
      a.push(b.top());
      b.pop();
    }
  }
  showstack(a);
}

//reverse using 0 extra stacks

void revereStack(stack <int> a){
  // ??
  // do this later



}

int main(){
  stack <int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);
  a.push(5);
  showstack(a);
  reverseStack1(a);
  // reverseStack2(a);

}
