#include <iostream>
#include <stack>
using namespace std;

void answer(int arr[], int n){
	int arr2[n];
	stack <int> s;
	stack <int> p;
	s.push(1e5);
	p.push(1);
	for(int i = 0; i < n;i++){
		int c = 0;
		if(arr[i] < s.top()){
			c+=1;
			p.push(c);
			s.push(arr[i]);
			arr2[i] = c;
		}
		else{
			while(arr[i] >= s.top()){
				s.pop();
				c+=p.top();
				p.pop();
			}
			c += 1;
			p.push(c);
			s.push(arr[i]);
			arr2[i] = c;
		}
	}

	for(int i = 0; i < n; i++){
		cout<<arr2[i]<<" ";
	}
	cout<<endl;
}


int main() {
	int arr[7] = {100,80,60,70,60,75,85};
	answer(arr,7);
}
