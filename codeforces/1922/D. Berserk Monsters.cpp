#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  vector<ll> vc(n + 2), hlt(n + 1), st, tmp;
  set<ll> ind;
  for (int i = 1; i <= n; i++) {
    cin >> vc[i];
    st.push_back(i);
    ind.insert(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> hlt[i];
  }
  ll ans = 0;
  bool ck = 0;
  vector<bool> check(n + 1, 0);
  for (int i = 0; i < n; i++) {
    if (ck || st.size() < 2) {
      cout << "0 ";
      continue;
    }
    vector<ll> gese;
    set<ll> s_tmp;
    for (int j = 0; j < st.size(); j++) {
      ll dmg = 0;
      if (j == 0) {
        dmg = vc[st[j + 1]];
      } else if (j == st.size() - 1) {
        dmg = vc[st[j - 1]];
      } else {
        dmg = vc[st[j - 1]] + vc[st[j + 1]];
      }
      if (dmg > hlt[st[j]]) {
        ans++;
        gese.push_back(st[j]);
        ind.erase(st[j]);
        check[j] = 1;
      }
    }
    for (int j = 0; j < gese.size(); j++) {
      auto ic = lower_bound(ind.begin(), ind.end(), gese[j]);
      if (ic != ind.begin()) {
        ic--;
        if (*ic < gese[j])
          s_tmp.insert(*ic);
      }
      ic = upper_bound(ind.begin(), ind.end(), gese[j]);
      if (ic != ind.end()) {
        if (*ic > gese[j])
          s_tmp.insert(*ic);
      }
    }
    while (s_tmp.size()) {
      tmp.push_back(*s_tmp.begin());
      s_tmp.erase(s_tmp.begin());
    }
    cout << ans << " ";
    if (ans == 0) {
      ck = 1;
    }
    st.clear();
    st = tmp;
    tmp.clear();
    ans = 0;
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
