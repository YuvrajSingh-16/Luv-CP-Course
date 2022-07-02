#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int M = 1e9+7;
double eps = 1e-10;


void printBinary(int n){
	for(int i=10; i>=0; i--){
		cout<<((n>>i)&1);
	}cout<<"\n";
}

vector<vector<int>> genaerateSubsets(vector<int> &nums){
	vector<vector<int>> ans;
	int n = nums.size();
	int subset_cnt = (1<<n);

	for(int mask=0; mask<subset_cnt; mask++){
		vector<int> subset;
		for(int i=0; i<n; i++){
			if((mask & (1<<i)) != 0)
				subset.push_back(nums[i]);
		} ans.push_back(subset);
	}
	// O(n * 2^n)
	return ans;
}


int gcd(int a, int b){ // TC: O(log n) max
	if(b==0) return a;
	return gcd(b, a%b);
}

int gcd_(int a, int b){
	if(a == 0)
		return b;
	return gcd_(b%a, a);
}

int binExpRec(int a, int b){
	if(b==0)
		return 1;

	int res = binExpRec(a, b/2);
	if(b&1)
		return (a*(res*1LL*res)%M)%M;
	else
		return (res*1LL*res)%M;
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

// //## Question:
// Consider this problem: 

// There are N≤5000 workers. 
// Each worker is available during some days of this month (which has 30 days). 
// For each worker, you are given a set of numbers, each from interval [1,30], 
// representing his/her availability. You need to assign an important project 
// to two workers but they will be able to work on the project only when they 
// are both available. Find two workers that are best for the job — 
// --> maximize the number of days when both these workers are available.

// You can compute the intersection of two workers (two sets) in O(30) 
// by using e.g. two pointers for two sorted sequences. 
// Doing that for every pair of workers is O(N2⋅30), slightly too slow.


// INPUT:
// 5
// 4
// 1 4 7 9
// 6 
// 2 9 1 7 25 29
// 7
// 1 23 4 7 9 11
// 29 
// 10
// 2 28 8 7 9 10 30 21 18 19
// 4
// 1 11 29 7


double nthRoot(double x, int n){  //  log(eps) i.e, log of search space size
	double l=1, h=x;

	while(h-l>eps){
		double mid = (l+h)/2;
		if(pow(mid, n) < x)
			l = mid;
		else 
			h = mid;
	}return l;
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		// Bit Masking problem
			// int n;
			// cin>>n;

			// vector<int> masks(n, 0);

			// for(int i=0; i<n; i++){
			// 	int num_workers;
			// 	cin>>num_workers;

			// 	int mask=0;
			// 	for(int j=0; j<num_workers; j++){
			// 		int day;
			// 		cin>>day;
			// 		mask = (mask | (1<<day));
			// 	}
			// 	masks[i] = mask;
			// }
			// int max_days=0;
			// int person1 = -1;
			// int person2 = -1;

			// for(int i=0; i<n; i++){
			// 	for(int j=i+1; j<n; j++){
			// 		int intersection = masks[i] & masks[j];
			// 		int common_days = __builtin_popcount(intersection);
			// 		if(common_days > max_days){
			// 			max_days = common_days;
			// 			person1 = i;
			// 			person2 = j;
			// 		}
			// 	}
			// }

			// cout<<max_days<<" -> "<<person1<<" "<<person2<<endl;
			// // O(N^2) * O(1)


		// // Subsets generation
			// int n;
			// cin>>n;
			// vector<int> arr(n, 0);

			// for(int i=0; i<n; i++){
			// 	cin>>arr[i];
			// }

			// vector<vector<int>> subsets = generateSubsets(arr);

			// for(auto subset: subsets){
			// 	for(int a: subset)
			// 		cout<<a<<" ";
			// 	cout<<"\n";
			// }


		cout<<gcd_(12, 18)<<endl;
		cout<<gcd(2, 8)<<endl;

		cout<<binExpRec(2,24)<<endl;
		cout<<binExpItr(2,24);

	cout << "\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}