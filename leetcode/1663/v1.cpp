class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<char> vc;
        k -= n;
        for(int i=0;i<n;i++){
            if(k >= 25){
                vc.push_back(25+97);
                k -= 25;
            }
            else {
                vc.push_back(k+97);
                k = 0;
            }
        }
        string s(vc.rbegin(), vc.rend());
        return s;
    }
};