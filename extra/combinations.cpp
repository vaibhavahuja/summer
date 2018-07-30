#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

// void show(vi a);
//
// void show2(vvi c){
//   int i = 0;
//   while(i < c.size()){
//     show(c[i]);
//     i++;
//   }
//   cout<<endl;
// }

void show(vi a){
  int i = 0;
  while( i < a.size() ){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

void answer(vi inp, int be, vi out, int k, int n, vvi &c){
  if(be != k && be == n+1 ) return;
  if(out.size() == k){
    // c.push_back(out);
    show(out);
    return;
  }

  answer(inp, be+1, out, k, n, c);
  out.push_back(inp[be]);
  answer(inp, be + 1, out, k, n, c);
}





int main(){
  vi inp = {1,2,3,4};
  vvi c;
  vi out;
  answer(inp, 0, out, 2, 4, c );
}
