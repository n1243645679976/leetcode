
class BIT{
public:
    int _max, _min;
    vector<ll> c;
    BIT(int __max, int __min = 0){
        _max = __max + 2 + __min;
        _min = __min; // serve as offset
        c.reserve(_max);
        for(int i = 0;i<_max;i++){
            c[i] = 0;
        }
    }
    void update(int i, int v){
        i += 2 + _min;
        while(i < _max){
            c[i] += v;
            i += i & (-i);
        }
    }
    ll query(int i){
        ll ans = 0;
        i += 2 + _min;
        while(i > 0){
            ans += c[i];
            i -= i & (-i);
        }
        return ans;
    }
};