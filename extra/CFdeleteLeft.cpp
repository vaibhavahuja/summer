//getting wrong ans.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

ll answer(string a, string b){
  int l1 = a.length();
  int l2 = b.length();

  int i = l1-1;
  int j = l2-1;

  ll ans = 0;
  while(i >= 0 || j>=0){
    if(a[i] != b[j]) return l1+l2 - 2*ans;
    ans++;
    i--;
    j--;
  }
}

int main(){
  // int t;
  // cin>>t;
  // while(t--){
    string a,b;
    cin>>a>>b;
    cout<<answer(a,b)<<endl;
  // }


}
