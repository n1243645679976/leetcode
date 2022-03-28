class Solution {
public:
    int lx;
    int ly;
    int ind;
    unordered_map<int, int> umii;
    void dfs(vector<vector<int>>& grid, int x, int y){
        if(grid[x][y] <= 0) return ;
        grid[x][y] = ind;
        umii[ind]++;
        if(x != lx - 1)
            dfs(grid, x+1, y);
        if(x != 0)
            dfs(grid, x-1, y);
        if(y != ly - 1)
            dfs(grid, x, y+1);
        if(y != 0)
            dfs(grid, x, y-1);
    }
    int largestIsland(vector<vector<int>>& grid) {
        lx = grid.size();
        ly = grid[0].size();
        ind = -1;
        set<int> been;
        for(int i=0;i<lx;i++){
            for(int j=0;j<ly;j++){
                if(grid[i][j] > 0){
                    dfs(grid, i, j);
                    ind--;
                }
            }
        }
        int ans = 0, temp;
        bool exist0 = false;
        for(int i=0;i<lx;i++){
            for(int j=0;j<ly;j++){
                if(grid[i][j] == 0){
                    exist0 = true;
                    temp = 0;
                    been = set<int>();
                    if(i != lx - 1){
                        if(been.find(grid[i+1][j]) == been.end()){
                            temp += umii[grid[i+1][j]];
                            been.insert(grid[i+1][j]);
                        }
                    }
                    if(i != 0){
                        if(been.find(grid[i-1][j]) == been.end()){
                            temp += umii[grid[i-1][j]];
                            been.insert(grid[i-1][j]);
                        }
                        
                    }
                    if(j != ly - 1){
                        if(been.find(grid[i][j+1]) == been.end()){
                            temp += umii[grid[i][j+1]];
                            been.insert(grid[i][j+1]);
                        }
                    }
                    if(j != 0){
                        if(been.find(grid[i][j-1]) == been.end()){
                            temp += umii[grid[i][j-1]];
                            been.insert(grid[i][j-1]);
                        }
                        
                    }
                    ans = max(temp+1, ans);
                }
            }
        }
        if(exist0)
            return ans;
        else
            return lx * ly;
    }
};