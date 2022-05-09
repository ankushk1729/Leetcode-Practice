// 17. Letter Combinations of a Phone Number


/*
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    Input: digits = ""
    Output: []
*/

#include <bits/stdc++.h>
using namespace std;

    void fillAns(int ind,string digits,string output,vector<string>& ans,vector<string>& mapping){
        if(ind == digits.size()){
            ans.push_back(output);
            return;
        }
        
        int num = digits[ind] - '0';
        
        string curr = mapping[num];
        
        for(int i = 0;i<curr.length();i++){
            output.push_back(curr[i]);
            fillAns(ind+1,digits,output,ans,mapping);
            
            // Backtracking and removing the character
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        string output = "";
        
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        fillAns(0,digits,output,ans,mapping);
        
        return ans;
    }


int main(){

    string digits = "23";

    vector<string> ans = letterCombinations(digits);

    for(auto x : ans) cout<<x<<endl;

    return 0;
}