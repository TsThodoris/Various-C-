#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void DFS(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid){
    visited[row][col] = 1;
    int n = grid.size(), m = grid[0].size();
    for(int deltarow = -1 ; deltarow <= 1 ; deltarow++){
        for(int deltacol = -1 ; deltacol <=1 ; deltacol++){
            int nrow = row + deltarow;
            int ncol = col + deltacol;
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                DFS(nrow, ncol, visited, grid);
            }
        }
    }
}
int numIslands(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n , vector<int>(m,0));
    int islands = 0;
    for(int row = 0 ; row < n ; row++){
        for(int col = 0 ; col < m ; col++){
            if(!visited[row][col] && grid[row][col] == 1){
                DFS(row, col, visited, grid);
                ++islands;
            }
        }
    }
    return islands;
};

int main(){
    vector<vector<int>> grid = { { 1, 1, 0, 0, 0 },{ 0, 1, 0, 0, 1 },{ 1, 0, 0, 1, 1 },{ 0, 0, 0, 0, 0 },{ 1, 0, 1, 0, 1 } };
    auto res = numIslands(grid);
    cout << "result : " << res << endl;
}

