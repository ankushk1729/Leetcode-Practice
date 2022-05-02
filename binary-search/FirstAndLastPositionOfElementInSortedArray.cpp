// 34. Find First and Last Position of Element in Sorted Array


/*
	Input: nums = [5,7,7,8,8,10], target = 6
	Output: [-1,-1]

	Input: nums = [5,7,7,8,8,10], target = 8
	Output: [3,4]
*/

#include<bits/stdc++.h>
using namespace std;

    int firstPosition(vector<int>& nums,int target){
        int low = 0,high = nums.size()-1;
        
        int firstIndex = INT_MAX;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(nums[mid] == target){
                firstIndex = min(firstIndex,mid);
                high = mid - 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return firstIndex;
    }
    int secondPosition(vector<int>& nums,int target){
        int low = 0,high = nums.size()-1;
        
        int secondIndex = INT_MIN;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(nums[mid] == target){
                secondIndex = max(secondIndex,mid);
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return secondIndex;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        
        int firstIndex = firstPosition(nums,target);
        int secondIndex = secondPosition(nums,target);
        
        if(firstIndex != INT_MAX){
            ans[0] = firstIndex;
        }
        if(secondIndex != INT_MIN){
            ans[1] = secondIndex;
        }
        return ans;
    }

int main(){

	vector<int> nums = {5,7,7,8,8,10};
	int target = 8;

	vector<int> ans = searchRange(nums,target);

	cout<<"[ "<<ans[0]<<", "<<ans[1]<<" ]"<<endl;
	return 0;
}