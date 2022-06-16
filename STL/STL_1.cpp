#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		// Pairs 
	// pair<int, string> p;
	// // p = make_pair(2, "UV");
	// p = {2, "UV"};

	// pair<int, string> &p1 = p;
	// p1.first = 1;

	// cout<< p.first << " " << p.second <<endl;


		// Vectors v(size, element)
	// vector<int> v(10, 3);
	// v.push_back(); // O(1)
	// v.size(); // O(1)

	// vector<int> v1 = v; // O(n)
	vector<int> vec = {2, 3, 4, 5, 6};
	// vector<int> iterator :: itr;
	// for(itr = vec.begin(); itr != vec.end(); itr++)
	// 	cout<<(*itr)<<" ";

	// for(auto val : vec)
	// 	cout<<val<<" ";
	// cout<<endl;

			// Vector of pairs
	vector<pair<int, int>> v = {{1, 2}, {3, 4}, {5, 6}};

			// Printing vector of pairs using #### ITERATOR ####
	vector<pair<int, int>> :: iterator itr;

	// // noobs way
	// for(itr = v.begin(); itr != v.end(); itr++)
	// 	cout<<(*itr).first<<" "<<(*itr).second<<endl;

	// cout<<endl;
	// // Programmers way
	// for(itr = v.begin(); itr != v.end(); itr++)
	// 	cout<<itr->first<<" "<<itr->second<<endl;

	//cout<<endl;
	// Pros way
	for(auto p : v)  							// ##################################
		cout<<p.first<<" "<<p.second<<endl;


	// for(auto &p : vec) // modifying vector elements using reference
	// 	p++;
	// for(auto p : vec)
	// 	cout<<p<<" ";

	cout<<endl;


                          // ############## MAPS ############## 
	map<int, string> mp;
	mp[5] = "namaste";    // O(log(n)) 
	mp[1] = "abcd";
	mp[2] = "efgh";
	mp[3] = "efhfe";
	mp[6];		// O(log(n))

	map<string, string> m;
	m["abcdefghklmn"] = "abcdefghklmn";  // Time Complexity depends on the time required to search a key

	// for(auto &itr : mp)  // O(n*log(n)) 
	// 	cout<<itr.first<<" "<<itr.second<<endl;

	// MAP find & erase
	// auto it = mp.find(7);   // O(log(n)) 
	// if(it != m.end())
	// 	mp.erase(it);   // O(log(n)) 

	// if(it == mp.end()){ 
	// 	cout<<"[-] Reached the end ....";
	// }else{ 
	// 	cout<<(*it).first<<" "<<(*it).second;
	// }cout<<endl;


	// mp.clear();
	// for(auto &itr : mp)  // O(n*log(n)) 
	// 	cout<<itr.first<<" "<<itr.second<<endl;



		// ############# Unordered Maps #############
	// 1. inbuilt implementation (using hashtables => it hashs the value of key)
	// 2. Time complexity (O(1))
	// 3. Valid keys datatype (cannot use complex data structures like vectors, pairs.., etc as **keys**)

	unordered_map<int, string> un_mp;
	un_mp[5] = "namaste";    // O(1) 
	un_mp[1] = "abcd";
	un_mp[2] = "efgh";
	un_mp[3] = "efhaehfe";
	un_mp[6];		// O(1)


	// auto it = un_mp.find(7); // O(1)
	// un_mp.erase(it);


	// Multimap :-- Multiple values can be stored. instead we can use 
	// Exp. -> map<string, vector<int>> mp;



	//  ############################# SETS #############################
	//// Normal sets(ordered set)
	// set<string> s;
	// s.insert("abc");  // O(log(n))
	// s.insert("bcd");
	// s.insert("gfg");
	// s.insert("hij");

	// auto it = s.find("dda");  // O(log(n))
	// if(it != s.end())
	// 	s.erase(it);

	// for(string str : s)
	// 	cout<<str<<endl;
	// cout<<endl;


	//// unordered sets (Hash tables && only basic DS can be used )
	// unordered_set<string> un_st;
	// un_st.insert("abc");  // O(1)
	// un_st.insert("bcd");
	// un_st.insert("gfg");
	// un_st.insert("hij");

	// auto it1 = un_st.find("dda");  // O(1)
	// if(it1 != un_st.end())	
	// 	un_st.erase(it1);

	// for(string str : un_st)
	// 	cout<<str<<endl;


	//// Multisets :- Duplicate values can exist
	multiset<string> mset;
	mset.insert("abc");  // O(log(n))
	mset.insert("bcd");
	mset.insert("gfg");
	mset.insert("abc");
	mset.insert("bcd");

	auto it1 = mset.find("bcdd");  // O(log(n))

	if(it1 != mset.end())
		mset.erase(it1);  // Only deletes element pointed by iterator

	//mset.erase("abc"); // Deletes value present on each location
	for(string str : mset)
		cout<<str<<endl;

	return 0;
}