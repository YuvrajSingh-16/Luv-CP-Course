#include<bits/stdc++.h>

using namespace std;
#define lli long long int

// XOR Challenge
// https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-challenge-2420f189/


// Input
// 17

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		
		int n;
		cin>>n;

		// Total number of bits in input
		int bit_cnt = (int)log2(n)+1;
		int a, b;
		a = b = 0;
		vector<int> set_bits;

		// Saving all the set bits idx of input number 
		// and setting bits on a and b to maximize the number 
		for(int i=0; i<bit_cnt; i++){
			if(n & (1<<i))
				set_bits.push_back(i);
			else{
				a |= 1<<i;
				b |= 1<<i;
			}
		}

		lli ans = -1;
		int subsets = 1<<set_bits.size();

		// Traversing throw all possible subsets
		for(int mask=0; mask<subsets; mask++){
			int a_copy=a, b_copy=b;
			for(int i=0; i<set_bits.size(); i++){ // one time setting bit on in a and once in b
				if(mask & (1<<i))
					a_copy |= 1<<set_bits[i];
				else
					b_copy |= 1<<set_bits[i];
			}
			ans = max(ans, a_copy *1LL* b_copy);
		}

		cout<<ans<<endl;

	cout << "\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}