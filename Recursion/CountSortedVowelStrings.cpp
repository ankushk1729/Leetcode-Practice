// 1641. Count Sorted Vowel Strings


/*
	Input: n = 2
	Output: 15
	Explanation: The 15 sorted strings that consist of vowels only are
	["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
	Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.

*/

#include <bits/stdc++.h>
using namespace std;


    void solve(int n,int ind,int& count){
        if(n == 0){
            count++;
            return;
        }
        for(int i = 0;i<5;i++){
            if(i >= ind){
                solve(n-1,i,count);
            }
        }
    }
    int countVowelStrings(int n) {
        int count = 0;
        solve(n,0,count);
        return count;
    }

int main(){

	int n = 33;
	cout<<countVowelStrings(n);

	return 0;
}