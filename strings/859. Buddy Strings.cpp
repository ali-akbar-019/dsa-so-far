class Solution
{
public:
    bool checkFreq(string s)
    {
        int arr[26] = {0};
        for (char &ch : s)
        {
            arr[ch - 'a']++;
            if (arr[ch - 'a'] > 1)
            {
                return true;
            }
        }
        return false;
    }
    bool buddyStrings(string s, string goal)
    {
        if (s.size() != goal.size())
        {
            return false; // agar to lenght hi same ni then swap kar k b same ni ho sakte
        }
        //
        if (s == goal)
        {
            // agar same ha then false but agar kio repeat ho raha then use hi swap kar k kaho k true
            return checkFreq(s);
        }
        // ab swaping karo
        // check karo kitne ghalat ha , do hone chahie q k aik swap se bas do badal sakte
        vector<int> indices;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != goal[i])
            {
                indices.push_back(i);
            }
        }
        //
        if (indices.size() != 2)
        {
            return false;
        }
        swap(s[indices[0]], s[indices[1]]);
        return s == goal;
    }
};