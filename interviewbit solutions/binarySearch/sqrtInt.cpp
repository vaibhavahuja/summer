#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int answer(int a, int l, int r){
  long long int m = l + (r-l)/2;
  if(l<=r){
    if(m*m <= a && (m+1)*(m+1) > a) return m;
    if(m*m>a) return answer(a,l,m-1);
    else return answer(a,m+1,r);
  }
}


int main(){
  int n = 930675566;

  cout<<(int)answer(n,0,n/2);
}
