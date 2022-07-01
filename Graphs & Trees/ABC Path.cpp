#include<bits/stdc++.h>

using namespace std;
#define lli long long int

int maxLen = 0;

vector<pair<int, int>> movements = {
    {1, 0}, {1, 1}, //
    {0, 1}, {-1, 1}, // 
    {-1, 0}, {-1, -1}, //
    {0, -1}, {1, -1} //
};

bool isValid(vector<vector<char>>& grid, int i, int j){
    return (i>=0 && j>=0 && i<grid.size() && j<grid[0].size());
}


void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j, int curr_l){
    if(visited[i][j]) 
        return;
    
    visited[i][j] = 1;
    maxLen = max(maxLen, curr_l);

    for(auto movement: movements){
        int newX = i + movement.first;
        int newY = j + movement.second;

        if(isValid(grid, newX, newY) && (grid[newX][newY]-grid[i][j] == 1))
            dfs(grid, visited, newX, newY, curr_l+1);
    }
}


// // INPUT

// 4 3
// ABE
// CFG
// BDH
// ABC
// 0 0


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

        int r, c, k=0;

        while(cin>>r>>c){
            if(r==0 && c==0)
                break;
            vector<vector<char>> grid(r, vector<char>(c));
            vector<vector<int>> vis(r, vector<int>(c));

            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    cin>>grid[i][j];
                }
            }

            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    if(grid[i][j] == 'A')
                        dfs(grid, vis, i, j, 1);
                }
            }

            cout<<"Case "<<++k<<": "<<maxLen<<"\n";
            maxLen=0;
        }

	return 0;
}