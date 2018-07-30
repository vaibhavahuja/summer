#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count(int i, int j){
  if(i < 0 || j < 0) return 0;
  if(i == 1 && j == 1) return 1;
  return (count(i-1, j) + count(i, j-1));
}

//can easily make this as memoized soln.

int main(){
  // int a[][100];
  cout<<count(3, 3);
}
