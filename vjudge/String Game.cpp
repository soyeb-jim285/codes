#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool fn(ll ind, string &str, string &s, vector<ll> &p) {
  // cout << ind << "---ind\n";
  string newstr = "";
  vector<bool> v(str.size(), 0);
  for (int i = 0; i < ind; i++) {
    v[p[i] - 1] = 1;
  }
  // for (auto ic : v)
  //   cout << ic << " ";
  // cout << "\n";
  for (int i = 0; i < v.size(); i++) {
    if (!v[i])
      newstr += str[i];
  }
  // cout << newstr << "-----string\n";
  ll ct = 0;
  // cout << s.size() << "\n";
  for (int i = 0; i < newstr.size(); i++) {
    if (s[ct] == newstr[i]) {
      // cout << s[ct] << "--ok\n";
      ct++;
    }
    if (ct >= s.size())
      return 1;
  }
  return 0;
}
void solve() {
  string str, s;
  cin >> str >> s;
  int n = str.size();
  vector<ll> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  ll low = 0, high = n;
  while (high - low > 1) {
    ll mid = (low + high) / 2;
    if (fn(mid, str, s, p)) {
      low = mid;
    } else
      high = mid;
  }
  cout << low << "\n";
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
