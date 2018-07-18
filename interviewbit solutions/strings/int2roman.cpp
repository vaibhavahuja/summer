#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

string answer(int n){
    int arr[13] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string str[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    while(n>0){
      for(int c = 12; c>=0;c--){
        if(arr[c]<=n){
          n-=arr[c];
          // cout<<arr[c];
          s+=str[c];
          break;
        }
      }
    }
    return s;
}

int main(){
  cout<<answer(3999)<<endl;
}
