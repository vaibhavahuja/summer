#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

int answer(vi a, vi b, vi c){
  int i = 0, j = 0, k = 0;
  int diff = 1e3;
  while(i<a.size() && j<b.size() && k<c.size()){
    int max1 = max(max(a[i], b[j]), c[k]);
    int min1 = min(min(a[i], b[j]), c[k]);

    if(min1 == a[i]) i++;
    else if(min1 == b[j]) j++;
    else k++;

    diff = min(abs(max1-min1), diff);
  }
  return diff;
}

int main(){
  vi a = {1,4,5,8,10};
  vi b = {6,9,15};
  vi c = {2,3,2,6};

  cout<<answer(a,b,c)<<endl;

}
