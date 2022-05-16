// 2149. Rearrange Array Elements by Sign


/*
	Input: nums = [3,1,-2,-5,2,-4]
	Output: [3,-2,1,-5,2,-4]
	Explanation:
	The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
	The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
	Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect
	because they do not satisfy one or more conditions.  
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int pInd = 0, nInd = 1;
    
    vector<int> ans(nums.size(),0);
    
    for(auto x : nums){
        if(x >= 0){
            ans[pInd] = x;
            pInd += 2;
        }
        else {
            ans[nInd] = x;
            nInd += 2;
        }
    }
    return ans;
}


int main(){

	vector<int> nums = {3,1,-2,-5,2,-4};

	vector<int> ans = rearrangeArray(nums);

	for(auto x : ans ) cout<<x<<" ";

	return 0;
}