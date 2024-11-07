# Tutorial_(ru)

[1096A - Find Divisible](../problems/A._Find_Divisible.md "Educational Codeforces Round 57 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (PikMike)**
```cpp
T = int(input())
for i in range(T):
	l, r = map(int, input().split())
	print(l, l * 2)
```
[1096B - Substring Removal](../problems/B._Substring_Removal.md "Educational Codeforces Round 57 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	string s;
	cin >> n >> s;
	int cntl = 0, cntr = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == s[0]) {
			++cntl;
		} else {
			break;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == s[n - 1]) {
			++cntr;
		} else {
			break;
		}
	}
	if (s[0] == s[n - 1]) {
		cout << ((cntl + 1) * 1ll * (cntr + 1)) % 998244353 << endl;
	} else {
		cout << (cntl + cntr + 1) % 998244353;
	}
	
	return 0;
}
```
[1096C - Polygon for the Angle](../problems/C._Polygon_for_the_Angle.md "Educational Codeforces Round 57 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

int ang;

inline bool read() {
	if(!(cin >> ang))
		return false;
	return true;
}

inline void solve() {
	int g = __gcd(ang, 180);
	int k = ang / g;
	int n = 180 / g;
	
	if(k + 1 == n)
		k *= 2, n *= 2;
	cout << n << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	cout << fixed << setprecision(15);
	
	int tc; cin >> tc;
	while(tc--) {
		assert(read());
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
[1096D - Easy Problem](../problems/D._Easy_Problem.md "Educational Codeforces Round 57 (Rated for Div. 2)")

 **Tutorial**
### [1096D - Easy Problem](../problems/D._Easy_Problem.md "Educational Codeforces Round 57 (Rated for Div. 2)")

Denote string $t$ as hard.

We will solve this problem with dynamic programming. 

Denote $dp_{cnt, len}$ — the minimum possible ambiguity if we considered first $cnt$ letters of statement and got prefix $t$ having length $len$ as a subsequence of the string.

If $cnt$-th letter of the statement is not equal to $t_{len}$, then $dp_{cnt, len} = dp_{cnt-1, len}$ — we don't have to change it.

Otherwise we either change the letter, or let it stay as it is (and the length of the prefix we found so far increases): $dp_{cnt, len} = \min (dp_{cnt-1, len-1}, dp_{cnt-1, len} + a_{cnt-1})$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 100 * 1000 + 13;
const long long INF64 = 1e18;

int n;
string s;
int a[N];
long long dp[N][5];

const string h = "hard";

int main() {
	scanf("%d", &n);
	static char buf[N];
	scanf("%s", buf);
	s = buf;
	forn(i, n)
		scanf("%d", &a[i]);
	
	forn(i, N) forn(j, 5) dp[i][j] = INF64;
	dp[0][0] = 0;
	forn(i, n) forn(j, 4){
		dp[i + 1][j + (s[i] == h[j])] = min(dp[i + 1][j + (s[i] == h[j])], dp[i][j]);
		dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i]);
	}
	
	printf("%lldn", *min_element(dp[n], dp[n] + 4));
	return 0;
}
```
[1096E - The Top Scorer](../problems/E._The_Top_Scorer.md "Educational Codeforces Round 57 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int MOD = 998244353;
const int N = 10 * 1000 + 7;
const int M = 100 + 7;

int fact[N], rfact[N];

int add(int a, int b){
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}

int mul(int a, int b){
	return (a * 1ll * b) % MOD;
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

int cnk(int n, int k){
	if (n == k) return 1;
	if (k < 0 || k > n) return 0;
	return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int g(int s, int p, int m){
	int res = 0;
	forn(i, p + 1)
		res = add(res, mul(i & 1 ? MOD - 1 : 1, mul(cnk(p, i), cnk(s + p - 1 - i * (m + 1), p - 1))));
	return res;
}

int inv(int x){
	return mul(rfact[x], fact[x - 1]);
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < N; ++i) fact[i] = mul(fact[i - 1], i);
	rfact[N - 1] = binpow(fact[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; --i) rfact[i] = mul(rfact[i + 1], i + 1);
	
	int p, s, r;
	scanf("%d%d%d", &p, &s, &r);
	
	int Q = cnk(s - r + p - 1, p - 1);
	int P = 0;
	for (int t = r; t <= s; ++t) for (int q = 1; q <= p; ++q)
		P = add(P, mul(mul(cnk(p - 1, q - 1), inv(q)), g(s - q * t, p - q, t - 1)));
	
	printf("%dn", mul(P, binpow(Q, MOD - 2)));
	return 0;
}
```
[1096F - Inversion Expectation](../problems/F._Inversion_Expectation.md "Educational Codeforces Round 57 (Rated for Div. 2)")

 **Tutorial**
### [1096F - Inversion Expectation](../problems/F._Inversion_Expectation.md "Educational Codeforces Round 57 (Rated for Div. 2)")

Let's break the problem into four general cases.

* Case 1. Inversions between two unknown numbers. Each pair of numbers can either be or inversion or not and the number of permutations for both cases is the same. Thus, the expected value of that is $\frac{cnt(-1) \cdot (cnt(-1) - 1)}{2} \cdot \frac 1 2$.
* Case 2 and 3. Inversions between the known and unknown number. Let's check the case with left number being unknown and right being known. The opposite will be done similarly. For each known number calculate the number of unknowns to the left of it $lft_x$ and the total number of unknowns greater than it $gt_x$. Then you'll need to put a greater number out of all possible to make an inversion. Add $lft_x \cdot \frac{gt_x}{cnt(-1)}$ to the answer.
* Case 4. Inversions between two known numbers. Just calculate that number ignoring all $-1$ and add it to answer.

Overall complexity: $O(n \log n)$ (for the lase case, all others are done in $O(n)$).

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;
const int MOD = 998244353;

int n;
int p[N];
bool used[N];
int gt[N];

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int mul(int a, int b){
	return (a * 1ll * b) % MOD;
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

int f[N];

void upd(int x){
	for (int i = x; i < N; i |= i + 1)
		++f[i];
}

int get(int x){
	int sum = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		sum += f[i];
	return sum;
}

int main() {
	scanf("%d", &n);
	forn(i, n){
		scanf("%d", &p[i]);
		if (p[i] != -1)
			used[p[i]] = true;
	}
	
	int cur = 0;
	for (int i = n; i >= 1; --i){
		gt[i] = cur;
		cur += !used[i];
	}
	
	// case 1
	int ans = mul(mul(cur, cur - 1), binpow(4, MOD - 2));
	
	int inv = binpow(cur, MOD - 2);
	
	// case 2
	int lft = 0;
	forn(i, n){
		if (p[i] == -1)
			++lft;
		else
			ans = add(ans, mul(lft, mul(gt[p[i]], inv)));
	}
	
	// case 3
	int rgh = 0;
	for (int i = n - 1; i >= 0; --i){
		if (p[i] == -1)
			++rgh;
		else
			ans = add(ans, mul(rgh, mul(cur - gt[p[i]], inv)));
	}
	
	// case 4	
	int tmp = 0;
	forn(i, n) if (p[i] != -1){
		ans = add(ans, tmp - get(p[i]));
		upd(p[i]);
		++tmp;
	}
	
	printf("%dn", ans);
	return 0;
}
```
[1096G - Lucky Tickets](../problems/G._Lucky_Tickets.md "Educational Codeforces Round 57 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution 1 (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

#define mp make_pair
#define pb push_back

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}

template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

const int N = 2500 * 1000 + 555;
const int LOGN = 22;

const int MOD = 998244353;
int g = 3;

inline int mul(int a, int b){
	return int(a * 1ll * b % MOD);
}

inline int norm(int a) {
	if(a >= MOD)
		a -= MOD;
	if(a < 0)
		a += MOD;
	return a;
}

inline int binPow(int a, int k) {
	int ans = 1;
	while(k > 0) {
		if(k & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		k >>= 1;
	}
	return ans;
}

inline int inv(int a) {
	return binPow(a, MOD - 2);
}

vector<int> w[LOGN];
vector<int> rv[LOGN];

void precalc() {
    int wb = binPow(g, (MOD - 1) / (1 << LOGN));

    for(int st = 0; st < LOGN - 1; st++) {
        w[st].assign(1 << st, 1);

        int bw = binPow(wb, 1 << (LOGN - st - 1));
        int cw = 1;

        for (int k = 0; k < (1 << st); k++) {
            w[st][k] = cw;
            cw = mul(cw, bw);
        }
    }
    for(int st = 0; st < LOGN; st++) {
        rv[st].assign(1 << st, 0);

        if(st == 0) {
            rv[st][0] = 0;
            continue;
        }
        int h = (1 << (st - 1));
        for(int k = 0; k < (1 << st); k++)
            rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
    }
}

inline void fft(int a[N], int n, bool inverse) {
    int ln = 0;
    while((1 << ln) < n)
        ln++;

    assert((1 << ln) < N);
    n = (1 << ln);

    forn(i, n) {
        int ni = rv[ln][i];
        if(i < ni)
            swap(a[i], a[ni]);
    }

    for(int st = 0; (1 << st) < n; st++) {
        int len = (1 << st);
        for(int k = 0; k < n; k += (len << 1)) {
            for(int pos = k; pos < k + len; pos++) {
                int l = a[pos];
                int r = mul(a[pos + len], w[st][pos - k]);

                a[pos] = norm(l + r);
                a[pos + len] = norm(l - r);
            }
        }
    }

    if(inverse) {
        int in = inv(n);
        forn(i, n)
            a[i] = mul(a[i], in);
        reverse(a + 1, a + n);
    }
}

int aa[N], bb[N], cc[N];

inline vector<int> multiply(const vector<int> a, const vector<int> b) {
	int ln = 1;
	while(ln < (sz(a) + sz(b)))
		ln <<= 1;
		
	forn(i, ln)
		aa[i] = (i < sz(a) ? a[i] : 0);
		
	forn(i, ln)
		bb[i] = (i < sz(b) ? b[i] : 0);
		
	fft(aa, ln, false);
	fft(bb, ln, false);
	
	forn(i, ln)
		cc[i] = mul(aa[i], bb[i]);
		
	fft(cc, ln, true);
	
	vector<int> c(ln, 0);
	forn(i, sz(c))
		c[i] = cc[i];
	
	while(sz(c) > 1 && c.back() == 0)
		c.pop_back();
	return c;
}

int n, k, a[11];

inline bool read() {
	if(!(cin >> n >> k))
		return false;
	forn(i, k)
		cin >> a[i];
	return true;
}

inline void solve() {
	sort(a, a + k);
	
	vector<int> ans(1, 1);
	vector<int> f(10, 0);
	forn(i, k)
		f[a[i]] = 1;

	precalc();
		
	int pw = n / 2;
	while(pw > 0) {
		if(pw & 1)
			ans = multiply(ans, f);
		f = multiply(f, f);
		pw >>= 1;
	}
	
	int res = 0;
	forn(i, sz(ans))
		res = norm(res + mul(ans[i], ans[i]));
	cout << res << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
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
 **Solution 2 (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int LOGN = 21;
const int N = (1 << LOGN);
const int MOD = 998244353;
const int g = 3;

#define forn(i, n) for(int i = 0; i < int(n); i++)

inline int mul(int a, int b)
{
	return (a * 1ll * b) % MOD;
}

inline int norm(int a) 
{
	while(a >= MOD)
		a -= MOD;
	while(a < 0)
		a += MOD;
	return a;
}

inline int binPow(int a, int k) 
{
	int ans = 1;
	while(k > 0) 
	{
		if(k & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		k >>= 1;
	}
	return ans;
}

inline int inv(int a) 
{
	return binPow(a, MOD - 2);
}

vector<int> w[LOGN];
vector<int> iw[LOGN];
vector<int> rv[LOGN];

void precalc() 
{
	int wb = binPow(g, (MOD - 1) / (1 << LOGN));
	
	for(int st = 0; st < LOGN; st++) 
	{
		w[st].assign(1 << st, 1);
		iw[st].assign(1 << st, 1);
		
		int bw = binPow(wb, 1 << (LOGN - st - 1));
		int ibw = inv(bw);
		
		int cw = 1;
		int icw = 1;
		
		for(int k = 0; k < (1 << st); k++) 
		{
			w[st][k] = cw;
			iw[st][k] = icw;
			
			cw = mul(cw, bw);
			icw = mul(icw, ibw);
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

inline void fft(int a[N], int n, int ln, bool inverse) 
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
				int l = a[pos];
				int r = mul(a[pos + len], (inverse ? iw[st][pos - k] : w[st][pos - k]));
				
				a[pos] = norm(l + r);
				a[pos + len] = norm(l - r);
			}
		}
	}
	
	if(inverse) 
	{
		int in = inv(n);
		for(int i = 0; i < n; i++)
			a[i] = mul(a[i], in);
	}
}

int aa[N], bb[N], cc[N];

inline void multiply(int a[N], int sza, int b[N], int szb, int c[N], int &szc) 
{
	int n = 1, ln = 0;
	while(n < (sza + szb))
		n <<= 1, ln++;
	for(int i = 0; i < n; i++)
		aa[i] = (i < sza ? a[i] : 0);
	for(int i = 0; i < n; i++)
		bb[i] = (i < szb ? b[i] : 0);
		
	fft(aa, n, ln, false);
	fft(bb, n, ln, false);
	
	for(int i = 0; i < n; i++)
		cc[i] = mul(aa[i], bb[i]);
		
	fft(cc, n, ln, true);
	
	szc = n;
	for(int i = 0; i < n; i++)
		c[i] = cc[i];
}

vector<int> T[N];

int a[N];
int b[N];
int c[N];

#define sz(a) (int(a.size()))

int main()
{
	precalc();
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; i++)
	{
	    int x;
	    scanf("%d", &x);
	    a[x] = 1;
	}
	int nn = 1, ln = 0;
	int nw = (n * 5) + 1;
	while(nn < nw)
	{
		nn *= 2;
		ln++;
	}
	fft(a, nn, ln, false);
	forn(i, nn)
		a[i] = binPow(a[i], n / 2);
	fft(a, nn, ln, true);
	int ans = 0;
	forn(i, nn)
		ans = norm(ans + binPow(a[i], 2));
	printf("%dn", ans);
	return 0;	
}
```
