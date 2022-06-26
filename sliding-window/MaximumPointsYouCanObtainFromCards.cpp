// 1423. Maximum Points You Can Obtain from Cards

/*
    Input: cardPoints = [1,2,3,4,5,6,1], k = 3
    Output: 12
    Explanation: After the first step, your score will always be 1.
    However, choosing the rightmost card first will maximize your total score. 
    The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
*/


/* 
    Logic - We can remove k elements, that means we would be left with middle subarray with n - k elements.
    If we are able to find the minimum sum middle subarray, then we can find maximum sum subsequence of size k
    by subtracting the sum of minimum middle subarray from total sum of all elements.

    We are using sliding window of size n - k, and every time find the corresponding max sum subsequence from edges
*/

#include <bits/stdc++.h>
using namespace std;


int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int st = 0, end = n - k - 1;
    int windowSum = 0;
    int ans = INT_MIN;
    int totSum = 0;
    for(int i = 0;i<n;i++){
        // Finding the sum for first sliding window
        if(i <= end){
            windowSum += cardPoints[i];
        }
        totSum += cardPoints[i];
    }
    while(end < n){
        ans = max(ans, totSum - windowSum);
        windowSum -= cardPoints[st];
        st++;
        end++;
        if(end < n) windowSum += cardPoints[end];
    }
    return ans;
}


int main(){

    vector<int> cardPoints = {1,2,3,4,5,6,1};

    cout<<maxScore(cardPoints, 3);

    return 0;
}