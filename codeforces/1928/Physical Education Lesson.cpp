#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, x;
  cin >> n >> x;
  set<ll> st;
  ll low = n - x;
  ll high = n + x - 2;
  if (low % 2 == 0) {
    low /= 2;
    for (ll i = 1; i * i <= low; i++) {
      if (low % i == 0) {
        if (i + 1 >= x)
          st.insert(i);
        if (low / i + 1 >= x)
          st.insert(low / i);
      }
    }
  }
  if (high % 2 == 0) {
    high /= 2;
    for (ll i = 1; i * i <= high; i++) {
      if (high % i == 0) {
        if (i + 1 >= x)
          st.insert(i);
        if (high / i + 1 >= x)
          st.insert(high / i);
      }
    }
  }
  cout << st.size() << "\n";
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
