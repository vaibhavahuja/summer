//Time limit exceeded. can you believe it?

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define msi map<string, int>
#define vs vector<string>

void subSequence(char inp[], int be, char ans[], int i, msi &tab){
  if(inp[be] == '\0'){
    ans[i] = '\0';
    // tab[ans] = 1;
    cout<<ans<<endl;
    return;
  }
    subSequence(inp, be+1,ans,i, tab);
    ans[i] = inp[be];
    subSequence(inp, be+1,ans,i+1, tab);

    // subSequence(inp, be+1,ans,i, tab);
    // ans[i] = inp[be] - 32;
    // subSequence(inp, be+1,ans,i+1, tab);
}

int main(){
  char a[100] = "ab";
  char b[100];
  msi tab;
  subSequence(a,0,b,0,tab);
  // int t;
  // cin>>t;
  // while(t--){
  //   char a[100];
  //   char out[100];
  //   cin>>a;
  //   vs z;
  //   msi tab;
  //   subSequence(a,0,out,0, tab);
  //   msi:: iterator it;
  //   int len = 0;
  //   for(it = tab.begin(); it != tab.end(); it++){
  //     len++;
  //     z.push_back(it->first);
  //     // cout<<it->first<<" "<<it->second<<endl;
  //   }
  //   cout<<len-1<<endl;
  //   int p = 1;
  //   while(p<z.size()){
  //     cout<<z[p]<<" ";
  //     p++;
  //   }
  //   cout<<endl;
  //
  // }

}
