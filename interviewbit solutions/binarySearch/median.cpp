//to complete
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

double answer(vi a, vi b){
  int m = a.size();
  int n = b.size();

  int be = 0;
  int end = m-1;
  int i,j;
  while(1){
    i = (be+end)/2;
    j = (n+m+1)/2 - i;
    if(a[i-1]>b[j] && j<n && i>=1) end = i-1;
    else if(b[j-1]>a[i] && j>=1 && i<m) be = i+1;
    else{
      if((m+n)%2!=0)  return (double)max(a[i-1], b[j-1]);
      else return (double)(max(a[i-1],b[j-1])+min(a[i],b[j]))/2;
    }
  }
}

int main(){
  vi a;
  a.push_back(1);
  a.push_back(4);



  vi b;
  b.push_back(2);
  b.push_back(3);

  double c = answer(a,b);
  cout<<c<<endl;

}
