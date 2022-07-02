#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 2e5+10;

int multiples_cnt[N];
int hsh[N];


int gcd(int a, int b){ // TC: O(log n) max
	if(a == 0)
		return b;
	return gcd(b%a, a);
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int n, q; 
		cin>>n;

		// Storing array elements count
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			hsh[x]++;
		}

		cin>>q;

		// Storing number of multiples count for each array element
		for(int i=1; i<N; i++){
			for(int j=i; j<N; j+=i){
				multiples_cnt[i] += hsh[j];
			}
		}

		// for(int i=0; i<=10; i++){
		// 	cout<<i<<" "<<multiples_cnt[i]<<"\n";
		// }

		while(q--){
			int p, q;
			cin>>p>>q;

			lli lcm = p*1LL*q/gcd(p,q);
			lli ans = multiples_cnt[p]+multiples_cnt[q];
			if(lcm < N)      // if lcm is out of range of given number range
				ans -= multiples_cnt[lcm]; // 

			cout<<ans<<"\n";
		}

	cout << "\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}