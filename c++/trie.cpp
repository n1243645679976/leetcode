

namespace chh{
    int trie_op_bith2l(int& a, int i){return i > 31 ? -1 : ((a >> (31-i)) & 1);}
    int trie_op_bitl2h(int& a, int i){return i > 31 ? -1 : ((a >> i) & 1);}
    int trie_op_lstr(string& a, int i){return i >= a.size() ? -1 : a[i] - 97;}
    int trie_op_str(string& a, int i){return i >= a.size() ? -1 : (a[i] - 65) - 6 * (a[i] >= 97);}
    template<typename T, int ALPHALEN, int (*op)(T&, int)>
    class Trie {
    public:
        struct TrieNode{
            long long is_end = 0;
            long long cnt = 0;
            array<int, ALPHALEN> child;
            TrieNode(){memset(&child[0], -1, ALPHALEN * sizeof(int));}
        };
        vector<TrieNode> data;
        Trie() : data(1, TrieNode()){}

        void insert(T& word) {
            int node = 0, ind = 0;
            while(true){
                int nnode = op(word, ind++);
                if(nnode == -1) break;
                if(data[node].child[nnode] == -1) data[node].child[nnode] = data.size(), data.push_back(TrieNode());
                node = data[node].child[nnode];
                data[node].cnt++;
            }
            data[node].is_end++;
        }
        void erase(T word) {
            int node = 0, ind = 0;
            while(true){
                int nnode = op(word, ind++);
                if(nnode == -1) break;
                assert(data[node].child[nnode] != -1);
                node = data[node].child[nnode];
                data[node].cnt--;
            }
            data[node].is_end--;
        }
        int startsWith(T prefix) {
            int node = 0, ind = 0;
            while(true){
                int nnode = op(prefix, ind++);
                if(nnode == -1) break;
                node = data[node].child[nnode];
                if(node == -1) return false;
            }
            return data[node].cnt;
        }
        int search(T word) {
            int node = 0, ind = 0;
            while(true){
                int nnode = op(word, ind++);
                if(nnode == -1) break;
                node = data[node].child[nnode];
                if(node == -1) return 0;
            }
            return data[node].is_end;
        }
    };
    using LStringTrie = Trie<string, 26, trie_op_lstr>;
    using StringTrie = Trie<string, 52, trie_op_str>;
    using BitH2LTrie = Trie<int, 32, trie_op_bith2l>;
    using BitL2HTrie = Trie<int, 32, trie_op_bitl2h>;
}