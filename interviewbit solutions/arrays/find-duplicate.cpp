#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define vi vector<int>

void show(vi A){
  int i = 0;
  while(i<A.size()){
    cout<<A[i]<<" ";
    i++;
  }
  cout<<endl;
}

//still showing memory limit exceeded. idk why.
int answer(vi &A){
  int i = 0;
  while(i<A.size()){
    if(A[abs(A[i])]>0){
      A[abs(A[i])] *= -1;
      // show(A);
    }
    else if(A[abs(A[i])]<0) return abs(A[i]);

    i++;
  }
  return -1;
}

//trying for better approach-> think of it as a linked list; individual nodes
//visualised a vector as a linked list. amazing solution. wont work for cases with 0 duplicates.
int answer2(vi &A){
  int slow = A[0];
  int fast = A[A[0]];
  while(slow!=fast){
    slow=A[slow];
    fast=A[A[fast]];
  }

  fast = 0;
  while(slow!=fast){
    slow = A[slow];
    fast = A[fast];
  }
  return slow;
}

int main(){
  vi a;
  a.push_back(3);
  a.push_back(4);
  a.push_back(1);
  a.push_back(4);
  a.push_back(1);
  // a.push_back(5);
  cout<<answer2(a)<<endl;
}
