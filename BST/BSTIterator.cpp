#include<bits/stdc++.h>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
	  TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class BSTIterator {
public:
    TreeNode* root = NULL;
    vector<TreeNode*> v;
    int curr = 0;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        this->root = root;
        inorder(root);
    }
    
    int next() {
        int temp = v[curr]->val;
        curr++;
        return temp;
    }
    
    bool hasNext() {
        return curr <= v.size()-1;
    }
};


TreeNode* takeInputLevelWise() {
	int rootData;
	cout<<"Enter root data :"<<endl;
	cin>>rootData;
	if(rootData == -1) {
		return NULL;
	}
	TreeNode* root = new TreeNode(rootData);
	queue<TreeNode*> remainingNodes;
	remainingNodes.push(root);
	while(remainingNodes.size()!= 0) {
		TreeNode* front = remainingNodes.front();
		remainingNodes.pop();
		cout<<"Enter left child of "<<front->val<<endl;
		int leftChildData;
		cin>>leftChildData;
		if(leftChildData!= -1){
		TreeNode* child = new TreeNode(leftChildData);
		front->left = child;
		remainingNodes.push(child);
		}
		cout<<"Enter right child of "<<front->val<<endl;
		int rightChildData;
		cin>>rightChildData;
		if(rightChildData!= -1){
		TreeNode* child = new TreeNode(rightChildData);
		front->right = child;
		remainingNodes.push(child);
		}

	}
	return root;

}

int main(){

	TreeNode* root = takeInputLevelWise();

	BSTIterator* obj = new BSTIterator(root);
 	int param_1 = obj->next();
 	bool param_2 = obj->hasNext();

 	cout<<param_1<<endl;
 	cout<<param_2<<endl;

 	return 0;
}