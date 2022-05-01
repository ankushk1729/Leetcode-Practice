// 416. Partition Equal Subset Sum

/*
	Input: nums = [1,5,11,5]
	Output: true
	Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/


#include<bits/stdc++.h>
using namespace std;

// DP Tabulation + Space Optimization Solution
// Time Complexity - O(n*target)
// Space Complexity - O(target) [prev vector]
bool checkSubsetSum(int k,vector<int>& nums){
	int n = nums.size();

	vector<bool> prev(k+1,0),curr(k+1,0);

	prev[0] = curr[0] = true;

	if(nums[0] <= k) prev[nums[0]] = true;

	for(int ind = 1;ind<n;ind++){
		for(int target = 1;target <= k;target++){
			bool notTake = prev[target];

			bool take = false;

			if(target >= nums[ind]){
				take = prev[target - nums[ind]];
			}

			curr[target] = take || notTake;
		}
		prev = curr;
	}

	return prev[k];
}

int main(){
	vector<int> nums = {1,2,3,4,5};

	int totalSum = 0;

	int n = nums.size();

	for(int i = 0;i<n;i++) totalSum += nums[i];

	if(totalSum % 2 != 0) return false;

	int k = totalSum / 2;

	return checkSubsetSum(k,nums);
}