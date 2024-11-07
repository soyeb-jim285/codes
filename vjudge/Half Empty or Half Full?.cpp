#include <bits/stdc++.h>
#include <utility>
using namespace std;
H
#define sz(a) ((int)((a).size()))

    typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool good(pair<ll, ll> &p) { return 2 * p.second > p.first; }
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].second;
  }
  pair<ll, ll> lst_good = {-1, -1}, bad = {0, 0};
  ll l, r;
  vector<pair<ll, ll>> ans;
  ll gd = 0, bd = 0;
  for (int i = 0; i < n; i++) {
    if (good(a[i])) {
      gd++;
      if (lst_good.first != -1) {
        r = i;
        if (l != r) {
          ans.push_back({l, r});
        }
      }
      lst_good = a[i];
      if (bad.first || bad.second && lst_good.first == -1) {
        pair<ll, ll> p = {lst_good.first + bad.first,
                          lst_good.second + bad.second};
        if (good(p)) {
          lst_good = p;
          ans.push_back({l, i + 1});
        } else {
          ans.push_back({l, i});
          bd++;
        }
      }
      l = i + 1;
    } else {
      bad.first += a[i].first;
      bad.second += a[i].second;
      if (lst_good.first == -1) {
        l = i + 1;
      } else {
        pair<ll, ll> p = {lst_good.first + bad.first,
                          lst_good.second + bad.second};
        r = i + 1;
        if (good(p)) {
        } else {
          l = i + 1;
          if (l != r) {
            ans.push_back({l, r});
            bad.first = 0;
            bad.second = 0;
            lst_good = {-1, -1};
          }
        }
      }
    }
  }
  pair<ll, ll> p = {lst_good.first + bad.first, lst_good.second + bad.second};
  if (good(p)) {
    if (l != n)
      ans.push_back({l, n});
  } else {
    if (l != n) {
      ans.push_back({l, n});
      bd++;
    }
  }
  if (gd > bd) {
    cout << "Yes\n";
    cout << sz(ans) << "\n";
    for (auto p : ans) {
      cout << p.first << " " << p.second << "\n";
    }
  } else {
    cout << "No\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
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
