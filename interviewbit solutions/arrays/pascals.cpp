#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

void show1(vi a){
  int i = 0;
  while(i<a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

void show(vvi a){
  int i =0;
  int j = 0;
  while(i<a.size()){
    show1(a[i]);
    i++;
  }
}



vvi ans(int a){
  vvi z;
  int j = 0;
  int i = 0;
  while(j<a){
    vi c;
    c.push_back(1);
    while(i < j){
      int x = c[i]*(j-i);
      x/=i+1;
      c.push_back(x);
      i++;
    }
    i = 0;
    // show1(c);
    z.push_back(c);
    j++;
  }

  return z;
}

int main(){
  show(ans(5));

}
