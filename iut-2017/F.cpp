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
  vector<pair<ll, ll>> ans;
  string s;
  getline(cin, s);
  getline(cin, s);
  vector<string> vc;
  string tmp = "";
  for (int i = 0; i < sz(s); i++) {
    if (s[i] == '+') {
      vc.push_back(tmp);
      tmp = "";
    } else {
      tmp += s[i];
    }
  }
  vc.push_back(tmp);
  for (int i = 0; i < sz(vc); i++) {
    if (vc[i].back() == ' ') {
      vc[i].pop_back();
    }
    if (vc[i].front() == ' ') {
      vc[i].erase(vc[i].begin());
    }
    // cout << vc[i] << endl;
    ll coeff = 0, ct = 0;
    if (vc[i][ct] == 'X') {
      coeff = 1;
      ct++;
    } else {
      while (ct < sz(vc[i])) {
        if (vc[i][ct] == '*' || vc[i][ct] == 'X') {
          break;
        }
        coeff = coeff * 10 + (vc[i][ct] - '0');
        ct++;
      }
    }
    ct--;
    // cout << ct << " -**-" << endl;
    ll pow = 0;
    while (ct < sz(vc[i])) {
      if (vc[i][ct] == 'X')
        pow = 1;
      if (vc[i][ct] == '^') {
        ct++;
        pow = 0;
        while (ct < sz(vc[i])) {
          pow = pow * 10 + (vc[i][ct] - '0');
          ct++;
        }
        break;
      }
      ct++;
    }
    // cout << coeff << " " << pow << endl;
    for (int ii = 0; ii < n; ii++) {
      coeff *= pow;
      pow--;
    }
    ans.push_back({coeff, pow});
  }
  vector<string> anss;
  for (auto ic : ans) {
    if (ic.first == 0) {
      anss.push_back("0");
      break;
    }
    if (ic.first != 1)
      anss.push_back(to_string(ic.first));
    if (ic.second > 0) {
      if (ic.first != 1)
        anss.push_back("*");
      anss.push_back("X");
      if (ic.second != 1) {
        anss.push_back("^");
        anss.push_back(to_string(ic.second));
      }
    } else {
      if (ic.first == 1)
        anss.push_back("1");
    }
    if (ic != ans.back())
      anss.push_back(" + ");
  }
  ll ind = sz(anss);
  for (int i = sz(anss) - 1; i >= 0; i--) {
    if (anss[i] == "0" || anss[i] == " + ")
      ind = i;
    else
      break;
  }
  if (ind == 0)
    cout << "0";
  for (int i = 0; i < ind; i++) {
    cout << anss[i];
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
