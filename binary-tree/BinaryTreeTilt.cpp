// 563. Binary Tree Tilt

/*
    Input: root = [1,2,3]
    Output: 1
    Explanation: 
    Tilt of node 2 : |0-0| = 0 (no children)
    Tilt of node 3 : |0-0| = 0 (no children)
    Tilt of node 1 : |2-3| = 1 (left subtree is just left child, so sum is 2;
     right subtree is just right child so sum is 3)
    Sum of every tilt : 0 + 0 + 1 = 1
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

int sum(TreeNode* root){
   if(root == NULL) return 0;

    return root->val + sum(root->left) + sum(root->right);
}

void solve(TreeNode* root, int& ans){
    if(root == NULL){
        return;
    }
    int lVal = sum(root->left);
    int rVal = sum(root->right);

    ans += abs(lVal - rVal);

    solve(root->left, ans);
    solve(root->right, ans);
}

int findTilt(TreeNode* root) {
    if(root == NULL) return 0;
    int sum = 0;
    solve(root, sum);
    return sum;
    
}


int main(){

    TreeNode* root = takeInputLevelWise();
    cout<<findTilt(root);

    return 0;
}