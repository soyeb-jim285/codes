# Tutorial

[1475A - Odd Divisor](../problems/A._Odd_Divisor.md "Codeforces Round 697 (Div. 3)")

Problem authors: [Stepavly](https://codeforces.com/profile/Stepavly "Master Stepavly"), [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz")

 **Editorial**
### [1475A - Odd Divisor](../problems/A._Odd_Divisor.md "Codeforces Round 697 (Div. 3)")

If the number $x$ has an odd divisor, then it has an odd prime divisor. To understand this fact, we can consider what happens when multiplying even and odd numbers: 

* even $*$ even $=$ even;
* even $*$ odd $=$ even;
* odd $*$ even $=$ even;
* odd $*$ odd $=$ odd.

There is only one even prime number — $2$. So, if a number has no odd divisors, then it must be a power of two. To check this fact, for example, you can divide $n$ by $2$ as long as it is divisible. If at the end we got $1$, then $n$ — the power of two.

Bonus: You can also use the following condition to check: $$n \\& (n-1) = 0$$. If the number — is a power of two, then it contains only one unit in the binary notation. Then $(n-1)$ contains units in all positions except the one in which the unit in $n$ is located. So their bitwise "AND" does not contain units.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  ll n;
  cin >> n;
  if (n & (n - 1)) {
    cout << "YESn";
  } else {
    cout << "NOn";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
[1475B - New Year's Number](../problems/B._New_Year's_Number.md "Codeforces Round 697 (Div. 3)")

Problem author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**
### [1475B - New Year's Number](../problems/B._New_Year's_Number.md "Codeforces Round 697 (Div. 3)")

Let $x$ — the number of $2020$, $y$ — the number of $2021$ ($x, y \geq 0$). Let us write the required decomposition of the number $n$: $$n = 2020 \cdot x + 2021 \cdot y = 2020 \cdot (x + y) + y$$ Then we get that $n - y$ is divisible by $2020$. Take $y$ equal to the remainder of $n$ divided by $2020$. Then $x$ is uniquely determined from the formula above: $$x = \frac{n - y}{2020} - y$$ Then, if the result is that $x \geq 0$ ($y \geq 0$ because the remainder of dividing $n$ by $2020$ is non-negative), then $n$ can be represented as the sum of a certain number of $2020$ and a certain number of $2021$.

 **Solution**
```cpp
#include <bits/stdc++.h>

#include <utility>
using namespace std;

using pii = pair<int, int>;

int main() {
  int test;
  cin >> test;
  while (test-- > 0) {
    int n;
    cin >> n;
    int cnt2021 = n % 2020;
    int cnt2020 = (n - cnt2021) / 2020 - cnt2021;
    if (cnt2020 >= 0 && 2020 * cnt2020 + 2021 * cnt2021 == n) {
      cout << "YESn";
    } else {
      cout << "NOn";
    }
  }
  return 0;
}
```
[1475C - Ball in Berland](../problems/C._Ball_in_Berland.md "Codeforces Round 697 (Div. 3)")

Problem authors: [Stepavly](https://codeforces.com/profile/Stepavly "Master Stepavly"), [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz")

 **Editorial**
### [1475C - Ball in Berland](../problems/C._Ball_in_Berland.md "Codeforces Round 697 (Div. 3)")

We can think that it is given a bipartite graph. Boys and girls are the vertices of the graph. If a boy and a girl are ready to dance together, then an edge is drawn between them. In this graph, you need to select two edges that do not intersect at the vertices.

Let $deg(x)$ — the number of edges included in the vertex $x$.

Iterate over the first edge — ($a, b$). It will block $deg(a)+deg(b)-1$ of other edges (all adjacent to vertex $a$, to vertex $b$, but the edge ($a, b$) will be blocked twice. All non-blocked edges do not intersect with ($a, b$) at the vertices. So you can add $k-deg(a)-deg(b)+1$ to the answer.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int A, B, k;
  cin >> A >> B >> k;
  vector<int> a(A), b(B);
  vector<pair<int, int>> edges(k);
  for (auto &[x, y] : edges) {
    cin >> x;
  }
  for (auto &[x, y] : edges) {
    cin >> y;
  }
  for (auto &[x, y] : edges) {
    x--;
    y--;
    a[x]++;
    b[y]++;
  }
  ll ans = 0;
  for (auto &[x, y] : edges) {
    ans += k - a[x] - b[y] + 1;
  }
  cout << ans / 2 << "n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
[1475D - Cleaning the Phone](../problems/D._Cleaning_the_Phone.md "Codeforces Round 697 (Div. 3)")

Problem authors: [Stepavly](https://codeforces.com/profile/Stepavly "Master Stepavly"), [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz")

 **Editorial**
### [1475D - Cleaning the Phone](../problems/D._Cleaning_the_Phone.md "Codeforces Round 697 (Div. 3)")

Let's say we remove $x$ applications with $b_i=1$ and $y$ applications with $b_i=2$. Obviously, among all the applications with $b_i=1$, it was necessary to take $x$ maximum in memory (so we will clear the most memory).

Let's split all the applications into two arrays with $b_i=1$ and $b_i=2$ and sort them. Then you need to take a prefix from each array.

Let's iterate over which prefix we take from the first array. For it, we can uniquely find the second prefix (we remove applications until the sum exceeds $m$). If we now increase the first prefix by taking a new application, then we don't need to take any applications in the second array. This means that when the first prefix is increased, the second one can only decrease.

To solve the problem, you can use the two-pointer method.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a, b;
  vector<int> v(n);
  for (int &e : v) {
    cin >> e;
  }
  for (int &e : v) {
    int x;
    cin >> x;
    if (x == 1) {
      a.push_back(e);
    } else {
      b.push_back(e);
    }
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  ll curSumA = 0;
  int r = (int)b.size();
  ll curSumB = accumulate(b.begin(), b.end(), 0ll);
  int ans = INT_MAX;
  for (int l = 0; l <= a.size(); l++) {
    while (r > 0 && curSumA + curSumB - b[r - 1] >= m) {
      r--;
      curSumB -= b[r];
    }
    if (curSumB + curSumA >= m) {
      ans = min(ans, 2 * r + l);
    }
    if (l != a.size()) {
      curSumA += a[l];
    }
  }
  cout << (ans == INT_MAX ? -1 : ans) << "n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
[1475E - Advertising Agency](../problems/E._Advertising_Agency.md "Codeforces Round 697 (Div. 3)")

Problem authors: [Stepavly](https://codeforces.com/profile/Stepavly "Master Stepavly"), [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz")

 **Editorial**
### [1475E - Advertising Agency](../problems/E._Advertising_Agency.md "Codeforces Round 697 (Div. 3)")

It is obvious that Masha will enter into agreements only with bloggers that have the most subscribers. You can sort all the bloggers and greedily select the prefix.

Let $x$ — be the minimum number of subscribers for the hired blogger. Then we must hire all the bloggers who have more subscribers. Let $m$ — the number of bloggers who have more than $x$ subscribers, $cnt[x]$ — the number of bloggers who have exactly $x$ subscribers. Then we should select $k-m$ bloggers from $cnt[x]$. The number of ways to do this is equal to the binomial coefficient of $cnt[x]$ by $k-m$.

You could calculate it by searching for the inverse element modulo. Then you could calculate the factorials and use the equality $\binom n k = \frac{n!}{k! \cdot (n-k)!}$.

Alternatively, you can use the equation $\binom n k = \binom {n-1} {k} + \binom {n-1} {k-1}$ and calculate it using dynamic programming. This method is better known as the Pascal triangle.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int mod = 1e9 + 7;

int fast_pow(int a, int p) {
  int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % mod;
      p /= 2;
    } else {
      res = res * 1ll * a % mod;
      p--;
    }
  }
  return res;
}

int fact(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
  }
  return res;
}

int C(int n, int k) {
  return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll * fast_pow(fact(n - k), mod - 2) % mod;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> cnt(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  for (int i = n; i >= 0; i--) {
    if (cnt[i] >= k) {
      cout << C(cnt[i], k) << "n";
      return;
    } else {
      k -= cnt[i];
    }
  }
  cout << 1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
[1475F - Unusual Matrix](../problems/F._Unusual_Matrix.md "Codeforces Round 697 (Div. 3)")

Problem authors: [Stepavly](https://codeforces.com/profile/Stepavly "Master Stepavly"), [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz")

 **Editorial**
### [1475F - Unusual Matrix](../problems/F._Unusual_Matrix.md "Codeforces Round 697 (Div. 3)")

It is clear that the order of operations does not affect the final result, also it makes no sense to apply the same operation more than once (by the property of the xor operation). Let's construct a sequence of operations that will reduce the matrix $a$ to the matrix $b$ (if the answer exists). Let's try iterate over: will we use the operation "horizontal xor".

Now, by the each element of the first line ($a_{1,j}$), we can understand whether it is necessary to apply the operation "vertical xor" (if $a_{1,j} \ne b_{1,j}$). Let's apply all necessary operations "vertical xor". It remains clear whether it is necessary to apply the operation "horizontal xor" for $i$ ($2 \le i \le n$). Let's look at each element of the first column ($a_{i,1}$) by it you can understand whether it is necessary to apply the operation "horizontal xor" (if $a_{i, 1} \ne b_{i,1}$).

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

bool check(vector<vector<int>> a, vector<vector<int>> const &b) {
  int n = (int) a.size();
  for (int j = 0; j < n; j++) {
    if (a[0][j] != b[0][j]) {
      for (int i = 0; i < n; i++) {
        a[i][j] ^= 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int need_xor = (a[i][0] ^ b[i][0]);
    for (int j = 1; j < n; j++) {
      if (need_xor != (a[i][j] ^ b[i][j])) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  vector<vector<int>> b(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j] = s[j] - '0';
    }
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      b[i][j] = s[j] - '0';
    }
  }

  for (int times = 0; times < 2; times++) {
    if (check(a, b)) {
      cout << "YESn";
      return;
    }
    for (int j = 0; j < n; j++) {
      a[0][j] ^= 1;
    }
  }
  cout << "NOn";
}

int main() {
  int test;
  cin >> test;
  while (test-- > 0) {
    solve();
  }
  return 0;
}
```
[1475G - Strange Beauty](../problems/G._Strange_Beauty.md "Codeforces Round 697 (Div. 3)")

Problem author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**
### [1475G - Strange Beauty](../problems/G._Strange_Beauty.md "Codeforces Round 697 (Div. 3)")

Let's calculate for each number $x$ how many times it occurs in the array $a$. Let's denote this number as $cnt_x$.

Let's use the dynamic programming method. Let $dp(x)$ be equal to the maximum number of numbers not greater than $x$ such that for each pair of them one of the conditions above is satisfied. More formally, if $dp(x) = k$, then there exists numbers $b_1, b_2, \ldots, b_k$ ($b_i \leq x$) from the array $a$ such that for all $i \ne j$ ($1 \leq i, j \leq k$) one of the conditions above is satisfied.

Then to calculate $dp(x)$ you can use the following formula: $$dp(x) = cnt(x) + \max \limits_{y = 1, x mod y = 0}^{x-1} dp(y)$$.

Note that to calculate $dp(x)$ you need to go through the list of divisors of $x$. For this, we use the sieve of Eratosthenes.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 100;

int dp[N];
int cnt[N];

void solve() {
  int n;
  cin >> n;
  fill(dp, dp + N, 0);
  fill(cnt, cnt + N, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  for (int i = 1; i < N; i++) {
    dp[i] += cnt[i];
    for (int j = 2 * i; j < N; j += i) {
      dp[j] = max(dp[j], dp[i]);
    }
  }
  cout << (n - *max_element(dp, dp + N)) << endl;
}

int main() {
  int test;
  cin >> test;
  while (test-- > 0) {
    solve();
  }
  return 0;
}
```
