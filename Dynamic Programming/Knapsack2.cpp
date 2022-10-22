#include<bits/stdc++.h>

using namespace std;
#define lli long long int

lli dp[110][100010];

int w[110];
int v[110];

// 0/1 Knapsack
lli knapsack2(int idx, int value_lft){
	if(value_lft == 0)
		return 0;

	if(idx<0)
		return 1e18;

	if(dp[idx][value_lft] != -1)
		return dp[idx][value_lft];

	lli ans = knapsack2(idx-1, value_lft);

	if(value_lft - v[idx] >= 0)
		ans = min(ans, knapsack2(idx-1, value_lft-v[idx])+w[idx]);  // Minimizing weight

	return dp[idx][value_lft] = ans;
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		memset(dp, -1, sizeof(dp));

		int n, wt;
		cin>>n>>wt;


		for(int i=0; i<n; i++){
			cin>>w[i]>>v[i];
		}
		
		// Maximizing value
		for(int i=1e5; i>=0; i--){
			if(knapsack2(n-1, i)<=wt){
				cout<<i<<"\n";
				break;
			}
		}
		
	cout<<"\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}