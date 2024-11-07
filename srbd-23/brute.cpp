#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (Union-Find) structure
struct DSU {
  vector<int> parent;
  vector<int> rank;
  DSU(int n) {
    parent.resize(n);
    rank.resize(n, 1);
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }
  int find_set(int x) {
    if (parent[x] != x) {
      parent[x] = find_set(parent[x]);
    }
    return parent[x];
  }
  void union_set(int x, int y) {
    int fx = find_set(x);
    int fy = find_set(y);
    if (fx == fy)
      return;
    if (rank[fx] < rank[fy]) {
      parent[fx] = fy;
    } else {
      parent[fy] = fx;
      if (rank[fx] == rank[fy]) {
        rank[fx]++;
      }
    }
  }
};

// Function to compute smallest prime factors up to max_num
vector<int> smallest_prime_factor(int max_num) {
  vector<int> spf(max_num + 1, 0);
  spf[0] = spf[1] = 1;
  for (int i = 2; i <= max_num; i++) {
    if (spf[i] == 0) {
      spf[i] = i;
      for (long long j = 1LL * i * i; j <= max_num; j += i) {
        if (spf[j] == 0) {
          spf[j] = i;
        }
      }
    }
  }
  return spf;
}

// Function to get unique prime factors using SPF
vector<int> get_unique_prime_factors(int num, const vector<int> &spf) {
  vector<int> factors;
  if (num < 2)
    return factors;
  while (num > 1) {
    int factor = spf[num];
    factors.push_back(factor);
    while (num % factor == 0) {
      num /= factor;
    }
  }
  return factors;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ratings(n);
  int max_rating = 0;
  for (int &x : ratings) {
    cin >> x;
    if (x > max_rating)
      max_rating = x;
  }
  // Get smallest prime factors
  vector<int> spf = smallest_prime_factor(max_rating);
  DSU dsu(n);
  // Map from prime to first index
  unordered_map<int, int> prime_to_index;
  for (int i = 0; i < n; i++) {
    int num = ratings[i];
    vector<int> primes = get_unique_prime_factors(num, spf);
    for (auto p : primes) {
      if (prime_to_index.find(p) == prime_to_index.end()) {
        prime_to_index[p] = i;
      } else {
        dsu.union_set(i, prime_to_index[p]);
      }
    }
  }
  // Count unique parents
  unordered_set<int> groups;
  for (int i = 0; i < n; i++) {
    groups.insert(dsu.find_set(i));
  }
  cout << groups.size();
}
