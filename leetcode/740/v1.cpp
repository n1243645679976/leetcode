class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> counter;
        for(int n: nums){
            counter[n]++;
        }
        
        int maxnum = *std::max_element(nums.begin(), nums.end());
        int minnum = *std::min_element(nums.begin(), nums.end());
        vector<int> dp(maxnum+1, 0);
        dp[1] = counter[1];
        for(int i=2;i<=maxnum;++i){
            dp[i] = std::max(dp[i-1], dp[i-2] + counter[i] * i);
        }
        return dp[maxnum];
    }
};