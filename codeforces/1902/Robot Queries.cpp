#include <algorithm>
#include <cstdio>
#include <utility>
#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll const p = 1e9 + 7;

ll hsh(ll x, ll y) { return x * p + y; }

void fn(string &str, vector<pair<ll, ll>> &vct) {
  ll up = 0, right = 0;
  ll n = vct.size();
  for (int i = 0; i < n; i++) {
    if (str[i] == 'U')
      up++;
    else if (str[i] == 'D')
      up--;
    else if (str[i] == 'R')
      right++;
    else
      right--;
    vct[i].first = right;
    vct[i].second = up;
  }
}

void solve() {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<pair<ll, ll>> vc(n), rvc(n);
  vector<pair<ll, ll>> mp, rmp;
  fn(s, vc);
  reverse(s.begin(), s.end());
  fn(s, rvc);
  for (int i = 0; i < n; i++) {
    mp.push_back({hsh(vc[i].first, vc[i].second), i});
    rmp.push_back({hsh(rvc[i].first, rvc[i].second), i});
  }
  sort(mp.begin(), mp.end());
  sort(rmp.begin(), rmp.end());
  // for (auto ic : vc)
  //   cout << ic.first << " " << ic.second << "\n";
  // cout << "----------\n";
  // for (auto ic : rvc)
  //   cout << ic.first << " " << ic.second << "\n";
  // cout << "----------\n";
  // for (auto ic : mp) {
  //   cout << "(" << ic.first.first << ", " << ic.first.second << ") =";
  //   for (auto i = ic.second.begin(); i != ic.second.end(); i++)
  //     cout << *i << ", ";
  //   cout << "\n";
  // }
  // cout << "---------------\n";
  // for (auto ic : rmp) {
  //   cout << "(" << ic.first.first << ", " << ic.first.second << ") =";
  //   for (auto i = ic.second.begin(); i != ic.second.end(); i++)
  //     cout << *i << ", ";
  //   cout << "\n";
  // }

  while (k--) {
    ll x, y, l, r;
    cin >> x >> y >> l >> r;
    if (x == 0 && y == 0) {
      cout << "YES\n";
      continue;
    }
    l--, r--;
    bool ck = 0;
    auto ic = upper_bound(mp.begin(), mp.end(), make_pair(hsh(x, y), l - 1));
    if (ic != mp.begin()) {
      ic--;
      if (ic->second >= 0 && ic->second <= l - 1 && ic->first == hsh(x, y))
        ck = 1;
    }
    // cout << ck << " 1\n";
    ic = upper_bound(mp.begin(), mp.end(), make_pair(hsh(x, y), n - 1));
    if (ic != mp.begin()) {
      ic--;
      if (ic->second >= r + 1 && ic->second < n && ic->first == hsh(x, y))
        ck = 1;
      // cout << ic->first << " " << ic->second << " " << hsh(x, y) << "\n";
      // cout << ck << " 2\n";
    }
    pair<ll, ll> fst, lst;
    if (r == n - 1)
      fst = {0, 0};
    else
      fst = rvc[n - 2 - r];
    if (l == 0)
      lst = {0, 0};
    else
      lst = vc[l - 1];
    x += (fst.first - lst.first);
    y += (fst.second - lst.second);
    // cout << x << " " << y << " " << ck << "--find\n";
    ic = upper_bound(rmp.begin(), rmp.end(), make_pair(hsh(x, y), n - 1 - l));
    if (ic != rmp.begin()) {
      ic--;
      if (ic->second >= n - 1 - r && ic->second <= n - 1 - l &&
          ic->first == hsh(x, y))
        ck = 1;
    }
    if (ck)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("input.in", "r", stdin);
  // freopen("output.out", "w", stdout);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
