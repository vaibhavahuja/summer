#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void equate(string &a1, string &b1){
  int a = a1.length();
  int b = b1.length();

  int c;
  string d = "";
  if(a==b){
    return;
  }else if(a>b){
    c = a-b;
    while(c--) d+="0";
    b1 = d+b1;
  }else if(b>a){
    c = b-a;
    while(c--) d+="0";
    a1 = d+a1;
  }
}

string answer(string &a, string &b){
  // cout<<a<<" "<<b<<endl;
  equate(a,b);
  int n = a.length();

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int carry, first, second;
  string ans = "";
  for(int i = 0; i < n; i++){
    first = a[i]-'0';
    second = b[i] - '0';
    if(first==0 && second==0){
      if(carry == 1){
        ans+="1";
        carry = 0;
      }else{
        ans+="0";
        carry = 0;
      }
    }else if(first == 1 && second == 0){
      if(carry==1){
        ans+="0";
        carry = 1;
      }else ans+="1";
    }else if(first == 0 && second == 1){
      if(carry==1){
        ans+="0";
        carry = 1;
      }else ans+="1";
    }else if(first == 1 && second == 1){
      if(carry==1){
        ans+="1";
        carry = 1;
      }else{
        // cout<<i<<endl;
        ans+="0";
        carry = 1;
      }
    }
    // cout<<a<<" "<<b<<" "<<ans<<" "<<carry<<endl;
  }
  // cout<<carry<<endl;
  if(carry == 1){
    ans+="1";
  }
  reverse(ans.begin(), ans.end());
  return ans;
}


int main(){
  string a="1010110111001101101000", b = "1000011011000000111100110";
  cout<<answer(a,b);

  // cout<<a<<" "<<b<<endl;



}
