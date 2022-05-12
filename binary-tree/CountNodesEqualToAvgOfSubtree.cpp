// 2265. Count Nodes Equal to Average of Subtree

/*
	Input: root = [4,8,5,0,1,null,6]
	Output: 5
	Explanation: 
	For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
	For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
	For the node with value 0: The average of its subtree is 0 / 1 = 0.
	For the node with value 1: The average of its subtree is 1 / 1 = 1.
	For the node with value 6: The average of its subtree is 6 / 1 = 6.
	
*/

#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// Utility function to create binary tree for the question
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

    pair<int,int> count(TreeNode* root,int& cnt){
        if(root == NULL){
            return make_pair(0,0);
        }
        pair<int,int> p;
        
        pair<int,int> left = count(root->left,cnt);
        pair<int,int> right = count(root->right,cnt);
        
        p.first = root->val + left.first + right.first;
        p.second = 1 + left.second + right.second;
        
        int avg = (p.first) / p.second;
        
        if(avg == root->val) cnt++;
        
        return p;
        
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        count(root,cnt);
        
        return cnt;
    }


int main(){

	TreeNode* root = takeInputLevelWise();

	cout<<averageOfSubtree(root);

	return 0;
}