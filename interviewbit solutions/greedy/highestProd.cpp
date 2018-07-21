#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>


int highest(vi a){
  sort(a.begin(), a.end());
  return max(a[a.size()-1]*a[a.size()-2]*a[a.size()-3], a[0]*a[1]*a[a.size()-1]);
}

int main(){
  vi a = { 0, -1, 3, 100, -70, -50 };
  cout<<highest(a);
}
