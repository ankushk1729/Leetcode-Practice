// 1332. Remove Palindromic Subsequences

/*
    Input: s = "ababa"
    Output: 1
    Explanation: s is already a palindrome, so its entirety can be removed in a single step.

    Input: s = "abb"
    Output: 2
    Explanation: "abb" -> "bb" -> "". 
    Remove palindromic subsequence "a" then "bb".
*/

#include <bits/stdc++.h>
using namespace std;

int removePalindromeSub(string s) {
    if(s == "") return 0;
    
    int i = 0, j = s.size() - 1;
    
    while(i < j){
        if(s[i] != s[j]) return 2;
        
        i++;
        j--;
    }
    return 1;
}

int main(){

    string s = "abb";

    cout<<removePalindromeSub(s);

    return 0;
}