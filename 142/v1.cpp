/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> a;
        ListNode dummy = ListNode(-1e6);
        dummy.next = head;
        
        ListNode* temp = &dummy;
        ListNode* next;
        while(temp){
            temp = temp->next;
            if(a.count(temp)){
                return temp;
            }
            a.insert(temp);
        }
        return NULL;
        
    }
};