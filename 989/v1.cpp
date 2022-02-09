class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int kk, c=0;
        for(int i=num.size()-1;i>=0;--i){
            kk = k % 10;
            if(kk + num[i] + c >= 10){
                ans.push_back(num[i]+kk + c - 10);
                c = 1;
            }
            else {
                ans.push_back(num[i] + kk + c);
                c = 0;
            }
            k /= 10;
        }
        while(k){
            kk = k % 10;
            if(kk + c >= 10){
                ans.push_back(kk+c-10);
                c = 1;
            }
            else{
                ans.push_back(kk+c);
                c = 0;
            }
            k /= 10;
        }
        if(c){
            ans.push_back(1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};