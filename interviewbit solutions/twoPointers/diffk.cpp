#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#define vi vector<int>

bool search(vi a, int n, int i){
  int l = i+1;
  int r = a.size()-1;
  while(l<r){
    int mid = l+(r-l)/2;
    if(a[mid] == n) return true;
    else if(a[mid]<n){
      l = mid+1;
    }else if(a[mid]>n) r = mid-1;
  }
  return false;
}

int answer(vi a, int k){
  int i = 0;
  while(i<a.size()){
    if(search(a,abs(a[i]-k),i)) return 1;
    i++;
  }
  return 0;
}

int main(){
  vi a = {1,2,2,3,4};
  cout<<answer(a,0);


}
