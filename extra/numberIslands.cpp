#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ROW 5
#define COL 5

bool safe(int m[][COL], int row, int col, bool visited[][COL]){
  return (row>=0 && row<ROW && col>=0 && col<COL && m[row][col] && !visited[row][col]);
}

void dfs(int m[][COL], int row, int col, bool visited[][COL]){
  int xdir[8] = {0,1,1,1,0,-1,-1,-1};
  int ydir[8] = {1,1,0,-1,-1,-1,0,1};

  visited[row][col] = true;

  for(int i = 0; i < 8; i++){
    if (safe(m, row + xdir[i], col + ydir[i], visited)){
      dfs(m, row + xdir[i], col + ydir[i], visited);
    }
  }
}

int islands(int m[][COL]){

  bool visited[ROW][COL];
  for(int i =0; i < ROW; i++){
    for(int j=0;j<COL;j++){
      visited[i][j] = false;
    }
  }


  int cnt = 0;
  for(int i =0; i < ROW; i++){
    for(int j=0;j<COL;j++){
      if(m[i][j] == 1 && !visited[i][j]){
        cnt++;
        dfs(m, i, j, visited);
      }
    }
  }
  return cnt;

}

int main(){
  int m[][COL] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0,0 , 0, 0, 0},
                   {1, 0, 1, 0, 1}};

   cout<<islands(m)<<endl;

}
