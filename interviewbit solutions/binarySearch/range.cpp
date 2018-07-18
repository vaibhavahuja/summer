#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

int answer = -1;
int first(vi a, int low, int high, int x){
  int mid = low - (low-high)/2;
  if(low<=high){
    if(a[mid] == x){
      answer = mid;
      first(a,low,mid-1, x);
    }
    else if(a[mid] < x){
      return first(a,mid+1,high,x);
    }
    else return first(a,low,mid-1,x);
  }
  return answer;
}


int last(vi a, int low, int high, int x){
  int mid = low - (low-high)/2;
  if(low<=high){
    if(a[mid] == x){
      answer = mid;
      last(a,mid+1,high, x);
    }
    else if(a[mid] < x){
      return last(a,mid+1,high,x);
    }
    else return last(a,low,mid-1,x);
  }
  return answer;
}

vi myAns(vi c, int b){
  vi d;
  d.push_back(first(c,0,c.size()-1,b));
  d.push_back(last(c,0,c.size()-1,b));
  return d;
}



int main(){
  int arr[7] = {4,7,7,7,8,10,10};
  vi c;
  for(int i = 0; i < 7; i++){
    c.push_back(arr[i]);
  }
  // cout<<c[3];
  // cout<<first(c,0,c.size()-1,3)<<endl;
  // cout<<last(c,0,c.size()-1,3)<<endl;
  vi d = myAns(c,3);
  int i = 0;
  while(i<d.size()){
    cout<<d[i]<<" ";
    i++;
  }

}
