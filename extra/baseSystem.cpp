//got 8 on 12 correct test cases. Cannot figure out why not rest 4.

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;

#define mci map<char, long>

void show(mci a){
  mci :: iterator it;
  for(it = a.begin(); it != a.end(); it++){
    cout<<it->first<<" "<<it->second<<endl;
  }
  cout<<endl;
}

long answer(string s){
  mci tab;

  long q = 0;
  for(long i = 0; i < s.length(); i++){
    if(tab.find(s[i]) == tab.end()) {tab[s[i]] = q; q+=1;}
  }

  long min = tab[s[0]];
  long k = 0;
  while(s[k] == s[0]) k++;

  long p = tab[s[0]];
  tab[s[0]] = tab[s[k]];
  tab[s[k]] = p;

  long base = tab.size();
  // cout<<base<<endl;
  long answer = 0;
  for(long i = 0; i < s.length(); i++){
    // cout<<base<<" "<<s.length()-i<<endl;
    long qw = tab[s[i]]*pow(base,s.length() - i - 1);
    // cout<<qw<<endl;
    answer += qw;
  }

  return answer;
  // show(tab);


}


int main(){
  // string s = "cats";
  string s = "11001";
  cout<<answer(s);
}
