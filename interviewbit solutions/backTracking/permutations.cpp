#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

void show(vi a){
	int i = 0;
	while(i<a.size()){
		cout<<a[i]<<" ";
		i++;
	}
	cout<<endl;
}

void show2(vvi a){
	int i =0 ;
	while(i<a.size()){
		show(a[i]);
		i++;
	}
	cout<<endl;
}

void mySwap(vi &a, int i, int j){
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}


void permute(vi a, int be, vvi &z){

  if(be == a.size()){
    z.push_back(a);
    // show(a);
    return;
  }

  for(int i = be; i < a.size(); i++){
    mySwap(a, be, i);
    permute(a, be+1, z);
    mySwap(a, be, i);
  }
}




int main(){
  vi a = {1,2, 3};
  vi out;
  permute(a, 0);
  // permute(a, 0, 0);

}
