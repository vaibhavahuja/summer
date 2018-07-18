#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

int answer(vi a){
  int l = 0;
  int r = a.size()-1;
  int maxi = 0;
  while(l<r){
    maxi = max(maxi, (r-l)*min(a[l], a[r]));
    if(a[l]<a[r]) l+=1;
    else r-=1;
  }
  return maxi;
}

int main(){
  vi a = {3,1,2,4,5};
  cout<<answer(a)<<endl;

}
