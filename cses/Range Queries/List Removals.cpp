#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 2e5 + 9;
int arr[N];
int tree[4 * N];
void build(int v, int tl, int tr) {
  if (tl == tr) {
    tree[v] = arr[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
  }
}
void update(int v, int tl, int tr, int pos, int new_val) {
  if (tl == tr) {
    tree[v] = new_val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v * 2, tl, tm, pos, new_val);
    else
      update(v * 2 + 1, tm + 1, tr, pos, new_val);
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
  }
}
ll quary(int v, int cnt, int tl, int tr) {
  if (tl == tr) {
    return tl;
  }
  ll tm = (tl + tr) / 2;
  if (tree[v * 2] >= cnt) {
    return quary(v * 2, cnt, tl, tm);
  } else {
    return quary(v * 2 + 1, cnt - tree[v * 2], tm + 1, tr);
  }
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    arr[i] = 1;
  }
  build(1, 0, n - 1);
  // for (int i = 0; i < 3 * n; i++) {
  //   cout << tree[i] << ' ';
  // }
  // cout << '\n';
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    ll ans = quary(1, x, 0, n - 1);
    // cout << ans << " --\n";
    cout << a[ans] << ' ';
    update(1, 0, n - 1, ans, 0);
    // for (int i = 0; i < 3 * n; i++) {
    //   cout << tree[i] << ' ';
    // }
    // cout << '\n';
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
