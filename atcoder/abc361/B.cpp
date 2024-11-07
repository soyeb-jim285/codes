#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool overlap(int start1, int end1, int start2, int end2) {
  return (start1 <= start2 && start2 <= end1) or
         (start1 <= end2 && end2 <= end1) or
         (start2 <= start1 && start1 <= end2) or
         (start2 <= end1 && end1 <= end2);
}
void solve() {
  vector<int> a(6), b(6);
  for (int i = 0; i < 6; i++)
    cin >> a[i];
  for (int i = 0; i < 6; i++)
    cin >> b[i];
  ll val = 0;
  for (int i = 0; i < 3; i++) {
    if (overlap(a[i], a[i + 3], b[i], b[i + 3])) {
      val++;
    }
  }
  cout << val << endl;
  if (val > 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
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
