#include<bits/stdc++.h>

using namespace std;
#define lli long long int

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		//################################## Operator precedence

		// cout<<7/2*3<<endl;
		// cout<<3*7/2<<endl;
		// cout<<7/(2*3)<<endl;
		// cout<<3*(7/2)<<endl;


		//##################################### Overflow 
		// int a = 100000;
		// int b = 100000;
		// int c = a*b;
		// cout<<c<<endl;  // -> 1410065408

		// lli a = 100000;
		// lli b = 100000;
		// int c = a*b;
		// cout<<c<<endl;  // -> 1410065408

		// int a = 100000;
		// int b = 100000;
		// lli c = a*b;
		// cout<<c<<endl;  // -> 1410065408

					// Output as 10^10 (accurate for large values) ######################
		// int a = 100000;
		// int b = 100000;
		// lli c = a * 1LL * b;
		// cout<<c<<endl;  // -> 10000000000

		// lli a = 100000;
		// lli b = 100000;
		// lli c = a * b;
		// cout<<c<<endl;  // -> 10000000000

		double a = 100000;
		double b = 100000;
		double c = a * b;
		// fixed -> not to show ans in scientific notation
		// setprecision(0) -> not to show value after decimal
		cout << fixed << setprecision(0) << c << endl;  // -> 10000000000


		// C++ strings
		//// getline() in details

		// string str;
		// getline(cin, str);
		// cout<<str<<endl;

		/*
		int t;
		cin>>t;
		cin.ignore(); // ignores the extra whitespace characters i.e, shifts to nextline

		while(t--){
			string s;
			getline(cin, s);  // takes input from the whole line
			cout << s << endl;
		}*/

		// string a;
		// int n = 10;
		// // string.push_back()
		// for(int i=0; i<n; i++)
		// 	a.push_back('a'); // ✔ -> TC: O(1)

		// for(int i=0; i<n; i++)
		// 	a = a+'a';		// ❌  -> TC: O(a.length())



		// ##################### Arrays
		int arr[10];
		arr[11]=19;
		cout << arr[11];      // random behaviour

}