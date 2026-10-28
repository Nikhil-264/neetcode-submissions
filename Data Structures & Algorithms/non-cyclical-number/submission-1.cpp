class Solution {
public:
    bool happy(int n, unordered_set<int> &st){
        if(n == 1) return true;
        if(st.find(n) != st.end()) return false;
        st.insert(n);
        int temp = n;
        int sum = 0;
        while(temp > 0){
            int rem = temp % 10;
            sum += rem * rem;
            temp = temp / 10;
        }   
        return happy(sum, st);
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        // st.insert(n);
        return happy(n, st);
    }
};
