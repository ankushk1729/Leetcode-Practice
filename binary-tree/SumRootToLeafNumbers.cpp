// 129. Sum Root to Leaf Numbers


/*
	Input: root = [1,2,3]
	Output: 25
	Explanation:
	The root-to-leaf path 1->2 represents the number 12.
	The root-to-leaf path 1->3 represents the number 13.
	Therefore, sum = 12 + 13 = 25.
*/

#include<bits/stdc++.h>
using namespace std;



 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

    void traverse(TreeNode* root,string& currAns,int& totalSum){
        currAns += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            totalSum += stoi(currAns);
            currAns.pop_back();
            return;
        }
        
        
        if(root->left) traverse(root->left,currAns,totalSum);
        if(root->right) traverse(root->right,currAns,totalSum);
        
        currAns.pop_back();

    }
    int sumNumbers(TreeNode* root) {
        string currAns = "";
        int totalSum = 0;
        traverse(root,currAns,totalSum);
        
        return totalSum;
    }

int main(){

	TreeNode* root = takeInputLevelWise();

	cout<<sumNumbers(root);

	return 0;
}