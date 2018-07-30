#include <iostream>
using namespace std;


//recursion
int ans(char a[], char b[], int la, int lb, int l1, int l2){
	if(la == l1 && lb == l2) return 0;
	if(la == l1 && lb != l2) return (l2-lb);
	if(la != l1 && lb == l2) return (l1-la);

	if(a[la] == b[lb]) return ans(a,b,la+1,lb+1,l1,l2);
	else{
		return min(min(1+ans(a,b,la,lb+1,l1,l2),1+ans(a,b,la+1,lb,l1,l2)), 1+ans(a,b,la+1,lb+1,l1,l2));
	}
}

//dp solution
int ans2(char a[], char b[], int l1, int l2){
	int dp[l1+1][l2+1];

	for(int i = 0; i <= l1; i++){
		for(int j = 0; j<=l2;j++){

			if(i==0) dp[i][j] = j;
			else if(j==0) dp[i][j] = i;
			else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
			else{
				dp[i][j] = min(min(1+dp[i-1][j], 1+dp[i][j-1]),1+dp[i-1][j-1]);
			}
		}
	}

	return dp[l1][l2];
}

int main() {

	int t;
	cin>>t;

	while(t--){
		int one,two;
		cin>>one>>two;
		char a[one], b[two];
		for(int i = 0; i < one; i++){
			cin>>a[i];
		}
		for(int i = 0; i < two; i++){
			cin>>b[i];
		}
		cout<<ans2(a,b,one,two)<<endl;
		// cout<<ans(a,b,0,0,one,two)<<endl;

	}


}
