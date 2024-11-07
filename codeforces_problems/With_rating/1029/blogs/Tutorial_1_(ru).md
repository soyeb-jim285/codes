# Tutorial_1_(ru)

[1029A - Many Equal Substrings](../problems/A._Many_Equal_Substrings.md "Codeforces Round 506 (Div. 3)")

 **Tutorial**
### [1029A - Many Equal Substrings](../problems/A._Many_Equal_Substrings.md "Codeforces Round 506 (Div. 3)")

Let's carry the current answer as $ans$, the last position we're checked as $pos$ and the number of occurrences as $cnt$. Initially, the answer is $t$, $cnt$ is $1$ and $pos$ is $1$ (0-indexed). We don't need to check the position $0$ because there is the beginning of the occurrence of $t$ at this position. Also $cnt$ is $1$ by the same reason. Let's repeat the following algorithm while $cnt < k$: if $pos >= |ans|$, where |ans| is the length of the answer, let's add $t$ to the answer, increase $cnt$ and $pos$ by $1$. In the other case let's check if there is a prefix of $t$ starting from $pos$. If it is, let $len$ be its length. Then we need to add the suffix of $t$ starting from $len$ till the end of $t$, increase $cnt$ and $pos$ by $1$. If there is no prefix of $t$ starting from $pos$ the we just increase $pos$.

The other idea is the following: we have to find the period of the string $t$. Let this period will be $p$. Then the answer is $p$ repeated $k-1$ times and $t$. The period of the string $s$ is the minimum prefix of this string such that we can repeat this prefix infinite number of times so the prefix of this infinite string will be $s$. For example, the period of the string $ababa$ is $ab$, the period of the string $abc$ is $abc$ and the period of the string $aaaaa$ is $a$. The period of the string can be found using prefix-function of the string or in $O(n^2)$ naively.

 **Solution (Vovuh, O(n^2))**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size())

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	string t;
	cin >> n >> k >> t;
	
	int cnt = 1;
	int pos = 1;
	string ans = t;
	while (cnt < k) {
		if (pos >= sz(ans)) {
			ans += t;
			++cnt;
		} else {
			bool ok = true;
			int len = 0;
			for (int i = 0; i < sz(t); ++i) {
				if (pos + i >= sz(ans)) break;
				++len;
				if (ans[pos + i] != t[i]) ok = false;
			}
			if (ok) {
				ans += t.substr(len);
				++cnt;
			}
		}
		++pos;
	}
	
	cout << ans << endl;
	
	return 0;
}
```
 **Solution (Vovuh, prefix-function)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size())

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	string t;
	cin >> n >> k >> t;
	
	vector<int> p(n);
	for (int i = 1; i < sz(t); ++i) {
		int j = p[i - 1];
		while (j > 0 && t[j] != t[i])
			j = p[j - 1];
		if (t[i] == t[j])
			++j;
		p[i] = j;
	}
	
	int len = sz(t) - p[n - 1];
	
	for (int i = 0; i < k - 1; ++i)
		cout << t.substr(0, len);
	cout << t << endl;
	
	return 0;
}
```
[1029B - Creating the Contest](../problems/B._Creating_the_Contest.md "Codeforces Round 506 (Div. 3)")

 **Tutorial**
### [1029B - Creating the Contest](../problems/B._Creating_the_Contest.md "Codeforces Round 506 (Div. 3)")

The answer is always a segment of the initial array. The authors solution uses two pointers technique: let's iterate over all left bounds of the correct contests and try to search maximum by inclusion correct contest. Let's iterate over all $i$ from $0$ to $n-1$ and let the current left bound be $i$. Let $j$ be the maximum right bound of the correct contest starting from the position $i$. Initially $j=i$. Now while $j + 1 < n$ and $a_{j + 1} \le a_j \cdot 2$ let's increase $j$. Try to update the answer with the value $j - i + 1$. It is obvious that all positions from $i + 1$ to $j$ cannot be left bounds of the maximum by inclusion correct contests, so let's set $i=j$ and go on. Because each element will be processed once, time complexity is $O(n)$.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
		
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int j = i;
		while (j + 1 < n && a[j + 1] <= a[j] * 2)
			++j;
		ans = max(ans, j - i + 1);
		i = j;
	}
	
	printf("%dn", ans);
}
```
[1029C - Maximal Intersection](../problems/C._Maximal_Intersection.md "Codeforces Round 506 (Div. 3)")

 **Tutorial**
### [1029C - Maximal Intersection](../problems/C._Maximal_Intersection.md "Codeforces Round 506 (Div. 3)")

Intersection of some segments $[l_1, r_1], [l_2, r_2], \dots, [l_n, r_n]$ is $[\max \limits_{i = 1}^n l_i; \min \limits_{i = 1}^n r_i]$. If this segment has its left bound greater than its right bound then the intersection is empty.

Removing some segment $i$ makes the original sequence equal to $[l_1, r_1], \dots, [l_{i - 1}, r_{i - 1}], \dots [l_{i + 1}, r_{i + 1}], \dots, [l_n, r_n]$. That can be split up to a prefix of length $i - 1$ and a suffix of length $n - i$. Intersections for them can be precalced separately and stored in some partial sum-like arrays. Finally, you have to iterate over the position of the removed segment and calculate the intersection of prefix and suffix without this segment.

Overall complexity: $O(n)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 300 * 1000 + 13;
const int INF = int(1e9);

int n;
int prl[N], prr[N], sul[N], sur[N];
int l[N], r[N];

int main() {
	scanf("%d", &n);
	forn(i, n)
		scanf("%d%d", &l[i], &r[i]);
	
	prl[0] = sul[n] = 0;
	prr[0] = sur[n] = INF;
	
	forn(i, n){
		prl[i + 1] = max(prl[i], l[i]);
		prr[i + 1] = min(prr[i], r[i]);
	}
	
	for (int i = n - 1; i >= 0; --i){
		sul[i] = max(sul[i + 1], l[i]);
		sur[i] = min(sur[i + 1], r[i]);
	}
	
	int ans = 0;
	forn(i, n)
		ans = max(ans, min(prr[i], sur[i + 1]) - max(prl[i], sul[i + 1]));
	printf("%dn", ans);
	return 0;
}
```
[1029D - Concatenated Multiples](../problems/D._Concatenated_Multiples.md "Codeforces Round 506 (Div. 3)")

 **Tutorial**
### [1029D - Concatenated Multiples](../problems/D._Concatenated_Multiples.md "Codeforces Round 506 (Div. 3)")

Let's rewrite concatenation in a more convenient form. $conc(a_i, a_j) = a_i \cdot 10^{len_j} + a_j$, where $len_j$ is the number of digits in $a_j$. Then this number is divisible by $k$ if and only if the sum of ($a_{j}~ mod~ k$) and ($(a_i \cdot 10^{len_j})~ mod~ k$) is either $0$ or $k$.

Let's calculate $10$ arrays of remainders $rem_1, rem_2, \dots, rem_{10}$. For each $i$ $a_i$ adds ($a_{i}~ mod~ k$) to $rem_{len_i}$. That's the first term of the sum.

Now iterate over the second term, for $i \in [1..n]$ and for $j \in [1..10]$ you binary search for ($k - ((a_i \cdot 10^j)~ mod~ k)$) in $rem_j$. The number of its occurrences should be added to answer.

You also might have calculated some pairs $(i, i)$, iterate over them and subtract them naively.

Overall complexity: $O(10 \cdot n \log n)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;

using namespace std;

const int N = 200 * 1000 + 13;
const int LOGN = 11;

int n, k;
int a[N];
int len[N];
vector<int> rems[LOGN];
int pw[LOGN];

int main() {
	scanf("%d%d", &n, &k);
	forn(i, n) scanf("%d", &a[i]);
	
	pw[0] = 1;
	forn(i, LOGN - 1)
		pw[i + 1] = pw[i] * 10 % k;
	
	forn(i, n){
		int x = a[i];
		while (x > 0){
			++len[i];
			x /= 10;
		}
		rems[len[i]].push_back(a[i] % k);
	}
	
	forn(i, LOGN)
		sort(rems[i].begin(), rems[i].end());
	
	li ans = 0;
	forn(i, n){
		for (int j = 1; j < LOGN; ++j){
			int rem = (a[i] * li(pw[j])) % k;
			int xrem = (k - rem) % k;
			auto l = lower_bound(rems[j].begin(), rems[j].end(), xrem);
			auto r = upper_bound(rems[j].begin(), rems[j].end(), xrem);
			ans += (r - l);
			if (len[i] == j && (rem + a[i] % k) % k == 0)
				--ans;
		}
	}
	
	printf("%lldn", ans);
	return 0;
}
```
[1029E - Tree with Small Distances](../problems/E._Tree_with_Small_Distances.md "Codeforces Round 506 (Div. 3)")

 **Tutorial**
### [1029E - Tree with Small Distances](../problems/E._Tree_with_Small_Distances.md "Codeforces Round 506 (Div. 3)")

The first idea is the following: it is always profitable to add the edges from the vertex $1$ to any other vertex. The proof is the following: if we will add two edges $(1, u)$ and $(u, v)$ then the distance to the vertex $u$ will be $1$, the distance to the vertex $v$ will be $2$. But we can add edges $(1, u)$ and $(1, v)$ and this will be better (in fact, you cannot obtain the less answer by adding two edges in the other way).

The main idea is the following. Let's carry all vertices of the tree with the distance more than $2$ in the set. Let the vertex with the maximum distance be $v$. What we will obtain if we will add the edge $(1, v)$? The distance to the vertex $v$ will be $1$ and the distance to the vertex $p_v$ (where $p_v$ is the parent of the vertex $v$ if we will root the tree by the vertex $1$) will be $2$. So we will make reachable at most two vertices (if the vertex $p_v$ is already reachable then it will be not counted in the answer). Now what we will obtain if we will add the edge $(1, p_v)$? We will make reachable all the vertices adjacent to the vertex $p_v$ and the vertex $p_v$ (the number of such vertices is not less than $1$ so this move won't make the answer greater instead of any other way to add the edge). After adding such edge let's remove the vertex $p_v$ and all vertices adjacent to it from the set. We need to repeat this algorithm until the set will not become empty.

Time complexity is $O(n \log n)$.

I sure that there exists the solution with the dynamic programming in the linear time, I will be very happy if someone will explain it to other participants.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 11;

int p[N];
int d[N];
vector<int> g[N];

void dfs(int v, int pr = -1, int dst = 0) {
	d[v] = dst;
	p[v] = pr;
	for (auto to : g[v]) {
		if (to != pr) {
			dfs(to, v, dst + 1);
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dfs(0);
	set<pair<int, int>> st;
	for (int i = 0; i < n; ++i) {
		if (d[i] > 2) {
			st.insert(make_pair(-d[i], i));
		}
	}
	
	int ans = 0;
	while (!st.empty()) {
		int v = st.begin()->second;
		v = p[v];
		++ans;
		auto it = st.find(make_pair(-d[v], v));
		if (it != st.end()) {
			st.erase(it);
		}
		for (auto to : g[v]) {
			auto it = st.find(make_pair(-d[to], to));
			if (it != st.end()) {
				st.erase(it);
			}
		}
	}
	
	printf("%dn", ans);
}
```
[1029F - Multicolored Markers](../problems/F._Multicolored_Markers.md "Codeforces Round 506 (Div. 3)")

 **Tutorial**
### [1029F - Multicolored Markers](../problems/F._Multicolored_Markers.md "Codeforces Round 506 (Div. 3)")

$a+b$ should be area of the outer rectangle. It means that its sides are divisors of $a+b$. The same holds for the inner rectangle. Let's assume that red color forms a rectangle, we'll try it and then swap $a$ with $b$ and solve the same problem again. Write down all the divisors of $a$ up to $\sqrt a$, these are the possible smaller sides of the inner rectangle. Divisors of $a+b$ up to $\sqrt{a+b}$ are possible smaller sides of the outer rectangle. 

Let's put inner rectangle to the left bottom corner of the outer rectangle and choose smaller sides of both of them as bottom and top ones. Iterate over the divisors $d1$ of $a+b$, for each of them choose the greatest divisor $d2$ of $a$ smaller or equal to it and check that $\frac{a+b}{d1} \ge \frac{a}{d2}$. Update the answer with $2(d1 + \frac{a+b}{d1})$ if it holds.

You can use both binary search or two pointers, both get AC pretty easily.

The number of divisors of $n$ can usually be estimated as $n^{\frac 1 3}$.

Overall complexity: $O(\sqrt{a+b})$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;

using namespace std;

const int N = 1000 * 1000;

int lens[N];
int k;

li solve(li a, li b){
	k = 0;
	for (li i = 1; i * i <= b; ++i)
		if (b % i == 0)
			lens[k++] = i;
	
	li ans = 2 * (a + b) + 2;
	li x = a + b;
	int l = 0;
	for (li i = 1; i * i <= x; ++i){
		if (x % i == 0){
			while (l + 1 < k && lens[l + 1] <= i)
				++l;
			if (b / lens[l] <= x / i)
				ans = min(ans, (i + x / i) * 2);
		}
	}
	
	return ans;
}

int main() {
	li a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lldn", min(solve(a, b), solve(b, a)));
	return 0;
}
```
