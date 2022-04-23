// 2221. Find Triangular Sum of an Array

/*
	You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).

	The triangular sum of nums is the value of the only element present in nums after the following process terminates:

	Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a new 0-indexed integer array newNums of length n - 1.
	For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10, where % denotes modulo operator.
	Replace the array nums with newNums.
	Repeat the entire process starting from step 1.
	Return the triangular sum of nums
	Input: nums = [1,2,3,4,5]
	Output: 8
*/
	
#include<bits/stdc++.h>
using namespace std;

int triangularSum(vector<int>& nums) {
        int n = nums.size();
        
        while(n > 1){
            vector<int> newNums(nums.size()-1,0);
            
            for(int i = 0;i<nums.size()-1;i++){
                newNums[i] = (nums[i] + nums[i+1]) % 10;
            }
            
            nums = newNums;
            n--;
        }
        return nums[0];
    }


int main(){

	vector<int> nums = {1,2,3,4,5};
	cout<<triangularSum(nums);

	return 0;
}