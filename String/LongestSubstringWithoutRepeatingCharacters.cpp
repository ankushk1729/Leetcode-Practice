// 3. Longest Substring Without Repeating Characters


/*
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.
*/

#include <bits/stdc++.h>
using namespace std;

 int lengthOfLongestSubstring(string s) {
    
    unordered_map<char, int> map;
    int st = -1;
    int len = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (map.count(s[i]) != 0) {
            st = max(st, map[s[i]]);
        }
        map[s[i]] = i;
        len = max(len, i-st);
    }
    
    return len;
}

int main(){

    string s = "abcabcbb";

    cout<<lengthOfLongestSubstring(s);

    return 0;
}