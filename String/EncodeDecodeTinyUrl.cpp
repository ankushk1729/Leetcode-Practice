// 535. Encode and Decode TinyURL

/*
    Input: url = "https://leetcode.com/problems/design-tinyurl"
    Output: "https://leetcode.com/problems/design-tinyurl"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string,string> map;
    int n = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        n++;
        string temp = "https://SixetyNine.com/";
        temp += n;
        map[temp] = longUrl;
        return temp;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

int main(){
    string url = "https://leetcode.com/problems/design-tinyurl";
    Solution solution;
    cout<<solution.decode(solution.encode(url));
    return 0;
}
