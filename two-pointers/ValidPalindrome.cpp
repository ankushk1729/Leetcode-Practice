// 125. Valid Palindrome

/*
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.

    Input: s = " "
    Output: true
    Explanation: s is an empty string "" after removing non-alphanumeric characters.
    Since an empty string reads the same forward and backward, it is a palindrome.
*/


#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    string newString = "";
    
    for(auto x : s){
        if(isalnum(x)){
            if(isupper(x)){
                newString.push_back(tolower(x));
            }
            else newString.push_back(x);
        }
    }
    int st = 0, end = newString.length()-1;
    
    while(st < end){
        if(newString[st] != newString[end]) return false;
        st++;
        end--;
    }
    return true;
}

int main(){

    string s = "A man, a plan, a canal: Panama";

    cout<<isPalindrome(s);

    return 0;
}