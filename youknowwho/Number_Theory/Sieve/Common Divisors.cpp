#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll N = 1e6 + 1;
vector<int> counts(N);
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    const int a = sqrt(x);
    for (int j = 1; j <= a; j++) {
      if (x % j == 0) {
        counts[j]++;
        if (j * j != x) {
          counts[x / j]++;
        }
      }
    }
  }
  for (int i = N - 1; i >= 1; i--) {
    if (counts[i] > 1) {
      cout << i << endl;
      return;
    }
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
