#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

int ans(vi a, int x, int low, int high){

  if(low<=high){
    int mid = low - (low-high)/2;
    if(a[mid] == x) return mid;
    else if(a[mid]<x) return ans(a, x, mid+1,high);
    else return ans(a,x,low,mid-1);
  }
  return low;

}


int main(){
  int arr[4] = {1,3,5,6};
  vi c;
  for(int i = 0; i < 4; i++){
    c.push_back(arr[i]);
  }
  int x = 7;
  cout<<ans(c,x,0,c.size()-1);


}
