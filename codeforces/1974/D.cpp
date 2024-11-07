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
  string s;
  cin >> s;
  map<char, ll> mp;
  for (int i = 0; i < n; i++) {
    mp[s[i]]++;
  }
  if (mp['N'] > mp['S']) {
    mp['N'] -= mp['S'];
    mp['S'] = 0;
  } else {
    mp['S'] -= mp['N'];
    mp['N'] = 0;
  }
  if (mp['W'] > mp['E']) {
    mp['W'] -= mp['E'];
    mp['E'] = 0;
  } else {
    mp['E'] -= mp['W'];
    mp['W'] = 0;
  }
  vector<ll> vals(2);
  if (mp['N'] % 2 || mp['S'] % 2 || mp['W'] % 2 || mp['E'] % 2) {
    cout << "NO\n";
  } else {
    vector<int> ans(n, -1);
    bool pl = 0;
    if (mp['N'] > 0) {
      for (int i = 0; i < n; i++) {
        if (mp['N'] == 0) {
          break;
        }
        if (s[i] == 'N') {
          ans[i] = pl;
          vals[pl]++;
          pl ^= 1;
          mp['N']--;
        }
      }
    } else {
      for (int i = 0; i < n; i++) {
        if (mp['S'] == 0) {
          break;
        }
        if (s[i] == 'S') {
          ans[i] = pl;
          vals[pl]++;
          pl ^= 1;
          mp['S']--;
        }
      }
    }
    int nn = 0, ss = 0;
    bool paisi = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'N' && ans[i] == -1 && nn == 0) {
        ans[i] = pl;
        paisi = 1;
        nn++;
      }
      if (s[i] == 'S' && ans[i] == -1 && ss == 0) {
        ans[i] = pl;
        paisi = 1;
        ss++;
      }
      if (nn && ss)
        break;
    }
    if (paisi) {
      pl ^= 1;
      paisi = 0;
    }
    for (int i = 0; i < n; i++) {
      if ((s[i] == 'N' || s[i] == 'S') && ans[i] == -1) {
        ans[i] = pl;
        paisi = 1;
      }
    }
    if (paisi) {
      pl ^= 1;
      paisi = 0;
    }
    if (mp['W'] > 0) {
      for (int i = 0; i < n; i++) {
        if (mp['W'] == 0) {
          break;
        }
        if (s[i] == 'W') {
          ans[i] = pl;
          vals[pl]++;
          pl ^= 1;
          mp['W']--;
        }
      }
    } else {
      for (int i = 0; i < n; i++) {
        if (mp['E'] == 0) {
          break;
        }
        if (s[i] == 'E') {
          ans[i] = pl;
          vals[pl]++;
          pl ^= 1;
          mp['E']--;
        }
      }
    }
    int ww = 0, ee = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W' && ans[i] == -1 && ww == 0) {
        ans[i] = pl;
        paisi = 1;
        ww++;
      }
      if (s[i] == 'E' && ans[i] == -1 && ee == 0) {
        ans[i] = pl;
        paisi = 1;
        ee++;
      }
      if (ww && ee)
        break;
    }
    if (paisi) {
      pl ^= 1;
      paisi = 0;
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W' || s[i] == 'E') {
        if (ans[i] == -1) {
          ans[i] = pl;
        }
      }
    }
    ll n1 = 0, n2 = 0, w1 = 0, w2 = 0, one = 0, zero = 0;
    for (int i = 0; i < ans.size(); i++) {
      if (ans[i] == 0) {
        zero++;
        if (s[i] == 'N') {
          n1++;
        } else if (s[i] == 'S') {
          n1--;
        } else if (s[i] == 'W') {
          w1++;
        } else {
          w1--;
        }
      } else {
        one++;
        if (s[i] == 'N') {
          n2++;
        } else if (s[i] == 'S') {
          n2--;
        } else if (s[i] == 'W') {
          w2++;
        } else {
          w2--;
        }
      }
    }
    if (n1 == n2 && w1 == w2 && one > 0 && zero > 0 && one + zero == n) {
      for (auto ic : ans) {
        cout << (ic == 0 ? "R" : "H");
      }
      cout << "\n";
    } else {
      cout << "NO\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
