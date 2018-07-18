#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

vi ans(int a){
  vi c;
  int i = 0;
  c.push_back(1);
  while(i < a){
    int x = c[i]*(a-i);
    x/=i+1;
    c.push_back(x);

    i++;
  }

  return c;
}

int main(){
  ans(13);

}
