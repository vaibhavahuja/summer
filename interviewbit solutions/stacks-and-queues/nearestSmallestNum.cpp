#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define si stack<int>
#define vi vector<int>

void showV(vi a){
  int i = 0;
  while(i<a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

vi answer(vi a){
  int i =0;
  si s;
  vi ans;
  s.push(-1);
  while(i<a.size()){
    if(s.top()<a[i]){
      ans.push_back(s.top());
      s.push(a[i]);
    }else if(s.top()>=a[i]){
      while(s.top()>=a[i]){
        s.pop();
      }
      ans.push_back(s.top());
      s.push(a[i]);
    }
    i++;
  }
  showV(ans);
  return ans;
}

int main(){
  vi a = { 39, 27, 11, 4, 24, 32, 32, 1 };
  answer(a);

}
