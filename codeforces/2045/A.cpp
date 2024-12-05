#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool is_vowel(char c) {
  return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
void solve() {
  string s;
  cin >> s;
  ll ans = 0, vls = 0, ys = 0, ns = 0, gs = 0, others = 0;
  for (int i = 0; i < s.size(); i++) {
    if (is_vowel(s[i])) {
      vls++;
    } else if (s[i] == 'Y') {
      ys++;
    } else if (s[i] == 'N') {
      ns++;
    } else if (s[i] == 'G') {
      gs++;
    } else {
      others++;
    }
  }
  cout << ans << endl;
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
