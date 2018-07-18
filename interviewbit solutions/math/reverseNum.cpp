#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int len(int a){
  int c = 0;
  while(a>0){
    a/=10;
    c++;
  }
  return c;
}

int answer(int a){
  int sign = a<0?1:0;
  a = abs(a);
  long long int m = 0;
  int k = 0;
  int len1 = len(a)-1;
  while(len1 >= 0){
   int l = a%10;
   m = m*10 + l;

   len1--;
   a/=10;
   // cout<<m<<endl;
  }
  if(abs(m)>INT_MAX) return 0;


  if(sign==1) return (int)-1*m;
  return (int)m;
}
int main(){
  int n;
  cin>>n;
  while(n--){
    int p;
    cin>>p;
    // cout<<len(p)<<endl;
    cout<<answer(p)<<endl;
  }
}
