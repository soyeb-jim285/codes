#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
bool is_good(vector<ll> &a, string &s) {
  ll n = sz(a);
  set<ll> st;
  for (int i = 0; i < n; i++) {
    st.insert(a[i]);
    if (s[i] == 'p') {
      ll a = *st.rbegin();
      if (a != st.size()) {
        return false;
      }
    }
  }
  st.clear();
  for (int i = n - 1; i >= 0; i--) {
    st.insert(a[i]);
    if (s[i] == 's') {
      ll a = *st.rbegin();
      if (a != st.size()) {
        return false;
      }
    }
  }
  return true;
}
void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> ans1(n), ans2(n);
  iota(all(ans1), 1);
  ans2 = ans1;
  reverse(all(ans2));
  if (is_good(ans1, s) || is_good(ans2, s)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
