class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int ls1 = s1.length(), ls2 = s2.length();
        if(ls2 < ls1)
            return false;
        int cs1[26]{0};
        int cs2[26]{0};
        for(char c: s1){
            cs1[c-97] += 1;
        }
        for(int i=0;i<ls1;++i){
            cs2[s2[i]-97] += 1;
        }
        if(check(cs1, cs2)) return true;
        for(int i=ls1;i<ls2;++i){
            cs2[s2[i] - 97] += 1;
            cs2[s2[i-ls1] - 97] -= 1;
            if(check(cs1, cs2)) return true;
        }
        return false;
    }
    bool check(int* a, int* b){
        for(int i=0;i<26;++i){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};