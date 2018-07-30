#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define vi vector<int>

void show(vi a){
  int i = 0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}


void ans(vi inp, int be, vi out, int val){
  if(be == inp.size() || val < 0) return;
  if(val == 0){
    show(out);
    return;
  }

  for(int i = 0; i < inp.size(); i++){
    out.push_back(inp[i]);
    ans(inp, be, out, val - inp[i]);
  }
  // out.push_back(inp[be]);
  // ans(inp, be, out, val - inp[be]);
  // out.pop_back();
  // ans(inp, be+1, out, val);
}


int main(){
  vi a = {1,5,6,8};
  vi out;
  ans(a, 0, out, 11);
}
