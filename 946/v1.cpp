class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        st.push(-1);
        int i_push = 0, i_pop = 0, l_push = pushed.size(), l_pop = popped.size();
        while (i_push < l_push){
            if(st.top() == popped[i_pop]){
                ++i_pop;
                st.pop();
            }
            else{
                st.push(pushed[i_push]);
                ++i_push;
            }
        }
        while(i_pop < l_pop){
            if(st.top() == popped[i_pop]){
                ++i_pop;
                st.pop();
            }
            else break;
        }
        if(st.size() == 1) return true;
        else return false;
    }
};