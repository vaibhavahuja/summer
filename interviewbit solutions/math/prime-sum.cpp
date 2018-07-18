#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define vi vector<int>

bool isPrime(int A){
  int c = sqrt(A);
  if(A <= 1) return false;
  for(int i = 2; i <= c; i++){
    if(A%i == 0) return false;
  }
  return true;
}

vi prime(int a){
  vi c;
  for(int i = 2; i <= a; i++){
    if(isPrime(i) && isPrime(a-i)){
      c.push_back(i);
      c.push_back(a-i);
      return c;
    }
  }
}

int main(){
  vi c;
  c = prime(102);
  cout<<c[0]<<' '<<c[1]<<endl;

}
