class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // first convert to string
            string currNumber = to_string(nums[i]);
            for (int j = 0; j < currNumber.size(); j++)
            {
                int curr = currNumber[j] - '0';
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
// optimized
class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        for (auto num : nums)
        {
            vector<int> temp;
            while (num != 0)
            {
                int dig = num % 10;
                num /= 10;
                temp.push_back(dig);
            }
            // reverse and addd
            for (int j = temp.size() - 1; j >= 0; j--)
            {
                ans.push_back(temp[j]);
            }
        }
        return ans;
    }
};
