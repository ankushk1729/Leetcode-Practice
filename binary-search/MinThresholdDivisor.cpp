// 1283. Find the Smallest Divisor Given a Threshold

/*
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
*/

// Intiution

// The minimum divisor will be 1 and the maximum divisor would be the max element of the array as dividing
// the elements by something greater than the max element will yield the same result as the max element.
// For example - [1,2,5,9] when we take divisor as 9 i.e the max element then the sum of the division will be 4
// also dividing by something greater than max element i.e 9 will also give the result as 4

// The max sum can be the sum of all the elements in case we take the smallest divisor i.e 1.
// The min sum can be the length of the array as when we divide by the max divisor all elements will yield 1 as output
// and 1*n = n

#include<bits/stdc++.h>
using namespace std;

int sumAfterDiv(vector<int>& nums,int div){
	int sum = 0;
	for(int i = 0;i<nums.size();i++){
		sum += nums[i]/div;

		if(nums[i]%div != 0){
			sum += 1;
		}
	}
	return sum;
}


// Method 1 
// Time complexity - O(n*max_element)
// Space Complexity - O(1)
int smallestDivisor1(vector<int>& nums,int threshold){
	int max = *max_element(nums.begin(),nums.end());
	int ans = max;
	for(int i = 1;i<max;i++){
		if(sumAfterDiv(nums,i) <= threshold){
			return i;
		}
	}
	return ans;
}


// Method 2 - Binary Search (Binary search on answers)
// Time Complexity - O(n*log(max_element))
// Space Complexity - O(1)
int smallestDivisor(vector<int>& nums,int threshold){
	int low = 1,high = *max_element(nums.begin(),nums.end());
	int ans = high;

	while(low <= high){
		int mid = (low + high) / 2;
		if(sumAfterDiv(nums,mid) <= threshold){
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}


int main(){
	vector<int> nums = {1,2,5,9};
	int thres = 6;
	cout<<smallestDivisor(nums,thres);
	return 0;
}