// 8. String to Integer (atoi)

/*
    Input: s = "   -42"
    Output: -42
    Explanation:
    Step 1: "   -42" (leading whitespace is read and ignored)
                ^
    Step 2: "   -42" ('-' is read, so the result should be negative)
                 ^
    Step 3: "   -42" ("42" is read in)
                   ^
    The parsed integer is -42.
    Since -42 is in the range [-231, 231 - 1], the final result is -42.
*/

#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    if(s.length() == 0) return 0;
    int i = 0;
    while(i < s.size() && s[i] == ' ') i++;
    
    s = s.substr(i);
    int sign = 1;
    long ans = 0;
    if(s[0] == '-') sign = -1;
    i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
    
    while(i < s.length()){
        if(s[i] == ' ' || !isdigit(s[i])) break;
        
        ans = ans*10 + (s[i] - '0');
        if(sign == -1 && -1*ans < INT_MIN) return INT_MIN;
        if(sign == 1 && ans > INT_MAX) return INT_MAX;
        i++;
    }
    return ans*sign;
}

int main(){

    cout<<myAtoi("   -42");

    return 0;
}