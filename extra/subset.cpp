#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

void show(vi a){
  int i = 0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

void answer(vi inp, int be, vi out, int n){
  if(be == n){
    // z.push_back(out);
    show(out);
    return;
  }

  answer(inp, be+1, out, n);
  out.push_back(inp[be]);
  answer(inp, be+1, out, n);
}

int main(){
  vi inp = {1,2,3,4};
  vi out;
  answer(inp, 0, out, 4);

}
