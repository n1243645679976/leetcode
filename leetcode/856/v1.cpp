class Solution {
public:
    int scoreOfParentheses(string s) {
        int ls = s.length(), ind, start_ind, sums;
        pair<int, int> p;
        stack<int> indlist;
        stack<pair<int, int>> nums;
        bool flag = false;
        nums.push(pair<int, int>(-1, 0));
        for(int i=0;i<ls;++i){
            if(s[i] == '(') indlist.push(i);
            else{
                start_ind = indlist.top();
                indlist.pop();
                vector<int> vi;
                flag = false;
                while(get<0>(nums.top()) > start_ind){
                    vi.push_back(get<1>(nums.top()));
                    nums.pop();
                    flag = true;
                }
                if(flag){
                    sums = 2*accumulate(vi.begin(), vi.end(), 0);
                }
                else sums = 1;
                nums.push(pair<int, int>(i, sums));
            }
        }
        int ans = 0;
        while(!nums.empty()){
            ans += get<1>(nums.top());
            nums.pop();
        }
        return ans;
    }
};