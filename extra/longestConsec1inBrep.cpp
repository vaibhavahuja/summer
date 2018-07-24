#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer(int x){
  int count = 0;
  while(x != 0){
    x = x & (x<<1);
    count++;
  }
  return count;
}


int main(){
  cout<<answer(239);

}
