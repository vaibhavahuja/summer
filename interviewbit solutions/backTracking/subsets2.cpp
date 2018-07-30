#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define mvi map<vi, int>


void show(vi a){
  int i = 0;
  while(i<a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

void show1(vvi a){
  int i = 0;
  while(i<a.size()){
    show(a[i]);
    i++;
  }
  cout<<endl;
}


void answer(vi inp, int be, vi out, vvi &z, mvi &myMap){
  if(be == inp.size()){
    sort(out.begin(), out.end());
    if(myMap.find(out) == myMap.end()){
      myMap[out] = 1;
      z.push_back(out);
      // show(out);
    }
    return;
  }
  out.push_back(inp[be]);
  answer(inp, be+1, out, z, myMap);
  out.pop_back();
  answer(inp, be+1, out, z, myMap);
}

vvi final(vi a){
  vi out;
  vvi z;
  mvi myMap;
  answer(a, 0, out, z, myMap);

  sort(z.begin(), z.end());
  return z;
  // show(z);
}


int main(){
  vi inp = {1,2,2};
  show1(final(inp));
}
