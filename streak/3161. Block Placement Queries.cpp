// that i made first
class Solution
{
public:
    vector<bool> getResults(vector<vector<int>> &queries)
    {
        int n = queries.size();
        int maxDistInProblem = 0;
        for (auto &q : queries)
        {
            maxDistInProblem = max(maxDistInProblem, q[1]); // har aik me 1 index ho ga hi ho ga
        }
        // ab max hamare pass ha to aik array bana lo
        vector<bool> isMarkedByQueryType1(maxDistInProblem + 1, false);
        // ab har query ko check karo
        vector<bool> result;
        for (auto &q : queries)
        {
            int type = q[0];
            if (type == 1)
            {
                int toMark = q[1];
                // then we have to mark
                isMarkedByQueryType1[toMark] = true;
            }
            else
            {
                // type 2 hai
                // range nikalo
                int startOfRange = 0;
                int endOfRange = q[1];
                int sizeOfBlock = q[2];
                int maxWeCanPlaceInRange = 0;
                int prevIndex = 0;
                for (int i = startOfRange; i <= endOfRange; i++)
                {
                    if (prevIndex == 0 && isMarkedByQueryType1[i] == true)
                    {
                        maxWeCanPlaceInRange = abs(i - prevIndex);
                        prevIndex = i;
                    }
                    if (prevIndex != 0 && isMarkedByQueryType1[i] == true)
                    {
                        maxWeCanPlaceInRange = max(maxWeCanPlaceInRange, abs(i - prevIndex));
                        prevIndex = i;
                    }
                }
                maxWeCanPlaceInRange = max(maxWeCanPlaceInRange, abs(endOfRange - prevIndex));
                if (maxWeCanPlaceInRange >= sizeOfBlock)
                {
                    result.push_back(true);
                }
                else
                {
                    result.push_back(false);
                }
            }
        }
        return result;
    }
};

// brute force fixed
class Solution
{
public:
    vector<bool> getResults(vector<vector<int>> &queries)
    {

        int mx = 0;
        for (auto &q : queries)
        {
            mx = max(mx, q[1]);
        }

        vector<bool> obstacle(mx + 1, false);
        vector<bool> ans;

        for (auto &q : queries)
        {

            if (q[0] == 1)
            {
                obstacle[q[1]] = true;
            }
            else
            {

                int x = q[1];
                int sz = q[2];

                int maxGap = 0;
                int prevObstacle = 0;

                bool firstObstacleFound = false;

                for (int i = 0; i <= x; i++)
                {

                    if (obstacle[i])
                    {

                        if (!firstObstacleFound)
                        {
                            maxGap = max(maxGap, i);
                            firstObstacleFound = true;
                        }
                        else
                        {
                            maxGap = max(maxGap, i - prevObstacle);
                        }

                        prevObstacle = i;
                    }
                }

                if (firstObstacleFound)
                {
                    maxGap = max(maxGap, x - prevObstacle);
                }
                else
                {
                    maxGap = x;
                }

                ans.push_back(maxGap >= sz);
            }
        }

        return ans;
    }
};

class Solution
{
public:
    vector<bool> getResults(vector<vector<int>> &queries)
    {

        // obstacles sorted order mein rakhenge
        set<int> obs;

        // har gap store karenge (prev -> current obstacle distance)
        multiset<int> gaps;

        vector<bool> ans;

        for (auto &q : queries)
        {

            if (q[0] == 1)
            {
                // -------------------------
                // TYPE 1: obstacle add karna
                // -------------------------

                int x = q[1];

                // insert kar diya obstacle
                auto it = obs.insert(x).first;

                int left = 0;
                int right = 0;
                bool hasLeft = false, hasRight = false;

                // left neighbor nikaalo
                if (it != obs.begin())
                {
                    auto l = it;
                    l--;
                    left = *l;
                    hasLeft = true;
                }

                // right neighbor nikaalo
                auto r = it;
                r++;
                if (r != obs.end())
                {
                    right = *r;
                    hasRight = true;
                }

                // agar dono side exist karte hain
                if (hasLeft && hasRight)
                {
                    // purana gap remove karo (left -> right)
                    gaps.erase(gaps.find(right - left));

                    // ab 2 naye gaps add honge
                    gaps.insert(x - left);
                    gaps.insert(right - x);
                }
                else if (hasLeft)
                {
                    // sirf left side hai
                    gaps.insert(x - left);
                }
                else if (hasRight)
                {
                    // sirf right side hai
                    gaps.insert(right - x);
                }
                else
                {
                    // first obstacle
                    gaps.insert(x);
                }
            }

            else
            {
                // -------------------------
                // TYPE 2: query
                // -------------------------

                int x = q[1];
                int sz = q[2];

                int prev = 0;
                int maxGap = 0;

                // sirf x tak obstacles consider karo
                for (auto it = obs.begin(); it != obs.end(); it++)
                {
                    if (*it > x)
                        break;

                    // gap nikal liya prev se current tak
                    maxGap = max(maxGap, *it - prev);
                    prev = *it;
                }

                // last segment (last obstacle -> x)
                maxGap = max(maxGap, x - prev);

                // answer
                ans.push_back(maxGap >= sz);
            }
        }

        return ans;
    }
};

// accepetd solution
class Solution
{
public:
    vector<int> seg;
    void update(int idx, int val, int p, int l, int r)
    {
        if (l == r)
        {
            seg[p] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
        {
            update(idx, val, p << 1, l, mid);
        }
        else
        {
            update(idx, val, p << 1 | 1, mid + 1, r);
        }
        seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
    }

    int query(int L, int R, int p, int l, int r)
    {
        if (L <= l && r <= R)
        {
            return seg[p];
        }
        int mid = (l + r) >> 1;
        int res = 0;
        if (L <= mid)
        {
            res = max(res, query(L, R, p << 1, l, mid));
        }
        if (R > mid)
        {
            res = max(res, query(L, R, p << 1 | 1, mid + 1, r));
        }
        return res;
    }

    vector<bool> getResults(vector<vector<int>> &queries)
    {
        int mx = 50000;
        seg.resize(mx << 2);
        set<int> st = {0, mx};
        update(mx, mx, 1, 0, mx);
        vector<bool> ans;

        for (auto &q : queries)
        {
            if (q[0] == 1)
            {
                int x = q[1];
                auto it = st.upper_bound(x);
                int r = *it;
                int l = *prev(it);
                update(x, x - l, 1, 0, mx);
                update(r, r - x, 1, 0, mx);
                st.insert(x);
            }
            else
            {
                int x = q[1];
                int sz = q[2];
                auto it = st.upper_bound(x);
                --it;
                int pre = *it;
                int max_space = query(0, pre, 1, 0, mx);
                max_space = max(max_space, x - pre);
                ans.push_back(max_space >= sz);
            }
        }
        return ans;
    }
};