#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int LIM = 1e6;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;
bitset<LIM> isPrime;
vector<int> not_primes;
vector<int> eratosthenes() {
  const int S = 1e3, R = LIM / 2;
  vi pr = {2}, sieve(S + 1);
  pr.reserve(int(LIM / log(LIM) * 1.1));
  vector<pii> cp;
  for (int i = 3; i <= S; i += 2)
    if (!sieve[i]) {
      cp.push_back({i, i * i / 2});
      for (int j = i * i; j <= S; j += 2 * i)
        sieve[j] = 1;
    }
  for (int L = 1; L <= R; L += S) {
    array<bool, S> block{};
    for (auto &[p, idx] : cp)
      for (int i = idx; i < S + L; idx = (i += p))
        block[i - L] = 1;
    rep(i, 0, min(S, R - L)) if (!block[i]) pr.push_back((L + i) * 2 + 1);
  }
  for (int i : pr)
    isPrime[i] = 1;
  return pr;
}
vector<ll> ans(LIM, 0);
ll n;
bool fn(ll mid, ll val) {
  if (not_primes[mid] >= val) {
    return true;
  }
  return false;
}
bool dfs(int u, int p, int ind, ll &mx, vector<vector<int>> &adj,
         vector<bool> &used) {
  ll low = ind, high = LIM - 1;
  while (low < high) {
    ll mid = (low + high) / 2;
    if (fn(mid, mx + 1 - ans[p])) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  ll k = not_primes[low] + ans[p];
  ans[u] = k;
  used[k] = true;
  if (ans[u] > 2 * n)
    return false;
  ind = 0;
  mx = max(mx, ans[u]);
  for (auto v : adj[u]) {
    if (v == p)
      continue;
    dfs(v, u, ind, mx, adj, used);
    ind++;
  }
  return true;
}
void solve() {
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<bool> used(2 * n, false);
  ll mx = 0;
  if (!dfs(0, 0, 0, mx, adj, used)) {
    cout << "-1\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
    ans[i] = 0;
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  eratosthenes();
  for (int i = 1; i < LIM; i++) {
    if (!isPrime[i]) {
      not_primes.push_back(i);
    }
  }
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
