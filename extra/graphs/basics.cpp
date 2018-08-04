#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define qi queue<int>

class Graph{
  vvi g;
public:
  Graph(int n){
    g.resize(n);
  }

  void addEdge(int src, int dest, bool isBidirectional=false){
    g[src].push_back(dest);
    if(isBidirectional){
      g[dest].push_back(src);
    }
  }

  //doing a breadth first search
  void bfs(int s){
    qi q;
    vb visited(g.size(), false);
    // cout<<s<<" ";
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
      int cur = q.front();
      cout<<cur<<" ";
      q.pop();
      for(int j = 0; j < g[cur].size(); j++){

        if(visited[g[cur][j]] == false){
          visited[g[cur][j]] = true;
          // cout<<"pushed in queue "<<g[cur][j]<<endl;
          q.push(g[cur][j]);
        }
      }
    }
  }

  // vb visited(g.size(), false);
  void dfs(int s, vb &visited){
    visited[s] = true;
    cout<<s<<" ";
    for(int i = 0; i < g[s].size(); i++){
      if(visited[g[s][i]] == false){
        // visited[g[s][i]]
        dfs(g[s][i], visited);
      }
    }
  }



};

int main(){

  // Graph g(4);
  // g.addEdge(0, 1);
  // g.addEdge(0, 2);
  // g.addEdge(1, 2);
  // g.addEdge(2, 0);
  // g.addEdge(2, 3);
  // g.addEdge(3, 3);

  Graph g(36);
  g.addEdge(1,2);
  g.addEdge(1,3);
  g.addEdge(2,4);
  g.addEdge(2,1);
  g.addEdge(2,5);
  g.addEdge(3,5);
  g.addEdge(3,1);
  g.addEdge(5,3);
  g.addEdge(5,2);
  g.addEdge(5,6);
  g.addEdge(4,2);
  g.addEdge(4,5);
  g.addEdge(4,6);
  g.addEdge(6,4);
  g.addEdge(6,5);

  vb visited(36, false);
  g.dfs(1, visited);





}
