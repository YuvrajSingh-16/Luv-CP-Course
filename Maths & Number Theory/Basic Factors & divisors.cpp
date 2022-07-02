#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;
const int M = 1e9+7;

vector<bool> isPrime(N, 1);
vector<int> lp(N, 0), hp(N, 0); // Lowest and highest prime

vector<int> divisors[N];


void seive(){  // N * log(log(N))
	isPrime[0] = isPrime[1] = false;

	for(int i=2; i<N; i++){
		if(isPrime[i]){
			lp[i] = hp[i] = i;  // highest and lowest primes 
			for(int j=i*2; j<N; j+=i){
				isPrime[j]=false;
				hp[j]=i;
				if(lp[j] == 0)
					lp[j]=i;
			}
		}
	}
}


void seiveDivisors(){
	for(int i=2; i<N; i++){
		for(int j=i; j<N; j+=i){
			divisors[j].push_back(i);
		}
	}
}


// If values of a and M are large
int binMultiply(int a, int b){
	int ans = 0;
	while(b){
		if(1&b) // if odd
			ans = (ans + a) % M;
		a = (a + a) % M;
		b>>=1;
	}return ans;
}


int binExpItr(int a, int b){ // O(log^2(N))
	int ans = 1;
	while(b){
		if(1&b) // if odd
			ans = binMultiply(ans, a);
		a = binMultiply(a, a);
		b>>=1;
		// b/=2;
	}
	return ans;
}




int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

 		// Count and sum of factors of a number
			// int n;
			// cin>>n;

			// int sum=0, cnt=0;	

			// for(int i=1; i*i<=n; i++){
			// 	if(n%i==0){
			// 		cout<<n/i<<" "<<i<<"\n";

			// 		sum+=i;
			// 		cnt++;
			// 		if(i != n/i){
			// 			sum+=n/i;
			// 			cnt++;
			// 		}
			// 	}
			// }
			// cout<<"Count: "<<cnt<<" Sum: "<<sum<<"\n";


		// Prime factorisation 
			// int n;
			// cin>>n;

			// vector<int> prime_factors;
			// for(int i=2; i*i <= n; i++){ // O(sqrt(N))
			// 	while(n%i == 0){
			// 		prime_factors.push_back(i);
			// 		n/=i;
			// 	}
			// }
			// if(n>1)
			// 	prime_factors.push_back(n);

			// for(int pf: prime_factors){
			// 	cout<<pf<<" ";
			// }


		// Prime factorisation using Seive

			// seive();

			// for(int i=1; i<=100; i++){
			// 	cout<<lp[i]<<" "<<hp[i]<<endl;
			// }

			// int num;
			// cin>>num;
			// // vector<int> prime_factors;
			// map<int, int> prime_factors;

			// while(num > 1){
			// 	int prime_factor = hp[num];
			// 	while(num % prime_factor == 0){
			// 		num /= prime_factor;
			// 		// prime_factors.push_back(prime_factor);
			// 		prime_factors[prime_factor]++;
			// 	}
			// }

			// for(auto factor: prime_factors){
			// 	// cout<<factor<<" ";
			// 	cout<<factor.first<<"^"<<factor.second<<endl;
			// }


		// seiveDivisors();
		// for(int i=1; i<10; i++){
		// 	cout<<i<<": ";
		// 	for(int divisor: divisors[i]){
		// 		cout<<divisor<<" ";
		// 	}cout<<"\n";
		// }


		// Modular Multiplicative Inverse

		// There are N children and K toffees K<N 
		// Count the number of ways to distribute toffee among N students
		// such that each students get 1 toffe only --> nCk
		// N < 10^6, k<N<10^6
		// Q < 10^5
		// n! / ((n-r)! * r!)


		const int N = 1e6+10;
		int fact[N];

		fact[0] = 1;
		for(int i=1; i<N; i++){
			fact[i] = (fact[i-1] * 1LL * i)%M;
		}

		// int q;
		// cin>>q;
		// while(q--){
		// 	int n, k;
		// 	cin>>n>>k;

		// 	int ans = fact[n];
		// 	int den = (fact[n-r] * 1LL * fact[r]) % M;
		// 	ans = ans * binExp(den, M-2); // Calculating inverse using Binary Exponentiation
		// 	cout<<ans<<endl;
		// }


		// HackerEarth - Unlock the door

		// ans -> n! * kCn
		//  n! * k!/((k-n)! * n!)
		int t;
		cin>>t;

		while(t--){
			int n, k;
			cin>>n>>k;

			int ans = (fact[n] * 1LL * fact[k])%M;
			int den = (fact[k-n]*1LL*fact[n])%M;
			ans = (ans *1LL* binExpItr(den, M-2))%M;
			cout<<ans<<endl;
		}


	cout << "\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}