#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define qi queue<int>

int dirx[4] = {1,0,-1,0};
int diry[4] = {0,-1,0,1};
void showMat(int out[][10]){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cout<<out[i][j]<<" ";
    }
    cout<<endl;
  }
}

void bfs(char inp[][10], int r, int c, int out[][10]){
  qi p;
  qi q;
  p.push(r);
  q.push(c);
  out[r][c] = 0;
  int parentRow;
  int parentCol;
  bool visited[10][10];
  for(int i =0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      visited[i][j] = false;
    }
  }

  while(!p.empty()){
    parentCol = q.front();
    parentRow = p.front();
    visited[parentRow][parentCol] = true;
    p.pop();
    q.pop();
    for(int i = 0; i < 4; i++){
      if(parentCol + diry[i] >= 0 && parentCol + diry[i] < 10 && parentRow + dirx[i] >= 0 && parentRow + dirx[i] < 10 && inp[parentRow+dirx[i]][parentCol+diry[i]] == 'T' && !visited[parentRow+dirx[i]][parentCol+diry[i]]){
        out[parentRow+dirx[i]][parentCol+diry[i]] = min(out[parentRow+dirx[i]][parentCol+diry[i]], out[parentRow][parentCol] + 1);

        q.push(parentCol+diry[i]);
        p.push(parentRow+dirx[i]);
      }
    }
  }
}


int minFire(char inp[][10]){
  int out[10][10];
  for(int i =0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      out[i][j] = 1e5;
    }
  }

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(inp[i][j] == 'F') bfs(inp, i, j, out);
    }
  }

  int t = 0;

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(inp[i][j] == 'T' && out[i][j] == 1e5) return -1;
      else if(inp[i][j] == 'T') t = max(t, out[i][j]);
    }
  }

  return t;
}

int main(){
  char inp[10][10];
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cin>>inp[i][j];
    }
  }

  cout<<minFire(inp)<<endl;
}
