class Solution {
public:
    int minOperations(vector<int>& nums) {
        int winl = 0, ind = 0, ans = 0;
        int maxdiff = nums.size(), ln;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        ln = nums.size();
        for(ind=0;ind<ln;ind++){
            while(nums[winl] <= nums[ind] - maxdiff){
                winl++;
            }
            ans = max(ind - winl + 1, ans);
        }
        return maxdiff - ans;
    }
};