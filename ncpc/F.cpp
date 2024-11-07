#include <bits/stdc++.h>
#include <queue>
#include <set>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, sum = -1e18, bst = -1e18;
  cin >> n;
  vector<ll> a(n);
  /* map<multiset<ll>, ll> mp; */
  vector<vector<ll>> v;
  vector<ll> tmp;
  ll mnlen = 1e18;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (sum + a[i] <= a[i]) {
      tmp.clear();
      sum = a[i];
    } else {
      sum += a[i];
    }
    tmp.push_back(a[i]);
    if (sum >= bst) {
      if (sum > bst || mnlen < tmp.size()) {
        /* mp.clear(); */
        v.clear();
        mnlen = 1e18;
      }
      if (mnlen < tmp.size()) {
        mnlen = tmp.size();
      }
      mnlen = min(mnlen, (ll)tmp.size());
      sort(tmp.begin(), tmp.end());
      v.push_back(tmp);
      /* mp[tmp]++; */
      bst = sum;
    }
  }
  map<pair<int, int>, int> mp;
  int M1 = 1e9 + 7;
  int M2 = 1e9 + 13;
  ll nnk = v.front().size();
  for (auto i : v) {
    int s1 = 0, s2 = 0;
    for (auto j : i)
      s1 *= 10, s2 *= 10, s1 += (j), s1 %= M1, s2 += j, s2 %= M2;
    mp[{s1, s2}]++;
  }
  int mxt = 0;
  for (auto ic : mp) {
    mxt = max(mxt, ic.second);
  }
  cout << mxt * nnk << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
