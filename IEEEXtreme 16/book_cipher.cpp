/*
    score = 100pt
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set                                                            \
  tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set                                                       \
  tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,               \
       tree_order_statistics_node_update>:
void solve() {
  string nn;
  getline(cin, nn);
  ll n;
  n = stoi(nn);
  // cin >> n;
  string coln, lk;
  getline(cin, coln);
  // lk = coln.substr(0, coln.size());
  ll col;
  col = stoi(coln);
  string kp;
  getline(cin, kp);
  char ind;
  cin >> ind;
  // cout << n << " " << col << " " << kp << " " << ind << "\n";
  string rr = "", cc = "";
  bool cm = 0;
  for (int i = 0; i < (int)kp.size(); i++) {
    if (kp[i] == ',')
      cm = 1;
    else {
      if (kp[i] == ' ')
        continue;
      if (cm)
        cc += kp[i];
      else
        rr += kp[i];
    }
  }
  // cout << kp << " " << rr << " " << cc << '\n';
  //  ll c = 1;
  ll r = stoi(rr), c = stoi(cc);
  string pp;
  getline(cin, pp);
  vector<string> vc(n);
  for (int i = 0; i < n; i++)
    getline(cin, vc[i]);
  string xml = "";
  map<char, pair<int, int>> mp;
  string x;
  while (getline(cin, x)) {
    bool tg = 0;
    for (int j = 0; j < (int)x.size(); j++) {
      if (x[j] == '<') {
        tg = 1;
      } else if (x[j] == '>') {
        tg = 0;
      } else {
        if (!tg && (int)xml.size() < r * c) {
          xml += x[j];
          if (!mp[x[j]].first) {
            mp[x[j]].first = (int)xml.size();
            mp[x[j]].second = (int)xml.size();
          } else {
            mp[x[j]].second = (int)xml.size();
          }
        }
      }
    }
  }
  // cout << xml << "\n";
  for (int i = 0; i < n; i++) {
    vector<int> ans;
    bool pr = 1;
    if (ind == 'S') {
      for (int j = 0; j < (int)vc[i].size(); j++) {
        ll p = mp[vc[i][j]].first - 1;
        if (p < 0)
          pr = 0;
        ll d = p % c;
        if (d < 0)
          d += c;
        d++;
        ans.push_back(p / c + 1);
        ans.push_back(d);
      }
    } else {
      for (int j = 0; j < (int)vc[i].size(); j++) {
        ll p = mp[vc[i][j]].second - 1;
        if (p < 0)
          pr = 0;
        ll d = p % c;
        if (d < 0)
          d += c;
        d++;
        ans.push_back(p / c + 1);
        ans.push_back(d);
      }
    }
    // for (auto ic : ans)
    //     cout << ic << ",";
    // cout << "\n";
    if (pr) {
      for (int j = 0; j < (int)ans.size() - 1; j++) {
        cout << ans[j] << ",";
      }
      cout << ans.back() << "\n";
    } else
      cout << "0\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
