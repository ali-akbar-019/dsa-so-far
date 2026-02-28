class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        // ham ne check karna ha ka dono equal ha to ho sakta
        int n = word1.size();
        int m = word2.size();
        if (m != n)
        {
            return false; // agar equal hi nai to kaisey same ho sakte
        }

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        // frequency nikalo
        for (int i = 0; i < n; i++)
        {
            int idx1 = word1[i] - 'a';
            int idx2 = word2[i] - 'a';

            freq1[idx1]++;
            freq2[idx2]++;
        }

        // frequency mil gai
        // agar to frequency same ha then theek ha warna nai
        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] != 0 && freq2[i] != 0)
            {
                continue; // q k dono ki us index pe kch na kch ha
            }
            if (freq1[i] == 0 && freq2[i] == 0)
            {
                continue;
            }
            return false; // kch esa mil gaya k aik me ha or aik me nai ha
        }

        // ab sort karo or check karo k dono ki freq same ha k nai
        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));
        return freq1 == freq2;
    }
};