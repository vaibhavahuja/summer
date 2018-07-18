//very basic; use common sense from next time please

#include <iostream>
#include <vector>
using namespace std;

int minSteps(int x1, int y1, int x2, int y2){
  int a = abs(x2-x1);
  int b = abs(y2-y1);
  return max(a,b);
}


int answer(vector<int> &A, vector<int> &B){
  int c = 0;
  for(int i = 0; i < A.size()-1; i++){
    c+=minSteps(A[i], B[i], A[i+1], B[i+1]);
  }
  return c;
}



int main(){
  vector <int> g1, g2;
  g1.push_back(0);
  g1.push_back(1);
  g1.push_back(1);
  g2.push_back(0);
  g2.push_back(1);
  g2.push_back(2);

  cout<<answer(g1,g2);
}
