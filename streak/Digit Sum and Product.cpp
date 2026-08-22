class Solution {
public:
    bool checkDivisibility(int n) {
        int digSum = 0;
        int digProd = 1;
        int temp = n;
        while(n != 0){
            int dig = n  % 10;
            digSum += dig;
            digProd *= dig;
            n = n/10;
        }
        return temp % (digSum + digProd) == 0 ? true : false;
    }
};