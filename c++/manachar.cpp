// https://leetcode.com/problems/longest-palindromic-substring/submissions/1220967765/
namespace manachar{
    template<typename T>
    vector<T> manachar_longest(vector<T>& temp, function<T()> e){
        vector<T> data(1, e());
        for(auto& d:temp) data.push_back(d), data.push_back(e());

        int R = 0, M = 0;
        vector<int> ans(data.size());
        for(int C = 0;C < data.size();C++){
            R = max(R, C);
            int L = M - (C - M);
            if(L >= 0){
                ans[C] = min(ans[L], R-C);
                if(C + ans[C] >= R) R = C + ans[C], M = C;
            }
            while(C + ans[C] == R && R < data.size() && C - (R - C) >= 0){
                if(data[R] == data[C - (R - C)]) ans[C]++, R++, M = C;
                else break;
            }
        }
        vector<T> res;
        int malength = 0, startind = 0;
        for(int i=0;i<ans.size();i++){
            int length = ans[i] - 1;
            if(length > malength) malength = length, startind = i;
        }
        for(int i=startind-ans[startind]+1;i<startind+ans[startind];i++){
            if(data[i] != e()) res.push_back(data[i]);
        }
        return res;
    }
    // "babad" -> return the length spread from center "#b#a#b#a#d#", [{1, 2, 1, 4, 1, 4, 1, 2, 1, 2, 1}]
    // the length, left bound, right bound of each answer can be found from the last two `for` inside manachar_longest.
    template<typename T>
    vector<int> manachar(vector<T>& temp, function<T()> e){
        vector<T> data(1, e());
        for(auto& d:temp) data.push_back(d), data.push_back(e());

        // .....C.M.C..R
        // check M
        int R = 0, M = 0;
        vector<int> ans(data.size());
        for(int C = 0;C < data.size();C++){
            R = max(R, C);
            int L = M - (C - M);
            if(L >= 0){
                ans[C] = min(ans[L], R-C);
                if(C + ans[C] >= R) R = C + ans[C], M = C;
            }
            while(C + ans[C] == R && R < data.size() && C - (R - C) >= 0){
                if(data[R] == data[C - (R - C)]) ans[C]++, R++, M = C;
                else break;
            }
        }
        return ans;
    }
    string manachar_longest(string& data){
        vector<char> s(data.begin(), data.end());
        function<char()> e = []() -> char {return '#';};
        auto res = manachar_longest(s, e);
        return string(res.begin(), res.end());
    }
    vector<int> manachar(string& data){
        vector<char> s(data.begin(), data.end());
        function<char()> e = []() -> char {return '#';};
        return manachar(s, e);
    }
}