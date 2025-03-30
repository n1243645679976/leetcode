class Solution {
public:
    void dfs(int cand_ind, int now, vector<int>& cand, int tar, vector<vector<int>>& ans, vector<int> temp){
        if(now > tar){
            return;
        }
        if(now == tar){
            ans.push_back(temp);
        }
        for(int i=cand_ind; i<cand.size();++i){
            temp.push_back(cand[i]);
            dfs(i, now+cand[i], cand, tar, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0, 0, candidates, target, ans, temp);
        return ans;
    }
};