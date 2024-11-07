#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int const N = 2e5 + 9;
int const INF = 2e9 + 9;
int t[4 * N];
int lazy[4 * N];
int a[N];
void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
}

void push(int v) {
  t[v * 2] += lazy[v];
  lazy[v * 2] += lazy[v];
  t[v * 2 + 1] += lazy[v];
  lazy[v * 2 + 1] += lazy[v];
  lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
  if (l > r)
    return;
  if (l == tl && tr == r) {
    t[v] += addend;
    lazy[v] += addend;
  } else {
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), addend);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
}

int query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return -INF;
  if (l == tl && tr == r)
    return t[v];
  push(v);
  int tm = (tl + tr) / 2;
  return max(query(v * 2, tl, tm, l, min(r, tm)),
             query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
void solve() {
  ll n, q;
  cin >> n >> q;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  for (int i = 1; i < n + 1; i++) {
    a[i] = a[i - 1] + vc[i - 1];
  }
  build(1, 0, n);
  while (q--) {
    int x;
    cin >> x;
    if (x == 1) {
      ll k, u;
      cin >> k >> u;
      update(1, 0, n, k, n, u - vc[k - 1]);
      vc[k - 1] = u;
    } else {
      ll l, r;
      cin >> l >> r;
      cout << max(query(1, 0, n, l, r) - a[l - 1], 0) << '\n';
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
