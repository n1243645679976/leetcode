class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        else{
            string minstr = s;
            string temp;
            for(int i=0;i<s.length();++i){
                temp = s.substr(i) + s.substr(0, i);
                if(temp < minstr) minstr = temp;
            }
            return minstr;
        }
    }
};