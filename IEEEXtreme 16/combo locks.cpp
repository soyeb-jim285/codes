/*
    score = 48.53pt
    Best answer = 1574
    my answer = 1438

    cout <<"scpmtbafwd\n";
    cout <<"aeoirhultc\n";
    cout <<"ranteilso\n";
    cout <<"tenilsrda\n";
    cout <<"eistnaolr\n";
    cout <<"nesridtoa\n";
    cout <<"gsnredtcy\n";
    cout <<"sgdetyrho\n";
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set                                                            \
  tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set                                                       \
  tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,               \
       tree_order_statistics_node_update>
void solve() {
  vector<string> vcc;
  string x;
  while (cin >> x) {
    while (x.size() < 8)
      x += '{';
    vcc.push_back(x);
  }
  ll mx = 0;
  vector<string> main(8);
  for (int ii = 0; ii < 8; ii++) {
    vector<string> ans;
    vector<string> vc = vcc;
    for (int i = 0; i < 8; i++) {
      map<char, int> mp;
      for (int j = 0; j < vc.size(); j++) {
        int ind = (i + ii) % 8;
        if (ind < 0)
          ind += 8;

        mp[vc[j][ind]]++;
      }
      // cout << "a\n";
      vector<pair<int, char>> kp;
      for (auto ic : mp)
        kp.push_back({ic.second, ic.first});
      sort(kp.begin(), kp.end(), greater<pair<int, char>>());
      // cout << kp.size() << " " << vc.size() << "----\n";
      vector<string> tmp;
      string xp = "";
      // cout << mp.size() << " " << kp.size() << "\n";
      for (int j = 0; j < 10; j++) {
        if (kp[j].second == '{')
          continue;
        xp += kp[j].second;
      }
      // cout << "b\n";
      ans.push_back(xp);
      for (int j = 0; j < vc.size(); j++) {
        for (int k = 0; k < 10; k++) {
          int ind = (i + ii) % 8;
          if (ind < 0)
            ind += 8;
          if (vc[j][ind] == kp[k].second)
            tmp.push_back(vc[j]);
        }
      }
      vc = tmp;
    }
    if (vc.size() > mx) {
      mx = vc.size();
      for (int i = 0; i < 8; i++) {
        int ind = (i + ii) % 8;
        if (ind < 0)
          ind += 8;
        main[ind] = ans[i];
      }
    }
  }

  for (auto ic : main)
    cout << ic << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen64("words.txt", "r", stdin);
  // freopen64("output.txt", "w", stdout);
  solve();
  return 0;
}
