#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  multiset<ll> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  ll xl = 1, xr = 1e10;
  ll lst = -1;
  for (int i = n - 1; i >= 0; i--) {
    ll x = *--s.end();
    s.erase(s.find(a[i]));
    if(a[i] < x) {
      if(lst -1 == i){
        cout << "NO\n";
        return;
      }
      lst = i;
      xl = max(xl, x - a[i]);
      if(i!= n-1)
      xr = min(xr, a[i+1] - a[i]);
      if(xr < xl){
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
#ifdef ONPC
  cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
