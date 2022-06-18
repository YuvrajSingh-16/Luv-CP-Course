#include<bits/stdc++.h>

using namespace std;
#define lli long long int


void selectionSort(int a[], int n){
	for(int i=0; i<n; i++){
		int minIdx=i;
		for(int j=i+1; j<n; j++)
			if(a[j]<a[minIdx])
				minIdx=j;
		swap(a[i], a[minIdx]);
	}
}

void merge(int a[], int l, int r, int mid){
	// Defining 2 arrays left and right to store elements upto l and r respectively
	int l_sz = mid-l+1;
	int L[l_sz+1];
	int r_sz = r-mid;
	int R[r_sz+1];

	for(int i=0; i<l_sz; i++)
		L[i] = a[i+l];
	for(int i=0; i<r_sz; i++)
		R[i] = a[i+mid+1];

	// Taking last element of both arrays as MAX so that no element remains uncopied from the array
	L[l_sz] = R[r_sz] = INT_MAX;
	int l_i=0, r_i=0;

	for(int i=l; i<=r; i++){
		if(L[l_i] <= R[r_i]){
			a[i] = L[l_i];
			l_i++;
		}else{
			a[i] = R[r_i];
			r_i++;
		}
	}
}

void mergeSort(int arr[], int l, int r){
	if(l==r)
		return;
	int mid = (l+r)/2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid+1, r);
	merge(arr, l, r, mid);
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int n;
		cin>>n;
		int a[n];
		for(int i=0; i<n; i++)
			cin>>a[i];

		// selectionSort(a, n);	// O(n^2)

		mergeSort(a, 0, n-1);	// O(n*log(n))

		for(int i=0; i<n; i++)
			cout<<a[i]<<" ";

	return 0;
}