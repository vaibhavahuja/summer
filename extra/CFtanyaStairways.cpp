//accepted
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

void show(vi p){
  int i = 0;
  while(i<p.size()){
    cout<<p[i]<<" ";
    i++;
  }
  cout<<endl;
}

void answer(vi c){
  int i = 1;
  vi p;
  int j = 0;
  int ans = 0;
  c.push_back(1);
  while(i<c.size()){
    j++;
    if(c[i] == 1){
      p.push_back(j);
      ans++;
      j = 0;
    }
    i++;
  }

  cout<<ans<<endl;
  show(p);
}



int main(){
  int n;
  cin>>n;
  vi c;
  while(n--){
    int p;
    cin>>p;
    c.push_back(p);
  }
  answer(c);
}
