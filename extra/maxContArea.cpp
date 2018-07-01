#include <iostream>
#include <stack>
using namespace std;

void showStack(stack<int>s){
  stack<int>p = s;
  while(!p.empty()){
    cout<<p.top()<<"-";
    p.pop();
  }
  cout<<endl;
}

void answer(int arr[], int n){
	stack<int> s;
	stack<int> c;
	int m = 0;

	s.push(-10000);
	c.push(0);

	for(int i = 0; i < n; i++){
    // showStack(s);
		if(arr[i] >= s.top()){
			s.push(arr[i]);
			m++;
			c.push(m);
		}
		else{
			while(arr[i]<s.top()){
				int x = s.top();
				s.pop();
				c.pop();
				int y = c.top();
				cout<<x<<" "<<y<<" "<<x*(m-y)<<endl;
			}
			s.push(arr[i]);
			m++;
			c.push(m);
		}
	}
  m-=1;
  while(s.top()!=-10000){
    int x = s.top();
    s.pop();
    c.pop();
    int y = c.top();
    cout<<x<<" "<<y<<" "<<x*(m-y)<<endl;
  }
}


int main() {
	int arr[7] = {6, 2, 5, 4, 5, 1, 6};
	answer(arr,7);
}
