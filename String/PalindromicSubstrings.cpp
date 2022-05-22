// 647. Palindromic Substrings


/*
    Input: s = "aaa"
    Output: 6
    Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

#include <bits/stdc++.h>
using namespace std;


int count(string s,int l,int r){
    int res = 0;
    
    // For every ind we expand our substring to left and right by 1
    // If the middle is a palindrome then we just need left and right element to be 
    // equal for the substring to be a palindrome
    // once we go out of the range or left and right are not equal we stop
    
    while(l >= 0 && r < s.length() && s[l] == s[r]){
        res++;
        l -= 1;
        r += 1;
    }
    
    return res;
}
int countSubstrings(string s) {
    int ans = 0;
    
    for(int i = 0;i<s.length();i++){
        // This will take care of all odd length substrings [1,3,5,7,...]
        ans += count(s,i,i);
        // This will take care of all even length substrings [2,4,6,8,...]
        ans += count(s,i,i+1);
    }
    
    return ans;
}


int main(){

    string s = "aaa";

    cout<<countSubstrings(s);

    return 0;
}