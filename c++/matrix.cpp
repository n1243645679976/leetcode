namespace chh{
  vector<vector<long long>> matmul(vector<vector<long long>> a, vector<vector<long long>> b, long long MOD=8000000000000000000ll){
    assert(a[0].size() == b.size());
    vector<vector<long long>> c(a.size(), vector<long long>(b[0].size()));
    for(int i=0;i<a.size();i++) for(int j=0;j<a[0].size();j++) for(int k=0;k<b[0].size();k++){
        c[i][j] += 1ll * a[i][k] * b[k][j] % MOD;
        c[i][j] %= MOD;
    }
    return c;
  }
  vector<vector<long long>> matpow(vector<vector<long long>> a, int n, long long MOD=8000000000000000000ll){
    assert(a.size() == a[0].size());
    vector<vector<long long>> base(a.size(), vector<long long>(a.size()));
    for(int i=0;i<a.size();i++) base[i][i] = 1;
    while(n){
        if(n & 1) base = matmul(base, a, MOD);
        a = matmul(a, a, MOD);
        n >>= 1;
    }
    return base;
  }
}