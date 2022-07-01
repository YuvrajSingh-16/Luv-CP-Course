#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e3+10;
const int INF = 1e9+10;


int n, m;

int vis[N][N];
int grid[N][N];
int level[N][N];


vector<pair<int, int>> movements = {
	{0, 1}, {0, -1}, {1, 0}, {-1, 0},
	{1, 1}, {-1, 1}, {1, -1}, {-1, -1}
};


bool isValid(int x, int y){
	return (x >= 0 && y >= 0 && x < n && y < m);
}


int bfs(){
	int mx=0;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			mx = max(mx, grid[i][j]);
		}
	}

	queue<pair<int, int>> q;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j]==mx){
				q.push({i, j});
				level[i][j]=0;
				vis[i][j]=1;
			}
		}
	}

	int ans = 0;

	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();

		int x = p.first, y = p.second;

		for(auto movement: movements){
			int childX = x + movement.first;
			int childY = y + movement.second;

			if(!isValid(childX, childY)) continue;
			if(vis[childX][childY]) continue;
			
			q.push({childX, childY});
			level[childX][childY] = level[x][y]+1;
			vis[childX][childY] = 1;
			ans = max(ans, level[childX][childY]);
		}
	} return ans;
}

void reset(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			vis[i][j]=0;
			level[i][j]=INF;
		}
	}
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int t;
		cin>>t;

		while(t--){
			cin>>n>>m;
			reset();

			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					cin>>grid[i][j];
				}
			}

			cout<<bfs()<<"\n";
		}


	return 0;
}