class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        int n = asteroids.size();
        // sort kar do
        sort(asteroids.begin(), asteroids.end());
        /// now aik hi pass me check kar lo
        long long currMass = mass;
        for (int i = 0; i < n; i++)
        {
            if (currMass >= asteroids[i])
            {
                currMass += asteroids[i];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};