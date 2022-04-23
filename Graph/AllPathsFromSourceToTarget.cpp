// 797. All Paths From Source to Target

/*
	Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
	Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
*/

#include<bits/stdc++.h>
using namespace std;

    
    void getPaths(vector<vector<int>>& graph,vector<int>& path,vector<vector<int>>& ans,int index,int n){
        path.push_back(index);
        if(index == n - 1) {
            ans.push_back(path);
        }
        for(int i = 0;i<graph[index].size();i++){
            getPaths(graph,path,ans,graph[index][i],n);
        }   
        path.pop_back();
    }
        
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        getPaths(graph,path,ans,0,graph.size());
        
        return ans;
    }



int main(){

	vector<vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};

	vector<vector<int>> ans = allPathsSourceTarget(graph);

	for(auto x : ans){
		for(auto y : x){
			cout<<y<<" ";
		}
		cout<<endl;
	}

	return 0;
}