#include<bits/stdc++.h>

using namespace std;

#define PI 3.14159265358979323846264338327950
double eps = 1e-6;

const int N = 1e6;



bool isPossible(long double pie_area[], int n, long double mid, int f){
	int pieces=0;
	if(mid==0)
		return false;

	for(int i=0; i<n; i++){
		pieces += (int)(pie_area[i]/mid);
	}

	return pieces>=f;
}


long double findArea(long double pie_area[], int n, int f){
	long double l = 0, h = pie_area[n-1];

	while(h-l>=1e-4){
		long double mid = l+(h-l)/2;
		if(isPossible(pie_area, n, mid, f)){
			l = mid;
		}else{
			h = mid;
		}
	}return l;
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int t;
		cin>>t;

		while(t--){
			int n, f;
			cin>>n>>f;

			f++;
			int pies[n] {0};
			long double pie_area[n] {0};

			for(int i=0; i<n; i++){
				cin>>pies[i];
			}

			sort(pies, pies+n);

			for(int i=0; i<n; i++){
				pie_area[i] = pies[i]*pies[i]*PI;
			}

			long double area = findArea(pie_area, n, f);

			// cout<<setprecision(4)<<area<<"\n";
			printf("%0.4Lf\n", area);
		}


	cout << "\n\n";
	cout << (double)clock()/CLOCKS_PER_SEC << " sec" << endl;

	return 0;
}