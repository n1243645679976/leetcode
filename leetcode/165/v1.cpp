class Solution {
public:
    int compareVersion(string version1, string version2) {
        int s1 = 0, s2 = 0, e1 = 0, e2 = 0, v1 = 0, v2 = 0;
        int l1 = version1.length(), l2 = version2.length();
        while(s1 < l1 || s2 < l2){
            while(e1 < l1 && version1[e1] != '.') ++e1;
            while(e2 < l2 && version2[e2] != '.') ++e2;
            if(s1 >= l1) v1 = 0;
            else v1 = stoi(version1.substr(s1, e1 - s1));
            if(s2 >= l2) v2 = 0;
            else v2 = stoi(version2.substr(s2, e2 - s2));
            if(v1 > v2) return 1;
            else if(v1 < v2) return -1;
            e1 += 1;
            e2 += 1;
            s1 = e1;
            s2 = e2;
        }
        return 0;
    }
};