#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define vs vector<string>

void show(vs a){
  int i = 0;
  while( i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}


int answer(string a){
  int answer = 0;
  string p = "";
  vs my;
  for(int i = 0; i < a.size(); i++){
    if(a[i] == '*'){
      my.push_back(p);
      my.push_back("*");
      p = "";

    }else if(a[i] == '+'){
      my.push_back(p);
      my.push_back("+");
      p = "";

    }else if(a[i] == '-'){
      my.push_back(p);
      my.push_back("-");
      p = "";

    }else if(a[i] == '/'){
      my.push_back(p);
      my.push_back("/");
      p = "";

    }else{
      p += a[i];
    }
  }
  my.push_back(p);

  int qw = 1;
  answer = 0;
  answer += stoi(my[0]);
  while(qw < my.size()){
    if(my[qw] == "+"){
      answer += stoi(my[qw+1]);
      qw+=2;

    }else if(my[qw] == "-"){
      answer -= stoi(my[qw+1]);
      qw+=2;
    }else if(my[qw] == "*"){
      answer *= stoi(my[qw+1]);
      qw+=2;
    }else if(my[qw] == "/"){
      answer /= stoi(my[qw+1]);
      qw+=2;
    }

  }
  cout<<answer<<endl;

  // show(my);
}

int main(){
  string s = "20 - 3 * 6 + 208";
  answer(s);

}
