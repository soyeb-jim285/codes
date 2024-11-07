#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> vc(n);
  vector<pair<ll, ll>> pr(n, {-1, -1});
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  ll a = vc[0], a_ind = 0;
  for (int i = 1; i < n; i++) {
    if (vc[i] == vc[i - 1]) {
      pr[i].first = pr[i - 1].first;
      pr[i].second = pr[i - 1].second + 1;
    } else {
      pr[i].first = i - 1;
      pr[i].second = i;
    }
  }
  /* for (auto ic : pr) { */
  /*   cout << ic.first << ' ' << ic.second << '\n'; */
  /* } */
  ll q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    l--, r--;
    if (pr[r].first < l) {
      /* cout << pr[r].first + 1 << ' ' << pr[r].second + 1 << "--------\n"; */
      cout << "-1 -1\n";
    } else {
      cout << pr[r].first + 1 << ' ' << pr[r].second + 1 << '\n';
    }
  }
  cout << "\n";
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
