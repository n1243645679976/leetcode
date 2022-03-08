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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        ListNode* node = head;
        while(node){
            if(s.find(node) == s.end()){
                s.insert(node);
            }
            else{
                return true;
            }
            node = node->next;
        }
        return false;
    }
};