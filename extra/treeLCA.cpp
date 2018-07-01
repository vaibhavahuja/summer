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

TreeNode *LCArecur(TreeNode *root, int n1, int n2){
	if(root == NULL) return NULL;

	if(root->data == n1 || root->data == n2) return root;

	TreeNode *left = LCArecur(root->left, n1, n2);
	TreeNode *right = LCArecur(root->right, n1, n2);

	if(left&&right) return root;

	else{
		if(!left) return right;
		else return left;
	}
}

int main(){
	TreeNode* x = createTree();
	TreeNode *temp = LCArecur(x,4,6);
	cout<<temp->data;

}
