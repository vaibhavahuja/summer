#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer(string a, string b){
  int m = a.size();
  int n = b.size();
  int dp[m+1][n+1];

  for(int i = 0; i < m+1; i++){
    for(int j = 0; j < n+1; j++){
      if(i == 0) dp[i][j] = j;
      else if(j == 0) dp[i][j] = i;
      else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
      else dp[i][j] = 1+min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
    }
  }

  return dp[m][n];

}

int main(){
  int t;
  cin>>t;
  while(t--){
    int q, w;
    cin>>q>>w;
    string a,b;
    cin>>a>>b;
    cout<<answer(a,b)<<endl;;
  }
  // string a = "sunday";
  // string b = "saturday";

}
