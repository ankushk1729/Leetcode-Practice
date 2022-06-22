// 215. Kth Largest Element in an Array

/*
    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5
*/

#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    
    for(auto x : nums) pq.push(x);
    
    int ans;
    while(k--){
        ans = pq.top();
        pq.pop();
    }
    return ans;
}

int main(){

    vector<int> nums = {3, 2, 1, 5, 6, 4};

    cout<<findKthLargest(nums, 2);

    return 0;
}