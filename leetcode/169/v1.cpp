class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> uoii;
        int max=0, ans=0;
        for(int c:nums) ++uoii[c];
        for(auto& it: uoii){
            if(it.second > max){
                max = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};