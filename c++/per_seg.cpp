// tested:
// https://atcoder.jp/contests/abc339/submissions/50037731
namespace per_seg{
    static int MX;
    const int SZ = 20000005;
    class Data{
    public:
        ll val = 0;
        Data set(ll v){
            return Data{v};
        }
        Data update(ll v){
            return Data{val + v};
        }
    };
    int left[SZ], right[SZ];
    Data data[SZ];
    Data combineNode(Data& a, Data& b){
        return Data{a.val + b.val};
    }
    Data e(){
        return Data{0};
    }
    const Data E = e();
    class per_seg{
    public:
        int id = 0;
        vector<int> root;
        int build(int n, bool entry = true, int L=0, int R=MX-1){
            if(entry){
                MX = n;
                root.push_back(build(n, false));
                return root[0];
            }
            if(L == R) {
                data[id] = e();
                return id++;
            }
            int MID = (L+R) / 2, tid = id++;
            left[tid] = build(n, false, L, MID);
            right[tid] = build(n, false, MID+1, R);
            data[tid] = combineNode(data[left[tid]], data[right[tid]]);
            return tid;
        }
        template<typename T> int build(int n, vector<T>& a, bool entry = true, int L=0, int R=MX-1){
            if(entry) {
                root.push_back(build(n, a, false, L, R));
                return root[0];
            }
            if(L == R) {
                if(L >= a.size()) return id++;
                else {
                    data[id].set(a[L]);
                    return id++;
                }
            }
            int MID = (L+R) / 2, tid = id++;
            left[tid] = build(n, a, false, L, MID);
            right[tid] = build(n, a, false, MID+1, R);
            data[tid] = combineNode(data[left[tid]], data[right[tid]]);
            return tid;
        }
        int update(int pos, ll val, int nowid = -1, int L=0, int R=MX-1){
            if(nowid < 0){
                assert(pos <= R && 0 <= pos);
                root.push_back(update(pos, val, root.back(), L, R));
                return root.back();
            }
            if(L == R) {
                data[id] = data[nowid].update(val);
                return id++;
            }
            int MID = (L+R) / 2, tid = id++;
            left[tid] = left[nowid];
            right[tid] = right[nowid];
            if(pos <= MID) left[tid] = update(pos, val, left[nowid], L, MID);
            else right[tid] = update(pos, val, right[nowid], MID+1, R);
            data[tid] = combineNode(data[left[tid]], data[right[tid]]);
            return tid;
        }
        Data query(int ver, int l, int r, int nowid = -1, int L=0, int R=MX-1){
            if(nowid < 0) return query(ver, l, r, root[ver], L, R);
            if(R < l || L > r) return E;
            if(l <= L && R <= r) return data[nowid];
            int MID = (L+R) / 2;
            auto tl = query(ver, l, r, left[nowid], L, MID);
            auto tr = query(ver, l, r, right[nowid], MID+1, R);
            return combineNode(tl, tr);
        }
    };
}