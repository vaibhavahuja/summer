#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(int a, int b, int c, int d){
  if(c==a && d==b) return true;
  if(c<a || d<b) return false;
  // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
  return isPossible(a+b,b,c,d)||isPossible(a,b+a,c,d);
}

//dp solution
bool ans(int a, int b, int c, int d){
  bool dp[c+1][d+1];
  if(c==a && d==b) return dp[c][d] = true;
  if(a>c || b>d) return dp[a][b] = false;
  // cout<<a<<" "<<b<<endl;
  return dp[a][b] = ans(a+b,b,c,d)||ans(a,b+a,c,d);
}


int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  // if(isPossible(a,b,c,d)) cout<<"yes"<<endl;
  // else cout<<"no"<<endl;
  cout<<ans(a,b,c,d);
}
