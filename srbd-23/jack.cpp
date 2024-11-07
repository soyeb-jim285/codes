#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  vector<pair<int, int>> test_cases(t);
  int n_max = 0, m_max = 0;
  for (int i = 0; i < t; i++) {
    cin >> test_cases[i].first >> test_cases[i].second;
    n_max = max(n_max, test_cases[i].first);
    m_max = max(m_max, test_cases[i].second);
  }

  // Sieve of Eratosthenes to find all primes up to m_max - 1
  int sieve_size = max(m_max, 2);
  vector<bool> is_prime(sieve_size, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i < sieve_size; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j < sieve_size; j += i) {
        is_prime[j] = false;
      }
    }
  }

  // Collect all primes up to m_max - 1
  vector<int> primes_up_to_m_max;
  for (int p = 2; p < m_max; p++) {
    if (is_prime[p]) {
      primes_up_to_m_max.push_back(p);
    }
  }

  // Vector to store results
  vector<long long> results;

  // Process each test case
  for (int i = 0; i < t; i++) {
    int n = test_cases[i].first;
    int m = test_cases[i].second;

    // Collect primes less than m
    int idx =
        lower_bound(primes_up_to_m_max.begin(), primes_up_to_m_max.end(), m) -
        primes_up_to_m_max.begin();
    vector<int> P(primes_up_to_m_max.begin(), primes_up_to_m_max.begin() + idx);

    if (n == 0) {
      results.push_back(1);
      continue;
    }

    // Initialize DP array
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int j = 1; j <= n; j++) {
      dp[j] = dp[j - 1];
      for (auto l : P) {
        if (l > j) {
          break;
        }
        if (j - l >= 1) {
          dp[j] = (dp[j] + dp[j - l - 1]) % MOD;
        } else if (j - l == 0) {
          dp[j] = (dp[j] + 1) % MOD;
        }
      }
    }
    results.push_back(dp[n]);
  }

  // Print all results separated by space
  for (int i = 0; i < results.size(); i++) {
    cout << results[i] << (i < results.size() - 1 ? '\n' : '\n');
  }
}
