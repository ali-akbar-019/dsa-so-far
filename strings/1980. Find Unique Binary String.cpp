class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(stoi(nums[i], 0, 2)); // convert binary to string
        }
        //
        string result;
        for (int number = 0; number < pow(2, n) - 1; number++)
        {
            if (st.find(number) == st.end())
            {
                result = bitset<16>(number).to_string();
                // convert to binary
                return result.substr(16 - n, n);
            }
        }
        return "";
    }
};
class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();
        string result(n, '0');
        for (int i = 0; i < n; i++)
        {
            result[i] = nums[i][i] == '1' ? '0' : '1'; // flip diagnol bits
        }
        return result;
    }
};