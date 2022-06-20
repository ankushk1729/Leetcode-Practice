// 671. Second Minimum Node In a Binary Tree

/*
    Input: root = [2,2,5,null,null,5,7]
    Output: 5
    Explanation: The smallest value is 2, the second smallest value is 5.
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

void dfs(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& pq, unordered_map<int,int>& map){
    if(root == NULL) return;
    
    if(!map.count(root->val)){
        pq.push(root->val);
    }
    
    map[root->val]++;
    
    dfs(root->left, pq, map);
    dfs(root->right, pq, map);
}

int findSecondMinimumValue(TreeNode* root) {
    if(root->left == NULL && root->right == NULL) return -1;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int,int> map;
    dfs(root, pq, map);
    
    int first = pq.top();
    pq.pop();
    int second = pq.top();
    pq.pop();
    if(first == second) return -1;
    return second;
}


int main(){

    TreeNode* root = takeInputLevelWise();

    cout<<findSecondMinimumValue(root);

    return 0;
}