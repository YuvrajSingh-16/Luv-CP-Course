#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;

int parent[N];
int size[N];

multiset<int> sizes; // Stores sizes of groups


// Problem link:- https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/

// Disjoint Set Union -> more at https://cp-algorithms.com/data_structures/disjoint_set_union.html

void make_set(int v){
	parent[v] = v;
	size[v] = 1;
	sizes.insert(1);
}

int find_set(int v){
	if(parent[v] == v)
		return v;
	// Path compression
	return parent[v] = find_set(parent[v]);
}

void merge(int a, int b){
	sizes.erase(sizes.find(size[a]));
	sizes.erase(sizes.find(size[b]));

	sizes.insert(size[a]+size[b]);
}

void Union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);

	if(a!=b){
		// Union by size
		if(size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		merge(a, b);
		size[a] += size[b];
	}
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int n, q;
		cin>>n>>q;

		for(int i=1; i<=n; i++){
			make_set(i);
		}

		while(q--){
			int u, v;
			cin>>u>>v;
			Union_sets(u, v);

			if(sizes.size()==1){
				cout<<0<<endl;
			}else{
				int mn = *(sizes.begin());
				int mx = *(--sizes.end());

				cout<< mx-mn <<"\n";
			}
		}



	return 0;
}