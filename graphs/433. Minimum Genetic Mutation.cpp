class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        // normal BFS se ho jaye ga ye
        unordered_set<string> st(bank.begin(), bank.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(startGene);
        visited.insert(startGene);
        // to keep track of the number of mutations
        int level = 0;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                string curr = q.front();
                q.pop();
                if (curr == endGene)
                    return level;
                // abb ACGT
                for (char ch : "ACGT")
                {
                    for (int i = 0; i < curr.length(); i++)
                    {
                        string ngbr = curr;
                        ngbr[i] = ch;
                        if (visited.count(ngbr) != 0 || st.find(ngbr) == st.end())
                            continue;
                        q.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};