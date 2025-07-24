namespace chh{
    const int INPUT_END = -1, NOT_FOUND = -1;
    template<class DATA,
             class INPUT,
             class OUTPUT,
             int DICT_SIZE, 
             int getkey(INPUT&, int), 
             void apply_route(DATA&, bool), 
             void aggregate_route(DATA&, OUTPUT&, bool),
             OUTPUT (*found_fail)()>
    class Trie{
    public:
        class TrieNode{
        public:
            vector<int> next;
            DATA data;
            TrieNode() : next(DICT_SIZE, -1) {}
        };
        vector<TrieNode> nodes;
        Trie() : nodes(1) {}
        void insert(INPUT& a){
            int i = 0, key = getkey(a, i), node = 0;
            while(key != INPUT_END){
                if(nodes[node].next[key] == -1) nodes[node].next[key] = nodes.size(), nodes.push_back(TrieNode());
                node = nodes[node].next[key];
                apply_route(nodes[node].data, 0);
                key = getkey(a, ++i);
            }
            apply_route(nodes[node].data, 1);
        }
        OUTPUT search(INPUT& a){
            int i = 0, key = getkey(a, i), node = 0;
            OUTPUT o = OUTPUT();
            while(key != INPUT_END){
                node = nodes[node].next[key];
                if(node == NOT_FOUND) {
                    return found_fail();
                }
                aggregate_route(nodes[node].data, o, 0);
                key = getkey(a, ++i);
            }
            aggregate_route(nodes[node].data, o, 1);
            return o;
        }
    };
}