#include <iostream>
using namespace std;

void hanoi(char src, char dest, char help, int n);

int main(){
  hanoi('A','B','C',2);
}


void hanoi(char src, char dest, char help, int n){
  if(n==0) return;
  hanoi(src,help,dest,n-1);
  cout<<"from "<<src<<" to "<<dest<<endl;
  hanoi(help,dest,src,n-1);
}
