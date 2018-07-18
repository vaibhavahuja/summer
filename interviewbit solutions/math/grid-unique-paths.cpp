#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//recursive approach
int answer(int a, int b){
  if(a==1 || b == 1) return 1;
  return answer(a-1,b) + answer(a,b-1);
}

//dp approach
int ans(int a, int b){
  int dp[a+1][b+1];
  for(int i = 0; i <= a; i++){
    for(int j = 0; j <= b; j++){
      if(i==1||j == 1) dp[i][j] = 1;
      else dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
  }
  return dp[a][b];
}

int main(){
  cout<<ans(5,5);
}
