#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;

vector<int> graph[N];
bool vis[N];
int level[N];


void bfs(int source){
	queue<int> q;
	q.push(source);
	vis[source] = 1;

	while(!q.empty()){ // V times
		int curr_v = q.front();
		q.pop();
		cout<<curr_v<<" ";

		for(int child: graph[curr_v]){ // Total E times over all the vertex
			if(!vis[child]){
				q.push(child);
				vis[child]=1;
				level[child] = level[curr_v]+1; 
			}
		}
	}cout<<"\n";

	// v1 - e1, v2 - e2, e1 + e2 + e3 +... en
	// TC:- O(V+2E) - BFS
}

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


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int n;
		cin>>n;

		for(int i=0; i<n; i++){
			int v1, v2;
			cin>>v1>>v2;

			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}
		
		cout<<"BFS: ";
		bfs(1);

		cout<<"Levels:- \n";
		for(int i=1; i<=n; i++){
			cout<<i<<": "<<level[i]<<"\n";		
		}

	return 0;
}