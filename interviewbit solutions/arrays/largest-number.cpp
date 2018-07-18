#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#define vi vector<int>

string toString(int num){
    ostringstream str1;
    str1 << num;
    string geek = str1.str();
    return geek;
}

int len(int a){
	int l = 1;
	while(a/10>0){
		l++;
		a/=10;
	}
	return l;
}

bool mySort(int a, int b){
	string aa = to_string(a);
	string bb = to_string(b);
	string c = aa+bb;
	string d = bb+aa;
	return c>d;
}

int main(){
	int x[10] = {0,0,0,0,0};
	vi a;
	for(int i = 0; i < 5; i++){
		a.push_back(x[i]);
	}

	sort(a.begin(), a.end(), mySort);


	  string s = "";
    int i = 0;
    while(i<a.size()){
        s+=toString(a[i]);
        i++;
    }
    cout<<s;

}
