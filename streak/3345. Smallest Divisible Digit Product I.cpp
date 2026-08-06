class Solution {
public:
    int smallestNumber(int n, int t) {
        if (t == 0 ) return n;
        int temp_n = n;
        while(true){
            int digProduct = 1;
            int temp = temp_n;
            while(temp != 0){
                digProduct *= temp%10;
                temp = temp / 10;
            }
            // cout<<digProduct << endl;
            if(digProduct % t == 0){
                return temp_n;
            }
            temp_n++;
        }
        return -1;
    }
};