#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e6+10;

int hp[N];
int canRemove[N]; // canRemove[i] -> if i can be removed - 1 else 0 
				// (if i is present in input array or it's power is present)
int hsh[N];

vector<int> distinctPF(int x){
	vector<int> ans;

	while(x>1){
		int pf = hp[x];
		while(x%pf==0){
			x/=pf;
		} 
		ans.push_back(pf);
	}

	return ans;
}

// Hacker Decrypting Messages:
//
// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/


// // Concepts used
// - Highest Prime
// - Prime factorization
// - Seive

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		// Calculating highest prime factor of a numbers till 1000010
		for(int i=2; i<N; i++){
			if(hp[i] == 0){
				for(int j=i; j<N; j+=i){
					hp[j] = i;
				}
			}
		}

		int n, q; 
		cin>>n>>q;

		// Storing array elements count
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			hsh[x]++;
		}


		// Marking all the array elements and their powers as 1
		for(int i=2; i<N; i++){
			if(hsh[i]){
				for(long long j=i; j<N; j*=i){
					canRemove[j] = 1;
				}
			}
		}


		// Queries
		while(q--){
			int x;
			cin>>x;

			vector<int> pf = distinctPF(x); // Distinct prime factors
			bool isPossible = false;

			for(int i=0; i<pf.size(); i++){
				for(int j=i; j<pf.size(); j++){
					int prod = pf[i]*pf[j];
					if(i==j && (x%prod) != 0) continue; // if same element's multiple cannot divide x

					int toRemove = x/prod;
					if(canRemove[toRemove] == 1 || toRemove == 1){ // if remaining factor(s) can be removed from x i.e, present in array
						isPossible = true;
						break;
					}
				}
				if(isPossible) break;
			}
			cout<<(isPossible? "YES\n": "NO\n");
		}
		

	cout << "\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}