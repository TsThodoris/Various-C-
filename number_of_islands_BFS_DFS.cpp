#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void BFS(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid){
    visited[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});
    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        //traverse in neighbours and mark visited
        for(int deltarow = -1 ; deltarow <= 1 ; deltarow++){
            for(int deltacol = -1 ; deltacol <= 1 ; deltacol++){
                int nrow = row + deltarow;
                int ncol = col + deltacol;
                if(nrow >= 0 && nrow <= n && ncol >= 0 && ncol <= m && grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m,0));
    int islands = 0;
    for(int row = 0 ; row < n ; row++){
        for(int col = 0 ; col < m ; col++){
            if(!visited[row][col] && grid[row][col] == '1'){
                islands++;
                BFS(row, col, visited, grid);
            }
        }
    }
    return islands;
}

int main(){  
    vector<vector<char>> grid = {{'0','0'},{'1','0'},{'0','0'},{'0','0'}};
    int res = numIslands(grid);
    cout << res << endl;
}