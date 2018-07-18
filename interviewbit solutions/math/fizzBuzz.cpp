
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vs vector<string>

vs answer(int n){
  vs ans;
  for(int i = 1; i <= n; i++){
    if(i%3 == 0 && i%5 == 0) ans.push_back("FizzBuzz");
    else if(i%3 == 0) ans.push_back("Fizz");
    else if(i%5 == 0) ans.push_back("Buzz");
    else ans.push_back(to_string(i));
  }
  return ans;
}

int main(){
  vs c = answer(5);
  int i = 0;
  while(i<c.size()){
    cout<<c[i]<<" ";
    i++;
  }
}
