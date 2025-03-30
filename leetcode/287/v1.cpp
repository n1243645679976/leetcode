class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> si;
        for(int n: nums){
            if(si.find(n) != si.end()) return n;
            si.insert(n);
        }
        return -1;
    }
};