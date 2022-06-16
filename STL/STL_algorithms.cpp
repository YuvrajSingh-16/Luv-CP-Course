#include<bits/stdc++.h>

using namespace std;

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

	// cout<<(*min_element(v.begin(), v.end()))<<endl;
	// cout<<(*max_element(v.begin(), v.end()))<<endl;
	// cout<<"Sum : "<<accumulate(v.begin(), v.end(), 0)<<endl; // accumulate(begin, end, initial_sum);

	// cout<<count(v.begin(), v.end(), 3)<<endl;
	// auto itr = find(v.begin(), v.end(), 3);
	// if(itr != v.end())
	// 	cout<<*itr;
	// else
	// 	cout<<"Not found!!";
	// cout<<endl;

	// sort(v.begin(), v.end());
	// for(auto val: v)
	// 	cout<<val<<" ";
	// cout<<endl;

	// reverse(v.begin(), v.end()); // can reverse string, vector, array
	// for(auto val : v)
	// 	cout<<val<<" ";


	// ############# Lambda functions ############

	vector<int> v = {2, 4, 6, 9};

	cout<<all_of(v.begin(), v.end(), [](int x){ return x%2==0; })<<endl;
	cout<<any_of(v.begin(), v.end(), [](int x){ return x > 0; })<<endl;
	cout<<none_of(v.begin(), v.end(), [](int x){ return x < 0; })<<endl; // none of the element is less than zero
	return 0;
}