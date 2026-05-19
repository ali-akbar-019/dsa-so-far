class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        // simple bfs in here
        // left jao
        // right jao
        // and same elements wale deko
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        vector<bool> visited(n, false);
        // fill the map
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0); // indexes store kare ge ham
        visited[0] = true;
        int steps = 0;

        while (!q.empty())
        {
            int currentLevelN = q.size();
            while (currentLevelN--)
            {
                //
                int idx = q.front();
                q.pop();
                // ab ham ne dekhna ha k ham kahi last pe to nahi agaye
                if (idx == n - 1)
                {
                    return steps;
                }
                // ab left right ddeko
                int left = idx - 1;
                int right = idx + 1;
                if (left >= 0 && !visited[left])
                {
                    q.push(left);
                    visited[left] = true;
                }
                if (right < n && !visited[right])
                {
                    q.push(right);
                    visited[right] = true;
                }
                // ab same elements k leye deko
                for (auto &i : mp[arr[idx]])
                {
                    if (!visited[i])
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
                // ab remove b kar do is element ki entry map se q k sari to dal di ham ne
                mp.erase(arr[idx]);
            }
            steps++;
        }
        return steps;
    }
};