// 724. Find Pivot Index


/*
    Input: nums = [1,7,3,6,5,6]
    Output: 3
    Explanation:
    The pivot index is 3.
    Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
    Right sum = nums[4] + nums[5] = 5 + 6 = 11


    Input: nums = [1,2,3]
    Output: -1
    Explanation:
    There is no index that satisfies the conditions in the problem statement.
*/


#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int totSum = 0;
    for(auto x : nums) totSum += x;
    int prefixSum = 0;
    for(int i = 0;i<nums.size();i++){
        if(totSum - nums[i] == 2*prefixSum) return i;
        
        prefixSum += nums[i];
    }
    return -1;
}

int main(){

    vector<int> nums = {1,7,3,6,5,6};

    // Returns the pivot index if any otherwise -1
    cout<<pivotIndex(nums);

    return 0;
}