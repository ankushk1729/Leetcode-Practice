// 410. Split Array Largest Sum

/*
	Input: nums = [7,2,5,10,8], m = 2
	Output: 18
	Explanation:
	There are four ways to split nums into two subarrays.
	The best way is to split it into [7,2,5] and [10,8],
	where the largest sum among the two subarrays is only 18.
*/

#include <bits/stdc++.h>
using namespace std;
	
	// Logic - Binary Search on Answers
	// range of answer is Max_element(arr) to Sum(arr)
	// i.e in binary search => left = Max_element(arr) and right = Sum(arr)
    bool isLargestSubarraySumInLimit(vector<int>& nums,int m,int l){
        int k  = 1;
        int sum = 0;
        
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > l) return false;
            
            if(nums[i] + sum > l){
                k++;
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
        }
        return k <= m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(),nums.end());
        
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = high;
        
        while(low <= high){
            int mid = (low + high) / 2;
            
            if(!isLargestSubarraySumInLimit(nums,m,mid)) {
                low = mid + 1;
            }
            else{
              high = mid - 1;
              ans = mid;
            } 
        }
        return ans;
    }

 int main(){

 	vector<int> nums = {1,2,3,4,5};

 	int m = 2;

 	cout<<splitArray(nums,m);

 	return 0;
 }