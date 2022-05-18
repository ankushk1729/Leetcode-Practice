// 2161. Partition Array According to Given Pivot


/*
    Input: nums = [9,12,5,10,14,3,10], pivot = 10
    Output: [9,5,3,10,10,12,14]
    Explanation: 
    The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
    The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
    The relative ordering of the elements less than and greater than pivot is also maintained.
     [9, 5, 3] and [12, 14] are the respective orderings.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> ans(nums.size(),0);
    int i = 0;
    
    // First inserting values smaller than pivot
    for(int x : nums){
        if(x < pivot)
            ans[i++] = x;
    }

    // Inserting the pivot element
    for(int x : nums){
        if(x == pivot)
            ans[i++] = x;
    }
    
    // Inserting the elements greater than pivot
    for(int x : nums){
        if(x > pivot)
            ans[i++] = x;
    }
    
    return ans;
    
}

int main(){

    vector<int> nums  = {9,12,5,10,14,3,10};

    vector<int> ans = pivotArray(nums,10);

    for(auto x : ans) cout<<x<<" ";

    return 0;
}
