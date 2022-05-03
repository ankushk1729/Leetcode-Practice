// 109. Convert Sorted List to Binary Search Tree

/*
    Input: head = [-10,-3,0,5,9]
    Output: [0,-3,9,-10,null,5]
    Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
*/


// Divide and Conquer

#include<bits/stdc++.h>
using namespace std;

  // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

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

    void traverseList(ListNode* head,vector<int>& nums){
        ListNode* temp = head;
        while(temp != NULL){
            nums.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    TreeNode* makeBST(vector<int>& nums,int low,int high){
        if(high < low) return NULL;
         TreeNode* root = new TreeNode();
        if(low == high){
           root->val = nums[low];
           return root;
         }
        int mid = (low + high) / 2;
        
        root->val = nums[mid];
        
        root->left = makeBST(nums,low,mid-1);
        root->right = makeBST(nums,mid+1,high);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        traverseList(head,nums);
        
        return makeBST(nums,0,nums.size()-1);
    }


int main(){

    // Driver Code

    // Creating LL
    ListNode* head = new ListNode(-10);
    ListNode* n2 = new ListNode(-3);
    head->next = n2;
    ListNode* n3 = new ListNode(0);
    n2->next = n3;
    ListNode* n4 = new ListNode(5);
    n3->next = n4;
    ListNode* n5 = new ListNode(9);
    n4->next = n5;

    TreeNode* root = sortedListToBST(head);

    printTreeLevelWise(root);

    return 0;
}
