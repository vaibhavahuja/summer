#include <iostream>
using namespace std;

string answer(string s, int n){
	string strArr[n];
	int i = 0;
	int j = 0;
	int p = 0;

	while(i<s.length()){
		if(j==0) p = 1;
		if(j==n-1) p = -1;
		strArr[j] += s[i];
		j+=p;
		i++;
	}
	string q = "";
	for(int i = 0; i < n; i++){
		q+=strArr[i];
	}
	return q;
}

int main(){
	int t;
	cin>>t;
	while(t--){
			int n;
		string s;
		cin>>s>>n;
		cout<<answer(s,n)<<endl;
	}
}
 
