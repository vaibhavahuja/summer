//generate a knights tour for n*n chess board

#include <iostream>
using namespace std;
const int D = 10;
//top, right bottom left
int rowDir[8] = {+2,+2,+1,-1,-2,-2,+1,-1};
int colDir[8] = {+1,-1,+2,+2,+1,-1,-2,-2};

void initBoard(int board[][D], int n){
  for(int i=0;i<n;i++){
    for(int j = 0; j < n; j++){
      board[i][j] = -1;
    }
  }
}


void printBoard(int board[][D], int n){
  for(int i=0;i<n;i++){
    for(int j = 0; j < n; j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
}
bool canPlace(int board[][D], int row, int col, int n){
  return (row < n && col < n && row >= 0 && col >= 0 && board[row][col] == -1);
}

bool knightsTour(int board[][D], int row, int col, int n, int turns){
  if(turns>=n*n-1) return true;

  for(int i = 0; i < 8; i ++){
    if(canPlace(board,row+rowDir[i], col+colDir[i], n)){
      board[row+rowDir[i]][col+colDir[i]] = turns;
      if(knightsTour(board,row+rowDir[i], col+colDir[i], n,turns+1)){
        return true;
      }
      board[row+rowDir[i]][col+colDir[i]] = -1;
    }
  }
  return false;

}

int main(){
  int n;
  cin>>n;
  int board[D][D];
  initBoard(board,n);
  if(knightsTour(board,0,0,n,)){
    printBoard(board,n);
  }
}
