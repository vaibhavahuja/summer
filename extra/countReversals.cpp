#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
#define sc stack<char>


int answer(string s){
  sc bracket;
  if(s.length()%2 != 0) return -1;
  // cout<<"yea"<<endl;
  for(int i = 0; i < s.length(); i++){
    // if(!bracket.empty())
    if(!bracket.empty() && bracket.top() == '{' && s[i] == '}') bracket.pop();
    else bracket.push(s[i]);
  }
  if(bracket.empty()) return 0;
  float a = 0, b = 0;
  while(!bracket.empty()){
    if(bracket.top() == '{') a++;
    else b++;
    // cout<<bracket.top()<<" ";
    bracket.pop();
  }
  // double p;
  float p = ceil(a/2);
  float q = ceil(b/2);

  return (int)p+q;
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
