#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer(unsigned int a){
  int p = 0;
  while(a>0){
    if(a%2!=0) p++;
    a/=2;
  }
  return p;
}


int answer2(unsigned int a){
  int count = 0;
  while(a){
    a = a&(a-1);
    count++;
  }
  return count;
}


int main(){
  cout<<answer(719723)<<endl;
  cout<<answer2(719723)<<endl;


}
