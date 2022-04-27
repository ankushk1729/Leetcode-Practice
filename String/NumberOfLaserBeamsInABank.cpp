// 2125. Number of Laser Beams in a Bank
	
/*
	Input: bank = ["011001","000000","010100","001000"]
	Output: 8
	Explanation: Between each of the following device pairs, there is one beam. In total, there are 8 beams:
	 * bank[0][1] -- bank[2][1]
	 * bank[0][1] -- bank[2][3]
	 * bank[0][2] -- bank[2][1]
	 * bank[0][2] -- bank[2][3]
	 * bank[0][5] -- bank[2][1]
	 * bank[0][5] -- bank[2][3]
	 * bank[2][1] -- bank[3][2]
	 * bank[2][3] -- bank[3][2]
	Note that there is no beam between any device on the 0th row with any on the 3rd row.
	This is because the 2nd row contains security devices, which breaks the second condition.
*/	

#include<bits/stdc++.h>
using namespace std;

  int numberOfBeams(vector<string>& bank) {
        int cnt = 0;
        int m = bank.size();
        int n = bank[0].size();
        int prev = 0;
        bool flag = false;
        
        for(int i = 0;i<m;i++){
            int curr = 0;
            flag = false;
            for(int j = 0;j<n;j++){
                if(bank[i][j] == '1'){
                    cnt += prev;
                    curr++;
                    flag = true;
                }
            }
            if(flag) prev = curr;
            
        }
        return cnt;
   }


int main(){

	vector<string> bank = {"011001","000000","010100","001000"};

	cout<<numberOfBeams(bank);
	return 0;
}