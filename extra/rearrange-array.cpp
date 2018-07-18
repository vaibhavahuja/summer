#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//very good technique to encode two numbers in one to reduce space.
#define vi vector<int>

void show(vi a){
  int i = 0;
  while(i<a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

int getMax(vi a){
  int i = 0;
  int maxi = 0;
  while(i<a.size()){
    maxi = max(maxi,a[i]);
    i++;
  }
  return maxi;
}



void arrange(vi &a){
  int m = getMax(a)+1;
  int i = 0;
  while(i<a.size()){
    a[i] += (a[a[i]]%m)*m;
    i++;
  }

  i = 0;
  while(i<a.size()){
    int p = a[i]/m;
    a[i] = p;
    i++;
  }

}

int main(){
  vi a;
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);
  a.push_back(4);
  a.push_back(1);

  arrange(a);
  show(a);
  // show(a);
  // cout<<getMax(a);

}
