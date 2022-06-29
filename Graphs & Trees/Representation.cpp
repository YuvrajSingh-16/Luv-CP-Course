#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e3+10;
int graph1[N][N];

vector<pair<int, int>> graph2[N];


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int n,m;
		cin>>n>>m;

		for(int i=0; i<m; i++){
			int v1, v2, wt;
			cin>>v1>>v2>>wt;
			graph1[v1][v2] = wt;
			graph1[v2][v1] = wt;

			graph2[v1].push_back({v2, wt});
			graph2[v2].push_back({v1, wt});
		}

		// Adjacency matrix
		// O(N^2) - Space Complexity
		// N != 10^5 / N <=10^3

		// Pros of Adjacency matrix
		// // i, j connected ?, i, j -> wt?
		// if(graph1[i][j] == 1){
		// 	// Connected
		// }


		// Adjacency List
		// O(M + N)
		// N = 10^5 , E < 10^7

		// // i, j connected ?, i, j -> wt?
		// for(pair<int, int> child: graph2){
		// 	if(child.first == j){
		// 		// connected
		// 		child.second // weight
		// 	}
		// }

	return 0;
}