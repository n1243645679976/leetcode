class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double** q = new double*[query_row+1];
        for(int i=0;i<=query_row;++i){
            q[i] = new double[i+1]{0};
        }
        q[0][0] = poured;
        for(int i=1;i<=query_row;++i){
            for(int j=0;j<=i;++j){
                if(j != 0 && q[i-1][j-1] >= 1){
                    q[i][j] += double(q[i-1][j-1] - 1) / 2;
                }
                if(j != i && q[i-1][j] >= 1){
                    q[i][j] += double(q[i-1][j] - 1) / 2;
                }
            }
        }
        if(q[query_row][query_glass] > 1) return 1;
        return q[query_row][query_glass];
    }
};