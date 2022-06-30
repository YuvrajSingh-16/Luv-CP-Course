#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;
vector<int> graph[N];

int depth[N];


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

void dfs(int vertex, int parent=0){
	/**
	* Take action on vertex after entering the vertex
	**/ 
	for(int child: graph[vertex]){
		if(child == parent) continue;
		/**
		 * Take action on child before entering the child node
		 **/
		depth[child] = depth[vertex]+1;
		dfs(child, vertex);
		/** 
		 * Take action on child after exiting the child node
		 **/
	}
	/** 
	 * Take action on vertex before exiting the vertex
	 **/
}
// TC: O(V+2*E)


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

		int mx_depth = -1;
		int mx_d_node;
		for(int i=1; i<=n; i++){
			if(mx_depth < depth[i]){
				mx_depth = depth[i];
				mx_d_node = i; 
			}
			depth[i] = 0;
		}

		dfs(mx_d_node);
		mx_depth = -1;
		for(int i=1; i<=n; i++){
			if(mx_depth < depth[i])
				mx_depth = depth[i];
		}

		cout<<mx_depth<<endl;

	return 0;
}