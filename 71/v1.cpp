class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ss;
        string temp;
        int end = path.find('/');
        int start = 0;
        while(end != string::npos){
            if(end-start != 0){
                temp = path.substr(start, end-start);
                if(temp == ".."){
                    if(!ss.empty()){
                        ss.pop_back();
                    }
                }
                else if(temp == "."){
                    ;
                }
                else{
                    ss.push_back(temp);
                }
            }
            start = end + 1;
            end = path.find('/', start);
        }
        if(start != path.length()){
            temp = path.substr(start);
            if(temp == ".."){
                if(!ss.empty()){
                    ss.pop_back();
                }
            }
            else if(temp == "."){
                ;
            }
            else{
                ss.push_back(temp);
            }
        }
        string ans = "";
        for(string s:ss){
            ans += "/" + s;
        }
        if(ans == "") return "/";
        return ans;
    }
};