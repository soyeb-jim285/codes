#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int const N = 3e4 + 1;
int tree[3 * N];
int arr[N];
void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    tree[v] = val;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm)
    update(2 * v, tl, tm, pos, val);
  else
    update(2 * v + 1, tm + 1, tr, pos, val);
  tree[v] = tree[2 * v] + tree[2 * v + 1];
}
ll sum(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;
  if (l == tl && r == tr) {
    return tree[v];
  }
  int tm = (tl + tr) / 2;
  return sum(v * 2, tl, tm, l, min(r, tm)) +
         sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void solve() {
  ll n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end(), greater<pair<int, int>>());
  ll q;
  cin >> q;
  vector<pair<int, int>> qua(q);
  int ranges[q][2];
  for (int i = 0; i < q; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    qua[i].first = k;
    qua[i].second = i;
    ranges[i][0] = l - 1;
    ranges[i][1] = r - 1;
  }
  sort(qua.begin(), qua.end(), greater<pair<int, int>>());
  vector<int> ans(q);
  for (int i = 0; i < q; i++) {
    int k = qua[i].first;
    int indx = 0;
    while (indx < n && a[indx].first > k) {
      update(1, 0, n - 1, a[indx].second, 1);
      indx++;
    }
    int as =
        sum(1, 0, n - 1, ranges[qua[i].second][0], ranges[qua[i].second][1]);
    ans[qua[i].second] = as;
  }
  for (auto ic : ans) {
    cout << ic << "\n";
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
