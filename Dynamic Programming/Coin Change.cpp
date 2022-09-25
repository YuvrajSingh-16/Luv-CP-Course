#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e4+10;
int dp[N];

int DP[310][5010];

// Coin Change: 1
int func(int amount, vector<int>& coins){
	if(amount == 0)
		return 0;

	if(dp[amount] != -1)
		return dp[amount];

	int ans = INT_MAX;
	for(int coin: coins){
		if(amount-coin >= 0)
			ans = min(ans+0LL, func(amount-coin, coins)+1LL);
	}

	return dp[amount] = ans;
}

// unbound Knapsack
int coinChange2(vector<int>& coins, int amount, int idx){
	if(amount == 0)
		return 1;

	if(idx < 0)
		return 0;

	if(DP[idx][amount] != -1){
		return DP[idx][amount];
	}

	int ways=0;
	for(int coin_amt=0; coin_amt<=amount; coin_amt+=coins[idx]){
		if(amount-coin_amt>=0)
			ways += coinChange2(coins, amount-coin_amt, idx-1);
	}

	return DP[idx][amount] = ways;
}

int coinChange1(vector<int>& coins, int amount, int idx){
	if(amount == 0)
		return 0;

	if(idx < 0)
		return 0;

	if(dp[amount] != -1)
		return dp[amount];

	int ans=INT_MAX;
	for(int coin_amt=0; coin_amt<=amount; coin_amt+=coins[idx]){
		if(amount-coin_amt>=0){
			cout<<idx<<": "<<coin_amt<<" "<<amount<<" ";
			int coin_change = coinChange1(coins, amount-coin_amt, idx-1);
			cout<<coin_change<<"\n";
			ans = min(ans, coin_change+1);
		}
	}

	return dp[amount] = ans;
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		for(int j=0; j<N; j++){
			dp[j] = -1;
		}

		memset(DP, -1, sizeof(DP));

		int n, amount;
		cin>>n>>amount;

		vector<int> vec(n);
		for(int i=0; i<n; i++){
			cin>>vec[i];
		}

		// int ans = func(amount, vec);
		cout<<coinChange1(vec, amount, n-1)<<endl;

		// cout<<coinChange2(vec, amount, n-1)<<endl;
		
	cout<<"\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}