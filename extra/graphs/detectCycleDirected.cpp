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




};

int main(){

  // Graph g(36);
  // g.addEdge(1,2);
  // g.addEdge(1,3);
  // g.addEdge(2,4);
  // g.addEdge(2,1);
  // g.addEdge(2,5);
  // g.addEdge(3,5);
  // g.addEdge(3,1);
  // g.addEdge(5,3);
  // g.addEdge(5,2);
  // g.addEdge(5,6);
  // g.addEdge(4,2);
  // g.addEdge(4,5);
  // g.addEdge(4,6);
  // g.addEdge(6,4);
  // g.addEdge(6,5);

  Graph g(5); // Total 5 vertices in graph
   g.addEdge(1, 0);
   g.addEdge(0, 2);
   g.addEdge(2, 1);
   g.addEdge(0, 3);
   g.addEdge(1, 4);

   // cout << "Following is Depth First Traversal\n";
   vb visited(36, false);
   si s;
   g.iter_dfs(0, s, visited);
  //
  // g.iter_dfs(1, s, visited);
  cout<<endl;
  vb visit(36, false);
  g.dfs(0, visit);

}
