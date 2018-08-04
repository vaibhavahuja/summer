#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//recursive solution
//n eggs and k floors
int eggDrop(int n, int k){
  if(k==1 || k==0) return k;
  if(n==1) return k;
  int mn = 1e5, res;
  for(int i=1; i<=k; i++){
    res = max(eggDrop(n-1,i-1), eggDrop(n, k-i));
    mn = min(res, mn);
  }
  return mn + 1;
}

//dp solution

int egg(int n, int k){
  int dp[n+1][k+1];
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= k; j++){
      if(j==1 || j == 0) dp[i][j] = j;
      if(i==1) dp[i][j] = j;
    }
  }

  for(int i = 2; i <= n; i++){
    for(int j = 2; j <= k; j++){
      dp[i][j] = 1e5;
      for(int q = 1; q<=j; q++){
        int res = 1+max(dp[i-1][q-1], dp[i][j-q]);
        dp[i][j] = min(dp[i][j], res);
      }
    }
  }

  return dp[n][k];
  // for(int i = 0; i <= n; i++){
  //   for(int j = 0; j <= k; j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    cout<<egg(n,k)<<endl;
  }

}
