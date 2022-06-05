// 2177. Find Three Consecutive Integers That Sum to a Given Number

/*
    Input: num = 33
    Output: [10,11,12]
    Explanation: 33 can be expressed as 10 + 11 + 12 = 33.
    10, 11, 12 are 3 consecutive integers, so we return [10, 11, 12].

    Input: num = 4
    Output: []
    Explanation: There is no way to express 4 as the sum of 3 consecutive integers.
*/

#include <bits/stdc++.h>
using namespace std;

vector<long long> sumOfThree(long long num) {
    vector<long long> nums;
    if(num % 3 == 0){
        long long mid = num / 3;
        nums.push_back(mid-1);            
        nums.push_back(mid);
        nums.push_back(mid+1);

    }
    return nums;
}


int main(){

    long long n;
    cin>>n;
    vector<long long> ans = sumOfThree(n);

    for(auto x : ans) cout<<x<<" ";

    return 0;
}