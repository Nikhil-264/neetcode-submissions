class Solution {
    int sumOfS(int n){
        int output = 0;
        while(n != 0){
            output += (n % 10) * (n % 10);
            n /= 10;
        }
        return output;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = sumOfS(n);

        while(slow != fast){
            fast = sumOfS(fast);
            fast = sumOfS(fast);
            slow = sumOfS(slow);
        }
        return fast == 1;
    }
};
