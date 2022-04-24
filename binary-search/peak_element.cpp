//162. Find Peak Element




#include<bits/stdc++.h>

using namespace std;

// My Code
	
    int findPeakElement1(vector<int>& nums) {
        int low = 0,high = nums.size()-1;
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        while(low <= high) {
            int mid = (low + high)/2;
            int prev = mid == 0 ? INT_MIN : nums[mid-1];
            int next = mid == (n - 1) ? INT_MIN : nums[mid+1];
            if(nums[mid] > next && nums[mid] > prev ) return mid;
            
            else if(nums[mid] < next && nums[mid] > prev){
                low = mid + 1;
            }
            
            else if(nums[mid] > next && nums[mid] < prev){
                high = mid - 1;
            }
             
            else {
                if(prev > next){
                    high = mid - 1;
                }
                else low = mid + 1;
            }
        }
        return -1;
    }
	

// Second's Solution

int findPeakElement2(vector<int>& nums){
	int low = 0,high = nums.size()-1;

	while(low < high) {
		int mid = (low + high ) / 2;

		if(nums[mid] > nums[mid+1]){
			high = mid;
		}
		else {
			low = mid + 1;
		}

	}
	return low;
}    

// Driver Code
int main(){
	vector<int> nums = {1,2,3,4,3,2,5,1};

	cout<<findPeakElement2(nums)<<endl;

	cout<<findPeakElement1(nums)<<endl;

	return 0;
}