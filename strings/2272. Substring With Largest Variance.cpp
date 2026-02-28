class Solution
{
public:
    int largestVariance(string s)
    {
        // first of all check k kon se characters hamari string me ha
        int n = s.size();
        int arr[26] = {0};
        for (char &ch : s)
        {
            arr[ch - 'a'] = 1; // means k ye character present ha
        }
        int ans = 0;
        //
        for (int i = 'a'; i <= 'z'; i++)
        {
            for (int j = 'a'; j <= 'z'; j++)
            {
                if (i == j)
                    continue;
                if (arr[i - 'a'] == 0 || arr[j - 'a'] == 0)
                {
                    continue; // means ye present hi nai ha
                }
                //
                // else hame mil gaya jon se do present ha
                char first = i;
                char second = j;
                int firstCount = 0;
                int secondCount = 0;
                bool pastSecond = 0; // pehle to nai dek leya ise kahi

                for (char &ch : s)
                {
                    if (ch == first)
                    {
                        firstCount++;
                    }
                    if (ch == second)
                    {
                        secondCount++;
                    }
                    //
                    if (secondCount > 0)
                    {
                        ans = max(ans, firstCount - secondCount);
                    }
                    else
                    {
                        ans = pastSecond ? max(ans, firstCount - 1) : ans; // means past present
                    }
                    //
                    if (secondCount > firstCount)
                    {
                        firstCount = 0;
                        secondCount = 0;
                        pastSecond = 1;
                    }
                }
            }
        }
        return ans;
    }
};