class Solution {
public:
    string largestOddNumber(string num) {
        int ls = num.length(), i=ls-1;
        for(;i>=0;i--){
            if(num[i] & 1){
                break;
            }
        }
        return num.substr(0, i+1);
    }
};