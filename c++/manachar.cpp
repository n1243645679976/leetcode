// https://leetcode.com/problems/longest-palindromic-substring/submissions/1220967765/
#include<vector.h>

namespace chh{
template<typename T>
class manachar{
public:
    vector<int> info;
    vector<T> data;
    T e;
    void padding(vector<T>& temp, T e){
        data.resize(temp.size() * 2 + 1, e);
        for(int i=0;i<temp.size();i++) data[i*2+1] = temp[i];
    }
public:
    void init(vector<T>& temp, T e){
        padding(temp, e);
        this->e = e;
        // .....C.M.C..R
        // check M
        int R = 0, M = 0;
        info.resize(data.size());
        for(int C = 0;C < data.size();C++){
            R = max(R, C);
            int L = M - (C - M);
            if(L >= 0){
                info[C] = min(info[L], R-C);
                if(C + info[C] >= R) R = C + info[C], M = C;
            }
            while(C + info[C] == R && R < data.size() && C - (R - C) >= 0){
                if(data[R] == data[C - (R - C)]) info[C]++, R++, M = C;
                else break;
            }
        }
    }
    manachar(vector<T>& s, T e){
        init(s, e);
    }
    manachar(string& data, char e = '#'){
        vector<char> s(data.begin(), data.end());
        init(s, e);
    }
    vector<T> longest_palindrom(){
        vector<T> res;
        int malength = 0, startind = 0;
        for(int i=0;i<info.size();i++){
            int length = info[i] - 1;
            if(length > malength) malength = length, startind = i;
        }
        for(int i=startind-info[startind]+1;i<startind+info[startind];i++){
            if(data[i] != this->e) res.push_back(data[i]);
        }
        return res;
    }
    bool check_palindrom(int l, int r){
        // inclusive [l, r]
        l *= 2; l++; r *= 2; r++;
        int mid = (l+r) / 2;
        return mid - info[mid] + 1 <= l;
    }
};
using manachar_str = manachar<char>;
} 