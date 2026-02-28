class Solution
{
public:
    int minOperations(string s, int k)
    {
        int n = s.size();
        int startingZero = 0;
        for (char &ch : s)
        {
            if (ch == '0')
            {
                startingZero++;
            }
        }
        if (startingZero == 0)
        {
            return 0;
        }
        //
        set<int> evenSet;
        set<int> oddSet;
        // values daal do set me
        for (int i = 0; i <= n; i++)
        {
            // iss pori string me itne hi zeros ho sakte ha
            if (i % 2 == 0)
            {
                evenSet.insert(i);
            }
            else
            {
                oddSet.insert(i);
            }
        }
        // value agai set me
        // now the vector to store the results that are required to reach certain number of zero
        vector<int> opZero(n + 1, -1);
        opZero[startingZero] = 0;
        // remove it from the set too
        if (startingZero % 2 == 0)
        {
            evenSet.erase(startingZero);
        }
        else
        {
            oddSet.erase(startingZero); // means we have checked this much count
        }
        // now DO the bfs
        queue<int> q;
        q.push(startingZero);
        while (!q.empty())
        {
            int z = q.front();
            q.pop();
            //
            int min_new_z = z + k - 2 * min(z, k);
            int max_new_z = z + k - 2 * max(0, k - n + z);
            //
            // check weather the min_new_z is even or odd
            set<int> &currSet = min_new_z % 2 == 0 ? evenSet : oddSet;
            auto it = currSet.lower_bound(min_new_z);
            while (it != currSet.end() && *it <= max_new_z)
            {
                int new_z = *it;
                if (opZero[new_z] == -1)
                {
                    opZero[new_z] = opZero[z] + 1;
                    if (new_z == 0)
                    {
                        return opZero[new_z];
                    }
                    q.push(new_z);
                }

                it = currSet.erase(it); // we have checked this one
            }
        }
        return -1;
    }
};