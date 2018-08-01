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

vi longest(vi a){
  vi ans(a.size(), 1);

  for(int i = 0; i < a.size(); i++){
    for(int j = 0; j < i; j++){
      if(a[i] > a[j]) ans[i] = max(ans[i], ans[j] + 1);
    }
  }
  // show(ans);
  return ans;
}

int answer(vi a){
  vi c = a;
  vi b = longest(c);
  reverse(c.begin(), c.end());
  vi d = longest(c);
  reverse(d.begin(), d.end());

  int i = 0;
  int ans = 0;
  while(i < a.size()){
    ans = max(b[i] + d[i] - 1, ans);
    i++;
  }
  return ans;
}

int main(){
  // vi a = {1,11,2,10,4,5,2,1};
  // vi a = {1 3 5 6 4 8 4 3, 2, 1}
  vi a = {1,3,5,6,4,8,4,3,2,1};
  cout<<answer(a);
  // longest(a);
  // reverse(a.begin(), a.end());
  // longest(a);
}
