// 1695. Maximum Erasure Value

/*
    Input: nums = [4,2,4,5,6]
    Output: 17
    Explanation: The optimal subarray here is [2,4,5,6].
*/

#include <bits/stdc++.h>
using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
    int res = 0;
    unordered_set<int> s;
    int i = 0, sum = 0;            
    for (int j = 0; j < nums.size(); j++) {
        while (s.find(nums[j]) != s.end()) {
            s.erase(nums[i]);
            sum -= nums[i];
            i++;
        }
        s.insert(nums[j]);
        sum += nums[j];
        res = max(res, sum);
    }
    return res;
}


int main(){

    vector<int> nums = {4, 2, 4, 5, 6};

    cout<<maximumUniqueSubarray(nums);

    return 0;
}