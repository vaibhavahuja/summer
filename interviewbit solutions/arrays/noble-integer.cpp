#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define V vector<int>


int solve(V &A){
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  int count = 0;
  int ce = 0;
  if(A[0] == 0) return 1;
  for(int i = 1; i < A.size(); i++){
    if(A[i]<A[i-1]){
      count++;
      count+=ce;
      ce = 0;
    }
    else if(A[i] == A[i-1]){
      ce++;
    }
    if(A[i] == count) return 1;
  }
  return -1;

}


int main(){
  int arr[9] = {1, 2, 7, 0, 9, 3, 6, 0, 6};

  int i = 0;
  V a;
  while(i<9){
    a.push_back(arr[i]);
    i++;
  }
  cout<<solve(a);

}
