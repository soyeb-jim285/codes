#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, sum = 0, tmp = 0;
  cin >> n;
  string a, b;
  cin >> a >> b;
  bool paisi = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 'b' || b[i] == 'b') {
      if (a[i] == b[i]) {
        paisi = 1;
        sum += tmp;
        tmp = 0;
      } else {
        cout << "NO\n";
        return;
      }
    }
    if (a[i] == 'a' && b[i] == 'c') {
      tmp++;
    }
    if (a[i] == 'c' && b[i] == 'a') {
      if (paisi)
        sum--;
      else {
        cout << "NO\n";
        return;
      }
      if (sum == 0) {
        paisi = 0;
      }
      if (sum < 0) {
        cout << "NO\n";
        return;
      }
    }
  }
  if (sum == 0 && tmp == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
