#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int, int>> graph[N];


void dijkstra(int source, vector<pair<int, int>>& graph[N], int n){
	vector<int> vis(N, 0);
	vector<int> dist(N, INF);

	set<pair<int, int>> st;
	st.insert({0, source});
	dist[source] = 0;

	while(st.size() > 0){
		auto node = *st.begin();
		int v = node.second;
		int v_dist = node.first;
		st.erase(st.begin());

		if(vis[v]) continue;
		vis[v]=1;

		for(auto child: graph[v]){
			int child_v = child.first;
			int wt = child.second;

			if(dist[v] + wt < dist[child_v]){ // If shorter path exists
				dist[child_v] = dist[v] + wt;
				st.insert({dist[child_v], child_v});
			}
		}
	}

	int ans = 0;
	for(int i=1; i<=n; i++){
		if(dist[i] == INF)
			return -1;
		ans = max(ans, dist[i]);
	}return ans;
}


int networkDelayTime(vector<vector<int>>& times, int n, int k) {
	vector<pair<int, int>> graph[N];
    for(auto vec: times){
    	graph[vec[0]].push_back({vec[1], vec[2]});
    }
    return dijkstra(k, graph, n);
}


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