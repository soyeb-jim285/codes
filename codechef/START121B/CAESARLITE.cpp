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
  string s1, s2;
  cin >> s1 >> s2;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    ll k = s2[i] - s1[i];
    if (k < 0)
      k += 26;
    while (k % 3 != 0) {
      k += 26;
    }
    a[i] = k / 3;
  }
  for (auto x : a) {
    cout << x << " ";
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
