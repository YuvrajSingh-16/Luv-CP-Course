#include<bits/stdc++.h>

using namespace std;
#define lli long long int

bool isVowel(char ch){
	return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}


vector<string> subsets(string str){
	vector<string> ans;
	int subset_cnt = 1<<str.length();

	for(int mask=0; mask<subset_cnt; mask++){
		string subset;
		for(int bit=0; bit<str.length(); bit++){
			if(mask & 1<<bit) subset.push_back(str[bit]);
		}
		if(subset.size())
			ans.push_back(subset);
	}

	return ans;
}


// Three Musketeers
// https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		
		int t;
		cin>>t;

		while(t--){
			int n;
			cin>>n;
			string str[n];
			for(int i=0; i<n; i++){
				cin>>str[i];
			}

			unordered_map<string, int> hsh;
			for(int i=0; i<n; i++){
				// Finding distinct vowels present in a name
				set<char> distinct_vow;
				for(char ch: str[i]){
					if(isVowel(ch))
						distinct_vow.insert(ch);
				}

				// Creating vowel string
				string vowel_str;
				for(char ch: distinct_vow)
					vowel_str.push_back(ch);

				// Finding subsets of vowel string
				vector<string> all_subsets = subsets(vowel_str);
				// Storing count of each subset present
				for(string vowel_subset: all_subsets)
					hsh[vowel_subset]++;
			}

			long long ans=0;
			// Traversing throw hash array
			for(auto &p: hsh){
				if(p.second<3) continue;
				long long times = p.second;
				// Ways to select 3 students out of n('times' here) nC3
				long long ways = times * (times-1) * (times-2) / 6;

				// Adding if odd subtracting if even(AUBUC = A+B+C -A^B -B^C -C^A +A^B^C)
				if(p.first.size()%2 == 0) ans -= ways;
				else ans += ways;
			}

			cout<<ans<<"\n";
		}

	cout << "\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}