#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int const N = 1e6 + 1;
int tree[4 * N];
int arr[N];
void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    tree[v] += val;
    return;
  }
  int tm = (tl + tr) >> 1;
  if (pos <= tm)
    update(2 * v, tl, tm, pos, val);
  else
    update(2 * v + 1, tm + 1, tr, pos, val);
  tree[v] = tree[2 * v] + tree[2 * v + 1];
}
int sum(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;
  if (l == tl && r == tr) {
    return tree[v];
  }
  int tm = (tl + tr) >> 1;
  return sum(v * 2, tl, tm, l, min(r, tm)) +
         sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  map<int, int> bck, frnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    bck[a[i]]++;
  }
  vector<int> left(n), right(n);
  for (int i = 0; i < n; i++) {
    frnt[a[i]]++;
    left[i] = frnt[a[i]];
    right[i] = bck[a[i]];
    bck[a[i]]--;
  }
  ll ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans += sum(1, 0, n, 1, left[i] - 1);
    update(1, 0, n, right[i], 1);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("input.in", "r", stdin);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
