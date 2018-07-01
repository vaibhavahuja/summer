#include <iostream>
#include <stack>
using namespace std;

//to find next greatest number: [5,5,2,10,8] ==> [5,10,10,-1,-1]

void answer(int arr[], int n){
  int arr2[n];

  stack <int> a;
  int c = n-1;
  a.push(-1);

  while(c>-1){
    while(a.top() < arr[c] && a.top()!=-1){
      a.pop();
    }
    arr2[c] = a.top();
    a.push(arr[c]);
    c--;
  }

  for(int i = 0; i < n;i++){
    cout<<arr2[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int arr[5] = {5,5,2,10,8};
  answer(arr,5);

}
