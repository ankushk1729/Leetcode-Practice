// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

/*
    Input: n = "32"
    Output: 3
    Explanation: 10 + 11 + 11 = 32
*/

#include <bits/stdc++.h>
using namespace std;

int minPartitions(string n) {
    int maxi = INT_MIN;
    
    for(int i = 0;i<n.length();i++){
        maxi = max(maxi, n[i] - '0');
    }
    return maxi;
}

int main(){

    string n = "82734";

    cout<<minPartitions(n);

    return 0;
}