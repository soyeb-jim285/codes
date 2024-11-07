# Tutorial

[1613A - Long Comparison](../problems/A._Long_Comparison.md "Educational Codeforces Round 118 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1613A - Long Comparison](../problems/A._Long_Comparison.md "Educational Codeforces Round 118 (Rated for Div. 2)")

First, let's say that appending the number with $p$ zeros is the same as multiplying it by $10^p$.

The given numbers are so large that they can't fit into any reasonable integer type. Even if you use a language with unlimited length integers (python, for example) or store the numbers in strings, you should still face the time limit issue. So let's learn to shrink the numbers a bit.

Note that the result of the comparison of two numbers doesn't change if you divide both numbers by the same positive number. So we can keep dividing both numbers by $10$ until one of them is not divisible anymore. Let's also ignore the trailing zeros in $x_1$ and $x_2$ and leave them as is. If the first number is appended with $p_1$ zeros and the second numbers is appended with $p_2$ zeros, we can subtract $min(p_1, p_2)$ from both values, effectively dividing both numbers by $10^{min(p_1, p_2)}$.

This way, one of the numbers becomes short enough to fit into an integer type (because it has $p=0$ and $x$ is only up to $10^6$). The other number might still be large enough.

However, if it's really large, we can instantly say that it's larger than another one. Say, if its $p$ is at least $7$. This number it at least $10^7$ and the other number is at most $10^6$.

Otherwise, we can calculate this number as well and compare the values normally.

Overall complexity: $O(1)$ per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int t;
	cin >> t;
	while (t--){
		long long x1, x2;
		int p1, p2;
		cin >> x1 >> p1 >> x2 >> p2;
		int mn = min(p1, p2);
		p1 -= mn;
		p2 -= mn;
		if (p1 >= 7)
			cout << ">" << endl;
		else if (p2 >= 7)
			cout << "<" << endl;
		else{
			for (int i = 0; i < p1; ++i) x1 *= 10;
			for (int i = 0; i < p2; ++i) x2 *= 10;
			if (x1 < x2)
				cout << "<" << endl;
			else if (x1 > x2)
				cout << ">" << endl;
			else
				cout << "=" << endl;
		}
	}
}
```
[1613B - Absent Remainder](../problems/B._Absent_Remainder.md "Educational Codeforces Round 118 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1613B - Absent Remainder](../problems/B._Absent_Remainder.md "Educational Codeforces Round 118 (Rated for Div. 2)")

There is one important observation: x mod y<y.

Thus, you can obtain at least n−1 pair by choosing y as the minimum number in the sequence and x as anything else. n−1≥⌊n2⌋ for any positive n.

Overall complexity: O(n) per testcase.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int mn = *min_element(a.begin(), a.end());
    for (int i = 0, k = 0; k < n / 2; ++i) if (a[i] != mn) {
      cout << a[i] << ' ' << mn << 'n';
      k += 1;
    }
  }
}
```
[1613C - Poisoned Dagger](../problems/C._Poisoned_Dagger.md "Educational Codeforces Round 118 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1613C - Poisoned Dagger](../problems/C._Poisoned_Dagger.md "Educational Codeforces Round 118 (Rated for Div. 2)")

Let's find out the total damage for a fixed value of $k$. Since the effect of the poison from the $i$-th attack deals damage $\min(k, a_{i+1} - a_i)$ seconds for $i < n$ and $k$ seconds for $i = n$, then the total damage is $k +\sum\limits_{i=1}^{n-1}{\min(k, a_{i+1} - a_i)}$. We can see that the higher the value of $k$, the greater the total sum. So we can do a binary search on $k$ and find the minimum value when the sum is greater than or equal to $h$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    li h;
    cin >> n >> h;
    vector<li> a(n);
    for (li &x : a) cin >> x;
    li l = 1, r = 1e18;
    while (l <= r) {
      li m = (l + r) / 2;
      li sum = m;
      for (int i = 0; i < n - 1; ++i) 
        sum += min(m, a[i + 1] - a[i]);
      if (sum < h) l = m + 1;
      else r = m - 1;
    }
    cout << r + 1 << 'n';
  }
}
```
[1613D - MEX Sequences](../problems/D._MEX_Sequences.md "Educational Codeforces Round 118 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1613D - MEX Sequences](../problems/D._MEX_Sequences.md "Educational Codeforces Round 118 (Rated for Div. 2)")

Let's understand what MEX-correct sequences look like. It turns out there are only two types: $[\underline{0, \dots, 0}, \underline{1, \dots, 1}, \dots, \underline{x-1, \dots, x-1}, \underline{x, \dots, x}]$ and $[\underline{0, \dots, 0}, \underline{1, \dots, 1}, \dots, \underline{x-1, \dots, x-1}, \underline{x+1, \dots, x+1}, \underline{x-1, \dots, x-1}, \underline{x+1, \dots}]$. For example, the sequences $[0, 0, 1, 1, 1, 2, 3, 3]$ and the empty sequence are MEX-correct sequences of the first type, and $[1, 1, 1, 1]$ and $[0, 0, 1, 2, 4, 4, 2, 4, 2, 2]$ of the second one.

Let's calculate the dynamic programming $\mathrm{dp1}_{i, j}$ — the number of MEX-correct subsequences of the first type on the prefix of length $i$ with $\operatorname{MEX}$ equal to $j$ and similarly $\mathrm{dp2}_{i, j}$ — the number of MEX-correct subsequences of the second type on the prefix of length $i$ with $\operatorname{MEX}$ equal to $j$.

Let's look at the transitions in these dps, and show that there are no other MEX-correct sequences at the same time.

Let the current state be $\mathrm{dp1}_{i, j}$, and we are trying to add an element equal to $x$:

* if $x < j - 1$, then such an element cannot be added;
* if $x = j - 1$, then the value of $\operatorname{MEX}$ will not change and the sequence is still of the first type, which means we have a transition to $\mathrm{dp1}_{i + 1, j}$;
* if $x = j$, then the value of $\operatorname{MEX}$ will increase by $1$, but it will still be of the first type, which means we have a transition to $\mathrm{dp1}_{i + 1, j + 1}$
* if $x = j + 1$, then the value of $\operatorname{MEX}$ will not change, but the sequence will become of the second type, which means we have a transition to $\mathrm{dp2}_{i + 1, j}$;
* if $x > j + 1$, then such an element cannot be added.

Let the current state be $\mathrm{dp2}_{i, j}$, and we are trying to add an element equal to $x$:

* if $x < j - 1$, then such an element cannot be added;
* if $x = j - 1$, then the value of $\operatorname{MEX}$ will not change and the sequence is still of the second type, which means we have a transition to $\mathrm{dp2}_{i + 1, j}$;
* if $x = j$, then such an element cannot be added, because $\operatorname{MEX}$ will increase by $2$, which means the absolute difference between $\operatorname{MEX}$ and $x$ is greater than $1$;
* if $x = j + 1$, then the value of $\operatorname{MEX}$ will not change and the sequence is still of the second type, which means we have a transition to $\mathrm{dp2}_{i + 1, j}$;
* if $x > j + 1$, then such an element cannot be added.

Thus, we considered all possible transitions (adding a new element to the already MEX-correct sequences) and made sure that there are only two types.

While the solution itself works in $O(n)$ time (because each element $x$ has $O(1)$ possible transitions in the dps), it uses $O(n^2)$ memory, which does not allow us to write that solution as is. However, note that $\mathrm{dp1}_i$ and $\mathrm{dp1}_{i + 1}$ (similarly for $\mathrm{dp2}$) differ in only a few positions (in those that the element $a_i$ allowed us to make), which means we can store only one-dimensional arrays, $\mathrm{dp1}_j$ and $\mathrm{dp2}_j$. Thus, the final complexity of the solution is $O(n)$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> dp1(n + 2), dp2(n + 2);
    dp1[0] = 1;
    while (n--) {
      int x;
      scanf("%d", &x);
      dp1[x + 1] = add(dp1[x + 1], dp1[x + 1]);
      dp1[x + 1] = add(dp1[x + 1], dp1[x]);
      if (x > 0) dp2[x - 1] = add(dp2[x - 1], dp2[x - 1]);
      if (x > 0) dp2[x - 1] = add(dp2[x - 1], dp1[x - 1]);
      dp2[x + 1] = add(dp2[x + 1], dp2[x + 1]);
    }
    int ans = 0;
    for (int x : dp1) ans = add(ans, x);
    for (int x : dp2) ans = add(ans, x);
    printf("%dn", add(ans, MOD - 1));
  }
} 

```
[1613E - Crazy Robot](../problems/E._Crazy_Robot.md "Educational Codeforces Round 118 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1613E - Crazy Robot](../problems/E._Crazy_Robot.md "Educational Codeforces Round 118 (Rated for Div. 2)")

One way to think about this problem is in game theory terms.

Imagine a following game. Two players alternate moves. The first players chooses a direction. The second player chooses a different direction and moves a robot there. The game ends when the robot reaches the lab, and the first player wins. Otherwise, it's a draw. What's the outcome of the game if both players play optimally (as in the first player tries to win, the second player tries to draw)?

Does it sound easier? Well, it sure does if you ever dealt with solving games on arbitrary graphs. You can skim through [this article](https://codeforces.com/https://cp-algorithms.com/game_theory/games_on_graphs.html) if that's unfamiliar to you. The state of the game is a pair $(\mathit{cell}, \mathit{direction})$. If a direction is not chosen (denote it with $-1$), it's the first player's move. Otherwise, it's the second player's move.

You can even implement it as is. Or you can adjust a part of this algorithm for this particular problem. 

Initially, all the states are drawing, only the state $(\mathit{lab}, -1)$ is winning. What we basically need is a way to determine if a state is winning or not. From game theory, we can tell that the state is winning if there's a transition from it to a losing state. The state is losing if all the transitions from it lead to winning states. So $(\mathit{cell}, -1)$ is winning if any of $(\mathit{cell}, \mathit{direction} \neq -1)$ are losing.

Promote that one step further. The state is winning if there exists such a direction that all neighbouring free cells except in this direction are winning states. Rephrase it. The state is winning if it has at least one winning state neighbour and no more than one non-winning state neighbour.

Let's store the number of non-winning neighbouring states for each cell. Initially, it's the number of neighbouring free cells. If some state becomes marked as winning, decrease the value for each of its neighbours by $1$. If some state's value reaches $0$ or $1$ after this operation, mark it as winning.

Since what this does is basically a traversal of a grid, this can be done with a DFS/BFS, starting from the lab.

Overall complexity: $O(nm)$ per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct cell{
	int x, y;
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		int lx = -1, ly = -1;
		forn(i, n){
			cin >> s[i];
			forn(j, m) if (s[i][j] == 'L'){
				lx = i;
				ly = j;
			}
		}
		auto in = [&](int x, int y){
			return 0 <= x && x < n && 0 <= y && y < m;
		};
		vector<vector<int>> d(n, vector<int>(m, 0));
		forn(x, n) forn(y, m) if (s[x][y] == '.'){
			forn(i, 4){
				int nx = x + dx[i];
				int ny = y + dy[i];
				d[x][y] += in(nx, ny) && s[nx][ny] != '#';
			}
		}
		queue<cell> q;
		vector<vector<char>> used(n, vector<char>(m, 0));
		q.push({lx, ly});
		used[lx][ly] = true;
		while (!q.empty()){
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			forn(i, 4){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (!in(nx, ny) || s[nx][ny] == '#' || used[nx][ny]) continue;
				--d[nx][ny];
				if (d[nx][ny] <= 1){
					used[nx][ny] = true;
					q.push({nx, ny});
				}
			}
		}
		forn(i, n){
			forn(j, m) if (s[i][j] == '.' && used[i][j])
				s[i][j] = '+';
			cout << s[i] << "n";
		}
	}
	return 0;
}
```
[1613F - Tree Coloring](../problems/F._Tree_Coloring.md "Educational Codeforces Round 118 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1613F - Tree Coloring](../problems/F._Tree_Coloring.md "Educational Codeforces Round 118 (Rated for Div. 2)")

When a problem asks us to calculate the number of combinatorial objects that meet some constraints, we can sometimes use inclusion-exclusion formula. Let's try to apply it in this problem.

We could use $n-1$ constraints that should not be violated. The $i$-th constraint is formulated as follows: $c_i \ne c_{p_i} - 1$ (there will be a constraint of this type for each $i \in [2, n]$). Suppose we violated $k$ of these constraints (and have chosen which $k$ constraints to violate), then the number of colorings that meet these violations is $(n-k)!$ (for $k$ vertices, the colors on them depend on some other independent vertices, so we can assign only colors for independent vertices). So, the answer can be calculated as follows: 

$$\sum\limits_{k=0}^{n-1} (-1)^k f(k) (n-k)!$$,

where $f(k)$ is the number of ways to choose $k$ constraints to violate.

One initial guess how to calculate $f(k)$ is that $f(k) = {{n-1}\choose{k}}$, as it would be calculated in other, more usual inclusion-exclusion problems. Unfortunately, in this problem, the constraints we violate are not independent. For example, if a vertex has several sons, we can violate the constraint only on at most one edge leading from a vertex to its son simultaneously, we cannot violate two or more such constraints.

Let's take care of this issue as follows: we can write a dynamic programming of the form $dp_{i, j}$ is the number of ways to process $i$ first vertices of the tree and choose exactly $j$ edges leading from these nodes to their sons so that no vertex has more than one edge leading to its sons chosen. Then, $dp_{n, k}$ is exactly the number of ways to choose $k$ edges in the tree so that no vertex has more than one chosen edge leading to its sons, and that will be equal to $f(k)$.

We can calculate this dynamic programming in a knapsack fashion in $O(n^2)$, but it is too slow. Instead, let's optimize this knapsack DP with FFT: for each vertex $i$, introduce a polynomial $1 + d_i \cdot x$, where $d_i$ is the number of children of the vertex $i$. Coefficients of this polynomial for the first vertex are the values of $dp_{1,k}$; coefficients of the product of this polynomial with the polynomial for the second vertex are the values of $dp_{2,k}$, and so on; to obtain the values of $dp_{n,k}$, we have to multiply all these polynomials, and using FFT + divide-and-conquer, we can do it in $O(n \log^2 n)$.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)
#define sz(a) int((a).size())

const int MOD = 998244353;

struct Mint
{
  int val;

  bool operator==(const Mint& other)
  {
    return val == other.val;
  }

  Mint operator+(const Mint& other)
  {
    int res = val + other.val;
    while(res >= MOD) res -= MOD;
    while(res < 0) res += MOD;
    return Mint(res);
  }

  Mint operator-(const Mint& other)
  {
    int res = val - other.val;
    while(res >= MOD) res -= MOD;
    while(res < 0) res += MOD;
    return Mint(res);  
  }

  Mint operator*(const Mint& other)
  {
    return Mint((val * 1ll * other.val) % MOD);
  }

  Mint pow(int y)
  {
    Mint z(1);
    Mint x(val);
    while(y > 0)
    {
      if(y % 2 == 1) z = z * x;
      x = x * x;
      y /= 2;
    }
    return z;
  }

  Mint operator/(const Mint& other)
  {
    return Mint(val) * Mint(other.val).pow(MOD - 2);
  }

  Mint() {
      val = 0;
  };
  Mint(int x)
  {
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    val = x;
  };
};

ostream& operator<<(ostream& out, const Mint& x)
{
  return out << x.val;
}

const int g = 3;
const int LOGN = 19;

vector<Mint> w[LOGN];
vector<int> rv[LOGN];

void prepare() {
  Mint wb = Mint(g).pow((MOD - 1) / (1 << LOGN));
  forn(st, LOGN - 1) {
    w[st].assign(1 << st, 1);
    Mint bw = wb.pow(1 << (LOGN - st - 1));
    Mint cw = 1;
    forn(k, 1 << st) {
      w[st][k] = cw;
      cw = cw * bw;
    }
  }
  forn(st, LOGN) {
    rv[st].assign(1 << st, 0);
    if (st == 0) {
      rv[st][0] = 0;
      continue;
    }
    int h = (1 << (st - 1));
    forn(k, 1 << st)
      rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
  }
}

void ntt(vector<Mint> &a, bool inv) {
  int n = sz(a);
  int ln = __builtin_ctz(n);
  forn(i, n) {
    int ni = rv[ln][i];
    if (i < ni) swap(a[i], a[ni]);
  }
  forn(st, ln) {
    int len = 1 << st;
    for (int k = 0; k < n; k += (len << 1)) {
      fore(pos, k, k + len){
        Mint l = a[pos];
        Mint r = a[pos + len] * w[st][pos - k];
        a[pos] = l + r;
        a[pos + len] = l - r;
      }
    }
  }
  if (inv) {
    Mint rn = Mint(n).pow(MOD - 2);
    forn(i, n) a[i] = a[i] * rn;
    reverse(a.begin() + 1, a.end());
  }
}

vector<Mint> mul(vector<Mint> a, vector<Mint> b) {
  int cnt = 1 << (32 - __builtin_clz(sz(a) + sz(b) - 1));
  a.resize(cnt);
  b.resize(cnt);
  ntt(a, false);
  ntt(b, false);
  vector<Mint> c(cnt);
  forn(i, cnt) c[i] = a[i] * b[i];
  ntt(c, true);
  return c;
}

vector<Mint> norm(vector<Mint> a)
{
  while(a.size() > 1 && a.back() == Mint(0))
    a.pop_back();
  return a;
}

const int N = 250043;
vector<int> G[N];
int d[N];

Mint fact[N * 2];
Mint rev[N * 2];

void dfs(int x, int p)
{
  if(p != x) d[p]++;
  for(auto y : G[x]) if(y != p) dfs(y, x);
}

Mint C(int n, int k)
{
  return fact[n] * rev[k] * rev[n - k];
}

int main()
{
  prepare();
  fact[0] = Mint(1);
  for(int i = 1; i < N * 2; i++) fact[i] = fact[i - 1] * i;
  for(int i = 0; i < N * 2; i++) rev[i] = Mint(1) / fact[i];
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    G[x].push_back(y);
    G[y].push_back(x);  
  }
  dfs(0, 0);
  vector<vector<Mint>> cur;
  for(int i = 0; i < n; i++)
    if(d[i] > 0)
      cur.push_back(vector<Mint>({Mint(1), Mint(d[i])}));
  while(cur.size() > 1)
  {
    vector<vector<Mint>> ncur;
    for(int i = 0; i + 1 < cur.size(); i += 2)
      ncur.push_back(norm(mul(cur[i], cur[i + 1])));
    if(cur.size() % 2 == 1) ncur.push_back(cur.back());
    cur = ncur;  
  }
  Mint ans = 0;
  for(int i = 0; i < cur[0].size(); i++)
  {
    if(i % 2 == 0) ans = ans + cur[0][i] * fact[n - i];
    else ans = ans - cur[0][i] * fact[n - i];
  }
  cout << ans << endl;
}
```
