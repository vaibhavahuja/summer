#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>


void show(vi a){
  int i = 0;
  while(i<a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

void show1(vvi a){
  int i = 0;
  while(i<a.size()){
    show(a[i]);
    i++;
  }
  cout<<endl;
}

string convert1(int n, int q){
  string c = "";
  while(n>0){
    if(n%2 != 0) c += "1";
    else c+= "0";
    n/=2;
  }
  reverse(c.begin(), c.end());
  if(c.length() < q){
    string pl = "";
    int qw = 0;
    while(qw<q-c.length()){
      pl+="0";
      qw++;
    }
    pl += c;
    return pl;
  }
  return c;
}

vvi answer(vi a){
  vvi qw;
  for(int i = 0; i < 1<<a.size(); i++){
    string ans = convert1(i, a.size());
    vi l;
    for(int i = 0; i < ans.size(); i++){
      if(ans[i] == '1') l.push_back(a[i]);
    }
    qw.push_back(l);
  }
  sort(qw.begin(), qw.end());
  return qw;
}

int main(){

  vi a = {1,2,3};
  show1(answer(a));
  // cout<<"heyy"<<endl;

}
