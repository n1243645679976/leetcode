class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(auto c: columnTitle){
            ans *= 26;
            ans += c - 64;
        }
        return ans;
    }
};