namespace chh{
class Prime{
public:
  vector<int> minp, primes;
  void sieve(int n){
    minp.assign(n+1, 0);
    primes.clear();
    for(int i=2;i<=n;i++){
      if(minp[i] == 0) minp[i] = i, primes.push_back(i);
      for(auto p:primes){
        if(i * p > n) break;
        minp[i * p] = p;
        if(p == minp[i]) break;
      }
    }
  }
};
}

namespace chh{
  __int128 qpow(__int128 a,__int128 b,__int128 m){
    a%=m;
    __int128 res = 1;
    while(b){
      if(b&1)	res = res*a%m;
      a = a*a%m;
      b >>= 1;
    }
    return res%m;
  }
  // https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test : check until 2 ^ 32
  explicit vector<int> check32 = {2, 7, 61};
  // https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test : check until 2 ^ 64
  explicit vector<int> check64 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  bool Miller(__int128 x,__int128 n){
    __int128 b = n-1;
    while(!(b&1)) b >>= 1;
    x = qpow(x,b,n);	
    while(b < n-1 && x != 1 && x != n-1)
      x = (x*x)%n,b <<= 1; 
    return x == n-1 || b&1 == 1;
  }
  // default = 64
  bool isprime(ll n, vector<int> tocheck=check64){
    for(auto k:tocheck) if(n == k) return true;
    if(n == 1 || !(n&1)) return false;
    for(auto k:tocheck) if(!Miller(k, n)) return false;
    return true;
  }
}