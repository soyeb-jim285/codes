#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    sum += a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end(), greater<pair<int, int>>());
  ll bg = a.front().first;
  if (bg > sum - bg) {
    cout << "impossible" << endl;
    return;
  } else {
    for (int i = 0; i < n; i++) {
      cout << a[i].second + 1 << ' ';
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
