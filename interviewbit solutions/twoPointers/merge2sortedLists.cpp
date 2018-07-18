#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

void show(vi a){
  int i = 0;
  while(i<a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}


void answer(vi &a, vi &b){
  int i = 0;
  int j = 0;

  while(i<a.size() && j<b.size()){
    if(a[i]<b[j]) i++;
    else{
      a.insert(a.begin()+i, b[j]);
      j++;
      i++;
    }
  }
  while(j<b.size()){
    a.push_back(b[j]);
    j++;
  }
}

int main(){
  vi a = {1,5,8};
  vi b = {5,6,11};
  show(a);

  answer(a,b);


  show(a);
}
