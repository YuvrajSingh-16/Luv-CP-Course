#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int, int>> graph[N];
vector<int> level(N, INF);


int bfs(int n){
	deque<int> q;
	q.push_back(1);
	level[1] = 0;

	while(!q.empty()){ 
		int curr_v = q.front();
		q.pop_front();

		for(auto child: graph[curr_v]){ 
			int child_v = child.first;
			int wt = child.second;

			if(level[curr_v]+wt < level[child_v]){ // If shorter path than last visited path exists,
				level[child_v] = level[curr_v]+wt; // which is known by checking if level of curr node 
				if(wt==1)						 // adding with wt(0 or 1) greater or equal to level of child node
					q.push_back(child_v);
				else 
					q.push_front(child_v);
			}
		}
	}

	return level[n] == INF ? -1 : level[n]; // level[n] is ans because level is only increased if reverse edge is used
}

// // Input
// 7 7
// 1 2 
// 3 2
// 3 4
// 7 4
// 6 2
// 5 6
// 7 5


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int n, m;
		cin>>n>>m;


		for(int i=0; i<m; i++){
			int v1, v2;
			cin>>v1>>v2;

			if(v1==v2) continue;

			graph[v1].push_back({v2, 0});
			graph[v2].push_back({v1, 1});
		}

		cout<<bfs(n)<<"\n";

	return 0;
}