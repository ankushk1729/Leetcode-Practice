// 15. 3Sum

/*
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation: 
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not matter.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    
    for(int i = 0;i<nums.size()-2;i++){
        if(i == 0 ||(i > 0 && nums[i] != nums[i-1])){
            int low = i + 1, high = nums.size()-1, sum = 0 - nums[i];
            
            while(low < high){
                
                if(nums[low] + nums[high] == sum){
                    vector<int> temp;
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    temp.push_back(nums[i]);
                    ans.push_back(temp);
                    
                    while(low < high && nums[low] == nums[low + 1]) low++;
                    while(low < high && nums[high] == nums[high - 1]) high--;
                    
                    low++;
                    high--;
                }
                else if(nums[low] + nums[high] < sum) low++;
                else high--;
            }
        }
    }
    return ans;
}


int main(){

    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> ans = threeSum(nums);

    for(auto x : ans) {
        for(auto y : x) {
            cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}