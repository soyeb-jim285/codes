# Tutorial

[1223A - CME](../problems/A._CME.md "Technocup 2020 - Elimination Round 1")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1223A - CME](../problems/A._CME.md "Technocup 2020 - Elimination Round 1")

If $n$ is odd then we have to buy at least one match because integers $a+b$ and $c$ ($a$, $b$ and $c$ is elements of equation $a+b=c$) must be of the same parity, so integer $a+b+c$ is always even.

If $n$ is even then we can assemble an equation $1 + \frac{n-2}{2} = \frac{n}{2}$. But there is one corner case. If $n = 2$, then we have to buy two matches, because all integers $a$, $b$ and $c$ must be greater than zero.

In this way, the answer is equal: 

1. $2$ if $n = 2$;
2. $1$ if $n$ is odd;
3. $0$ if $n$ is even and greater than $2$.
 **Solution (Roms)**
```cpp
for t in range(int(input())):
	n = int(input())
	print(2 if n == 2 else (n & 1))
```
[1223B - Strings Equalization](../problems/B._Strings_Equalization.md "Technocup 2020 - Elimination Round 1")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1223B - Strings Equalization](../problems/B._Strings_Equalization.md "Technocup 2020 - Elimination Round 1")

If there is a character which is contained in string $s$ and $t$ (let's denote it as $c$), then we answer is "YES" because we can turn these string into string consisting only of this character $c$.

Otherwise the answer is "NO", because if initially strings have not a common character, then after performing operation they also have not a common character. 

 **Solution (Roms)**
```cpp
for t in range(int(input())):
    print('NO' if len(set(input()) & set(input())) == 0 else 'YES')
```
[1223C - Save the Nature](../problems/C._Save_the_Nature.md "Technocup 2020 - Elimination Round 1")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1223C - Save the Nature](../problems/C._Save_the_Nature.md "Technocup 2020 - Elimination Round 1")

At first, let's assume that $x \ge y$ (otherwise, we can swap parameters of programs). Let's define $cont(len)$ as the maximum contribution we can get selling exactly $len$ tickets.

Note, in general case sold ticket can be one of $4$ types:

* tickets with $(x + y)\%$ of the price are contributed; the number of such tickets is $cXY$;
* tickets with $x\%$ of the price are contributed; the number of such tickets is $cX$;
* tickets with $y\%$ of the price are contributed; the number of such tickets is $cY$;
* tickets which are not in both programs.

All values $cXY$, $cX$, $cY$ can be easily counted by iterating over indices $i$ from $1$ to $len$ and checking whenever $i$ is divisible by $a$ or by $b$ or both.

Now we can understand that it's always optimal to choose in the first group $cXY$ maximums from $p$, in the second group next $cX$ maximums and in the third — next $cY$ maximums.

Using the algorithm above we can calculate $cont(len)$ in linear time (just sort $p$ beforehand).

The final step is to understand that function $cont(len)$ is non decreasing, so we can just binary search the minimal $len$ with $cont(len) \ge k$.

The time complexity is $O(n \log{n})$, but $O(n \log^2{n})$ can pass too.

 **Solution (adedalic)**
```cpp
fun calc(p: IntArray, len: Int, x: Int, a: Int, y: Int, b: Int): Long {
    var ans = 0L
    var (cX, cY, cXY) = listOf(0, 0, 0)
    for (i in 1..len) {
        if (i % a == 0 && i % b == 0) cXY++
        else if (i % a == 0) cX++
        else if (i % b == 0) cY++
    }
    for (i in 0 until cXY)
        ans += p[i] * (x + y)
    for (i in 0 until cX)
        ans += p[cXY + i] * x
    for (i in 0 until cY)
        ans += p[cXY + cX + i] * y;
    return ans
}

fun main() {
    val q = readLine()!!.toInt()
    for (ct in 1..q) {
        val n = readLine()!!.toInt()
        val p = readLine()!!.split(' ').map { it.toInt() / 100 }
                .sortedDescending().toIntArray()
        var (x, a) = readLine()!!.split(' ').map { it.toInt() }
        var (y, b) = readLine()!!.split(' ').map { it.toInt() }
        val k = readLine()!!.toLong()

        if (x < y) {
            x = y.also { y = x }
            a = b.also { b = a }
        }

        var lf = 0; var rg = n + 1
        while (rg - lf > 1) {
            val mid = (lf + rg) / 2
            if (calc(p, mid, x, a, y, b) >= k)
                rg = mid
            else
                lf = mid
        }

        if (rg > n) rg = -1
        println(rg)
    }
}
```
[1223D - Sequence Sorting](../problems/D._Sequence_Sorting.md "Technocup 2020 - Elimination Round 1")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1223D - Sequence Sorting](../problems/D._Sequence_Sorting.md "Technocup 2020 - Elimination Round 1")

Let's consider two sequences of integers $m_1 < m_2 < \dots < m_k$ and $d_1 < d_2 < \dots < d_l$. Sequence $m$ contains integers which were used in some operation in the optimal answer. Sequence $d$ contains integers which were not used.

For example, if $a = [2, 1, 3, 5, 4]$, then optimal answer is move all $1$-elements to the beginning and then move all $5$-elements to the end, so $m = [1, 5]$ and $d = [2, 3, 4]$. 

Two important conditions are held for these sequences: 

1. $maxInd(d_{i-1}) < minInd(d_i)$ for every $i$ from $2$ to $l$. $minInd(x)$ is the minimum index $i$ such that $a_i = x$, and $maxInd(x)$ is the maximum index $i$ such that $a_i = x$;
2. for each $i$ from $2$ to $l$ there is no such integer $x$, that $d_i < x < d_{i + 1}$ and sequence $m$ contains this integer $x$.

Since the answer is equal to $|m| = k$, we want to minimize this value. So we want to maximize the length of sequence $d$. 

For each integer $l$ we want to find the maximum integer $dp_l = len$ such that we can sort sequence $a$ without moving elements in range $l \dots l + len - 1$. We can do it with dynamic programming. 

Let's consider all integers occurring in sequence $a$ in descending order $s_1, s_2, \dots, s_t$ ($s_{i - 1} > s_{i}$ for each $i$ from $2$ to $t$). If $maxInd(s_i) < minInd(s_{i+1})$ then $dp_i = dp_{i + 1} + 1$, otherwise $dp_i = 1$.

The answer is equal to $t - \max\limits_{i=1 \dots t} dp_i$, there $t$ is the number of distinct integers in sequence $a$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;
const int INF = int(1e9) + 99;

int t, n;
int a[N];
int l[N], r[N];
int dp[N];

int main() {
	scanf("%d", &t);
	for(int tc = 0; tc < t; ++tc){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			l[i] = INF;
			r[i] = -INF;
			dp[i] = 0;
		}

		vector <int> v;	
		for(int i = 0; i < n; ++i){
			scanf("%d", a + i);
			--a[i];
			v.push_back(a[i]);
			l[a[i]] = min(l[a[i]], i);
			r[a[i]] = max(r[a[i]], i);
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	
		int res = n;
		for(int i = v.size() - 1; i >= 0; --i){
			if(i + 1 == v.size() || r[v[i]] >= l[v[i + 1]]) dp[i] = 1;
			else dp[i] = 1 + dp[i + 1];
			res = min(res, int(v.size())- dp[i]);
		}

		printf("%dn", res);
	}	

	return 0;
}                             	
```
[1223E - Paint the Tree](../problems/E._Paint_the_Tree.md "Technocup 2020 - Elimination Round 1")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1223E - Paint the Tree](../problems/E._Paint_the_Tree.md "Technocup 2020 - Elimination Round 1")

It is obvious that if we paint two vertices in the same color, they should be adjacent to each other — otherwise we could paint them in different colors, and the answer would not be worse. So we can reduce the problem to the following: choose a set of edges with maximum cost such that no vertex is adjacent to more than $k$ chosen edges. This problem is very similar to maximum weighted matching on the tree, and we can try to use some methods that allow us to solve that problem.

Let's solve the problem using dynamic programming $dp_{v, f}$ — the answer to the problem for the subtree of the vertex $v$, $f$ is the flag that denotes whether the edge from $v$ to its parent is chosen. Depending on the flag $f$, we can choose $k$ or $k - 1$ edges connecting our vertex to its children (let's denote the maximum number of edges we can choose as $t$).

We have to select no more than $t$ child nodes of the vertex $v$. If we choose an edge leading to node $u$, then $dp_{u, 1} + w_ {v, u}$ is added to the $dp$ value we are currently calculating; otherwise, $dp_{u, 0}$ is added. 

Based on this formula, you have to choose no more than $t$ child nodes of vertex $v$ for which the total sum of $dp_{u, 1} + w_{v, u} - dp_{u, 0}$ is maximum.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int N = 500 * 1000 + 13;

int n, k;
vector<pair<int, int>> g[N];
long long dp[N][2];

void calc(int v, int p = -1) {
	long long cur = 0;
	vector<long long> adds;
	
	for (auto it : g[v]) {
		int to = it.x;
		int w = it.y;
		if (to == p)
			continue;
		calc(to, v);
		
		cur += dp[to][0];
		adds.pb(dp[to][1] + w - dp[to][0]);
	}
	
	sort(all(adds), greater<long long>());
	forn(i, min(sz(adds), k)) if (adds[i] > 0)
		cur += adds[i];
	
	dp[v][0] = dp[v][1] = cur;
	if (k <= sz(adds) && adds[k - 1] > 0)
		dp[v][1] -= adds[k - 1];
}

long long solve() {
    scanf("%d%d", &n, &k);
    forn(i, n) g[i].clear();
	forn(i, n - 1) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		--x; --y;
		g[x].pb(mp(y, w));
		g[y].pb(mp(x, w));
	}
	
	calc(0);
	
	return dp[0][0];
}

int main() {
	int q;
	scanf("%d", &q);
	forn(i, q) printf("%lldn", solve());
}
```
[1223F - Stack Exterminable Arrays](../problems/F._Stack_Exterminable_Arrays.md "Technocup 2020 - Elimination Round 1")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1223F - Stack Exterminable Arrays](../problems/F._Stack_Exterminable_Arrays.md "Technocup 2020 - Elimination Round 1")

Let's understand how calculate the array $nxt$, such that $nxt_l$ is equal to the minimum index $r > l$ such that subarray $a_{l \dots r}$ is stack exterminable. If there is no such index, then $nxt_l = -1$.

If we calculate this array then we solve this task by simple dynamic programming.

Let's calculate it in order $nxt_n, nxt_{n-1}, \dots , nxt_1$ by dynamic programming. At first consider simple case. If $a_i = a_{i + 1}$, then $nxt_i = i + 1$. Otherwise we have to "add" the block $a_{i+1} \dots a_{nxt_{i+1}}$ (of course, $nxt_{i + 1}$ should be not equal to $-1$) and check that $a_i = a_{1 + nxt_{i + 1}}$. If this ($a_i = a_{1 + nxt_{i + 1}}$) also is not true, then you have to add a new block $a_{1 + nxt_{i+1}} \dots a_{nxt_{1 + nxt_{i+1}}}$ and check the condition $a_i = a_{1 + nxt_{1 + nxt_{i+1}}}$. If this condition also is not try, then you have to add a new block and so on. 

It is correct solution, but it can be too slowly. Let's understand, that we add blocks to $a_i$ until condition $a_i = a_{1 + nxt_{\dots}}$ is holds. Let's assume, that we have an array $nxtX$ (this array contains a hashMaps, for example you can use map in C++), such that $nxtX_{i, x}$ is is equal to the minimum index $r > l$ such that subarray $a_{l \dots r}$ is stack exterminable and $x = a_{r + 1}$. Then we can easily calculate the value $nxt_i = nxtX_{i+1, a_i} + 1$. Remains to understand, how to calculate $nxtX_{i}$. For this we just can make an assignment $nxtX_{i} = nxtX_{nxt_i + 1}$. And then update $nxtX_{i, a_{nxt_i + 1}} = nxt_{i} + 1$. 

But I deceived you a little. We can't make an assignment $nxtX_{i} = nxtX_{nxt_i + 1}$ because it is to slow. Instead that you need to swap elements $nxtX_{i}$ and $nxtX_{nxt_i + 1}$, this can be done using the function $swap$ in C++ or Java (time complexity of $swap$ if $O(1)$).

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

int t, n;
int a[N];
int nxt[N];
int dp[N];
map<int, int> nxtX[N];


int main() {	
	scanf("%d", &t);
	for(int tc = 0; tc < t; ++tc){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", a + i);
		for(int i = 0; i < n + 2; ++i){
			nxt[i] = -1;
			nxtX[i].clear();
			dp[i] = 0;
		}

		for(int i = n - 1; i >= 0; --i){
			if(nxtX[i + 1].count(a[i])){
				int pos = nxtX[i + 1][a[i]];
				assert(pos < n && a[pos] == a[i]);
				nxt[i] = pos;
				swap(nxtX[i], nxtX[pos + 1]);
				if(pos < n - 1)
					nxtX[i][a[pos + 1]] = pos + 1;
			}
			nxtX[i][a[i]] = i;
		}	

		long long res = 0;
		for(int i = n - 1; i >= 0; --i){
			if(nxt[i] == -1) continue;	
			dp[i] = 1 + dp[nxt[i] + 1];
			res += dp[i];
		}

		printf("%lldn", res);
	}
	return 0;
} 
```
[1223G - Wooden Raft](../problems/G._Wooden_Raft.md "Technocup 2020 - Elimination Round 1")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1223G - Wooden Raft](../problems/G._Wooden_Raft.md "Technocup 2020 - Elimination Round 1")

Let's iterate $y$ from $2$ to $A$, where $A = \max(a_i)$. And let's try to find the best answer for a fixed $y$ in $O(\frac{A}{y})$ time.

How to do so? At first, we can quite easily calculate the total number of logs of length $y$ we can acquire (denote it as $cntY$): since all $a_i \in [ky, ky + y)$ give the same number of logs which is equal to $k$, then let's just count the number of $a_i$ in $[ky, ky + y)$ for each $k$. We can do so using frequency array and prefix sums on it.

There are two cases in the problem: both logs of length $x$ lies in the same log $a_i$ or from the different logs $a_i$ and $a_j$. In the first case it's the same as finding one log of length $2x$. But in both cases we will divide all possible values of $x$ ($2x$) in segments $[ky, ky + y)$ and check each segment in $O(1)$ time.

Let's suppose that $2x \in [ky, ky + y)$ and there is $a_i$ such that $a_i \ge 2x$ and $(a_i \mod y) \ge (2x \mod y)$. In that case it's optimal to cut $2x$ from $a_i$ and, moreover, it's optimal to increase $2x$ while we can. It leads us straight to the solution, let's keep $\max(a_i \mod y)$ over $a_i \ge ky$ and check only $2x = ky + \max(a_i \mod y)$ (maybe minus one in case of wrong parity). We can maintain this max iterating $k$ in descending order. And since $\max(a_i \mod y)$ for all $a_i \in [ky, ky + y)$ is just a $\max(a_i~|~a_i < ky + y)$. We can find such $a_i$ in $O(1)$ using precalc. To check the chosen $2x$ is trivial: the number of remaining logs $y$ is equal to $cntY - k$ and the plot will have the area $y \cdot \min(x, cntY - k)$.

The case with cutting $x$-s from different $a_i$ and $a_j$ is based on the same idea, but we need to maintain two maximums $mx1$ and $mx2$ ($mx1 \ge mx2$). But in this case $x$ can be equal to both $mx1$ or $mx2$.

If $x = ky + mx2$ then everything is trivial: the number of logs $y$ is $cntY - 2 \cdot k$ and so on. If $x = ky + mx1$ then we need to additional check the existence of $a_i \ge x$ and $a_j \ge x$. Remaining number of logs $y$ will be equal to $cntY - 2 \cdot k - 1$ and so on.

In result, for each $y$ we can calculate the answer in $O(\frac{A}{y})$, so the total time complexity is $O(n + \sum_{y = 2}^{A}{O(\frac{A}{y})}) = O(n + A \log A)$.

P.S.: We decided to allow the $O(A \log^2 A)$ solution which binary search $x$ for each $y$ to pass if it's carefully written.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);

int n;
vector<int> a;

inline bool read() {
    if(!(cin >> n))
        return false;
    a.resize(n);
    fore(i, 0, n)
        cin >> a[i];
    return true;
}

template<class A>
pair<A, A> upd(const pair<A, A> &mx, const A &val) {
    return {max(mx.x, val), max(mx.y, min(mx.x, val))};
}

vector<int> cnt, sum;
vector<int> prv;

li getSum(int l, int r) {
    return sum[r] - sum[l];
}

li ans, rx, ry;
void updAns(li x, li y) {
    if (x < 2 || y < 2)
        return;
    if (ans >= x * y)
        return;
    ans = x * y;
    rx = x, ry = y;
}

inline void solve() {
    cnt.assign(*max_element(all(a)) + 1, 0);
    fore(i, 0, n)
        cnt[a[i]]++;
    sum.assign(sz(cnt) + 1, 0);
    fore(i, 0, sz(cnt))
        sum[i + 1] = sum[i] + cnt[i];
    prv.assign(sz(cnt), -1);
    fore(i, 0, sz(prv)) {
        if(i > 0)
            prv[i] = prv[i - 1];
        if(cnt[i] > 0)
            prv[i] = i;
    }

    ans = 0;
    fore(y, 2, sz(cnt)) {
        li cntY = 0;
        for(int i = 0; y * i < sz(cnt); i++)
            cntY += i * 1ll * getSum(i * y, min((i + 1) * y, sz(cnt)));

        pair<pt, pt> mx = {{-1, -1}, {-1, -1}};
        int lf = (sz(cnt) - 1) / y * y, rg = sz(cnt);
        while(lf >= 0) {
            int cntMore = (mx.x.x >= 0) + (mx.y.x >= 0);
            int val1 = prv[rg - 1];
            if (val1 >= lf) {
                mx = upd(mx, pt{val1 % y, val1});
                if (cnt[val1] == 1)
                    val1 = prv[val1 - 1];
                if (val1 >= lf)
                    mx = upd(mx, pt{val1 % y, val1});
            }

            if (mx.x.x >= 0) {
                li x = (lf + mx.x.x) / 2;
                li cur = cntY - lf / y;
                updAns(min(cur, x), y);
            }
            if (mx.y.x >= 0) {
                li x = lf + mx.y.x;
                li cur = cntY - 2 * (lf / y);
                updAns(min(cur, x), y);

                if(cntMore + (mx.x.y < rg) >= 2) {
                    x = lf + mx.x.x;
                    cur--;
                    updAns(min(cur, x), y);
                }
            }

            rg = lf;
            lf -= y;
        }
    }
    cout << ans << endl;
    cerr << rx << " " << ry << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cerr << fixed << setprecision(15);

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
[1240F - Football](https://codeforces.com/contest/1240/problem/F "Codeforces Round 591 (Div. 1, based on Technocup 2020 Elimination Round 1)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1240F - Football](https://codeforces.com/contest/1240/problem/F "Codeforces Round 591 (Div. 1, based on Technocup 2020 Elimination Round 1)")

Let's assume that $m \leq n \cdot k$.

We can randomly assign colors to edges. If there is a vertex that does not satisfy the condition, then we can choose color $a$ which appears the smallest number of times and color $b$ which appears the biggest number of times. We will "recolor" edges that have one of these two colors. 

Let's consider this graph only with edges with colors $a$ and $b$. Let's add a "fake" vertex $0$. This graph may have many components. If a component has at least one vertex with odd degree, we connect each such vertex with $0$. Otherwise, let's choose any vertex from that component and add two edges to $0$. Therefore, the graph will be connected and each vertex will have an even degree. Thus, we will be able to find an Euler cycle. Let's color the odd edges in the cycle in $a$, and even edges in $b$. As a result, the difference between these two colors for each vertex will be at most $1$.

Let's do this operation while there is a vertex which does not satisfy the condition.

If $m > n \cdot k$, let's split the edges into two groups with the equal sizes (that is, $\lfloor \frac{m}{2} \rfloor$ and $\lceil \frac{m}{2} \rceil$). If a group has not greater than $n \cdot k$ edges, then do the algorithm at the beginning of the tutorial. Otherwise, split it again.

If you found the answers for two groups, you need to find the answer for the combined graph. Let $f_1$ be the most popular color in the first group, $f_2$ the second most popular color, ..., $f_k$ the least popular color in the first group. Similarly, let $g_1$ be the most popular color in the second graph, etc. So, in the combined graph, $f_1$ should be equal to $g_k$, $f_2$ should be equal to $g_{k-1}$. In other words, we take the most popular color in the first group and color the least popular color in the second group with that color. If there is a vertex that does not satisfy the condition, "recolor" the graph according to the algorithm explained in the third paragraph.

 **Solution (arsijo)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 101;
const int MAX_M = 1001;

int n, m, k;

vector<pair<int, int> > v[MAX_N];
int w[MAX_N];
int a[MAX_M], b[MAX_M], c[MAX_M], color[MAX_M];

set<pair<int, int> > s[MAX_N], s2;
int deg[MAX_N][MAX_M];
inline pair<int, int> get_s2(int i){
    return {s[i].begin()->first - s[i].rbegin()->first, i};
}
inline void change_edge_color(int edge, int d){
    int pos1 = a[edge];
    int pos2 = b[edge];
    assert(s[pos1].find({deg[pos1][color[edge]], color[edge]}) != s[pos1].end());
    s[pos1].erase({deg[pos1][color[edge]], color[edge]});
    s[pos2].erase({deg[pos2][color[edge]], color[edge]});
    deg[pos1][color[edge]] += d;
    deg[pos2][color[edge]] += d;
    s[pos1].insert({deg[pos1][color[edge]], color[edge]});
    s[pos2].insert({deg[pos2][color[edge]], color[edge]});
}
inline void change_color(int edge, int col){
    if (edge == 0 || edge > m || color[edge] == col)
        return;
    int pos1 = a[edge];
    int pos2 = b[edge];
    s2.erase(get_s2(pos1));
    s2.erase(get_s2(pos2));
    change_edge_color(edge, -1);
    color[edge] = col;
    change_edge_color(edge, 1);
    s2.insert(get_s2(pos1));
    s2.insert(get_s2(pos2));
}

vector<pair<int, int> > v2[MAX_N];
int deg2[MAX_N];
vector<int> vertices;
int used[MAX_N];
void dfs2(int pos){
    used[pos] = 2;
    for (auto e : v2[pos]){
        if (used[e.first] != 2){
            dfs2(e.first);
        }
    }
    vertices.push_back(pos);
}
int _col[2];
set<int> used3;
int i;
vector<int> euler;
void dfs3(int pos, int prev = -1, int pr2 = 0){
    while(!v2[pos].empty()){
        int ind = v2[pos].back().second;
        int to = v2[pos].back().first;
        v2[pos].pop_back();
        if (used3.find(ind) != used3.end()){
            continue;
        }
        used3.insert(ind);
        dfs3(to, ind, pos);
    }
    if (prev != -1){
        euler.push_back(prev);
    }
}

void stabilize_two_colors(const vector<int> &e, int col1, int col2){
    assert(!e.empty());
    v2[0].clear();
    for (auto edge : e){
        v2[a[edge]].clear();
        v2[b[edge]].clear();
        deg2[a[edge]] = 0;
        deg2[b[edge]] = 0;
        used[a[edge]] = 0;
        used[b[edge]] = 0;
    }
    for (auto edge : e){
        v2[a[edge]].push_back({b[edge], edge});
        v2[b[edge]].push_back({a[edge], edge});
    }
    vertices.clear();
    int u = m;
    for (auto edge : e){
        if (used[a[edge]] != 2){
            int k = (int) vertices.size();
            dfs2(a[edge]);
            bool find = false;
            for (int i = k; i < (int) vertices.size(); i++){
                int v = vertices[i];
                if (v2[v].size() % 2 == 1){
                    find = true;
                    ++u;
                    v2[v].push_back({0, u});
                    v2[0].push_back({v, u});
                }
            }
            if (!find){
                int v = vertices[k];
                for (int j = 0; j < 2; j++){
                    ++u;
                    v2[v].push_back({0, u});
                    v2[0].push_back({v, u});
                }
            }
        }
    }
    used3.clear();
    euler.clear();
    dfs3(0);
    for (int a : euler){
        change_color(a, col1);
        swap(col1, col2);
    }
}

void stabilize(const vector<int> &e){
    s2.clear();
    for (int i = 1; i <= n; i++){
        s[i].clear();
        for (int j = 1; j <= k; j++){
            deg[i][j] = 0;
        }
    }
    for (int edge : e){
        deg[a[edge]][color[edge]]++;
        deg[b[edge]][color[edge]]++;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            s[i].insert({deg[i][j], j});
        }
        s2.insert(get_s2(i));
    }
    while(-s2.begin()->first > 2){

        int ind = s2.begin()->second;
        int col1 = s[ind].begin()->second;
        int col2 = s[ind].rbegin()->second;
        vector<int> e2;
        for (int edge : e){
            if (color[edge] == col1 || color[edge] == col2){
                e2.push_back(edge);
            }
        }
        stabilize_two_colors(e2, col1, col2);
    }
}

void make_random(vector<int> e){
    random_shuffle(e.begin(), e.end());
    for (int i = 0; i < (int) e.size(); i++){
        color[e[i]] = i % k + 1;
    }
    stabilize(e);
}

int change[MAX_N];

void build(vector<int> e){
    if ((int) e.size() <= n * k){
        make_random(e);
        return;
    }
    random_shuffle(e.begin(), e.end());
    vector<int> e1, e2;
    int s = (int) e.size() / 2;
    for (int i = 0; i < (int) e.size(); i++){
        if (i < s){
            e1.push_back(e[i]);
        }else{
            e2.push_back(e[i]);
        }
    }
    build(e1);
    build(e2);
    vector<pair<int, int> > v1(k), v2(k);
    for (int i = 1; i <= k; i++){
        v1[i - 1].first = v2[i - 1].first = 0;
        v1[i - 1].second = v2[i - 1].second = i;
    }
    for (int edge : e1){
        v1[color[edge] - 1].first++;
    }
    for (int edge : e2){
        v2[color[edge] - 1].first++;
    }
    sort(v1.rbegin(), v1.rend());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < k; i++){
        change[v1[i].second] = i + 1;
    }
    for (int edge : e1){
        color[edge] = change[color[edge]];
    }
    for (int i = 0; i < k; i++){
        change[v2[i].second] = i + 1;
    }
    for (int edge : e2){
        color[edge] = change[color[edge]];
    }
    stabilize(e);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));
#ifdef LOCAL
    freopen("/Users/antontsypko/tsypko/input.txt", "r", stdin);
#endif
    
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }
    
    ll sum = 0;
    vector<int> e;
    for (int i = 1; i <= m; i++){
        cin >> a[i] >> b[i];
        sum += w[a[i]] + w[b[i]];
        e.push_back(i);
    }
    
    build(e);
    
    for (int i = 1; i <= m; i++){
        assert(color[i]);
        cout << color[i] << endl;
    }
    
}
```
