#include <iostream>
using namespace std;

//recursive solution
int ans(int val[], int wt[], int w, int n){
	if(n==0 || w==0) return 0;

	//do not include if it is greater than weight
	if(wt[n-1] > w) return ans(val, wt, w,n-1);

	//check with including it and one without
	if(w>=wt[n-1])return max(ans(val,wt,w-wt[n-1],n-1)+val[n-1], ans(val, wt, w,n-1));
}

//memoized solution --> correct this one

int ans2(int val[], int wt[], int w, int n){
	int memo[w+1][n+1];
	memo[0][0] = 0;

	for(int i = 0; i < n+1; i++){
		for(int j = 0; j<=w+1; j++){
			if(i==0||w==0) memo[i][j] = 0;
			else if(wt[i-1] > w) memo[i][w] = memo[i-1][w];
			else memo[i][w] = max(val[i-1]+memo[i-1][w-wt[i-1]], memo[i-1][w]);
		}

	}


	return memo[n][w];
}


int main() {
	int val[3] = {60,100,120};
	int wt[3] = {10,20,30};
	int W = 50;
	// cout<<ans2(val,wt,W,3);
  cout<<ans(val,wt,W,3);
}
