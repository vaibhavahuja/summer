#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

int answer(vvi a){
  int mn = a[0][0], mx = a[0][0], n=a.size(), m=a[0].size();
  for(int i = 0; i < n; i++){
    mn = min(mn,a[i][0]);
    mx = max(mx, a[i][m-1]);
  }
  int desired = (n*m + 1)/2;
  while(mn < mx){
    int mid = mn + (mx - mn)/2;
    int place = 0;
    for(int i = 0; i < n; i++){
      place += upper_bound(a[i].begin(), a[i].end(), mid) - a[i].begin();
    }
    if(place<desired) mn = mid+1;
    else mx = mid;
  }
  return mn;
}



int main(){
  vvi a;

  vi b;
  b.push_back(1);
  b.push_back(5);
  b.push_back(7);

  a.push_back(b);

  vi c;
  c.push_back(4);
  c.push_back(10);
  c.push_back(11);

  a.push_back(c);

  vi d;
  d.push_back(8);
  d.push_back(11);
  d.push_back(12);
  a.push_back(d);

  cout<<answer(a);
}
