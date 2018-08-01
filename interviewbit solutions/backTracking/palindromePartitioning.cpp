#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define vc vector<char>
#define vs vector<string>

bool isPalin(string s, int be, int end){
  int i = be;
  int j = end - 1;
  while(i < j){
    if(s[i] != s[j]) return false;
    i++;
    j--;
  }
  return true;
}


void answer(vc inp, int be, vc out){
  if(be == inp.size()){
    show(out);
    return;
  }

  for(int i = be; i < inp.size(); i++){
    if(answer(inp, ))
  }


}


int main(){
  vc inp = {'a','a','b'};

}
