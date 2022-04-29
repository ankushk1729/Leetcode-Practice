// 785. Is Graph Bipartite?

/*
	Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
	Output: false
	Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
*/

#include <bits/stdc++.h>
using namespace std;
	
	// Traverse all the nodes by BFS giving alternate colors to adjacent nodes, if we reach a node whose color is same
	// as its adjacent node that means graph is bipartite
    bool bipartiteBFS(int start,vector<vector<int>>& graph,int color[],int n){
        queue<int> nodes;
        nodes.push(start);
        color[start] = 1;
        
        while(!nodes.empty()){
            int front = nodes.front();
            nodes.pop();
            
            for(auto i:graph[front]){
                if(color[i] == -1){
                    color[i] = 1 - color[front];
                    nodes.push(i);
                }
                else if(color[i] == color[front]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        
        memset(color,-1,sizeof color);
        
        for(int i = 0;i<n;i++){
            if(color[i] == -1){
                if(!bipartiteBFS(i,graph,color,n)) return false;
            }
        }
        return true;
    }


int main(){

	vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};

	cout<<isBipartite(graph)<<endl;

	return 0;
}