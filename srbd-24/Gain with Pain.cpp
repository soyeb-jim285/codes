#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<int> perf = {2, 3, 10, 2, 3, 10, 2, 3, 10, 1, 3, 10, 3, 3, 10};
void solve() {
  int n;
  cin >> n;
  vector<int> tmp;
  bool hoise = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3 * 5; j++) {
      int x;
      cin >> x;
      tmp.push_back(x);
    }
    if (tmp != perf)
      hoise = false;
    tmp.clear();
  }
  if (hoise)
    cout << "Consistent\n";
  else
    cout << "Inconsistent\n";
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
