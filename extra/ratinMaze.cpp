#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void showMat(int arr[][10], int n){
  cout<<endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
}

bool isSafe(int arr[][10], int x, int y, int n){
  return(x>=0 && x<n && y>=0 && y<n && arr[x][y] == 1);
}


bool ratMaze(int arr[][10], int r, int c, int n, int out[][10]){
  if(r == n-1 && c == n-1){
    out[n-1][n-1] = 1;
    return true;
  }

  if(isSafe(arr,r,c,n)){
    out[r][c] = 1;
    if(ratMaze(arr,r+1,c,n,out)){
      cout<<"D ";
      return true;
    }
    if(ratMaze(arr,r,c+1,n,out)) {
      cout<<"R ";
      return true;
    }

    out[r][c] = 0;
    return false;
  }
  return false;
}

int main(){
  int arr[4][10] = {{1,0,0,0}, {1,1,0,1}, {0,1,0,0}, {1,1,1,1}};
  int out[4][10];
  int n = 4;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      out[i][j] = 0;
    }
  }

  if(ratMaze(arr, 0,0,4,out)) showMat(out, 4 );
  else cout<<"not possible"<<endl;


}
