class Solution
{
public:
    int towerOfHanoi(int n, int from, int to, int aux)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            // cout<<"move dist "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
            return 1;
        }
        //
        int count = 0;
        count += towerOfHanoi(n - 1, from, aux, to);
        // us k bad jo last wala ha use from se utha k to pe rakh do
        // cout<<"move dist "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
        count += 1;
        //
        count += towerOfHanoi(n - 1, aux, to, from);
        return count;
    }
};