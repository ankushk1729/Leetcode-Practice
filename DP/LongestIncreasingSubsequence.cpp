// 300. Longest Increasing Subsequence

/*
    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/


#include <bits/stdc++.h>
using namespace std;


// Memoization
int solve(int ind, int prev_ind, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == nums.size()) return 0;
        
        // not take case
        int len = solve(ind + 1, prev_ind, nums, dp);
        
        if(prev_ind == -1 || nums[ind] > nums[prev_ind])
            // take case
            len = max(len, 1 + solve(ind + 1, ind, nums, dp));
        
        return len;
    }

// Special tabulation
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++){
        for(int prev = 0;prev<i;prev++){
            if(nums[prev] < nums[i]){
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi,dp[i]);
    }
    return maxi;
}


int main(){

    vector<int> nums = {10,9,2,5,3,7,101,18};

    cout<<lengthOfLIS(nums);

    return 0;

}