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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *q1, *q2, *head;
        q1 = new ListNode();
        q1->next = l1;
        q2 = new ListNode();
        q2->next = l2;
        head = q1;
        int c=0;
        while(q1->next != NULL && q2->next != NULL){
            q1->next->val += q2->next->val + c;
            if(q1->next->val >= 10){
                q1->next->val -= 10;
                c = 1;
            }
            else c = 0;
            q1 = q1->next;
            q2 = q2->next;
        }
        if(q2->next != NULL){
            q1->next = q2->next;
        }
        while(q1->next != NULL){
            q1->next->val += c;
            if(q1->next->val >= 10){
                q1->next->val -= 10;
                c = 1;
            }
            else c = 0;
            q1 = q1->next;
        }
        if(c){
            q1->next = new ListNode(1);
        }
        return head->next;
    }
};