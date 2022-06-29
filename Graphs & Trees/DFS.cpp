#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;

vector<int> graph[N];
bool vis[N];


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

void dfs(int vertex){
	/**
	* Take action on vertex after entering the vertex
	**/ 
	cout<<vertex<<endl;
	vis[vertex] = true;
	for(int child: graph[vertex]){
		cout<<"Parent: "<<vertex<<", Child: "<<child<<endl;
		if(vis[child]) continue;
		/**
		 * Take action on child before entering the child node
		 **/
		
		dfs(child);
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