class Solution
{
public:
    typedef long long ll;
    int M = 1e9 + 7;
    ll binPow(ll a, ll e)
    {
        // if bit is set then only mult else no
        ll res = 1;
        while (e > 0)
        {
            if (e & 1)
            {
                // bit is set then
                res = (res * a) % M;
            }
            a = (a * a) % M;
            e >>= 1;
        }
        return res;
    }
    ll mdInv(ll v)
    {
        return binPow(v, M - 2);
    }
    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        // this time the constraints are change
        // well adha code we'll use the bruteforce approach and adha will be the prefix multiplication
        // if jo hamare pass k ki value is less than sqrt(n) then we have to use the prefix mult appraoch
        /// else using the bruteforce will still work
        //
        int n = nums.size();
        int limit = sqrt(n);
        unordered_map<int, vector<vector<int>>> mp;
        for (auto &q : queries)
        {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            //
            if (k >= limit)
            {
                for (int idx = l; idx <= r; idx += k)
                {
                    nums[idx] = ((ll)nums[idx] * v) % M;
                }
            }
            else
            {
                mp[k].push_back(q);
            }
        }
        // process the k less than limit , smaller k
        for (auto &[k, qrs] : mp)
        {
            vector<ll> diff(n, 1);
            for (auto &q : qrs)
            {
                ll l = q[0];
                ll r = q[1];
                ll k = q[2];
                ll v = q[3];
                // first diff[l] ko v se mult kar do
                diff[l] = (diff[l] * v) % M;
                // steps
                int last = l + ((r - l) / k) * k;
                int next = last + k;
                if (next < n)
                {
                    diff[next] = (diff[next] * mdInv(v)) % M;
                }
            }
            // prefix array to get all multipliers
            for (int i = 0; i < n; i++)
            {
                if (i >= k)
                {
                    diff[i] = (diff[i - k] * diff[i]) % M;
                }
                nums[i] = ((ll)nums[i] * diff[i]) % M;
            }
        }
        // xor
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res = res ^ nums[i];
        }
        return res;
    }
};