#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;
vector<int> graph[N];

int depth[N];
int height[N];

// // Input
// 6 9 
// 1 3 
// 1 5 
// 3 5 
// 3 4 
// 3 6 
// 3 2 
// 2 6 
// 4 6 
// 5 6 

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
		height[vertex] = max(height[vertex], height[child]+1);
		/** 
		 * Take action on child after exiting the child node
		 **/
	}
	/** 
	 * Take action on vertex before exiting the vertex
	 **/
}
// TC: O(V+2*E)


void tree_dfs(int vertex, int parent){

	for(int child: graph[vertex]){
		if(child == parent) continue;

		depth[child] = depth[vertex]+1;
		tree_dfs(child, vertex);
		height[vertex] = max(height[vertext], height[child]+1);
	}
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

		for(int i=1; i<=n; i++){
			cout<<depth[i]<<" "<<height[i]<<endl;
		}

	return 0;
}