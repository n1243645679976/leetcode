class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "0";
        for(char c: num){
            while(c < ans.back() && k > 0){
                ans.pop_back();
                k -= 1;
            }
            ans.push_back(c);
        }
        while(k){
            ans.pop_back();
            k -= 1;
        }
        int i=0,lans=ans.length();
        while(i < lans && ans[i] == '0') ++i;
        ans = ans.substr(i);
        if(ans.length() == 0){
            return "0";
        }
        else{
            return ans;
        }
    }
};