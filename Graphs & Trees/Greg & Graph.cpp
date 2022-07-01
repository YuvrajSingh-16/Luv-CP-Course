#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 510;

lli dist[N][N];

// INPUT
// 4
// 0 3 1 1
// 6 0 400 1
// 2 4 0 1
// 1 1 1 0
// 4 1 2 3


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif


		int n;
		cin>>n;

		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++)
				cin>>dist[i][j];
		}
		
		vector<int> del_order(n);
		for(int i=0; i<n; i++){
			cin>>del_order[i];
		}

		reverse(del_order.begin(), del_order.end());

		vector<lli> ans(n);
		for(int k=0; k<n; k++){ // Floyd Warshall
			int kv = del_order[k];
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					lli new_dist = dist[i][kv] + dist[kv][j];
					dist[i][j] = min(dist[i][j], new_dist);
				}
			}

			lli sum=0;
			for(int i=0; i<=k; i++){
				for(int j=0; j<=k; j++){
					sum += dist[del_order[i]][del_order[j]];	
				}
			}ans[k]=sum;
		}

		reverse(ans.begin(), ans.end());

		for(int i=0; i<n; i++){
			cout<<ans[i]<<"\n";
		}


	return 0;
}