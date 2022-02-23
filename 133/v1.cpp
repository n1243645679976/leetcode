/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> int2Node;
    unordered_set<int> visited;
    int k=0;
    Node* dfs(Node* node){
        visited.insert(node->val);
        for(Node* n:node->neighbors){
            if(int2Node.find(n->val) == int2Node.end()){
                int2Node[n->val] = new Node(n->val);
            }
            int2Node[node->val]->neighbors.push_back(int2Node[n->val]);
            if(visited.find(n->val) == visited.end()){;
                dfs(n);
            }
        }
        return node;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        int2Node[1] = new Node(1);
        dfs(node);
        return int2Node[1];
    }
};