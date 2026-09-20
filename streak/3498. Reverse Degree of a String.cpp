class Solution
{
public:
    int reverseDegree(string s)
    {
        int arr[26];
        for (int i = 0; i < 26; i++)
        {
            arr[i] = 26 - i;
        }
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';
            sum += (arr[idx] * (i + 1));
        }
        return sum;
    }
};