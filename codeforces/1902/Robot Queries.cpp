#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

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
  map<pair<ll, ll>, set<int>> mp, rmp;
  fn(s, vc);
  reverse(s.begin(), s.end());
  fn(s, rvc);
  for (int i = 0; i < n; i++) {
    mp[vc[i]].insert(i);
    rmp[rvc[i]].insert(i);
  }
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
    if (mp[{x, y}].size()) {
      auto ic = upper_bound(mp[{x, y}].begin(), mp[{x, y}].end(), l - 1);
      ic--;
      if (*ic >= 0 && *ic <= l - 1) {
        ck = 1;
      }
      ic = upper_bound(mp[{x, y}].begin(), mp[{x, y}].end(), n - 1);
      ic--;
      if (*ic >= r + 1 && *ic < n)
        ck = 1;
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
    // cout << x << " " << y << "--find\n";
    if (rmp[{x, y}].size()) {
      auto ic = upper_bound(rmp[{x, y}].begin(), rmp[{x, y}].end(), n - 1 - l);
      ic--;
      if (*ic >= n - 1 - r && *ic <= n - 1 - l)
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
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
