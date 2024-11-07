# Tutorial

[1334A - Level Statistics](../problems/A._Level_Statistics.md "Educational Codeforces Round 85 (Rated for Div. 2)")

Idea: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo")

 **Tutorial**
### [1334A - Level Statistics](../problems/A._Level_Statistics.md "Educational Codeforces Round 85 (Rated for Div. 2)")

Let's use the fact that initially the level has $0$ plays and $0$ clears. Call the differences before the previous stats and the current ones $\Delta p$ and $\Delta c$.

The stats are given in chronological order, so neither the number of plays, nor the number of clears should decrease (i.e. $\Delta p \ge 0$ and $\Delta c \ge 0$).

Finally, $\Delta p$ should be greater or equal to $\Delta c$. It's easy to show that if $\Delta c$ players pass the level successfully and $\Delta p - \Delta c$ players just try the level then such deltas are achieved.

So in implementation it's enough to check these three conditions between the consecutive pieces of data (including the initial ($0, 0$)).

Overall complexity: $O(n)$.

 **Solution (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;


int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--){
		int n;
		scanf("%d", &n);
		int p = 0, c = 0;
		bool fl = true;
		forn(i, n){
			int x, y;
			scanf("%d%d", &x, &y);
			if (x < p || y < c || y - c > x - p)
				fl = false;
			p = x, c = y;
		}
		puts(fl ? "YES" : "NO");
	}
	return 0;
}
```
[1334B - Middle Class](../problems/B._Middle_Class.md "Educational Codeforces Round 85 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1334B - Middle Class](../problems/B._Middle_Class.md "Educational Codeforces Round 85 (Rated for Div. 2)")

In fact, to carry out only one reform is always enough. And it's easy to prove if you make only one reform it's always optimal to take the maximum such $k$ that the average of $k$ maximums in the array $a$ is at least $x$ (i.e. sum greater or equal to $kx$). So the solution is next: sort array $a$ and find the suffix with maximum length $k$ such that the sum on the suffix is at least $kx$.

===

To prove the fact about one reform we can prove another fact: after each reform, the sum of $k$ maximums doesn't increase for each $k$. We'll prove it in two steps.

The first step. Let's look at some reform and form an array $b$ from the chosen elements in $a$ in descending order. After the reform we'll get array $b'$ where all $b'[i] = \frac{1}{|b|} \sum_{i=1}^{|b|}{b[i]}$. Let's just skip the proof and say it's obvious enough that $\sum_{i=1}^{y}{b[i]} \ge \sum_{i=1}^{y}{b'[i]}$ for any $y$.

The second step. Let fix $k$ and divide array $a$ on two parts: $k$ maximums as $a_1$ and other $n - k$ elements as $a_2$. And let's make the same division of $a'$ (the array after performing the reform) on $a'_1$ and $a'_2$. So, we need to prove that $sum(a'_1) \le sum(a_1)$. 

Suppose $m$ elements were chosen in the reform: $cnt$ of them were in $a_1$ and $cnt'$ now in $a'_1$. If $cnt \ge cnt'$ then we can think like maximum $cnt'$ elements from $cnt$ elements in $a$ were replaced by the average and other $cnt - cnt'$ were replaced by elements from $a_2$. Since $\sum_{i=1}^{cnt'}{b[i]} \ge \sum_{i=1}^{cnt'}{b'[i]}$ and any element from $a_1$ is greater or equal to any element from $a_2$ then we proved that $sum(a'_1) \le sum(a_1)$ when $cnt \ge cnt'$.

If $cnt < cnt'$ then let's look at $a_2$ and $a'_2$. The $a_2$ has $m - cnt$ chosen elements and $a'_2$ has $m - cnt'$, so $m - cnt > m - cnt'$ and we can prove that $sum(a'_2) \ge sum(a_2)$ practically in the same way as before. Obviously, if $sum(a') = sum(a)$ and $sum(a'_2) \ge sum(a_2)$ then $sum(a'_1) \le sum(a_1)$. Q.E.D.

The last step is easy, let's prove that the only reform is enough. The answer after several reforms is clearly equal to $k$ maximums which are at least $x$. But it means that the sum of $k$ maximums is at least $kx$, therefore the sum of $k$ maximums in the initial array is at least $kx$. So we can make them all at least $k$ by only one reform. 

 **Solution (adedalic)**
```cpp
fun main() {
    val T = readLine()!!.toInt()
    for (tc in 1..T) {
        val (n, x) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.sortedDescending()

        var cnt = 0
        var sum = 0L
        while (cnt < n && sum + a[cnt] >= (cnt + 1) * x.toLong()) {
            sum += a[cnt]
            cnt++
        }
        println(cnt)
    }
}
```
[1334C - Circle of Monsters](../problems/C._Circle_of_Monsters.md "Educational Codeforces Round 85 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1334C - Circle of Monsters](../problems/C._Circle_of_Monsters.md "Educational Codeforces Round 85 (Rated for Div. 2)")

We cannot utilize the explosion of the last monster we kill. So the naive approach is to iterate on the monster we kill the last, break the circle between this monster and the next one, and then shoot the first monster in the broken circle until it's dead, then the second one, and so on.

Let's calculate the number of bullets we will fire this way. If the circle is broken after the monster $i$, then the first monster gets $a_{i + 1}$ bullets, the second one — $\max(0, a_{i + 2} - b_{i + 1})$, and so on; all monsters except the first one get exactly $\max(0, a_i - b_{i - 1})$ bullets. 

So we should choose an index $i$ such that $a_{i + 1} - \max(0, a_{i + 1} - b_i)$ is minimum possible, since this is the number of bullets we have to spend additionally since we cannot utilize the explosion of the $i$-th monster. After breaking the circle between the monsters $i$ and $i + 1$, you may use a formula to calculate the required number of bullets, or just model the shooting.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

typedef long long li;

const int N = 300 * 1000 + 13;

int n;
li a[N], b[N];

void solve() {
	scanf("%d", &n);
	forn(i, n) scanf("%lld%lld", &a[i], &b[i]);
	
	li ans = 0, mn = 1e18;
	forn(i, n) {
		int ni = (i + 1) % n;
		li val = min(a[ni], b[i]);
		ans += a[ni] - val;
		mn = min(mn, val);
	}
	ans += mn;
	printf("%lldn", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	forn(i, T)
		solve();
}
```
[1334D - Minimum Euler Cycle](../problems/D._Minimum_Euler_Cycle.md "Educational Codeforces Round 85 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1334D - Minimum Euler Cycle](../problems/D._Minimum_Euler_Cycle.md "Educational Codeforces Round 85 (Rated for Div. 2)")

The solution of the problem can be found clearly in constructive way. An example for $n=5$: (1 2 1 3 1 4 1 5 (2 3 2 4 2 5 (3 4 3 5 (4 5 ()))) 1) where brackets mean that we call here some recursive function $calc$.

Since on each level of recursion we have only $O(n)$ elements and there $O(n)$ levels then the generation of the certificate is quite easy: if on the currect level of recursion we can skip the whole part — let's just skip it. Otherwise let's build this part. Anyway, the built part of the cycle will have only $O(n + (r - l))$ length so the whole algorithm has $O(n + (r - l))$ complexity.

The answer is lexicographically minimum by the construction, since on each level of recursion there is no way to build lexicographically smaller sequence.

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

int n;
li l, r;

inline bool read() {
	if(!(cin >> n >> l >> r))
		return false;
	return true;
}

bool intersect(li l1, li r1, li l2, li r2) {
	return min(r1, r2) > max(l1, l2);
}

vector<int> ans;

void calc(int lf, int rg, li &id) {
	if(lf == rg) return;
	
	if(intersect(l, r, id, id + 2 * (rg - lf))) {
		fore(to, lf + 1, rg + 1) {
			if(l <= id && id < r)
				ans.push_back(lf);
			id++;
			
			if(l <= id && id < r)
				ans.push_back(to);
			id++;
		}
	} else
		id += 2 * (rg - lf);
	
	calc(lf + 1, rg, id);
	
	if(lf == 0) {
		if(l <= id && id < r)
			ans.push_back(lf);
		id++;
	}
}

inline void solve() {
	ans.clear();
	li id = 0;
	l--;
	calc(0, n - 1, id);
	
	assert(sz(ans) == r - l);
	assert(id == n * li(n - 1) + 1);
	
	for(int v : ans)
		cout << v + 1 << " ";
	cout << endl;
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
[1334E - Divisor Paths](../problems/E._Divisor_Paths.md "Educational Codeforces Round 85 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1334E - Divisor Paths](../problems/E._Divisor_Paths.md "Educational Codeforces Round 85 (Rated for Div. 2)")

Let's define the semantics of moving along the graph. On each step the current number is either multiplied by some prime or divided by it.

I claim that the all shortest paths from $x$ to $y$ always go through $gcd(x, y)$. Moreover, the vertex numbers on the path first only decrease until $gcd(x, y)$ and only increase after it.

Let's watch what happens to the divisors list on these paths. At first, all the divisors of $x$ that are not divisors of $y$ are removed from the list. Now we reach gcd and we start adding the divisors of $y$ that are missing from the list. The length of the path is this total number of changes to the list. That shows us that these paths are the shortest by definition.

If we ever take a turn off that path, we either will add some divisor that we will need to remove later or remove some divisor that we will need to add later. That makes the length of the path not optimal.

Now let's learn to calculate the number of paths. The parts before gcd and after it will be calculated separately, the answer is the product of answers for both parts.

How many paths are there to gcd? Well, let's divide $x$ by $gcd$, that will give us the primes that should be removed from $x$. You can remove them in any order because the length of the path is always the same. That is just the number of their permutations with repetitions (you might also know that formula as multinomial coefficient).

The number of paths from $gcd$ to $y$ is calculated the same way.

To find the primes in $\frac{x}{gcd(x, y)}$ you can factorize $D$ beforehand and only iterate over the primes of $D$.

Overall complexity: $O(\sqrt{D} + q \log D)$.

 **Solution (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int MOD = 998244353;

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return a * 1ll * b % MOD;
}

int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int main() {
	long long d;
	scanf("%lld", &d);
	int q;
	scanf("%d", &q);
	
	vector<long long> primes;
	for (long long i = 2; i * i <= d; ++i) if (d % i == 0){
		primes.push_back(i);
		while (d % i == 0) d /= i;
	}
	if (d > 1){
		primes.push_back(d);
	}
	
	vector<int> fact(100), rfact(100);
	fact[0] = 1;
	for (int i = 1; i < 100; ++i)
		fact[i] = mul(fact[i - 1], i);
	rfact[99] = binpow(fact[99], MOD - 2);
	for (int i = 98; i >= 0; --i)
		rfact[i] = mul(rfact[i + 1], i + 1);
	
	forn(i, q){
		long long x, y;
		scanf("%lld%lld", &x, &y);
		vector<int> up, dw;
		for (auto p : primes){
			int cnt = 0;
			while (x % p == 0){
				--cnt;
				x /= p;
			}
			while (y % p == 0){
				++cnt;
				y /= p;
			}
			if (cnt < 0) dw.push_back(-cnt);
			else if (cnt > 0) up.push_back(cnt);
		}
		int ans = 1;
		ans = mul(ans, fact[accumulate(up.begin(), up.end(), 0)]);
		for (auto it : up) ans = mul(ans, rfact[it]);
		ans = mul(ans, fact[accumulate(dw.begin(), dw.end(), 0)]);
		for (auto it : dw) ans = mul(ans, rfact[it]);
		printf("%dn", ans);
	}
	
	return 0;
}
```
[1334F - Strange Function](../problems/F._Strange_Function.md "Educational Codeforces Round 85 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms") и [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1334F - Strange Function](../problems/F._Strange_Function.md "Educational Codeforces Round 85 (Rated for Div. 2)")

The "naive" version of the solution is just dynamic programming: let $dp_{i, j}$ be the minimum cost of removed elements (or the maximum cost of remaining elements) if we considered first $i$ elements of $a$, and the resulting sequence maps to the first $j$ elements of $b$. There are two versions of this solution, both working in $O(n^2)$:

* calculate this dp "as it is", so there are $O(nm)$ states and $O(1)$ transitions from each state;
* ensure that the $i$-th element is taken into $f(a)$, so there are $O(n)$ states (since each element appears in $b$ exactly once, the second state can be deduces from the first one), but up to $O(n)$ transitions from each state.

It turns out that we can optimize the second approach. Let's calculate the values of $dp_i$ in ascending order of $a_i$: first of all, we calculate the values of $dp_i$ such that $a_i = b_1$, then transition into states such that $a_i = b_2$, and so on.

Calculating $dp_i$ for $a_i = b_1$ is easy: since the first element of $a$ is always the first element of $f(a)$, we should delete all elements before the $i$-th if we want it to be the first element in $f(a)$. So, if $dp_i$ is the maximum possible sum of costs of remaining elements, if we considered the first $i$ elements of $a$ (and the $i$-th element gets included in $f(a)$), then $dp_i = c_i$ for indices $i$ such that $a_i = b_1$.

Okay, now let's consider advancing from $b_k$ to $b_{k + 1}$. If we want to go from $dp_i$ to $dp_j$ such that $a_i = b_k$ and $a_j = b_{k + 1}$, we should leave the element $a_j$ in the array and delete some elements between indices $i$ and $j$. Which ones should be deleted? First of all, they are all elements with negative deletion cost; but we should also get rid of all elements which could replace $a_j$ in $f(a)$ — that is, all elements that are greater than $a_i$. So the remaining elements are $x$ which have $i < x < j$, $c_x > 0$ and $a_x \le a_i$, and we should be able to compute the sum of such elements.

Even if we manage to do it in $O(\log n)$, which is possible, there may be up to $O(n^2)$ possible pairs of $dp_i$ and $dp_j$ to consider. The easiest way to get rid of that is to sort all occurences of $b_k$ and $b_{k + 1}$, and process them in ascending order, maintaining the best $dp_i$ that was already met. That way, each of the elements of $a$ will be considered at most twice, so this solution runs in $O(n \log n)$.

We know how to calculate the $dp$ values now, but how to determine the answer? We should consider all values of $dp_i$ such that $a_i = b_m$ and delete all elements with negative costs and all elements that are greater than $a_i$ from the suffix $[i + 1, n]$ — so this is another query of the form "compute the sum of $c_x$ over $x$ which have $i < x < j$, $c_x > 0$ and $a_x \le a_i$". The most straightforward way to process them in $O(\log n)$ is to use a persistent segment tree, but since $a_i$ does not decrease in these queries as we process them, we may maintain the elements we are interested in with a much simpler data structure, for example, Fenwick tree.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long li;
const li INF64 = li(1e18);
const int N = 500043;

li f[N];

li get(int x)
{
    li ans = 0;    
    for (; x >= 0; x = (x & (x + 1)) - 1)
        ans += f[x];
    return ans;
}

void inc(int x, li d)
{
    for (; x < N; x = (x | (x + 1)))
        f[x] += d;    
}

li get(int l, int r)
{
    return get(r) - get(l - 1);
}

li dp[N];
int a[N], b[N], p[N];
int n, m;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    for(int i = 0; i < n; i++)
        dp[i] = -INF64;
    map<int, vector<int> > pos;
    for(int i = 0; i < n; i++)
        pos[a[i]].push_back(i);
    set<pair<int, int> > q;
    for(int i = 0; i < n; i++)
        q.insert(make_pair(a[i], i));
    
    for(auto x : pos[b[0]])
        dp[x] = p[x];
    while(!q.empty() && q.begin()->first <= b[0])
    {
        int k = q.begin()->second;
        q.erase(q.begin());
        if(p[k] > 0)
            inc(k, p[k]);
    }  

    for(int i = 1; i < m; i++)
    {
        int i1 = b[i - 1], i2 = b[i];
        vector<int> both_pos;
        for(auto x : pos[i1])
            both_pos.push_back(x);
        for(auto x : pos[i2])
            both_pos.push_back(x);
        li best = -INF64;
        int last = -1;
        sort(both_pos.begin(), both_pos.end());
        for(auto x : both_pos)
        {
            best += get(last + 1, x);
            last = x;
            if(a[x] == i1)
                best = max(best, dp[x]);
            else
                dp[x] = best + p[x];
        }
        while(!q.empty() && q.begin()->first <= i2)
        {
            int k = q.begin()->second;
            q.erase(q.begin());
            if(p[k] > 0)
                inc(k, p[k]);
        }
    }

    li best_dp = -INF64;
    for(int i = 0; i < n; i++)
        if(a[i] == b[m - 1])
            best_dp = max(best_dp, dp[i] + get(i + 1, n - 1));
    li ans = 0;
    for(int i = 0; i < n; i++)
        ans += p[i];
    ans -= best_dp;
    if(ans > li(1e15))
        puts("NO");
    else     
        printf("YESn%lldn", ans);
    
}
```
[1334G - Substring Search](../problems/G._Substring_Search.md "Educational Codeforces Round 85 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1334G - Substring Search](../problems/G._Substring_Search.md "Educational Codeforces Round 85 (Rated for Div. 2)")

We will run two tests for each substring of $t$ we are interested in. If at least one of them shows that the substring is not an occurence of $s$, we print 0, otherwise we print 1.

The first test is fairly easy. The given permutation can be decomposed into cycles. Let's replace each character with the index of its cycle (in both strings) and check if each substring of $t$ is equal to $s$ after this replacement (for example, using regular KMP algorithm). If some substring is not equal to $s$ after the replacement, then it is definitely not an occurence.

The second test will help us distinguish the characters belonging to the same cycle. Let $[c_1, c_2, \dots, c_k]$ be some cycle in our permutation (elements are listed in the order they appear in the cycle, so $p_{c_i} = c_{i + 1}$). We will replace each character with a complex number in such a way that the case when they match are easily distinguishable from the case when they don't match. One of the ways to do this is to replace $c_i$ with a complex number having magnitude equal to $1$ and argument equal to $\dfrac{2 \pi i}{k}$ (if this character belongs to $s$) or to $\dfrac{\pi - 2 \pi i}{k}$ (if this character belongs to $t$).

How does this replacement help us checking the occurence? If we multiply the numbers for two matching characters, we get a complex number with argument equal to $\dfrac{\pi}{k}$ or to $-\dfrac{\pi}{k}$, and its real part will be $\cos \dfrac{\pi}{k}$. In any other case, the real part of the resulting number will be strictly less than $\cos \dfrac{\pi}{k}$, and the difference will be at least $0.06$. So, if we compute the value of $\sum \limits_{i = 1}^{|s|} f(s_i) \cdot f(t_{j + i - 1})$ for the $j$-th substring of $t$ (where $f(c)$ is the number that replaced the character $c$), we can check if the real part of the result is close to the value we would get if we matched $s$ with itself (and if the difference is big enough, at least one pair of characters didn't match). The only case when this method fails is if we try to match characters from different cycles of the permutation, that's why we needed the first test.

Overall, the first test can be done in $O(|s| + |t|)$ using prefix function (or any other linear substring search algorithm), and the second test can be done in $O((|s| + |t|) \log(|s| + |t|))$, if we compute the aforementioned values for each substring using FFT.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < n; i++)
#define sz(a) ((int)(a).size())

const int LOGN = 20;
const int N = (1 << LOGN);

typedef long double ld;
typedef long long li;

const ld PI = acos(-1.0);

struct comp 
{
    ld x, y;
    comp(ld x = .0, ld y = .0) : x(x), y(y) {}
    inline comp conj() { return comp(x, -y); }
};

inline comp operator +(const comp &a, const comp &b) 
{
    return comp(a.x + b.x, a.y + b.y);
}

inline comp operator -(const comp &a, const comp &b) 
{
    return comp(a.x - b.x, a.y - b.y);
}

inline comp operator *(const comp &a, const comp &b) 
{
    return comp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

inline comp operator /(const comp &a, const ld &b) 
{
    return comp(a.x / b, a.y / b);
}

vector<comp> w[LOGN];
vector<int> rv[LOGN];

void precalc() 
{
    for(int st = 0; st < LOGN; st++) 
    {
        w[st].assign(1 << st, comp());
        for(int k = 0; k < (1 << st); k++) 
        {
            double ang = PI / (1 << st) * k;
            w[st][k] = comp(cos(ang), sin(ang));
        }
        
        rv[st].assign(1 << st, 0);
        if(st == 0) 
        {
            rv[st][0] = 0;
            continue;
        }
        int h = (1 << (st - 1));
        for(int k = 0; k < (1 << st); k++)
            rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
    }
}

inline void fft(comp a[N], int n, int ln, bool inv) 
{
    for(int i = 0; i < n; i++) 
    {
        int ni = rv[ln][i];
        if(i < ni)
            swap(a[i], a[ni]);
    }
    
    for(int st = 0; (1 << st) < n; st++) 
    {
        int len = (1 << st);
        for(int k = 0; k < n; k += (len << 1)) 
        {
            for(int pos = k; pos < k + len; pos++) 
            {
                comp l = a[pos];
                comp r = a[pos + len] * (inv ? w[st][pos - k].conj() : w[st][pos - k]);
                
                a[pos] = l + r;
                a[pos + len] = l - r;
            }
        }
    }
    
    if(inv) for(int i = 0; i < n; i++)
        a[i] = a[i] / n;
}

comp aa[N];
comp bb[N];
comp cc[N];

inline void multiply(comp a[N], int sza, comp b[N], int szb, comp c[N], int &szc) 
{
    int n = 1, ln = 0;
    while(n < (sza + szb))
        n <<= 1, ln++;
    for(int i = 0; i < n; i++)
        aa[i] = (i < sza ? a[i] : comp());
    for(int i = 0; i < n; i++)
        bb[i] = (i < szb ? b[i] : comp());
        
    fft(aa, n, ln, false);
    fft(bb, n, ln, false);
    
    for(int i = 0; i < n; i++)
        cc[i] = aa[i] * bb[i];
        
    fft(cc, n, ln, true);
    
    szc = n;
    for(int i = 0; i < n; i++)
        c[i] = cc[i];
}

comp a[N];
comp b[N];
comp c[N];

vector<int> p_function(const vector<int>& v)
{
    int n = v.size();
    vector<int> p(n);
    for(int i = 1; i < n; i++)
    {
        int j = p[i - 1];
        while(j > 0 && v[j] != v[i])
            j = p[j - 1];
        if(v[j] == v[i])
            j++;
        p[i] = j;   
    }
    return p;
}

int p[26];
char buf[N];
string s, t;

int main()
{
    precalc();                  
    for(int i = 0; i < 26; i++)
    {
        scanf("%d", &p[i]);
        p[i]--;
    }
    scanf("%s", buf);
    s = buf;
    scanf("%s", buf);
    t = buf;

    int n = s.size();
    int m = t.size();
    vector<int> color(26, 0);
    vector<vector<int> > cycles;
    for(int i = 0; i < 26; i++)
    {
        if(color[i])
            continue;
        vector<int> cycle;
        int cc = cycles.size() + 1;
        int cur = i;
        while(color[cur] == 0)
        {
            cycle.push_back(cur);
            color[cur] = cc;
            cur = p[cur];
        }
        cycles.push_back(cycle);
    }

    vector<int> ans(m - n + 1);
    vector<int> s1, t1;
    for(int i = 0; i < n; i++)
        s1.push_back(color[int(s[i] - 'a')]);
    for(int i = 0; i < m; i++)
        t1.push_back(color[int(t[i] - 'a')]);
    vector<int> st = s1;
    st.push_back(0);
    for(auto x : t1)
        st.push_back(x);
    vector<int> pf = p_function(st);
    for(int i = 0; i < m - n + 1; i++)
        if(pf[2 * n + i] == n)
            ans[i] = 1;
    map<char, comp> m1, m2;
    for(auto cur : cycles)
    {
        int k = cur.size();
        for(int i = 0; i < k; i++)
        {
            ld ang1 = 2 * PI * i / k;
            ld ang2 = (PI - 2 * PI * i) / k;
            m1[char('a' + cur[i])] = comp(cosl(ang1), sinl(ang1));
            m2[char('a' + cur[i])] = comp(cosl(ang2), sinl(ang2));
        }
    }

    ld ideal = 0;
    for(int i = 0; i < n; i++)
        ideal += (m1[s[i]] * m2[s[i]]).x;
    reverse(s.begin(), s.end());
    for(int i = 0; i < n; i++)                  
        a[i] = m1[s[i]];                
    for(int i = 0; i < m; i++)
        b[i] = m2[t[i]];
    int szc;
    multiply(a, n, b, m, c, szc);
    for(int i = 0; i < m - n + 1; i++)
        if(fabsl(c[i + n - 1].x - ideal) > 0.01)
            ans[i] = 0;
    

    for(int i = 0; i < m - n + 1; i++)
        printf("%d", ans[i]);
    return 0;
}
```
