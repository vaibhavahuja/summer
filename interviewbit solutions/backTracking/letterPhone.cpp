#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define vs vector<string>
#define vc vector<char>

void show(auto out){
  int i = 0;
  while(i < out.size()){
    cout<<out[i]<<" ";
    i++;
  }
  cout<<endl;
}

char map[][5] = {"0", "1", "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void answer(string inp, int be, char out[], int en, vs &q){
  if(inp[be] == '\0'){
    out[en] = '\0';
    q.push_back(out);
    // cout<<out<<endl;
    return;
  }

  int digit = inp[be] - '0';
  char code[5] = "";
  strcpy(code, map[digit]);

  int j = 0;
  while(code[j] != '\0'){
    out[en] = code[j];
    answer(inp, be+1, out, en+1, q);
    j++;
  }
}

vs answer(string a){
  vs q;
  char out[1000];
  answer(a, 0, out, 0, q);
  show(q);
}




int main(){
  // char inp[] = "23";
  string inp = "234";
  char out[100];
  // answer(inp, 0, out, 0);
  answer(inp);

}
