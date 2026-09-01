class Solution {
public:

    struct State {
        int r;
        int c;
        int energy;
        int mask;
        int moves;
    };

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        pair<int, int> start;

        // Give every litter cell an index
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    start = {i, j};
                }

                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        int allCollected = (1 << litterCount) - 1;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        queue<State> q;

        q.push({
            start.first,
            start.second,
            energy,
            0,
            0
        });

        visited[start.first][start.second][energy][0] = true;

        vector<vector<int>> directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty()) {

            State curr = q.front();
            q.pop();

            int r = curr.r;
            int c = curr.c;
            int e = curr.energy;
            int mask = curr.mask;
            int moves = curr.moves;

            // All litter collected
            if (mask == allCollected) {
                return moves;
            }

            for (auto& dir : directions) {

                int nr = r + dir[0];
                int nc = c + dir[1];

                // Boundary check FIRST
                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n) {
                    continue;
                }

                // Can't walk through obstacle
                if (classroom[nr][nc] == 'X') {
                    continue;
                }

                // Every move costs 1 energy
                if (e == 0) {
                    continue;
                }

                int newEnergy = e - 1;
                int newMask = mask;

                // Collect litter
                if (classroom[nr][nc] == 'L') {

                    int id = litterId[nr][nc];

                    newMask |= (1 << id);
                }

                // Reset energy
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                if (!visited[nr][nc][newEnergy][newMask]) {

                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask,
                        moves + 1
                    });
                }
            }
        }

        return -1;
    }
};