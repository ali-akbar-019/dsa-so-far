class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        // using bfs
        queue<int> q;
        vector<int> result;
        /// sab ko queue me daal do
        for (int i = 1; i <= 8; i++)
        {
            q.push(i);
        }
        //
        while (!q.empty())
        {
            int num = q.front();
            q.pop();
            // range me ha k nahi
            if (num >= low && num <= high)
            {
                result.push_back(num);
            }
            // ahiri digit nikalo
            int dig = num % 10;
            // agar to 9 ha to kya hi barhao ge bs conitnue karo is number ko
            if (dig == 9)
                continue;
            // dig ko aik aage barha do
            dig += 1;
            num = num * 10 + dig;
            q.push(num);
        }
        return result;
    }
};