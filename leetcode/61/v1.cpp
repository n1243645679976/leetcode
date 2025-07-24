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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){return head;}
        ListNode* node = head;
        vector<ListNode*> ln;
        int i = 0;
        while(node){
            ln.push_back(node);
            node = node->next;
            ++i;
        }
        k %= i;
        if(k != 0){
            ln[ln.size()-1]->next = ln[0];
            ln[ln.size()-k-1]->next = NULL;
            return ln[ln.size()-k];
        }
        else return ln[0];
    }
};