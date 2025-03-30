
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char, int> char2count, temp_c2c;
        int i = 0, diff = 0, ls = s.length();
        bool split = false;
        for(char c: s) char2count[c]++;
        while(i + diff < ls){
            temp_c2c[s[i+diff]]++;
            i++;
            split = true;
            for(auto it = temp_c2c.begin();it != temp_c2c.end();it++){
                if(it->second != char2count[it->first]){
                    split = false;
                    break;
                }
            }
            if(split){
                ans.push_back(i);
                diff += i;
                i = 0;
                temp_c2c = unordered_map<char, int>();
            }
        }
        if(i != 0) ans.push_back(i);
        return ans;
    }
};