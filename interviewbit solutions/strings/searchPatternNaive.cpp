#include <iostream>
using namespace std;

//searching b in a
int answer(string a, string b){
	int m = a.length();
	int n = b.length();
	for(int i = 0; i <= m-n; i++){
		int j;
		for(j = 0; j < n; j++){
			if(a[i+j] != b[j]) break;
		}
		if(j==n){ return i; break;}
	}
	return -1;
}

int main() {
	cout<<answer("asdasd", "babaaa")<<endl;
	return 0;
}
Close
Sphere Research Labs. Ideone is powered by Sphere Engine™
home api widget faq credits desktop mobile
terms of service privacy policy gdpr info

Feedback & Bugs
 Not using Hotjar yet?
Select an element on the page.
