#include<bits/stdc++.h>

using namespace std;
#define lli long long int

void generate(string &s, int open, int close){
	if(open == 0 && close == 0){
		cout<<s<<endl;
		return;
	}

	if(open > 0){
		s.push_back('(');
		generate(s, open-1, close);
		s.pop_back();
	}

	if(close > 0 && open < close){
		s.push_back(')');
		generate(s, open, close-1);
		s.pop_back();
	}
}

int lSubstr(string &s, int k, int start, int end){

 		for(int j=start; j<end; j++)
 			cout<<s[j];
 		cout<<endl;

        vector<int> f(26, 0);
        for(int i=start; i<end; i++)
            f[s[i]-'a']++;
        
        int l, r;
        
        for(int i=start; i<end; i++){
            if(f[s[i]-'a']<k){
                l = lSubstr(s, k, start, i);
                r = lSubstr(s, k, i+1, end);
                cout<<"l: "<<l<<", r: "<<r<<endl;
                return max(l, r);
            }
        } return end-start;
    }
    
int longestSubstring(string s, int k) {
    return lSubstr(s, k, 0, s.length());
}

vector<vector<int>> subsets;
void generateSubset(vector<int> &nums, int i, vector<int> subset){
	if(i == nums.size()){
		subsets.push_back(subset);
		return;
	}

	generateSubset(nums, i+1, subset);
	subset.push_back(nums[i]);
	generateSubset(nums, i+1, subset);
	subset.pop_back();

}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		string s="";
		// int n = 2;
		// generate(s, n, n);

		// cout<<longestSubstring("aaab", 3);

		int n;
		cin>>n;

		vector<int> nums(n);
		for(int i=0; i<n; i++)
			cin>>nums[i];
		vector<int> subset;

		generateSubset(nums, 0, subset);

		for(auto arr: subsets){
			for(int a: arr){
				cout<<a<<" ";
			}cout<<"\n";
		}

	cout<<"\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}