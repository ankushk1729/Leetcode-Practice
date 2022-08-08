// 78. Subsets

/*
    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, int ind){
    if(ind == nums.size()){
        ans.push_back(curr);
        return;
    }
    curr.push_back(nums[ind]);
    solve(nums, curr, ans, ind+1);
    curr.pop_back();
    solve(nums, curr, ans, ind+1);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    solve(nums, curr, ans, 0);
    return ans;
}

int main(){

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> curr;
    solve(nums, curr, ans, 0);

    for(auto x : ans){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}