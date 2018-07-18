#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

void show(vi c){
  int i =0;
  while(i<c.size()){
    cout<<c[i]<<' ';
    i++;
  }
  cout<<endl;
}

void answer(int n, vi c){
  if(n<=0){
    vi d = c;
    c.push_back(n);
    int p = d.size()-1;
    while(p>=0){
      c.push_back(d[p]);
      p--;
    }
    show(c);
    return;

  }
  c.push_back(n);
  answer(n-5,c);

}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vi c;
    answer(n,c);
  }
}
