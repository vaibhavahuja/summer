#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

// int ans(vi a){
//   sort(a.begin(), a.end());
//   int count = 0;
//   for(int i = 0; i<a.size(); i++){
//     for(int j = 0; j<a.size(); j++){
//       if(i!=j){
//
//       }
//     }
//   }
//
// }

int main(){
  vi v = {1,2,3,3,3};
  cout<<(lower_bound(v.begin(), v.end(), 2)) - v.begin();





}
