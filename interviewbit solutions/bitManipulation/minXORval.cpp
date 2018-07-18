#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

int answer(vi &a){
  sort(a.begin(), a.end());
  int m = 1e5;

  int i = 0;
  int p;
  while(i<a.size()-1){
    p = a[i]^a[i+1];
    m = min(p,m);
    i++;
  }
  return m;

}

int main(){
  vi a;
  a.push_back(9);
  a.push_back(0);
  a.push_back(7);
  a.push_back(4);

  cout<<answer(a);

}
