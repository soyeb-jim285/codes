# Tutorial

[1469A - Regular Bracket Sequence](../problems/A._Regular_Bracket_Sequence.md "Educational Codeforces Round 101 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1469A - Regular Bracket Sequence](../problems/A._Regular_Bracket_Sequence.md "Educational Codeforces Round 101 (Rated for Div. 2)")

There are two solutions to this problem: casework and greedy.

The greedy solution goes as follows: the number of opening brackets in an RBS should be exactly $\frac{|s|}{2}$, and if there is a closing bracket before an opening bracket, it's optimal to swap them, if possible. So, we should replace the first $\frac{|s|}{2} - 1$ question marks with opening brackets, other question marks with closing brackets, and if the answer exists, this method will find it. All that's left is to check that the resulting sequence is an RBS.

The casework solution goes as follows: first of all, each RBS should have an even length, so if $|s|$ is odd, there is no answer. Furthermore, an RBS always begins with an opening bracket and always ends with a closing bracket, so if the first character is a closing bracket or the last character is an opening bracket, there is no answer. Since there is at most one opening bracket and at most one closing bracket in the original sequence, these three constraints are enough: if the opening bracket is before the closing bracket, then they balance out, and all other characters can be replaced in such a way that they form an RBS of length $|s| - 2$. If the opening bracket is after the closing bracket, then the first and the last characters are question marks (since the first character is not a closing bracket, and the last one is not an opening bracket). We should replace the first character with an opening bracket, the last character with a closing bracket, so we get four characters (two opening and two closing brackets) which balance themselves out. All other question marks can be replaced in such a way that they form an RBS of length $|s| - 4$. So, all we have to check is that $|s|$ is even, the first character is not a closing bracket, and the last character is not an opening bracket.

 **Solution 1 (BledDest)**
```cpp
t = int(input())
for i in range(t):
    s = input()
    if len(s) % 2 == 0 and s[0] != ')' and s[-1] != '(':
        print('YES')
    else:
        print('NO')
```
 **Solution 2 (BledDest)**
```cpp
t = int(input())
for i in range(t):
    s = input()
    n = len(s)
    a = [s[i] for i in range(n)]
    cnt = n // 2 - 1
    for j in range(n):
        if a[j] == '?':
            if cnt > 0:
                cnt -= 1
                a[j] = '('
            else:
                a[j] = ')'
    bal = 0
    minbal = 0
    for j in range(n):
        if a[j] == '(':
            bal += 1
        else:
            bal -= 1
        minbal = min(bal, minbal)
    print('YES' if bal == 0 and minbal >= 0 else 'NO') 
```
[1469B - Red and Blue](../problems/B._Red_and_Blue.md "Educational Codeforces Round 101 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest") and [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1469B - Red and Blue](../problems/B._Red_and_Blue.md "Educational Codeforces Round 101 (Rated for Div. 2)")

Denote $p_i$ as the sum of first $i$ elements of $r$, and $q_j$ as the sum of first $j$ elements of $b$. These values can be calculated in $O(n + m)$ with prefix sums.

The first solution is to use dynamic programming. Let $dp_{i, j}$ be the maximum value of $f(a)$ if we placed the first $i$ elements of $r$ and the first $j$ elements of $b$. Transitions can be performed in $O(1)$: we either place an element from $r$ (then we go to $dp_{i + 1, j}$ and update it with $\max(dp_{i, j}, p_{i + 1} + q_j)$), or place an element from $b$ (then we go to $dp_{i, j + 1}$ and update it with $\max(dp_{i, j}, p_i + q_{j + 1})$). The answer is stored in $dp_{n, m}$, and this solution works in $O(nm)$.

The second solution: observe that the sum of several first elements of $a$ is the sum of several first elements of $r$ and several first elements of $b$. So each prefix sum of $a$ (and the answer itself) is not greater than $\max_{i = 0}^{n} p_i + \max_{j = 0}^{m} p_j$. It's easy to show how to obtain exactly this answer: let $k$ be the value of $i$ such that $p_i$ is maximized, and $l$ be the value of $j$ such that $q_j$ is maximized. Let's place the first $k$ elements of $r$, then the first $l$ elements of $b$ (so the current sum is exactly $\max_{i = 0}^{n} p_i + \max_{j = 0}^{m} p_j$), and place all of the remaining elements in any possible order. So, the answer is $\max_{i = 0}^{n} p_i + \max_{j = 0}^{m} p_j$. This solution works in $O(n + m)$.

 **Solution 1 (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> r(n);
	for (int &x : r) cin >> x;
	int m;
	cin >> m;
	vector<int> b(m);
	for (int &x : b) cin >> x;
	partial_sum(r.begin(), r.end(), r.begin());
	partial_sum(b.begin(), b.end(), b.begin());
	cout << max(0, *max_element(r.begin(), r.end())) + max(0, *max_element(b.begin(), b.end())) << 'n';
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
```
 **Solution 2 (pikmike)**
```cpp
for _ in range(int(input())):
	n = int(input())
	a = [int(x) for x in input().split()]
	m = int(input())
	b = [int(x) for x in input().split()]
	dp = [[-10**9 for j in range(m + 1)] for i in range(n + 1)]
	dp[0][0] = 0
	ans = 0
	for i in range(n + 1):
		for j in range(m + 1):
			if i < n:
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i])
			if j < m:
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + b[j])
			ans = max(ans, dp[i][j])
	print(ans)
```
[1469C - Building a Fence](../problems/C._Building_a_Fence.md "Educational Codeforces Round 101 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1469C - Building a Fence](../problems/C._Building_a_Fence.md "Educational Codeforces Round 101 (Rated for Div. 2)")

Let's set sections from left to right. Note that for the $i$-th section all valid heights $x$ (heights for which it's possible to choose heights for all sections $1 \dots i$ meeting all rules and finishing with the height of $i$ equal to $x$) form a segment.

It's not hard to prove by induction. For the first section, the valid segment is $[h_1, h_1]$. The step of induction: if the valid segment for $i - 1$ is $[l_{i - 1}, r_{i - 1}]$ then valid $x_i$-s for $i$ is the segment $[\max(l_{i - 1} - (k - 1), h_i), \min(r_{i - 1} + (k - 1), h_i + (k - 1))]$, since for each $x_i$ you can find at least one $x_{i - 1}$ in $[l_{i - 1}, r_{i - 1}]$ which don't break the first rule.

If for any $i$ the correct segment is empty or if we can't fulfill the third rule ($h_n \not\in [l_{n - 1} - (k - 1), r_{n - 1} + (k - 1)]$) then there is no answer, otherwise at least one answer is always exist.

As a result, to solve the problem, you should just maintain the segment of valid $x_i$ (using the formula above) while iterating $i$. Complexity is $O(n)$.

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val h = readLine()!!.split(' ').map { it.toInt() }

        var mn = h[0]
        var mx = h[0]
        var ok = true
        for (i in 1 until n) {
            mn = maxOf(mn - k + 1, h[i])
            mx = minOf(mx + k - 1, h[i] + k - 1)
            if (mn > mx) {
                ok = false
                break
            }
        }
        if (h[n - 1] !in mn..mx)
            ok = false
        println(if (ok) "YES" else "NO")
    }
}
```
[1469D - Ceil Divisions](../problems/D._Ceil_Divisions.md "Educational Codeforces Round 101 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1469D - Ceil Divisions](../problems/D._Ceil_Divisions.md "Educational Codeforces Round 101 (Rated for Div. 2)")

There are many different approaches. We will describe a pretty optimal one.

Let's solve the problem recursively. Let's say we need to process segment $[1, x]$. If $x = 2$, we don't need to do anything. Otherwise, $x > 2$. Let's find the minimum $y$ such that $y \ge \left\lceil \frac{x}{y} \right\rceil$.

The chosen $y$ is convenient because it allows making $x$ equal to $1$ in two divisions (and it's the minimum number of divisions to get rid of $x$). Now we can, firstly, make all $z \in [y + 1, x)$ equal to $1$ in one step (by division on $x$) and then make $x$ equal to $1$ with two divisions on $y$.

As a result, we've spent $x - y + 1$ operations and can solve our task recursively for $[1, y]$. In total, we will spend $n - 2 + \mathit{\text{number_of_segments}}$ and since the segments are like $(\sqrt{x}, x]$, $(\sqrt{\sqrt{x}}, \sqrt{x}]$,... There will be at most $\log{(\log{n})}$ segments and $n + 3$ operations are enough for $n \le 2^{32}$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n;

inline bool read() {
	if(!(cin >> n))
		return false;
	return true;
}

void calc(int n, vector<pt> &ans) {
	if (n == 2)
		return;
	
	int y = max(1, (int)sqrt(n) - 1);
	while (y < (n + y - 1) / y)
		y++;
	
	fore (pos, y + 1, n)
		ans.emplace_back(pos, n);
	ans.emplace_back(n, y);
	ans.emplace_back(n, y);
	
	calc(y, ans);
}

inline void solve() {
	vector<pt> ans;
	calc(n, ans);
	
	cout << sz(ans) << endl;
	for(auto p : ans)
		cout << p.first << " " << p.second << 'n';
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc; cin >> tc;
	while(tc--) {
		read();
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
[1469E - A Bit Similar](../problems/E._A_Bit_Similar.md "Educational Codeforces Round 101 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1469E - A Bit Similar](../problems/E._A_Bit_Similar.md "Educational Codeforces Round 101 (Rated for Div. 2)")

Let's denote $z$ as the number of substrings of $s$ having length exactly $k$ (so, $z = n - k + 1$).

The first and crucial observation is that if $2^k > z$, then the answer always exists. Each of $z$ substrings forbids one of the strings from being the answer (a string is forbidden if every each character differs from the corresponding character in one of the substrings); we can forbid at most $z$ strings from being the answer, and the number of possible candidates for the answer is $2^k$. 

This observation leads us to a more strong fact that actually allows us to find a solution: we can set the first $k - \lceil \log_2 (z+1) \rceil$ characters in the answer to 0; all the remaining characters are enough to find the answer.

There are at most $2^{\lceil\log_2(z+1)\rceil}$ possible combinations of the last characters, and this number is not greater than $2n$. Let's iterate on each substring of $s$ of length $k$ and check which combination it forbids by inverting the last $\lceil \log_2 (z+1) \rceil$ characters of the substring. After that, find the minimum unforbidden combination. Note that there may be a case when a substring doesn't actually forbid any combination — if there are zeroes in the first $k - \lceil \log_2 (z+1) \rceil$ characters of the substring, it is a bit similar to the answer no matter which combination we choose. This can be checked by precalculating the closest position of zero to the left/right of each index.

The whole solution works in $O(n \log n)$ per test case — the hardest part is inverting the suffix of each substring we are interested in.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 1000043;                 
int q;
char buf[N];
int n, k;

int ceilLog(int x)
{
    int y = 0;
    while((1 << y) < x)
        y++;
    return y;
}

int main()
{
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        scanf("%d %d", &n, &k);
        scanf("%s", buf);
        string s = buf;
        int m = min(k, ceilLog(n - k + 2));
        vector<int> used(1 << m, 0);
        vector<int> next0(n, int(1e9));
        if(s[n - 1] == '0')
            next0[n - 1] = n - 1;
        for(int j = n - 2; j >= 0; j--)
            if(s[j] == '0')
                next0[j] = j;
            else
                next0[j] = next0[j + 1];
        int d = k - m;
        for(int j = 0; j < n - k + 1; j++)
        {
            if(next0[j] - j < d)
                continue;
            int cur = 0;
            for(int x = j + d; x < j + k; x++)
                cur = cur * 2 + (s[x] - '0');
            used[((1 << m) - 1) ^ cur] = 1;    
        }
        int ans = -1;
        for(int j = 0; j < (1 << m); j++)
            if(used[j] == 0)
            {
                ans = j;
                break;    
            }
        if(ans == -1)
            puts("NO");
        else
        {
            puts("YES");
            string res(d, '0');
            string res2;
            for(int j = 0; j < m; j++)
            {
                res2.push_back('0' + (ans % 2));
                ans /= 2;
            }
            reverse(res2.begin(), res2.end());
            res += res2;
            puts(res.c_str());
        }
    }
}
```
[1469F - Power Sockets](../problems/F._Power_Sockets.md "Educational Codeforces Round 101 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1469F - Power Sockets](../problems/F._Power_Sockets.md "Educational Codeforces Round 101 (Rated for Div. 2)")

At first, let's realize that the tree structure doesn't matter that much. What we actually need is the array $cnt_i$ such that it stores the number of white vertices on depth $i$.

Initially, $cnt_0=1$ and all other are zero. If you take a chain and attach it to some vertex on depth $d$, then the number of vertices on depth $d$ decreases by $1$. Also, the added vertices update some other counts.

So far, it's extremely unclear what to begin with. Let's start by introducing some greedy ideas.

For each $t$ let's find the most optimal tree using exactly $t$ chains and update the answer with each of them.

First, it's always optimal to attach a chain with its middle vertex. Just consider the changes in the white vertices counts.

Second, for each $t$ it's always optimal to take the longest $t$ chains to use. If not the longest $t$ are used, then you can replace any of them and there will be more white vertices.

It would be nice if we were able to just add another chain to the tree for $t-1$ to get the tree for $t$. However, that's not always the case. But we can still attempt it and show that the optimal answer was achieved somewhere in the process.

Let's show that it's always optimal to attach a new chain to the closest white vertex.

So there are basically two cases: there is not enough white vertices yet and there is enough. What happens if there is not enough vertices, and we pick the closest one to attach a chain to? If there are still not enough vertices, then we'll just continue. Otherwise, we'll have to show that the answer can't get any smaller by rearranging something.

Consider what the answer actually is. Build a prefix sum array over $cnt$, then the answer is the shortest prefix such that its prefix sum is greater or equal to $k$.

So we put the $t$-th chain to the closest white vertex at depth $d$. It decreases $cnt_d$ by $1$ and increases $cnt_{d+2}$ and further by $1$ or $2$. Every chain we have put to this point was attached to a vertex at depth less or equal to the answer (otherwise, we could've rearranged it and obtain the answer before). The optimal answer can be neither $d$, nor $d+1$ (also because we could've rearranged). Thus, the answer is at least $d+2$ and every single chain we have put was packed as tightly as possible below that depth.

The second case works similarly. We could've obtained the optimal answer before $t$. So the answer is below $d+2$ and we can do nothing about that. Or the optimal answer is ahead of us, so putting the chain at $d$ can decrease it as much or stronger as any other choice.

Thus, updating the answer on every iteration will give us the optimal result.

Now we are done with the greedy, time to implement it. I chose the most straightforward way. We basically have to maintain a data structure that can add on range, get the value of a cell and find the shortest prefix with sum at least $k$. That can be easily done with segtree.

Overall complexity: $O(n \log n)$.

 **Solution (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int INF = 1e9;

int n, k, nn;

vector<long long> t, ps;

void push(int v, int l, int r){
	if (l < r - 1){
		ps[v * 2] += ps[v];
		ps[v * 2 + 1] += ps[v];
	}
	t[v] += ps[v] * (r - l);
	ps[v] = 0;
}

void upd(int v, int l, int r, int L, int R, int val){
	push(v, l, r);
	if (L >= R)
		return;
	if (l == L && r == R){
		ps[v] = val;
		push(v, l, r);
		return;
	}
	int m = (l + r) / 2;
	upd(v * 2, l, m, L, min(m, R), val);
	upd(v * 2 + 1, m, r, max(m, L), R, val);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

long long get(int v, int l, int r, int L, int R){
	push(v, l, r);
	if (L >= R)
		return 0;
	if (l == L && r == R)
		return t[v];
	int m = (l + r) / 2;
	long long res = get(v * 2, l, m, L, min(m, R)) + get(v * 2 + 1, m, r, max(m, L), R);
	t[v] = t[v * 2] + t[v * 2 + 1];
	return res;
}

int trav(int v, int l, int r, int cnt){
	push(v, l, r);
	if (l == r - 1)
		return l;
	int m = (l + r) / 2;
	push(v * 2, l, m);
	push(v * 2 + 1, m, r);
	int res = INF;
	if (t[v * 2] >= cnt)
		res = trav(v * 2, l, m, cnt);
	else if (t[v * 2 + 1] >= cnt - t[v * 2])
		res = trav(v * 2 + 1, m, r, cnt - t[v * 2]);
	t[v] = t[v * 2] + t[v * 2 + 1];
	return res;
}

int main() {
	scanf("%d%d", &n, &k);
	vector<int> a(n);
	forn(i, n) scanf("%d", &a[i]);
	sort(a.begin(), a.end(), greater<int>());
	nn = a[0] + 500;
	t.resize(4 * nn);
	ps.resize(4 * nn);
	upd(1, 0, nn, 0, 1, 1);
	int fst = 0;
	int ans = INF;
	forn(i, n){
		while (get(1, 0, nn, 0, fst + 1) == 0) ++fst;
		upd(1, 0, nn, fst, fst + 1, -1);
		upd(1, 0, nn, fst + 2, fst + 2 + (a[i] - 1) / 2, 1);
		upd(1, 0, nn, fst + 2, fst + 2 + a[i] / 2, 1);
		ans = min(ans, trav(1, 0, nn, k));
	}
	printf("%dn", ans == INF ? -1 : ans);
	return 0;
}
```
