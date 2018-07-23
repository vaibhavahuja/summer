#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define vi vector<int>

void show(vi a){
  int i = 0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

string answer(string input){
  vi a;
  int i = 0;
  string x = "";
  while(i <= input.length()){
    if(input[i] == ' ' || i == input.length()){
      a.push_back(stoi(x));
      x = "";
    }else x+=input[i];
    i++;
  }
  // show(a);
  int maxP = -1;
  int P = -1;
  vi z;
  for(int i = 0; i < a.size(); i++){
    for(int j = i+1; j < a.size(); j++){
      if (maxP < (a[j] - a[i])/(j-i)){
        maxP = (a[j] - a[i])/(j-i);
        P = a[j] - a[i];
        // z.clear();
        // for(int k = i; k<=j; k++) z.push_back(a[k]);
        // show(z);
        // cout<<j-i<<" ";
        // cout<<a[i]<<" "<<a[j]<<endl;
        // cout<<

      }else if(maxP == (a[j] - a[i])/(j-i)){
        if(P < a[j] - a[i]){
          P = a[j] - a[i];
        }
      }

    }
  }

  // z.push_back(maxP, P);
  string finalAns = "";
  finalAns += to_string(maxP);
  finalAns += " ";
  finalAns += to_string(P);

  if(finalAns == "-1 -1") return "impossible";
  else return finalAns;


}


int main(){
  // string input = "300 290 280";

  string input = "1 2 3 4 5 6 7";
  cout<<answer(input);

}
