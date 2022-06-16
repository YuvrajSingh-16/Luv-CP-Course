#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

lli binExp(lli x, lli n){
	lli res=1;

	while(n>0){
		if(n%2==0){
			x*=x, n/=2;
			x%=mod;
		}
		else{
			res*=x;
			res%=mod;
			n--;
		}
	}
	return res;
}

int gcd(int a, int b){
	if(a>b){
		if(b==0)
			return a;
		else
			return gcd(a%b, b);

	}else{
		if(a==0)
			return b;
		else
			return gcd(b%a, a);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	// cout<<binExp(2, 16)<<endl;
	// cout<<gcd(44, 12)<<endl;


	// ######################################## MAPS Question
		/*
			Given N strings, print unique strings
			in lexiographical order with their frequency

			N <= 10^5
			|S| <= 100
		*/

	int n;
	cin>>n;
	map<string, int> m;

	string a;
	for(int i=1; i<=n; i++)
		cin>>a, m[a]++;

	for(auto &pr : m)
		cout<<pr.first<<" "<<pr.second<<endl;
	
	cout<<"\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;
	return 0;
}