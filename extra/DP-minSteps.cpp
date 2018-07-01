#include <iostream>
using namespace std;

int minSteps(int n){
  if(n<=1) return 0;
  int c;
  c = 1 + minSteps(n-1);
  if(n%2 == 0) c = min(c,minSteps(n/2))+1;
  if(n%3 == 0) c = min(c,minSteps(n/3))+1;

  return c;
}


int minStepsDP(int n){
  int arr[n+1];
  for(int i = 0; i < n+1; i++){
    arr[i] = 1e5;
  }
  arr[0] = 0;
  arr[1] = 0;
  arr[2] = 1;
  arr[3] = 1;

  int c = 4;
  while(c!=n+1){
    if(c%3 == 0) arr[c] = arr[c/3] + 1;
    if(c%2 == 0) arr[c] = min(arr[c/3] + 1, arr[c]);
    arr[c] = min(arr[c-1] + 1, arr[c]);
    c++;
  }

  return arr[n];
}

int main(){
  cout<<minStepsDP(5);
}
