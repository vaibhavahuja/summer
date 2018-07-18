#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(string s) {
       int result = 0;
       for (int i = 0; i < s.size(); i++) {
               result = result * 26 + (s[i] - 'A' + 1);
       }
       return result;
}

int main(){
  cout<<solution("AA");

}
