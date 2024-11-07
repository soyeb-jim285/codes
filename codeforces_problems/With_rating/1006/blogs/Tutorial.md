# Tutorial

[1006A - Adjacent Replacements](../problems/A._Adjacent_Replacements.md "Codeforces Round 498 (Div. 3)")

 **Tutorial**
### [1006A - Adjacent Replacements](../problems/A._Adjacent_Replacements.md "Codeforces Round 498 (Div. 3)")

It is easy to see that for the odd elements there is no changes after applying the algorithm described in the problem statement, and for the even elements there is only one change: each of the even elements will be decreased by $1$. So we can iterate over all the elements of the array and print $a_i - (a_i \% 2)$, where $x \% y$ is taking $x$ modulo $y$.

Overall complexity is $O(n)$.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		cout << x - !(x & 1) << " ";
	}
	
	return 0;
}
```
[1006B - Polycarp's Practice](../problems/B._Polycarp's_Practice.md "Codeforces Round 498 (Div. 3)")

 **Tutorial**
### [1006B - Polycarp's Practice](../problems/B._Polycarp's_Practice.md "Codeforces Round 498 (Div. 3)")

The maximum possible total profit you can obtain is the sum of the $k$ largest values of the given array. This is obvious because we can always separate these $k$ maximums and then extend the segments corresponding to them to the left or to the right and cover the entire array. I suggest the following: extract $k$ largest values of the given array and place a separator right after each of them (except the rightmost one).

Overall complexity is $O(n \log n)$.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); 
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> res(n);
	vector<int> a(n); 
	for (int i = 0; i < n; ++i) {
		cin >> res[i].first;
		a[i] = res[i].first;
		res[i].second = i + 1;
	}
	
	sort(res.begin(), res.end());
	reverse(res.begin(), res.end());
	sort(res.begin(), res.begin() + k, [&](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
	
	int lst = 0, sum = 0;
	for (int i = 0; i < k - 1; ++i) {
	    sum += *max_element(a.begin() + lst, a.begin() + res[i].second);
		lst = res[i].second;	
	}
	sum += *max_element(a.begin() + lst, a.end());
	cout << sum << endl;
	

	lst = 0;
	for (int i = 0; i < k - 1; ++i) {
		cout << res[i].second - lst << " ";
		lst = res[i].second;	
	}
	cout << n - lst << endl;
	
	return 0;
}
```
[1006C - Three Parts of the Array](../problems/C._Three_Parts_of_the_Array.md "Codeforces Round 498 (Div. 3)")

 **Tutorial**
### [1006C - Three Parts of the Array](../problems/C._Three_Parts_of_the_Array.md "Codeforces Round 498 (Div. 3)")

Since the given array consists of positive integers, for each value of $a$, there can be at most one value of $c$ such that $sum_1 = sum_3$. We can use binary search on the array of prefix sums of $d$ to find the correct value of $c$, given that it exists. If it does exist and $a+c \le n$, this is a candidate solution so we store it. Alternatively, we can use the two pointers trick – when $a$ increases, $c$ cannot decrease. Be careful to use 64 bit integers to store sums.

Overall complexity is $O(n \log n)$ or $O(n)$. 

 **Solution (Vovuh, set)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
		
	set<long long> sum;
	long long l = 0;
	for (int i = 0; i < n; ++i) {
		l += a[i];
		sum.insert(l);
	}
	
	long long ans = 0;
	long long r = 0;
	for (int i = n - 1; i >= 0; --i) {
		sum.erase(l);
		l -= a[i];
		r += a[i];
		if (sum.count(r))
			ans = max(ans, r);
	}
	
	cout << ans << endl;
	
	return 0;
}
```
 **Solution (ivan100sic, two pointers)**
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int i = 0, j = n+1;
	ll zi = 0, zj = 0, solidx = 0;
	while (i < j) {
		if (zi < zj)
			zi += a[++i];
		else if (zi > zj)
			zj += a[--j];
		else {
			solidx = i;
			zi += a[++i];
			zj += a[--j];
		}
	}
	
	cout << accumulate(a+1, a+solidx+1, 0ll); // here
}
```
[1006D - Two Strings Swaps](../problems/D._Two_Strings_Swaps.md "Codeforces Round 498 (Div. 3)")

 **Tutorial**
### [1006D - Two Strings Swaps](../problems/D._Two_Strings_Swaps.md "Codeforces Round 498 (Div. 3)")

Let's divide all characters of both strings into groups in such a way that characters in each group can be swapped with each other with changes. So, there will be following groups: $\{a_1, a_n, b_1, b_n\}$, $\{a_2, a_{n - 1}, b_2, b_{n - 1}\}$ and so on. Since these groups don't affect each other, we can calculate the number of preprocess moves in each group and then sum it up.

How to determine if a group does not need any preprocess moves? For a group consisting of $2$ characters (there will be one such group if $n$ is odd, it will contain $a_{\lceil\frac{n}{2}\rceil}$ and $b_{\lceil\frac{n}{2}\rceil}$), that's easy — if the characters in this group are equal, the answer is $0$, otherwise it's $1$.

To determine the required number of preprocess moves for a group consising of four characters, we may use the following fact: this group doesn't require preprocess moves iff the characters in this group can be divided into pairs. So if the group contains four equal characters, or two pairs of equal characters, then the answer for this group is $0$. Otherwise we may check that replacing only one character of $a_i$ and $a_{n - i + 1}$ will be enough; if so, then the answer is $1$, otherwise it's $2$.

Overall complexity is $O(n)$.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}
 
template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}
 
mt19937 rnd(time(NULL));
 
const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
 
int n;
string s, t;

bool read() {
	if (!(cin >> n >> s >> t))
		return false;
	return true;
}

void solve() {
	int ans = 0;
	forn(i, n / 2) {
		map<char, int> a;
		a[s[i]]++; a[s[n - i - 1]]++;
		a[t[i]]++; a[t[n - i - 1]]++;
		if (sz(a) == 4)
			ans += 2;
		else if (sz(a) == 3)
			ans += 1 + (s[i] == s[n - i - 1]);
		else if (sz(a) == 2)
			ans += a[s[i]] != 2;
	}
	
	if (n % 2 == 1 && s[n / 2] != t[n / 2])
		ans++;
		
	cout << ans << endl;
}
 
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
 
	int tt = clock();
 
#endif
 
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;
	
#ifdef _DEBUG
	while (read()) {	
#else
	if (read()) {
#endif
		solve();
 
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif
 
	}
}
```
[1006E - Military Problem](../problems/E._Military_Problem.md "Codeforces Round 498 (Div. 3)")

 **Tutorial**
### [1006E - Military Problem](../problems/E._Military_Problem.md "Codeforces Round 498 (Div. 3)")

Let's form the following vector $p$: we run DFS from the first vertex and push the vertex $v$ to the vector when entering this vertex. Let $tin_v$ be the position of the vertex $v$ in the vector $p$ (the size of the vector $p$ in moment we call DFS from the vertex $v$) and $tout_v$ be the position of the first vertex pushed to the vector after leaving the vertex $v$ (the size of the vector $p$ in moment when we return from DFS from the vertex $v$). Then it is obvious that the subtree of the vertex $v$ lies in half-interval $[tin_v; tout_v)$.

After running such DFS we can answer the queries. Let $pos_i = v_i + k_i - 1$ (answering the $i$-th query). If $pos_i$ is greater than or equal to $n$ then answer to the $i$-th query is "-1".

We need to check if the vertex $p_{pos_i}$ lies in the subtree of the vertex $v_i$. The vertex $a$ is in the subtree of the vertex $b$ if and only if $[tin_a; tout_a) \subseteq [tin_b; tout_b)$.

If the vertex $p_{pos_i}$ is not in the subtree of the vertex $v_i$ then answer is "-1". Otherwise the answer is $p_{pos_i}$.

Overall complexity is $O(n + q)$.

 **Solution (mareksom)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<vector<int>> tree;

int current_preorder;
vector<int> preorder, max_preorder;
vector<int> sorted_by_preorder;

void Dfs(int w) {
  sorted_by_preorder[current_preorder] = w;
  preorder[w] = current_preorder++;
  for (int c : tree[w]) {
    Dfs(c);
  }
  max_preorder[w] = current_preorder - 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  assert(2 <= n);
  assert(1 <= q);
  tree.resize(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    assert(0 <= p and p < n);
    tree[p].push_back(i);
  }

  preorder.resize(n);
  max_preorder.resize(n);
  sorted_by_preorder.resize(n);
  current_preorder = 0;
  Dfs(0);

  for (int i = 0; i < q; i++) {
    int u, k;
    cin >> u >> k;
    u--; k--;
    assert(0 <= u and u < n);
    assert(0 <= k and k < n);
    k += preorder[u];
    int answer = -1;
    if (k <= max_preorder[u]) {
      answer = sorted_by_preorder[k] + 1;
      assert(1 <= answer and answer <= n);
    }
    cout << answer << 'n';
  }
  return 0;
}
```
[1006F - Xor-Paths](../problems/F._Xor-Paths.md "Codeforces Round 498 (Div. 3)")

 **Tutorial**
### [1006F - Xor-Paths](../problems/F._Xor-Paths.md "Codeforces Round 498 (Div. 3)")

This is a typical problem on the meet-in-the-middle technique.

The number of moves we will made equals $n + m - 2$. So if $n + m$ would be small enough (25 is the upper bound, I think), then we can just run recursive backtracking in $O(2^{n + m - 2})$ or in $O($${n + m - 2}\choose{m - 1}$$ \cdot (n + m - 2))$ to iterate over all binary masks of lengths $n + m - 2$ containing exactly $m - 1$ ones and check each path described by such mask ($0$ in this mask is the move to the bottom and $1$ is the move to the right) if its xor is $k$.

But it is too slow. So let's split this mask of $n + m - 2$ bits into two parts — the left part will consist of $mid = \lfloor\frac{n + m - 2}{2}\rfloor$ bits and the right part will consist of $n + m - 2 - mid$ bits. Note that each left mask (and each right mask too) uniquely describes the endpoint of the path and the path itself.

Let's carry $n \times m$ associative arrays $cnt$ where $cnt_{x, y, c}$ for the endpoint $(x, y)$ and xor $c$ will denote the number of paths which end in the cell $(x, y)$ having xor $c$.

Let's run recursive backtracking which will iterate over paths starting from the cell $(1, 1)$ and move to the right or to the bottom and maintain xor of the path. If we made $mid$ moves and we are currently in the cell $(x, y)$ with xor $c$ right now, set $cnt_{x, y, c} := cnt_{x, y, c} + 1$ and return from the function. Otherwise try to move to the bottom or to the right changing xor as needed.

Let's run another recursive backtracking which will iterate over paths starting from the cell $(n, m)$ and move to the left or to the top and maintain xor of the path except the last cell. The same, if we made $n + m - 2 - mid$ moves and we are currently in the cell $(x, y)$ with xor $c$ right now, let's add $cnt_{x, y, k ^ c}$ to the answer (obvious, that way we "complement" our xor from the right part of the path with the suitable xor from the left part of the path). Otherwise try to move to the left or to the top changing xor as needed.

So, this is the meet-in-the-middle technique (at least the way I code it).

Overall complexity is $O(2^{\frac{n + m - 2}{2}} \cdot \frac{n + m - 2}{2})$.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 20;

map<long long, int> v[N][N];

int n, m;
int half;
long long k;
long long a[N][N];
long long ans;

void calclf(int x, int y, long long val, int cnt) {
	val ^= a[x][y];
	if (cnt == half) {
		++v[x][y][val];
		return;
	}
	if (x + 1 < n)
		calclf(x + 1, y, val, cnt + 1);
	if (y + 1 < m)
		calclf(x, y + 1, val, cnt + 1);
}

void calcrg(int x, int y, long long val, int cnt) {
	if (cnt == n + m - 2 - half) {
		if (v[x][y].count(k ^ val))
			ans += v[x][y][k ^ val];
		return;
	}
	if (x > 0)
		calcrg(x - 1, y, val ^ a[x][y], cnt + 1);
	if (y > 0)
		calcrg(x, y - 1, val ^ a[x][y], cnt + 1);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m >> k;
	half = (n + m - 2) / 2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	
	calclf(0, 0, 0, 0);
	calcrg(n - 1, m - 1, 0, 0);
	
	cout << ans << endl;
	
	return 0;
}
```
