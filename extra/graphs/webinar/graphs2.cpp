#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cstring>
using namespace std;

template<typename T>

class Graph{
  map<T, list<T>> adjList;
public:
  Graph(){}

  void addEdge(T u, T v, bool bidir = true){
    adjList[u].push_back(v);
    if(bidir) adjList[v].push_back(u);
  }

  void printAdjList(){
    for(auto row:adjList){
      T key = row.first;
      cout<<key<<"->";

      for(T element:row.second) cout<<element<<", ";
      cout<<endl;
    }
  }
};


int main(){
  Graph<string> g;
  g.addEdge("amritsar", "delhi");
  g.addEdge("amritsar", "jaipur");
  g.addEdge("delhi", "siachen");
  g.addEdge("delhi", "bangalore");
  g.addEdge("delhi", "agra");
  g.addEdge("amritsar", "siachen");

  g.printAdjList();
}
