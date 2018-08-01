#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define vi vector<int>
#define mi map<int, int>

int answer(vi a, mi &myMap, int c){
  int count = 0;
  int i = 0;

  while(i < a.size()){
    int q = c&a[i];
    count++;
    if(myMap.find(a[i]) == myMap.end()){
      myMap[a[i]] = 1;
    }else if(myMap.find(a[i]) != myMap.end()) return 0;

    if(myMap.find(q) == myMap.end()){
      myMap[q] = 1;
    }else if(myMap.find(q) != myMap.end() return count;

    i++;
  }
  return -  1;

}



int main(){
  vi a = {1,2,3};
  mi myMap;
  cout<<answer(a, myMap, 7);

}
