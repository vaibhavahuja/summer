//wrong answer
//figure out why

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define vi vector<int>

void show(vi a){
  int i = 0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

int calc(vi a, int b, int c){
  int i = b;
  int sum = 0;
  if(b < c){
    while(i < c){
      if(a[i] < 0){
        sum += abs(a[i]);
      }
      i++;
    }
  }else if(b > c){
    while(i > c){
      if(a[i]<0)sum += abs(a[i]);
      i--;
    }
  }
  return sum;
}

int getPosMedian(vi a){
  int i = 0;
  int k = 0;
  while(i < a.size()){
    if(a[i] > 0) k++;
    i++;
  }
  int qw;
  if(k%2 == 0) qw = k/2;
  else qw = k/2 + 1;
  // if(k/2)
  int p = 0;
  while(p < a.size()){
    if(a[p] > 0){
      qw--;
    }
    if(qw == 0) return p;
    p++;
  }


}

int answer(string s){
  vi a;
  int i = 0;
  while(i < s.length()){
    int p = 0;
    if(s[i] == '.'){
      while(s[i] == '.'){
        p+=1;
        i++;
      }
      a.push_back((-1)*p);

    }else if(s[i] == 'x'){
      while(s[i] == 'x'){
        p+=1;
        i++;
      }
      a.push_back(p);
    }
  }
  int ind = getPosMedian(a);

  // i = 0;
  // int mx = 0;
  // int ind = 0;
  // while(i < a.size()){
  //   if(a[i] > mx){
  //     mx = a[i];
  //     ind = i;
  //   }
  //   i++;
  // }
  int j = 0;
  int sum = 0;
  while(j < a.size()){
    if(a[j] > 0){
      sum += calc(a, j, ind);
      // cout<<calc(a,j,ind)<<endl;
    }
    j++;
  }
  show(a);
  cout<<ind<<endl;
  return sum;


}

int main(){
  string s = "xx.....xx.x..xxxx..xxxx.xx..xx..x.xxxx";
  // string s = "....x..xx...x..";
  cout<<answer(s);
}
