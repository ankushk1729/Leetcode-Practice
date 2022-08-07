// 42. Trapping Rain Water

/*
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
    In this case, 6 units of rain water (blue section) are being trapped.
*/

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int ans = 0;
    int lMax = 0, rMax = 0;
    int l = 0; int r = height.size()-1;
    
    while(l <= r){
        if(height[l] <= height[r]){
            if(height[l] >= lMax) lMax = height[l];
            else ans += lMax - height[l];
            l++;
        }
        else {
            if(height[r] >= rMax) rMax = height[r];
            else ans += rMax - height[r];
            r--;
        }
    }
    
    return ans;
}

int main(){

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height);
    

    return 0;
}