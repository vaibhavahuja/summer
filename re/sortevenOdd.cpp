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

void answer(vi a){
  int i = 0;
  while(i < a.size()){
    if(a[i] % 2 != 0){
      a[i]*=-1;
    }
    i++;
  }

  sort(a.begin(), a.end());
  i = 0;
  while(i < a.size()){
    if(a[i] < 0){
      a[i]*=-1;
    }
    i++;
  }

  show(a);

}


int main(){
  vi a = {1,3,2,7,5,4};
  answer(a);


}
