#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e3+10;
int a[N];
int pf[N];

lli pre[N][N];
int arr[N][N];

const int NN = 1e5+10;
int hsh[NN][26];


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		// int t;
		// cin>>t;
		// while(t--){
		// 	int n; 
		// 	cin>>n;
		// 	long long fact = 1;
		// 	for(int i=2; i<=n; i++)
		// 		fact = (fact*i) % M;
		// 	cout<<fact<<endl;
		// }

		//// 1-D array
			// int n;
			// cin>>n;
			// for(int i=1; i<=n; i++){
			// 	cin>>a[i];
			// 	pf[i] = pf[i-1] + a[i];
			// }

			// int q;
			// cin>>q;
			// while(q--){
			// 	int l, r;
			// 	cin >> l >> r;
			// 	cout << pf[r] - pf[l-1] << endl;
			// }
			// // O(n) + O(q*n) = 10^10  // calculation sum for each query
			// // O(n) + O(q) = 10^5 // using precomputation


		//// 2-D array sum of sq. (a, b) (c, d)
			/*
			Given 2d array a of N*N integers. Given Q queries and in each
			query given a, b, c and d. Print sum of square represented by (a,b)
			as top left point and (c,d) as top bottom right point

			Constraints 
			1 <= N <= 10^3 
			1 <= a[i][j] <= 10^9 
			1 <= Q <= 10^5 
			1 <= a,b,c,d <= N 
			*/
			// int n;
			// cin>>n;
			// for(int i=1; i<=n; i++)
			// 	for(int j=1; j<=n; j++){
			// 		cin>>arr[i][j];
			// 		pre[i][j] = arr[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
			// 	}

			// int q;
			// cin>>q;
			// while(q--){
			// 	int a,b,c,d;
			// 	cin>>a>>b>>c>>d;

			// 	cout << pre[c][d]-pre[a-1][d]-pre[c][b-1]+pre[a-1][b-1] << endl;
			// }

			// // O(n^2) + O(q) = O(n^2)


		//// GCDQ
			// https://www.codechef.com/problems/GCDQ
			// int t;
			// cin>>t;
			
			// while(t--){
			//     int n, q;
			//     cin>>n>>q;
			    
			//     int arr[n+1];
			//     for(int i=1; i<=n; i++)
			//         cin>>arr[i];
			    
			//     int forward[n+1], backward[n+1];
			//     forward[0] = backward[n+1] = 0;
			    
			//     for(int i=1; i<=n; i++)
			//         forward[i] = __gcd(forward[i-1], arr[i]);
			        
			//     for(int i=n; i>=1; i--)
			//         backward[i] = __gcd(backward[i+1], arr[i]);
			    
			//     while(q--){
			//         int l, r;
			//         cin>>l>>r;
			        
			//         int gc=__gcd(forward[l-1], backward[r+1]);
			//         cout<<gc<<"\n";
			//     }
			// }


		//// Array Manipulation
			// https://www.hackerrank.com/challenges/crush/problem
			// Global vars 
			/*
			const int N = 1e7+10;
			long long int arr[N];
			*/

		    // int n, m;
		    // cin>>n>>m;
		    
		    // while(m--){
		    //     int a, b, k;
		    //     cin>>a>>b>>k;
		        
		    //     arr[a] += k;
		    //     arr[b+1] -= k;
		    // }
		    
		    // // Taking prefix sum
		    // for(int i=1; i<=n; i++)
		    //     arr[i] = arr[i-1]+arr[i];
		    
		    // long long int mx = -1;
		    // // Finding out max element
		    // for(int i=1; i<=n; i++)
		    //     mx = max(mx, arr[i]);
		        
		    // cout<<mx<<endl;


		//// PrefixSum + Hashing ->> is string from pos l to r palindrome
		// Bruteforce
			// int t;
			// cin >> t;
			// while(t--){
			// 	int n, q;
			// 	cin >> n >> q;
			// 	string s;
			// 	cin >> s;
			// 	while(q--){
			// 		int l, r;
			// 		cin >> l >> r;
			// 		int hsh[26];
			// 		for(int i=0; i<26; i++)
			// 			hsh[i] = 0;
			// 		l--; r--;
			// 		for(int i=l; i<=r; i++)
			// 			hsh[s[i]-'a']++;
			// 		int oddCnt=0;
			// 		for(int i=0; i<26; i++)
			// 			if(hsh[i]%2)
			// 				oddCnt++;
			// 		if(oddCnt>1)
			// 			cout<<"NO\n";
			// 		else
			// 			cout<<"YES\n";
			// 	}
			// }
			//// O(t*(n+q*(26+n+26))) = O(t*q*n) = 10 * 10^5 * 10^5

		int t;
		cin >> t;
		while(t--){
			int n, q;
			cin >> n >> q;
			string s;
			cin >> s;
			// Initialising hash array to zero
			for(int i=0; i<NN; i++)
				for(int j=0; j<26; j++)
					hsh[i][j] = 0;

			// Increasing count for each alphabet present in string
			for(int i=0; i<n; i++)
				hsh[i+1][s[i]-'a']++;
			// Making prefix sum array for each alphabet
			for(int i=0; i<26; i++)
				for(int j=1; j<=n; j++)
					hsh[j][i] += hsh[j-1][i];

			while(q--){
				int l, r;
				cin >> l >> r;

				int oddCnt=0;
				for(int i=0; i<26; i++){
					int charCt = hsh[r][i] - hsh[l-1][i];
					if(charCt%2)
						oddCnt++;
				}

				if(oddCnt>1)
					cout<<"NO\n";
				else
					cout<<"YES\n";
			}
		}

	return 0;
}