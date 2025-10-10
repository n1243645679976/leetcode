
namespace chh{
  template<typename T>
  class CombHelper{
  public:
    vector<T> fact, ifact;
    CombHelper() : fact(1, T(1)), ifact(1, T(1)) {}
    void init(int n){
      for(int i=fact.size();i<=n;i++){
        fact.push_back(fact.back() * i);
        ifact.push_back(ifact.back() / i);
      }
    }
    T C(int a, int b){
      init(a);
      if(b < 0 || b > a) return 0;
      return fact[a] * ifact[b] * ifact[a-b];
    }
    vector<T> interval_sum(int N, int a){
        // The permutation of A, B.
        // maximum number of A = a.
        vector<T> su(N+1);
        su[0] = 0;
        for(int i=1;i<=N;i++){
            su[i] = su[i-1] + su[i-1];
            su[i] -= C(i-1, a);
            su[i] -= C(i-1, i-1-a);
        }
        return su;
    }
  };
}