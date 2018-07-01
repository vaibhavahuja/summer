#include <iostream>
using namespace std;

void printArr(auto arr[], int n){
  for(int i=0;i<n;i++){
    cout<<arr[i];
  }
  cout<<endl;
}

void generate(int input[], int be, char output[], int i, int n){
  if(be==n){
    printArr(output,i);
    return;
  }

  int dig1 = input[be];
  output[i] = dig1 + 'a' - 1;
  generate(input,be+1,output,i+1,n);

  int dig2 = input[be+1];
  if(!dig2) return;

  int dig3 = dig1*10+ dig2;
  if(dig3<=26){
    output[i] = dig3 + 'a' - 1;
    generate(input,be+2,output,i+1,n);
  }

}



int main(){
  int input[3] = {1,2,3};
  char output[3];
  generate(input,0,output,0,3);
}
