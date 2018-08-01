#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define mv map<string, vi>
#define vs vector<string>


void show(vi a){
  int i = 0;
  while(i < a.size()){
    cout<<a[i]<<' ';
    i++;
  }
  cout<<endl;
}

void show2(vvi a){
  int i = 0;
  while(i<a.size()){
    show(a[i]);
    i++;
  }
  cout<<endl;
}

vvi answer(const vs &a){
  mv tab;
  int i = 0;
  while(i < a.size()){
    string q = a[i];
    sort(q.begin(), q.end());
    tab[q].push_back(i+1);
    i++;
  }
  vvi finalAns;
  mv::iterator it;
  for(it = tab.begin(); it != tab.end(); it++){
    // cout<<it->first<<" ";
    finalAns.push_back(it->second);
  }



  return finalAns;

}

int main(){
  vs a = {"cat", "dog", "god", "tca"};
  // answer(a);
  show2(answer(a));
}
