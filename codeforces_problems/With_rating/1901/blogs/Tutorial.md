# Tutorial

[1901A - Line Trip](../problems/A._Line_Trip.md "Educational Codeforces Round 158 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1901A - Line Trip](../problems/A._Line_Trip.md "Educational Codeforces Round 158 (Rated for Div. 2)")

We can iterate over the volume of the gas tank from 1 to ∞ (in fact 200 is enough due to problem limitations) and check whether it's enough to travel from the point 0 to the point x, and back.

Let the volume be V, then all the following inequalities (which correspond to the ability to travel from the current gas station, having a full tank, to the next one) must be met: a1−0≤V, a2−a1≤V, ..., an−an−1≤V, and 2(x−an)≤V (the multiplier 2 because there is no gas station at x, and we have to go from an to x and back without refueling). If all these conditions hold, then V can be the answer.

However, we can notice that the minimum value of V that is sufficient for the travel is just the maximum of the left sides of inequalities written above. In other words, the answer to the problem is max(a1,a2−a1,…,an−an−1,2(x−an)).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int prev = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
      int a; cin >> a;
      ans = max(ans, a - prev);
      prev = a;
    }
    ans = max(ans, 2 * (x - prev));
    cout << ans << 'n';
  }
}
```
[1901B - Chip and Ribbon](../problems/B._Chip_and_Ribbon.md "Educational Codeforces Round 158 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1901B - Chip and Ribbon](../problems/B._Chip_and_Ribbon.md "Educational Codeforces Round 158 (Rated for Div. 2)")

At first, let's change the statement a bit: instead of teleporting our chip into cell $x$, we create a new chip in cell $x$ (it means that the chip does not disappear from the cell where it was located). And when we want to move a chip, we move any chip to the next cell. Then, $c_i$ will be the number of times a chip appeared in the cell $i$, and the problem will be the same: ensure the condition on each $c_i$ by "creating" the minimum number of chips.

Let's look at value of $c_1$. If $c_1 > 1$, we have to create at least $c_1 - 1$ new chips in cell $1$. Let's create that number of chips in that cell.

Then, let's see how we move chips from the cell $i$ to the cell $(i+1)$. If $c_i \ge c_{i+1}$, then all chips that appeared in the cell $(i+1)$ could be moved from the $i$-th cell, so we don't need to create any additional chips in that cell.

But if $c_i < c_{i+1}$, then at least $c_{i+1} - c_i$ chips should be created in the cell $(i+1)$, since we can move at most $c_i$ chips from the left.

So, for every $i$ from $2$ to $n$, we have to create $\max(0, c_i - c_{i-1})$ chips in the $i$-th cell; and the number of times we create a new chip in total is $c_1 - 1 + \sum\limits_{i=2}^{n} \max(0, c_i - c_{i-1})$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 200'000;
 
int t;
 
int main() {
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int n;
        cin >> n;
        vector <int> cnt(n);
        long long res = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cin >> cnt[i];
            if (cnt[i] > cur) 
                res += cnt[i] - cur;
            cur = cnt[i];
        }
        
        cout << res - 1 << endl;
    }
    return 0;
}
```
[1901C - Add, Divide and Floor](../problems/C._Add,_Divide_and_Floor.md "Educational Codeforces Round 158 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1901C - Add, Divide and Floor](../problems/C._Add,_Divide_and_Floor.md "Educational Codeforces Round 158 (Rated for Div. 2)")

Sort the array. Notice how applying the operation doesn't change the order of the elements, regardless of $x$. It means that it's enough to make the initial minimum and maximum equal to make all elements equal.

Consider the difference between the minimum and the maximum values. What happens to it after an operation? Let the minimum be $a$ and the maximum be $b$. Then it's $\lfloor \frac{b + x}{2} \rfloor - \lfloor \frac{a + x}{2} \rfloor$. The roundings are difficult to deal with, so let's pretend the parities always align to even. So it's $\frac{b + x}{2} - \frac{a + x}{2} = \frac{b - a}{2}$. Apparently, the difference is just getting divided by $2$.

Let's bring the parities back. Notice that the rounding of the difference depends only on the parities of $a, b$ and $x$. You can consider all cases of parities of $a$ and $b$ to discover that it's always possible to divide the difference by $2$, rounding down, and it's never possible to make it less than that.

One easy algorithm to achieve that is the following: if the minimum is even, choose $x = 0$; otherwise, choose $x = 1$. Repeat until the minimum is equal to the maximum.

Overall complexity: $O(n + \log A)$ per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	x, y = min(a), max(a)
	res = []
	while x != y:
		res.append(x % 2)
		x = (x + res[-1]) // 2
		y = (y + res[-1]) // 2
	print(len(res))
	if len(res) <= n:
		print(*res)
```
[1901D - Yet Another Monster Fight](../problems/D._Yet_Another_Monster_Fight.md "Educational Codeforces Round 158 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1901D - Yet Another Monster Fight](../problems/D._Yet_Another_Monster_Fight.md "Educational Codeforces Round 158 (Rated for Div. 2)")

Let's start with a naive solution. Let $i$ be the index of the monster we started with. Let's make sure that we can kill all monsters, starting with monster $i$.

Suppose we have chosen spell power $x$. How to check if all monsters will be definitely killed? Let's iterate on each monster $j$ and calculate the minimum possible damage it can get:

* if $i = j$, then the $j$-th monster will receive exactly $x$ damage. So, $x$ should be at least $a_j$;
* if $i > j$, then the minimum amount of damage the $j$-th monster may receive happens when the spell first strikes all monsters to the right of monster $i$, and then goes to the left of monster $i$. It means that $n - j$ monsters will be struck before the $j$-th monster, so the $j$-th monster will receive $x - (n-j)$ damage. So, $x$ should be at least $a_j + (n-j)$ for every $j < i$;
* and if $i < j$, then the minimum amount of of damage the $j$-th monster may receive happens when the spell first strikes all monsters to the left of monster $i$, and then goes to the right of monster $i$. It means that $j-1$ monsters will be struck before the $j$-th monster, so the $j$-th monster will receive $x - (j-1)$ damage. So, $x$ should be at least $a_j + (j-1)$ for every $j > i$.

So, if we want to start with the $i$-th monster, the minimum spell power we need is $\max(\max\limits_{j=1}^{i-1} a_j + (n-j), a_i, \max\limits_{j=i+1}^{n} a_j + (j-1))$. This gives us a solution in $O(n^2)$, but it can be sped up to $O(n)$ using prefix and suffix maxima.

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    
    vector<int> pref(n), suf(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = a[i] + (n - i - 1);
        suf[i] = a[i] + i;
    }
    for (int i = 1; i < n; ++i) {
        pref[i] = max(pref[i], pref[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = max(suf[i], suf[i + 1]);
    }
    
    int ans = 2e9;
    for (int i = 0; i < n; ++i) {
        int cur = a[i];
        if (i > 0) cur = max(cur, pref[i - 1]);
        if (i + 1 < n) cur = max(cur, suf[i + 1]);
        ans = min(ans, cur);
    }
    
    cout << ans << endl;
    
    return 0;
}
```
[1901E - Compressed Tree](../problems/E._Compressed_Tree.md "Educational Codeforces Round 158 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1901E - Compressed Tree](../problems/E._Compressed_Tree.md "Educational Codeforces Round 158 (Rated for Div. 2)")

We can use dynamic programming on tree to solve this problem. After we're done removing vertices, a vertex will be left in the tree after the compression process if and only if its degree is not $2$. So, we can try to choose the number of children for each vertex in dynamic programming, and depending on this number of children, the vertex we're considering is either removed from the tree during the compression, or left in the tree.

But if we want to use dynamic programming, we have to root the tree at some vertex, so the degree of each vertex depends not only on the number of its children we left in the tree, but also on whether there exists an edge leading from the ancestor to that vertex. So, for each vertex, we will consider two values of dynamic programming: the best answer for its subtree if there is an edge leading into it from the parent (i. e. we haven't deleted everything outside of that subtree), and the answer if there is no edge leading from the parent (i. e. we deleted everything outside of that subtree).

Let the first of these two values be $dp_v$ — the maximum answer for subtree of $v$ if there is at least one non-deleted vertex not in the subtree of vertex $v$ (i.e there is an edge from vertex $v$ up the tree).

Let's look at the dp transitions, depending on the number of children of vertex $v$ that are not deleted: 

* $0$: $dp_v = \max(dp_v, a_v)$;
* $1$: $dp_v = \max(dp_v, \max\limits_u dp_u)$ ($a_v$ is not taken into account, because $v$ has $2$ incident edges and will be compressed);
* at least $2$: $dp_v = \max(dp_v, a_v + \sum\limits_u dp_u)$.

Then let us consider the case when the resulting tree is in the subtree of some vertex $v$. We can update the global answer depending on the number of children of vertex $v$ that are not deleted:

* $0$: $ans = \max(ans, a_v)$;
* $1$: $ans = \max(ans, a_v + \max\limits_u dp_u)$;
* $2$: $ans = \max(ans, \max\limits_{u_1, u_2} dp_{u_1} + dp_{u_2})$ ($a_v$ is not taken into account, because $v$ has $2$ incident edges and will be compressed);
* at least $3$: $ans = \max(ans, a_v + \sum\limits_u dp_u)$.

For convenience, we can calculate auxiliary dynamic programming for children of vertex $v$: $sum_i$ is the maximum sum of $dp_u$ for $i$ children. From above written transitions, we can see that, $sum_3$ can store maximum sum for at least $3$ children. 

Don't forget that we can delete all vertices, so the answer is at least $0$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
using li = long long;
 
const li INF = 1e18;
const int N = 555555;
 
int n;
int a[N];
vector<int> g[N];
li dp[N];
li ans;
 
void calc(int v, int p) {
  vector<li> sum(4, -INF);
  sum[0] = 0;
  for (int u : g[v]) if (u != p) {
    calc(u, v);
    for (int i = 3; i >= 0; --i) {
      sum[min(i + 1, 3)] = max(sum[min(i + 1, 3)], sum[i] + dp[u]);
    }
  }
  dp[v] = -INF;
  for (int j = 0; j < 4; ++j) {
    dp[v] = max(dp[v], sum[j] + (j == 1 ? 0 : a[v]));
    ans = max(ans, sum[j] + (j == 2 ? 0 : a[v]));
  }
}
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) g[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    ans = 0;
    calc(0, -1);
    cout << ans << 'n';
  }
}
```
[1901F - Landscaping](../problems/F._Landscaping.md "Educational Codeforces Round 158 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1901F - Landscaping](../problems/F._Landscaping.md "Educational Codeforces Round 158 (Rated for Div. 2)")

Let's say that we are searching for the best line that contains the best segment.

Observation $1$: the best line touches at least one vertex of the polyline. Otherwise, you can push it down until it touches polyline.

Observation $2$: the best line touches two vertices of the polyline. Suppose it touches only one vertex $i$ then it's not hard to prove that rotating the line around point $i$ either clockwise or counterclockwise will decrease the area under the line.

Observation $3$: if both points are on the left half ($i < j < \frac{n}{2}$) then rotating the line clockwise around point $j$ will decrease the area. Analogically, if both points are on the right half ($\frac{n}{2} < i < j$) then rotating the line counterclockwise around $i$ will decrease the area.

Observation $4$: since all points of the polyline should be under the line, then the vertices the line touches are the consecutive vertices on the convex hull of the polyline.

In total, we understand that the pair of points we need forms a segment of the convex hull that crosses a vertical line $x = \frac{n}{2}$.

Knowing that, what can we do? Let's split all vertices in two halves: "left half" with all vertices to the left of $\frac{n}{2}$ and "right half" with all vertices to the right. Note that while we process the first half of "queries" the right half (vertices in $[\frac{n}{2}, n - 1]$) remains the same. If we know how to process the first half of queries, then processing the second half is practically the same thing but in the reverse order.

So, how to find that best segment of the convex hull that crosses $x = \frac{n}{2}$ efficiently while we work with the left half of vertices? Note that if we look at all segments that connect vertex from the left part with vertex from the right part: 

1. each segment will certainly cross $x = \frac{n}{2}$ in some real point $y_c$;
2. the segment of the convex hull will have maximum possible $y_c$ (otherwise, it's not a convex hull segment).

There are around $n^2$ segment that crosses $\frac{n}{2}$ but we don't need all of them. Let's calculate for each vertex $i$ ($i < \frac{n}{2}$) (both the old and new values) the segment that crosses $\frac{n}{2}$ and has $y_c$ maximum possible.

Note that this "maximum possible" segment connects $i$ with some vertex $j$ that has to be on the convex hull that was built on the right half (otherwise, we will find convex hull point with higher slope and its $y_c$ will be bigger).

In other words, for each point from the left, we are searching a tangent line to the convex hull on the right. And we can do it efficiently with binary search while checking some cross products. Let's name that tangent line as $t(x, y)$ where $(x, y)$ is a point from the left half.

One more observation: $y_c = \frac{y_0 + y_1}{2}$. You can prove it by looking at the area of trapezoid that formed by segment $(0, y_0) - (n - 1, y_1)$. So, let's define a function $f(l)$ that takes line $l$ and returns $2 y_c$ (or the answer to the task).

We have all we need to calculate the answer: the answer to the $i$-th query is equal to the maximum among $f(t(j, b_j))$ for all $j \le i$ and $f(t(j, a_j))$ for all $i < j < \frac{n}{2}$.

In total, the solution is next: 

1. build convex hull on vertices $[\frac{n}{2}, n - 1]$;
2. calculate $t(i, a_i)$ with binary search for all $i < \frac{n}{2}$;
3. calculate $f(t(i, a_i))$ for all $i < \frac{n}{2}$ and store suffix maximums among these values;
4. calculate $t(i, b_i)$ with binary search for all $i < \frac{n}{2}$;
5. calculate $f(t(i, b_i))$ for all $i < \frac{n}{2}$ and store prefix maximums among these values;
6. calculate the $i$-th answer as maximum between the $i$-th prefix maximum and the $(i+1)$-th suffix maximum.

In order to solve the task for the right half $[\frac{n}{2}, n - 1]$ just reverse arrays $a$ and $b$ and swap them, and do the same algorithm above. It's true, because replacing first $k$ values $a_i$ with $b_i$ in array $a$ is equivalent to replacing last $n - k$ values $b_i$ with $a_i$ in array $b$.

Complexity of the solution is $O(n \log n)$ because of binary searches. Note that we can do everything in integers, except calculating the values of function $f$ and taking maximum among $f$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
 
#define x first
#define y second
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
	fore(i, 0, sz(v)) {
		if(i) out << " ";
		out << v[i];
	}
	return out;
}
 
pt operator+ (const pt &a, const pt &b) {
	return {a.x + b.x, a.y + b.y};
}
pt operator- (const pt &a, const pt &b) {
	return {a.x - b.x, a.y - b.y};
}
li operator *(const pt &a, const pt &b) {
	return a.x * 1ll * b.x + a.y * 1ll * b.y;
}
li operator %(const pt &a, const pt &b) {
	return a.x * 1ll * b.y - a.y * 1ll * b.x;
}
 
const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
 
int n;
vector<pt> old, nw;
 
inline bool read() {
	if(!(cin >> n))
		return false;
	old.resize(n);
	nw.resize(n);
	fore (i, 0, n) {
		old[i].x = i;
		cin >> old[i].y;
	}
	fore (i, 0, n) {
		nw[i].x = i;
		cin >> nw[i].y;
	}
	return true;
}
 
inline ld getTr(const pt &a, const pt &b) {
	pt tmp = b - a;
	pt v = {-tmp.y, tmp.x};
	ld c = v * a;
	ld y0 = (c - v.x * 0) / v.y;
	ld y1 = (c - v.x * li(n - 1)) / v.y;
	return (y0 + y1);
}
 
vector<pt> hull(const vector<pt> &ps, int l, int r) {
	vector<pt> h;
	fore (i, l, r) {
		while (sz(h) > 1 && (h[sz(h) - 1] - h[sz(h) - 2]) % (ps[i] - h[sz(h) - 1]) >= 0)
			h.pop_back();
		h.push_back(ps[i]);
	}
	return h;
}
 
inline void solve() {
	vector<ld> maxTr(n - 1, 0);
	fore (t, 0, 2) {
		auto h = hull(old, n / 2, n);
 
		auto best = [&](const pt &p) {
			int l = -1, r = sz(h) - 1;
			while (r - l > 1) {
				int mid = (l + r) >> 1;
				if ((h[mid] - p) % (h[mid + 1] - h[mid]) >= 0)
					l = mid;
				else
					r = mid;
			}
			return h[r].x;
		};
		
		vector<ld> bs(n / 2 + 1, 0);
		for (int i = n / 2 - 1; i >= 0; i--) {
			int j = best(old[i]);
			bs[i] = getTr(old[i], old[j]);
			bs[i] = max(bs[i], bs[i + 1]);
		}
		
		ld lans = 0;
		fore (i, 0, n / 2) {
			int j = best(nw[i]);
			lans = max(lans, getTr(nw[i], old[j]));
			maxTr[i] = max({maxTr[i], lans, bs[i + 1]});
		}
		
		reverse(all(old));
		reverse(all(nw));
		swap(old, nw);
		fore (i, 0, n)
			old[i].x = nw[i].x = i;
		
		reverse(all(maxTr));
	}
			
	maxTr.push_back(maxTr.back());
	cout << maxTr << endl;
}
 
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(12);
	
	if(read()) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
