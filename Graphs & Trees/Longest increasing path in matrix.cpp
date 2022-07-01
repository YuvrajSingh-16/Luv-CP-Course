#include<bits/stdc++.h>

using namespace std;
#define lli long long int

int n = 0;

int longIncPath(vector<vector<int>>& matrix, int i, int j,  vector<vector<int>>& dp, int prev){
    if(i<0 || j<0 || i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] <= prev)
        return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];


    int d1 = longIncPath(matrix, i-1, j, dp, matrix[i][j]);
    int d2 = longIncPath(matrix, i+1, j, dp, matrix[i][j]);
    int d3 = longIncPath(matrix, i, j-1, dp, matrix[i][j]);
    int d4 = longIncPath(matrix, i, j+1, dp, matrix[i][j]);

    n = max(n, 1+max(max(d1, d2), max(d3, d4)));
    dp[i][j] = 1+max(max(d1, d2), max(d3, d4));
    return dp[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    vector<vector<int>> dp=matrix;

    for(auto &row: dp){
        for(auto &v: row)
            v = -1;
    }

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            longIncPath(matrix, i, j, dp, -1);
        }
    }

    return n;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int n,m;
		cin>>n>>m;

		for(int i=0; i<m; i++){
			int v1, v2;
			cin>>v1>>v2;

			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}

		for(int i=1; i<=n; i++){
			cout<<i<<": ";
			for(int child: graph[i])
				cout<<child<<" ";
			cout<<endl;
		}
		dfs(1);

	return 0;
}