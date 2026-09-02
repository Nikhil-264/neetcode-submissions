class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(m < n) return false; 

        vector<int> forS1(26, 0);
        vector<int> forS2(26, 0);

        for(int i = 0; i < n; i++){
            forS1[s1[i] - 'a']++;
        }

        int i = 0;
        for(i = 0; i < n - 1; i++){
            forS2[s2[i] - 'a']++;
        }
        int l = 0;
        while(i < m){
            forS2[s2[i] - 'a']++;

            //check both vectors
            if(forS1 == forS2) return true;

            forS2[s2[l] - 'a']--;
            
            l++;
            i++;
        }
        return false;
    }
};
