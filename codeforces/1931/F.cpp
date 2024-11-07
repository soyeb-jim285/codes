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
  vector<vector<ll>> vc(k, vector<ll>(n));
  vector<ll> ans, tmp;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      cin >> vc[i][j];
      if (i == 0 && j > 0)
        tmp.push_back(vc[i][j]);
    }
  }
  if (k == 1) {
    cout << "YES\n";
    return;
  }
  ll left = -1, right = -1;
  for (int i = 1; i < n; i++) {
    if (vc[1][i] == vc[0][0]) {
      if (i - 1 >= 1)
        left = i - 1;
      if (i + 1 < n)
        right = i + 1;
    }
  }
  vector<vector<ll>> maybe;
  bool paisi = 0;
  if (right == -1 && left == -1) {
    maybe.push_back(vc[1]);
    reverse(vc[1].begin(), vc[1].end());
    maybe.push_back(vc[1]);
  } else if (right == -1) {
    vector<ll> tmp2;
    for (int i = 1; i < n; i++) {
      if (vc[0][i] == vc[1][left]) {
        tmp2.push_back(vc[0][i]);
        tmp2.push_back(vc[0][0]);
      } else {
        tmp2.push_back(vc[0][i]);
      }
    }
    maybe.push_back(tmp2);
    for (int i = 0; i < n; i++) {
      if (tmp2[i] == vc[0][0]) {
        swap(tmp2[i], tmp2[i + 1]);
        break;
      }
    }
    maybe.push_back(tmp2);
  } else if (left == -1) {
    vector<ll> tmp2;
    for (int i = 1; i < n; i++) {
      if (vc[0][i] == vc[1][right]) {
        tmp2.push_back(vc[0][0]);
        tmp2.push_back(vc[0][i]);
      } else {
        tmp2.push_back(vc[0][i]);
      }
    }
    maybe.push_back(tmp2);
    for (int i = 0; i < n; i++) {
      if (tmp2[i] == vc[0][0]) {
        swap(tmp2[i], tmp2[i + 1]);
        break;
      }
    }
    maybe.push_back(tmp2);
  } else {
    vector<ll> tmp2;
    for (int i = 1; i < n; i++) {
      if (vc[0][i] == vc[1][left] && vc[0][i + 1] == vc[1][right]) {
        tmp2.push_back(vc[0][i]);
        tmp2.push_back(vc[0][0]);
      } else {
        tmp2.push_back(vc[0][i]);
      }
    }
    maybe.push_back(tmp2);
  }
  bool ok = 1;
  /* for (auto it : maybe) { */
  /*   for (auto it2 : it) { */
  /*     cout << it2 << " "; */
  /*   } */
  /*   cout << endl; */
  /* } */
  /* cout << "\n"; */
  for (int i = 0; i < sz(maybe); i++) {
    ok = 1;
    for (int j = 0; j < k; j++) {
      vector<ll> tmp;
      tmp.push_back(vc[j][0]);
      for (int kk = 0; kk < n; kk++) {
        if (maybe[i][kk] != vc[j][0])
          tmp.push_back(maybe[i][kk]);
      }
      if (tmp != vc[j]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
      return;
    }
  }
  if (ok)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
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
