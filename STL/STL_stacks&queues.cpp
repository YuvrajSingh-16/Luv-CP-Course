#include<bits/stdc++.h>
using namespace std;


// Balanced paranthesis

unordered_map<char, int> symbols = {{'(', -1}, {'{', -2}, 
									{'[', -3}, {')', 1}, 
									{'}', 2}, {']', 3}};

string isBalanced(string s) {
	stack<char> st;

	for(char c : s){
		if(symbols[c] < 0)
			st.push(c);
		else if(symbols[c] > 0) {
			if(st.empty())
				return "NO";
			char tmp = st.top();
			st.pop();

			if(symbols[tmp]+symbols[c] != 0)
				return "NO";
		}
	}
	return st.empty()? "YES": "NO";
}


vector<int> NGE(vector<int> vec){
	stack<int> st;
	int size = vec.size();
	vector<int> nge(size, -1);

	int i=0;
	for(;i<size; i++){
		while(!st.empty() && vec[st.top()] < vec[i]){
			nge[st.top()] = vec[i];
			st.pop();
		}st.push(i);
	}

	return nge;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
				//// ########STACKS#######
		// stack<char> s;
		// string paranthesis = "()(()(())())";

		// int len = paranthesis.length();
		// int i=0;

		// while(i<len){
		// 	if(paranthesis[i] == '(')
		// 		s.push('(');
		// 	else if(!s.empty())
		// 		s.pop();
		// 	else{
		// 		cout<<"Not balanced...."<<endl; 
		// 		break;
		// 	}i++;
		// }

		// if(!s.empty() && i == len)
		// 	cout<<"Not balanced.."<<endl; 
		// else if(i == len && s.empty())
		// 	cout<<"Balanced paranthesis..";
		// cout<<endl;

		// ##############################################################
		//// ########## Next Greater Element #########

		int n;
		cin>>n;

		vector<int> vec;
		int x;
		for(int i=0; i<n; i++)
			cin>>x, vec.push_back(x);   // 4 5 2 25 7 8

		vector<int> nge_arr = nge(vec);
		
		for(int x : nge_arr)
			cout<<x<<" ";
		cout<<endl;
		// ###############################################################


				//// #########QUEUE########
		// queue<string> q;
		// q.push("abcd");
		// q.push("efgh");
		// q.push("ijkl");
		// q.push("mnop");
		// while(!q.empty()){
		// 	cout<<q.front()<<endl;
		// 	q.pop();
		// }

	return 0;
}