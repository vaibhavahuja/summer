#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define sc stack<char>

bool checkPalin(string s){
  for(int i = 0; i < s.length(); i++){
    if(s[i] != s[s.length()-1-i]) return false;
  }
  return true;
}

bool parent(string s){
  return checkPalin(s);
}

bool odd(string s){
  string p = "";
  for(int i = 0; i<s.length(); i+=2){
    p+=s[i];
  }
  return checkPalin(p);
}

bool even(string s){
  string p = "";
  for(int i = 1; i < s.length(); i+=2){
    p+=s[i];
  }
  return checkPalin(p);
}



string answer(string s){
  // int p=0;
  int e=0;
  int o=0;
  // int t=0;

  if(parent(s)) return "PARENT";
  else{
    if(odd(s)) o = 1;
    if(even(s)) e = 1;

    if(o==1 && e==1) return "TWIN";
    else if(o==1 && e==0) return "ODD";
    else if(o==0 && e == 1)return "EVEN";
  }

  return "ALIEN";
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
