//wrong answer 

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define sc stack<string>

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
  string dir;
  s.push("/");
  for(int i = 0; i < a.length(); i++){
    dir.clear();
    while(a[i] == '/') i++;

    while(i<a.length() && a[i] != '/'){
      dir.push_back(a[i]);
      i++;
    }
    if(dir.compare("..") == 0){
      if(!s.empty()) s.pop();
    }
    else if(dir.compare(".") == 0) continue;

    else if(dir.length() != 0) s.push(dir+"/");

  }

  if(s.empty()) s.push("/");
	q = show(s);
	return q;
}

int main() {
	cout<<answer("/a/./b/../../c/")<<endl;

}
