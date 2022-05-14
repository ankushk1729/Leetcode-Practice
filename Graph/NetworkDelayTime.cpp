// 743. Network Delay Time


/*
	Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
	Output: 2

	Input: times = [[1,2,1]], n = 2, k = 2
	Output: -1
*/

#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    
    // Creating a adjacency list
    vector<vector<pair<int,int>>> g(n+1);
    
    for(auto x : times){
        g[x[0]].push_back(make_pair(x[1],x[2]));
    }

    // Distance array to keep the shortest distance to each node from starting node
    vector<int> distTo(n+1,1e9);
    distTo[k] = 0;

    // Priority queue is used instead of normal queue to always take shorter
    // distance (time in this problem)
    
    // If the edge weights (times) were same for all the edges then we could have
    // just used normal queue
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push(make_pair(0,k));

    vector<bool> visited(n+1,false);
    

    while(pq.size()){
        int prev = pq.top().second;
        pq.pop();

        if(visited[prev]) continue;

        visited[prev] = true;

        for(auto it:g[prev]){
            int next = it.first;
            int nextDis = it.second;
            
            // Checking if further relaxation of node is possible or not
            if(distTo[next] > distTo[prev] + nextDis){
                distTo[next] = distTo[prev] + nextDis;
                pq.push(make_pair(distTo[next],next));
            }
        }
    }
    
    int ans = *max_element(distTo.begin()+1,distTo.end());
    
    // If the max distance to reach any node is 1e9 that means signal didn't reach that node
    return ans == 1e9 ? -1 : ans;
    }

int main(){

	vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};

	// Returns the time taken for signal to reach all the nodes if possible, otherwise -1
	cout<<networkDelayTime(times,4,2);

	return 0;

}