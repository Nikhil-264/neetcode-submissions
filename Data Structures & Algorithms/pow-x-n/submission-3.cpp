class Solution {
public:
    double myPow(double x, int n) {
        int negPower = 0;
        if(n < 0) negPower = 1;
        n = abs(n);
        if(n == 0) return 1;
        if(x == 1) return 1;
        double ans = 1;
        double half = myPow(x, n / 2);
        if(n & 1){
            ans = x * half * half;
        }else{
            ans = half * half;
        }
        if(negPower){
            return 1 / ans;
        }
        return ans;
    }
};
