#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define vi vector<int>
#define mi map<int, int>

void show(vi a){
  int i =0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

int answer(const vi &a){
  mi tab;
  int size = a.size()/2;
  for(int i = 0; i < a.size(); i++){
    tab[a[i]] += 1;
  }

  mi::iterator it;
  for(it = tab.begin(); it != tab.end(); it++){
    if(it->second > size){
      return it->first;
    }
  }


}

int main(){
  vi a = {2,1,2,3,3,3,3};
  cout<<answer(a)<<endl;

}
