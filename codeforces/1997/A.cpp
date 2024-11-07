#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string s;
  cin >> s;
  char x = s.back() + 1;
  int indx = sz(s) - 1;
  for (int i = 0; i < sz(s) - 1; i++) {
    if (s[i] == s[i + 1]) {
      indx = i;
      x = s[i] + 1;
    }
  }
  if (x > 'z')
    x = 'a';
  for (int i = 0; i < sz(s); i++) {
    cout << s[i];
    if (i == indx)
      cout << x;
  }
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
