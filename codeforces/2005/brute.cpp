#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<vector<int>> combi;

void Combination(int a[], int reqLen, int start, int currLen, bool check[],
                 int len) {
  if (currLen > reqLen)
    return;
  else if (currLen == reqLen) {
    vector<int> temp;
    for (int i = 0; i < len; i++) {
      if (check[i] == true) {
        temp.push_back(a[i]);
      }
    }
    combi.push_back(temp);
    return;
  }
  if (start == len) {
    return;
  }
  check[start] = true;
  Combination(a, reqLen, start + 1, currLen + 1, check, len);
  check[start] = false;
  Combination(a, reqLen, start + 1, currLen, check, len);
}
vector<char> val = {'n', 'a', 'r', 'e', 'k'};
ll fn(string &str) {
  ll m = str.size(), valind = 0;
  ll sn = 0, sc = 0;
  vector<bool> paisi(m, false);
  for (int i = 0; i < m; i++) {
    if (str[i] == val[valind]) {
      paisi[i] = true;
      valind++;
      if (valind == 5) {
        valind = 0;
        sn += 5;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (!paisi[i]) {
      if (str[i] == 'n' || str[i] == 'a' || str[i] == 'r' || str[i] == 'e' ||
          str[i] == 'k') {
        sc++;
      }
    }
  }
  return sn - sc;
  return 0;
}
void solve() {
  int i, n, m;
  cin >> n >> m;
  bool check[n];
  vector<string> str(n);
  for (i = 0; i < n; i++) {
    cin >> str[i];
  }
  int arr[n];
  for (i = 0; i < n; i++) {
    arr[i] = i;
    check[i] = false;
  }
  combi.clear();
  // For each length of sub-array, call the Combination().
  for (i = 1; i <= n; i++) {
    Combination(arr, i, 0, 0, check, n);
  }
  ll ans = -1e9;
  for (auto ic : combi) {
    string s = "";
    for (int i = 0; i < sz(ic); i++) {
      s += str[ic[i]];
    }
    ans = max(fn(s), ans);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
