#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void print(int c){
  if(c<0) return;
  cout<<c;
  c--;
  print(c);
  c++;
  cout<<c;
}


int main(){
  int i = 5;
  print(i);
  // cout<<(i++) * (++i);
}
