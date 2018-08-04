//remember C(n,k) = C(n-1,k-1) + C(n-1,k);
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//basic recursive solution
long coeff(long n, long k){
  if(n==k || k == 0) return 1;
  return coeff(n-1, k-1) + coeff(n-1, k);
}

//dp solution
long co(long n, long k){
  long dp[n+1][k+1];

  for(long i = 0; i < n+1; i++){
    for(long j = 0; j < k+1; j++){
      if(i==j || j==0) dp[i][j] = 1;
      else dp[i][j] = 0;
    }
  }

  for(long i = 1; i < n+1; i++){
    for(long j = 1; j < k+1; j++){
      if(i != j) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%1000000007;
    }
  }

  return dp[n][k];
  // for(long i = 0; i < n+1; i++){
  //   for(long j = 0; j < k+1; j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

}


int main(){
  // cout<<coeff(10, 2);
  long t;
  cin>>t;
  while(t--){
    long n, r;
    cin>>n>>r;
    cout<<co(n,r)<<endl;
  }
}
