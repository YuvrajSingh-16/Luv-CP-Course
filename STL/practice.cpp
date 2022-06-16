#include<bits/stdc++.h>
using namespace std;

#define lli long long int 

//###### Recursion GFG ######
int rope(int k, int a, int b, int c){
	if(k == 0)
		return 0;
	if(k < 0)
		return -1;

	int max_count = max({rope(k-a, a, b, c), rope(k-b, a, b, c), rope(k-c, a, b, c)});

	if(max_count == -1)
		return -1;

	return max_count + 1;
}

void subsets(string str, string curr, int k){
	if(k == str.length()){
		cout<<curr<<" ";
		return;
	}

	subsets(str, curr+str[k], k+1);
	subsets(str, curr, k+1);
}

void TOH(int n, char a, char b, char c){
	if(n>0){
		TOH(n-1, a, c, b);
		cout<<"Moving disk "<<n<<" from "<<a<<" to "<<c<<endl;
		TOH(n-1, b, a, c);
	}
}

int joseph(int n, int k){
	if(n == 1)
		return 0;

	return (joseph(n-1, k)+k)%n;
}

int subsetSum(vector<int> a, int sum, int i){
	if(i == 0)
		return (sum == 0 ? 1: 0);

	return subsetSum(a, sum, i-1) + subsetSum(a, sum-a[i], i-1);
}

// void subsets(vector<int> a, int i, vector<int> subset, int pos){
// 	if(pos == a.size()){
// 		for(int val : subset)
// 			cout<<val<<" ";
// 		cout<<endl;
// 		return;
// 	}

// 	subset[i] = a[pos];
// 	subsets(a, i, subset, pos+1);
// 	subsets(a, i+1, subset, pos+1);
// }

bool isSafe(string str, int l, int i, int r){
	if(l != 0 && str[l-1] == 'A' && str[i] == 'B')
		return false;
	if((r == l+1) && str[i] == 'A' && str[l] == 'B' ||
		 r == l + 1 && l == i && str[r] == 'B' && str[l] == 'A')
		return false;
	return true;
}

void perm(string str, int l, int r){
	if(l == r){
		cout<<str<<endl;
		return;
	}

	for(int i=l; i<=r; i++){
		if(isSafe(str, l, i, r)){
			swap(str[l], str[i]);
			perm(str, l+1, r);
			swap(str[l], str[i]);
	}
  }
}

vector<string> permutations;
void permutation(string str, int l, int h){
	if(l == h){
		string st = str;
		permutations.push_back(st);
		return;
	}

	for(int i=l; i<=h; i++){
		swap(str[i], str[l]);
		permutation(str, l+1, h);
		swap(str[i], str[l]);
	}
}

// #######  #######  #######  #######  #######  


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		// cout<<rope(23, 11, 9, 12);
		// subsets("abc", "", 0);
		// TOH(16, 'A', 'B', 'C');
		// cout<<joseph(5, 3);

		// cout<<subsetSum({10,20,15}, 0, 3);
		// subsets({10, 2, 6, 8, 1, 9, 3}, 0, {}, 0);

		// perm("ABCAB", 0, 4);

		// for(string val : permutations)
		// 	cout<<val<<endl;

		cout<<power(2, 10);

	cout<<"\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}