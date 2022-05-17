// 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

/*
    Input: tree = [7,4,3,null,null,6,19], target = 3
    Output: 3
    Explanation: In all examples the original and cloned trees are shown. 
    The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.
*/

#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Utility function for generating tree for the question
 pair<TreeNode*,TreeNode*> takeInputLevelWise() {
    int rootData;
    TreeNode* target = NULL;
    pair<TreeNode*,TreeNode*> ans(NULL,NULL);
    cout<<"Enter root data :"<<endl;
    cin>>rootData;
    if(rootData == -1) {
        return ans;
    }
    TreeNode* root = new TreeNode(rootData);
    queue<TreeNode*> remainingNodes;
    remainingNodes.push(root);
    while(remainingNodes.size()!= 0) {
        TreeNode* front = remainingNodes.front();
        if(front->val == 3) ans.second = front;
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
    ans.first = root;
    return ans;

}


// BFS Method
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    int tVal = target->val;
    
    queue<TreeNode*> q;
    q.push(cloned);
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i = 0;i<size;i++){
            TreeNode* front = q.front();
            q.pop();
            if(front->val == tVal) return front;
            
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
    return NULL;
}

void dfs(TreeNode* original,TreeNode* cloned,TreeNode* target,TreeNode*& ans){
    if(original == NULL) return;
    if(original == target) ans = cloned;

    dfs(original->left,cloned->left,target,ans);
    dfs(original->right,cloned->right,target,ans);
}

// DFS Method
TreeNode* getTargetCopyII(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    TreeNode* ans = NULL;

    dfs(original,cloned,target,ans);

    return ans;     
}


int main(){

    // Driver Code
    pair<TreeNode*,TreeNode*> original = takeInputLevelWise();

    pair<TreeNode*,TreeNode*> cloned = takeInputLevelWise();


    // TreeNode* node = getTargetCopy(original.first,cloned.first,original.second);

    TreeNode* node = getTargetCopyII(original.first,cloned.first,original.second);


    cout<<node->val;

    return 0;
}