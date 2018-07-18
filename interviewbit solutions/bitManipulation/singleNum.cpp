#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

int singleNum(vi a){
  int i = 0;
  int p = 0;
  while(i < a.size()){
    p ^= a[i];
    i++;
  }
  return p;

}

int main(){
  vi a;
  a.push_back(2);
  a.push_back(5);
  a.push_back(2);
  a.push_back(3);
  a.push_back(3);

  cout<<singleNum(a);


}
