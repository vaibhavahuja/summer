//idk why it shows wrong answer

#include <iostream>
using namespace std;

void showArr(int arr[], int n){
	for(int j = 0; j<n; j++){
		cout<<arr[j]<<" ";
	}
	cout<<endl;
}

int Min(int arr[], int i, int mem[]){
	int c = -1e2;
	if(i==0) return 1;
	if(i==1) return arr[i]>arr[0]?2:1;
	for(int j = i-1; j>=0; j--){
		if(arr[j]<arr[i]){
			if(mem[j]>c) c = mem[j];
		}
	}
	return c+1;
}

int lis(int arr[], int n, int mem[]){
	for(int i = 0; i < n; i++){
		mem[i] = Min(arr,i,mem)<0?0:Min(arr,i,mem);
	}
	return mem[n-1];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int mem[n]  = {0};

		for(int c = 0; c<n;c++){
			cin>>arr[c];
		}
		cout<<lis(arr,n,mem)<<endl;
	}
}
