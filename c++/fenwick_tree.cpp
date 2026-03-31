template<typename T>
class BIT{
public:
    int _max;
    int offset = 2; // -> update(-1, v), query(-1, v)
    vector<T> c;
    BIT(int __max){
        _max = __max + offset;
        c.reserve(_max);
        for(int i = 0;i<_max;i++){
            c[i] = e();
        }
    }
    void update(int i, int v){
        i += offset;
        while(i < _max){
            c[i] = op(c[i], v);
            i += i & (-i);
        }
    }
    T query(int i) {
        // [0, i)
        T ans = 0;
        i = i + offset;
        i--;
        while(i > 0){
            ans = op(ans, c[i]);
            i -= i & (-i);
        }
        return ans;
    }
    T e(){return T(0);}
    T op(T a, T b){return a+b;}
};