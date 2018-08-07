#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  unsigned long long int n, m;
  cin>>n>>m;
  unsigned long long int sum = 0;
  for(unsigned long long int i = 0; i < m; i++){
    unsigned long long int a,b,k;
    cin>>a>>b>>k;
    sum += (b-a+1)*k;
  }
  cout<<sum/n<<endl;
}
