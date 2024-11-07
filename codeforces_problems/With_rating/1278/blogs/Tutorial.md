# Tutorial

[1278A - Shuffle Hashing](../problems/A._Shuffle_Hashing.md "Educational Codeforces Round 78 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1278A - Shuffle Hashing](../problems/A._Shuffle_Hashing.md "Educational Codeforces Round 78 (Rated for Div. 2)")

The general idea of the solution is to check that string $h$ contains some substring which is a permutation of $p$. The constraints were so low you could do it with any algorithm, even $O(n^3 \log n)$ per test case could pass.

The most straightforward way was to iterate over the substring of $h$, sort it and check if it's equal to $p$ sorted. That's $O(n^3 \log n)$.

Next you could notice than only substrings of length $|p|$ matter and shave another $n$ off the complexity to get $O(n^2 \log n)$.

After that you might remember that the size of the alphabet is pretty low. And one string is a permutation of another one if the amounts of letters 'a', letters 'b' and so on in them are equal. So you can precalculate array $cnt_p$, where $cnt_p[i]$ is equal to the amount of the $i$-th letter of the alphabet in $p$. Calculating this array for $O(n)$ substrings will be $O(n)$ each, so that makes it $O(n^2)$.

Then notice how easy it is to recalculate the letter counts going from some substring $[i; i + |p| - 1]$ to $[i + 1; i + |p|]$. Just subtract $1$ from the amount of the $i$-th letter and add $1$ to the amount of the $(i + |p|)$-th letter. Comparing two array every time will still lead to $O(n \cdot |AL|)$, though.

The final optimization is to maintain the boolean array $eq$ such that $eq_i$ means that $cnt_p[i]$ is equal to the current value of $cnt$ of the substring. You are updating just two values of $cnt$ on each step, thus only two values of $eq$ might change. You want all the $|AL|$ values to be $true$, so keep the number of values $true$ in that array and say "YES" if that number is equal to $|AL|$. That finally makes the solution $O(n)$ per test case.

 **Solution 1 (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

string p, h;

bool read(){
	if (!(cin >> p >> h))
		return false;
	return true;
}

void solve(){
	int n = h.size();
	vector<int> cntp(26);
	forn(i, p.size())
		++cntp[p[i] - 'a'];
	forn(i, n){
		vector<int> cnth(26);
		for (int j = i; j < n; ++j){
			++cnth[h[j] - 'a'];
			if (cntp == cnth){
				puts("YES");
				return;
			}
		}
	}
	puts("NO");
}

int main() {
	int tc;
	scanf("%d", &tc);
	forn(_, tc){
		read();
		solve();
	}
	return 0;
}
```
 **Solution 2 (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int AL = 26;
string p, h;

bool read(){
	if (!(cin >> p >> h))
		return false;
	return true;
}

void solve(){
	vector<int> cntp(AL), cnt(AL);
	vector<bool> eq(AL);
	int sum = 0;
	
	auto chg = [&cntp, &cnt, &eq, &sum](int c, int val){
		sum -= eq[c];
		cnt[c] += val;
		eq[c] = (cntp[c] == cnt[c]);
		sum += eq[c];
	};
	
	forn(i, p.size())
		++cntp[p[i] - 'a'];
	forn(i, AL){
		eq[i] = (cnt[i] == cntp[i]);
		sum += eq[i];
	}
	
	int m = p.size();
	int n = h.size();
	forn(i, n){
		chg(h[i] - 'a', 1);
		if (i >= m) chg(h[i - m] - 'a', -1);
		if (sum == AL){
			puts("YES");
			return;
		}
	}
	
	puts("NO");
}

int main() {
	int tc;
	scanf("%d", &tc);
	forn(_, tc){
		read();
		solve();
	}
	return 0;
}
```
[1278B - A and B](../problems/B._A_and_B.md "Educational Codeforces Round 78 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1278B - A and B](../problems/B._A_and_B.md "Educational Codeforces Round 78 (Rated for Div. 2)")

Assume that $a > b$. Let's denote the minimum number of operations required to make $a$ and $b$ equal as $x$.

There are two restrictions on $x$:

1. At first, $\frac{x(x+1)}{2} \ge a - b$, because if $\frac{x(x+1)}{2} < a - b$ then $a$ will be greater than $b$ (after applying all operations);
2. Secondly, integers $\frac{x(x+1)}{2}$ and $a - b$ must have the same parity, because if they have different parity, then $a$ and $b$ will have different parity (after applying all operations).

It turns out that we always can make integers $a$ and $b$ equal after applying $x$ operations. It's true because we have to add $\frac{\frac{x(x+1)}{2} - a + b}{2} + a - b$ to $b$ and the rest to $a$. And we can get any integer from $0$ to $\frac{z(z+1)}{2}$ as a sum of subset of set $\{1, 2, \dots, z\}$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int t, a, b;

bool ok(int res, int d){
	long long sum = res * 1LL * (res + 1) / 2;
	if(sum < d) return false;
	return sum % 2 == d % 2;
}	

int main() {		
	cin >> t;
	for(int tc = 0; tc < t; ++tc){
		cin >> a >> b;
		int d = abs(a - b);
		if(d == 0){ 
			cout << "0n";
			continue;
		}

		int res = 1;
		while(!ok(res, d)) ++res;
		cout << res << endl;
		
	}
	return 0;
}
```
[1278C - Berry Jam](../problems/C._Berry_Jam.md "Educational Codeforces Round 78 (Rated for Div. 2)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1278C - Berry Jam](../problems/C._Berry_Jam.md "Educational Codeforces Round 78 (Rated for Div. 2)")

Let's transit from counting strawberry and blueberry jam jars separately to their difference. Let $dif$ be equal to $\\#of\\_strawberry\\_jars - \\#of\\_blueberry\\_jars$. Then eating one strawberry jar decreases $dif$ by $1$ and eating one blueberry jar increases $dif$ by $1$. The goal is to make $dif$ equal to $0$.

Let there be some initial difference $dif_{init}$. Let's eat first $l$ jars from the left and first $r$ jars from the right. Difference of the jars on the left is $difl$, on the right it's $difr$. So the goal becomes to find such $l$ and $r$ that $dif_{init} - difl_l - difr_r = 0$. Rewrite that as $dif_{init} - difl_l = difr_r$. Now for each unique value of $difr_r$ save the smallest $r$ to reach that value in a map. Finally, iterate over the $l$ and find the minimum answer.

Overall complexity: $O(n \log n)$.

 **Solution (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n;
vector<int> a;

bool read(){
	if (scanf("%d", &n) != 1)
		return false;
	a.resize(2 * n);
	forn(i, 2 * n)
		scanf("%d", &a[i]);
	return true;
}

void solve(){
	int cur = 0;
	map<int, int> difr;
	
	difr[0] = 0;
	cur = 0;
	for (int i = n; i < 2 * n; ++i){
		if (a[i] == 1)
			++cur;
		else
			--cur;
		if (!difr.count(cur))
			difr[cur] = i - (n - 1);
	}
	
	int ans = 2 * n;
	int dif = count(a.begin(), a.end(), 1) - count(a.begin(), a.end(), 2);
	
	cur = 0;
	for (int i = n - 1; i >= 0; --i){
		if (a[i] == 1)
			++cur;
		else
			--cur;
		if (difr.count(dif - cur))
			ans = min(ans, n - i + difr[dif - cur]);
	}
	if (difr.count(dif)){
		ans = min(ans, difr[dif]);
	}
	
	printf("%dn", ans);
}

int main() {
	int tc;
	scanf("%d", &tc);
	forn(_, tc){
		read();
		solve();
	}
	return 0;
}
```
[1278D - Segment Tree](../problems/D._Segment_Tree.md "Educational Codeforces Round 78 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1278D - Segment Tree](../problems/D._Segment_Tree.md "Educational Codeforces Round 78 (Rated for Div. 2)")

The main idea of the solution is to find a linear number of intersections of segments.

Intersections can be found with sweep line approach. We will maintain a set for the endpoints open segments. When we add a segment, we find all segments which intersect with it — that is, all segments that end earlier than it. 

Obviously, if the number of intersections are greater than $n-1$, then the answer is "NO". So as soon as we find $n$ intersections, we stop our algorithm.

After that, it is necessary to check the connectivity of the resulting graph. You can use DFS or DSU to do this.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;
typedef pair<li, li> pt;

const int N = 500010;

int n;
pt a[N];
vector<int> g[N];
bool used[N];

void dfs(int v, int p = -1) {
	used[v] = true;
	for (auto to : g[v]) if (to != p) {
		if (!used[to])
			dfs(to, v);
	}
}

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%d%d", &a[i].x, &a[i].y);
	
	vector<pt> evs;
	forn(i, n) {
		evs.pb(mp(a[i].x, i));
		evs.pb(mp(a[i].y, i));
	}
	
	sort(all(evs));
	
	int cnt = 0;
	set<pt> cur;
	for (auto it : evs) {
		if (cnt >= n) break;
		if (cur.count(it)) {
			cur.erase(it);
		} else {
			int i = it.y;
			int r = a[i].y;
			for (auto jt : cur) {
				if (jt.x > r) break;
				int j = jt.y;
				g[i].pb(j);
				g[j].pb(i);
				cnt++;
				if (cnt >= n) break;
			}
			cur.insert(mp(a[i].y, i));
		}
	}
	
	dfs(0);
	puts(cnt == n - 1 && count(used, used + n, 1) == n ? "YES" : "NO");
}
```
[1278E - Tests for problem D](../problems/E._Tests_for_problem_D.md "Educational Codeforces Round 78 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1278E - Tests for problem D](../problems/E._Tests_for_problem_D.md "Educational Codeforces Round 78 (Rated for Div. 2)")

For each vertex, we will build the following structure for its children: the segment for the second child is nested in the segment for the first child, the nested for the third child is nested in the segment for the second child, and so on; and the children of different vertices do not intersect at all.

Let's solve the problem recursively: for each of the children, create a set of segments with endpoints from $1$ to $2k$, where $k$ is the size of the subtree. After that, combine them. To do this, you can use small-to-large technique and change the coordinates of the segments or use the necessary offset in the function call for the next child.

After that, it remains to cross children's segments with the segment of the vertex itself. To do this, you can move the right ends of all segments of the children by $1$ to the right, and add a segment that starts before the first one and ends immediately after the last one.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef pair<int, int> pt;

const int N = 500 * 1000 + 13;

int n;
vector<int> g[N], vs[N];
pt segs[N];

void dfs(int v, int p = -1) {
	int sum = 0;
	int bst = -1;
	for (auto to : g[v]) if (to != p) {
		dfs(to, v);
		sum += 2 * sz(vs[to]);
		if (bst == -1 || sz(vs[to]) > sz(vs[bst]))
			bst = to;
	}
	
	if (bst == -1) {
		vs[v].pb(v);
		segs[v] = mp(1, 2);
		return;
	}
	
	swap(vs[v], vs[bst]);
	int lst = segs[bst].y;
	
	sum -= 2 * sz(vs[v]);
	sum += 1;
	segs[bst].y += sum;
	
	for (auto to : g[v]) if (to != p && to != bst) {
		int add = lst - 1;
		for (auto u : vs[to]) {
			segs[u].x += add;
			segs[u].y += add;
			vs[v].pb(u);
		}
		lst = segs[to].y;
		sum -= 2 * sz(vs[to]);
		segs[to].y += sum;
		vs[to].clear();
	}
	
	vs[v].pb(v);
	segs[v] = mp(lst, segs[bst].y + 1);
}	

int main() {
	scanf("%d", &n);
	forn(i, n - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	dfs(0);
	
	for (int i = 0; i < n; i++)
		printf("%d %dn", segs[i].x, segs[i].y);
	
	return 0;
}
```
[1278F - Cards](../problems/F._Cards.md "Educational Codeforces Round 78 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1278F - Cards](../problems/F._Cards.md "Educational Codeforces Round 78 (Rated for Div. 2)")

First of all, I would like to thank [Errichto](https://codeforces.com/profile/Errichto "International Grandmaster Errichto") for his awesome lecture on expected value: [part 1](https://codeforces.com/blog/entry/62690), [part 2](https://codeforces.com/blog/entry/62792). This problem was invented after I learned the concept of estimating the square of expected value from that lecture — and the editorial uses some ideas that were introduced there.

Okay, now for the editorial itself. We call a number a as good if 1≤a≤n, and the a-th shuffle of the deck resulted in a joker on top. x from our problem is the number of such good numbers a. We can represent x2 as the number of pairs (a1,a2) such that every element of the pair is a good number, x3 as the number of triples, and so on — xk is the number of k-tuples (a1,a2,…,ak) such that each element of a tuple is a good number.

So we can rewrite the expected value of xk as the expected number of such tuples, or the sum of P(t) over all tuples t, where P(t) is the probability that t consists of good numbers. How to calculate the probability that t is a good tuple? Since all shuffles of the deck result in a joker with probability 1m, P(t) should be equal to 1mk — but that is true only if all elements in t are unique. How to deal with tuples with repeating elements? Since all occurences of the same element are either good or bad (with probability 1m of being good), the correct formula for P(t) is P(t)=1md, where d is the number of distinct elements in the tuple.

Okay, then for each d∈[1,k] we have to calculate the number of k-tuples with exactly d distinct elements. To do that, we use dynamic programming: let dpi,j be the number of i-tuples with exactly j distinct elements. Each transition in this dynamic programming solution models adding an element to the tuple; if we want to compute the transitions leading from dpi,j, we either add a new element to the tuple (there are n−j ways to choose it, and we enter the state dpi+1,j+1), or we add an already existing element (there are j ways to choose it, and we enter the state dpi+1,j).

Overall complexity is O(k2logMOD) or O(k2+logMOD), depending on your implementation.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 5043;

int add(int x, int y)
{
	x += y;
	while(x >= MOD) x -= MOD;
	while(x < 0) x += MOD;
	return x;
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
	int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}

int inv(int x)
{
	return binpow(x, MOD - 2);
}

int n, m, k;

int dp[N][N];

int main()
{
	cin >> n >> m >> k;
	dp[0][0] = 1;
	for(int i = 0; i < k; i++)
		for(int j = 0; j < k; j++)
		{
			dp[i + 1][j] = add(dp[i + 1][j], mul(dp[i][j], j));
			dp[i + 1][j + 1] = add(dp[i + 1][j + 1], mul(dp[i][j], n - j));
		}
	int ans = 0;
	for(int i = 1; i <= k; i++)
		ans = add(ans, mul(dp[k][i], binpow(inv(m), i)));
	cout << ans << endl;
}
```
