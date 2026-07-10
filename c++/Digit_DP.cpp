
template<size_t NUM_STATE,
        typename OUTPUT_TYPE,
        bool (*check_state)(array<int, NUM_STATE> now_state), // false -> pruning
        OUTPUT_TYPE (*e)(),  // zero element of OUTPUT_TYPE, used for pruning
        array<int, NUM_STATE> (*init_state)(), // initial state
        array<int, NUM_STATE> (*next_state)(array<int, NUM_STATE> now_state, int next_tight, int next_lz, int index, int d),  // now_state * (plz, nlz, d) -> next_state
        OUTPUT_TYPE (*cal_state)(array<int, NUM_STATE> leaf_state), // leaf_state -> output
        int digit_base = 10>
class Digit_DP{
  using STATE_TYPE = array<int, NUM_STATE>;
  const static int SZ = 13000000;
  const static int dbgSZ = 300;
  STATE_TYPE dims;
  STATE_TYPE offset;
  int seen[SZ];
  int seen_gen;
  OUTPUT_TYPE dp[SZ];
  vector<int> dbg_inds;
  STATE_TYPE tmpT[dbgSZ];
  int string_len;
  int to_index(STATE_TYPE& g, int tight, int lz, int ind){
    int index = 0;
    for(int i=0;i<NUM_STATE;i++) index += offset[i] * g[i];
    index += string_len * 2 * tight + string_len * lz + ind;
    //used_index.insert(index);
    return index;
  }
  void clear(){
    seen_gen++;
  }
public:
  Digit_DP(STATE_TYPE EACH_STATE_MAX_DIM, int NUM_LENGTH) : dims(EACH_STATE_MAX_DIM), string_len(NUM_LENGTH), seen_gen(1) {
    offset[NUM_STATE-1] = NUM_LENGTH * 4;
    for(int i=dims.size()-1;i>0;i--) offset[i-1] = offset[i] * dims[i];
  }
  OUTPUT_TYPE run(string& s, STATE_TYPE state = init_state(), int tight = 1, int lz = 1, int ind = 0, int dbg_ind=-1, int entry = 1){
    // ans of [0, s]
    if(entry) clear();
    if(!check_state(state)) return e();
    if(ind == s.size()){
      if(tight && dbg_ind >= 0) tmpT[dbg_ind] = state;
      return cal_state(state);
    }
    int index = to_index(state, tight, lz, ind);
    if(seen[index] == seen_gen) return dp[index];
    int ma = tight ? s[ind] - 48 : digit_base - 1;
    OUTPUT_TYPE res = 0;
    for(int i=0;i<ma+1;i++){
      int ntight = tight && i == ma;
      int nlz = lz && i == 0;
      res += run(s, next_state(state, ntight, nlz, ind, i), ntight, nlz, ind+1, dbg_ind, 0);
    }
    dp[index] = res, seen[index] = seen_gen;
    if(dbg_ind >= 0) dbg_inds.push_back(index);
    return res;
  }
  void debug(int tar){
    // output 0 ~ tar
    assert(tar < dbgSZ);
    int digit = 0, tmp = tar; while(tmp) tmp /= 10, digit++;
    vector<OUTPUT_TYPE> anss;
    for(int i=0;i<=tar;i++){
      auto si = to_string(i);
      while(si.size() < digit) si.insert(si.begin(), '0');
      anss.push_back(run(si, init_state(), 1, 1, 0, i));
      for(auto ind:dbg_inds) dp[ind] = 0, seen[ind] = 0;
      dbg_inds.clear();
    }
    for(int i=tar;i>=1;i--) anss[i] -= anss[i-1];
    for(int i=0;i<=tar;i++) {
      cout<<i<<":";
      for(int j=0;j<NUM_STATE;j++) cout<<",{"[j==0]<<tmpT[i][j];
      cout<<"}"<<" "<<anss[i]<<",\t"; 
      if(i % 5 == 4) cout<<endl;
    }
    cout<<endl;
  }
};