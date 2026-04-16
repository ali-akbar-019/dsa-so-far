class Solution
{
public:
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
    {
        // first of all find the circular distances of all and store them
        int n = nums.size();
        int qn = queries.size();
        //
        vector<int> minDistances(n, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            int target = nums[i];
            for (int j = 0; j < n; j++)
            {
                if (nums[j] == target && i != j)
                {
                    int diff = abs(j - i);
                    int dist = min(diff, n - diff);
                    minDistances[i] = min(minDistances[i], dist);
                }
            }
            // check
            if (minDistances[i] == INT_MAX)
            {
                minDistances[i] = -1;
            }
        }
        // now check the queries
        vector<int> result;
        for (int i = 0; i < qn; i++)
        {
            int idx = queries[i];
            result.push_back(minDistances[idx]);
        }
        return result;
    }
};

class Solution
{
public:
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
    {
        // first of all find the circular distances of all and store them
        int n = nums.size();
        int qn = queries.size();
        //
        // use the map approach
        unordered_map<int, vector<int> > pairMap;
        for (int i = 0; i < n; i++)
        {
            pairMap[nums[i]].push_back(i);
        }
        vector<int> minDist(n, -1);
        // now check
        for (auto &p : pairMap)
        {
            vector<int> v = p.second;
            int m = v.size();
            if (m == 1)
            {
                continue;
            }
            //
            for (int i = 0; i < m; i++)
            {
                int curr = v[i];
                int prev = v[(i - 1 + m) % m];
                int next = v[(i + 1) % m];
                int diff1 = abs(curr - prev);
                int diff2 = abs(curr - next);
                int d1 = min(diff1, n - diff1);
                int d2 = min(diff2, n - diff2);
                minDist[curr] = min(d1, d2);
            }
        }
        // now check the queries
        vector<int> result;
        for (int i = 0; i < qn; i++)
        {
            int idx = queries[i];
            result.push_back(minDist[idx]);
        }
        return result;
    }
};