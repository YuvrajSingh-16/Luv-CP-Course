#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;

vector<int> graph[N];
bool vis[N];


bool dfs(int vertex, int parent){
	/**
	* Take action on vertex after entering the vertex
	**/ 
	vis[vertex] = true;
	bool isLoopDetected = false;

	for(int child: graph[vertex]){
		if(vis[child] && child == parent ) continue;
		if(vis[child]) return true;
		/**
		 * Take action on child before entering the child node
		 **/

		isLoopDetected |= dfs(child, vertex);
		/** 
		 * Take action on child after exiting the child node
		 **/
	}
	/** 
	 * Take action on vertex before exiting the vertex
	 **/

	return isLoopDetected;
}
// TC: O(V+2*E)


bool loopDetect(int vertex, int parent){
	vis[vertex] = true;
	bool isLoopDetected = false;

	for(int child: graph[vertex]){
		if(vis[child] && parent == child) continue;
		if(vis[child])
			return true;

		isLoopDetected |= dfs(child, vertext);
	}

	return isLoopDetected;
}


// // Input
// 8 7
// 1 2
// 2 3
// 2 4
// 3 5
// 6 7
// 1 5
// 3 4


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		// Nodes & Edges
		int n,e;
		cin>>n>>e;

		for(int i=0; i<e; i++){
			int v1, v2;
			cin>>v1>>v2;

			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}

		bool isLoopDetected = false;
		for(int i=1; i<=n; i++){
			if(vis[i]) continue;
			if(dfs(i, 0)){
				isLoopDetected = true;
				break;
			}
		}

		cout<<(isLoopDetected? "Loop Detected!!\n": "No Loop detected\n")<<endl;

		for(int i=1; i<=n; i++){
			cout<<i<<" : ";
			for(int child: graph[i])
				cout<<child<<" ";
			cout<<"\n";
		}


	return 0;
}