#include <bits/stdc++.h>
#include <functional>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll ans = n * (n + 1) / 2;
  vector<ll> odds;
  ll odd = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2) {
      odd++;
    } else {
      odds.push_back(odd);
      odd = 0;
    }
  }
  odds.push_back(odd);
  sort(odds.begin(), odds.end(), greater<ll>());
  for (int i = 0; i < sz(odds); i++) {
    if (i == 0) {
      odds[i]--;
      ll a = odds[i] / 2;
      ll b = odds[i] - a;
      ans -= a * (a + 1) / 2;
      ans -= b * (b + 1) / 2;
    } else {
      ans -= odds[i] * (odds[i] + 1) / 2;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
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
