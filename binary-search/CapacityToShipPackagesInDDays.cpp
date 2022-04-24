// 1011. Capacity To Ship Packages Within D Days


// Logic - Binary Search on Answers
// range of answer is Max_element(arr) to Sum(arr)
// i.e in binary search => left = Max_element(arr) and right = Sum(arr)

/*
	Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
	Output: 15
	Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
	1st day: 1, 2, 3, 4, 5
	2nd day: 6, 7
	3rd day: 8
	4th day: 9
	5th day: 10

	Note that the cargo must be shipped in the order given,
	so using a ship of capacity 14 and splitting the packages into parts like
	(2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
*/

#include<bits/stdc++.h>
using namespace std;

    int checkIsMin(vector<int>& weights,int w,int days){
        int sum = 0;
        int d = 0;
        int i = 0;
        while(i<weights.size()){
            if(sum +weights[i] == w){
                d++;
                sum = 0;
                i++;
            }
            else if(sum + weights[i] > w){
                d++;
                sum = 0;
            }
            else {
                sum += weights[i];
                i++;
            }
        }
        if(d < days) return 1;
        
        if(d == days && sum == 0) return 2;
        
        return 0;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int max = *max_element(weights.begin(),weights.end());
        
        int low = max,high = accumulate(weights.begin(),weights.end(),0);
        while(low < high){
            int mid = (low + high) / 2;
            if(checkIsMin(weights,mid,days) == 1){
                high = mid;
            }
            else if(checkIsMin(weights,mid,days) == 0) {
                low = mid + 1;
            }
            else return mid;
        }
        return low;
    }

int main(){

	vector<int> weights = {3,2,2,4,1,4};
	int days = 3;

	cout<<shipWithinDays(weights,days);

	return 0;
}    