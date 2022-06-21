// 1642. Furthest Building You Can Reach

/*
    Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
    Output: 4
    Explanation: Starting at building 0, you can follow these steps:
    - Go to building 1 without using ladders nor bricks since 4 >= 2.
    - Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
    - Go to building 3 without using ladders nor bricks since 7 >= 6.
    - Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
    It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
*/

#include <bits/stdc++.h>
using namespace std;

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int> pq;
    
    for(int i = 0;i<heights.size()-1;i++){
        int diff = heights[i+1] - heights[i];
        
        if(diff > 0){
            pq.push(-diff);
        }
        if(pq.size() > ladders){
            bricks += pq.top();
            pq.pop();
        }
        if(bricks < 0){
            return i;
        }
    }
    return heights.size()-1;
}


int main(){

    vector<int> heights = {4,2,7,6,9,14,12};

    cout<<furthestBuilding(heights, 5, 1);

    return 0;
}