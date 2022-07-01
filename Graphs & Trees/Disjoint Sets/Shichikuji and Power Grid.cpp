#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 2e3+10;

int parent[N];
int size[N];

void make_set(int v){
	parent[v] = v;
	size[v] = 1;
}

int find_set(int v){
	if(parent[v] == v)
		return v;
	// Path compression
	return parent[v] = find_set(parent[v]);
}

void Union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);

	if(a!=b){
		// Union by size
		if(size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}

// Problem link :- https://codeforces.com/contest/1245/problem/D

// // Input1
// 3
// 2 3
// 1 1
// 3 2
// 3 2 3
// 3 2 3


// // Input2
// 3
// 2 1
// 1 2
// 3 3
// 23 2 23
// 3 2 3


// Minimum Spanning Tree
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int n;
		cin>>n;

		vector<pair<int, int>> cities(n+1);
		for(int i=1; i<=n; i++){
			int x, y;
			cin>>x>>y;
			cities[i] = {x, y};
		}

		vector<int> gCost(n+1); // Generator cost
		for(int i=1; i<=n; i++){
			cin>>gCost[i];
		}

		vector<int> wCost(n+1); // Wire cost
		for(int i=1; i<=n; i++){
			cin>>wCost[i];
		}

		vector<pair<long long, pair<int, int>>> edges; // Graph with all cities connected

		//// Creating fully connected graph

		// Let generator be at 0 node and all cities connected with it
		for(int i=1; i<=n; i++){
			edges.push_back({gCost[i], {0, i}});
		}

		// Calculating distance and cost of wire btw cities
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				int dist = abs(cities[i].first-cities[j].first) + abs(cities[i].second-cities[j].second);
				long long cost = dist * 1LL * (wCost[i]+wCost[j]);
				edges.push_back({cost, {i, j}});
			}
		}


		// Kruskal Algo
		sort(edges.begin(), edges.end());

		for(int i=1; i<=n; i++) make_set(i);

		vector<int> power_stations;
		vector<pair<int, int>> connections;
		lli total_cost=0;

		for(auto &edge: edges){
			int wt = edge.first;
			int u = edge.second.first;
			int v = edge.second.second;

			if(find_set(u) == find_set(v)) continue; // If there exist connection

			Union_sets(u, v);
			total_cost += wt;
			if(u == 0 || v == 0)
				power_stations.push_back(max(u, v));
			else
				connections.push_back({u, v});
		}

		cout<<total_cost<<endl;
		cout<<power_stations.size()<<endl;
		for(int station: power_stations)
			cout<<station<<" ";
		cout<<endl;

		cout<<connections.size()<<endl;
		for(auto &connection: connections){
			cout<<connection.first<<" "<<connection.second<<"\n";
		}

	return 0;
}

