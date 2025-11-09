#include "mint.cpp"
template<typename T>
class Poly{
    vector<int> powers;
    Poly(vector<int>& p) : powers(p) {}
    void discrete_integration(){
        // n -> (n+1) * n / 2
        // sum(n) from 1 to 100 -> 
        vector<int> new_powers(powers.size() + 1);
        if (n <= 0) return 0;
        mh.build_bernoulli(p+1);
        T inner_sum = 0, n_T = n;
        for (int j = 0; j <= p; ++j) {
            new_powers[p + 1 - j] = mh.C(p + 1, j) * mh.bernoulli[j];
        }
        return inner_sum / T(p + 1);
    }

  // Akiyama–Tanigawa algorithm
  T sum_of_powers(int p, int n, minthelper& mh) {
      if (n <= 0) return 0;
      mh.build_bernoulli(p+1);
      T inner_sum = 0, n_T = n;
      for (int j = 0; j <= p; ++j) {
          inner_sum += mh.C(p + 1, j) * mh.bernoulli[j] * n_T.pow(p + 1 - j);
      }
      return inner_sum / T(p + 1);
  }
  T calculate_polynomial_sum(const std::vector<int>& powers, int upperbound, int lowerbound) {
    T total_sum = 0;
    for (int p : powers) {
        T sum_up_to_upper = sum_of_powers(p, upperbound);
        T sum_up_to_lower_minus_1 = sum_of_powers(p, lowerbound - 1);
        total_sum += (sum_up_to_upper - sum_up_to_lower_minus_1);
    }
    return total_sum;
  }
};