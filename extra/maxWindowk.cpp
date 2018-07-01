#include <iostream>
#include <deque>
using namespace std;

void answer(int arr[], int n, int k){
	int arr2[n];
	deque<int>q;
	q.push_back(0);
	for(int i = 1; i < k; i++){
		if(arr[q.back()] > arr[i] && !q.empty()){
			q.push_back(i);
		}
		else{
			while(!q.empty() && arr[q.back()]<arr[i]){
				q.pop_back();
			}
			q.push_back(i);
		}
	}

	for(int i = k; i <= n; i++){
		cout<<arr[q.front()]<<" ";

		if(q.front() < i-k){
			q.pop_front();
		}
		if(arr[q.back()] > arr[i]){
			q.push_back(i);
		}
		else{
			while(!q.empty() && arr[q.back()]<arr[i]){
				q.pop_back();
			}
			q.push_back(i);
		}
	}
}


int main() {
	int arr[10] =  {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
	answer(arr,10,4);

}
