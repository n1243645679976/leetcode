// https://leetcode.com/problems/minimum-time-to-reach-target-with-limited-power/submissions/2050252379/
// only checked for dec.
template<typename U, typename T, void (*_erase)(U, T), void (*_insert)(U, T)>
class MonoMap{
public:
    map<U, T> mono;
    function<bool(T, T)> comp;
    int _mono_type, _eq, _rev;
    MonoMap(int dec, int inc, int eq = 0, int rev = 0) : _mono_type(inc - dec), _eq(eq), _rev(rev ? -1 : 1) {
        // rev: 0: erase >=k, 1: erase < k
        assert(dec != inc);
        _mono_type *= _rev;
        if(_mono_type == 1) {if(!eq) comp = [](T a, T b){return (b > a);}; else comp = [](T a, T b){return (b >= a);};}
        else {if(!eq) comp = [](T a, T b){return (b < a);}; else comp = [](T a, T b){return (b <= a);};}
    }
    bool insert(U k, T v){
        k *= _rev;
        auto it = mono.lower_bound(k);
        while(it != mono.end()){
            if(!comp(v, it->second)) {
                _erase(it->first * _rev, it->second);
                it = next(it); mono.erase(prev(it));
            } else break;
        }
        if(it == mono.begin() || it != mono.begin() && comp(prev(it)->second, v)) {_insert(k * _rev, v); mono.insert({k * _rev, v}); return 1;}
        return 0;
    }
};
int globalu;
multiset<array<long long, 3>> q; 
void erase(long long k, long long v){
    q.erase({k, v, globalu});
}
void insert(long long k, long long v){
    q.insert({k, v, globalu});
}