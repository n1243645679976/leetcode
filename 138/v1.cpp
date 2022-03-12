/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> Node2Int;
        vector<Node*> vectorNode;
        Node* node = head;
        int i = 0;
        while(node){
            vectorNode.push_back(new Node(node->val));
            Node2Int[node] = i;
            ++i;
            node = node->next;
        }
        Node2Int[NULL] = vectorNode.size();
        vectorNode.push_back(NULL);
        node = head;
        i = 0;
        while(node){
            vectorNode[i]->random = vectorNode[Node2Int[node->random]];
            vectorNode[i]->next = vectorNode[i+1];
            ++i;
            node = node->next;
        }
        return vectorNode[0];
    }
};