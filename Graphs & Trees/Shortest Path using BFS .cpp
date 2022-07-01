#include<bits/stdc++.h>

using namespace std;
#define lli long long int

const int N = 1e5+10;
const int INF = 1e9+10;

bool vis[8][8];
int level[8][8];

// Coordinates of movements with bottom left corner as (0, 0)
vector<pair<int, int>> movements = {
	{2, -1}, {2, 1}, //
	{-1, 2}, {1, 2}, // 
	{-2, -1}, {-2, 1}, //
	{-1, -2}, {1, -2} //
};


int getX(string source){
	return source[0]-'a';
}

int getY(string source){
	return source[1]-'1';
}

bool isValid(int x, int y){
	return (x >= 0 && y >= 0 && y < 8 && x < 8);
}

// Returns shortest distance
int bfs(string source, string dest){
	int sourceX = getX(source);
	int sourceY = getY(source);

	int destX = getX(dest);
	int destY = getY(dest);

	queue<pair<int, int>> q;
	q.push({sourceX, sourceY});
	vis[sourceX][sourceY] = 1;
	level[sourceX][sourceY] = 0;

	while(!q.empty()){
		pair<int, int> p = q.front();
		int x = p.first, y = p.second;
		q.pop();


		for(auto movement: movements){
			int childX = x + movement.first;
			int childY = y + movement.second;

			if(!isValid(childX, childY)) continue;
			if(!vis[childX][childY]){
				q.push({childX, childY});
				level[childX][childY] = level[x][y]+1;
				vis[childX][childY] = 1;
			}

			if(level[destX][destY] != INF)
				break;
		}
	}
	return level[destX][destY];
}

void reset(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			vis[i][j] = 0;
			level[i][j] = INF;
		}
	}
}

// // INPUT
// 3
// a1 h8
// a1 c2
// h8 c3


// Question -> https://www.spoj.com/problems/NAKANJ/

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int t;
		cin>>t;

		while(t--){
			reset();

			string src, dest;
			cin>>src>>dest;

			cout<<bfs(src, dest)<<"\n";
		}

}