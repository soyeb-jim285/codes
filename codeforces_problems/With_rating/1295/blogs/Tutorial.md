# Tutorial

[1295A - Display The Number](../problems/A._Display_The_Number.md "Educational Codeforces Round 81 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1295A - Display The Number](../problems/A._Display_The_Number.md "Educational Codeforces Round 81 (Rated for Div. 2)")

First of all, we don't need to use any digits other than $1$ and $7$. If we use any other digit, it consists of $4$ or more segments, so it can be replaced by two $1$'s and the number will become greater. For the same reason we don't need to use more than one $7$: if we have two, we can replace them with three $1$'s.

Obviously, it is always optimal to place $7$ before $1$. So our number is either a sequence of $1$'s, or a $7$ and a sequence of $1$'s. We should use $7$ only if $n$ is odd, because if $n$ is even, it will decrease the number of digits in the result.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    n = int(input())
    if(n % 2 == 1):
        print(7, end='')
        n -= 3
    while(n > 0):
        print(1, end='')
        n -= 2
    print()
```
[1295B - Infinite Prefixes](../problems/B._Infinite_Prefixes.md "Educational Codeforces Round 81 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1295B - Infinite Prefixes](../problems/B._Infinite_Prefixes.md "Educational Codeforces Round 81 (Rated for Div. 2)")

Let's denote a prefix of length $i$ as $pref(i)$. We can note that each $pref(i) = k \cdot pref(n) + pref(i \mod n)$ where $k = \left\lfloor \frac{i}{n} \right\rfloor$ and $+$ is a concatenation. Then balance $bal(i)$ of prefix of length $i$ is equal to $k \cdot bal(n) + bal(i \mod n)$.

Now there two cases: $bal(n)$ is equal to $0$ or not. If $bal(n) = 0$ then if exist such $j$ ($0 \le j < n$) that $bal(j) = x$ then for each $k \ge 0$ $bal(j + kn) = x$ and answer is $-1$.

Otherwise, for each such $j$ there will no more than one possible $k$: since there are zero or one solution to the equation $bal(j) + k \cdot bal(n) = x$. The solution exists if and only if $x - bal(j) \equiv 0 \mod bal(n)$ and $k = \frac{x - bal(j)}{bal(n)} \ge 0$. So, just precalc $bal(n)$ and for each $0 \le j < n$ check the equation.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long li;

int n, x;
string s;

inline bool read() {
	if(!(cin >> n >> x >> s))
		return false;
	return true;
}

inline void solve() {
	int ans = 0;
	bool infAns = false;
	
	int cntZeros = (int)count(s.begin(), s.end(), '0');
	int total = cntZeros - (n - cntZeros);
	
	int bal = 0;
	for(int i = 0; i < n; i++) {
		if(total == 0) {
			if(bal == x)
				infAns = true;
		}
		else if(abs(x - bal) % abs(total) == 0) {
			if((x - bal) / total >= 0)
				ans++;
		}
		
		if(s[i] == '0')
			bal++;
		else
			bal--;
	}
	
	if(infAns) ans = -1;
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
		read();
		solve();
	}
	
	return 0;
}
```
[1295C - Obtain The String](../problems/C._Obtain_The_String.md "Educational Codeforces Round 81 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1295C - Obtain The String](../problems/C._Obtain_The_String.md "Educational Codeforces Round 81 (Rated for Div. 2)")

The answer is $-1$ when in string $t$ there is a character that is not in string $s$.

Otherwise let's precalculate the following array $nxt_{i, j}$ = minimum index $x$ from $i$ to $|s|$ such that $s_x = j$ (if there is no such index then $nxt_{i, j} = inf$).

Now we can solve this problem by simple greed. Presume that now $z = t_0 t_1 \dots t_{i-1}$, and last taken symbol in $s$ is $s_{pos}$. Then there are two options: 

1. if $nxt_{pos, i} \neq inf$, then $i = i + 1$, $pos = nxt_{pos+1, i}$;
2. if $nxt_{pos, i} = inf$, then $pos = 0$ and $ans = ans + 1$ ($ans$ is equal to $0$ initially);
 **Solution (Roms)**
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = int(2e5) + 99;
const int INF = int(1e9) + 99;

int tc;
string s, t;
int nxt[N][26];

int main() {
    cin >> tc;
    while(tc--){
        cin >> s >> t;
        for(int i = 0; i < s.size() + 5; ++i)
            for(int j = 0; j < 26; ++j)
                nxt[i][j] = INF;
    	
        for(int i = int(s.size()) - 1; i >= 0; --i){
            for(int j = 0; j < 26; ++j)
                nxt[i][j] = nxt[i + 1][j];
            nxt[i][s[i] - 'a'] = i;
        }    
    
        int res = 1, pos = 0;
        for(int i = 0; i < t.size(); ++i){
            if(pos == s.size()){
                pos = 0;
                ++res;
            }
            if(nxt[pos][t[i] - 'a'] == INF){
                pos = 0; 
                ++res;
    		}
    		if(nxt[pos][t[i] - 'a'] == INF && pos == 0){
                res = INF;
                break;
            }    
            pos = nxt[pos][t[i] - 'a'] + 1;
            
        }
    
        if(res >= INF) cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}
```
[1295D - Same GCDs](../problems/D._Same_GCDs.md "Educational Codeforces Round 81 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1295D - Same GCDs](../problems/D._Same_GCDs.md "Educational Codeforces Round 81 (Rated for Div. 2)")

The Euclidean algorithm is based on the next fact: if $a \ge b$ then $\gcd(a, b) = \gcd(a - b, b)$. So, if $(a + x) \ge m$ then $\gcd(a + x, m) = \gcd(a + x - m, m)$. So we can declare that we are looking at $m$ different integers $x' = (a + x) \mod m$ with $0 \le x' < m$, so all $x'$ forms a segment $[0, m - 1]$. So, we need to find the number of $x'$ ($0 \le x' < m$) such that $\gcd(x', m) = \gcd(a, m)$.

Let's denote $g = \gcd(a, m)$, then $a = ga'$ and $m = gm'$. So, $\gcd(a, m) = \gcd(ga', gm') = g \cdot \gcd(a', m') = g$ or $\gcd(a', m') = 1$. Since $\gcd(x', m) = \gcd(a, m) = g$ so we also can represent $x' = x^{"}g$ and, therefore $gcd(x^{"}, m') = 1$.

Since $0 \le x' < m$, then $0 \le x^{"} < m'$ or we need to calaculate the number of $x^{"}$ ($0 \le x^{"} < m'$) such that $\gcd(x^{"}, m') = 1$. Since $gcd(0, m') = m' > 1$ so we can consider $x^{"} \in [1, m' - 1]$ and this is the definition of Euler's totient function $\varphi(m')$ which is the answer.

Euler's totient function $\varphi(m')$ can be calculated using factorization of $m' = \prod\limits_{i=1}^{l}{p_i^{a_i}}$. Then $\varphi(m') = m' \prod\limits_{i=1}^{l}{(1 - \frac{1}{p_i})}$.

 **Solution (adedalic)**
```cpp
fun gcd(a : Long, b : Long) : Long {
    return if (a == 0L) b else gcd(b % a, a)
}
fun phi(a : Long) : Long {
    var (tmp, ans) = listOf(a, a)
    var d = 2L
    while (d * d <= tmp) {
        var cnt = 0
        while (tmp % d == 0L) {
            tmp /= d
            cnt++
        }
        if (cnt > 0) ans -= ans / d
        d++
    }
    if (tmp > 1L) ans -= ans / tmp
    return ans
}

fun main() {
    val t = readLine()!!.toInt()
    for (tc in 1..t) {
        val (a, m) = readLine()!!.split(' ').map { it.toLong() }
        println(phi(m / gcd(a, m)))
    }
}
```
[1295E - Permutation Separation](../problems/E._Permutation_Separation.md "Educational Codeforces Round 81 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1295E - Permutation Separation](../problems/E._Permutation_Separation.md "Educational Codeforces Round 81 (Rated for Div. 2)")

"All elements in the left set smaller than all elements in the right set" means that there is such value $val$ that all elements from the first set less than $val$ and all elements from the second set are more or equal to $val$. So let's make a sweep line on $val$ from $1$ to $n + 1$ while trying to maintain all answers for each prefix $pos$.

Let's maintain for each $pos$ the total cost $t[pos]$ to make sets "good" if we split the permutation $p$ on sets $[p_1, \dots, p_{pos}]$ and $[p_{pos} + 1, \dots, p_n]$ in such way that after transformations all elements in the first set less than $val$. It's easy to see that the total cost is equal to sum of weights $a_i$ where $i \le pos$ and $p_i \ge val$ and $a_i$ where $i > pos$ and $p_i < val$.

So what will happen if we increase $val$ by $1$? Let's define the position of $p_k = val$ as $k$. For each $pos \ge k$ we don't need to move $p_k$ to the second set anymore, so we should make $t[pos] -= a_k$. On the other hand, for each $pos < k$ we need to move $p_k$ from the second set to the first one now, so we should make $t[pos] += a_k$.

The answer will be equal to the $\min\limits_{1 \le pos < n}(t[pos])$. It means that we should handle two operations: add some value on the segment and ask minimum on the segment. So we can store all $t[pos]$ in pretty standart Segment Tree with "add on segment" and "minimum on segment" while iterating over $val$. So the total complexity is $O(n \log{n})$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = int(2e5) + 99;

int n;
int p[N];
int rp[N];
int a[N];

long long b[N];
long long t[4 * N];
long long add[4 * N];

void build(int v, int l, int r){
	if(r - l == 1){
		t[v] = b[l];
		return;
	}

	int mid = (l + r) / 2;	
	build(v * 2 + 1, l, mid);
	build(v * 2 + 2, mid, r);
	t[v] = min(t[v * 2 + 1], t[v * 2 + 2]); 
}

void push(int v, int l, int r){
	if(add[v] != 0){
		if(r - l > 1)
			for(int i = v+v+1; i < v+v+3; ++i){
				add[i] += add[v];
				t[i] += add[v];
			}
		add[v] = 0;
	}
}

void upd(int v, int l, int r, int L, int R, int x){
	if(L >= R) return;
	if(l == L && r == R){
		add[v] += x;
		t[v] += x;
		push(v, l, r);
		return;
	}
	
	push(v, l, r);
	int mid = (l + r) / 2;
	upd(v * 2 + 1, l, mid, L, min(mid, R), x);
	upd(v * 2 + 2, mid, r, max(mid, L), R, x);

	t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
}

void upd(int l, int r, int x){
	upd(0, 0, n, l, r, x);
}

long long get(int v, int l, int r, int L, int R){
	if(L >= R) return 1e18;

	push(v, l, r);
	if(l == L && r == R)
		return t[v];

	int mid = (l + r) / 2;
	return min(get(v * 2 + 1, l, mid, L, min(R, mid)), 
		   get(v * 2 + 2, mid, r, max(L, mid), R));		
}

long long get(int l, int r){
	return get(0, 0, n, l, r);
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", p + i);
        --p[i];
        rp[p[i]] = i;
	}
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);
	
	b[0] = a[0];
	for(int i = 1; i < n; ++i)
		b[i] = a[i] + b[i - 1];
	build(0, 0, n);
	
	long long res = get(0, n - 1);
	//for(int i = 0; i < n; ++i) cout << get(i, i+1) << ' ';cout << endl;
	for(int i = 0; i < n; ++i){
	    int pos = rp[i];
		upd(pos, n, -a[pos]);
		upd(0, pos, a[pos]);
		res = min(res, get(0, n - 1));
		//for(int i = 0; i < n; ++i) cout << get(i, i+1) << ' ';cout << endl;
	}
	
	cout << res << endl;
	return 0;
}
```
[1295F - Good Contest](../problems/F._Good_Contest.md "Educational Codeforces Round 81 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1295F - Good Contest](../problems/F._Good_Contest.md "Educational Codeforces Round 81 (Rated for Div. 2)")

Model solution (slow, complicated and not cool):

The naive solution is dynamic programming: let $dp_{i, x}$ be the probability that the first $i$ problems don't have any inversions, and the $i$-th one got $x$ accepted solutions. Let's somehow speed it up. For convenience, I will modify the variable denoting the maximum number of accepted solutions for each problem: $L_i = l_i$, $R_i = r_i + 1$; and I will also reverse the problem order, so that we don't want the number of solutions to decrease from problem to problem.

We know that $dp_{i, x} = \frac{1}{R_i - L_i} \sum\limits_{j = 0}^{x} dp_{i - 1, j}$, if $x \in [L_i, R_i)$, and $dp_{i, x} = 0$ otherwise. Let's divide the whole segment between $0$ and $998244351$ into $O(n)$ segments with the values of $L_i$ and $R_i$ and analyse the behavior of $dp$ values on each such segment.

Let $f_i(x) = dp_{i, x}$. If we consider the behavior of $f_i(x)$ on some segment we got, we can prove by induction that it is a polynomial of degree not exceeding $i$.

All that is left is to carefully calculate and maintain these polynomials on segments. The main thing we will use to calculate the polynomials is interpolation. To transition from $f_i$ to $f_{i + 1}$, we will consider each segment separately, calculate the first several values of $f_{i + 1}$ on each segment (we need to calculate the sum $\sum\limits_{x = L}^{R} P(x)$ fast, if $P(x)$ is a polynomial, this can also be done with interpolation), and then interpolate it on the whole segment.

This is actually slow (we have to interpolate at least $O(n^2)$ polynomials) and not easy to write. Let's consider a better solution.

Participants' solution (much faster and easier to code):

We will use combinatoric approach: instead of calculating probabilities, we will count all the non-descending sequences $(a_1, a_2, \dots, a_n)$ such that $i \in [L_i, R_i)$, and divide it by the number of all sequences without the non-descending condition (that is just $\prod_{i=1}^{n} R_i - L_i$).

Let's again divide $[0, 998244353]$ into $O(n)$ segments using the points $L_i$, $R_i$, and enumerate these segments from left to right. If there are two neighboring values $a_i$ and $a_{i + 1}$, they either belong to the same segment, or the segment $a_{i + 1}$ belongs to is to the right of the segment $a_i$ belongs to.

We could try to write the following dynamic programming solution: $cnt_{i, j}$ is the number of non-descending prefixes of the sequence such that there are $i$ elements in the prefix, and the last one belongs to segment $j$. It's easy to model transitions from $cnt_{i, j}$ to $cnt_{i + 1, k}$ where $k > j$, but we don't know how to model the transition to $cnt_{i + 1, j}$.

Let's get rid of them altogether! We will introduce an additional constraint in our dynamic programming: $cnt_{i, j}$ is the number of prefixes of the sequence of length $i$ such that all elements on prefix belong to one of the first $j$ segments, but next element should not belong to it. The transitions in this dynamic programming are different: we iterate on the number of elements $k$ belonging to the next segment and transition into $cnt_{i + k, j + 1}$ (if possible). Calculating the number of ways to take $k$ elements from an interval $[L, R)$ in sorted order can be reduced to calculating the number of ways to compose $k$ as the sum of $R - L$ non-negative summands (order matters). We should be able to calculate binomial coefficients with fairly large $n$ and not so large $k$, but that's not really hard if we use the formula $\binom{n}{k} = \binom{n}{k - 1} \cdot \frac{n - k + 1}{k}$. 

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

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
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

typedef vector<int> poly;

void norm(poly& p)
{
    while(p.size() > 0 && p.back() == 0)
        p.pop_back();
}

poly operator +(const poly& a, const poly& b)
{
    poly c = a;
    while(c.size() < b.size()) c.push_back(0);
    for(int i = 0; i < b.size(); i++) c[i] = add(c[i], b[i]);
    norm(c);
    return c;
}

poly operator +(const poly& a, int b)
{
    return a + poly(1, b);
}

poly operator +(int a, const poly& b)
{
    return b + a;
}

poly operator *(const poly& a, int b)
{
    poly c = a;                               
    for(int i = 0; i < c.size(); i++) c[i] = mul(c[i], b);
    norm(c);
    return c;
}

poly operator /(const poly& a, int b)
{   
    return a * inv(b);
}

poly operator *(const poly& a, const poly& b)
{
    poly c(a.size() + b.size() - 1);
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            c[i + j] = add(c[i + j], mul(a[i], b[j]));

    norm(c);
    return c;
}

poly interpolate(const vector<int>& x, const vector<int>& y)
{
    int n = int(x.size()) - 1;
    vector<vector<int> > f(n + 1);
    f[0] = y;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n - i; j++)
            f[i].push_back(divide(add(f[i - 1][j + 1], -f[i - 1][j]), add(x[i + j], -x[j])));
    
    poly cur = poly(1, 1);
    poly res;
    for(int i = 0; i <= n; i++)
    {
        res = res + cur * f[i][0];
        cur = cur * poly({add(0, -x[i]), 1});
    }

    return res;
}

int eval(const poly& a, int x)
{
    int res = 0;
    for(int i = int(a.size()) - 1; i >= 0; i--)
        res = add(mul(res, x), a[i]);
    return res;
}

poly sumFromL(const poly& a, int L, int n)
{
    vector<int> x;
    for(int i = 0; i <= n; i++)
        x.push_back(L + i);
    vector<int> y;
    int cur = 0;
    for(int i = 0; i <= n; i++)
    {
        cur = add(cur, eval(a, x[i]));
        y.push_back(cur);
    }
    return interpolate(x, y);
}

int sumOverSegment(const poly& a, int L, int R)
{
    return eval(sumFromL(a, L, a.size()), R - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> L(n), R(n);
    for(int i = 0; i < n; i++)
    {
        cin >> L[i] >> R[i];
        R[i]++;
    }
    reverse(L.begin(), L.end());
    reverse(R.begin(), R.end());

    vector<int> coord = {0, MOD - 2};
    for(int i = 0; i < n; i++)
    {
        coord.push_back(L[i]);
        coord.push_back(R[i]);
    }
    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());
    vector<int> cL = coord, cR = coord;
    cL.pop_back();
    cR.erase(cR.begin());
    int cnt = coord.size() - 1;
    vector<poly> cur(cnt);
    for(int i = 0; i < cnt; i++)
        if(cL[i] >= L[0] && cR[i] <= R[0])
            cur[i] = poly(1, inv(R[0] - L[0]));
    for(int i = 1; i < n; i++)
    {
        vector<poly> nxt(cnt);        
        int curSum = 0;
        for(int j = 0; j < cnt; j++)
        {
            nxt[j] = sumFromL(cur[j], cL[j], i) + curSum;
            curSum = add(curSum, sumOverSegment(cur[j], cL[j], cR[j]));    
        }
        for(int j = 0; j < cnt; j++)
            nxt[j] = nxt[j] * (cL[j] >= L[i] && cR[j] <= R[i] ? inv(R[i] - L[i]) : 0);
        cur = nxt;
    }
    int ans = 0;
    for(int i = 0; i < cnt; i++)
        ans = add(ans, sumOverSegment(cur[i], cL[i], cR[i]));

    cout << ans << endl;
}
```
