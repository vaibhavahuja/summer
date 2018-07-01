#include <iostream>
using namespace std;

//using recursion
int lcs(char a[], char b[], int m, int n){
	if(m==0 || n==0) return 0;
	if(a[m-1] == b[n-1]) return 1+lcs(a,b,m-1,n-1);
	else if(a[m-1] != b[n-1]) return max(lcs(a,b,m,n-1), lcs(a,b,m-1,n));
}

int lcs2(char a[], char b[], int m, int n){
	int mem[m+1][n+1];
	for(int i = 0; i < m+1 ; i++){
		for(int j = 0; j < n+1; j++){
			if(i==0 || j == 0) mem[i][j] = 0;
			else if(a[i-1] == b[j-1]) mem[i][j] = 1+mem[i-1][j-1];
			else mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
		}
	}

	return mem[m][n];
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int a1,b1;

		cin>>a1>>b1;

		char a[a1], b[b1];

		for(int i = 0;i < a1; i++){
			cin>>a[i];
		}

		for(int i = 0;i < b1; i++){
			cin>>b[i];
		}

		cout<<lcs2(a,b,a1,b1)<<endl;

	}


}
