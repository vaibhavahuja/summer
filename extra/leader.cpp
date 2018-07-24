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

vi answer(vi a){
  int max = -1;
  int p = a.size() - 1;
  vi c;
  while( p > -1){

    if(a[p] > max){
      c.push_back(a[p]);
      max = a[p];
    }
    p--;
  }
  return c;
}


int main(){
  int t;
  cin>>t;
  while(t--){
    vi a;
    int n;
    cin>>n;
    while(n--){
      int p;
      cin>>p;
      a.push_back(p);
    }

    vi c = answer(a);
    reverse(c.begin(), c.end());
    show(c);
  }
}
