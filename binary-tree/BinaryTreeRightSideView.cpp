// 199. Binary Tree Right Side View

/*
    Input: root = [1,2,3,null,5,null,4]
    Output: [1,3,4]
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

// Driver Code to create the tree
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


vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i = 1;i<=size;i++){
            TreeNode* front = q.front();
            q.pop();
            if(i == size){
                ans.push_back(front->val);
            }
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
    return ans;
}


int main(){

    TreeNode* root = takeInputLevelWise();

    vector<int> ans = rightSideView(root);

    for(auto x : ans) cout<<x<<" ";

    return 0;
}