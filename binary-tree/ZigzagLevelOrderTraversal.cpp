// 103. Binary Tree Zigzag Level Order Traversal

/*
    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[20,9],[15,7]]
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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    bool flag = true;
    stack<int> s;
    while(q.size()){
        int size = q.size();
        vector<int> v;
        if(flag == true){
            for(int i = 0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                v.push_back(front->val);
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
        else {
            for(int i = 0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
            
                s.push(front->val);
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            while(s.size()){
                int val = s.top();
                s.pop();
                v.push_back(val);
            }
        }
        ans.push_back(v);
        flag = flag ? false : true;
    }
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
    vector<vector<int>> v = zigzagLevelOrder(root);

    for(auto x:v){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}