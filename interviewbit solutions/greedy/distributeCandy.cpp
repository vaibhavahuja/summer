#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>


void show(vi a){
  int i =0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

int answerr(vi a){
  int i =0;
  int sum = 0;
  while(i < a.size()){
    sum += a[i];
    i++;
  }
  return sum;
}

int answer(vi a){
  vi c(a.size(),1);

  int j = 0;
  while(j < c.size() - 1){
    if(a[j+1] > a[j]){
      c[j+1] = c[j] + 1;
    }
    j++;
  }
  j = c.size()-1;
  while(j > 0){
    if(a[j-1] > a[j]){
      c[j-1] = max(c[j-1], c[j] + 1);
    }
    j--;
  }

  return answerr(c);
}

int main(){
  vi a = {1,2,2};
  cout<<answer(a)<<endl;

}
