class Solution {
public:
    bool check(int i, int j, int li, int lj){
        if(i<0 || i>=li) return false;
        if(j<0 || j>=lj) return false;
        return true;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int li = board.size(), lj = board[0].size(), count;
        for(int i=0;i<li;i++){
            for(int j=0;j<lj;j++){
                count = 0;
                for(int di=-1;di<2;di++){
                    for(int dj=-1;dj<2;dj++){
                        if(check(i+di, j+dj, li, lj))
                            count += board[i+di][j+dj] & 1;
                    }
                }
                if(board[i][j] == 1){
                    if(count == 3 || count == 4)
                        board[i][j] |= 2;
                }
                else{
                    if(count == 3)
                        board[i][j] |= 2;
                }
                
                
            }
        }
        for(int i=0;i<li;i++){
            for(int j=0;j<lj;j++){
                board[i][j] >>= 1;
            }
        }
    }
};