#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// #define D 1e5

int minimum(int arr[100][100], int m, int n){
  int dp[m+1][n+1];
  for(int i = 0; i < m+1; i++){
    for(int j = 0; j < n+1; j++){
      dp[i][j] = 0;
    }
  }

  for(int i = 1; i < m+1; i++){
    for(int j = 1; j < n+1; j++){
      if(i==1) dp[i][j] = arr[i-1][j-1] + max(dp[i-1][j], dp[i][j-1]);
      else dp[i][j] = arr[i-1][j-1] + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
    }
  }

  return dp[m][n];
}


int main(){
  int arr[3][100] = {{1,2,3},{4,8,2},{1,5,3}};
  cout<<minimum(arr, 3, 3)<<endl;
}
