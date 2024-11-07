#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool is_palindrom(string s) {
  for (int i = 0; i < sz(s) / 2; i++) {
    if (s[i] != s[sz(s) - i - 1])
      return false;
  }
  return true;
}
void solve() {
  string s;
  cin >> s;
  ll n = sz(s);
  if (!is_palindrom(s)) {
    cout << "YES\n";
    cout << "1\n";
    cout << s << '\n';
    return;
  }
  ll k = n / 2;
  string s1 = s.substr(0, k);
  string s2 = s.substr(k, n - k);
  if (!is_palindrom(s1) && !is_palindrom(s2)) {
    cout << "YES\n";
    cout << "2\n";
    cout << s1 << ' ' << s2 << '\n';
    return;
  }
  cout << "NO\n";
  // if (n < 500) {
  //   for (int i = 0; i < n; i++) {
  //     ll k = i;
  //     string s1 = s.substr(0, k);
  //     string s2 = s.substr(k, n - k);
  //     if (!is_palindrom(s1) && !is_palindrom(s2)) {
  //       cout << "YES\n";
  //       cout << "2\n";
  //       cout << s1 << ' ' << s2 << '\n';
  //       return;
  //     }
  //   }
  //   cout << "NO\n";
  // } else {
  //   for (int i = 0; i < 500; i++) {
  //     ll k = rand() % n;
  //     string s1 = s.substr(0, k);
  //     string s2 = s.substr(k, n - k);
  //     if (!is_palindrom(s1) && !is_palindrom(s2)) {
  //       cout << "YES\n";
  //       cout << "2\n";
  //       cout << s1 << ' ' << s2 << '\n';
  //       return;
  //     }
  //   }
  //   cout << "NO\n";
  // }
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
