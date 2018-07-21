#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>



void show(vi a){
  int i = 0;
  while(i < a.size()){
    cout<<a[i]<<' ';
    i++;
  }
  cout<<endl;
}
void show2(vvi a){
  int i = 0;
  while(i<a.size()){
    show(a[i]);
    i++;
  }
  cout<<endl;
}

void answer(int arr[], int val, int n, vvi &qa){

}

int main(){
  int arr[4] = {2, 3, 6, 7};
  // cout<<answer(arr, 7, 4);
  vvi d;
  answer(arr,7,4,d);
  show2(d);
}
