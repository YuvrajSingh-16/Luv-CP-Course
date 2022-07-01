#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;

int parent[N];
int size[N];

// Disjoint Set Union -> more at https://cp-algorithms.com/data_structures/disjoint_set_union.html

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


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int n, k;
		cin>>n>>k;

		for(int i=1; i<=n; i++){
			make(i);
		}

		while(k--){
			int u, v;
			cin>>u>>v;
			Union_sets(u, v);
		}

		int connected_cmp_cnt=0;
		for(int i=1; i<=n; i++){
			if(find(v) == v) connected_cmp_cnt++;
		}

		cout<<connected_cmp_cnt<<endl;

	// cout << "\n\n";
	// cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}