#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e3+10;
const int M = 1000000007;

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


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int n;
		cin>>n;

		for(int i=1; i<=n; i++){
			make_set(i);
		}

		vector<int> risk(n);
		for(int i=0; i<n; i++){
			cin>>risk[i];
		}

		int k;
		cin>>k;

		while(k--){
			int u, v;
			cin>>u>>v;
			Union_sets(u, v); // Connecting cities
		}

		unordered_map<int, unordered_map<int, int>> mp;
		for(int i=0; i<n; i++){
			mp[find_set(i+1)][risk[i]]++; // storing all the risks(weights) associated with the given city i+1;
		}

		vector<pair<int, int>> vec;
		for(auto &m: mp){ // traversing all cities from 1 to n
			pair<int, int> p = {INT_MAX, INT_MAX}; // will store min risk and it's count(repeated times)
			for(auto &pr: m.second){ 
				if(p.first>pr.first){  // if there exist a less risky connection btw cities 
					p = pr;
				}
			} vec.push_back(p); // collect all the min risks to reach all connected cities
		}

		int cnt=1;

		for(auto &v: vec){
			cnt = (cnt%M * v.second%M)%M;
		}

		cout<<cnt<<"\n";
	return 0;
}	