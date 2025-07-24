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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy = ListNode();
        dummy.next = head;
        ListNode *node = &dummy, *temp, *next1, *next2;
        while(true){
            if(node->next == NULL){
                return dummy.next;
            }
            if(node->next->next == NULL){
                return dummy.next;
            }
            next1 = node->next;
            next2 = next1->next;
            temp = next2->next;
            
            node->next = next2;
            next2->next = next1;
            next1->next = temp;
            
            node = next1;
        }
    }
};