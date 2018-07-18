#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

#define vi vector<Interval>
#define vint vector<int>
#define in Interval

bool canIntersect(in a, in b){
	if(max(a.start, b.start) > min(a.end, b.end)) return false;
	return true;
}

in merge(in a, in b){
	in c;
	c.start = min(a.start, b.start);
	c.end = max(a.end, b.end);
	return c;
}

bool mysort(in a, in b){
	return(a.start<b.start);
}

vi showIntervals(vi a, in n){
	vi ans;
	int done = 0;
	int i = 0;
	in d;
	d.start = min(n.start, n.end);
	d.end = max(n.start, n.end);
	while(i < a.size()){
		if(!canIntersect(a[i], d)){
			ans.push_back(a[i]);
		}else{
			done = 1;
			a[i] = merge(a[i], d);
			d = a[i];
		}
		i++;
	}
	ans.push_back(d);

	sort(ans.begin(), ans.end(), mysort);
	int m = 0;
	while(m<ans.size()){
		cout<<ans[m].start<<"->"<<ans[m].end<<" ";
		m++;
	}
	return ans;
}


int main(){
	vi a;
	a.push_back(in(1,2));
	a.push_back(in(3,5));
	a.push_back(in(6,7));
	a.push_back(in(8,10));
	a.push_back(in(12,16));

	showIntervals(a, in(4,9));
}
 
