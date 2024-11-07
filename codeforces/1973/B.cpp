#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool fn(ll mid, vector<vector<ll>> &sparse_table, vector<ll> &a) {
  ll n = a.size();
  ll orr = -1;
  for (int i = 0; i < n - mid + 1; i++) {
    ll l = i, r = i + mid - 1;
    int k = log2(r - l + 1);
    ll cur = sparse_table[k][l] | sparse_table[k][r - (1 << k) + 1];
    if (orr == -1) {
      orr = cur;
    } else {
      if (orr != cur)
        return false;
    }
  }
  return true;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a) {
    cin >> x;
  }
  ll k = log2(n);
  vector<vector<ll>> sparse_table(k + 1, vector<ll>(n));
  // copy(a.begin(), a.end(), sparse_table[0]);
  for (ll i = 0; i < n; i++) {
    sparse_table[0][i] = a[i];
  }
  for (ll i = 1; i <= k; i++) {
    for (ll j = 0; j + (1 << i) <= n; j++) {
      sparse_table[i][j] =
          sparse_table[i - 1][j] | sparse_table[i - 1][j + (1 << (i - 1))];
    }
  }
  ll low = 1, high = n;
  while (low <= high) {
    ll mid = (low + high) / 2;
    if (fn(mid, sparse_table, a)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
