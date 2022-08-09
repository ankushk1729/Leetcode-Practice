// 516. Longest Palindromic Subsequence

/*
    Input: s = "bbbab"
    Output: 4
    Explanation: One possible longest palindromic subsequence is "bbbb".
*/

#include <bits/stdc++.h>
using namespace std;


int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
    if(i < 0 || j < 0) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]) return dp[i][j] = 1 + solve(s1, s2, i - 1, j - 1, dp);
    
    return dp[i][j] = max(solve(s1, s2, i - 1, j, dp), solve(s1, s2, i, j - 1, dp));
}
int longestPalindromeSubseq(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    int m = s.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));
    
    return solve(s, t, m - 1, m - 1, dp);   
}

int main()
{
    cout<<longestPalindromeSubseq("bbbab");
    return 0;
}