#include<bits/stdc++.h>

using namespace std;
#define lli long long int
const long long M = 2760727302517;

int binExpItr(int a, int b){
	int ans = 1;
	while(b){
		if(1&b) // if odd
			ans = (ans * 1LL * a) % M;
		a = (a * 1LL * a) % M;
		b>>=1;	}

	return ans;
}

// INPUT

// 1
// 3 5
// 1 2 3
// 3
// 1 1 5
// 3
// 2 3 6
// 3

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int t;
		cin>>t;

		while(t--){
			int n, Q;
			cin>>n>>Q;

			int arr[n];
			for(int i=0; i<n; i++) // +10^5
				cin>>arr[i];

			lli sum[n+1] {0};
			for(int i=n-1; i>=0; i--){ // +10^5
				sum[i] = (sum[i+1]+arr[i])%M;
			}

			while(Q--){  // +10^5
				int q;
				cin>>q;

				if(q<3){
					int x, v;
					cin>>x>>v;

					if(q==1)
						arr[x-1]=v;
					else if(q==2)
						arr[x-1]+=v;

					for(int i=n-1; i>=0; i--){ // +10^5
						sum[i] = (sum[i+1]+arr[i])%M;
					}
				}else{
					lli fa=0;

					for(int i=0; i<n; i++){ // +10^5
						fa += ((n-1)*1LL*binExpItr(arr[i], 2))%M;
						fa -= (2*arr[i]*1LL*sum[i+1])%M;
						fa %= M;
					}

					cout<<fa<<"\n";
				}
			}
					// TC -> 6*(10^5+10^5+10^5*(10^5+10^5)) = 10^10
		}

	cout << "\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}