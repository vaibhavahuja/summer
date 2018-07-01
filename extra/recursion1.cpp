#include <iostream>
using namespace std;

int fact(int x){
  if(x<=0) return 1;
  return x*fact(x-1);
}

int fib(int x){
  if(x<=0) return 0;
  if(x==1) return 1;

  return fib(x-1) + fib(x-2);
}

int nSteps(int x){
  if(x<0) return 1e5;
  if(x==0) return 0;
  if(x==1) return 1;
  if(x==2) return 1;
  if(x==3) return 1;

  return 1 + min(nSteps(x-1), min(nSteps(x-2),nSteps(x-3)));
}


int main(){
  cout<<nSteps(10)<<endl;
}
