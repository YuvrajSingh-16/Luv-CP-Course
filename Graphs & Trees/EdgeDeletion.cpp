#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;
const int M = 1e9+7;

vector<int> graph[N];

int subtree_sum[N];
int val[N];


// Problem Description

// Given a undirected tree with N nodes labeled  from 1 to N.
// Each node has a certain weight assigned to it given by an integer array A of size N.
// You need to delete an edge in such a way that Product between sum of weight of nodes in one subtree with sum of weight of nodes in other subtree is maximized.
// Return this maximum possible product modulo 109 + 7.

// NOTE:
// The tree is rooted at node labeled with 1.


// Problem Constraints
// 2 <= N <= 105
// 1 <= A[i] <= 103



// Input Format
// First argument is an integer array A of size N denoting the weight of each node.
// Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.


// Output Format
// Return a single integer denoting the maximum product prossible of sum of weights of nodes in the two subtrees formed by deleting an edge with modulo 109 + 7.



//// Delete Edge Soln [InterviewBit]
// void dfs(int vertex, int parent, vector<int> graph[], vector<int>& subtree_sum, vector<int>& val){
// 	subtree_sum[vertex] += val[vertex-1];

// 	for(int child: graph[vertex]){
// 		if(child == parent) 
//             continue;
// 		dfs(child, vertex, graph, subtree_sum, val);
// 		subtree_sum[vertex] += subtree_sum[child];
// 	}
// }

// int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
//     vector<int> graph[A.size()+1];
//     vector<int> subtree_sum(A.size()+1, 0);
    
//     for(auto edge: B){
// 			graph[edge[0]].push_back(edge[1]);
// 			graph[edge[1]].push_back(edge[0]);
// 		}
    
//     dfs(1, 0, graph, subtree_sum, A);

//     long long ans = 0;
    
//     for(int i=2; i<=A.size(); i++){
//         int part1 = subtree_sum[i];
//         int part2 = subtree_sum[1] - part1;

//         ans = max(ans, (part1 * 1LL * part2)%M);
//     }
//     return ans;
// }


void dfs(int vertex, int parent=-1){
	subtree_sum[vertex] += val[vertex];

	for(int child: graph[vertex]){
		if(child == parent) continue;
		dfs(child, vertex);
		subtree_sum[vertex] += subtree_sum[child];
	}
}
// TC: O(V+2*E)


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

		long long ans = 0;
		for(int i=2; i<=n; i++){
			int part1 = subtree_sum[i];
			int part2 = subtree_sum[1] - part1;

			ans = max(ans, (part1 * 1LL * part2)%M);
		}
		cout<<ans<<endl;


	return 0;
}