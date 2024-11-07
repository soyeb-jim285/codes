#include <bits/stdc++.h>
#include <iostream>
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
  ll n;
  ll vol;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> zero, one;
  ll zeros = 0, ones = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (zeros) {
        zero.push_back(zeros);
      }
      ones++;
      zeros = 0;
    } else {
      if (ones)
        one.push_back(ones);
      zeros++;
      ones = 0;
    }
  }
  if (zeros) {
    zero.push_back(zeros);
    bool ok = 0, out = 0;
    ll kp = 0;
    for (int i = 0; i < n; i++) {
      if (!ok) {
        cout << "0 ";
        zero[zero.size() - 1]--;
        if (zero[zero.size() - 1] == 0) {
          zero.pop_back();
          ok = 1;
        }
      } else {
        if (zero.size() == 0 || one.size() == 0) {
          cout << "-1 ";
          continue;
        }
        kp += one.back();
        cout << kp << " ";
        zero[zero.size() - 1]--;
        if (zero[zero.size() - 1] == 0) {
          zero.pop_back();
          ll lp = one.back();
          one.pop_back();
          if (one.size())
            one[one.size() - 1] += lp;
        }
      }
    }
  } else {
    one.push_back(ones);
    bool ok = 0, out = 0;
    ll kp = 0;
    for (int i = 0; i < n; i++) {
      if (zero.size() == 0 || one.size() == 0) {
        cout << "-1 ";
        continue;
      }
      kp += one.back();
      cout << kp << " ";
      zero[zero.size() - 1]--;
      if (zero[zero.size() - 1] == 0) {
        zero.pop_back();
        ll lp = one.back();
        one.pop_back();
        if (one.size())
          one[one.size() - 1] += lp;
      }
    }
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
