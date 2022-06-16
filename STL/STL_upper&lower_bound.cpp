#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	vector<int> a(n, 0);

	for(int i=0; i<n; i++)
		cin>>a[i];

	sort(a.begin(), a.end());
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;

	auto it = lower_bound(a.begin(), a.end(), 4);  // O(log(n))

	if(it != a.end())
		cout<<(*it)<<endl;
	else
		cout<<"Not found !!";


	// Sets
	set<int> s;
	// lower_bound(s.begin(), s.end(), x) // O(n) -> uses binary search
	//s.lower_bound() // O(log(n)) -> uses trees for searching

	// Maps 
	map<int, int> m;
	// m.lower_bound() // O(log(n)) -> uses trees for searching

	return 0;
}