#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

string answer(vi a, vi b){
  int sum1 = 0;
  int sum2 = 0;

  for(int i =0; i < a.size(); i++){
    sum1 += a[i];
    sum2 += b[i];
  }


  if(sum1 >= sum2) return "Yes";
  else return "No";

}

int main(){

  int n;
  cin>>n;
  int p = n;
  vi a, b;
  while(n--){
    int q;
    cin>>q;
    a.push_back(q);
  }
  while(p--){
    int qq;
    cin>>qq;
    b.push_back(qq);
  }
  cout<<answer(a, b)<<endl;

}
