#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define vc vector<char>
#define vi vector<int>

void show(auto a){
  int i = 0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}


void answer(vi inp, int be, vi out, int &count){
  if(be == inp.size()){
    count += 1;
    return;
    // cout<<count<<endl;
    // return 1;
  }

  out.push_back(inp[be]);
  answer(inp, be+1, out, count);

  if(be + 1 < inp.size()){
    out.pop_back();
    if(inp[be] == 1 || (inp[be] == 2 && inp[be+1] >= 0 && inp[be+1] < 7)){
      out.push_back(inp[be]*10 + inp[be+1]);
      answer(inp, be + 2, out, count);
    }
  }

}

int main(){
  vi inp = {1,2,3, 4, 5, 8, 9};
  vi out;
  int c = 0;
  answer(inp, 0, out, c);
  cout<<c<<endl;
}
