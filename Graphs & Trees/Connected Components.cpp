#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;

vector<int> graph[N];
bool vis[N];

// Connected components
vector<vector<int>> cc;
vector<int> current_cc;

// // Input
// 8 5
// 1 2
// 2 3
// 2 4
// 3 5
// 6 7


void dfs(int vertex){
	/**
	* Take action on vertex after entering the vertex
	**/ 
	vis[vertex] = true;
	current_cc.push_back(vertex);

	for(int child: graph[vertex]){
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

		// Nodes & Edges
		int n,e;
		cin>>n>>e;

		for(int i=0; i<e; i++){
			int v1, v2;
			cin>>v1>>v2;

			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}

		int ct = 0;
		for(int i=1; i<=n; i++){
			if(vis[i]) continue;
			current_cc.clear();
			dfs(i);
			cc.push_back(current_cc);
			ct++;
		}

		for(int i=1; i<=n; i++){
			cout<<i<<" : ";
			for(int child: graph[i])
				cout<<child<<" ";
			cout<<"\n";
		}
		cout<<"\n";

		cout<<"Connected Components: "<<cc.size()<<endl;

		for(auto component: cc){
			for(int i: component)
				cout<<i<<" ";
			cout<<"\n";
		}

	return 0;
}