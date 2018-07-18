#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int answer(string s){

  map<char,int> tab;
  tab['I'] = 1;
  tab['V'] = 5;
  tab['X'] = 10;
  tab['L'] = 50;
  tab['C'] = 100;
  tab['D'] = 500;
  tab['M'] = 1000;
  int g = 0;
  for(int i = 0; i < s.length(); i++){
    int c = tab[s[i]];
    if(i+1<s.length()){
      if(tab[s[i+1]]>tab[s[i]]) g-=2*c;
    }
    g+=c;
  }
  return g;

}



int main(){
  cout<<answer("CMXCIX")<<endl;

}
