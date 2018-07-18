#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPower(unsigned int n){
  if(n<=1) return true;
  for(int x = 2; x<=sqrt(n); x++){
    unsigned p = x;
    while(p<=n){
      p *= x;
      if(p==n) return true;
    }
  }
  return false;
}

int main(){
  cout<<isPower(32)<<endl;

}
