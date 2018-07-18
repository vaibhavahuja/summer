#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

void show(vvi a){
  int i = 0;
  int j = 0;
  while(i < a.size()){
    while(j < a[i].size()){
      cout<<a[i][j]<<" ";
      j++;
    }
    cout<<endl;
    i++;
    j = 0;
  }
}

void setRowZero(vvi &a, int row){
  int i = 1;
  while(i < a[0].size()){
    a[row][i] = 0;
    i++;
  }
}


void setColZero(vvi &a, int col){
  int i = 1;
  while(i < a.size()){
    a[i][col] = 0;
    i++;
  }
}

void answer(vvi &a){
  int R = 1, C = 1;
  //checking first row for any 0;
  int i = 0;
  while(i < a[0].size()){
    if(a[0][i] == 0) R = 0;
    // a[0][i] = ;
    i++;
  }
  //checking first column for any 0
  i = 0;
  while(i < a.size()){
    if(a[i][0] == 0) C = 0;
    // a[i][0] = 1;
    i++;
  }
  // show(a); //checked: works
  //now that i have both col and row i will start with checking for every row and column and update the first row and col accordingly
  i = 1;
  int j = 1;
  while(i < a.size()){
    while(j < a[i].size()){
      if(a[i][j] == 0){
        a[i][0] = 0;
        a[0][j] = 0;
      }
      j++;
    }
    i++;
    j = 1;
  }

  // cout<<R<<" "<<C;
  //i have got R and C and the final array;
  // now just need to set everything to setColZero
  i = 1;
  while(i < a[0].size()){
    if(a[0][i] == 0) setColZero(a, i);
    i++;
  }

  i = 1;
  while(i < a.size()){
    if(a[i][0] == 0) setRowZero(a, i);
    i++;
  }




  if(R == 0){
    i = 0;
    while(i < a[0].size()){
      a[0][i] = 0;
      i++;
    }
  }
  if(C == 0){
    i = 0;
    while(i < a.size()){
      a[i][0] = 0;
      i++;
    }
  }


}



int main(){
  vvi x;

	vi a;

	a.push_back(0);
	a.push_back(1);
	a.push_back(1);
  x.push_back(a);

	vi ab;
	ab.push_back(1);
	ab.push_back(1);
	ab.push_back(1);
	x.push_back(ab);


	vi ac;
	ac.push_back(1);
	ac.push_back(1);
	ac.push_back(1);
	x.push_back(ac);

  show(x);

  answer(x);
  cout<<endl;
  show(x);
}
