#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//recursive soln
int stairs(int n){
  if(n==0) return 1;
  if(n<0) return 0;

  return stairs(n-1) + stairs(n-2);
}


//dp solution
int stairs2(int n){
  int arr[n+1];
  arr[0] = 1;
  arr[1] = 1;

  for(int i = 2; i <= n; i++){
    arr[i] = arr[i-1] + arr[i-2];
  }
  return arr[n];
}

int main(){
  cout<<stairs2(5)<<endl;

}
