class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < walls.size(); i++) {
            int _i = walls[i][0];
            int _j = walls[i][1];
            if (_i >= 0 && _i < visited.size() && _j >= 0 &&
                _j < visited[0].size()) {
                visited[_i][_j] = -1;
            }
        }

       for(int k = 0; k < guards.size(); k++) {
            // auto p = q.front();
            int row = guards[k][0];
            int col = guards[k][1];
            visited[row][col] = 1;
            // checking above rows where guard can see
            for (int i = row - 1; i >= 0; i--) {
                if (visited[i][col] == -1) {
                    break;
                } else if (visited[i][col] != 1) {
                    visited[i][col] = 1;
                }
            }

            for (int i = row + 1; i < m; i++) {
                if (visited[i][col] == -1) {
                    break;
                } else if (visited[i][col] != 1) {
                    visited[i][col] = 1;
                }
            }

            for (int i = col - 1; i >= 0; i--) {
                if (visited[row][i] == -1) {
                    break;
                } else if (visited[row][i] != 1) {
                    visited[row][i] = 1;
                }
            }

            for (int i = col + 1; i < n; i++) {
                if (visited[row][i] == -1) {
                    break;
                } else if (visited[row][i] != 1) {
                    visited[row][i] = 1;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};