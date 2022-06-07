// 88. Merge Sorted Array


/*
    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]
    Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
    The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int n1 = m - 1;
    int n2 = n - 1;
    int i = m + n - 1; // Last index of nums1 array
    
    // Start from back and fill the greater elements from nums1 and nums2
    while(n1 >= 0 && n2 >= 0){
        if(nums1[n1] > nums2[n2]) nums1[i--] = nums1[n1--];
        else nums1[i--] = nums2[n2--];
    }
    
    // If there are still elements remaining in nums2
    while(n2 >= 0) nums1[i--] = nums2[n2--];
}

int main(){

    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
    merge(nums1,m,nums2,n);

    for(auto x : nums1) cout<<x<<" ";

    return 0;
}