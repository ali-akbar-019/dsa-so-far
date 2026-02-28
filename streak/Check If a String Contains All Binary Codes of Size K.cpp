class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        int n = s.length();
        int codes = 1 << k; // pow(2,k)
        unordered_set<string> st;
        for (int i = k; i <= n; i++)
        {
            string sub = s.substr(i - k, k); // pechli do length ki sub array
            if (!(st.count(sub)))
            {
                st.insert(sub);
                codes--;
            }
            if (codes == 0)
            {
                return true;
            }
        }
        return false;
    }
};