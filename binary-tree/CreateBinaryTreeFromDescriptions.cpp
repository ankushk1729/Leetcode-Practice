// 2196. Create Binary Tree From Descriptions


/*
    Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
    Output: [50,20,80,15,17,19]
    Explanation: The root node is the node with value 50 since it has no parent.

*/

#include <bits/stdc++.h>
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

void printTreeLevelWise(TreeNode* root) {
    queue<TreeNode*> remainingNodes;
    remainingNodes.push(root);
    while(remainingNodes.size()!= 0) {
        TreeNode* front = remainingNodes.front();
        remainingNodes.pop();
        cout<<front->val<<":";
        if(front->left!= NULL) {
            cout<<"L"<<front->left->val<<",";
            remainingNodes.push(front->left);
        }
        if(front->right!= NULL) {
            cout<<"R"<<front->right->val;
            remainingNodes.push(front->right);
        }
        cout<<endl;
    }
}


    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        // For keeping reference of each node
        unordered_map<int,TreeNode*> map;
        
        // For maintaing whether a node is child node or not
        unordered_map<int,bool> isChild;
        
        for(auto x:descriptions){
            // If parent doesn't exits we create a new node and push it in hashmap
            if(map.find(x[0]) == map.end()){
                TreeNode* parent = new TreeNode(x[0]);
                map[x[0]] = parent;
            }
            
            // If child doesn't exits we create a new node and push it in hashmap
            if(map.find(x[1]) == map.end()){
                TreeNode* child = new TreeNode(x[1]);
                map[x[1]] = child;
            }    
            
            if(x[2] == 1) map[x[0]]->left = map[x[1]];
            else map[x[0]]->right = map[x[1]];
            isChild[x[1]] = true;    
        }
        
        TreeNode* ans;
        for(auto x : descriptions){
            // If a node isn't a child that means it's the root of tree
            if(!isChild[x[0]]){
                ans = map[x[0]];
                break;
            }
        }
        return ans;
    }

int main(){

    vector<vector<int>> descriptions = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};

    TreeNode* root = createBinaryTree(descriptions);

    printTreeLevelWise(root);

    return 0;
}