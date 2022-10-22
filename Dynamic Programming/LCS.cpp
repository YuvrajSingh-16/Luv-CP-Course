#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;

int dp[1005][1005];


int lcs(string &str1, string &str2, int i, int j){
	if(i<0 || j<0)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	int ans = lcs(str1, str2, i-1, j);

	ans = max(ans, lcs(str1, str2, i, j-1));

	ans = max(ans, lcs(str1, str2, i-1, j-1));
	ans += (str1[i]==str2[j]);

	return dp[i][j]=ans;
}


int longestCommonSubsequence(string text1, string text2) {
	
	return lcs(text1, text2, text1.size()-1, text2.size()-1);
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

		string str1, str2;
		cin>>str1>>str2;

		cout<<longestCommonSubsequence(str1, str2)<<endl;
		
	cout<<"\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}