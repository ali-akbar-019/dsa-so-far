class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int index = 0;
        int n = chars.size();
        int i = 0;
        while (i < n)
        {
            char current_character = chars[i];
            int count = 0;
            while (i < n && chars[i] == current_character)
            {
                i++;
                count++;
            }
            //
            chars[index] = current_character;
            index++;
            if (count > 1)
            {

                string count_str = to_string(count);
                for (int i = 0; i < count_str.size(); i++)
                {
                    chars[index] = count_str[i];
                    index++;
                }
            }
            //
        }
        return index;
    }
};