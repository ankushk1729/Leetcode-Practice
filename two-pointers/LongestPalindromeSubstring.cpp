// 5. Longest Palindromic Substring

/*
    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.

    Input: s = "cbbd"
    Output: "bb"
*/

#include <bits/stdc++.h>
using namespace std;


void solve(int l, int r, string& s, string& res, int& maxLen){
    // extend the substring on both sides till left and right elements are same
    while(l >= 0 && r < s.length() && s[l] == s[r]){
            if(r - l + 1 > maxLen){
                maxLen = r - l + 1;
                res.assign(s,l,r - l + 1);
            }
            l--;
            r++;
        }
}
string longestPalindrome(string s) {
    int maxLen = 0;
    string res = "";
    for(int i = 0;i<s.length();i++){
        // For odd length substrings
        solve(i, i, s, res, maxLen);
        
        // For even length substrings
        solve(i, i + 1, s, res, maxLen);
    }
    return res;
}


int main(){

    string s1 = "cbbd";

    // Even length longest palindrome substring
    cout<<longestPalindrome(s1)<<endl;

    string s2 = "babad";

    // Odd length longest palindrome substring
    cout<<longestPalindrome(s2)<<endl;

    return 0;
}