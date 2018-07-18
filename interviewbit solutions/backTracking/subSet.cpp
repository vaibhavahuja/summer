#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>



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

void answer(vi inp, int be, vi out, vvi &c){
  if(be==inp.size()){
    c.push_back(out);
    // show(out);
    return;
  }
  answer(inp, be+1, out, c);
  out.push_back(inp[be]);
  answer(inp, be+1, out, c);
}


vvi subsets(vi &inp){
  sort(inp.begin(), inp.end());
  vvi c;
  vi out;
  answer(inp, 0, out, c);
  sort(c.begin(), c.end());
  show1(c);
}




int main(){
  vi a = {15,20,12,19,4};
  // sort(a.begin(), a.end());
  vi out;
  // answer(a, 0, out);
  subsets(a);
}
