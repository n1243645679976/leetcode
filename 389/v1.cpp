class Solution {
public:
    char findTheDifference(string s, string t) {
        char q='\0';
        for(char c: s) q ^= c;
        for(char c: t) q ^= c;
        return q;
    }
};