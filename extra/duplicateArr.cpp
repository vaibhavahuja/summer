#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

int sum(vi a){
  int i =0;
  int sum = 0;
  while(i <a.size()){
    sum += a[i];
    i++;
  }
  return sum;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    vi a;
	    int n;
	    cin>>n;
      int qwe = n-1;
	    while(qwe--){
	        int q;
	        cin>>q;
	        a.push_back(q);
	    }
	    cout<<((n+1)*n)/2 - sum(a)<<endl;
	}

}
