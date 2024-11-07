# Tutorial

[1221A - 2048 Game](../problems/A._2048_Game.md "Educational Codeforces Round 73 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1221A - 2048 Game](../problems/A._2048_Game.md "Educational Codeforces Round 73 (Rated for Div. 2)")

It's obvious that we don't need elements that are larger than $2048$.

If the sum of the remaining elements is greater than or equal to 2048, then the answer is YES, and NO otherwise.

It's true because for getting a integer $x$ that wasn't in the multiset initially, we first need to get integer $\frac{x}{2}$.

 **Solution (Roms)**
```cpp
for t in range(int(input())):
	n = input()
	l = filter(lambda x : x <= 2048,  map(int, input().split()) )
	print('YES' if sum(l) >= 2048 else 'NO')
```
[1221B - Knights](../problems/B._Knights.md "Educational Codeforces Round 73 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1221B - Knights](../problems/B._Knights.md "Educational Codeforces Round 73 (Rated for Div. 2)")

Let's denote a cell ($i$, $j$) as black if $i + j$ is even, otherwise the cell is white. It's easy to see that if a knight is occupying a black cell, then all cells attacked by it are white, and vice versa.

Using this fact, we can construct a solution where every pair of knights that attack each other have different colors — put black knights into black cells, and white knights into white cells, so every pair of knights that can possibly form a duel actually form it.

 **Solution (PikMike)**
```cpp
n = int(input())
for i in range(n):
	print(''.join(['W' if (i + j) % 2 == 0 else 'B' for j in range(n)]))
```
[1221C - Perfect Team](../problems/C._Perfect_Team.md "Educational Codeforces Round 73 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1221C - Perfect Team](../problems/C._Perfect_Team.md "Educational Codeforces Round 73 (Rated for Div. 2)")

Notice that if $c \ne m$, then you can equalize them to the min and re-qualify the rest into students without specialization. That won't change the answer.

Now analyze the possible team formations: 1 of each kind, 2 coders and 1 mathematician or 1 coder and 2 mathematicians. Each of these squads have 1 coder and 1 mathematician, so you can only choose the type of the third member.

The students without specialization can only be used in the first kind of teams, so let's use them first. After that you might have been left with a nonzero count of coders and mathematicians. These are equal however, so $\lfloor \frac{c + m}{3} \rfloor$ can be added to the answer.

This solves each query in $O(1)$.

You can also run a binary search and solve each query in $O(\log MAX)$. 

 **Solution 1 (BledDest)**
```cpp
t = int(input())
for i in range(t):
	c, m, x = map(int, input().split())
	d = max(c, m) - min(c, m)
	x += d
	if(c > m):
		c -= d
	else:
		m -= d
	ans = min(c, m, x)
	c -= ans
	m -= ans
	x -= ans
	ans += (c + m) // 3
	print(ans)
```
 **Solution 2 (PikMike)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i){
		int c, m, x;
		cin >> c >> m >> x;
		int l = 0, r = min(c, m);
		int ans = 0;
		while (l <= r){
			int mid = (l + r) / 2;
			if (c + m + x - 2 * mid >= mid){
				l = mid + 1;
				ans = mid;
			}
			else{
				r = mid - 1;
			}
		}
		cout << ans << "n";
	}
}
```
[1221D - Make The Fence Great Again](../problems/D._Make_The_Fence_Great_Again.md "Educational Codeforces Round 73 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1221D - Make The Fence Great Again](../problems/D._Make_The_Fence_Great_Again.md "Educational Codeforces Round 73 (Rated for Div. 2)")

Let's notice that in optimal answer all boards will be increased by no more than two. It is true because if it is beneficial to increase the length of some board by three or more (denote its length as $len$) then increasing to the length $len - 1$, $len - 2$ or $len - 3$ is cheaper and one of these boards is not equal to any of its adjacent boards.

Noticing this, we can write a solution based on dynamic programming. Let's $dp_{pos, add}$ is minimum amount of money for making fence $a_1, a_2, \dots , a_{pos}$ great, moreover the last board(with index $pos$) we increase by $add$. 

Then value $dp_{pos, add}$ can be calculated as follows:

$dp_{pos, add} = add \cdot b_{pos} + \min\limits_{x=0 \dots 2, a_{pos-1}+x \neq a_{pos}+add} dp_{pos-1, x}$

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;
const long long INF64 = (long long)(1e18) + 100;

int t;
int n;
int a[N];
int b[N];
long long dp[3][N];

long long calc(int add, int pos){
	long long &res = dp[add][pos];
	if(res != -1) return res;

	res = INF64;
	if(pos == n) return res = 0;
	for(long long x = 0; x <= 2; ++x)
		if(pos == 0 || a[pos] + x != a[pos - 1] + add)
			res = min(res, calc(x, pos + 1) + x * b[pos]);
		
	return res;
}

int main() {	
	scanf("%d", &t);
	for(int tc = 0; tc < t; ++tc){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", a + i);
			scanf("%d", b + i);
		}

		for(int i = 0; i <= n; ++i) 
			dp[0][i] = dp[1][i] = dp[2][i] = -1;				
		printf("%lldn", calc(0, 0));
	}
	return 0;
} 
```
[1221E - Game With String](../problems/E._Game_With_String.md "Educational Codeforces Round 73 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1221E - Game With String](../problems/E._Game_With_String.md "Educational Codeforces Round 73 (Rated for Div. 2)")

At first, let's transform input to a more convenient form. We consider only such subsegments that consist of the symbols . and which cannot be expanded to the right or left. For example, for $s = XX...X.X...X..$ we consider segments of length $3$, $1$, $3$, and $2$.

Let's divide all such segments into four groups by their length $len$: 

1. $len < b$;
2. $b \le len < a$;
3. $a \le len < 2b$;
4. $len \ge 2b$.

In such a division, each segment belongs to exactly one type.

Suppose that the Bob takes the first turn. If there is a segment of second type, then Bob wins, because he always have a spare turn that Alice cannot make. If there is a segment of fourth type then the Bob also wins because he can make the segment of second type by taking turn in this segment of four type. If there are no segments of second and four types, then victory depends on the parity of the number of segments of the third type.

But it is true if the Bob takes first turn. If Alice takes first turn then she doesn't want, after her move, there are segments of the second and fourth types. So if initially there is a segment of second type then Alice loses because she can't take turns into segment of second type. If there are two or more segments of four type then Alice also loses, because after her turn at least one such segments remains. If there are only one segment of four type then Alice have to take turn into this segment. Since the length of this segment doesn't exceed $n$, we can iterate over all possible Alice moves. After Alice's move segment of fourth type can be divided into no more than two new segments, let's denote their types as $t_1$ and $t_2$. If at least one of these segments of second or fourth type, then it's bad turn for Alice. Otherwise Alice win if remaining number of segment of third type is even (note that $t_1$ or $t_2$ also can be the third type). And finally, if initially there are only segments of first or third type, then victory depends on the parity of the number of segments of the third type.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 99;

int t;
int a, b;
string s;

int main() {
	cin >> t;
	for(int tc = 0; tc < t; ++tc){
		cin >> a >> b >> s;
		vector <int> v;
		int l = 0;
		while(l < s.size()){
			if(s[l] == 'X'){
				++l;
				continue;
			}

			int r = l + 1;
			while(r < s.size() && s[r] == '.') ++r;
			v.push_back(r - l);
			l = r;
		}
		
		bool ok = true;
		int id = -1;
		int cnt = 0;
		for(int i = 0; i < v.size(); ++i){
			if(b <= v[i] && v[i] < a) ok = false;
			if(b + b <= v[i]){
				if(id == -1) id = i;
				else ok = false;
			}
			if(a <= v[i] && v[i] < b + b) ++cnt; 
		}

		if(!ok){
			cout << "NO" << endl;			
			continue;
		}

		if(id == -1){
			if(cnt & 1) cout << "YES" << endl;
			else cout << "NO" << endl;
			continue;
		}

		ok = false;
		int sz = v[id];
		assert(sz >= a);
		for(int rem1 = 0; sz - a - rem1 >= 0; ++rem1){
			int rem2 = sz - a - rem1;
			int ncnt = cnt;
			if((rem1 >= b + b) || (b <= rem1 && rem1 < a)) continue;
			if((rem2 >= b + b) || (b <= rem2 && rem2 < a)) continue;

			if(rem1 >= a) ++ncnt;
			if(rem2 >= a) ++ncnt;
			if(ncnt % 2 == 0) ok = true;
		}
		
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}                             	






```
[1221F - Choose a Square](../problems/F._Choose_a_Square.md "Educational Codeforces Round 73 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1221F - Choose a Square](../problems/F._Choose_a_Square.md "Educational Codeforces Round 73 (Rated for Div. 2)")

Notice that the square ($l, l$) ($r, r$) covers the point ($x, y$) if and only if $l \le min(x, y) \le max(x, y) \le r$.

Using this fact, let's reformulate the problem the following way: we have to find the segment $(l, r)$, such that the sum of the segments fully covered by it is maximal.

Let's build a segment tree, the $r$-th of its leaves stores $f(l, r)$ — the sum of the segments covered by the segment $(l, r)$ . Initially, it's built for some $l$ such that it is to the right of all segments. Other nodes store the maximum in them.

Now let's iterate over the values ​​of $l$ in descending order. Let there be some segment starting in $l$ $(l, x)$ with the cost $c$. All the answers $f(l, r)$ for $r < x$ won't change because they don't cover that new segment. And the values on the suffix from the position $x$ ($r \ge x$) will increase by $c$.

The only thing left is to learn how to handle the subtraction of the length of the side. That term is $(r - l)$ and the thing we are looking for is $\max \limits_{r} f(l, r) - (r - l)$. Rewrite it in form $l + \max \limits_{r} f(l, r) - r$ and you'll see that you can just subtract $r$ from the value of the $r$-th leaf of the segment tree at the beginning to get the correct result. Surely, you'll need to add that $l$ after you ask the maximum of all the segtree to obtain the answer.

You'll probably need to compress the coordinates — leave only such positions $i$ that there is at least one $x = i$ or $y = i$. Implicit segtree might work but neither ML, nor TL are not friendly to it. Also be careful with the case with all points being negative.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)

typedef long long li;
typedef pair<int, int> pt;

const int N = 1000 * 1000 + 13;

int n;
pair<pt, int> a[N];
vector<int> vals;
vector<pt> ev[N];
pair<li, int> t[4 * N];
li add[4 * N];

void build(int v, int l, int r) {
	if (l == r) {
		t[v] = mp(-vals[l], l);
		add[v] = 0;
		return;
	}
	int m = (l + r) >> 1;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m + 1, r);
	t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

void push(int v, int l, int r) {
	if (add[v] == 0) return;
	t[v].x += add[v];
	if (l != r) {
		add[v * 2 + 1] += add[v];
		add[v * 2 + 2] += add[v];
	}
	add[v] = 0;
}

void upd(int v, int l, int r, int L, int R, int val) {
	push(v, l, r);
	if (L > R) return;
	if (l == L && r == R) {
		add[v] += val;
		push(v, l, r);
		return;
	}
	int m = (l + r) >> 1;
	upd(v * 2 + 1, l, m, L, min(m, R), val);
	upd(v * 2 + 2, m + 1, r, max(m + 1, L), R, val);
	t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

pair<li, int> get(int v, int l, int r, int L, int R) {
	push(v, l, r);
	if (L > R) return mp(-li(1e18), 0);
	if (l == L && r == R) return t[v];
	int m = (l + r) >> 1;
	auto r1 = get(v * 2 + 1, l, m, L, min(m, R));
	auto r2 = get(v * 2 + 2, m + 1, r, max(m + 1, L), R);
	return max(r1, r2);
}

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%d%d%d", &a[i].x.x, &a[i].x.y, &a[i].y);
	
	forn(i, n) {
		vals.pb(a[i].x.x);
		vals.pb(a[i].x.y);
	}
	
	vals.pb(0);
	sort(all(vals));
	vals.pb(vals.back() + 1);
	
	vals.resize(unique(all(vals)) - vals.begin());
	
	forn(i, n) {
		int x = lower_bound(all(vals), a[i].x.x) - vals.begin();
		int y = lower_bound(all(vals), a[i].x.y) - vals.begin();
		ev[min(x, y)].pb(mp(max(x, y), a[i].y));
	}
	
	n = sz(vals);
	
	build(0, 0, n - 1);
	
	li ans = -1;
	int ansl = -1, ansr = -1;
	
	for (int i = sz(vals) - 1; i >= 0; i--) {
		for (auto it : ev[i]) upd(0, 0, n - 1, it.x, n - 1, it.y);
		auto cur = get(0, 0, n - 1, i, n - 1);
		if (cur.x + vals[i] > ans) {
			ans = cur.x + vals[i];
			ansl = vals[i]; ansr = vals[cur.y]; 
		}
	}
	
	printf("%lldn%d %d %d %dn", ans, ansl, ansl, ansr, ansr);
	
}
```
[1221G - Graph And Numbers](../problems/G._Graph_And_Numbers.md "Educational Codeforces Round 73 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1221G - Graph And Numbers](../problems/G._Graph_And_Numbers.md "Educational Codeforces Round 73 (Rated for Div. 2)")

Let $F(S)$ be the number of ways to paint the graph so that all numbers on edges belong to the set $S$. Using inclusion-exclusion we may get that the answer is $F(\{0, 1, 2\}) - F(\{1, 2\}) - F(\{0, 2\}) + F(\{2\}) - F(\{0, 1\}) + F(\{1\}) + F(\{0\}) - F(\{\})$.

Okay, let's analyze everything separatedly.

* $F(\{0, 1, 2\})$ is $2^n$, because every number is allowed;
* $F(\{1, 2\})$ will be analyzed later;
* $F(\{0, 2\})$ is $2^C$, where $C$ is the number of connected components — in each component we have to use the same number;
* $F(\{2\})$ is $2^I$, where $I$ is the number of isolated vertices — every non-isolated vertex should have number $1$ on it, and all isolated vertices may have any numbers;
* $F(\{0, 1\}) = F(\{1, 2\})$, since these cases are symmetric;
* $F(\{1\})$ is the number of bipartite colorings of the graph. It is $0$ if the graph contains an odd cycle, or $2^C$ if it is bipartite;
* $F(\{0\}) = F(\{2\})$, since these cases are symmetric;
* $F(\{\})$ is $2^n$ if there are no edges in the graph, otherwise it is $0$.

So, the only thing left to consider is $F(\{1, 2\})$. Actually, it is easier to calculate $F(\{0, 1\})$ — it is the number of independent sets of this graph. This problem is NP-complete, but when $n = 40$, we may apply meet-in-the-middle technique as follows:

1. divide all vertices into two sets $S_1$ and $S_2$ of roughly equal size;
2. for $S_1$, find all its independent subsets, and for each such subset, find which vertices from $S_2$ can be added to it without breaking its independency;
3. for each subset of $S_2$, find the number of independent subsets of $S_1$ such that no vertex from chosen subset of $S_2$ is adjacent to any vertex from chosen subset of $S_1$ (you may use subset DP and OR-convolution here);
4. find all independent subsets of $S_2$, and for every such subset, add the number of subsets of $S_1$ that can be merged with it so the resulting set is independent.

The most time-consuming part is counting all independent sets, so the time complexity is $(O(n2^{n/2}))$.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 40;
const int M = 20;

long long incident_mask[N];
vector<int> g[N];
int n, m;
long long ans = 0;
long long cntmask[1 << M];

long long binpow(long long x, long long y)
{
	long long z = 1;
	while(y > 0)
	{
		if(y % 2 == 1) z *= x;
		x *= x;
		y /= 2;
	}
	return z;
}

int used[N];

void dfs(int x, int c)
{
	if(used[x])
		return;
	used[x] = c;
	for(auto y : g[x])
		dfs(y, 3 - c);
}

long long countIsolated()
{
	long long ans = 0;
	for(int i = 0; i < n; i++)
		if(g[i].empty())
			ans++;
	return ans;
}

long long countComponents()
{
	memset(used, 0, sizeof used);
	long long ans = 0;
	for(int i = 0; i < n; i++)
		if(!used[i])
		{
			ans++;
			dfs(i, 1);
		}
	return ans;
}

bool bipartite()
{
	memset(used, 0, sizeof used);
	for(int i = 0; i < n; i++)
		if(!used[i])
			dfs(i, 1);
	for(int i = 0; i < n; i++)
		for(auto j : g[i])
			if(used[i] == used[j])
				return false;
	return true;
}

long long countIndependentSets()
{
	int m1 = min(n, 20);
	int m2 = n - m1;
	//cerr << m1 << " " << m2 << endl;
	memset(cntmask, 0, sizeof cntmask);
	for(int i = 0; i < (1 << m1); i++)
	{
		long long curmask = 0;
		bool good = true;
		for(int j = 0; j < m1; j++)
		{
			if((i & (1 << j)) == 0)
				continue;
			if(curmask & (1 << j))
				good = false;
			curmask |= ((1 << j) | incident_mask[j]);
		}
		if(good)
		{
			cntmask[curmask >> m1]++;
		}
	}	
	for(int i = 0; i < m2; i++)
		for(int j = 0; j < (1 << m2); j++)
			if(j & (1 << i))
				cntmask[j] += cntmask[j ^ (1 << i)];
	long long ans = 0;
	for(int i = 0; i < (1 << m2); i++)
	{
		long long curmask = 0;
		bool good = true;
		for(int j = m1; j < n; j++)
		{
			if((i & (1 << (j - m1))) == 0)
				continue;
			if(curmask & (1ll << j))
				good = false;
			curmask |= (1ll << j) | incident_mask[j];
		}
		if(good)
		{
			//cerr << i << endl;
			ans += cntmask[(i ^ ((1 << m2) - 1))];
		}
	}
	return ans;
}

long long calc(int mask)
{
	if(mask == 0)
		return binpow(2, n);
	if(mask == 1 || mask == 4)
		return countIndependentSets();
	if(mask == 2)
		return binpow(2, countComponents());
	if(mask == 3 || mask == 6)
		return binpow(2, countIsolated());
	if(mask == 5)
		return (bipartite() ? binpow(2, countComponents()) : 0);
	if(mask == 7)
		return (m == 0 ? binpow(2, n) : 0);
	return 0;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		g[x].push_back(y);
		g[y].push_back(x);
		incident_mask[x] ^= (1ll << y);
		incident_mask[y] ^= (1ll << x);
	}
	for(int i = 0; i < 8; i++)
	{
		//cerr << i << " " << calc(i) << endl;
		if(__builtin_popcount(i) % 2 == 0)
			ans += calc(i);
		else
			ans -= calc(i);
	}
	cout << ans << endl;
    return 0;
}
```
