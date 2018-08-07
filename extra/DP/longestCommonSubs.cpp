#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer(string a, string b){
  int m = a.length();
  int n = b.length();

  //a rows; b cols.

  int dp[m+1][n+1];
  for(int i = 0; i < m+1; i++){
    for(int j = 0; j < n+1; j++){
      dp[i][j] = 0;
    }
  }

  for(int i = 1; i < m+1; i++){
    for(int j = 1; j < n+1; j++){
      if(a[i-1] == b[j-1]){
        dp[i][j] = 1+dp[i-1][j-1];
      }else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

  // for(int i = 0; i < m+1; i++){
  //   for(int j = 0; j < n+1; j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  return dp[m][n];


}

int main(){
  int t;
  cin>>t;
  while(t--){
    int aw,bw;
    cin>>aw>>bw;
    string a,b;
    cin>>a>>b;
    cout<<answer(a, b)<<endl;
  }


}
