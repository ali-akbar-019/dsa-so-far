class Solution
{
public:
    int reverseNum(int num)
    {
        int x = 0;
        while (num > 0)
        {
            x = x * 10 + num % 10; // last wala digit add hota rahe ga
            num = num / 10;
        }
        return x;
    }
    int minMirrorPairDistance(vector<int> &nums)
    {
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;
        // add all to the map
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int rev = reverseNum(nums[i]);
            if (mp.count(rev))
            {
                for (int j : mp[rev])
                {
                    if (i < j)
                    {
                        ans = min(ans, j - i);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

// this worked=.
class Solution
{
public:
    int reverseNum(int num)
    {
        int x = 0;
        while (num > 0)
        {
            x = x * 10 + num % 10;
            num = num / 10;
        }
        return x;
    }

    int minMirrorPairDistance(vector<int> &nums)
    {
        unordered_map<int, int> lastSeen; // reverse(nums[i]) -> last index i
        int ans = INT_MAX;

        for (int i = 0; i < (int)nums.size(); i++)
        {
            int rev = reverseNum(nums[i]);

            // Check if current number was stored as a reverse of some earlier element
            if (lastSeen.count(nums[i]))
            {
                ans = min(ans, i - lastSeen[nums[i]]);
            }

            // Store reverse -> index, so future elements matching this reverse find it
            lastSeen[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};