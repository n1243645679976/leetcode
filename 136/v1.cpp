class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0;
        for(int c:nums)a^=c;
        return a;
    }
};