#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

void show(vi a){
  int i = 0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

// int answer(vi a){
//   if(a.size() == 0) return 0;
//   int i = 0;
//   int x = 0;
//   while(i < a.size() - 1){
//     if(a[i] == 0){
//       a[i] = 1;
//       int j = i;
//       while(j<a.size()){
//         a[j] = 1-a[j];
//         j++;
//       }
//       x++;
//     }
//     // show(a);
//     i++;
//   }
//   if(a[a.size() - 1] == 0){
//     x++;
//   }
//   return x;
//
// }


//more efficient one
int answer(vi a){
  int state = 0, ans = 0;
  if(a.size() == 0) return 0;
  int i = 0;
  while(i < a.size()){
    if(a[i] == state){
      ans++;
      state = 1-state;
    }
    i++;
  }
  return ans;
}

int main(){
  vi a = {0,1,0,1};
  cout<<answer(a);

}
