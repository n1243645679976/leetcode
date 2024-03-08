
template<int MOD>
struct comb {
  vector<mint<MOD>> Comb;
  vector<mint<MOD>> Perm;
  vector<mint<MOD>> Fact;
  void setComb(int n){
      /* Usage: 
            mint<MOD> Comb;
            Comb.setComb(12);
            F0R(i, 13) cout<<Comb.Comb[i]<<endl;
      */
      mint<MOD> c0 = 1;
    Comb.reserve(n+1);
      for(int i=0;i<=n;i++){
          Comb.push_back(c0);
          c0 *= (n-i);
          c0 /= (i+1);
      }
  }
  void setPerm(int n){
      /* Usage: 
            mint<MOD> Perm;
            Perm.setPerm(12);
            F0R(i, 13) cout<<Perm.Perm[i]<<endl;
      */
     Perm.reserve(n+1);
      mint<MOD> p0 = 1;
      for(int i=0;i<=n;i++){
          Perm.push_back(p0);
          p0 *= (n-i);
      }
  }
  void setFact(int n){
      /* Usage: 
            mint<MOD> Fact;
            Fact.setFact(12);
            F0R(i, 13) cout<<Fact.Fact[i]<<endl;
      */
      Fact.reserve(n+1);
      mint<MOD> f0 = 1;
      for(int i=1;i<=n;i++){
          Fact.push_back(f0);
          f0 *= i;
      }
  }
};