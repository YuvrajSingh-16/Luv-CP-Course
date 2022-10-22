#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;
vector<int> graph[N];

int subtree_sum[N];
int even_ct[N];


/** Given Q Queries, Q <= 10^5
 * In each query given V,
 * Print subtree sum of V & Number of even numbers
 * in subtree of V
**/


// // Input
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

	if(vertex % 2 == 0)
		even_ct[vertex]++;

	subtree_sum[vertex] += vertex;
	for(int child: graph[vertex]){
		if(child == parent) continue;
		/**
		 * Take action on child before entering the child node
		 **/

		dfs(child, vertex);
		subtree_sum[vertex] += subtree_sum[child];
		even_ct[vertex] += even_ct[child];

		/** 
		 * Take action on child after exiting the child node
		 **/
	}
	/** 
	 * Take action on vertex before exiting the vertex
	 **/
}
// TC: O(V+2*E)


void dfs(int vertex, int parent){
	if(vertex%2 == 0)
		even_cnt[vertex]++;

	subtree_sum[vertex] += vertex;

	for(int child: graph[vertex]){
		if(child == parent)
			continue;

		dfs(child, vertex);
		subtree_sum[child] += subtree_sum[child];
		even_ct[vertex] += even_ct[child];
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
			cout<<subtree_sum[i]<<" "<<even_ct[i]<<endl;
		}

		// 	int q;
		// cin>>q;

		// while(q--){
		// 	int v;
		// 	cin>>v;
		// 	cout<<subtree_sum[v]<<" "<<even_ct[v]<<endl;
		// }

	return 0;
}