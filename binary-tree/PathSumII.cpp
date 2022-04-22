// 113. Path Sum II

/*
	Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
	Output: [[5,4,11,2],[5,8,4,5]]
	Explanation: There are two paths whose sum equals targetSum:
	5 + 4 + 11 + 2 = 22
	5 + 8 + 4 + 5 = 22
*/

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

void getPaths(TreeNode* root,vector<int>& path,vector<vector<int>>& ans,int& pathSum,int target){
        if(root == NULL) return;
        
        path.push_back(root->val);
        pathSum += root->val;
        
        if(root->left == NULL && root->right == NULL){
            if(pathSum == target)
                ans.push_back(path);
        }
        
        getPaths(root->left,path,ans,pathSum,target);
        getPaths(root->right,path,ans,pathSum,target);
        
        path.pop_back();
        pathSum -= root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> ans;
        int pathSum = 0;
        if(root == NULL) return ans;
        getPaths(root,path,ans,pathSum,targetSum);
        return ans;
    }
 

 // Driver Code
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

	vector<vector<int>> ans = pathSum(root,22);

	for(auto x : ans){
		for(auto y : x){
			cout<<y<<" ";
		}
		cout<<endl;
	}

	return 0;
}