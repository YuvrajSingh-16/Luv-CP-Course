#include<bits/stdc++.h>

using namespace std;
#define lli long long int

double eps = 1e-10;

int lower_bound(vector<int>&v, int element){
	int lo=0, hi=v.size()-1;

	while(hi-lo>1){
		int mid = (lo+hi)/2;
		if(v[mid]<element)
			lo = mid+1;
		else 
			hi = mid;
	}

	if(v[lo] >= element)
		return lo;
	else if(v[hi] >= element)
		return hi;
	return -1;
}


int upper_bound(vector<int>&v, int element){
	int lo=0, hi=v.size()-1;

	while(hi-lo>1){
		int mid = (lo+hi)/2;
		if(v[mid]<=element)
			lo = mid+1;
		else 
			hi = mid;
	}

	if(v[lo] > element)
		return lo;
	else if(v[hi] > element)
		return hi;
	return -1;
}

// Time Complexity: p*log(N*10^d) -> pth root of number N
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


bool isPossible(vector<int> arr, int h, int m){
	lli sm=0;

	for(int i=0; i<arr.size(); i++){
		if(arr[i]>h)
			sm+=arr[i]-h;
	}
	return sm>=m;
}


int maxHeight(vector<int> trees, int m){
	int mx = *max_element(trees.begin(), trees.end());

	int l=0, h=mx;
	int ans=-1;

	while(l<h){
		int mid = l+(h-l)/2;
		if(isPossible(trees, mid, m)){
			ans = mid;
			l = mid+1;
		}else{
			h = mid-1;
		}
	}return ans;
}


int maxBladeHeight(vector<int> trees, int m){
	int l=0, h=1e9, mid;

	while(h-l>1){
		mid = (l+h)/2;

		if(isPossible(trees, mid, m))
			l = mid;
		else
			h = mid-1;
	} 
	
	if(isPossible(trees, h, m)) return h;
	else return l;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		// int n;
		// cin>>n;

		// vector<int> v(n);
		// for(int i=0; i<n; i++)
		// 	cin>>v[i];

		// sort(v.begin(), v.end());
		// int element;
		// cin>>element;

		// for(int i=0; i<n; i++)
		// 	cout<<v[i]<<" ";
		// cout<<endl;

		// int lb = lower_bound(v, element);
		// cout<<lb<<" :"<<( lb != -1? v[lb]: -1)<<endl;

		// int ub = upper_bound(v, element);
		// cout<<ub<<" :"<<( ub != -1? v[ub]: -1)<<endl;


		// cout<<setprecision(10)<<nthRoot(16, 2)<<endl;
		// cout<<setprecision(10)<<sqrt(16);

		int n, m;
		cin>>n>>m;

		vector<int> v(n);
		for(int i=0; i<n; i++)
			cin>>v[i];

		cout<<"Height of blade to be set :"<<maxBladeHeight(v, m);


	cout << "\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}