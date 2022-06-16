#include<bits/stdc++.h>
using namespace std;

// return false if wanna swap values

// Sorting in increasing order
bool cmp(pair<int, int> p1, pair<int, int> p2){ 
	if(p1.first != p2.first)
		return (p1.first < p2.first); // If this then let it be
	else
		return (p1.second > p2.second); // If this then let it be
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	vector<pair<int, int> >vec(n, {0,0});
	for(int i=0; i<n; i++)
		cin>>vec[i].first>>vec[i].second;

	// for(int i=0; i<n; i++){
	// 	for(int j=i+1; j<n; j++){
	// 		if(should_i_swap(vec[i], vec[j]))
	// 			swap(vec[i], vec[j]);
	// 	}
	// }

	sort(vec.begin(), vec.end(), cmp);

	for(int i=0; i<n; i++)
		cout<<vec[i].first<<" "<<vec[i].second<<endl;

	return 0;
}