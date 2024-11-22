#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  bool paisi = false;
  for (int i = 0; i < s1.size(); i++) {
    if (paisi) {
      if (s1[i] != '.') {
        cout << s1[i];
        return;
      }
    }
    if (s1[i] == '=') {
      paisi = true;
    }
  }
  if (paisi) {
    cout << "You shall pass!!!\n";
    return;
  }
  for (int i = 0; i < s2.size(); i++) {
    if (paisi) {
      if (s2[i] != '.') {
        cout << s2[i];
        return;
      }
    }
    if (s2[i] == '=') {
      paisi = true;
    }
  }
  if (paisi) {
    cout << "You shall pass!!!\n";
    return;
  }
  for (int i = 0; i < s3.size(); i++) {
    if (paisi) {
      if (s3[i] != '.') {
        cout << s3[i];
        return;
      }
    }
    if (s3[i] == '=') {
      paisi = true;
    }
  }
  cout << "You shall pass!!!\n";
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
