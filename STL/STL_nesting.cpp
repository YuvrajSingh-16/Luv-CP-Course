#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	map<pair<string, string>, vector<int>> m;
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		string fn, ln;
		int c;

		cin>>fn>>ln>>c;
		vector<int> vec;
		for(int j=0; j<c; j++){
			int x;
			cin>>x;
			vec.push_back(x);
		}
		
		m[{fn, ln}] = vec;
	}

	for(auto &p : m){
		auto &full_name = p.first;
		auto &marks = p.second;

		cout<<full_name.first<<" "<<full_name.second<<" ";
		cout<<marks.size()<<endl;
		
		for(auto &e: marks)
			cout<<e<<" ";
		cout<<endl;
	}

	return 0;
}