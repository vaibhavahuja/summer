#include <iostream>
using namespace std;

//recur
int coins(int n){
	if(n<12) return n;

	int m;
	m = coins(n/2)+coins(n/3)+coins(n/4);
	return m;
}

//dp
void coins2(int n){
	int dp[n+1];
	dp[0] = 0;
	for(int i = 0; i < n+1; i++){
		dp[i] = max(max(dp[i/2]+dp[i/3]+dp[i/4], i/2+i/3+i/4),i);
  }

	cout<<dp[n]<<endl;
}


int main(){
	int n;
  while(1){
    cin>>n;
    coins2(n);
  }
}
