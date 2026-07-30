class Solution
{
public:
    long long nCr(int n, int r, int k)
    {
        // nCr == nC(n-r)
        r = min(r, n - r);
        long long result = 1;
        for (int i = 1; i <= r; i++)
        {
            result = result * (n - r + i) / i; //
            if (result >= k)
                return k;
        }
        return result;
    }
    string smallestPalindrome(string s, int k)
    {
        int n = s.length();
        char mid = ' ';
        if (n % 2 == 1)
        {
            mid = s[n / 2];
        }
        // ab store karo count
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++)
        {
            // skip kar do agar odd ha mid wale ko
            if (n % 2 == 1 && i == n / 2)
                continue;
            count[s[i] - 'a']++;
        }
        // ab half kar do q k ham half k leye chek kare ge
        for (int i = 0; i < 26; i++)
        {
            count[i] = count[i] / 2;
        }
        //
        string halfResult = "";
        int half = n / 2;
        string halfRes = "";
        for (int i = 0; i < half; i++)
        {
            // lets try to fix
            bool isPlaced = false;
            for (int j = 0; j < 26; j++)
            {
                if (count[j] > 0)
                {
                    count[j] -= 1;
                    long long ways = 1;
                    int letters = 0;
                    for (int c = 0; c < 26; c++)
                    {
                        letters += count[c];
                    }
                    // ncr
                    for (int c = 0; c < 26; c++)
                    {
                        if (count[c] > 0)
                        {
                            ways *= nCr(letters, count[c], k);
                            letters -= count[c];
                        }
                        if (ways >= k)
                            break;
                    }
                    if (ways >= k)
                    {
                        // means solution ider hi ha
                        halfRes.push_back(j + 'a');
                        isPlaced = true;
                        break;
                    };
                    // agar na ho paye
                    k -= ways;
                    count[j] += 1;
                }
            }
            if (isPlaced == false)
                return "";
        }
        string rev = halfRes;
        reverse(begin(rev), end(rev));
        if (mid != ' ')
        {
            halfRes.push_back(mid);
        }
        return halfRes + rev;
    }
};