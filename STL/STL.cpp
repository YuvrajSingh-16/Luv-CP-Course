#include<bits/stdc++.h>
#include<iostream>
#include<vector>	
#include<set>

using namespace std;

#define oset tree<int, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>  

set <int> subarrays;

int findAns(int x){// The second type of query
	// For any element k, the first element in the subarray of element k is -
	// The largest element j in sa such j<=k
	auto it = subarrays.upper_bound(x);
	it--;
	return (*it);
}


void remove(int x){
	subarrays.erase(x);
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	// Map --> map<key, value> name; 
		// key can be of any type and it only uses memory for the number of values inserted
		// map is highly efficient in terms of memory

	// Set --> set<int> s;
		// only stores unique values
		// sorts the elements

             					
             					// set<int> s;

// s.lower_bound(x); --> returns an iterator to the first element in the set >=x
// s.upper_bound(x); --> returns an iterator to the first element in the set > x
// If not such element exists --> return an iterator to s.end()

			//s.begin(); -> returns an iterator to the first element
			//s.end(); -> returns an iterator to the next of the last element(after the final element)

	// Vector --> vector<int> v;

	// set<int> s;
	// s.insert(5);
	// s.insert(4);

	// vector<int> v;
	// v.push_back(5);
	// v.push_back(4);

// Vector insert is O(n), set insert is O(LogN)

	// for(int k: s) cout<<k<<" ";
	// 	cout<<endl;

	// for (auto i = v.begin(); i != v.end(); ++i) 
 //        cout << *i << " "; 
	// 	cout<<endl;


	// priority queue -> priority_queue<int> pq;
		// pq.top() returns the maximum element in a priority queue -> O(1)
		// pq.pop() removes the maximum element from the priority queue -> O(logN)
		// pq.push() adds an element to the queue -> O(LogN)
		// This is internally stored as binary heap


	// pbds -> policy based data structures
		// set -> no random access
		// If you wanted to know the kth largest element in a set, you would have to iterate through k elements
		// O(K.Q) -> O(K.N)
		// Ordered set can find the kth smallest element in O(LogN)

	 // Ordered set -> tree<int, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> 
		// Main function of the ordered set :
		// 1) Find by order -> returns the element at the kth position
		// 2) Order of key -> returns the position of the element


		// Save Konoha CodeChef DSA learning series problem

/*	int t;
	cin>>t;
	while(t--){
		int N, Z; // num of soldiers and the strength of the pain
		cin>>N>>Z;
		int a[N]; // power of the soldiers
		
		int i, x, count=0;
		priority_queue <int> pq;

		for(i=0; i<N; i++){
			cin>>x;         
			pq.push(x);
		}

	int attack;
	while (Z>0 && pq.top()>0){
			attack = pq.top();  // Fetching the max attacking power
			Z -= attack;  // hitting Pain with max attacking power
			pq.pop();   // removing the used power
			pq.push(attack/2); // reducing the max power according the question
			count++;
		}

	if(Z>0) cout<<"Evacuate"<<endl;
	else cout<<count<<endl;	
	} */

//-------------------------------------------------------------------------------------------
		// Yet another partition problem

	// This problem asks to form subarrays out of the given array such that considering
	// i and the index of the current element than 
		// if i and i+1 element is in the same subarray then 
	// the A[i+1] should be divisible by A[i] 
		// i.e, A[i+1]%A[i] == 0
	// and we have to minimise the number of subarrays forming out of the given array.

	int N, Q;
	cin>>N>>Q;
	int a[N+1];

	for(int i=1; i<=N; i++) cin>>a[i];

	subarrays.insert(1);
		// E.g, {2, 4, 8, 5, 10, 20, 3}
		//		 1        4          7

	// {2, 4, 8}
	// {5, 10, 20}
	// {3}
	
	//// subarray -->  {1, 4, 7}
				
				// formed the global subarray
		for(int i=2; i<=N; i++){
		// for index i, if A[i+1]%A[i]==0, then we should place i+1 and i in the same subarray
			if(a[i] % a[i-1] == 0) continue;
		//we continued the loop because we have already stored the start of the (i-1)th subarray
		subarrays.insert(i);
	} // We have created the basic partitions before any queries took place

	while(Q--){
		int type, i;
		cin>>type>>i;

		if(type==1){
			cin>>a[i]; // the updated value of a[i]
			// There are 4 things that can happen
			// A[i] and A[i-1] can now be in the same subarray -> DONE // merge
			// A[i] and A[i-1] can no longer be in the same subarray -> DONE // partition
			// A[i] and A[i+1] can now be in the same subarray -> DONE // merge
			// A[i] and A[i+1] can no longer be in the same subarray -> DONE // partition

			if(i>1){
				if((findAns(i)==i) && ((a[i] % a[i - 1]) == 0)){ // now a[i] and a[i-1] should be in the same subarray
					remove(i);
				}

				else if((findAns(i) < i) && ((a[i] % a[i-1]) != 0)){
					// this means a[i] and a[i-1] were in the same subarrays
					// we need to now saperate the subarrays
					subarrays.insert(i);
				}
			}

			if(i<N){
					if((findAns(i+1) > i) && ((a[i+1] % a[i] == 0))){
						remove(i+1);
					}
					else if((findAns(i+1) <= i) && ((a[i+1] % a[i])!=0)){
						subarrays.insert(i+1);
					}
				}
			}
		else
			cout<<findAns(i)<<endl;
	}

	return 0;
}