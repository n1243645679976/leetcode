
class KMP{
public:
    vector<int> LPS;
    void setlps1(string& s){
        LPS.resize(0);
        LPS.resize(s.size());
        
        int prev = 0, i = 1;
        while(i < s.size()){
            if(s[i] == s[prev]) LPS[i] = prev + 1, i++, prev++;
            else if(prev == 0) LPS[i] = 0, i++;
            else prev = LPS[prev - 1];
        }

    }
    void setlps(string& s){
        LPS.resize(0);
        LPS.resize(s.size()+1); // 用0當黑洞, check用-1, 固定都會增加
        LPS[0] = -1;
        int l = -1; // 跳過第一個prefix, 從-1開始
        for(int r=0;r<s.size();r++){
            // LPS[l] 有保 s[l-1] == s[r-1], 值為代測?
            while(l != -1 && s[l] != s[r]) l = LPS[l];
            // LPS[r+1] = l+1, 有保 s[r] == s[l]，且l+1代表對r+1來說的下個代測
            // aabaab__________aabaac
            //                      | 在前面的a連到第二個b
            //      | 在前面的a連到前面的b
            //   | 在前面的a連到前面的a
            //  | 在前面的a連到前面的a
            // | -1
            LPS[r+1] = l+1;
            l++;
        }
    }
    int kmp(string& a, string& b){
        setlps(b);
        int l = 0; // 找的時候不跳過第一個prefix, 從0開始
        vector<int> matches;
        for(int r=0;r<a.size();r++){
            while(l != -1 && b[l] != a[r]) l = LPS[l];
            l++;
            if(l == b.size()) return r - b.size() + 1;
        }
        return -1;
    }
};