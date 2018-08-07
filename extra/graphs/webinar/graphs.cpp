#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;
//adj list implementation for integer nodes

#define vb vector<bool>
#define li list<int>
#define vi vector<int>

class Graph{
  int V;
  li *adjList;
public:
  Graph(int v){
    V = v;
    adjList = new li[V];
  }

  void addEdge(int u, int v, bool bidir = true){
    adjList[u].push_back(v);
    if(bidir) adjList[v].push_back(u);
  }

  void printAdjList(){
    for(int i = 0; i < V; i++){
      cout<<i<<" -> ";
      for(int node:adjList[i]) cout<<node<<", ";
      cout<<endl;
    }
  }

  void bfs(int src){
    queue<int> q;
    vb visited(V, false);
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
      int node = q.front();
      cout<<node<<" ";
      q.pop();
      for(int i:adjList[node]){
        if(!visited[i]){
          q.push(i);
          visited[i] = true;
        }
      }
    }
    cout<<endl;
  }

  void minDistance(int src, int dest){
    queue<int> q;
    vb visited(V, false);
    vi distance(V, 0);
    vi parent(V, -1);

    q.push(src);
    visited[src] = true;

    while(!q.empty()){
      int node = q.front();
      // cout<<node<<" ";
      q.pop();

      for(int i:adjList[node]){
        if(!visited[i]){
          q.push(i);
          visited[i] = true;
          distance[i] = distance[node] + 1;
          parent[i] = node;
        }
      }
    }
    cout<<endl;
    for(int i = 0; i < V; i++){
      // cout<<i<<" "<<distance[i]<<endl;
    }

    int temp = dest;
    while(temp!=-1){
      cout<<temp<<"<--";
      temp = parent[temp];
    }

  }

  void dfsHelp(int src, vb &visited){
    if(!visited[src]){
      cout<<src<<" ";
      visited[src] = true;
      for(int i:adjList[src]) dfsHelp(i, visited);
    }
  }

  void dfs(int src){
    vb visited(V, false);
    dfsHelp(src, visited);
  }


};

int main(){

  int board[50] = {0};
  board[2] = 13;
  board[5] = 2;
  board[9] = 18;
  board[18] = 11;
  board[17] = -13;
  board[20] = -14;
  board[24] = -8;
  board[25] = -10;
  board[32] = -2;
  board[34] = -22;

  Graph g(50);
  for(int i = 0; i < 36; i++){
    for(int dice = 1; dice<=6; dice++){
      int v = i + dice + board[i+dice];
      g.addEdge(i, v, false);
    }
  }

  g.minDistance(0,36);

  // Graph g(6);
  // g.addEdge(0,1);
  // g.addEdge(1,2);
  // g.addEdge(0,4);
  // g.addEdge(2,4);
  // g.addEdge(3,2);
  // g.addEdge(2,3);
  // g.addEdge(3,5);
  // g.addEdge(3,4);
  //
  // g.minDistance(0, 5);

  // g.bfs(0);

  // g.dfs(0);


  // g.printAdjList();


}
