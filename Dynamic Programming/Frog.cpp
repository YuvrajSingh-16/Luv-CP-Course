#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;

int dp[N];
int h[N];


// TOP DOWN
int fun(int n){
	if(n==0)
		return 0;
	if(dp[n] != -1)
		return dp[n];

	int cost = INT_MAX;
	
	cost = min(cost, fun(n-1) + abs(h[n]-h[n-1]));
	if(n>1)
		cost = min(cost, fun(n-2) + abs(h[n]-h[n-2]));

	dp[n] = cost;

	return cost;
}
// O(2^n) -> TC


// Frog1
int minCost(vector<int> stones, int i, vector<int>& DP){
	if(i==0)
      return 0;

  	if(DP[i] != -1)
  		return DP[i];

  	int cst = INT_MAX;
  	cst = min(cst, minCost(stones, i-1, DP)+abs(stones[i]-stones[i-1]));
  	if(i>1)
  		cst = min(cst, minCost(stones, i-2, DP)+abs(stones[i]-stones[i-2]));

  	return DP[i] = cst;
}

// Frog2
int minCost2(vector<int> stones, int i, int k, vector<int>& DP){
	if(i==0)
      return 0;

  	if(DP[i] != -1)
  		return DP[i];

  	int cst = INT_MAX;

  	for(int j=1; j<=k; j++){
  		if(i-j>=0)
  			cst = min(cst, minCost2(stones, i-j, k, DP)+abs(stones[i]-stones[i-j]));
  	}
  	return DP[i] = cst;
}


int frog2(int n, int k){
	if(n==0)
		return 0;

	if(dp[n] != -1)
		return dp[n];

	int cost = INT_MAX;

	for(int i=1; i<=k; i++){
		if(n+1>i)
			cost = min(cost, frog2(n-i, k)+abs(h[n]-h[n-i]));
	}

	return dp[n] = cost;
}
// O(k*2^n) -> TC

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		memset(dp, -1, sizeof(dp));

		int n, k;
		cin>>n>>k;

		vector<int> stones(n);
		for(int i=0; i<n; i++){
			cin>>stones[i];
		}

		// cout<<frog2(n-1, k);
		vector<int> DP(n, -1);
		cout<<minCost2(stones, n-1, k, DP);
		// cout<<fun(n-1)<<endl;

		cout<<endl;
		for(int i: DP)
			cout<<i<<" ";

		// for(int i=0; i<n; i++)
		// 	cout<<dp[i]<<" ";

	cout<<"\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}