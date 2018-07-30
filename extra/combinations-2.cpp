#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define vi vector<int>

void show(vi a){
  int p = 0;
  while(p < a.size()){
    cout<<a[p]<<" ";
    p++;
  }
  cout<<endl;
}

void combinations(vi a, int be, vi out, int k){
  if(be == a.size() && out.size() != k){
    return;
  }
  if(out.size() == k){
    show(out);
    return;
  }
  out.push_back(a[be]);
  combinations(a, be+1, out, k);
  out.pop_back();
  combinations(a, be+1, out, k);

}


int main(){
  vi a = {1,2,3,4};
  vi out;
  combinations(a, 0, out, 2);

}
