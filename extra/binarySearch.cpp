#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>


int bSearch(vi a, int x){
  int l = 0;
  int r = a.size() - 1;
  while(l <= r){
    int mid = (l+r)/2;
    if(a[mid] == x) return mid;
    else if(a[mid] < x) l = mid + 1;
    else r = mid-1;
  }
  return -1;
}

//finding left most occurrence
int left(vi a, int x){
  int l = 0;
  int r = a.size() - 1;
  int mid;
  int k = -1;
  while(l <= r){
    mid = (l+r)/2;
    if(a[mid] == x){
      k = mid;
      r = mid - 1;
      // r = mid-1;
    }else if(a[mid] < x){
      l = mid + 1;
    }else r = mid-1;
  }
  return k;
}


int main(){
  vi a = {1,1,1,2,2,3,7,8,9};
  // cout<<bSearch(a, 6);
  // cout<<myfloor(a, 3);
  cout<<left(a, 2);

}
