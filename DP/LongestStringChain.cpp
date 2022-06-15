// 1048. Longest String Chain

/*
    Input: words = ["a","b","ba","bca","bda","bdca"]
    Output: 4
    Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

    Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
    Output: 5
    Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
*/

#include <bits/stdc++.h>
using namespace std;

// comparator function
bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}


bool check(string& s1, string& s2){
    // if the difference in length is not 1, then not possible
    if(s1.size()  != s2.size() + 1) return false;
    
    int p1 = 0, p2 = 0;
    
    while(p1 < s1.size()){
        if(p2 < s2.size() && s1[p1] == s2[p2]) {
            p1++;
            p2++;
        }
        else p1++;
        
    }
    // if both pointers reach at the end simultaneously then possible
    return (p1 == s1.size() && p2 == s2.size());
}

// The approach is similar to longest increasing subsequence
int longestStrChain(vector<string>& words) {
    // sorting because we can choose a sequence rather than a subsequence,
    // so random pickup is allowed and hence once sorted by length we can
    // do the same way as it was for subsequence
    sort(words.begin(), words.end(), comp);
    
    int n = words.size();
    vector<int> dp(n,1);
    
    int maxi = 1;
    for(int i = 0;i<n;i++){
        for(int prev = 0;prev<i;prev++){
            if(check(words[i],words[prev]) && dp[prev] + 1 > dp[i]){
                dp[i] = dp[prev] + 1;
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}



int main(){

    vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};

    cout<<longestStrChain(words);

    return 0;
}