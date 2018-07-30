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

void answer(vi a, int be, vi out){
  if(be == a.size()){
    show(out);
  }else{
    out.push_back(a[be]);
    answer(a, be+1, out);
    out.pop_back();
    answer(a, be+1, out);
  }
}

int main(){
  vi a = {1,2,3};
  vi out;
  answer(a, 0, out);

}
