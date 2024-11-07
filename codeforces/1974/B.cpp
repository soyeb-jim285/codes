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
  set<char> st;
  for (int i = 0; i < n; i++) {
    st.insert(s[i]);
  }
  vector<char> v;
  for (auto c : st) {
    v.push_back(c);
  }
  map<char, char> mp;
  for (int i = 0; i < sz(v); i++) {
    mp[v[i]] = v[sz(v) - 1 - i];
  }
  for (int i = 0; i < n; i++) {
    cout << mp[s[i]];
  }
  cout << '\n';
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
