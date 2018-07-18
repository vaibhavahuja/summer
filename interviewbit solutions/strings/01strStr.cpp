//need to fix this

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int answer(string h, string n){
  int i = 0;
  int j = 0;
  int p = 0;
  string m = "";
  if(h==n) return 0;
  while(i < h.length()){
    if(j == n.length()) return p;
    if(h[i] == n[j]) j++;
    else j=0;
    if(j == 1) p = i;
    i++;
  }
  return -1;
}

int main(){
  cout<<answer("bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba","babaaa");
}
