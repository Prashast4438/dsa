We start with distance = 1, not 0, because the problem
        // asks for the number of cells in the path (including both start and end),
        // not just the number of moves.
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // If the start or end is blocked
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        // Distance matrix
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;

        // Regular queue: {distance, {row, col}}
        queue<pair<int, pair<int, int>>> q;
        // push: q.push({distance, {row, col}});
 
        q.push({1, {0, 0}});  // Starting point with distance 1

        // 8 directions (top-left, top, top-right, right, bottom-right, bottom, bottom-left, left)
        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == n - 1)
                return d;

            // Explore all 8 possible directions
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Check if valid and a shorter path is found
                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 && d + 1 < dist[nr][nc]) {
                    dist[nr][nc] = d + 1;
                    q.push({d + 1, {nr, nc}});
                }
            }
        }

        return -1; // No path found
    }
};
