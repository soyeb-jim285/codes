# Editorial_(en)

[1520A - Do Not Be Distracted!](../problems/A._Do_Not_Be_Distracted!.md "Codeforces Round 719 (Div. 3)")

Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1520A - Do Not Be Distracted!](../problems/A._Do_Not_Be_Distracted!.md "Codeforces Round 719 (Div. 3)")

The simplest solution — go through the problem, because of which the teacher might have suspicions. Now you can find the first day when Polycarp solved this problem and the last such day. Between these two days, all problems should be the same. If this is not the case, the answer is "NO".

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char c = 'A'; c <= 'Z'; c++) {
        int first = n;
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                first = min(first, i);
                last = max(last, i);
            }
        }
        for (int i = first; i <= last; i++) {
            if (s[i] != c) {
                cout << "NOn";
                return;
            }
        }
    }
    cout << "YESn";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
[1520B - Ordinary Numbers](../problems/B._Ordinary_Numbers.md "Codeforces Round 719 (Div. 3)")

Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1520B - Ordinary Numbers](../problems/B._Ordinary_Numbers.md "Codeforces Round 719 (Div. 3)")

Note that every ordinary number can be represented as $d \cdot (10^0 + 10^1 + \ldots + 10^k)$. Therefore, to count all ordinary numbers among the numbers from $1$ to $ n $, it is enough to count the number of $(d, k)$ pairs such that $d \cdot (10^0 + 10^1 + \ldots + 10^k) \le n$. In the given constraints, it is enough to iterate over $d$ from $1$ to $9$ and $k$ from $0$ to $8$.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;
  int res = 0;
  for (ll pw = 1; pw <= n; pw = pw * 10 + 1) {
    for (int d = 1; d <= 9;  d++) {
      if (pw * d <= n) {
        res++;
      }
    }
  }
  cout << res << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}
```
[1520C - Not Adjacent Matrix](../problems/C._Not_Adjacent_Matrix.md "Codeforces Round 719 (Div. 3)")

Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1520C - Not Adjacent Matrix](../problems/C._Not_Adjacent_Matrix.md "Codeforces Round 719 (Div. 3)")

Note that $n = 2$ is the only case where there is no answer.

For other cases, consider the following construction: 

* Let's say that the cell $(i, j)$ is white if $i + j$ is an even number, otherwise, we will say that the cell $(i, j)$ is black;
* Let's arrange the cells so that all white cells are first, and if the colors are equal, the cells will be compared lexicographically.
* Arrange numbers from $1$ to $n^2$ in ordered cells.

For example, for $n=3$, the following matrix will be constructed: $$ \begin{pmatrix} 1 & 6 & 2\\\ 7 & 3 & 8\\\ 4 & 9 & 5\\\ \end{pmatrix} $$

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1" << endl;
    return;
  } else if (n == 2) {
    cout << "-1" << endl;
    return;
  }
  vector<vector<int>> a(n, vector<int>(n));
  a[0][0] = 1;
  a[n - 1][n - 1] = n * n;
  int x = n * n - 1;
  for (int i = 1; i + 1 < n; i++) {
    for (int j = i; j >= 0; j--, x--) {
      a[i - j][j] = x;
    }
  }
  x = 2;
  for (int j = n - 2; j > 0; j--) {
    for (int i = 0; i < n - j; i++, x++) {
      a[n - i - 1][j + i] = x;
    }
  }
  for (int i = n - 1; i >= 0; i--, x++) {
    a[i][n - i - 1] = x;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}
```
[1520D - Same Differences](../problems/D._Same_Differences.md "Codeforces Round 719 (Div. 3)")

Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1520D - Same Differences](../problems/D._Same_Differences.md "Codeforces Round 719 (Div. 3)")

Let's rewrite the original equality a bit: $$a_j - a_i = j - i,$$ $$a_j - j = a_i - i$$

Let's replace each $a_i$ with $b_i = a_i - i$. Then the answer is the number of pairs $(i, j)$ such that $i < j$ and $b_i = b_j$. To calculate this value you can use map or sorting.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  map<int, int> a;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x -= i;
    res += a[x];
    a[x]++;
  }
  cout << res << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}
```
[1520E - Arranging The Sheep](../problems/E._Arranging_The_Sheep.md "Codeforces Round 719 (Div. 3)")

Authors: [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz"), [Stepavly](https://codeforces.com/profile/Stepavly "Candidate Master Stepavly")

 **Tutorial**
### [1520E - Arranging The Sheep](../problems/E._Arranging_The_Sheep.md "Codeforces Round 719 (Div. 3)")

Let's denote by $k$ the number of sheep in the string, and by $x_1, x_2, \ldots, x_k$ ($1 \le x_1 < x_2 < \ldots < x_k \le n$) their positions in the string.

Note that in the optimal solution the sheep with the number $m = \lceil\frac{n}{2}\rceil$ will not make moves. This can be proved by considering the optimal solution in which the sheep with the number $m$ makes at least one move and come to the conclusion that this solution is not optimal. Consider sheep with numbers from $i=1$ to $n$. Then the final position of the $i$-th sheep will be $x_m - m + i$, and the answer will be $\sum\limits_{i=1}^{k} |x_i - (x_m - m + i)|$.

 **Solution**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for(auto x : s)
		cnt += (x == '*' ? 1 : 0);
	int pos = -1;
	int cur = -1;
	for(int i = 0; i < n; i++)
	{
	 	if(s[i] == '*')
	 	{
	 	    cur++;
	 	    if(cur == cnt / 2)
	 	    	pos = i;
	 	}	
	}
	long long ans = 0;
	cur = pos - cnt / 2;
	for(int i = 0; i < n; i++)
		if(s[i] == '*')
		{
		 	ans += abs(cur - i);
		 	cur++;
		}
	cout << ans << endl;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int i = 0; i < tc; i++)
	{
	 	solve();
	}
}
```
[1520F1 - Guess the K-th Zero (Easy version)](../problems/F1._Guess_the_K-th_Zero_(Easy_version).md "Codeforces Round 719 (Div. 3)")

Authors: [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz"), [Stepavly](https://codeforces.com/profile/Stepavly "Candidate Master Stepavly")

 **Tutorial**
### [1520F1 - Guess the K-th Zero (Easy version)](../problems/F1._Guess_the_K-th_Zero_(Easy_version).md "Codeforces Round 719 (Div. 3)")

This problem can be solved by binary search. Let's maintain a segment that is guaranteed to contain the $k$-th zero and gradually narrow it down.

Let the current segment be — $[l, r]$ and we want to find $k$-th zero on it. Let's make a query on the half of the segment $[l, m]$, where $m = \frac{l+r}{2}$. If there are at least $k$ zeros on the left half of the segment, then we go to the left segment and look for the $k$-th zero.

If there is only $x < k$ zeros on the left half, then we go to the right segment and look for $(k-x)$-th zero.

We will spend $\log{n}$ queries, which is within the limits.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

void calc(int l, int r, int k) {
    if (l == r) {
        cout << "! " << l << endl;
        return;
    }
    int m = (l + r) / 2;
    cout << "? " << l << " " << m << endl;
    int sum;
    cin >> sum;
    if ((m - l + 1) - sum >= k) {
        calc(l, m, k);
    } else {
        calc(m + 1, r, k - (m - l + 1) + sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t, k;
    cin >> n >> t >> k;
    calc(1, n, k);
}
```
[1520F2 - Guess the K-th Zero (Hard version)](../problems/F2._Guess_the_K-th_Zero_(Hard_version).md "Codeforces Round 719 (Div. 3)")

Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1520F2 - Guess the K-th Zero (Hard version)](../problems/F2._Guess_the_K-th_Zero_(Hard_version).md "Codeforces Round 719 (Div. 3)")

In this problem, you can apply the same solution as in the previous one, but you need to remember the responses to the requests and not make the same requests several times.

Why does it work? Imagine a binary tree with a segment at each vertex, and its children — the left and right half of the segment. We will leave only those vertexes for which we made requests. It remains to show that there are no more than $6 \cdot 10^4 $ such vertices.

First — the height of the tree is not more than $18$. Let's understand what the maximum number of vertices can be in the tree. We will consider each level separately. If the level number $x$ is less than $\log{t} \le 14$, then we can spend no more than $x$ of vertices (since there are simply no more vertices). If the level number is from $15$ to $18$, then we can spend no more than $t$ vertices, so each request uses only one vertex per level. By limiting the number of vertices in this way, we get that there are no more than $2^14 - 1 + 4 \cdot 10^4 = 56383$, which fits into the constraints.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

map<pair<int,int>, int> cache;

void dec(int pos, int L, int R) {
    cache[{L, R}]--;

    if (L != R) {
        int M = (L + R) / 2;
        if (pos <= M)
            dec(pos, L, M);
        else
            dec(pos, M + 1, R);
    }
}

int main() {
    int n, cases;
    cin >> n >> cases;
    forn(case_, cases) {
        int k;
        cin >> k;
        int L = 0, R = n - 1;
        while (L != R) {
            int M = (L + R) / 2;
            
            pair<int,int> range = make_pair(L, M);
            if (cache.count(range) == 0) {
                cout << "? " << range.first + 1 << " " << range.second + 1 << endl;
                cin >> cache[range];
                cache[range] = range.second - range.first + 1 - cache[range];
            }

            int value = cache[range];
            if (k <= value)
                R = M;
            else {
                k -= value;
                L = M + 1;
            }
        }

        cout << "! " << L + 1 << endl;
        dec(L, 0, n - 1);
    }
}
```
[1520G - To Go Or Not To Go?](../problems/G._To_Go_Or_Not_To_Go_.md "Codeforces Round 719 (Div. 3)")

Authors: [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz"), [Stepavly](https://codeforces.com/profile/Stepavly "Candidate Master Stepavly"), [Aris](https://codeforces.com/profile/Aris "Candidate Master Aris")

 **Tutorial**
### [1520G - To Go Or Not To Go?](../problems/G._To_Go_Or_Not_To_Go_.md "Codeforces Round 719 (Div. 3)")

There is no point in using two transitions between portals, because if you want to go from portal $A$ to portal $B$, and then from portal $C$ to portal $D$, then you can immediately go from portal $A$ to portal $D$ for less.

Then there are two possible paths.

First — do not use portals. Here it is enough to find the shortest path between two points.

The second — use a single transition. Let's choose a portal from which we should teleport. Obviously, this is a portal with a minimum distance to it and the cost of the transition. Similarly, the portal in which we should teleport is selected.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

const int MAX_N = 2010;

int dd[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
};

void bfs(int sx, int sy, vector<vector<int>> &d, vector<vector<int>> &a) {
    int n = d.size();
    int m = d[0].size();
    queue<pair<int, int>> q;
    q.push({sx, sy});
    d[sx][sy] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : dd) {
            int tx = x + dx;
            int ty = y + dy;
            if (tx >= 0 && ty >= 0 && tx < n && ty < m && d[tx][ty] == 0 && a[tx][ty] != -1) {
                d[tx][ty] = d[x][y] + 1;
                q.push({tx, ty});
            }
        }
    }
    for (auto &e : d) {
        for (auto &i : e) {
            i--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, w;
    cin >> n >> m >> w;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> d1(n, vector<int>(m));
    vector<vector<int>> d2(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    bfs(0, 0, d1, a);
    bfs(n - 1, m - 1, d2, a);
    ll bestFinish = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d2[i][j] != -1 && a[i][j] >= 1) {
                bestFinish = min(bestFinish, a[i][j] + w * 1ll * d2[i][j]);
            }
        }
    }
    ll ans = w * 1ll * d1[n - 1][m - 1];
    if (d1[n - 1][m - 1] == -1) {
        ans = 1e18;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d1[i][j] != -1 && a[i][j] >= 1 && bestFinish != 1e18) {
                ans = min(ans, w * 1ll * d1[i][j] + a[i][j] + bestFinish);
            }
        }
    }
    if (ans == 1e18) {
        cout << -1;
    } else {
        cout << ans;
    }
}
```
