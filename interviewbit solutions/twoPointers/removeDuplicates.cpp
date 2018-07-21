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

int removeDuplicates(vi &a){

  if (a.size()==0 || a.size()==1)
      return a.size();

  int i = 0;
  while(i < a.size()){
    if(a[i] == a[i-1]){
      a.erase(a.begin()+i);
    }
    else i++;
  }
  return a.size();
}

int main(){
  vi a = {0,0,0,0,0,0,0,0,1,1,1,1,1,2,2,2,2,2,3,3,3,3};
  cout<<removeDuplicates(a)<<endl;
  show(a);

}
