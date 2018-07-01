#include <iostream>
#include <queue>
#include <map>
using namespace std;

#define NEW1 pair<int, TreeNode*>


class TreeNode{
	public:
	int data;
	TreeNode *left, *right;

	TreeNode(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

TreeNode *createTree(){
	int x;
	cin>>x;
	if(x==-1) return NULL;
	TreeNode *root = new TreeNode(x);

	root->left = createTree();
	root->right = createTree();

	return root;
}

void printLevel(TreeNode *root){
	queue<TreeNode*>q;
	q.push(root);
	while(1){
		if(q.empty()) break;
		TreeNode *temp = q.front();
		cout<<temp->data<<" ";
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
		q.pop();
	}
}

void topView(TreeNode *root){
	#define NEW pair<TreeNode*, int>
	map<int, TreeNode*> tab;
	queue<NEW>q;
	NEW temp;
	temp.first = root;
	temp.second = 0;
	q.push(temp);

	while(!q.empty()){
		//cout<<q.front().first->data<<" "<<q.front().second<<endl;
		tab.insert(pair<int, TreeNode*>(q.front().second, q.front().first));
		NEW temp2;
		if(q.front().first->left){
			temp2.first = q.front().first->left;
			temp2.second = q.front().second-1;
			q.push(temp2);
		}
		NEW temp3;
		if(q.front().first->right){
			temp3.first = q.front().first->right;
			temp3.second = q.front().second+1;
			q.push(temp3);
		}
		q.pop();
	}
	//a map wont insert if the element already has a value; good thing;
	map<int, TreeNode*>::iterator it;
	for(it = tab.begin(); it!=tab.end();it++){
		cout<<it->second->data<<" ";

	}
}


void bottomView(TreeNode *root){

	queue<NEW1>q;
	map<int, TreeNode*>tab;
	NEW1 x;
	x.first = 0;
	x.second = root;
	q.push(x);

	while(!q.empty()){
		map<int, TreeNode*>::iterator itr;

		tab[q.front().first] = q.front().second;

		TreeNode *temp = q.front().second;
		if(temp->left){
			NEW1 y;
			y.first = q.front().first-1;
			y.second = temp->left;
			q.push(y);
		}
		if(temp->right){
			NEW1 y1;
			y1.first = q.front().first+1;
			y1.second = q.front().second = temp->right;
			q.push(y1);
		}

		q.pop();
	}
	map<int, TreeNode*>::iterator it;
	for(it=tab.begin(); it!=tab.end();it++){
		cout<<it->second->data<<" ";
	}
}

void leftView(TreeNode *root){
	map<int, TreeNode*> tab;
	queue<NEW1>q;
	q.push(NEW1(0,root));
	while(!q.empty()){
		NEW1 x = q.front();
		tab.insert(NEW1(x.first, x.second));
		//cout<<x.first<<" "<<x.second->data<<endl;
		if(x.second->left) q.push(NEW1(x.first+1, x.second->left));
		if(x.second->right) q.push(NEW1(x.first+1, x.second->right));

		q.pop();
	}
	map<int, TreeNode*>::iterator it;
	for(it=tab.begin(); it!=tab.end();it++){
		cout<<it->second->data<<" ";
	}
}

void rightView(TreeNode *root){
	map<int, TreeNode*> tab;
	queue<NEW1>q;
	q.push(NEW1(0,root));
	while(!q.empty()){
		NEW1 x = q.front();
		tab.insert(NEW1(x.first, x.second));
		//cout<<x.first<<" "<<x.second->data<<endl;
		if(x.second->right) q.push(NEW1(x.first+1, x.second->right));
		if(x.second->left) q.push(NEW1(x.first+1, x.second->left));


		q.pop();
	}
	map<int, TreeNode*>::iterator it;
	for(it=tab.begin(); it!=tab.end();it++){
		cout<<it->second->data<<" ";
	}
}


int main() {
	TreeNode *x = createTree();

}
