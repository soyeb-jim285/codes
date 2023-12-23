#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> vc(n);
  set<ll> st;
  ll ct = 1;
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  for (int i = 1; i < 10000; i++) {
    for (int j = 0; j < n; j++) {
      st.insert(vc[j] % i);
    }
    if (st.size() == 2) {
      cout << i << "\n";
    }
    st.clear();
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
