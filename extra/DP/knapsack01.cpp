#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define vi vector<int>

int knapsack(vi val, int be, vi wt, int w){
  if(w == 0 || be == 0) return 0;
  if(wt[be] > w) return knapsack(val, be-1, wt, w);
  else return max(val[be] + knapsack(val, be-1, wt, w-wt[be]), knapsack(val, be-1, wt, w));
}




//dp solution for the same

int sack(vi val, vi wt, int w){
  int be = val.size();
  int dp[be+1][w+1];
  // for(int i = 0; i < be+1; i++){
  //   for(int j = 0; j < w+1; j++){
  //     dp[i][j] = 0;
  //   }
  // }

  for(int i = 0; i < be+1; i++){
    for(int j = 0; j < w+1; j++){
      if(i==0 || j==0) dp[i][j] = 0;
      else if(wt[i] > j) dp[i][j] = dp[i-1][j];
      else dp[i][j] = max(dp[i-1][j], val[i] + dp[i-1][j-wt[i]]);
    }
  }
  return dp[be][w];
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int W;
    vi val, wt;
    int n;
    cin>>n>>W;
    int q = n;
    while(q--){
      int qw;
      cin>>qw;
      val.push_back(qw);
    }
    while(n--){
      int qwe;
      cin>>qwe;
      wt.push_back(qwe);
    }
    cout<<sack(val, wt, W)<<endl;
    // cout<<knapsack(val, val.size(), wt, W);
    //


  }

}
