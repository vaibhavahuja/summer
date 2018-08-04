//any doubt; read code; self sufficient;
//try to make it on paper

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show(string s, int a, int b){
  for(int i = a; i < b; i++){
    cout<<s[i];
  }
  cout<<endl;
}

int lps(string s){
  int n = s.length();
  int dp[n][n];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n ; j++){
      dp[i][j] = 0;
    }
  }

  for(int i = 0; i < n; i++){
    dp[i][i] = 1;
  }


  for(int i = 2; i <= n; i++){
    for(int j = 0; j <= n - i; j++){
      int m = j + i - 1;
      if(s[j] == s[m]) dp[j][m] = 2 + dp[j+1][m-1];
      else dp[j][m] = max(dp[j+1][m], dp[j][m-1]);
    }
  }


  return dp[0][s.length() - 1];
  // for(int i = 0; i < n; i++){
  //   for(int j = 0; j < n ; j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

}


int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    cout<<lps(s)<<endl;
  }
// lps("agbdba");

}
