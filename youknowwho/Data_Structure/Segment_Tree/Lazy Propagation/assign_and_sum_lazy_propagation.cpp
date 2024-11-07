#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll gcd(ll X, ll Y) { return !Y ? X : gcd(Y, X % Y); }
ll lcm(ll X, ll Y) { return X * Y / gcd(X, Y); }

const int N = 1e5 + 9;
int a[N];
ll t[4 * N], lazy[4 * N];
void push(int n, int b, int e) {
  if (lazy[n] == 0)
    return;
  t[n] = lazy[n] * (e - b + 1);
  if (b != e) {
    lazy[2 * n] = lazy[n];
    lazy[2 * n + 1] = lazy[n];
  }
  lazy[n] = 0;
}

void upd(int n, int b, int e, int i, int j, long long v) {
  push(n, b, e);

  if (j < b || e < i)
    return;
  if (i <= b && e <= j) {
    lazy[n] = v; // set lazy
    if (lazy[n] == 0)
      return;
    t[n] = lazy[n] * (e - b + 1);
    if (b != e) {
      lazy[2 * n] = lazy[n];
      lazy[2 * n + 1] = lazy[n];
    }
    lazy[n] = 0;
    return;
  }
  int mid = (b + e) >> 1;
  upd(2 * n, b, mid, i, j, v);
  upd(2 * n + 1, mid + 1, e, i, j, v);
  t[n] = t[2 * n] + t[2 * n + 1];
}
ll query(int n, int b, int e, int i, int j) {

  push(n, b, e);
  if (i > e || b > j)
    return 0; // return null
  if (i <= b && e <= j)
    return t[n];
  int mid = (b + e) >> 1;
  return query(2 * n, b, mid, i, j) + query(2 * n + 1, mid + 1, e, i, j);
}

void solve() {
  ll n, m;
  cin >> n >> m;
  memset(t, 0, sizeof t);
  memset(lazy, 0, sizeof lazy);
  // for (ll i = 1; i < 16; i++)
  // {
  //     cout << t[i] << " ";
  // }
  // cout << endl;
  for (ll i = 0; i < m; i++) {
    ll x;
    cin >> x;
    if (x == 1) {
      ll l, r, val;
      cin >> l >> r >> val;
      upd(1, 1, n, l, r, val);
    } else {
      ll l, r;
      cin >> l >> r;
      ll ans = query(1, 1, n, l, r);
      cout << ans << endl;
    }
    // for (ll i = 1; i < 16; i++)
    // {
    //     cout << t[i] << " ";
    // }
    // cout << endl;
  }
}
int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  int t = 1;
  // cin>>t;
  while (t--) {
    solve();
  }
}
