#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>



void show(vi a){
  int i = 0;
  while(i < a.size()){
    cout<<a[i]<<' ';
    i++;
  }
  cout<<endl;
}

void show2(vvi a){
  int i = 0;
  while(i<a.size()){
    show(a[i]);
    i++;
  }
  cout<<endl;
}


void answer(vi inp, int be, vi out, int val, vvi &z){
  if(be == inp.size() || val < 0){
    return;
  }
  if(val == 0){
    sort(out.begin(), out.end());
    z.push_back(out);
    // show(out);
    return;
  }

  out.push_back(inp[be]);
  answer(inp, be, out, val - inp[be], z);
  out.pop_back();
  answer(inp, be+1, out, val, z);
}

vvi myFinal(vi a, int b){
  vvi z;
  sort(a.begin(), a.end());
  vi c;
  c.push_back(a[0]);
  for(int i = 1; i < a.size(); i++){
    if(a[i] != a[i-1]){
      c.push_back(a[i]);
    }
  }
  vi out;
  answer(c, 0, out, b, z);

  return z;
}

int main(){
  // vi inp = {1, 5, 6, 8};
  vi inp = {2,2,2,3,3,6,3,6,7};
  show2(myFinal(inp, 7));
  // vi out;
  // answer(inp, 0, out, 7);
}
