#include <iostream>
using namespace std;

//using recursion
int maxP(int arr[], int be, int end, int n, int i){
	if(be>end) return 0;
	int max_profit;
	max_profit = max(maxP(arr,be+1,end,n,i+1)+arr[be]*(i), maxP(arr, be, end-1,n,i+1)+arr[end]*(i));


	return max_profit;
}

//using DP
// int maxDP(int arr[],)

int N = 5;
int arr[5] = {2,4,6,2,5};
int memo[5][5];


int profit(int be, int end){
	if(be>end) return 0;
	int year = N - (end-be);
	if(memo[be][end] != -1) return memo[be][end];

	return memo[be][end] = max((profit(be+1,end)+arr[be]*year),(profit(be,end-1)+arr[end]*year));
}


int main() {
	for(int i = 0; i < 5; i ++){
		for(int k = 0; k < 5; k++){
			memo[i][k] = -1;
		}
	}
	N = 5;
	// cout<<maxP(arr,0,4,5,1);
	cout<<profit(0,4);
}
