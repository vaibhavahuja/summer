#include <iostream>
using namespace std;

//first: given a number N, find number of ways to make N using 1,3 and 4

//basic recursion
int firstRec(int n){
  if(n<=2) return 1;
  if(n==3) return 2;

  return firstRec(n-1)+firstRec(n-3)+firstRec(n-4);
}

//using DP
int firstDP(int n){
  int arr[n+1];
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 1;
  arr[3] = 2;

  for(int i = 4; i < n+1; i++){
    arr[i] = arr[i-4]+arr[i-3]+arr[i-1];
  }
  return arr[n];
}

int main(){
  cout<<firstRec(5);
  cout<<firstDP(10);
}
