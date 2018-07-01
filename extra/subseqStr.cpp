#include <iostream>
using namespace std;

void printArr(auto arr[], int n){
  for(int i = 0; i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void printSub(char input[], int be, char output[],int i, int n){
  if(be==n){
    printArr(output,i);
    return;
  }

  printSub(input,be+1,output,i,n);
  output[i] = input[be];
  printSub(input,be+1,output,i+1,n);
}

int main(){
  char input[3] = {'a','b','c'};
  char output[3];
  printSub(input,0,output,0,3);
}
