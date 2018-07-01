//problem statement:
// Find maximum value of Sum( i*arr[i]) with:
// only rotations on given array allowed

#include <iostream>
using namespace std;

int answer(int arr[], int n){
  int basicSum = 0;
  int S = 0;

  for(int i=0;i<n;i++){
    basicSum += arr[i];
    S += i*arr[i];
  }
  int x = S;
  for(int i=n-1;i>=0;i--){
    if(S + basicSum - n*arr[i]  > x){
      x = S + (basicSum - n*arr[i]);
    }
    S += basicSum - n*arr[i];
  }
  return x;

}

int main(){
  // int arr[4] = {2,10,1,20};
  int arr[10] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout<<answer(arr,10);
}
