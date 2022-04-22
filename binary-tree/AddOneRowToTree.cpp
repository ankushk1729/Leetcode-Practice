// 623. Add One Row to Tree

/*
    Input: root = [4,2,6,3,1,5], val = 1, depth = 2
    Output: [4,1,1,2,null,null,6,3,1,5]
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
 
class Solution {
public:
    void addRow(TreeNode* root,int val){
        TreeNode* leftChild = root->left;
        TreeNode* rightChild = root->right;
        
        TreeNode* rowleft = new TreeNode(val);
        TreeNode* rowright = new TreeNode(val);
        
        root->left = rowleft;
        root->right = rowright;
        
        rowleft->left = leftChild;
        rowright->right = rightChild;

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        int dep = 1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            int size = q.size();
            
            if(dep == depth-1){
                for(int i = 0;i<size;i++){
                    TreeNode* front = q.front();
                    q.pop();
                    addRow(front,val);
                }
                break;
            }
            for(int i = 0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            dep++;
        }
        return root;
    }
};



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
    Solution *obj1 = new Solution();

    TreeNode* root =takeInputLevelWise();
    int val,depth;
    cout<<"Enter val"<<endl;
    cin>>val;
    cout<<"Enter depth"<<endl;
    cin>>depth;
    
    obj1->addOneRow(root,val,depth);
    return 0;
}