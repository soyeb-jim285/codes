#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, q, ans = 0;
  cin >> n >> q;
  string s;
  cin >> s;
  map<pair<char, char>, int> mp, mpp;
  vector<int> pre(26), lst(26);
  for (int i = 0; i < n; i++) {
    mp[{s[i], s[(i + 1) % n]}]++;
    mpp[{s[i], s[(i + 1) % n]}] = 0;
  }
  while (q--) {
    string s;
    char x, y;
    cin >> s >> x >> y;
    if (s == "CUT") {
      int d = mp[{x, y}];
      ans += d;
      pre[(int)x - 'A'] += d;
      lst[(int)y - 'A'] += d;
      mp[{x, y}] = 0;
    } else {
      ll mn = min(pre[x - 'A'], lst[y - 'A']);
      pre[x - 'A'] -= mn;
      lst[y - 'A'] -= mn;
      ans -= mn;
      mp[{x, y}] += mn;
      mpp[{x, y}] = 0;
    }
    // for (int i = 0; i < 26; i++) {
    //   cout << (char)(i + 'A') << ": " << pre[i] << "\n";
    // }
    // for (int i = 0; i < 26; i++) {
    //   cout << (char)(i + 'A') << ": " << lst[i] << "\n";
    // }
    cout << ans << "\n";
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
