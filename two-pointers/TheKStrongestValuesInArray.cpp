// 1471. The k Strongest Values in an Array


/*
    Input: arr = [1,2,3,4,5], k = 2
    Output: [5,1]
    Explanation: Median is 3, the elements of the array sorted by the strongest are [5,1,4,2,3]. 
    The strongest 2 elements are [5, 1]. [1, 5] is also accepted answer.
    Please note that although |5 - 3| == |1 - 3| but 5 is stronger than 1 because 5 > 1.
*/

#include <bits/stdc++.h>
using namespace std;

  vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> ans;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        if(n == 1){
            ans.push_back(arr[0]);
            return ans;
        }
        int median = arr[(n-1)/2];
        
        int a = 0, b = arr.size()-1;
        // Traverse from both sides by two pointers until k elements are added in ans 
        while(ans.size() < k){
            if(abs(arr[a] - median) > abs(arr[b] - median)){
                ans.push_back(arr[a]);
                a++;
            }
            else if(abs(arr[a] - median) < abs(arr[b] - median)){
                ans.push_back(arr[b]);
                b--;
            }
            else {
                if(arr[a] > arr[b]){
                    ans.push_back(arr[a]);
                    a++;
                }
                else {
                    ans.push_back(arr[b]);
                    b--;
                }
            }
        }
        
        return ans;
    }


int main(){

    vector<int> arr = {1,2,3,4,5};

    int k = 2;  

    vector<int> ans = getStrongest(arr,k);

    for(auto x : ans) cout<<x<<" ";

    return 0;
}