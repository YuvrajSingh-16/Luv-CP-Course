#include<bits/stdc++.h>

using namespace std;
#define lli long long int


int n, m;
int vis[51][51];
int grid[51][51];

int ans = 0;


bool isValid(int x, int y){
    return (x>=0 && y>=0 && x<n && y<m);
}	


int dfs(int i, int j){
	if(!isValid(i, j) || grid[i][j] == 0 || vis[i][j])
		return 0;

	cout<<i<<" "<<j<<"\n";

	vis[i][j] = 1;

	int val = dfs(i+1, j) + dfs(i, j+1) + dfs(i-1, j) + dfs(i, j-1);
	cout<<i<<j<<" val: "<<val<<"\n";

	return 1 + val;
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		cin>>n>>m;

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>grid[i][j];
			}
		}


		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(grid[i][j] == 1 && !vis[i][j])
					ans = max(ans, dfs(i, j));
			}
		}

		cout<<ans<<endl;

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout<<vis[i][j];
			}cout<<"\n";
		}

	return 0;
}