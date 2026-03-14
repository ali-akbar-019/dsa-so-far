class Solution
{
public:
    typedef long long ll;

    bool check(int mH, ll mid, vector<int> &workerTimes)
    {
        ll h = 0;
        for (int &t : workerTimes)
        {
            h += (ll)(sqrt(2.0 * mid / (double)t + 0.25) - 0.5);
            if (h >= mH)
                return true;
        }
        return h >= mH;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes)
    {
        ll maxTime = *max_element(begin(workerTimes), end(workerTimes));
        ll l = 1;
        ll r = (ll)maxTime * mountainHeight * (mountainHeight + 1) / 2;
        ll result = 0;

        while (l <= r)
        {
            ll mid = (l + r) >> 1;
            if (check(mountainHeight, mid, workerTimes))
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }
};