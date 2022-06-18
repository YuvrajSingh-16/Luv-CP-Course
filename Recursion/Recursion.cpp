#include<bits/stdc++.h>

using namespace std;
#define lli long long int

int sum(int n, int a[]){
	if(n<0)
		return 0;
	return sum(n-1, a)+a[n];
}

int digit_sum(int n){
	if(n==0)
		return 0;
	return n%10+digit_sum(n/10);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int n;
		cin>>n;
		// int a[n];
		// for(int i=0; i<n; i++)
		// 	cin>>a[i];

		// cout << sum(n-1, a);
		cout<<digit_sum(n);

	return 0;
}