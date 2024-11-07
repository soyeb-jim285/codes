#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define endl "\n"
#define mp make_pair
const int sz = 17;

// functions needed for bitmasking
bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
unsigned int SET(int N, int pos) { return (N | (1 << pos)); }

int x[sz], y[sz], n, t, tc, dp[1 << sz]; // variables

// sem[i][j] holds the mask for all the points (index)
// that lie on the line that connects i(th), j(th) point
unsigned int sem[sz][sz];

// function semline returns true if three points lie in the same line.
bool semLine(int p1, int p2, int p3) {
  return x[p1] * y[p2] + x[p2] * y[p3] + x[p3] * y[p1] ==
         x[p2] * y[p1] + x[p3] * y[p2] + x[p1] * y[p3];
}

// dp steps
int go(unsigned int mask) {
  if (dp[mask] != -1)
    return dp[mask]; // already calculated
  if (mask == (1 << n) - 1)
    return dp[mask] =
               0; // all the points are covered, no need to add more lines
  int ans = 8;
  int cnt = __builtin_popcount(mask);
  if (cnt == n - 1 || cnt == n - 2)
    return dp[mask] = 1; // for 1 or 2 remaining point, 1 line is enough.
  for (int i = 0; i < n; i++) {
    if (CHECK(mask, i))
      continue;
    for (int j = i + 1; j < n; j++) {
      if (CHECK(mask, j))
        continue;
      // point i and j are not covered still
      // we add a line that connects point i, j (also other points that lie on
      // that line using sem[i][j]) we then minimize the result
      ans = min(ans, 1 + go(mask | sem[i][j]));
    }
    break;
  }
  return dp[mask] = ans;
}

int main() {
  for (scanf("%d", &tc); t < tc; t++) {
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d %d", x + i, y + i);

    // precalculating sem[i][j]
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        unsigned int temp = 0;
        temp = SET(temp, i);
        temp = SET(temp, j);
        for (int k = 0; k < n; k++) {
          if (semLine(i, j, k))
            temp = SET(temp, k);
        }
        sem[i][j] = temp;
      }
    }
    // result
    printf("Case %d: %d\n", t + 1, go(0));
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
  return 0;
}
