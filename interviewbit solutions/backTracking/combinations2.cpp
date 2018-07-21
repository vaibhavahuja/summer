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

void generate(int in[], int be, int out[], int i, int k, int l, vvi &a2){
	if(be == k){
		if(i==l){
			vi a1;
			for(int j = 0; j < i; j++){
				a1.push_back(out[j]);
				// cout<<out[j]<<" ";
			}
			a2.push_back(a1);
			// sort(a2.begin(), a2.end());
			// cout<<endl;
		}
		return;
	}

	generate(in, be+1, out, i, k, l, a2);
	out[i] = in[be];
	generate(in, be+1, out, i+1, k, l, a2);

}


vvi solution(int a, int b){
	int arr[a];
	for(int i =0; i < a; i++){
		arr[i] = i+1;
	}
	int out[a];
	vvi c;
	generate(arr, 0, out, 0, a, b, c);

	sort(c.begin(), c.end());
	return c;

}


int main() {
	int inp[4] = {1,2,3,4};
	int out[4] = {0};
	vvi b;
	// generate(inp, 0, out, 0, 4, 3, b);
	show2(solution(4,2));
}
