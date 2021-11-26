class Solution {
public:
    bool isPrintable(vector<vector<int>>& tg) {
        int row = tg.size(), col = tg[0].size();
        vector<unordered_set<int>> topo(61);
        for(int color=1;color<61;++color){
            int l = 61, u = -1, r = -1, d = 61;
            for(int i=0;i<row;++i){
                for(int j=0;j<col;++j){
                    if(tg[i][j] == color){
                        l = min(i, l);
                        r = max(i, r);
                        d = min(j, d);
                        u = max(j, u);
                    }
                }
            }
            for(int i=l;i<=r;++i){
                for(int j=d;j<=u;++j){
                    if(tg[i][j] != color){
                        topo[color].insert(tg[i][j]);
                    }
                }
            }
        }
        // in_progress: 1, visited: 2
        vector<int> status(61, 0);
        for(int color=0;color<61;++color){
            if(!status[color] && find_cycle(color, topo, status)){
                return false;
            }
        }
        return true;
    }
private:
    bool find_cycle(int node, vector<unordered_set<int>>& topo, vector<int>& status){
        status[node] = 1;
        for(const int d: topo[node]){
            if(status[d] == 2) continue;
            if(status[d] == 1) return true;
            if(find_cycle(d, topo, status)) return true;
        }
        status[node] = 2;
        return false;
    }
};