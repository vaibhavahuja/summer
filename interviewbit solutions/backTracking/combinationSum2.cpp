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

void answer(vi a, int be, vi out, int val, vvi &z, mvi &myMap){
  if(be == a.size() + 1 || val < 0) return;
  if(val == 0){
    sort(out.begin(), out.end());

    if(myMap.find(out) == myMap.end()){
        // cout<<"found"<<endl;
        myMap[out] = 1;
        z.push_back(out);
        // show2(z);
    }
      // show(out);
    return;
  }

  out.push_back(a[be]);
  answer(a, be+1, out, val - a[be],z, myMap);

  out.pop_back();
  answer(a, be+1, out, val, z, myMap);
}


vvi answer(vi a, int b){
  vi out;
  vvi z;
  mvi myMap;
  answer(a, 0, out, b, z, myMap);
  sort(z.begin(), z.end());
  return z;
}

int main(){
  vi a = {15, 8, 15, 10, 19, 18, 10, 3, 11, 7, 17};
  show2(answer(a, 33));
}
