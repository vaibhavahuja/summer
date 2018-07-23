#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

int answer(vi &a, vi &b){
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int j = 0;
  int ans = -1;

  while(j < a.size()){
    ans = max(ans, abs(a[j] - b[j]));
    j++;
  }
  return ans;
}

int main(){
  vi a = {-10, -79, -79, 67, 93, -85, -28, -94};
  vi b = {-2, 9, 69, 25, -31, 23, 50, 78};

  cout<<answer(a,b);

}
