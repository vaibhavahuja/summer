#include <iostream>
using namespace std;

int skip1(int n, int row){
	if(n-row-2 >= 0) return 2*(n-row-2) + 2;

	return 0;
}

int skip2(int n, int row){
	if(row-1>=0) return 2*(row-1) + 2;
	return 0;
}

string answer(string s, int n){
	string p = "";
	for(int i = 0; i < n; i++){
		int k = i;

		while(k<s.length()){
			if(k==s.length()-1) {p+=s[k]; k++;}
			else{
				if(skip1(n,i)>0) p+=s[k];
				k+=skip1(n,i);
				// cout<<k<<" "<<p<<endl;
				if(skip2(n,i)>0) p+=s[k];
				k+=skip2(n,i);
				// cout<<k<<" "<<p<<endl;
			}
		}
	}
	return p;
}


int main() {
	cout<<answer("kHAlbLzY8Dr4zR0eeLwvoRFg9r23Y3hEujEqdio0ctLh4jZ1izwLh70R7SAkFsXlZ8UlghCL95yezo5hBxQJ1Td6qFb3jpFrMj8pdvP6M6k7IaXkq21XhpmGNwl7tBe86eZasMW2BGhnqF6gPb1YjCTexgCurS", 1)<<endl;

}
