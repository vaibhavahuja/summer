#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

int answer(vi a){
  int i = 0;
  int maxSoFar = -1e5;
  int maxEndingHere = 0;
  while(i<a.size()){
    maxEndingHere = maxEndingHere + a[i];
    if(maxSoFar<maxEndingHere) maxSoFar = maxEndingHere;
    if(maxEndingHere<0) maxEndingHere = 0;
    i++;
  }
  return maxSoFar;
}


int main(){
  int arr[9] = {-2,1,-3,4,-1,2,1,-5,4};
  vi a;
  for(int i =0; i < 1; i++){
      a.push_back(arr[i]);

  }
  cout<<answer(a)<<endl;

}
