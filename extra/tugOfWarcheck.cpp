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


int main(){
  vi a = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
  // vi a = {-23, -45, -34, -12, 0, -98, -99, -4, -189, -1, -4};
  int i = 0;
  vi pos;
  vi neg;
  while( i < a.size()){
    if(a[i] >= 0) pos.push_back(a[i]);
    else neg.push_back(a[i]);
    i++;
  }
  // sort(pos.begin(), pos.end());
  // sort(neg.begin(), neg.end(), greater<int>());

  show(pos);
  show(neg);

  vi b;
  vi c;
  int firs = 0;
  int sec = 0;
  vi d;
  vi e;
  for(int i = pos.size() - 1; i >= 0; i--){
    if(firs > sec) {sec += pos[i]; e.push_back(pos[i]);}
    else {firs += pos[i]; d.push_back(pos[i]);}
  }

  for(int i = neg.size() - 1; i >= 0; i--){
    if(firs < sec) {sec += neg[i]; e.push_back(neg[i]);}
    else {firs += neg[i]; d.push_back(neg[i]);}
  }

  show(d);
  show(e);

  cout<<firs<<" "<<sec<<endl;


}
