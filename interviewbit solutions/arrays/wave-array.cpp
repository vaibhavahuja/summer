#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define V vector<int>

V answer(V &A){
  sort(A.begin(), A.end());
  int i = 0;
  while(i < A.size()-1){
    int c = A[i];
    A[i] = A[i+1];
    A[i+1] = c;
    i+=2;
  }

  int m = 0;
  while(m<A.size()){
    cout<<A[m]<<" ";
    m++;
  }
  return A;
}

int main(){
  V A;
  A.push_back(3);
  A.push_back(1);
  A.push_back(2);
  A.push_back(4);
  // A.push_back(5);

  V c = answer(A);

}
