// 81. Search in Rotated Sorted Array II

/*
    Input: nums = [2,5,6,0,0,1,2], target = 0
    Output: true

    Input: nums = [2,5,6,0,0,1,2], target = 3
    Output: false
*/

#include <bits/stdc++.h>
using namespace std;

    bool search(vector<int>& nums, int target) {
        int low = 0,high = nums.size()-1;
        
        while(low <= high){
            int mid = (low + high) / 2;
            
            // if target element present at mid, return true
            if(nums[mid] == target) return true;
            
            // if left subarray is sorted
            if(nums[low] < nums[mid]){
                // if element exists in left subarray
                if(target >= nums[low]  && target <= nums[mid]){
                    high = mid - 1;
                }
                // else it exists in right subarray
                else low = mid + 1;
            }
            
            // else if element at low is equal to element at mid, then we are sure
            // that it can't be our target element, that's why we eliminate low by low++
            else if(nums[low] == nums[mid]) low++;
            
            // else right subarray is sorted
            else {
                // if element exists in right subarray
                if(target >= nums[mid]  && target <= nums[high]){
                    low = mid + 1;
                }
                // else it exists in left subarray
                else high = mid - 1;
            }
        }
        return false;
    }


int main(){

    vector<int> nums = {2,5,6,0,0,1,2};

    int target = 0;

    // Returns true if element exists in array otherwise false
    cout<<search(nums,target);

    return 0;
}