#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool ask(int i) {
  int o = 0, z = 0;
  vector<int> vc, vc2;
  cout << "? " << i << " " << i + 1 << endl;
  cout.flush();
  int x;
  cin >> x;
  if (x == -1) {
    return true;
  }
  vc.push_back(x);
  if (x == 1) {
    o++;
  } else {
    z++;
  }
  cout << "? " << i + 1 << " " << i + 2 << endl;
  cout.flush();
  cin >> x;
  if (x == -1) {
    return true;
  }
  vc.push_back(x);
  if (x == 1) {
    o++;
  } else {
    z++;
  }
  cout << "? " << i + 2 << " " << i << endl;
  cout.flush();

  cin >> x;
  if (x == -1) {
    return true;
  }

  vc.push_back(x);
  if (x == 1) {
    o++;
  } else {
    z++;
  }
  if (z == 1 && o == 2) {
    cout << "? " << i + 1 << " " << i << endl;
    cout.flush();

    cin >> x;
    if (x == -1) {
      return true;
    }
    if (vc[0] == x) {
      cout << "! " << i + 2 << endl;
      cout.flush();
      return true;
    }
    cout << "? " << i + 2 << " " << i + 1 << endl;
    cout.flush();

    cin >> x;
    if (x == -1) {
      return true;
    }
    if (vc[1] == x) {
      cout << "! " << i << endl;
      cout.flush();

      return true;
    }
    cout << "? " << i << " " << i + 2 << endl;
    cout.flush();

    cin >> x;
    if (x == -1) {
      return true;
    }
    if (vc[2] == x) {
      cout << "! " << i + 1 << endl;
      cout.flush();

      return true;
    }
  }
  return false;
}
void solve() {
  ll n;
  cin >> n;
  if (n == -1) {
    return;
  }
  bool paisi;
  for (int i = 0; i < n; i += 3) {
    paisi = ask(i + 1);
    if (paisi) {
      return;
    }
  }
  if (n % 3 == 1) {
    cout << "! " << n << endl;
    cout.flush();
  }
  if (n % 3 != 0) {
    paisi = ask(n + 2);
  }
  cout << "! " << n << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
