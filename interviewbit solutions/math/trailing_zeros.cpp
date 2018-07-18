#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int answer(int a){
  int m = 0;
  int k = 1;
  int l = 0;
  int q = a;
  while(a>0){
    a = q/pow(5,k);
    m+=a;
    k++;
  }

  return m;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    cout<<answer(n)<<endl;
  }

}
