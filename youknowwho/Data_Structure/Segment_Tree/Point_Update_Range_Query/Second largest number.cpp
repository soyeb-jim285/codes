#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 1e5 + 9;
pair<ll, ll> tree[4 * N];
ll arr[N];
void build(ll v, ll l, ll r) {
  if (l == r) {
    tree[v] = {arr[l], -1};
    return;
  }
  ll m = (l + r) / 2;
  build(2 * v, l, m);
  build(2 * v + 1, m + 1, r);
  set<ll> s;
  s.insert(tree[2 * v].first);
  s.insert(tree[2 * v].second);
  s.insert(tree[2 * v + 1].first);
  s.insert(tree[2 * v + 1].second);
  tree[v].first = *--s.end();
  s.erase(--s.end());
  tree[v].second = *--s.end();
}
void update(ll v, ll l, ll r, ll pos, ll val) {
  if (l == r) {
    tree[v] = {val, -1};
    return;
  }
  ll m = (l + r) / 2;
  if (pos <= m)
    update(2 * v, l, m, pos, val);
  else
    update(2 * v + 1, m + 1, r, pos, val);
  set<ll> s;
  s.insert(tree[2 * v].first);
  s.insert(tree[2 * v].second);
  s.insert(tree[2 * v + 1].first);
  s.insert(tree[2 * v + 1].second);
  tree[v].first = *--s.end();
  s.erase(--s.end());
  tree[v].second = *--s.end();
}
pair<ll, ll> second_max(ll v, ll tl, ll tr, ll l, ll r) {
  if (l > r)
    return {-1, -1};
  if (l == tl && r == tr) {
    return tree[v];
  }
  ll tm = (tl + tr) / 2;
  pair<ll, ll> tmp1 = second_max(2 * v, tl, tm, l, min(tm, r));
  pair<ll, ll> tmp2 = second_max(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
  set<ll> s;
  s.insert(tmp1.first);
  s.insert(tmp1.second);
  s.insert(tmp2.first);
  s.insert(tmp2.second);
  pair<ll, ll> ans;
  ans.first = *--s.end();
  s.erase(--s.end());
  ans.second = *--s.end();
  return ans;
}

void solve() {
  ll n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(1, 0, n - 1);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos, val;
      cin >> pos >> val;
      pos--;
      update(1, 0, n - 1, pos, val);
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      pair<ll, ll> ans = second_max(1, 0, n - 1, l, r);
      cout << ans.second << "\n";
    }
  }
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
