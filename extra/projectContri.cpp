#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define msi map<string, int>

void show(msi a){
  msi::iterator it;
  for(it = a.begin(); it != a.end(); it++){
    cout<<it->first<<" "<<it->second<<endl;
  }
  cout<<endl;
  cout<<endl;


}

int answer(string input){

  msi tab;
  msi index;
  string x = "";
  int i = 0;
  int q = 0;
  while(i <= input.length()){
    if(input[i] == ' ' || i == input.length()){
      if(tab.size() == 6) {
        // show(tab);
        q++;
        tab.clear();
        // show(index);
      }
      // cout<<x<<endl;
      if(tab[x] == 1){
        // show(tab);
        tab.clear();
        i = index[x];
      }else{
        tab[x] = 1;
        index[x] = i;
      }
      x = "";
    }else{
      x+=input[i];
    }
    i++;
  }
  if(tab.size() == 6) q++;
  // cout<<q<<endl;
  return q;

}

int main(){
  // string input = "M DEP TEST CODE DES RA TEST RA DES DES M DEP CODE DEP M DES TEST RA CODE DES RA DES CODE TEST DEP M";
  string input = "M DEP TEST CODE DES RA TEST RA DES DES M DEP CODE DEP M DES TEST RA CODE DES";
  // answer(input);
  cout<<answer(input)<<endl;
}
