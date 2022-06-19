// 872. Leaf-Similar Trees

/*
    Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
    Output: true
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

void inorder(TreeNode* root, vector<int>& v){
    if(root == NULL) return;
    inorder(root->left, v);
    if(root->left == NULL && root->right == NULL){
        v.push_back(root->val);
    }
    inorder(root->right, v);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> v1;
    vector<int> v2;
    
    inorder(root1, v1);
    inorder(root2, v2);
    
    if(v1.size() != v2.size()) return false;
    
    for(int i = 0;i<v1.size();i++){
        if(v1[i] != v2[i]) return false;
    }
    return true;
}

int main(){

    TreeNode* root1 = takeInputLevelWise();
    TreeNode* root2 = takeInputLevelWise();

    cout<<leafSimilar(root1, root2);

    return 0;
}