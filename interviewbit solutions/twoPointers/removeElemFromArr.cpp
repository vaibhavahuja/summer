#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>


void show(vi a){
  int i =0;
  while(i<a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

int answer(vi a, int b){
  int count = 0;
  for(int i = 0; i < a.size(); i++){
    if(a[i] != b){
      a[count] = a[i];
      count++;
    }
  }
  return count;
}

int main(){
  vi a = {4,1,1,2,1,3};
  int elem = 1;
  cout<<answer(a,elem);


}
