//see if you can reduce time complexity. 3 test cases pending.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>


int minSubs(string s){
  int check[27] = {0};
  for(int i = 0; i < s.length(); i++){
    int z = s[i] - 'a';
    check[z] += 1;
  }
  int ret = 0;
  for(int i = 0; i < 26; i++){
    if(check[i]%2!=0) ret+=1;
  }
  return ret/2;
}


string answer(string s, vi l, vi r, vi k){
  string ans = "";
  for(int i = 0; i < l.size();i++){
    string q = "";
    int min = k[i];
    for(int j = l[i]; j<=r[i];j++){
      q+=s[j];
    }
    // cout<<q<<" "<<k[i]<<endl;
    if(k[i]>=q.length()/2) ans+="1";
    else{
      if(k[i]>=minSubs(q)) ans+="1";
      else ans+="0";
    }
  }
  return ans;
}

int main(){
  // string s;
  // cin>>s;
  // cout<<minSubs(s);
  vi l;
  l.push_back(1);
  l.push_back(1);
  l.push_back(2);

  vi r;
  r.push_back(4);
  r.push_back(3);
  r.push_back(3);

  vi k;
  k.push_back(3);
  k.push_back(3);
  k.push_back(0);

  // int p = 'z'-'a'+1;
  // cout<<p<<endl;
  cout<<answer("bcbab",l,r,k);
  // cout<<minSubs("accdemlasfzzz");
}
