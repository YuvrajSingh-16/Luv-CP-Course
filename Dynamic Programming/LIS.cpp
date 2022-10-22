#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;

int dp[N];


// Longest increasing subsequence
int LongestIncSubs(vector<int> &vec, int i){
	if(dp[i] != -1)
		return dp[j];

	int ans = 1;
	for(int j=0; j<i; j++){
		if(vec[j] < vec[i]){
			ans = max(ans, LongestIncSubs(vec, j)+1);
		}
	}

	return dp[i] = ans;
}

// // INPUT
// 8
// 10 9 2 5 3 7 101 18


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
		
		int ans=0;
		for(int i=0; i<n; i++){
			int tmp = LongestIncSubs(vec, i);
			cout<<i<<" "<<tmp<<endl;
			ans = max(ans, tmp);
		}

		cout<<ans<<endl;

	cout<<"\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}