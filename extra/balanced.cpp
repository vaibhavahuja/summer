#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define sc stack<char>

string answer(string s){
  sc a;
  for(int i = 0; i < s.length(); i++){
    if(s[i] == '(' || s[i] == '{' || s[i] == '[') a.push(s[i]);
    else if(!a.empty()){
      if(s[i] == ')' && a.top() == '(') a.pop();
      else if(s[i] == ']' && a.top() == '[') a.pop();
      else if(s[i] == '}' && a.top() == '{') a.pop();
      else return "not balanced";
      
    }
    else return "not balanced";
  }
  if(a.empty()) return "balanced";
  else return "not balanced";
}

int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    cout<<answer(s)<<endl;
  }

}
