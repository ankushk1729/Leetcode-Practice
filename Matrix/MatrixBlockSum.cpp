// 1314. Matrix Block Sum


// Not so time optimized solution - O(m^2*n^2)

/*
	Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
	Output: [[12,21,16],[27,45,33],[24,39,28]]
*/


#include<bits/stdc++.h>
using namespace std;

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int sum = 0;
                int leftRow = max(0,i-k);
                int leftCol = max(0,j-k);
                int rightRow = min(i+k,m-1);
                int rightCol = min(j+k,n-1);
                
                
                for(int a = leftRow;a<=rightRow;a++){
                    for(int b = leftCol;b<=rightCol;b++){
                        sum += mat[a][b];
                    }
                }
                ans[i][j] = sum;
            }
        }
        return ans;
    }


int main(){
	vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};

	int k = 1;
	vector<vector<int>> ans = matrixBlockSum(mat,k);

	for(auto x : ans){
		for(auto y : x){
			cout<<y<<" ";
		}
		cout<<endl;
	}

	return 0;
}