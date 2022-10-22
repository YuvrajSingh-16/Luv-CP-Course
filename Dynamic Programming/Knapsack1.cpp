#include<bits/stdc++.h>

using namespace std;
#define lli long long int

lli dp[110][100010];

int w[110];
int v[110];

// 0/1 Knapsack
lli knapsack1(int idx, int w_lft){
	if(w_lft == 0)
		return 0;

	if(idx<0)
		return 0;

	if(dp[idx][w_lft] != -1)
		return dp[idx][w_lft];
	
	lli ans = knapsack1(idx-1, w_lft);

	if(w_lft-w[idx]>=0)
		ans = max(ans, knapsack1(idx-1, w_lft-w[idx])+v[idx]+0LL);

	return dp[idx][w_lft] = ans;
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
		
		cout<<knapsack1(n-1, wt);
		
	cout<<"\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}