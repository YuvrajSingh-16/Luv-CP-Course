#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;

int dp[N];


// TOP DOWN
// fib(n) --> nth fib number

// 0 1 1 2 3 5 8 13 21 34 56 90
int fib(int n){
	if(n==0) return 0;
	if(n==1) return 1;

	if(dp[n] != -1)
		return dp[n];

	return dp[n] = fib(n-1)+fib(n-2);
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		memset(dp, -1, sizeof(dp));

		int n;
		cin>>n;

		cout<<fib(n);

		
	cout<<"\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}