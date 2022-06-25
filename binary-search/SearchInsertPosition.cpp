// 35. Search Insert Position

/*
    Input: nums = [1,3,5,6], target = 5
    Output: 2

    Input: nums = [1,3,5,6], target = 2
    Output: 1
*/


#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    
    while(low <= high){
        int mid = (low + high) / 2;
        
        if(nums[mid] < target) low = mid + 1;
        
        else high = mid - 1;
    }
    return low;
}


int main(){

    vector<int> nums = {1,3,5,6};

    cout<<searchInsert(nums, 2);

    return 0;
}