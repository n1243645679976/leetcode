struct vv{
    bool operator()(const vector<int>& a, const vector<int>& b){
        return a[1] - a[0] < b[1] - b[0];
    }
};
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), vv());
        int ans = 0, ls = costs.size();
        for(int i=0;i < ls / 2;i++){
            ans += costs[i][1];
        }
        for(int i = ls/2;i < ls;i++){
            ans += costs[i][0];
        }
        return ans;
    }
};