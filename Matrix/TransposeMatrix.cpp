// 867. Transpose Matrix


/*
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [[1,4,7],[2,5,8],[3,6,9]]
*/

#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    vector<vector<int>> ans;
    vector<int> r;        
    for(int j = 0;j<n;j++){
        if(r.size() != 0) ans.push_back(r);
        r.clear();
        for(int i = 0;i<m;i++){
            r.push_back(matrix[i][j]);
        }
    }
    ans.push_back(r);
    return ans;
}


int main(){

    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    vector<vector<int>> ans = transpose(matrix);

    for(auto x : ans){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}