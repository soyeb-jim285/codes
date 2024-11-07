
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
typedef vector<int> vi;

// #define int long long

const int N = 5e5 + 10;
const int M = 1e9 + 7;
const long long INF = 1e6;

#define lll __int128_t
#define ld long double

ll n, k;
ll arr[30];
string s1, s2;
ll saved[10001][1001];

ll dp(int ind1, int ind2) {
  // cout << ind1 << " " << ind2 << "\n";
  if (ind2 >= k)
    return 1;
  if (ind1 >= n)
    return 0;
  if (saved[ind1][ind2] != -1)
    return saved[ind1][ind2];

  ll ans = 0;
  ans = dp(ind1 + 1, ind2);
  if (s1[ind1] == s2[ind2]) {
    ans += dp(ind1 + arr[s2[ind2] - 'A'] + 1, ind2 + 1);
    ans %= M;
  }
  return saved[ind1][ind2] = ans;
}

void solve() {
  cin >> k >> n;
  for (int i = 0; i < 26; i++)
    cin >> arr[i];
  if (k != 0)
    cin >> s2;
  if (n != 0)
    cin >> s1;
  if (k == 0) {
    cout << 1 << "\n";
    return;
  }
  if (n < k) {
    cout << 0 << "\n";
    return;
  }
  memset(saved, -1, sizeof(saved));
  cout << dp(0, 0) << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifdef LOCAL
  freopen("D:/IUPC/input.txt", "r", stdin);
  freopen("D:/IUPC/output.txt", "w", stdout);
#endif
  // inv = pwr(10000, M - 2);
  //   precalc();
  int t = 1;
  // cin >> t;
  rep(i, 0, t) {
    // cout << "Case #" << i + 1 << ": ";
    solve();
  }
}
