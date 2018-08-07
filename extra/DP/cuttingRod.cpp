#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define vi vector<int>


//recursive soln.
int rodCut(vi arr, int n, int i){
  if(n==0 || i < 0) return 0;
  if(n<0) return -1e5;

  return max(arr[i] + rodCut(arr, n-i-1, i), rodCut(arr, n, i-1));
}


//dp soln.
int cutRod(int n, vi arr){
  int dp[n+1][n+1];

  //i is n and j is i in comparison with above rodCut function

  for(int i = 0; i <= n; i++){
    for(int j = 0; j<=n; j++){
      if(i == 0) dp[i][j] = 0;
      else dp[i][j] = -1e5;
      if(i - j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i-j-1][j] + arr[j]);
      if(i - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
    }
  }

  return dp[n][n];
  for(int i = 0; i <= n; i++){
    for(int j = 0; j<=n; j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }

}


int main(){
  vi arr = {1, 5, 8, 9, 10, 17, 17, 20};
  cout<<rodCut(arr, 8, 7)<<endl;
  cout<<cutRod(8, arr)<<endl;

}
