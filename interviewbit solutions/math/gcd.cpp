#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
  if(a==0) return b;
  else if(b==0) return a;
  if(a==b) return a;
  if(a>b) gcd(a-b, b);
  if(b>a) gcd(a, b-a);
}

int main(){
  cout<<gcd(1,0)<<endl;


}
