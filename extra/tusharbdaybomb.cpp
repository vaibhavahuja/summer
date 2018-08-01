#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

void show(vi a){
  int i = 0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

void checkMax(vi a, int be, vi out, int val, vvi &z){
  if(val==0 || be == a.size()){
    // show(out);
    z.push_back(out);
    return;
  }else if(val<0) return;
  // if(a<0) return;
  out.push_back(be);
  checkMax(a, be, out, val-a[be], z);
  out.pop_back();
  checkMax(a, be+1, out, val, z);
}

vi answer(int b, vi a){
  vi out;
  vvi z;
  checkMax(a, 0, out, b, z);
  vi pqw;
  int sze = 0;
  for(int i = 0; i < z.size(); i++){
    // show(z[i]);
    // cout<<z[i].size()<<" ya"
    if(z[i].size() > sze){
      pqw = z[i];
      sze = z[i].size();
    }
  }

  return pqw;
}

int main(){
  vi a = {6,8,5,4,7};
  show(answer(11, a));


}
