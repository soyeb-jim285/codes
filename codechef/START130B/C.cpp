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
  string s;
  cin >> s;
  vector<ll> ans;
  for (int i = 0; i < n; i += 2) {
    if (s[i] != s[i + 1]) {
      if (ans.size() % 2 == 0) {
        if (s[i] == '1') {
          ans.push_back(i + 1);
        } else
          ans.push_back(i + 2);
      } else {
        if (s[i] == '0')
          ans.push_back(i + 1);
        else
          ans.push_back(i + 2);
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto x : ans)
    cout << x << " ";
  cout << "\n";
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
