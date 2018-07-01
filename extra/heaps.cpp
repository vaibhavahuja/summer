//write code to implement priority queue later.

#include <iostream>
using namespace std;

void show(int arr[], int n){
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void max_heapify(int arr[], int i, int N){
  int left = 2*i;
  int right = 2*i+1;
  int max;
  if(left<=N && arr[i]<arr[left]){
    max = left;
  }else{
    max = i;
  }

  if(right<=N && arr[max]<arr[right]){
    max = right;
  }

  if(i!=max){
    swap(arr[i], arr[max]);
    max_heapify(arr,max,N);
  }
}

void build_maxheap(int arr[], int N){
  for(int i = N/2; i>=1; i--){
    max_heapify(arr,i,N);
  }
}

//heapSort
void heap_sort(int arr[], int N){
  for(int i = N-1; i>0; i--){
    build_maxheap(arr,i);
    swap(arr[1], arr[i]);
  }
}





int main(){

  int arr[8] = {0,8,1,2,9,4,6,10};
  show(arr,8);
  // build_maxheap(arr,7);
  heap_sort(arr,7);
  show(arr,8);

}
