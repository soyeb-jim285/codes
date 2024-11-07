# Tutorial

[1257A - Two Rival Students](../problems/A._Two_Rival_Students.md "Educational Codeforces Round 76 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1257A - Two Rival Students](../problems/A._Two_Rival_Students.md "Educational Codeforces Round 76 (Rated for Div. 2)")

To solve the problem you need to understand two facts: 

1. The answer can't be greater than $n - 1$;
2. If current distance between rivaling student if less then $n-1$ we always can increment this distance by one swap;

In means that answer is equal to $\min (n - 1, |a - b| + x)$.

 **Solution (adedalic)**
```cpp
import kotlin.math.abs
fun main() {
    val q = readLine()!!.toInt()
    for (ct in 1..q) {
        val (n, x, a, b) = readLine()!!.split(' ').map { it.toInt() }
        println(minOf(n - 1, abs(a - b) + x))
    }
}
```
[1257B - Magic Stick](../problems/B._Magic_Stick.md "Educational Codeforces Round 76 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1257B - Magic Stick](../problems/B._Magic_Stick.md "Educational Codeforces Round 76 (Rated for Div. 2)")

$1$ cannot be transformed into any other number. $2$ can be transformed into $3$ or $1$, and $3$ can be transformed only into $2$. It means that if $x = 1$, then only $y = 1$ is reachable; and if $x = 2$ or $x = 3$, then $y$ should be less than $4$.

Otherwise, we can make $x$ as large as we want, so if $x > 3$, any $y$ is reachable.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;
	
	if (x > 3) puts("YES");
	else if (x == 1) puts(y == 1 ? "YES" : "NO");
	else puts(y <= 3 ? "YES" : "NO");
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) solve();
}
```
[1257C - Dominated Subarray](../problems/C._Dominated_Subarray.md "Educational Codeforces Round 76 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1257C - Dominated Subarray](../problems/C._Dominated_Subarray.md "Educational Codeforces Round 76 (Rated for Div. 2)")

At first, let's prove that the shortest dominated subarray has pattern like $v, c_1, c_2, \dots, c_k, v$ with $k \ge 0$ and dominated by value $v$. Otherwise, we can decrease its length by erasing an element from one of its ends which isn't equal to $v$ and it'd still be dominated.

Now we should go over all pairs of the same numbers and check its subarrays... Or not? Let's look closely at the pattern: if $v$ and all $c_i$ are pairwise distinct then the pattern is dominated subarray itself. Otherwise, we can find in our pattern other shorter pattern and either the found pattern is dominated or it has the pattern inside it and so on.

What does it mean? It means that the answer is just the shortest pattern we can find. And all we need to find is the shortest subarray with the same first and last elements or just distance between two consecutive occurrences of each number. We can do it by iterating over current position $i$ and keeping track of the last occurrence of each number in some array $lst[v]$. Then the current distance is $i - lst[a[i]] + 1$.

The total complexity is $O(n)$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

#define sz(a) int((a).size())

int n;
vector<int> a;

inline bool read() {
	if(!(cin >> n))
		return false;
	a.resize(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	return true;
}

inline void solve() {
	int ans = n + 5;
	vector<int> lst(n + 1, -1);
	for(int i = 0; i < n; i++) {
		if(lst[a[i]] != -1)
			ans = min(ans, i - lst[a[i]] + 1);
		lst[a[i]] = i;
	}
	if(ans > n)
		ans = -1;
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc; cin >> tc;
	while(tc--) {
		assert(read());
		solve();
	}
	return 0;
}
```
[1257D - Yet Another Monster Killing Problem](../problems/D._Yet_Another_Monster_Killing_Problem.md "Educational Codeforces Round 76 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1257D - Yet Another Monster Killing Problem](../problems/D._Yet_Another_Monster_Killing_Problem.md "Educational Codeforces Round 76 (Rated for Div. 2)")

At first, lets precalc array $bst$; $bst_i$ is equal to maximum hero power whose endurance is greater than or equal to $i$. 

Now let's notice that every day it's profitable for as to kill as many monster as possible. Remains to understand how to calculate it.

Suppose that we already killed $cnt$ monsters. If $a_{cnt+1} > bst_1$ then answer is -1, because we can't kill the $cnt+1$-th monster. Otherwise we can kill at least $x = 1$ monsters. All we have to do it increase the value $x$ until conditions $\max\limits_{cnt < i \le cnt + x} a_i \le bst_x$ holds. After calculating the value $x$ we just move to the next day with $cnt + x$ killed monsters.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 99;

int t;
int n;
int a[N];
int m;
int p[N], s[N];
int bst[N];

int main() {	
	scanf("%d", &t);
	for(int tc = 0; tc < t; ++tc){
		scanf("%d", &n);
		for(int i = 0; i <= n; ++i) bst[i] = 0;
		for(int i = 0; i < n; ++i)
			scanf("%d", a + i);
		scanf("%d", &m);
		for(int i = 0; i < m; ++i){
			scanf("%d %d", p + i, s + i);
			bst[s[i]] = max(bst[s[i]], p[i]);
		}
		for(int i = n - 1; i >= 0; --i)
			bst[i] = max(bst[i], bst[i + 1]);	
		

		int pos = 0;
		int res = 0;
		bool ok = true;
		while(pos < n){
			++res;
			int npos = pos;
			int mx = 0;
			while(true){
				mx = max(mx, a[npos]);
				if(mx > bst[npos - pos + 1]) break;
				++npos;
			}
	
			if(pos == npos){
				ok = false;
				break;
			}
			pos = npos;
		}

		if(!ok) res = -1;
		printf("%dn", res);
	}

	return 0;
}                             	            	
```
[1257E - The Contest](../problems/E._The_Contest.md "Educational Codeforces Round 76 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**
### [1257E - The Contest](../problems/E._The_Contest.md "Educational Codeforces Round 76 (Rated for Div. 2)")

Suppose we want to divide $r$ first problems of the contest between the first contestant and the second contestant (the first contestant will get $l$ first problems, and the second contestant will get $r - l$ problems in the middle), and then give all the remaining problems to the third contestant. We are going to iterate on $r$ from $0$ to $n$ and, for each possible $r$, find the best value of $l$.

Okay. Now suppose we fixed $l$ and $r$, and now we want to calculate the number of problems that should be redistributed. Let's denote $cnt_{l, i}$ as the number of problems among $l$ first ones given to the $i$-th contestant, $cnt_{r, i}$ as the number of problems among $r$ last ones given to the $i$-th contestant, and $cnt_{m, i}$ as the number of problems in the middle given to the $i$-th contestant.

Obviously, the answer for fixed $l$ and $r$ is $cnt_{l, 2} + cnt_{l, 3} + cnt_{m, 1} + cnt_{m, 3} + cnt_{r, 1} + cnt_{r, 2}$, but we don't like this expression because we don't know how to minimize it for fixed $r$. We know that, for fixed $r$, the values of $cnt_{l, i} + cnt_{m, i}$ and $cnt_{r, i}$ are constant. Using that, we may arrive at the fact that minimizing $cnt_{l, 2} + cnt_{l, 3} + cnt_{m, 1} + cnt_{m, 3} + cnt_{r, 1} + cnt_{r, 2}$ is the same as minimizing $cnt_{l, 2} - cnt_{l, 1}$ for fixed $r$ — and now we have a way to quickly find best possible $l$ for fixed $r$.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int k1, k2, k3;
	scanf("%d %d %d", &k1, &k2, &k3);
	int n = k1 + k2 + k3;
	vector<int> a(n);
	for(int i = 0; i < k1; i++)
	{
		int x;
		scanf("%d", &x);
		a[x - 1] = 0;
	}
	for(int i = 0; i < k2; i++)
	{
		int x;
		scanf("%d", &x);
		a[x - 1] = 1;
	}
	for(int i = 0; i < k3; i++)
	{
		int x;
		scanf("%d", &x);
		a[x - 1] = 2;
	}
	
	int ans = 0;
	int bestp = 0;
	for(int i = 0; i < n; i++)
		if(a[i] != 2)
			ans++;
	vector<int> cntl(3);
	vector<int> cntr(3);
	for(int i = 0; i < n; i++)
		cntr[a[i]]++;
	for(int i = 0; i < n; i++)
	{
		cntl[a[i]]++;
		cntr[a[i]]--;
		bestp = max(bestp, cntl[0] - cntl[1]);
		int curans = cntr[0] + cntr[1] + cntl[2] + cntl[0] - bestp;
		ans = min(ans, curans);
	}
	
	cout << ans << endl;
}                    	
```
[1257F - Make Them Similar](../problems/F._Make_Them_Similar.md "Educational Codeforces Round 76 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**
### [1257F - Make Them Similar](../problems/F._Make_Them_Similar.md "Educational Codeforces Round 76 (Rated for Div. 2)")

Iterating over all possible values of $x$ and checking them may be too slow (though heavily optimized brute force is difficult to eliminate in this problem), so we need to speed this approach up.

The resulting number consists of $30$ bits. Let's use the classical meet-in-the-middle trick: try all $2^{15}$ combinations of $15$ lowest bits, try all $2^{15}$ combinations of $15$ highest bits, and somehow "merge" the results.

When we fix a combination of $15$ lowest bits, we fix $15$ lowest bits in every $b_i$. Suppose that there are $cnt_{0, i}$ ones among $15$ lowest bits of $b_i$.

Analogically, when we fix a combination of $15$ highest bits, we fix $15$ highest bits in every $b_i$. Suppose that there are $cnt_{1, i}$ ones among $15$ highest bits of $b_i$.

We want to find a combination of lowest and highest bits such that $cnt_{0, i} + cnt_{1, i}$ is the same for each $i$. Let's represent each combination of $15$ lowest bits with an $(n-1)$-dimensional vector with coordinates $(cnt_{0, 1} - cnt_{0, 2}, cnt_{0, 1} - cnt_{0, 3}, \dots, cnt_{0, 1} - cnt_{0, n})$. Let's also represent each combination of $15$ highest bits with an $(n-1)$-dimensional vector with coordinates $(cnt_{1, 1} - cnt_{1, 2}, cnt_{1, 1} - cnt_{1, 3}, \dots, cnt_{1, 1} - cnt_{1, n})$. We want to find a combination of lowest bits and a combination of highest bits such that their vectors are opposite. We can do so, for example, by precalculating all vectors for all combinations of $15$ lowest bits, storing them in a map or a trie, iterating on a combination of $15$ highest bits and searching for the opposite vector in the map/trie.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long li;
const int N = 143;
const int K = 15;
const int V = 5000000;

int n;
li a[N];
int lst[V];
map<int, int> nxt[V];
int t = 1;
li a1[N];
li a2[N];

int get_nxt(int v, int x)
{
	if(!nxt[v].count(x))
		nxt[v][x] = t++;
	return nxt[v][x];
}

void add(vector<int> diff, int x)
{
	int v = 0;
	for(auto i : diff)
		v = get_nxt(v, i);
	lst[v] = x;
}

int try_find(vector<int> diff)
{
	int v = 0;
	for(auto i : diff)
	{
		if(!nxt[v].count(i))
			return -1;
		v = nxt[v][i];
	}
	return lst[v];
}

vector<int> get_diff(li arr[N], int x)
{
	vector<int> cnt(n);
	for(int i = 0; i < n; i++)
		cnt[i] = __builtin_popcountll(arr[i] ^ x);
	vector<int> diff(n - 1);
	for(int i = 0; i + 1 < n; i++)
		diff[i] = cnt[i + 1] - cnt[0];
	return diff;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	for(int i = 0; i < n; i++)
	{
		a1[i] = (a[i] >> K);
		a2[i] = a[i] ^ (a1[i] << K);
	}
	for(int i = 0; i < (1 << K); i++)
	{
		vector<int> d = get_diff(a1, i);
		add(d, i);
	}
	for(int i = 0; i < (1 << K); i++)
	{
		vector<int> d = get_diff(a2, i);
		for(int j = 0; j + 1 < n; j++)
			d[j] *= -1;
		int x = try_find(d);
		if(x != -1)
		{
			li res = (li(x) << K) ^ i;
			cout << res << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
	return 0;
}
```
[1257G - Divisor Set](../problems/G._Divisor_Set.md "Educational Codeforces Round 76 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1257G - Divisor Set](../problems/G._Divisor_Set.md "Educational Codeforces Round 76 (Rated for Div. 2)")

The problem consists of two parts: what do we want to calculate and how to calculate it?

What do we want to calculate? There are several ways to figure it out. At first, you could have met this problem before and all you need is to remember a solution.

At second, you can come up with the solution in a purely theoretical way — Hasse diagram can help with it greatly. Let's define $deg(x)$ as the number of primes in prime factorization of $x$. For example, $deg(2 \cdot 3 \cdot 2) = 3$ and $deg(1) = 0$. If you look at Hasse diagram of $p_1 \cdot \ldots \cdot p_n$ you can see that all divisors with $deg(d) = i$ lies on level $i$. If $x$ is divisible by $y$ then $deg(x) > deg(y)$ so all divisors on the same level don't divide each other. Moreover, the diagram somehow symmetrical about its middle level and sizes of levels are increasing while moving to the middle. It gives us an idea that the answer is the size of the middle level, i.e. the number of divisors with $deg(d) = \frac{n}{2}$.

The final way is just to brute force the answers for small $x$-s and find the sequence in OEIS with name A096825, where the needed formulas are described.

The second step is to calculate the number of divisors with $deg(d) = \frac{n}{2}$. Suppose we have $m$ distinct primes $p_j$ and the number of occurences of $p_j$ is equal to $cnt_j$. Then we need to calculate pretty standard knapsack problem where you need to calculate number of ways to choose subset of size $\frac{n}{2}$ where you can take each $p_j$ up to $cnt_j$ times. Or, formally, number of vectors $(x_1, x_2, \dots x_m)$ with $\sum\limits_{j = 0}^{j = m}{x_j} = \frac{n}{2}$ and $0 \le x_j \le cnt_j$.

Calculating the answer using $dp[pos][sum]$ will lead to time limit, so we need to make the following transformation. Let's build for each $p_j$ a polynomial $f_j(x) = 1 + x + x^2 + \dots + x^{cnt_j}$. Now the answer is just a coefficient before $x^{\frac{n}{2}}$ in product $f_1(x) \cdot f_2(x) \cdot \ldots \cdot f_m(x)$. Note, that the product has degree $n$, so we can multiply polynomials efficiently with integer FFT in the special order to acquire $O(n \log^2(n))$ time complexity.

There several ways to choose the order of multiplications. At first, you can, at each step, choose two polynomials with the lowest degree and multiply them. At second, you can use the divide-and-conquer technique by dividing the current segment in two with pretty same total degrees. At third, you can also use D-n-C but divide the segment at halves and, it seems still to be $O(n \log^2(n))$ in total.

What about the proof of the solution? Thanks to tyrion__ for the link at the article: [https://pure.tue.nl/ws/files/4373475/597494.pdf](https://codeforces.com/https://pure.tue.nl/ws/files/4373475/597494.pdf).

The result complexity is $O(n \log^2(n))$ time and $O(n)$ space (if carefully written). Note, that the hidden constant in integer FFT is pretty high and highly depends on the implementation, so it's possible for poor implementations not to pass the time limit.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

const int LOGN = 18;
const int MOD = 998244353;
int g = 3;

int mul(int a, int b) {
	return int(a * 1ll * b % MOD);
}
int norm(int a) {
	while(a >= MOD) a -= MOD;
	while(a < 0) a += MOD;
	return a;
}
int binPow (int a, int k) {
	int ans = 1;
	for (; k > 0; k >>= 1) {
		if (k & 1)
			ans = mul(ans, a);
		a = mul(a, a);
	}
	return ans;
}
int inv(int a) {
	return binPow(a, MOD - 2);
}

vector<int> w[LOGN], rv;
bool precalced = false;

void precalc() {
	if(precalced)
		return;
	precalced = true;
	
    int wb = binPow(g, (MOD - 1) / (1 << LOGN));
    fore(st, 0, LOGN) {
        w[st].assign(1 << st, 1);

        int bw = binPow(wb, 1 << (LOGN - st - 1));
        int cw = 1;

        fore(k, 0, (1 << st)) {
            w[st][k] = cw;
            cw = mul(cw, bw);
        }
    }
    
    rv.assign(1 << LOGN, 0);
    fore(i, 1, sz(rv))
		rv[i] = (rv[i >> 1] >> 1) | ((i & 1) << (LOGN - 1));
}

const int MX = (1 << LOGN) + 3;

inline void fft(int a[MX], int n, bool inverse) {
	precalc();
	
    int ln = __builtin_ctz(n);
    assert((1 << ln) < MX);
    assert((1 << ln) == n);

    fore(i, 0, n) {
        int ni = rv[i] >> (LOGN - ln);
        if(i < ni) swap(a[i], a[ni]);
    }

    for(int st = 0; (1 << st) < n; st++) {
        int len = (1 << st);
        for(int k = 0; k < n; k += (len << 1)) {
        	fore(pos, k, k + len) {
                int l = a[pos];
                int r = mul(a[pos + len], w[st][pos - k]);

                a[pos] = norm(l + r);
                a[pos + len] = norm(l - r);
            }
        }
    }
    
    if(inverse) {
        int in = inv(n);
        fore(i, 0, n)
            a[i] = mul(a[i], in);
        reverse(a + 1, a + n);
    }
}

int aa[MX], bb[MX], cc[MX];

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
	int ln = 1;
	while(ln < (sz(a) + sz(b)))
		ln <<= 1;
	
	fore(i, 0, ln)
		aa[i] = (i < sz(a) ? a[i] : 0);
	fore(i, 0, ln)
		bb[i] = (i < sz(b) ? b[i] : 0);
		
	fft(aa, ln, false);
	fft(bb, ln, false);
	
	fore(i, 0, ln)
		cc[i] = mul(aa[i], bb[i]);
	fft(cc, ln, true);
	
	vector<int> ans(cc, cc + ln);
	while(ans.back() == 0)
		ans.pop_back();
	return ans;
}

int n;
vector<int> ps;

inline bool read() {
	if(!(cin >> n))
		return false;
	ps.resize(n);
	fore(i, 0, n)
		cin >> ps[i];
	return true;
}

struct cmp {
	bool operator ()(const vector<int> &a, const vector<int> &b) {
		return sz(a) < sz(b);
	}
};

inline void solve() {
	map<int, int> cnt;
	fore (i, 0, n)
		cnt[ps[i]]++;
	
	multiset< vector<int>, cmp > polys;
	for (auto p : cnt)
		polys.emplace(p.second + 1, 1);
	
	while (sz(polys) > 1) {
		auto it2 = polys.begin();
		auto it1 = it2++;
		polys.insert(multiply(*it1, *it2));
		
		polys.erase(it1);
		polys.erase(it2);
	}

	auto poly = *polys.begin();
//	cerr << '[';
//	fore(i, 0, sz(poly)) {
//		if(i) cerr << ", ";
//		cerr << poly[i];
//	}
//	cerr << ']' << endl;

	cout << poly[n / 2] << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
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
