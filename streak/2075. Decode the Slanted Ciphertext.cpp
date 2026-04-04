class Solution
{
public:
    string decodeCiphertext(string encodedText, int rows)
    {
        int l = encodedText.length();
        int columns = l / rows; // kitna text ha or kitne rows ha to columns ajaye ge
        string orignalText;
        // T = O(l)
        for (int col = 0; col < columns; col++)
        {
            for (int j = col; j < l; j += (columns + 1))
            {
                orignalText += encodedText[j];
            }
        }
        // remove the trailing spaces
        while (!orignalText.empty() && orignalText.back() == ' ')
        {
            orignalText.pop_back();
        }
        return orignalText;
    }
};