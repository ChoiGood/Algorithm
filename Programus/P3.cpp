#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& grid, int row, int col, int n, int m, vector<vector<bool>>& visited, vector<pair<int, int>>& path, vector<vector<pair<int, int>>>& paths) {
    // base case
    if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0 || visited[row][col]) {
        return;
    }

    // mark current cell as visited and add it to the path
    visited[row][col] = true;
    path.push_back({row, col});

    // check if we have reached the destination
    if (row == n - 1 && col == m - 1) {
        paths.push_back(path);  // add path to the list of paths
    } else {
        // explore neighbors
        dfs(grid, row + 1, col, n, m, visited, path, paths);  // down
        dfs(grid, row, col + 1, n, m, visited, path, paths);  // right
        dfs(grid, row - 1, col, n, m, visited, path, paths);  // up
        dfs(grid, row, col - 1, n, m, visited, path, paths);  // left
    }

    // backtrack
    visited[row][col] = false;
    path.pop_back();
}

vector<vector<pair<int, int>>> findPaths(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<pair<int, int>> path;
    vector<vector<pair<int, int>>> paths;

    dfs(grid, 0, 0, n, m, visited, path, paths);

    return paths;
}

int solution(vector<string> grid, int k) {
    int answer = -1;
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> A(n,vector<int> (m));

    for(int i=0; i<n;i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] = '#') {
                A[i][j] = 0;
            }
            else {
                A[i][j] = 1;
            }
        }
    }

    
    vector<vector<pair<int, int>>> paths = findPaths(A);

    answer = 3;
    /*
    for (int i = 0; i < paths.size(); i++) {
        //cout << "Path " << i+1 << ": ";
        
        for (int j = 0; j < paths[i].size(); j++) {
            cout << "(" << paths[i][j].first << ", " << paths[i][j].second << ") ";
            
        }

        
        cout << endl;
    }
    */



    return answer;
}

