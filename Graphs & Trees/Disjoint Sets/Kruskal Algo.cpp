#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;

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

vector<pair<int, pair<int, int>>> edges;


// Minimum Spanning Tree

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int n, m;
		cin>>n>>m;

		for(int i=0; i<m; i++){ // edges
			int u, v, wt;
			cin>>u>>v>>wt;

			edges.push_back({wt, {u, v}});
		}

		sort(edges.begin(), edges.end());

		for(int i=1; i<=n; i++) make_set(i);

		int total_cost=0;
		for(auto &edge: edges){
			int wt = edge.first;
			int u = edge.second.first;
			int v = edge.second.second;

			if(find_set(u) == find_set(v)) continue;

			Union_sets(u, v);
			total_cost += wt;
			cout<<u<<" "<<v<<", wt: "<<wt<<"\n";
		}

		cout<<total_cost<<endl;


	cout << "\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}