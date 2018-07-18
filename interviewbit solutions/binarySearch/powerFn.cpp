#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<long long>

void show(vi a){
  int i = 0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

vi convert_to_binary(int n){
  vi ans;
  while(n>0){
    ans.push_back(n%2);
    n/=2;
  }
  // show(ans);
  return ans;
}

int power(int x, int n, int d){
  if(x==0) return (0);
  if(n==0) return(1);
  if(d==1) return 0;
  int i = 1;
  vi mod;
  mod.push_back(x%d);
  i++;
  int j = 1;
  while(i<=n){
    long long q = (mod[j-1]*mod[j-1])%d;
    mod.push_back(q);
    j+=1;
    i*=2;
  }
  vi z = convert_to_binary(n);
  int k = 0;
  long long pq = 1;
  while(k<mod.size()){
    if(z[k] == 1) pq*=mod[k];
    k++;
  }
  return (int)pq%d>0?(int)pq%d:d-abs((int)pq%d);
}
#define ll int
int power1(ll x, ll y, ll p){
  if(x==0) return (0);
  if(y==0) return(1);
  if(p==1) return 0;

  ll res = 1;

  x = x % p;

  while (y > 0)
  {

      if (y & 1)
          res = (res*x) % p;
      y/=2;
      x = (x*x) % p;
  }
  return (int)res>0?(int)res:p+(int)res;
}

int main(){
  cout<<power(71045970,41535484,64735492)<<endl;
  cout<<power1(71045970,41535484,64735492)<<endl;

  // convert_to_binary(200);

}
