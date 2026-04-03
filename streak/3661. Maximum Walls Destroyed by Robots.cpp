class Solution
{
public:
    int maxWalls(vector<int> &robots, vector<int> &d, vector<int> &walls)
    {
        int n = robots.size();

        // Store robots as {position, distance}
        vector<array<int, 2>> x(n);
        for (int i = 0; i < n; i++)
        {
            x[i] = {robots[i], d[i]};
        }

        // Sort robots and walls to get everything in order
        sort(x.begin(), x.end());
        sort(walls.begin(), walls.end());

        // Dummy robot to avoid boundary checks
        x.push_back({(int)1e9, 0});

        // Function to count walls in range [l, r]
        auto query = [&](int l, int r) -> int
        {
            if (l > r)
                return 0;
            auto it1 = upper_bound(walls.begin(), walls.end(), r);
            auto it2 = lower_bound(walls.begin(), walls.end(), l);
            return it1 - it2;
        };

        // dp[i][0] = i-th robot shoots LEFT
        // dp[i][1] = i-th robot shoots RIGHT
        vector<array<int, 2>> dp(n);

        // Base case (i = 0)- shooting left
        dp[0][0] = query(x[0][0] - x[0][1], x[0][0]);

        // shooting right
        if (n > 1)
        {
            dp[0][1] = query(
                x[0][0],
                min(x[1][0] - 1, x[0][0] + x[0][1]));
        }
        else
        {
            dp[0][1] = query(x[0][0], x[0][0] + x[0][1]);
        }

        // DP transitions
        for (int i = 1; i < n; i++)
        {

            // Case 1: shoot RIGHT
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) +
                       query(
                           x[i][0],
                           min(x[i + 1][0] - 1, x[i][0] + x[i][1]));

            // Case 2: shoot LEFT (no overlap with previous LEFT)
            dp[i][0] = dp[i - 1][0] +
                       query(
                           max(x[i][0] - x[i][1], x[i - 1][0] + 1),
                           x[i][0]);

            // Case 3: shoot LEFT but previous was RIGHT (handle overlap)
            int leftStart = max(x[i][0] - x[i][1], x[i - 1][0] + 1);
            int leftEnd = x[i][0];

            int overlapStart = leftStart;
            int overlapEnd = min(x[i - 1][0] + x[i - 1][1], x[i][0] - 1);

            int res = dp[i - 1][1] + query(leftStart, leftEnd) - query(overlapStart, overlapEnd);

            dp[i][0] = max(dp[i][0], res);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
class Solution
{
public:
    int maxWallsDestroyed(vector<int> &robots, vector<int> &distance, vector<int> &walls)
    {

        int n = robots.size();

        // ── STEP 1: Pair each robot with its shooting range ──────────────────
        // We keep (position, range) together so they don't get separated when sorting
        vector<pair<int, int>> bots(n);
        for (int i = 0; i < n; i++)
            bots[i] = {robots[i], distance[i]};

        // ── STEP 2: Sort robots left to right by position ────────────────────
        // Now bots[i-1] is always the nearest robot to the LEFT
        // and bots[i+1] is always the nearest robot to the RIGHT
        sort(bots.begin(), bots.end());

        // ── STEP 3: Sort walls left to right ─────────────────────────────────
        // Sorting walls lets us use binary search to quickly find
        // which walls fall inside any range [a, b]
        vector<int> sw = walls;
        sort(sw.begin(), sw.end());
        int m = sw.size();

        // ── STEP 4: Create a checklist for walls ──────────────────────────────
        // hit[j] = true means wall j can be destroyed by at least one robot
        // We start with everything false (no wall destroyed yet)
        vector<bool> hit(m, false);

        // ── STEP 5: Go through every robot ───────────────────────────────────
        for (int i = 0; i < n; i++)
        {

            long long pos = bots[i].first; // this robot's position
            long long d = bots[i].second;  // this robot's shooting range

            // ── LEFT SHOT ────────────────────────────────────────────────────
            // Ideally covers [pos - d, pos]
            // BUT the robot directly to our left BLOCKS the bullet
            // So the bullet can only start just after that left neighbor

            long long leftStart;
            if (i > 0)
                leftStart = (long long)bots[i - 1].first + 1; // just past the left neighbor
            else
                leftStart = 0; // no left neighbor, bullet can go all the way

            // actual left range = from max(pos-d, leftStart) to pos
            long long L = max(pos - d, leftStart);
            long long R = pos;

            // find all walls inside [L, R] using binary search
            // lower_bound → index of first wall >= L
            // upper_bound → index of first wall >  R, so we go one before it
            int lo = (int)(lower_bound(sw.begin(), sw.end(), (int)L) - sw.begin());
            int hi = (int)(upper_bound(sw.begin(), sw.end(), (int)R) - sw.begin()) - 1;

            // mark every wall in this range as reachable
            for (int j = lo; j <= hi; j++)
                hit[j] = true;

            // ── RIGHT SHOT ───────────────────────────────────────────────────
            // Ideally covers [pos, pos + d]
            // BUT the robot directly to our right BLOCKS the bullet
            // So the bullet can only reach just before that right neighbor

            long long rightEnd;
            if (i < n - 1)
                rightEnd = (long long)bots[i + 1].first - 1; // just before the right neighbor
            else
                rightEnd = 2e9; // no right neighbor, bullet can go all the way

            // actual right range = from pos to min(pos+d, rightEnd)
            L = pos;
            R = min(pos + d, rightEnd);

            // same binary search — find all walls inside [L, R]
            lo = (int)(lower_bound(sw.begin(), sw.end(), (int)L) - sw.begin());
            hi = (int)(upper_bound(sw.begin(), sw.end(), (int)R) - sw.begin()) - 1;

            // mark every wall in this range as reachable
            for (int j = lo; j <= hi; j++)
                hit[j] = true;
        }

        // ── STEP 6: Count how many walls were marked as reachable ─────────────
        return (int)count(hit.begin(), hit.end(), true);
    }
};