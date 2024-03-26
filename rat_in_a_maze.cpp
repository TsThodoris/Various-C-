#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
//targeted location bottom right cell
string direction = "DLRU";
vector<int> d_row{1,0,0,-1};
vector<int> d_col{0,-1,1,0};

vector<vector<int>> mapToMaze(vector<vector<string>> &map, int n){
    vector<vector<int>> maze(n,vector<int>(n,0));
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; j++){
            if(map[i][j] == "."){
                maze[i][j] = 1;
            }else if(map[i][j] == "A" || map[i][j] == "X"){
                maze[i][j] = 0;
            }else if(map[i][j] == ">"){
                for(int c = j ; c < n ; ++c){
                    maze[i][c] = 0;
                }
            }else if(map[i][j] == "<"){
                for(int c = j ; c > 0 ; --c){
                    maze[i][c] = 0;
                }
            }else if(map[i][j] == "^"){
                for(int r = i ; r > 0 ; --r){
                    maze[r][j] = 0;
                }
            }else if(map[i][j] == "v"){
                for(int r = i ; r < n ; ++r){
                    maze[r][j] = 0;
                }
            }
        }
    }
    return maze;
}

bool isUnblocked(int row, int col, int n,vector<vector<int>> &maze){
    return row >= 0 && col >= 0 && row < n && col < n && maze[row][col];
}

void findPath(int row, int col, int n, vector<vector<int>> &maze, vector<string> &path, string currentPath){
    if(row == n-1  && col == n-1){
        path.push_back(currentPath);
        return;
    }
    maze[row][col] = 0; //cell is now blocked because the rat is in it
    for(int i = 0 ; i < 4 ; ++i){
        int nextRow = row + d_row[i];
        int nextCol = col + d_col[i];
        bool res = isUnblocked(nextRow, nextCol, n, maze);
        if(res){
            currentPath += direction[i];
            findPath(nextRow, nextCol, n, maze, path, currentPath);
            currentPath.pop_back();
            
        }
    }
    maze[row][col] = 1;
}

int main(){
    vector<vector<string>> map = {{"A>.."},{"...."},{"..^X"},{"<..."}};
    vector<vector<int>> m = mapToMaze(map,4);
    vector<vector<int>> maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    for(auto i : m){
        for(auto j : i){
            cout << j << ",";
        }
        cout << endl;
    }
   /*  int n = maze.size();
    vector<string> result;
    string path;
    cout << "With maze : " << endl;
    findPath(0,0,n,maze,result,path);
    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    cout << endl;

    vector<string> result2;
    string path2;
    cout << "With map : " << endl;
    findPath(0,0,n,m,result2,path2);
    if (result2.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result2.size(); i++)
            cout << result2[i] << " ";
    cout << endl;
 */
    return 0;
}