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
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  vector<bool> ase(n), nai(n);
  set<ll> dorkar, paisi;
  for (int i = 0; i < n; i++) {
    if (dorkar.find(a[i]) == dorkar.end()) {
      paisi.insert(a[i]);
    } else {
      dorkar.erase(a[i]);
    }
    if (paisi.find(i + 1) == paisi.end()) {
      dorkar.insert(i + 1);
    } else {
      paisi.erase(i + 1);
    }
    if (sz(dorkar) == 0) {
      ase[i] = true;
    }
    if (sz(dorkar) == 1 && i != n - 1) {
      if (*dorkar.begin() == a[i + 1]) {
        nai[i] = true;
      }
    }
  }
  vector<ll> pref(n + 1), suff(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + ase[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    suff[i] = suff[i + 1] + ase[i];
  }
  // for (auto ic : ase)
  //   cout << ic << " ";
  // cout << "\n";
  // for (auto ic : nai)
  //   cout << ic << " ";
  // cout << "\n";
  // for (auto ic : pref)
  //   cout << ic << " ";
  // cout << "\n";
  // for (auto ic : suff)
  //   cout << ic << " ";
  // cout << "\n";
  ll ans = pref[n], or_sum = pref[n], maxh = 0, start = 0, end = 0;
  for (int i = 0; i < n; i += 2) {
    maxh += -ase[i] + nai[i];
    // cout << ans << " " << maxh << " " << pref[start] << " " << suff[i + 1]
    //      << " " << ase[i] << " " << nai[i] << "-*-\n";
    if (ans < maxh + pref[start] + suff[i + 1]) {
      ans = maxh + pref[start] + suff[i + 1];
    }
    if (maxh < 0) {
      maxh = 0;
      start = i + 2;
    }
    if (i != n && start != i + 2) {

      maxh += ase[i + 1];
    }
  }
  start = 1, end = 0, maxh = 0;
  for (int i = 1; i < n; i += 2) {
    maxh += -ase[i] + nai[i];
    // cout << ans << " " << maxh << " " << pref[start] << " " << suff[i + 1]
    //      << " " << ase[i] << " " << nai[i] << "-*-\n";
    if (ans < maxh + pref[start] + suff[i + 1]) {
      ans = maxh + pref[start] + suff[i + 1];
    }
    if (maxh < 0) {
      maxh = 0;
      start = i + 2;
    }
    if (i != n && start != i + 2) {

      maxh += ase[i + 1];
    }
  }
  cout << ans << '\n';
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
