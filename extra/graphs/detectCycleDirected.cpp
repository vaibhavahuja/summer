#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define si stack<int>
#define vb vector<bool>

class Graph{

public:
  vvi g;
  Graph(int n){
    g.resize(n);
  }

  void addEdge(int src, int dest){
    g[src].push_back(dest);
  }

  void dfs(int src, vb &visited){
    visited[src] = true;
    cout<<src<<" ";
    for(int i = 0; i < g[src].size(); i++){
      if(!visited[g[src][i]]) dfs(g[src][i], visited);
    }
  }

//iterative: one thing to notice: both iterativve and recursive produce different results
//which is true: does not matter tbh as both are correct
  void iter_dfs(int src, si s, vb &visited){
    s.push(src);
    while(!s.empty()){
      int q = s.top();
      s.pop();
      if(!visited[q]) {
        cout<<q<<" ";
        visited[q] = true;
      }
      for(int i = 0; i < g[q].size(); i++) {
        if(!visited[g[q][i]]){
          s.push(g[q][i]);
          // visited[g[q][i]] = true;
        }
      }
    }
  }

//check for cycle in a  graph
  bool isCycle(int src, vb &visited, vb &recStack){
    if(!visited[src]){
      visited[src] = true;
      recStack[src] = true;

      for(int i = 0; i < g[src].size(); i++){
        if(!visited[g[src][i]] && isCycle(g[src][i], visited, recStack)) return true;
        else if(recStack[g[src][i]]) return true;
      }
    }

    recStack[src] = false;
    return false;
  }


  bool isCyclic(){
    vb visited(g.size(), false);
    vb recStack(g.size(), false);

    for(int i = 0; i < g.size(); i++){
      if(isCycle(i, visited, recStack)) return true;
    }
    return false;
  }


};









int main(){

  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(3,2);
  // g.addEdge(2, 3);
  // g.addEdge(3,3);

  // vb visited(4, false);
  // vb recStack(4, false);


  if(g.isCyclic()) cout << "Graph contains cycle";
  else cout << "Graph doesn't contain cycle";

}
