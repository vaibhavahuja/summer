#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define V vector<int>
#define S stack<int>

V leftSpecial(V A){
  V ans;
  S s;
  s.push(-1);
  int i = 0;
  while(i<A.size()){

    if(A[i]<A[s.top()] && s.top() != -1){
      ans.push_back(s.top()==-1?0:s.top());
      s.push(i);
    }else{
      while(s.top()!=-1 && A[i] >= A[s.top()]){
        s.pop();
      }
      ans.push_back(s.top()==-1?0:s.top());
      s.push(i);
    }
    i++;
  }
  // int c = 0;
  // while(c<ans.size()){
  //   cout<<ans[c]<<" ";
  //   c++;
  // }
  return ans;
}

V rightSpecial(V A){ //reversed answer
  V ans;
  S s;
  s.push(-1);
  int i = A.size()-1;
  while(i>-1){
    if(A[i]<A[s.top()] && s.top() != -1){
      ans.push_back(s.top()==-1?0:s.top());
      s.push(i);
    }else{
      while(s.top()!=-1 && A[i] >= A[s.top()]){
        s.pop();
      }
      ans.push_back(s.top()==-1?0:s.top());
      s.push(i);
    }
    i--;
  }

  return ans;
}



int main(){
  V A;
  int c[11] = {6, 5, 4, 9, 9, 6, 5, 4, 5, 9, 9 };

  for(int i = 0; i < 11; i++){
    A.push_back(c[i]);
  }
  V a = leftSpecial(A);
  V b = rightSpecial(A);
  int i = 0;
  long long maxP = 0;
  while(i < A.size()){
    maxP = max(maxP, a[i]*b[A.size()-1-i]);
    i++;
  }
  cout<<maxP<<endl;

}
