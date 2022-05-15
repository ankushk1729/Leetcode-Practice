// 1302. Deepest Leaves Sum


/*
    Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
    Output: 15
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
 

int deepestLeavesSum(TreeNode* root) {
    if(!root->left && !root->right) return root->val;
    queue<TreeNode*> q;
    
    q.push(root);
    
    int sum = 0;
    
    while(!q.empty()){
        int size = q.size();
        sum = 0;
        for(int i = 0;i<size;i++){
            TreeNode* front = q.front();
            q.pop();
            sum += front->val;
            
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
    return sum;
}

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


int main(){

    TreeNode* root = takeInputLevelWise();

    cout<<deepestLeavesSum(root);

    return 0;
}