#include <iostream>
using namespace std;

#ifndef INF
#define INF 1e5
#endif

void printArr(int arr[], int l, int r);

void merge(int arr[], int l, int m, int r){
  int n1 = m-l+1;
  int n2 = r-m;

  int a[n1+1], b[n2+1];
  a[n1] = INF;
  b[n2] = INF;
  for(int i = 0; i < n1 ; i++){
    a[i] = arr[i+l];
  }
  // printArr(a,0,n1);

  for(int i=0; i < n2; i++){
    b[i] = arr[i+1+m];
  }
  // printArr(b,0,n2);

  int i=0,j=0,k=l;

  while(a[i] != INF || b[j] != INF){
    if(a[i]<=b[j]){
      arr[k] = a[i];
      i++;
    }
    else{
      arr[k] = b[j];
      j++;
    }
    k++;
  }
}

void mergeSort(int arr[], int l, int r){
  if(l<r){
    int m = (l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
  }
}

void printArr(int arr[], int l, int r){
  for(int i=l;i<r;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}



int main(){
  int arr[6] = {3,5,6,4,2,1};
  printArr(arr,0,6);
  mergeSort(arr,0,5);
  printArr(arr,0,6);
}
