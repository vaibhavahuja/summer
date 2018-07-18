#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

string check(string s){
  string str = "";
  for(int i = 0; i < s.length(); i++){
    int p = s[i];
    if(p >=48 && p<=57){
      str+=s[i];
    }else if(p>=65 && p<=90){
      str+=tolower(s[i]);
    }else if(p>=97 && p<=122){
      // cout<<s[i]<<" ";
      str+=tolower(s[i]);
    }
  }
  return str;
}

int palindrome(string s){
  for(int i = 0; i < s.length(); i++){
    if(s[i] != s[s.length() - i - 1]) return 0;
  }
  return 1;
}

int main(){
  string A;
  cin>>A;
  string q = check(A);
  cout<<palindrome(q)<<endl;

}
