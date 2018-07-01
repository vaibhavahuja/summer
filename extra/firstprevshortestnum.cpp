#include <iostream>
#include <stack>
using namespace std;

//find the first previous shortest number
//example: given array [4,5,2,10,8] :::> output array :::> [-1,4,-1,2,2]

void answer(int arr[], int n){
  int arr2[n];
  stack <int> a;
  a.push(-1);
  int i = 0;
  while(i != n){
    while(a.top() != -1 && a.top()>arr[i]){
      a.pop();
    }
    cout<<a.top()<<endl;
    arr2[i] = a.top();
    a.push(arr[i]);
    i++;
  }
  for(int i = 0; i<n;i++){
    cout<<arr2[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int arr[5] = {4,5,2,10,8};
  answer(arr,5);
}
