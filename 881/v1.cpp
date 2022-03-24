class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i=0, j=people.size()-1, ans = people.size();
        while(j>i){
            if(people[i] + people[j] <= limit){
                i++; j--;
                ans -= 1;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};