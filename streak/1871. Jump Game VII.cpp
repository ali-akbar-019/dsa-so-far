class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        //
        int n = s.length();
        vector<int> t(n, 0);
        // first index pe reach kar sakte ha ham
        t[0] = 1;

        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (i - minJump >= 0)
            {
                // new jo window me enter huwa
                count += t[i - minJump];
            }
            // remove from the window
            if (i - maxJump - 1 >= 0)
            {
                count -= t[i - maxJump - 1];
            }

            if (count > 0 && s[i] == '0')
            {
                t[i] = 1;
            }
        }
        return t[n - 1] > 0;
    }
};