// 62. Unique Paths

/*
    Input: m = 3, n = 2
    Output: 3
    Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
    1. Right -> Down -> Down
    2. Down -> Down -> Right
    3. Down -> Right -> Down
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& dp, int m, int n, int i, int j){
    if(i > m - 1 || j > n - 1) return 0;
    
    if(i == m - 1 && j == n - 1) return 1;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int right = solve(dp, m, n, i, j + 1);
    int down = solve(dp, m, n, i + 1, j);
    
    return dp[i][j] = right + down;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    
    return solve(dp, m, n, 0, 0);
}

int main(){

    cout<<uniquePaths(3, 7);

    return 0;
}