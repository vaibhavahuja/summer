#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define qi queue<int>

int xdir[8] = {+2,+2,+1,-1,-2,-2,+1,-1};
int ydir[8] = {+1,-1,+2,+2,+1,-1,-2,-2};

void showmat(int arr[][8]){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
}

void bfs(int arr[][8], int r, int c, int minDist[][8]){
  bool visited[8][8];

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      visited[i][j] = false;
    }
  }
  qi row;
  qi col;

  row.push(r);
  col.push(c);

  minDist[r][c] = 0;
  visited[r][c] = true;

  while(!row.empty()){
    int pr = row.front();
    int pc = col.front();
    row.pop();
    col.pop();
    for(int i=0; i<8; i++){
      if(pr+xdir[i] >= 0 && pr+xdir[i] < 8 && pc+ydir[i] >= 0 && pc+ydir[i]<8 && !visited[pr+xdir[i]][pc+ydir[i]]){
        row.push(pr+xdir[i]);
        col.push(pc+ydir[i]);
        visited[pr+xdir[i]][pc+ydir[i]] = true;
        minDist[pr+xdir[i]][pc+ydir[i]] = min(minDist[pr+xdir[i]][pc+ydir[i]], minDist[pr][pc]+1);
      }
    }
  }

  // showmat(minDist);
}

int main(){

  int t;
  cin>>t;
  while(t--){

    int arr[8][8];
    int minDist[8][8];
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        arr[i][j] = 0;
        minDist[i][j] = 1e5;
      }
    }

    string a, b;
    cin>>a>>b;
    int ui, uj, vi, vj;
    ui = a[0] - 'a';
    uj = a[1] - '0' - 1;
    vi = b[0] - 'a';
    vj = b[1] - '0' - 1;
    // cout<<ui<<" "<<uj<<" "<<vi<<" "<<vj<<endl;


    bfs(arr, ui, uj, minDist);
    cout<<minDist[vi][vj]<<endl;

  }



}
