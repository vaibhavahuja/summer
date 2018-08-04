#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>


//quick recursive soln

int answer(vi a, int be, int val){
  if(val == 0) return 1;
  else if(val < 0 || be < 0) return 0;

  return answer(a, be, val - a[be]) +  answer(a, be-1, val);
}

// converting same to dp
int coins(vi a, int be, int val){
  int dp[be+1][val+1];
  for(int i = 0; i < be+1; i++){
    for(int j = 0; j < val+1; j++){
      if(j == 0) dp[i][j] = 1;
      else dp[i][j] = 0;
    }
  }

  for(int i = 1; i < be+1; i++){
    for(int j = 1; j < val+1; j++){
      if(j - a[i-1] >= 0) dp[i][j] += dp[i][j-a[i-1]];
      if(i > 0) dp[i][j] += dp[i-1][j];
    }
  }

  return dp[be][val];
}




int main(){
  int t;
  cin>>t;
  while(t--){
    int m;
    cin>>m;
    vi a;
    while(m--){
      int p;
      cin>>p;
      a.push_back(p);
    }
      int n;
      cin>>n;
      cout<<coins(a, a.size(), n)<<endl;;
  }
  // vi a = {1,2,3};
  // answer2(a, 10);
  // cout<<endl;
  // cout<<endl;
  //
  // count(a, 4, 10);
  // int count = 0;
  // cout<<answer(a, a.size()-1, 10);
  // cout<<count<<endl;
}
