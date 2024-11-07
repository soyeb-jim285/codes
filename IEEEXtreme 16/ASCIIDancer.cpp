/*
    score = 90pt
*/
#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set                                                            \
  tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
void solve() {
  int n;
  cin >> n;
  int nn = n;
  string head = " o ", mid = "/|\\", leg = "/ \\";
  map<char, char> rev;
  rev['o'] = 'o';
  rev['|'] = '|';
  rev['/'] = '\\';
  rev['\\'] = '/';
  rev['>'] = '<';
  rev[' '] = ' ';
  rev['<'] = '>';
  rev['('] = ')';
  rev[')'] = '(';
  n++;
  while (n--) {

    string s;
    getline(cin, s);
    if (n == nn)
      continue;
    string sub = s.substr(0, 3);
    if (sub == "say") {
      cout << s.substr(4, s.size() - 4) << "\n";
    } else {
      if (s == "left hand to head") {
        head[2] = ')';
        mid[2] = ' ';
      } else if (s == "left hand to hip") {
        head[2] = ' ';
        mid[2] = '>';
      } else if (s == "left hand to start") {
        head[2] = ' ';
        mid[2] = '\\';
      } else if (s == "left leg in") {
        leg[2] = '>';
      } else if (s == "left leg out") {
        leg[2] = '\\';
      } else if (s == "right hand to head") {
        head[0] = '(';
        mid[0] = ' ';
      } else if (s == "right hand to hip") {
        head[0] = ' ';
        mid[0] = '<';
      } else if (s == "right hand to start") {
        head[0] = ' ';
        mid[0] = '/';
      } else if (s == "right leg in") {
        leg[0] = '<';
      } else if (s == "right leg out") {
        leg[0] = '/';
      } else {
        string head1, mid1, leg1;
        reverse(head.begin(), head.end());
        reverse(mid.begin(), mid.end());
        reverse(leg.begin(), leg.end());
        for (int i = 0; i < 3; i++) {
          head[i] = rev[head[i]];
          mid[i] = rev[mid[i]];
          leg[i] = rev[leg[i]];
        }
      }
      cout << head << "\n";
      cout << mid << "\n";
      cout << leg << "\n";
    }
  }
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
