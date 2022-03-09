/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    pair<ListNode*, int> get_next(ListNode* n, int count){
        if(n->next == NULL) return pair<ListNode*, int>(n->next, count);
        if(n->next->val != n->val) return pair<ListNode*, int>(n->next, count);
        return get_next(n->next, count+1);
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy, *ans_, *node, *temp;
        int r;
        
        dummy = new ListNode(-10000);
        temp = dummy;
        dummy->next = head;
        vector<pair<ListNode*, int>> v;
        node = dummy;
        while(node){
            auto q = get_next(node, 0);
            v.push_back(pair<ListNode*, int>(temp, q.second));
            temp = q.first;
            node = temp;
        }
        ans_ = dummy;
        for(auto i = next(v.begin());i!=v.end();++i){
            if((*i).second == 0){
                ans_->next = (*i).first;
                ans_ = ans_->next;
            }
        }
        ans_->next = NULL;
        return dummy->next;
    }
};