// 2342. Max Sum of a Pair With Equal Sum of Digits

/*
	Input: nums = [18,43,36,13,7]
	Output: 54
	Explanation: The pairs (i, j) that satisfy the conditions are:
	- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
	- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
	So the maximum sum that we can obtain is 54.
*/

#include <bits/stdc++.h>
using namespace std;


int findDigitSum(int num){
    int sum = 0;
    while(num){
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}

int maximumSum(vector<int>& nums) {
    unordered_map<int, vector<int>> m;
    int maxi = -1;
    for(auto x : nums) m[findDigitSum(x)].push_back(x);
    
    for(auto mapItem : m){
        vector<int> mapItemArray = mapItem.second;
        int size = mapItemArray.size();
        
        if(size > 1){
            sort(mapItemArray.begin(), mapItemArray.end());
            maxi = max(maxi, mapItemArray[size-1] + mapItemArray[size-2]);
        }
    }
    
    return maxi;
}


int main(){

	vector<int> nums = {18,43,36,13,7};

	cout<<maximumSum(nums);

	return 0;

}