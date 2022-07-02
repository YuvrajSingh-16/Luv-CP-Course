#include<bits/stdc++.h>

using namespace std;
#define lli long long int

void printBinary(int n){
	for(int i=10; i>=0; i--){
		cout<<((n>>i)&1);
	}cout<<"\n";
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		// printBinary(9);
		// int i=3;
		int n=9;

		// if((n&(1<<i)) != 0)
		// 	cout<<"Bit set";
		// else
		// 	cout<<"Bit not set";
		// cout<<"\n";

		// // Bit set
		// printBinary(n | (1<<1));

		// // Bit unset -> ~ complement
		// printBinary(n&(~(1<<3)));

		// // Toggle -> XOR
		// printBinary(n ^ (1<<2)); // 2nd bit toggle
		// printBinary(n ^ (1<<3)); // 3rd bit toggle

		int cnt=0;
		for(int i=31; i>=0; i--){
			if((n & (1<<i)) != 0)
				cnt++;
		} cout<<cnt<<endl;

		// BitSet count
		cout<<__builtin_popcount(n)<<endl;
		cout<<__builtin_popcountll(1LL<<35)<<endl;

		// // Divide by 2
		// cout<<(4>>1)<<endl;
		// // Multiply by 2
		// cout<<(4<<1)<<endl;

		// UpperCase, LowerCase conversion
		// for(char ch='A'; ch<='E'; ch++){
		// 	cout<<ch<<endl;
		// 	printBinary(ch);
		// }
		// for(char ch='a'; ch<='e'; ch++){
		// 	cout<<ch<<endl;
		// 	printBinary(ch);
		// }cout<<"\n";

		// char A = 'A';
		// char a = (A | (1<<5)); // Capital to small
		// cout<< a <<endl;
 
		// cout<< char(a & ~(1<<5)) << endl;  // Small to capital

		// cout<< char(1<<5) << endl;
		// printBinary('_');

		// cout<< char('c' & '_') << endl;  // Small to capital
		// cout<< char('C' | ' ') << endl;  // Capital to small

		// printBinary(' ');


		// // Clear LSBs upto ith bit
		// int a2 = 59;
		// printBinary(a2);
		// int i = 4;
		// int b = (a2 & (~((1<<(i+1))- 1)));
		// printBinary(b);

		// // Clear MSBs upto ith bit
		// i = 3;
		// int c = (a2 & ((1<<(i+1))-1));
		// printBinary(c);


		// // Check power of 2
		// int n = 14;
		// if(n&(n-1))
		// 	cout<<"Not power of 2";
		// else cout<<"Power of 2";
		// cout<<"\n";



		// Swap numbers
		// int a = 4, b = 6;

		// a = a ^ b;
		// b = b ^ a;

			// XOR 
		// 0 0 -> 0
		// 0 1 -> 1
		// 1 0 -> 1
		// 1 1 -> 0

		// b = b ^ a ^ b -> a
		// a = a ^ b ^ a -> b

		// a = a ^ b;
		// cout<<"Swapped numbers: \n";
		// cout<<a<<" "<<b<<endl;


		// Find number with odd count
		// int n;
		// cin>>n;

		// int arr[n];
		// for(int i=0; i<n; i++)
		// 	cin>>arr[i];

		// int XOR=0;
		// for(int i=0; i<n; i++)
		// 	XOR ^= arr[i];
		// cout<<"Number with odd count: "<<XOR<<endl;

	cout << "\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}