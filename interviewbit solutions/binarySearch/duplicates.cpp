#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

int answer = -1;
int firstOcc(vi a, int low, int high, int x){
  if(low<=high){

    int mid = low - (low-high)/2;
    if(a[mid] == x){
      answer = mid;
      firstOcc(a,low,mid-1,x);
    }
    else if(a[mid]<x) return firstOcc(a,mid+1,high,x);
    else return firstOcc(a,low,mid-1,x);
  }
  return answer;
}

int lastOcc(vi a, int low, int high, int x){
  if(low<=high){

    int mid = low - (low-high)/2;
    if(a[mid] == x){
      answer = mid;
      lastOcc(a,mid+1,high,x);
    }
    else if(a[mid]<x) return lastOcc(a,mid+1,high,x);
    else return lastOcc(a,low,mid-1,x);
  }
  return answer;
}

int main(){

  vi a;
  int arr[7] = {4,7,7,7,8,10,10};
  for(int i =0; i < 7; i++){
    a.push_back(arr[i]);
  }
  int n = 3;
  // cout<<lastOcc(a,0,a.size()-1,n)<<endl;
  // cout<<firstOcc(a,0,a.size()-1,n)<<endl;

  if(lastOcc(a,0,a.size()-1,n) == -1 && firstOcc(a,0,a.size()-1,n) == -1) cout<<0<<endl;
  else cout<<lastOcc(a,0,a.size()-1,n) - firstOcc(a,0,a.size()-1,n) + 1<<endl;

}
