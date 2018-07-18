//generate a chess board of n*n with n queens such that no two intersect

#include <iostream>
#include <vector>
using namespace std;
const int D = 10;

#define vs vector<string>
#define vvs vector<vs>



void show1(vs c){
  int i = 0;
  while(i < c.size()){
    cout<<c[i]<<" ";
    i++;
  }
  cout<<endl;
}

void show(vvs c){
  int i = 0;
  while(i<c.size()){
    show1(c[i]);
    i++;
  }
}


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



void printMat(auto board[][D], int n, vs &a){
  char board2[D][D];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(board[i][j] == 1) board2[i][j] = 'Q';
      else board2[i][j] = '.';
    }
  }
  string t = "";
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      t += board2[i][j];
    }
    a.push_back(t);
    t = "";
  }
}


bool nQueen(int board[][D], int n, int cols, vvs &c){
  if(cols>=n) return true;

  for(int i=0;i<n;i++){
    if(canPlace(board, i, cols, n)){
      board[i][cols] = 1;
      if(nQueen(board,n,cols+1,c)){
        vs a;
        printMat(board, n, a);
        // show1(a);
        c.push_back(a);
        // cout<<endl;
        // return true;
      }
      board[i][cols] = 0;
    }
  }
  return false;
}

void initBoard(int board[][D], int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      board[i][j] = 0;
    }
  }
}


vvs answer(int n){
  int board[D][D];
  initBoard(board,n);
  vvs c;
  nQueen(board,n,0,c);
  return c;
}

int main(){
  int n;
  cin>>n;
  int board[D][D];
  initBoard(board,n);
  vvs c;
  nQueen(board,n,0,c);
  show(c);
  // if(nQueen(board,n,0)){
  //   printMat(board,n);
  // }

}
