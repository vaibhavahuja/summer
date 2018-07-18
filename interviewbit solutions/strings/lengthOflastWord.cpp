#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


int answer(string s){
  int p = 0;
  int q = 0;
  for(int i = 0; i < s.length(); i++){
    if(s[i] == ' ') q = 0;
    else { q++; p = q; }
  }
  return p;
}

int main(){
  string p = "oskpakd  asopkdp aspokd";

  cout<<answer(p)<<endl;


}
