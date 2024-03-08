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
// 記得要確定end才有詞，不然是prefix
template<typename T, typename U>
class Trie {
public:
    TrieNode<U>* root;

    Trie() {
        root = new TrieNode<U>;
    }
    void insert(T word) {
        TrieNode<U>* node = root;
        for (auto c : word) {
            node = node->setnext(c);
            node->cnt++;
        }
        node->is_end++;
        node->data.push_back(word);
    }

    bool startsWith(T prefix) {
        TrieNode<U>* node = root;
        for (auto c : prefix) {
            node = node->getnext(c);
            if(node == NULL) return 0;
        }
        return true;
    }

    bool search(T word) {
        TrieNode<U>* node = root;
        for (auto c : word) {
            node = node->getnext(c);
            if(node == NULL) return 0;
        }
        return node->is_end;
    }
};




class TrieData{
    virtual bool is_end() = 0;
    virtual int getnext() = 0;
}
class IntTrieData : public TrieData{
private:
    int val;
    int ind;
public:
    IntTrieData(int v) : val(v){ind = 30;}
    bool is_end() override {
        return ind == -1;
    }
    int getnext() override {
        int temp = (val >> ind) & 1;
        ind--;
        return temp;
    }
}
class TrieNode{
    
};
template<typename T>
class Trie{
    bool update(T td){
        while(!td.is_end()){
            auto g = getnext
        }
    }
};
