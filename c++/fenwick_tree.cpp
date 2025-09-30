
class BIT{
public:
    int _max;
    int offset = 2; // -> update(-1, v), query(-1, v)
    vector<long long> c;
    BIT(int __max){
        _max = __max + offset;
        c.reserve(_max);
        for(int i = 0;i<_max;i++){
            c[i] = 0;
        }
    }
    void update(int i, int v){
        i += offset;
        while(i < _max){
            c[i] += v;
            i += i & (-i);
        }
    }
    long long query(int i){
        // [0, i)
        long long ans = 0;
        i += offset;
        i--;
        while(i > 0){
            ans += c[i];
            i -= i & (-i);
        }
        return ans;
    }
};