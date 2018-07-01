#include <iostream>
#include <cstring>
using namespace std;

char table[][5] = {
" ",
"?*$","abc","def",
"ghi","jkl","mno",
"pqrs","tuv","wxyz"
};

void printArr(auto arr[], int n){
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<"";
  }
  cout<<endl;
}

void generate(char input[], int be, char output[], int i, int n){
  if(i == n){
    printArr(output, n);
  }
  int digit = input[be] - '0';
  char string[] = "";
  strcpy(string, table[digit]);
  int j = 0;
  while(string[j]){
    output[i] = string[j];
    generate(input, be+1, output, i+1, n);
    j++;
  }
}

int main(){
  char input[3] = {'2','3','4'};
  char output[3];
  generate(input, 0, output, 0, 3);
}
