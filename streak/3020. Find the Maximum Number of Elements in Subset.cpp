// it passes 700 test cases
class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int n = nums.size();
        // build the freq map
        unordered_map<int, int> freq;
        for (auto &num : nums)
        {
            freq[num] += 1;
        }
        //
        int result = 0;
        // iterate over the map
        for (auto &[x, cnt] : freq)
        {
            int len = 1;
            // handle one
            if (x == 1)
            {
                //
                result = max(result, cnt - (cnt % 2 == 0));
                continue;
            }
            // handle others
            long long v = x;
            while (true)
            {
                long long r = sqrtl(v);
                if (1LL * r * r != v)
                    break;
                auto it = freq.find(r);

                if (it == freq.end() || it->second < 2)
                    break;
                //
                len += 2;
                v = r;
            }
            result = max(result, len);
        }
        return result;
    }
};
//

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {

        unordered_map<long long, int> freq;

        for (int num : nums)
            freq[num]++;

        int answer = 0;

        // Special handling for 1
        if (freq.count(1))
        {
            answer = (freq[1] % 2 == 0) ? freq[1] - 1 : freq[1];
            freq.erase(1);
        }

        for (auto &[start, count] : freq)
        {

            long long current = start;
            int currentLength = 0;

            while (freq.contains(current) && freq[current] >= 2)
            {
                currentLength += 2;
                current *= current;
            }

            if (freq.contains(current))
            {
                // Current value can act as the center
                currentLength++;
            }
            else
            {
                // Last pair cannot be completed
                currentLength--;
            }

            answer = max(answer, currentLength);
        }

        return answer;
    }
};