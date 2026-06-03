class Solution
{
public:
    int earliestFinishTime(vector<int> &landStartTime,
                           vector<int> &landDuration,
                           vector<int> &waterStartTime,
                           vector<int> &waterDuration)
    {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                // Land -> Water
                int landFinish = landStartTime[i] + landDuration[i];

                int waterStart =
                    max(landFinish, waterStartTime[j]);

                int waterFinish =
                    waterStart + waterDuration[j];

                ans = min(ans, waterFinish);

                // Water -> Land
                int waterFinish2 =
                    waterStartTime[j] + waterDuration[j];

                int landStart =
                    max(waterFinish2, landStartTime[i]);

                int landFinish2 =
                    landStart + landDuration[i];

                ans = min(ans, landFinish2);
            }
        }

        return ans;
    }
};