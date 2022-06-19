// 1753. Maximum Score From Removing Stones

/*
    Input: a = 2, b = 4, c = 6
    Output: 6
    Explanation: The starting state is (2, 4, 6). One optimal set of moves is:
    - Take from 1st and 3rd piles, state is now (1, 4, 5)
    - Take from 1st and 3rd piles, state is now (0, 4, 4)
    - Take from 2nd and 3rd piles, state is now (0, 3, 3)
    - Take from 2nd and 3rd piles, state is now (0, 2, 2)
    - Take from 2nd and 3rd piles, state is now (0, 1, 1)
    - Take from 2nd and 3rd piles, state is now (0, 0, 0)
    There are fewer than two non-empty piles, so the game ends. Total: 6 points.

*/

#include <bits/stdc++.h>
using namespace std;

int maximumScore(int a, int b, int c) {
    priority_queue<int> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    int ans = 0;
    while(true){
        int t = pq.top();
        pq.pop();
        int st = pq.top();
        pq.pop();
        if(t <= 0 || st <= 0) break;
        ans++;
        pq.push(t-1);
        pq.push(st-1);
    }
    return ans;
}


int main(){

    cout<<maximumScore(4, 4, 6);

    return 0;
}