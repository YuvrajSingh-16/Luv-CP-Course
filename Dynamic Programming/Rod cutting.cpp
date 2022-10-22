#include<bits/stdc++.h>

using namespace std;
#define lli long long int

int dp[1010];

// Unbound Knapsack
int rodCutting(vector<int> &prices, int len){
	if(len==0)
		return 0;

	if(dp[len] != -1)
		return dp[len];

	int ans = 0;
	for(int len_to_cut=1; len_to_cut<=prices.size(); len_to_cut++){
		if(len-len_to_cut >= 0)
			ans = max(ans, rodCutting(prices, len-len_to_cut) + prices[len_to_cut-1]);
	}
	return dp[len]=ans;
}
// O(n^2)

int cutRod(int price[], int n){
	vector<int> prices(price, price+n);
	memset(dp, -1, sizeof(dp));
	
	return rodCutting(prices, n);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		

	cout<<"\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}