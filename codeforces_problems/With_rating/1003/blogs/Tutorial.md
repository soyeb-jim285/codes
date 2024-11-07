# Tutorial

[1003A - Polycarp's Pockets](../problems/A._Polycarp's_Pockets.md "Codeforces Round 494 (Div. 3)")

 **Tutorial**
### [1003A - Polycarp's Pockets](../problems/A._Polycarp's_Pockets.md "Codeforces Round 494 (Div. 3)")

We have to find the maximum number of elements with the same value (it can be done by counting). This number will be the answer because if there are no more than $k$ elements with the same value in the array it is obvious that we cannot use less than $k$ pockets, but we also doesn't need to use more than $k$ pockets because of the other values can be also distributed using $k$ pockets.

Overall complexity is $O(n + maxAi)$.

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
	
	vector<int> cnt(101);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
	}
	
	cout << *max_element(cnt.begin(), cnt.end()) << endl;
	
	return 0;
}
```
[1003B - Binary String Constructing](../problems/B._Binary_String_Constructing.md "Codeforces Round 494 (Div. 3)")

 **Tutorial**
### [1003B - Binary String Constructing](../problems/B._Binary_String_Constructing.md "Codeforces Round 494 (Div. 3)")

This problem has several general cases:

* $x$ is even and $a > b$, then the answer is 01 repeated $\frac{x}{2}$ times, then $b - \frac{x}{2}$ ones and $a - \frac{x}{2}$ zeroes;
* $x$ is even and $a \le b$, then the answer is 10 repeated $\frac{x}{2}$ times, then $a - \frac{x}{2}$ zeroes and $b - \frac{x}{2}$ ones;
* $x$ is odd and $a > b$, then the answer is 01 repeated $\lfloor\frac{x}{2}\rfloor$ times, then $a - \lfloor\frac{x}{2}\rfloor$ zeroes and $b - \lfloor\frac{x}{2}\rfloor$ ones;
* $x$ is odd and $a \le b$, then the answer is 10 repeated $\lfloor\frac{x}{2}\rfloor$ times, then $b - \lfloor\frac{x}{2}\rfloor$ ones and $a - \lfloor\frac{x}{2}\rfloor$ zeroes.

I am sure that there are other more beautiful solution, but for me the easiest way to solve this problem is to extract general cases and handle it.

Overall complexity is $O(a + b)$.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int a, b, x;
	cin >> a >> b >> x;
	
	if (x % 2 == 0) {
		if (a > b) {
			for (int i = 0; i < x / 2; ++i)
				cout << "01";
			cout << string(b - x / 2, '1');
			cout << string(a - x / 2, '0');
		} else {
			for (int i = 0; i < x / 2; ++i)
				cout << "10";
			cout << string(a - x / 2, '0');
			cout << string(b - x / 2, '1');
		}
	} else if (a > b) {
		for (int i = 0; i < x / 2; ++i)
			cout << "01";
		cout << string(a - x / 2, '0');
		cout << string(b - x / 2, '1');
	} else {
		for (int i = 0; i < x / 2; ++i)
			cout << "10";
		cout << string(b - x / 2, '1');
		cout << string(a - x / 2, '0');
	}
	cout << endl;
	
	return 0;
}
```
[1003C - Intense Heat](../problems/C._Intense_Heat.md "Codeforces Round 494 (Div. 3)")

 **Tutorial**
### [1003C - Intense Heat](../problems/C._Intense_Heat.md "Codeforces Round 494 (Div. 3)")

This task is very straight-forward implementation problem. So we can iterate over all segments of the given array, calculate their sum, and if the length of the current segment is not less than $k$, try to update the answer with the mean of this segment.

Overall complexity is $O(n^2)$.

 **Solution (PikMike)**
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

const int INF = int(2e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 10000 + 7;

int n, k;
int a[N];

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	forn(i, n) scanf("%d", &a[i]);
	return true;
}

int pr[N];

void solve() {
	pr[0] = 0;
	forn(i, n) pr[i + 1] = pr[i] + a[i];
	
	ld ans = 0;
	forn(r, n) forn(l, r + 1){
		if (r - l + 1 >= k){
			ans = max(ans, (pr[r + 1] - pr[l]) / ld(r - l + 1));
		}
	}
	
	printf("%.15fn", double(ans));
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

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}
```
[1003D - Coins and Queries](../problems/D._Coins_and_Queries.md "Codeforces Round 494 (Div. 3)")

 **Tutorial**
### [1003D - Coins and Queries](../problems/D._Coins_and_Queries.md "Codeforces Round 494 (Div. 3)")

We can solve the problem by the following way: firstly, for each power of $2$ let's calculate the number of coins with the value equals this degree. Let's call it $cnt$.

It is obvious that we can obtain the value $b_j$ greedily (because all less values of coins are divisors of all greater values of coins).

Now let's iterate over all powers of $2$ from $30$ to $0$. Let's $deg$ be the current degree. We can take $min(\lfloor\frac{b_j}{2^{deg}}\rfloor, cnt_{deg})$ coins with the value equals $2^{deg}$. Let it be $cur$. Add $cur$ to the answer and subtract $2^{deg} \cdot cur$ from $b_j$.

If after iterating over all powers $b_j$ still be non-zero, print -1. Otherwise print the answer.

Overall complexity: $O((n + q) \log maxAi)$.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, q;
	cin >> n >> q;
	
	vector<int> cnt(31);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++cnt[__builtin_ctz(x)];
	}
	
	while (q--) {
		int x;
		cin >> x;
		
		int ans = 0;
		for (int i = 30; i >= 0 && x > 0; --i) {
			int need = min(x >> i, cnt[i]);
			ans += need;
			x -= (1 << i) * need;
		}
		
		if (x > 0)
			ans = -1;
		cout << ans << endl;
	}
	
	return 0;
}
```
[1003E - Tree Constructing](../problems/E._Tree_Constructing.md "Codeforces Round 494 (Div. 3)")

 **Tutorial**
### [1003E - Tree Constructing](../problems/E._Tree_Constructing.md "Codeforces Round 494 (Div. 3)")

Let's construct a tree by the following algorithm: if $d \ge n$, let's print "NO" and terminate the program. Otherwise let's keep the array $deg$ of the length $n$ which will represent degrees of vertices.

The first step is to construct the diameter of the tree. Let first $d + 1$ vertices form it. Let's add $d$ edges to the answer, increase degrees of vertices corresponding to this edges, and if some vertex has degree greater than $k$, print "NO" and terminate the program.

The second (and the last) step is to attach the remaining $n - d - 1$ vertices to the tree. Let's call the vertex free if its degree is less than $k$. Also let's keep all free vertices forming the diameter in some data structure which allows us to take the vertex with the minimum maximal distance to any other vertex and remove such vertices. It can be done by, for example, set of pairs ($dist_v, v$), where $dist_v$ is a maximum distance from the vertex $v$ to any other vertex. Now let's add all vertices from starting from the vertex $d + 1$ (0-indexed) to the vertex $n - 1$, let the current vertex be $u$. We get the vertex with the minimum maximal distance to any other vertex, let it be $v$. Now we increase the degree of vertices $u$ and $v$, add the edge between they, and if $v$ still be free, return it to the data structure, otherwise remove it. The same with the vertex $u$ (it is obvious that its maximal distance to any other vertex will be equals $dist_v + 1$).

If at any step our data structure will be empty or the minimum maximal distance will be equals $d$, the answer is "NO". Otherwise we can print the answer. See my solution to better understanding.

Overall complexity: $O(n \log n)$ or $O(n)$ (depends on implementation).

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, d, k;
	cin >> n >> d >> k;
	
	if (d >= n) {
		cout << "NO" << endl;
		return 0;
	}
	
	vector<int> deg(n);
	vector<pair<int, int>> ans;
	set<pair<int, int>> q;
	
	for (int i = 0; i < d; ++i) {
		++deg[i];
		++deg[i + 1];
		if (deg[i] > k || deg[i + 1] > k) {
			cout << "NO" << endl;
			return 0;
		}
		ans.push_back(make_pair(i, i + 1));
	}
	for (int i = 1; i < d; ++i)
		q.insert(make_pair(max(i, d - i), i));
	
	for (int i = d + 1; i < n; ++i) {
		while (!q.empty() && deg[q.begin()->second] == k)
			q.erase(q.begin());
		if (q.empty() || q.begin()->first == d) {
			cout << "NO" << endl;
			return 0;
		}
		++deg[i];
		++deg[q.begin()->second];
		ans.push_back(make_pair(i, q.begin()->second));
		q.insert(make_pair(q.begin()->first + 1, i));
	}
	
	assert(int(ans.size()) == n - 1);
	cout << "YES" << endl;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
	    p[i] = i;
	random_shuffle(p.begin(), p.end());
	for (int i = 0; i < n - 1; ++i)
	    if (rand() % 2)
		    cout << p[ans[i].first] + 1 << " " << p[ans[i].second] + 1 << endl;
		else
		    cout << p[ans[i].second] + 1 << " " << p[ans[i].first] + 1 << endl;
	
	return 0;
}
```
[1003F - Abbreviation](../problems/F._Abbreviation.md "Codeforces Round 494 (Div. 3)")

 **Tutorial**
### [1003F - Abbreviation](../problems/F._Abbreviation.md "Codeforces Round 494 (Div. 3)")

Let $eq_{i, j}$ equals true if words $s_i$ and $s_j$ are equal, otherwise it will be equals false. We can iterate over all pairs of words and compare they just using standard string comparator (constraints are really small so we can do it naively).

The next step is to calculate dynamic programming $dp_{i, j}$, which will be equal to the maximum length of coinciding segments of words which starts in positions $i$ and $j$, respectively. In other words, if $dp_{i, j}$ equals $k$, then $s[i..i+k-1] = s[j..j+k-1]$, word by word. We can calculate this dynamic programming in reverse order ($i := n - 1 .. 0, j := n - 1 .. 0$) and $dp_{i, j} := 0$ if $s_i \ne s_j$, else if $i < n - 1$ and $j < n - 1$, then $dp_{i, j} := dp_{i + 1, j + 1} + 1$, otherwise $dp_{i, j} := 1$.

Let's keep the length of the text in the variable $allsum$. Then iterate over all starting positions of the possible abbreviation and all its possible lengths. Let the current starting position will be equals $i$ (0-indexed) and its length will be equal $j$. Then we need to calculate the number of possible replacements by its abbreviation. Let it be $cnt$ and now it equals $1$. Let's iterate over all positions $pos$, at the beginning $pos = i + j$ (0-indexed). If $dp_{i, pos} \ge j$ then we can replace the segment of words which starts at the position $pos$ with its abbreviation, so $cnt := cnt + 1$ and $pos := pos + j$ (because we cannot replace intersecting segments), otherwise $pos := pos + 1$.

After this we need to update the answer. The length of the segment of words $s[i..j]$ can be calculated easily, let it be $seglen$. Also let $segcnt$ be the number of words in the current segment of words. Then we can update the answer with the value $allsum - seglen * cnt + cnt * segcnt$.

Overall complexity is $O(n^3 + n \cdot \sum\limits_{i = 0}^{n - 1}|s_i|)$, where $|s_i|$ is the length of the $i$-th word.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 303;

int n;
bool eq[N][N];
int dp[N][N];
string s[N];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	int allsum = n - 1;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		allsum += s[i].size();
	}
	
	for (int i = 0; i < n; ++i) {
		eq[i][i] = true;
		for (int j = 0; j < i; ++j) {
			eq[i][j] = eq[j][i] = s[i] == s[j];
		}
	}
	
	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			if (eq[i][j]) {
				if (i + 1 < n && j + 1 < n)
					dp[i][j] = dp[i + 1][j + 1] + 1;
				else
					dp[i][j] = 1;
			}
		}
	}
	
	int ans = allsum;
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; i + j < n; ++j) {
			sum += s[i + j].size();
			int cnt = 1;
			for (int pos = i + j + 1; pos < n; ++pos) {
				if (dp[i][pos] > j) {
					++cnt;
					pos += j;
				}
			}
			int cur = allsum - sum * cnt + (j + 1) * cnt - j * cnt;
			if (cnt > 1 && ans > cur) {
				ans = cur;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
```
