class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        char c;
        q.push('!');
        for(char _s: s){
            if(_s == '(' || _s == '{' || _s == '['){
                q.push(_s);
            }
            else{
                c = q.top();
                q.pop();
                if(_s == ')'){ if (c != '(') return false;}
                else if(_s == '}'){ if (c != '{') return false;}
                else if(_s == ']'){ if (c != '[') return false;}
            }
        }
        if(q.size() == 1){
            return true;
        }
        else return false;
    }
};