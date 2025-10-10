namespace chh{
    class Median{
    public:
        multiset<int, greater<int>> l; multiset<int> r;
        long long sl = 0, sr = 0;
        void erase(int n){
            if(r.find(n) != r.end()) {r.erase(r.find(n)), sr -= n; return ;}
            else if(l.find(n) != l.end()) {l.erase(l.find(n)), sl -= n; return ;}
            assert(false);
        }
        void insert(int n){
            if(!l.size() || n < *l.begin()){
                l.insert(n), sl += n;
            }
            else{
                r.insert(n); sr += n;
            }
            adjust();
        }
        void adjust(){
            while(l.size() >= r.size()){
                sl -= *l.begin(); sr += *l.begin();
                r.insert(*l.begin()); l.erase(l.begin());
            }
            while(l.size() < r.size()){
                sl += *r.begin(); sr -= *r.begin();
                l.insert(*r.begin()); r.erase(r.begin());
            }
        }
        long long min_L1(){
            return sr - 1ll * r.size() * (*l.begin()) + 1ll * l.size() * (*l.begin()) - sl;
        }
    };
}