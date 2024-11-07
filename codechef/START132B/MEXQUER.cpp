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
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  ll age = 0;
  for (int i = 0; i < n; i++) {
    if (age == -1) {
      cout << "-1 ";
      continue;
    }
    cout << age + vc[i] << " ";
    if (vc[i] == 0) {
      ll ind = i;
      bool paisi = 0;
      while (ind > 0) {
        ind /= 2;
        age++;
        if (vc[ind] > 1) {
          vc[ind]--;
          paisi = 1;
          break;
        }
      }
      if (!paisi)
        age = -1;
    }
  }
  cout << age << "\n";
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
