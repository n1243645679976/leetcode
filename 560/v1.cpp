class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, su=0;
        unordered_map<int,int> usii;
        usii[0]++;
        for(int num:nums){
            su += num;
            ans += usii[su-k];
            usii[su]++;
        }
        return ans;
    }
};