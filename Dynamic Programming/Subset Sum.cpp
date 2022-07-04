#include<bits/stdc++.h>

using namespace std;
#define lli long long int

int dp[205][20010];

bool subsetSum(vector<int>& vec, int idx, int sum){
	if(sum == 0)
		return true;

	if(idx==vec.size())
		return false;

	if(dp[idx][sum] != -1)
		return dp[idx][sum];


	bool ans = subsetSum(vec, idx+1, sum);
	if(sum-vec[idx]>=0)
		ans |= subsetSum(vec, idx+1, sum-vec[idx]);

	return dp[idx][sum] = ans;
}

vector<vector<int>> subsets;
void subsetGenerate(vector<int>& nums, int idx, vector<int>& subset){
	if(idx == nums.size()){
		subsets.push_back(subset);
		return;
	}

	subsetGenerate(nums, idx+1, subset);

	subset.push_back(nums[idx]);
	subsetGenerate(nums, idx+1, subset);
	subset.pop_back();
}


bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int num: nums)
        sum += num;
    
    if(sum%2)
        return false;
    
    memset(dp, -1, sizeof(dp));
    return subsetSum(nums, 0, sum/2);
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		memset(dp, -1, sizeof(dp));

		int n; 
		cin>>n;

		vector<int> vec(n);
		for(int i=0; i<n; i++){
			cin>>vec[i];
		}

		cout<<subsetSum(vec, 0, 11);
		// vector<int> subset;
		// subsetGenerate(vec, 0, subset);

		// for(auto &subset: subsets){
		// 	int sum = 0;
		// 	for(int &val: subset)
		// 		cout<<val<<" ", sum+=val;
		// 	cout<<": "<<sum<<"\n";
		// }

		
	cout<<"\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}