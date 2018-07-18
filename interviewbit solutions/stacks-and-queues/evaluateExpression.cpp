#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define si stack<int>
#define vs vector<string>

void show(si a){
	while(!a.empty()){
		cout<<a.top();
		a.pop();
	}
}


int answer(vs a){
	si s;
	int i = 0;
	int ans = 0;
	while(i<a.size()){
		if(a[i] == "+"){
			ans += s.top();
			s.pop();
			ans += s.top();
			s.pop();
			s.push(ans);
			ans = 0;
		}else if(a[i] == "-"){
			int q = s.top();
			s.pop();
			ans = s.top() - q;
			s.pop();
			s.push(ans);
			ans = 0;
		}else if(a[i] == "*"){
			int q = s.top();
			s.pop();
			ans = s.top()*q;
			s.pop();
			s.push(ans);
			ans = 0;
		}else if(a[i] == "/"){
			int q = s.top();
			s.pop();
			ans = s.top()/q;
			s.pop();
			s.push(ans);
			ans = 0;
		}
		else{
			s.push(stoi(a[i]));
		}
		i++;
	}
	return s.top();
}




int main() {
	vs str  = {"4", "13", "5", "/", "+"};
	cout<<answer(str);
}
