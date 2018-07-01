//generate a chess board of n*n with n queens such that no two intersect

#include <iostream>
using namespace std;
const int D = 10;

bool canPlace(int board[][D], int row, int col, int n){
  //same row
  for(int i=0;i<col;i++){
    if(board[row][i] == 1) return false;
  }

  //same col
  for(int i = 0; i < row; i++){
    if(board[i][col] == 1) return false;
  }

  //4 diagonals
  int a = row; int b = col;
  while(a>=0 && b>=0){
    if(board[a][b] == 1) return false;
    a--;
    b--;
  }
  a = row; b = col;
  while(a<n && b>=0){
    if(board[a][b] == 1) return false;
    a++;
    b--;
  }
  a = row; b = col;
  while(a>=0 && b<n){
    if(board[a][b] == 1) return false;
    a--;
    b++;
  }
  a = row; b = col;
  while(a<n && b<n){
    if(board[a][b] == 1) return false;
    a++;
    b++;
  }

  return true;
}


bool nQueen(int board[][D], int n, int cols){
  if(cols>=n) return true;

  for(int i=0;i<n;i++){
    if(canPlace(board, i, cols, n)){
      board[i][cols] = 1;
      if(nQueen(board,n,cols+1)){
        return true;
      }
      board[i][cols] = 0;
    }
  }
  return false;
}

void printMat(int board[][D], int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
}

void initBoard(int board[][D], int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      board[i][j] = 0;
      }
  }
}


int main(){
  int n;
  cin>>n;
  int board[D][D];
  initBoard(board,n);
  if(nQueen(board,n,0)){
    printMat(board,n);
  }

}
