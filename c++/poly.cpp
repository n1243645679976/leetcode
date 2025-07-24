
template<typename T>
class Poly{
  vector<T> bernoulli(1);
  vector<T> A(1);
  int prevnotused = 0;
  // Akiyama–Tanigawa algorithm
  void compute_bernoulli(int k) {
      if(k < prevnotused) return ;
      bernoulli.resize(k+1); A.resize(k+1);
      for (int m = prevnotused; m <= k; ++m) {
          A[m] = T(1) / T(m + 1);
          for (int j = m; j >= 1; --j)
              A[j - 1] = (A[j - 1] - A[j]) * T(j);
          bernoulli[m] = A[0];
      }
      prevnotused = k + 1;
  }
  T sum_of_powers(int p, int n) {
      if (n <= 0) return 0;
      compute_bernoulli(p+1);
      T inner_sum = 0, n_T = n;
      for (int j = 0; j <= p; ++j) {
          inner_sum += C(p + 1, j) * bernoulli[j] * std::pow(n_T, p + 1 - j);
      }
      return inner_sum / static_cast<T>(p + 1);
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