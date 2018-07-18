#include <iostream>
using namespace std;

bool palin(string s, int be, int end){
	while(end>be){
		if(s[be]!=s[end]) return false;
		be++;
		end--;
	}
	return true;
}

string show(string s, int i){
	string p;
	for(int j = 0; j<=i; j++){
		p+=s[j];
	}
	return p;
}

int answer(string s){
	for(int i = s.length()-1; i>=0; i--){
    if(palin(s,0,i)){
      // cout<<palin(s,0,i)<<" "<<show(s,i)<<endl;
      cout<<s.length()-i-1;
      break;
    }
	}
}

int main() {
	// int t;
	// cin>>t;
	// while(t--){
		string s;
	// 	cin>>s;
  s = "abc";
	answer(s);
	// }
}
