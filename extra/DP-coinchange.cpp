#include <iostream>
using namespace std;
// Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins,
// what is the minimum number of coins to make the change?
//
// Input: coins[] = {25, 10, 5}, V = 30
// Output: Minimum 2 coins required
// We can use one coin of 25 cents and one of 5 cents
//
// Input: coins[] = {9, 6, 5, 1}, V = 11
// Output: Minimum 2 coins required
// We can use one coin of 6 cents and 1 coin of 5 cents
// 7540 46
// 13 96 38 43 17 31 53 85 59 87 22 100 12 24 63 79 36 93 73 14 34 54 3 95 46 15 40 88 58 81 99 51 35 11 41 55 42 97 10 77 48 16 44 76 18 84


int coinChangeRecur(int coins[], int n, int len){
  if(n<=0) return 0;
  int ans = 1e5;

  for(int i = 0; i < len; i++){
    ans = min(ans,1+coinChangeRecur(coins,n-coins[i],len));
  }
  return ans;
}

int coinChangeDP(int coins[], int n, int len){
  int arr[n+1];
  for(int i = 0; i <= n; i++){
    arr[i] = 1e5;
  }
  arr[0] = 0;

  int j = 0;
  while(j<n+1){
    for(int i = 0; i < len; i++){
      if(coins[i] <= j){
        arr[j] = min(arr[j], 1+arr[j-coins[i]]);
      }
    }
    j++;
  }

  return arr[n]==1e5?-1:arr[n];
}


int main(){
  // int arr[4] = {9,6,5,1};
  // int arr[3] =
  // cout<<coinChangeRecur(arr,11,4);
  int t;
  cin>>t;
  while(t--){
    int v,n;
    cin>>v>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
      cin>>arr[i];
    }
    cout<<coinChangeDP(arr,v,n);

  }
  // cout<<coinChangeDP(arr,11,4);


}
