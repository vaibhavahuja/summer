#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool isSafe(int m[][50], int row, int col, bool visited[][50], int ROW, int COL){
  return (row>=0 && row<ROW && col>=0 && col<COL && m[row][col] && !visited[row][col]);
}


void DFS(int m[][50], int row, int col, bool visited[][50], int n, int M){
  int xdir[8] = {0,1,1,1,0,-1,-1,-1};
  int ydir[8] = {1,1,0,-1,-1,-1,0,1};

  visited[row][col] = true;

  for(int i = 0; i < 8; i++){
    if(isSafe(m, row+xdir[i], col+ydir[i], visited, n, M)){
      DFS(m, row+xdir[i], col+ydir[i], visited, n, M);
    }
  }
}

int countIslands(int m[][50], int ROW, int COL){
  bool visited[ROW][50];
  for(int i =0; i < ROW; i++){
    for(int j = 0; j < COL; j++){
      visited[i][j] = false;
    }
  }
  int count = 0;
  for(int i =0; i < ROW; i++){
    for(int j = 0; j < COL; j++){
      if(!visited[i][j] && m[i][j] == 1){
        DFS(m, i, j, visited, ROW, COL);
        count++;
      }
    }
  }

  return count;


}




int main(){
  int t;
  cin>>t;
  int n, m;
  cin>>n>>m;
  int arr[n][50];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>arr[i][j];
    }
  }

  cout<<countIslands(arr, n, m)<<endl;


}
