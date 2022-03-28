class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> vpii;
        int lm = mat.size();
        for(int i=0;i<lm;i++){
            vpii.push_back(pair<int, int>(std::accumulate(mat[i].begin(), mat[i].end(), 0), i));
        }
        sort(vpii.begin(), vpii.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vpii[i].second);
        }
        return ans;
    }
};