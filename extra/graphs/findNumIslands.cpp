#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rowdir[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
int coldir[8] = {-1,  0,  1, -1, 1, -1, 0, 1};




void dfs(int mat[][1000], int r, int c, bool visited[][1000], int row, int col){
  if(r<0 || c<0 || r>=row || c>=col || mat[r][c] == 0) return;
  visited[r][c] = true;
  for(int i = 0; i < 8; i++){
    if(!visited[r + rowdir[i]][c + coldir[i]]){
      dfs(mat, r+rowdir[i], c+coldir[i], visited, row, col);
    }
  }
}

int islands(int mat[][1000], int row, int col, bool visited[][1000]){
  int count = 0;
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      if(mat[i][j] == 1 && visited[i][j] == false){
        count++;
        dfs(mat, i, j, visited, row, col);
      }
    }
  }
  return count;
  // cout<<count;

}


int main(){
  int mat[5][1000] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 1, 1, 1},
                   {0, 0, 0, 1, 0},
                   {1, 1, 0, 1, 1}};
  bool visited[5][1000];

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      visited[i][j] = false;
    }
  }

  cout<<islands(mat, 5, 5, visited)<<endl;

}
