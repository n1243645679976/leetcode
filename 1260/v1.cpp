
class Solution {
public:
    int gcd(int a, int b){
        if(a==0) return b;
        return gcd(b%a, a);
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int allsize = grid.size() * grid[0].size();
        int rg = grid[0].size();
        for(int i=0;i<gcd(k, allsize);i++){
            int newplace = (k+i) % allsize;
            int temp = grid[i/rg][i%rg], temp1;
            while(newplace != i){
                
                temp1 = grid[newplace/rg][newplace%rg];
                grid[newplace/rg][newplace%rg] = temp;
                temp = temp1;
                newplace += k;
                
                newplace %= allsize;
                
            }
            grid[i/rg][i%rg] = temp;
        }
        return grid;
    }
};