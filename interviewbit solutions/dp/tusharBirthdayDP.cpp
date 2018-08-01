#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define mi map<int, int>
#define vi vector<int>
#define vvi vector<vi>

void show(vi a){
  int i =0;
  while (i < a.size()) {
    cout<<a[i]<<" ";
    i++;
  }
}


vi maximum(vi a, int val){
  mi table;
  for(int i = 0; i < a.size(); i++){
    if(table.find(a[i]) == table.end()) table[a[i]] = i;
  }
  vi c;
  sort(a.begin(), a.end(), comp());
  int value = val;
  while(value>a[0]){
    c.push_back(table[a[0]]);
    value -= a[0];
  }
  return c;
}


int main(){
  vi a = {6,8,4,5,7};

  vi z;
  show(maximum(a, 11));
  // cout<<checkMax(a, 11, z);

}
