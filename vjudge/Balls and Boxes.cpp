#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, m, mn = 1e16, ind = -1;
  cin >> n >> m;
  vector<ll> a(n), b(n);
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] < mn) {
      mn = a[i];
      ind = i;
    }
  }
  b = a;
  if (mn == a[m - 1]) {
    ind = m - 1;
  }
  ll sum = 0;
  if (ind + 1 > m) {
    for (int i = 0; i < m; i++) {
      a[i] -= (mn + 1);
      sum += (mn + 1);
      if (a[i] < 0) {
        a = b;
        for (int i = 0; i < n; i++) {
          cout << a[i] << " ";
        }
        cout << "\n";
        return;
      }
    }
    for (int i = m; i <= ind; i++) {
      a[i] -= mn;
      sum += mn;
    }
    for (int i = ind + 1; i < n; i++) {
      a[i] -= (mn + 1);
      sum += (mn + 1);
      if (a[i] < 0) {
        a = b;
        for (int i = 0; i < n; i++) {
          cout << a[i] << " ";
        }
        cout << "\n";
        return;
      }
    }
  } else {
    for (int i = 0; i <= ind; i++) {
      a[i] -= mn;
      sum += mn;
    }
    for (int i = ind + 1; i < m; i++) {
      a[i] -= (mn + 1);
      sum += (mn + 1);
      if (a[i] < 0) {
        a = b;
        for (int i = 0; i < n; i++) {
          cout << a[i] << " ";
        }
        cout << "\n";
        return;
      }
    }
    for (int i = m; i < n; i++) {
      a[i] -= mn;
      sum += mn;
    }
  }
  a[ind] += sum;
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
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
