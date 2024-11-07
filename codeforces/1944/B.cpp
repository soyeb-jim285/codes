#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n), dupa, siga, dupb, sigb;
  map<ll, ll> cnta, cntb;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    cnta[a[i]]++;
  }
  for (ll i = 0; i < n; i++) {
    cin >> b[i];
    cntb[b[i]]++;
  }
  for (auto ic : cnta) {
    if (ic.second == 2) {
      dupa.push_back(ic.first);
    } else {
      siga.push_back(ic.first);
    }
  }
  for (auto ic : cntb) {
    if (ic.second == 2) {
      dupb.push_back(ic.first);
    } else {
      sigb.push_back(ic.first);
    }
  }
  sort(siga.begin(), siga.end());
  sort(sigb.begin(), sigb.end());
  vector<ll> ansa, ansb;
  if (dupa.size() >= k) {
    for (int i = 0; i < k; i++) {
      ansa.push_back(dupa[i]);
      ansa.push_back(dupa[i]);
      ansb.push_back(dupb[i]);
      ansb.push_back(dupb[i]);
    }
  } else {
    for (int i = 0; i < dupa.size(); i++) {
      ansa.push_back(dupa[i]);
      ansa.push_back(dupa[i]);
      ansb.push_back(dupb[i]);
      ansb.push_back(dupb[i]);
    }
    k -= dupa.size();
    for (int i = 0; i < 2 * k; i++) {
      ansa.push_back(siga[i]);
      ansb.push_back(sigb[i]);
    }
  }
  for (auto ic : ansa) {
    cout << ic << " ";
  }
  cout << "\n";
  for (auto ic : ansb) {
    cout << ic << " ";
  }
  cout << "\n";
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
