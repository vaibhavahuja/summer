#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define mi map<int, int>
#define vi vector<int>

void show(vi a){
  int i =0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

vi answer(vi a, int sum){
  mi myMap;
  vi c;
  for(int i = 0; i < a.size(); i++){
    if(myMap.find(sum - a[i]) != myMap.end()){
      // cout<<'h'<<endl;
      c.push_back(myMap[sum-a[i]] + 1);
      c.push_back(i+1);
      break;
      // c = {i + 1, myMap[sum-a[i]] + 1};
    }

    if(myMap.find(a[i]) == myMap.end()){
      // cout<<"he"<<endl;
      myMap[a[i]] = i;
    }
  }
  return c;
}


int main(){
  // vi a = {4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, -4, 4, -8, 2, 2,};
  show(answer(a, 9));
}
