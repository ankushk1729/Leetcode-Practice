// 167. Two Sum II - Input Array Is Sorted

/*
	Array is 1-indexed
	Input: numbers = [2,7,11,15], target = 9
	Output: [1,2]
	Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
*/

#include<bits/stdc++.h>
using namespace std;

    vector<int> twoSum(vector<int>& numbers, int target) {
        int a = 0,b = numbers.size()-1;
        vector<int> ans;
        
        while(a < b){
            int sum = numbers[a] + numbers[b];
            
            if(sum == target){
                ans.push_back(a+1);
                ans.push_back(b+1);
                return ans;
            }
            
            else if(sum > target){
                b--;
            }
            else a++;
        }
        return ans;
    }



int main(){

	vector<int> numbers = {2,7,11,15};
	int target = 9;

	vector<int> ans = twoSum(numbers,target);
	cout<<"["<<ans[0]<<", "<<ans[1]<<"]"<<endl;
	return 0;
}
