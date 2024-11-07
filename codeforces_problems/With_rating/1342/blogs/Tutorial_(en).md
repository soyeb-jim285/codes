# Tutorial_(en)

[1342A - Road To Zero](../problems/A._Road_To_Zero.md "Educational Codeforces Round 86 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest") and [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1342A - Road To Zero](../problems/A._Road_To_Zero.md "Educational Codeforces Round 86 (Rated for Div. 2)")

Let's presume that $x \ge y$. Then there are two cases in the problem: 

1. If $a + a \le b$ then we have to $x + y$ times perform the first operation. So the answer is $(x + y) \cdot a$;
2. If $a + a > b$ then we have to $y$ times perform the second operation and pass the remaining distance by performing the first operation. So the answer is $y \cdot b + (x - y) \cdot a$.
 **Solution (Roms)**
```cpp
for _ in range(int(input())):
    x, y = map(int, input().split())
    a, b = map(int, input().split())
    b = min(b, a + a)
    if x < y:
        x, y= y, x
    print(y * b + (x - y) * a)
```
[1342B - Binary Period](../problems/B._Binary_Period.md "Educational Codeforces Round 86 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1342B - Binary Period](../problems/B._Binary_Period.md "Educational Codeforces Round 86 (Rated for Div. 2)")

Let's see how strings with periods $k = 1$ and $k = 2$ look. There are two types of strings with a period equal to $1$: 0000... and 1111.... And there are two types of strings with a period equal to $2$: 01010... and 10101....

It's easy to see if $t$ consists only of 0's (1's) then the string itself is an answer since it has period equal to $1$. Otherwise, it's also quite obvious that any string $t$ is a subsequence of 0101...01 (1010...10) of $2|t|$ length.

 **Solution (adedalic)**
```cpp
fun main() {
    val T = readLine()!!.toInt()
    for (tc in 1..T) {
        val t = readLine()!!

        val s = t.toCharArray().distinct().joinToString("").repeat(t.length)
        println(s)
    }
}
```
[1342C - Yet Another Counting Problem](../problems/C._Yet_Another_Counting_Problem.md "Educational Codeforces Round 86 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest") and [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1342C - Yet Another Counting Problem](../problems/C._Yet_Another_Counting_Problem.md "Educational Codeforces Round 86 (Rated for Div. 2)")

It's quite easy to see that $((ab + x) \bmod a) \bmod b = (x \bmod a) \bmod b$. What does it mean? The property given in the statement holds for $x$ if and only if it holds for $x \bmod ab$. It allows us to answer each testcase in $O(ab + q)$ as follows: for each number from $0$ to $ab - 1$, we may check the given property before processing the queries, and build an array of prefix sums on it to efficiently count the number of integers satisfying the property from the segment $[0, y]$, where $y < ab$. Then each query $[l, r]$ can be divided into two prefix-queries $[0, l - 1]$ and $[0, r]$. To answer a prefix query $[0, p]$ in $O(1)$, we can calculate the number of "full segments" of length $ab$ inside this prefix (that is $\lfloor \frac{p}{ab} \rfloor$) and the length of the last segment of numbers that don't belong into a full segment (that is $p \bmod ab$). To handle full segments, we multiply the number of integers satisfying the property on one segment by the number of such segments, and to handle the last part of segment, we use prefix sums.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 40043;

int len;
int p[N];

void build(int a, int b)
{
	len = a * b;
	p[0] = 0;
	for(int i = 1; i <= len; i++)
	{
		p[i] = p[i - 1];
		if((i % a) % b != (i % b) % a)
			p[i]++;
	}
}

long long query(long long l)
{
	long long cnt = l / len;
	int rem = l % len;
	return p[len] * 1ll * cnt + p[rem]; 
}

long long query(long long l, long long r)
{
	return query(r) - query(l - 1);
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int a, b, q;
		cin >> a >> b >> q;
		build(a, b);
		long long l, r;
		for(int j = 0; j < q; j++)
		{
			cin >> l >> r;
			cout << query(l, r) << " ";
		}
		cout << endl;
	}
}
```
[1342D - Multiple Testcases](../problems/D._Multiple_Testcases.md "Educational Codeforces Round 86 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1342D - Multiple Testcases](../problems/D._Multiple_Testcases.md "Educational Codeforces Round 86 (Rated for Div. 2)")

Let's estimate the smallest possible achievable answer. Let the number of the arrays of size greater than or equal to $i$ be $g_i$. The answer is maximum $\lceil \frac{g_i}{c_i} \rceil$ over all $i$ from $1$ to $k$. You can prove that you can't fit $g_i$ arrays in less than $\lceil \frac{g_i}{c_i} \rceil$ testcases with the pigeonhole principle. Let that be called $ans$.

Ok, let's now construct the solution for that estimate. Sort arrays in the increasing or decreasing order and assign the $i$-th array ($0$-indexed) in that order to the $i~mod~ans$ testcase. It's easy to see that for any $i$ the number of arrays of size greater than or equal to $i$ is always restricted by $\lceil \frac{g_i}{c_i} \rceil$.

Overall complexity: $O(n \log n + k)$ or $O(n + k)$ if you care enough to do counting sort.

 **Solution (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;


int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(n);
	forn(i, n) scanf("%d", &a[i]);
	vector<int> c(k + 1);
	forn(i, k) scanf("%d", &c[i + 1]);
	
	sort(a.begin(), a.end(), greater<int>());
	int ans = 0;
	for (int i = k, g = 0; i >= 1; --i){
		while (g < n && a[g] == i) ++g;
		ans = max(ans, (g + c[i] - 1) / c[i]);
	}
	vector<vector<int>> res(ans);
	forn(i, n) res[i % ans].push_back(a[i]);
	
	printf("%dn", ans);
	forn(i, ans){
		printf("%d", int(res[i].size()));
		for (auto it : res[i])
			printf(" %d", it);
		puts("");
	}
	return 0;
}
```
[1342E - Placing Rooks](../problems/E._Placing_Rooks.md "Educational Codeforces Round 86 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1342E - Placing Rooks](../problems/E._Placing_Rooks.md "Educational Codeforces Round 86 (Rated for Div. 2)")

If we want to place $n$ rooks on an $n \times n$ chessboard so all empty cells are under attack, then either each row or each column should contain at least one rook. Let's suppose that each row contains at least one rook, and multiply the answer by $2$ in the end.

How to ensure that there are exactly $k$ pairs of rooks attacking each other? Since each row contains exactly one rook, only the rooks in the same column attack each other — moreover, if there are $x$ rooks in a non-empty column, they create $(x - 1)$ pairs. So our goal is to distribute $n$ rooks to $n - k$ columns so that each column contains at least one rook.

How to calculate the number of ways to distribute the rooks into $c$ columns? One of the options is to choose the columns we use (the number of ways to do this is ${n}\choose{c}$), and then use inclusion-exclusion to ensure that we are counting only the ways where each column contains at least one rook. The formula we will get is something like $\sum \limits_{i = 0}^{c} (-1)^i {{c}\choose{i}} (c-i)^n$: we want to fix the number of columns that will not contain rooks (that is $i$), which are these columns (that is ${c}\choose{i}$), and how many are there ways to distribute the rooks among remaining columns (that is $(c-i)^n$).

Are we done? Almost. We wanted to multiply the answer by $2$ to count the ways where each column contains at least one rook, but we should not do it if $k = 0$, because in this case each placement of the rooks has exactly one rook in each row and exactly one rook in each column.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 200043;

int add(int x, int y)
{
	return (x + y) % MOD;
}

int sub(int x, int y)
{
	return add(x, MOD - y);
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

int fact[N];

int C(int n, int k)
{
	return mul(fact[n], inv(mul(fact[k], fact[n - k])));
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	if(k > n - 1)
	{
		cout << 0 << endl;
		return 0;
	}
	
	fact[0] = 1;
	for(int i = 1; i <= n; i++)
		fact[i] = mul(i, fact[i - 1]);
	int ans = 0;
	int c = n - k;
	for(int i = c; i >= 0; i--)
		if(i % 2 == c % 2)
			ans = add(ans, mul(binpow(i, n), C(c, i)));
		else
			ans = sub(ans, mul(binpow(i, n), C(c, i)));
	ans = mul(ans, C(n, c));
	if(k > 0)
		ans = mul(ans, 2);
	cout << ans << endl;
}
```
[1342F - Make It Ascending](../problems/F._Make_It_Ascending.md "Educational Codeforces Round 86 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1342F - Make It Ascending](../problems/F._Make_It_Ascending.md "Educational Codeforces Round 86 (Rated for Div. 2)")

Suppose we don't have any constraints on the order of elements, the resulting array just should not contain any duplicates. Let's build the result one element after another in ascending order, so each element we create is strictly greater than the previous. To create an element, just use some subset of elements and merge them into new element. This process can be efficiently modeled with the following dynamic programming: $dp_{cnt, mask}$ is the minimum value of the last element, if we merged all the elements from $mask$ into $cnt$ ascending numbers. To model transitions, we simply iterate on the mask of elements that will be merged into a new one, and check if its sum is greater than the last element we created. This runs in $O(n3^n)$, if we use an efficient way to iterate on all masks that don't intersect with the given mask.

Okay, how about maintaining the order? When we create an element by merging some elements of the original array, let's choose some position of an element we use in merging and state that all other elements are added to it. Then, to ensure that the result is ascending, the position of this element should be greater than the position of the element we chose while building the previous number. We can add the position we have chosen for the last element to the states of our dynamic programming, so it becomes $dp_{cnt, mask, pos}$ — the minimum value of the last element, if we merged the $mask$ of elements into $cnt$ numbers, and the last element originally had index $pos$ in the array.

Using some greedy optimizations (for example, we should not iterate on the position we are choosing to merge — it can be chosen greedily as the leftmost position after the position of previous element we are taking into consideration), we can make it $O(n^2 3^n)$, yet with a small constant factor. To restore the answer, we can maintain the previous values of $mask$ and $pos$ in each state, since $cnt$ just increases by $1$ with each transition.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)

typedef pair<int, int> pt;

const int INF = 1e9;
const int N = 15;

int n;
int a[N];
int sum[1 << N];
int dp[N + 1][1 << N][N + 1];
pt p[N + 1][1 << N][N + 1];

void solve() {
	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i]);
	
	forn(mask, 1 << n) {
		sum[mask] = 0;
		forn(i, n) if (mask & (1 << i))
			sum[mask] += a[i];
	}	
	
	forn(cnt, n + 1) forn(mask, 1 << n) forn(pos, n + 1)
		dp[cnt][mask][pos] = INF;
	
	dp[0][0][0] = 0;
	forn(cnt, n) forn(mask, 1 << n) forn(pos, n) if (dp[cnt][mask][pos] < INF) {
		int rmask = mask ^ ((1 << n) - 1);
		for (int nmask = rmask; nmask; nmask = (nmask - 1) & rmask) {
			if (sum[nmask] <= dp[cnt][mask][pos])
				continue;
			if ((nmask >> pos) == 0)
				continue;
			int npos = pos + __builtin_ctz(nmask >> pos) + 1;
			if (dp[cnt + 1][mask | nmask][npos] > sum[nmask]) {
				dp[cnt + 1][mask | nmask][npos] = sum[nmask];
				p[cnt + 1][mask | nmask][npos] = mp(mask, pos);
			}
		}
	}
	
	int acnt = 0, apos = 0;
	forn(cnt, n + 1) forn(pos, n + 1) if (dp[cnt][(1 << n) - 1][pos] < INF)
		acnt = cnt, apos = pos;
		
	vector<pt> ans;
	
	int mask = (1 << n) - 1, pos = apos;
	for (int cnt = acnt; cnt > 0; --cnt) {
		int nmask = p[cnt][mask][pos].x;
		int npos = p[cnt][mask][pos].y;
		forn(i, n) if ((nmask ^ mask) & (1 << i))
			if (i != pos - 1) ans.pb(mp(i, pos - 1));
		mask = nmask, pos = npos;
	}
	
	
	printf("%dn", sz(ans));
	forn(i, sz(ans)) {
		int from = ans[i].x;
		forn(j, i) from -= ans[j].x < ans[i].x;
		int to = ans[i].y;
		forn(j, i) to -= ans[j].x < ans[i].y;
		printf("%d %dn", from + 1, to + 1);
	}
}	

int main() {
	int tc;
	scanf("%d", &tc);
	forn(i, tc) solve();
		
}
```
