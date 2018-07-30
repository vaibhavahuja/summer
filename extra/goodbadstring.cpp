//WRONG ANSWER :P
//need to modify good bad mixed statement; rest all is fine; good question.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

void show(vi a){
  int i = 0;
  while( i < a.size() ){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

string answer(vi a){
  vi c;
  vi v;
  show(a);
  if(a[0] == 0) v.push_back(1);
  else v.push_back(0);

  if(a[0] == 1) c.push_back(1);
  else c.push_back(0);

  int oh = 0;
  int kay = 0;

  for(int i = 1; i < a.size(); i++){
    if(a[i] == 0 || a[i] == -1){
      v.push_back(v[i-1] + 1);
      if(v[i-1] == 4) oh = 1;
    }
    else v.push_back(0);
  }

  for(int i = 1; i < a.size(); i++){
    if(a[i] == 1 || a[i] == -1){
      c.push_back(c[i-1] + 1);
      if(c[i-1] == 2) kay = 1;
    }
    else c.push_back(0);
  }
  cout<<oh<<" "<<kay<<endl;
  show(v);
  show(c);

  // if(oh == 1 && kay == 1) return "MIXED";
  // else if(oh == 1 || kay == 1) return "BAD";
  // return "GOOD";

}


int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    vi a;
    for(int i = 0; i < s.length(); i++){
      if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
        a.push_back(0);
      }else if(s[i] == '?') a.push_back(-1);
      else a.push_back(1);
    }
    cout<<answer(a)<<endl;

  }
}
