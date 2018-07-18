#include <iostream>
#include <vector>
using namespace std;

#define V vector<int>

V maxSet(V A){
  A.push_back(-1);
  int i = 0;
  long long sum = 0;
  long long maxSum = 0;
  int index = 0;
  int length = 0;
  long long maxLength = 0;
  int minIndex = 1e3;
  while(i<A.size()){
    // cout<<maxSum<<" "<<index<<endl;
    if(A[i]>0){
      sum+=A[i];
      length++;
    }
    else if(A[i]<0){
        if(maxSum<sum){
          maxSum = sum;
          index = i - length;
          maxLength = length;
          // minIndex = min(index,minIndex);
        }else if(maxSum == sum){
          if(length>maxLength){
            maxLength = length;
            index = i - maxLength;
            minIndex = min(index,minIndex);
          }
        }
        length = 0;
        sum = 0;
      }
      i++;

    }
  V answer;
  int c = index;
  while(A[c] >= 0){
    answer.push_back(A[c]);
    // cout<<A[c]<<"  ";
    c++;
  }
  return answer;
}

int main(){
  V c;
  int arr[10]=  {336465782, -278722862, -2145174067, 1101513929, 1315634022, -1369133069, 1059961393, 628175011, -1131176229, -859484421};
  // int arr[10] = {3,-2,-2,11,13,-13,10,6,-11,-85};
  for(int i = 0; i < 10; i++){
    c.push_back(arr[i]);
  }
  // unsigned long long z = 0;
  // z =  1101513929+1315634022;
  // cout<<z<<endl;
  maxSet(c);
}
