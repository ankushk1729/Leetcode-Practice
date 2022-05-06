// 33. Search in Rotated Sorted Array

/*
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1

*/

#include <bits/stdc++.h>
using namespace std;

    int search(vector<int>& nums, int target) {
        int low = 0,high = nums.size()-1;
        while(low <= high){
            int mid = (low + high)/2;
            
            // if target element present at mid, return mid
            if(nums[mid] == target){
                return mid;
            }
            
            // if left subarray is sorted
            if(nums[low] <= nums[mid]){
                // if element exists in left subarray
                if(target >= nums[low] && target <= nums[mid]){
                    high = mid - 1;
                }
                // else it exists in right subarray
                else low = mid + 1;
            }
            
            // else right subarray is sorted
            else {
                // if element exists in right subarray
                if(target >= nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                // else it exists in left subarray
                else high = mid - 1;
            }
        }
        return -1;
    }


int main(){

    vector<int> nums = {4,5,6,7,0,1,2};

    int target = 0;

    // Returns index of target element if found otherwise -1
    cout<<search(nums,target);

    return 0;
}