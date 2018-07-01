#include <iostream>
using namespace std;

class TreeNode{
public:
	int data;
	TreeNode *left, *right;

	TreeNode(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

TreeNode *insertElem(TreeNode *root, int x){
	if(!root){
		TreeNode *temp = new TreeNode(x);
		return temp;
	}

	if(root->data < x){
		root->right = insertElem(root->right, x);
	}

	if(root->data > x){
		root->left = insertElem(root->left, x);
	}

	return root;
}

TreeNode *createBST(){
	int x;
	cin>>x;
	TreeNode *root = new TreeNode(x);
	while(1){
		cin>>x;
		if(x==-1) break;
		insertElem(root,x);
	}
	return root;
}

void inOrder(TreeNode *root){
	if(!root) return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

TreeNode *getMax(TreeNode *root){
	if(!root->right) return root;
	return(root->right);
}

TreeNode *deleteNode(TreeNode *root, int k){
	if(!root) return NULL;
	if(k<root->data){
		root->left = deleteNode(root->left, k);
	}
	else if(k>root->data){
		root->right = deleteNode(root->right, k);
	}else{
		if(!root->left && !root->right){
			TreeNode *temp = root;
			root=NULL;
			delete temp;
		}else if(!root->left){
			TreeNode *temp = root;
			root = root->right;
			delete temp;
		}else if(!root->right){
			TreeNode *temp = root;
			root=root->left;
			delete temp;
		}else{
			//has both right and left children
			TreeNode *temp = getMax(root->left);
			root->data = temp->data;
			root->left = deleteNode(root->left, temp->data);
		}
	}
	return root;
}



int main(){
	TreeNode *x = createBST();
	inOrder(x);
	inOrder(deleteNode(x,5));
}
