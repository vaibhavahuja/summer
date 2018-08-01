#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define mci map<char,int>

void show(mci table){
  mci::iterator it;
  for(it = table.begin(); it != table.end(); it++){
    cout<<it->first<<" "<<it->second<<endl;
  }
  cout<<endl;
}

int answer(string a){
  mci table;
  int i = 0;
  int j = 0;
  int cnt = 0;
  int maxcnt = 0;
  mci::iterator it;

  while(j < a.length()){
    if(table.find(a[j]) == table.end()){
      table[a[j]] = 1;
      j++;
      cnt++;
    }else if(table.find(a[j]) != table.end()){
      while(table.find(a[j]) != table.end()){
        table.erase(a[i]);
        i++;
        cnt--;
      }
      table[a[j]] = 1;
      j++;
      cnt++;
    }
    // show(table);
    maxcnt = max(cnt, maxcnt);
  }
  return maxcnt;
  // cout<<maxcnt<<endl;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    cout<<answer(s)<<endl;
  }
  // cout<<answer("abcabcbb");

}
