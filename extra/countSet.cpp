#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer(int a){
  int c = 0;
  while(a){
    c++;
    a = a&(a-1);
  }
  return c;
}

int main(){

}
