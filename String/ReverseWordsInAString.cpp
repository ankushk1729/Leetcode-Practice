// 151. Reverse Words in a String

/*
    Input: s = "the sky is blue"
    Output: "blue is sky the"

    Input: s = "  hello world  "
    Output: "world hello"
    Explanation: Your reversed string should not contain leading or trailing spaces.
*/

#include <bits/stdc++.h>
using namespace std;


string reverseWords(string s) {
    stack<string> st;
    
    int end = 0;
    string word = "";
    while(end <= s.length()-1){
        if(s[end] != ' '){
            word.push_back(s[end]);
        }
        else {
            if(word.length() != 0)
                st.push(word);
            word = "";
        }
        end++;
    }
    if(word.length() != 0) st.push(word);
    string ans;
    while(!st.empty()){
        ans.append(st.top());
        st.pop();
        if(st.size() == 0) break;
        ans.append(" ");
    }
    
    return ans;
}


int main(){

    string s = "  hello world  ";

    cout<<reverseWords(s);

    return 0;
}