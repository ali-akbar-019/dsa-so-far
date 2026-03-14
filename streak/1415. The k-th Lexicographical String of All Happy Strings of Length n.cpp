class Solution
{
public:
    void solve(int n, string curr, vector<string> &res)
    {
        if (curr.length() == n)
        {
            res.push_back(curr);
            return;
        }
        //
        for (int ch = 'a'; ch <= 'c'; ch++)
        {
            if (!curr.empty() && ch == curr.back())
            {
                continue;
            }
            //
            curr.push_back(ch);
            solve(n, curr, res);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k)
    {
        vector<string> result;
        string curr = "";
        solve(n, curr, result);
        if (result.size() < k)
        {
            return "";
        }
        //
        return result[k - 1];
    }
};

class Solution
{
public:
    void solve(int n, string &curr, int &count, int &k, string &res)
    {
        if (curr.length() == n)
        {
            count++;
            if (count == k)
            {
                res = curr;
            }
            return;
        }

        if (!res.empty())
            return;

        for (char ch = 'a'; ch <= 'c'; ch++)
        {
            if (!curr.empty() && ch == curr.back())
                continue;

            curr.push_back(ch);
            solve(n, curr, count, k, res);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k)
    {
        string result = "";
        string curr = "";
        int count = 0;

        solve(n, curr, count, k, result);
        return result;
    }
};

//
class Solution
{
public:
    void solve(int n, string &curr, int &count, int &k, string &res)
    {
        if (curr.length() == n)
        {
            count++;
            if (count == k)
            {
                res = curr;
            }
            return;
        }

        if (!res.empty())
            return;

        for (char ch = 'a'; ch <= 'c'; ch++)
        {
            if (!curr.empty() && ch == curr.back())
                continue;

            curr.push_back(ch);
            solve(n, curr, count, k, res);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k)
    {
        string result = "";
        string curr = "";
        int count = 0;

        solve(n, curr, count, k, result);
        return result;
    }
};