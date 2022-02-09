class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> q;
        for(int num: nums){
            q[num] += 1;
        }
        int ans = 0;
        if(k == 0){
            for(auto i: q){
                if(i.second > 1) ans += 1;
            }
        }
        else{
            for(auto i: q){
                if(i.second) ans += (q.count(i.first+k)>0);
            }
        }
        return ans;
    }
};