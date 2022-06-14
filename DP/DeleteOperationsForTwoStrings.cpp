// 583. Delete Operation for Two Strings

/*
    Input: word1 = "sea", word2 = "eat"
    Output: 2
    Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
*/

#include <bits/stdc++.h>
using namespace std;


int solve(string& w1, string& w2, vector<vector<int>>& dp, int i, int j){
    // If we have traversed both the strings till the end at the same time,
    // that means there are no extra characters, so return 0.
    // (Is being handled by the below base case but just added to minimize a max 
    // operation on some large string sizes)
    if(i == w1.length() && j == w2.length()) return 0;
    
    // If one of the strings is traversed completely before the other, 
    // that means there are some extra characters in the other string, 
    // so we add the remaining length to our steps count.
    if(i == w1.length() || j == w2.length()) return max(w1.length()-i, w2.length()-j);
    
    
    // return the cached value.
    if(dp[i][j] != -1) return dp[i][j];
    
    // if both characters are same that means no need to remove those characters
    // from both the strings, so just increment the pointer for both strings.
    if(w1[i] == w2[j]) return solve(w1, w2, dp, i + 1, j + 1);
    
    // otherwise we add one to the step count and solve for minimum steps
    // from the options of removing from string w1 or w2.
    return dp[i][j] = 1 + min(solve(w1, w2, dp, i + 1, j), solve(w1, w2, dp, i, j + 1));
}
int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
    return solve(word1, word2, dp, 0, 0);
}


int main(){

    string s1 = "leetcode";
    string s2 = "etco";

    cout<<minDistance(s1, s2);

    return 0;
}