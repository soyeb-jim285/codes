#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i].first >> vc[i].second;
  }
  sort(vc.begin(), vc.end());
  ll fst = -1, ct = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (vc[i].first == fst) {
      cnt++;
    } else {
      fst = vc[i].first;
      ct = 0;
      cnt = 1;
    }
    cout << vc[i].first + ct << "\n";
    if (cnt >= k) {
      cnt = 0;
      ct++;
    }
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
