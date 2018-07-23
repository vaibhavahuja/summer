#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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


int answer(vi a, int n){
  int i = 0;
  int count = 0;
  while(i < a.size()){
    if(isPrime(a[i])){
      if(n%a[i] == 0) count++;
    }
    i++;
  }
  return count;
}

int main(){
  vi a = {1,2,3,4,5};
  cout<<answer(a, 6);

}
