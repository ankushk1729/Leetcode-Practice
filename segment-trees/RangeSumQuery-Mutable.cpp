// 307. Range Sum Query - Mutable


// Solution using segment trees.

/*
    Input
    ["NumArray", "sumRange", "update", "sumRange"]
    [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
    Output
    [null, 9, null, 8]
*/

#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> seg;
    vector<int> arr;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();

        // Because max nodes or indexes in segment tree can be 4*n [There is a proof for that].
        seg.resize(4*n+1);
        for(auto x:nums) arr.push_back(x);
        build(0,0,n-1);
    }
    
    void build(int ind,int low,int high){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        
        // Recursively building left and right subtree.
        build(2*ind+1,low,mid);
        build(2*ind+2,mid+1,high);
        
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    
    // Updates the segment tree
    void updateH(int ind,int low,int high,int i,int val){

        // Base case for recursion - We have finally reached the index for which we want to update the value.
        if(low == high){
            seg[ind] = val;
            return;
        }
        
        int mid = (low + high) / 2;
        
        // Checking if index exits in left subtree
        if(i<=mid) updateH(2*ind+1,low,mid,i,val);

        // Else it exists in right subtree
        else updateH(2*ind+2,mid+1,high,i,val);
        
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    
    void update(int index, int val) {
        updateH(0,0,n-1,index,val);
        arr[index] = val;
    }
    
    int query(int ind,int low,int high,int l,int r){

        // No overlaping
        // [l r] [low high] or [low high] [l r] 
        if(r < low || high < l) return 0;
        
        // Complete overlaping
        // [l low high r]
        if(l <= low && high <= r) return seg[ind];
        
        // Partial overlaping
        int mid = (low + high) / 2;
        
        // Querying the answer from left and right subtree.
        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
        
        return left + right;
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

  
 



int main(){

    vector<int> nums = {1,3,5};
	NumArray numArray(nums);
	cout<<numArray.sumRange(0, 2)<<endl; // return 1 + 3 + 5 = 9
	numArray.update(1, 2);   // nums = [1, 2, 5]
	cout<<numArray.sumRange(0, 2)<<endl; // return 1 + 2 + 5 = 8

	return 0;
}
    