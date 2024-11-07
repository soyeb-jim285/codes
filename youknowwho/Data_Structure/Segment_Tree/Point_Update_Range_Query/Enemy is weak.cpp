#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 1e6 + 1;
vector<pair<ll, ll>> tree(4 * N);
vector<pair<ll, ll>> arr(N);
void build(ll v, ll tl, ll tr) {
  if (tl == tr) {
    tree[v] = arr[tl];
    return;
  }
  ll tm = (tl + tr) / 2;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm + 1, tr);
  tree[v].first = tree[2 * v].first + tree[2 * v + 1].first;
  tree[v].second = tree[2 * v].second + tree[2 * v + 1].second;
}
void update(ll v, ll tl, ll tr, ll pos, pair<ll, ll> val) {
  if (tl == tr) {
    tree[v].first += val.first;
    tree[v].second += val.second;
    return;
  }
  ll tm = (tl + tr) / 2;
  if (pos <= tm)
    update(2 * v, tl, tm, pos, val);
  else
    update(2 * v + 1, tm + 1, tr, pos, val);
  tree[v].first = tree[2 * v].first + tree[2 * v + 1].first;
  tree[v].second = tree[2 * v].second + tree[2 * v + 1].second;
}
pair<ll, ll> query(ll v, ll tl, ll tr, ll l, ll r) {
  if (l > r)
    return {0, 0};
  if (l == tl && r == tr) {
    return tree[v];
  }
  ll tm = (tl + tr) / 2;
  pair<ll, ll> left = query(v * 2, tl, tm, l, min(r, tm));
  pair<ll, ll> right = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  return {left.first + right.first, left.second + right.second};
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> b = a;
  sort(b.begin(), b.end());
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    mp[b[i]] = i;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    a[i] = mp[a[i]];
    auto as = query(1, 0, n - 1, a[i] + 1, n - 1);
    ans += as.second;
    update(1, 0, n - 1, a[i], {1, as.first});
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
