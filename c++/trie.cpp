
class BitIteratorL2H {
private:
    int num;
    int index;
public:
    BitIteratorL2H(int n) : num(n), index(0) {}
    BitIteratorL2H(int n, int ind) : num(n), index(ind) {}
    auto begin() {
        return *this;
    }
    auto end() {
        return BitIteratorL2H(0, 1); 
    }
    BitIteratorL2H& operator++() {
        ++index;
        return *this;
    }
    bool operator*() const {
        return (num >> index) & 1;
    }
    bool operator!=(const BitIteratorL2H& other) const {
        return index != other.index;
    }
};
class BitIteratorH2L {
const int MXBIT = 31;
private:
    int num;
    int index;
public:
    BitIteratorH2L(int n) : num(n), index(MXBIT) {}
    BitIteratorH2L(int n, int ind) : num(n), index(ind) {}
    auto begin() {
        return *this;
    }
    auto end() {
        return BitIteratorH2L(0, -1);
    }
    BitIteratorH2L& operator++() {
        --index;
        return *this;
    }
    bool operator*() const {
        return (num >> index) & 1;
    }
    bool operator!=(const BitIteratorH2L& other) const {
        return index != other.index;
    }
};
template<typename T, typename U>
struct TrieNode : public unordered_map<U, TrieNode<T, U>*> {
    int is_end = 0;
    int cnt = 0;
    vector<T> data;
    TrieNode() {}
    TrieNode* setnext(U t){
        if((*this)[t] == NULL) (*this)[t] = new TrieNode();
        return (*this)[t];
    }
    TrieNode* getnext(U t){
        return (*this)[t];
    }
};
template<typename T, typename U>
class Trie {
public:
    TrieNode<T, U>* root;
    Trie() {
        root = new TrieNode<T, U>;
    }
    void insert(T word) {
        TrieNode<T, U>* node = root;
        for (auto c : word) {
            node = node->setnext(c);
            node->cnt++;
        }
        node->is_end++;
        node->data.push_back(word);
    }
    void erase(T word) {
        TrieNode<T, U>* node = root;
        for (auto c : word) {
            node = node->setnext(c);
            node->cnt--;
        }
        node->is_end--;
        node->data.push_back(word);
    }
    bool startsWith(T prefix) {
        TrieNode<T, U>* node = root;
        for (auto c : prefix) {
            node = node->getnext(c);
            if(node == NULL) return 0;
        }
        return true;
    }
    bool search(T word) {
        TrieNode<T, U>* node = root;
        for (auto c : word) {
            node = node->getnext(c);
            if(node == NULL) return 0;
        }
        return node->is_end;
    }
    vector<U> searchfirst(T word) {
        TrieNode<T, U>* node = root;
        vector<U> res;
        for (auto c : word) {
            node = node->getnext(c);
            res.push_back(c);
            if(node == NULL) return {};
            if(node->is_end) return res;
        }
        return {};
    }
    
};
using StringTrie = Trie<string, char>;
using BitHLTrie = Trie<BitIteratorH2L, int>;
using BitLHTrie = Trie<BitIteratorL2H, int>;