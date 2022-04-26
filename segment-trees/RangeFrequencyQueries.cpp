// 2080. Range Frequency Queries

/*
	Input
	["RangeFreqQuery", "query", "query"]
	[[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]
	Output
	[null, 1, 2]

	Explanation
	RangeFreqQuery rangeFreqQuery = new RangeFreqQuery([12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]);
	rangeFreqQuery.query(1, 2, 4); // return 1. The value 4 occurs 1 time in the subarray [33, 4]
	rangeFreqQuery.query(0, 11, 33); // return 2. The value 33 occurs 2 times in the whole array.
*/

#include<bits/stdc++.h>
using namespace std;

void build(int ind,int low,int high,int arr[],unordered_map<int,int> seg[]){
	if(low == high){
		seg[ind][arr[low]]++;
		return;
	}

	int mid = (low + high) / 2;

	// Recursively build for left and right subtree.
	build(2*ind+1,low,mid,arr,seg);
	build(2*ind+2,mid+1,high,arr,seg);


	unordered_map<int,int> map;

	for(auto it = seg[2*ind+1].begin();it!=seg[2*ind+1].end();it++){
		map[it->first] += it->second;
	}

	for(auto it = seg[2*ind+2].begin();it!=seg[2*ind+2].end();it++){
		map[it->first] += it->second;
	}

	// Merging the right and left subtree solutions.
	seg[ind] = map;
}

int queryH(int ind, int low, int high, int l, int r, int value, unordered_map<int,int> seg[]){
	// No overlap
	// [l r] [low high] or [low high] [l r]
	if(r < low || high < l){
		return 0;
	}

	// Complete overlap
	// [l low high r]

	if(l <= low && high <= r){
		return seg[ind][value];
	}

	// Partial overlap
	int mid = (low + high) / 2;

	int left = queryH(2*ind+1,low,mid,l,r,value,seg);
	int right = queryH(2*ind+2,mid+1,high,l,r,value,seg);


	return left + right;
 }

int main(){
	int n;
	cin>>n;

	int arr[n] = {3,4,5,3,3,2,2,2,5,4};

	// for(int i = 0;i<n;i++) cin>>arr[i];

	// Every node is segment tree keeps a hashmap of count of array items for the given range.
	// Because max nodes or indexes in segment tree can be 4*n [There is a proof for that].
	unordered_map<int,int> seg[4*n];

	build(0,0,n-1,arr,seg);

	cout<<queryH(0,0,n-1,2,6,3,seg)<<endl;
	cout<<queryH(0,0,n-1,5,6,5,seg)<<endl;
	cout<<queryH(0,0,n-1,1,6,2,seg)<<endl;
	cout<<queryH(0,0,n-1,0,2,3,seg)<<endl;
	cout<<queryH(0,0,n-1,5,6,4,seg)<<endl;

	return 0;
}