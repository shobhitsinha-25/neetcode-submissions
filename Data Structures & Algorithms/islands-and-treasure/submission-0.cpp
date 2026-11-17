
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        // Step 1: Push all treasure chests into the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int delrow[] = {0, 1, 0, -1};
        int delcol[] = {1, 0, -1, 0};

        // Step 2: Multi-source BFS
        while(!q.empty()) {

            auto [i, j] = q.front();
            q.pop();

            for(int x = 0; x < 4; x++) {

                int nrow = i + delrow[x];
                int ncol = j + delcol[x];

                // Check boundaries and whether the cell is unvisited land
                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == INT_MAX) {

                    grid[nrow][ncol] = grid[i][j] + 1;

                    q.push({nrow, ncol});
                }
            }
        }
    }
};
