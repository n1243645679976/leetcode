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
    ListNode* sortList(ListNode* head) {
        ListNode* q = head;
        vector<int> vi;
        while(q){
            vi.push_back(q->val);
            q = q->next;
        }
        sort(vi.begin(), vi.end());
        int i = 0;
        q = head;
        while(q){
            q->val = vi[i];
            i += 1;
            q = q->next;
        }
        return head;
    }
};