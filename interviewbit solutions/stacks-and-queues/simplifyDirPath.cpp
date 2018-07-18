#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define sc stack<char>

string show(sc s){
	string t;
	while(!s.empty()){
		t+=s.top();
		s.pop();
	}
	reverse(t.begin(), t.end());
	return t;
}

string answer(string a){
	sc s;
	string q;

  for(int i = 0; i < a.length(); i++){

  }

	q = show(s);
	return q;
}

int main() {
	cout<<answer("/////")<<endl;

}
