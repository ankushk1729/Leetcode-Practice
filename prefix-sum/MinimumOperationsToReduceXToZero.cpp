// 1658. Minimum Operations to Reduce X to Zero


/*
    Input: nums = [1,1,4,2,3], x = 5
    Output: 2
    Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
*/

#include <bits/stdc++.h>
using namespace std;


int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    
    int sum = 0;
    unordered_map<int,int> map;
    map[0] = 0;
    
    for(int i = 0;i<n;i++){
        sum += nums[i];
        map[sum] = i;
    }
    
    if(x > sum) return -1;
    
    sum -= x;
    int val = 0;
    int longest = 0;
    for(int i = 0;i<n;i++){
        val += nums[i];
        
        if(map.count(val - sum)){
            
            if(val - sum == 0){
                longest = max(longest, i - map[val - sum] + 1);
            }
            else {
                longest = max(longest, i - map[val - sum]);
            }
        }
    }
    return longest == 0 ? (sum == 0 ? n : -1) : n - longest;
}


int main(){

    int x = 5;
    vector<int> nums = {1, 1, 4, 2, 3};
    
    cout<<minOperations(nums, x);

    return 0;
}