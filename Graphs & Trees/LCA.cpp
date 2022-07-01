#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;
vector<int> graph[N];

int Parent[N];


//// Input
// 13
// 1 2
// 1 3
// 1 13
// 2 5
// 3 4
// 5 6
// 5 7
// 5 8
// 8 12
// 4 9
// 4 10
// 10 11

void dfs(int vertex, int parent=-1){
	Parent[vertex] = parent;
	for(int child: graph[vertex]){
		if(child == parent) continue;
		dfs(child, vertex);
	}
}
// TC: O(V+2*E)


vector<int> path(int v){
	vector<int> ans;

	while(v!=-1){
		ans.push_back(v);
		v = Parent[v];
	}

	reverse(ans.begin(), ans.end());
	return ans;
}



int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		// Vertices -> n, Edges -> n-1
		int n;
		cin>>n;

		for(int i=0; i<n-1; i++){
			int v1, v2;
			cin>>v1>>v2;

			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}
		dfs(1);

		int x, y;
		cin>>x>>y;

		vector<int> path_x = path(x);
		vector<int> path_y = path(y);
		int mn_ln = min(path_x.size(), path_y.size());

		int lca=-1;
		for(int i=0; i<mn_ln; i++){
			if(path_x[i] == path_y[i]){
				lca = path_x[i];
			}else{
				break;
			}
		}
		cout<<lca<<endl;

	return 0;
}