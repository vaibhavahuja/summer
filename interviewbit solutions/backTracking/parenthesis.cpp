#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vc vector<char>
#define vs vector<string>

void show(auto a){
  int i = 0;
  while(i < a.size()){
    cout<<a[i]<<" ";
    i++;
  }
  cout<<endl;
}

void answer(vc first, vc second, int i, int j, vc out, vs &ans){

  if(i < j){
    return;
  }else if(i == first.size() && j < second.size()){
    while(j < second.size()){
      out.push_back(second[j]);
      j++;
    }
    if(out.size() == first.size() + second.size()){
      string s = "";
      int q = 0;
      while(q<out.size()){
        s+=out[q];
        q++;
      }
      ans.push_back(s);
    }
    return;
  }

  out.push_back(first[i]);
  answer(first, second, i+1, j, out, ans);
  out.pop_back();
  answer(first, second, i+1, j, out, ans);

  out.push_back(second[j]);
  answer(first, second, i, j+1, out, ans);
  out.pop_back();
  answer(first, second, i, j+1, out, ans);
}

vs generate(int a){
  vc first;
  vc second;
  vc out;
  int i = 0;
  while(i < a){
    first.push_back('(');
    second.push_back(')');
    i++;
  }
  vs ans;
  answer(first, second, 0, 0, out, ans);
  return ans;

}


int main(){
  vc first = {'(', '(', '('};
  vc second = {')', ')', ')'};
  vc out;
  vs ans;
  show(generate(3));
  // answer(first, second, 0, 0, out, ans);
  // show(ans);


}
