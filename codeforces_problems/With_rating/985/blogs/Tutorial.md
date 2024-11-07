# Tutorial

[985A - Chess Placing](../problems/A._Chess_Placing.md "Educational Codeforces Round 44 (Rated for Div. 2)")

 **Tutorial**
### [985A - Chess Placing](../problems/A._Chess_Placing.md "Educational Codeforces Round 44 (Rated for Div. 2)")

Firstly let's sort our array *p* (pay the attention that there are ![](images/a64c1b2df604f8cfa9acf6716a3cc1424488361e.png) elements in this array, not *n*). Then for 0-indexed array *p* answer will be equal to ![](images/f2cc6a8161ad380d32040a9d3940a6f3860b7a3c.png), where |*a* - *b*| is an absolute value of difference between *a* and *b*.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> pos(n / 2);
	for (int i = 0; i < n / 2; ++i)
		cin >> pos[i];
	sort(pos.begin(), pos.end());
	
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n / 2; ++i) {
		ans1 += abs(pos[i] - (i * 2 + 1));
		ans2 += abs(pos[i] - (i * 2 + 2));
	}
	
	cout << min(ans1, ans2) << endl;
	
	return 0;
}
```
[985B - Switches and Lamps](../problems/B._Switches_and_Lamps.md "Educational Codeforces Round 44 (Rated for Div. 2)")

 **Tutorial**
### [985B - Switches and Lamps](../problems/B._Switches_and_Lamps.md "Educational Codeforces Round 44 (Rated for Div. 2)")

Let's maintain an array *cnt* of size *m*, where *cnt**i* will be equal to the number of switches that are connected to the *i*-th lamp. Then answer will be "YES" if and only if there exists some switch such that for each lamp *i* that is connected to this switch *cnt**i* > 1. Otherwise the answer will be "NO".

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	vector<int> cnt(m);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '1') ++cnt[j];
	}
	
	for (int i = 0; i < n; ++i) {
		bool ok = true;
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '1' && cnt[j] == 1)
				ok = false;
		}
		if (ok) {
			puts("YES");
			return 0;
		}
	}
	
	puts("NO");
	
	return 0;
}
```
[985C - Liebig's Barrels](../problems/C._Liebig's_Barrels.md "Educational Codeforces Round 44 (Rated for Div. 2)")

 **Tutorial**
### [985C - Liebig's Barrels](../problems/C._Liebig's_Barrels.md "Educational Codeforces Round 44 (Rated for Div. 2)")

At first, sort all *a**i* in non-decreasing order.

Let *rg* be first position that *a**rg* > *a*1 + *l* (if *a**m* ≤ *a*1 + *l*, *rg* = *m* + 1). Then each barrel should have at least one stave from segment [1, *rg*). So if *rg* - 1 < *n* answer is 0.

Otherwise, for each *i* from 1 to *n* let's take no more than *k* smallest staves from this segment in the *i*-th barrel, but in such way, that there are at least *n* - *i* staves left for next barrels.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;

int n, k, l, m;
vector<li> a;

inline bool read() {
	if(!(cin >> n >> k >> l))
		return false;
	m = n * k;
	a.assign(m, 0);
	fore(i, 0, m)
		assert(scanf("%lld", &a[i]) == 1);
	return true;
}

inline void solve() {
	sort(a.begin(), a.end());
	int rg = int(upper_bound(a.begin(), a.end(), a[0] + l) - a.begin());
	
	if(rg < n) {
		puts("0");
		return;
	}
	li ans = 0;
	
	int u = 0;
	fore(i, 0, n) {
		ans += a[u++];
		
		fore(j, 0, k - 1) {
			if(rg - u > n - i - 1)
				u++;
			else
				break;
		}
	}
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
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
[985D - Sand Fortress](../problems/D._Sand_Fortress.md "Educational Codeforces Round 44 (Rated for Div. 2)")

 **Tutorial**
### [985D - Sand Fortress](../problems/D._Sand_Fortress.md "Educational Codeforces Round 44 (Rated for Div. 2)")

Let's consider the optimal answer to always look like *h*1 ≤ *h*2 ≤ ... ≤ *h**k* ≥ *h**k* + 1 ≥ ...

*k* will be the leftmost position of a pillar with maximum height. We will heavily use the fact that all integers from 1 to *h**k* - 1 appear in this sequence to the right of *k*.

If you are able to construct any answer, it is easy to rearrange it to this pattern: select the leftmost maximum *k*, sort [1..*k* - 1] in non-decreasing order and [*k* + 1..∞) in non-increasing order. Sorted sequence will also be valid.

Let a pyramid of height *k* be such a valid castle that it occupies exactly 2*k* - 1 consecutive spots and 1 = *h*1 < *h*2 < ... < *h**k* > *h**k* + 1 > ... > *h*2*k* - 1 = 1. Exactly *k*2 sand packs are required to build it.

At first let's solve the problem without even touching the fence. This won't always give the minimal answer but it'll help us further. Given some *k* you can build the pyramid of height *k* and get *n* - *k*2 sand packs left over. This can fit in exactly ![](images/82f756d940dca41c5a5154390d3eec050db9d518.png) pillars (you can place any pillar of height  ≤ *k* next to some pillar of the same height). That way we see that ![](images/91e6c8489436dce719b3657ddfcb86f621af4368.png). 

This function is non-increasing, let's show that for any *k* from 2 to ![](images/aaf0032769d151c2b4a3481b4b60e192c8f28819.png) *ans*(*k*) - *ans*(*k* - 1) is non-positive.

*ans*(*k*) - *ans*(*k* - 1) = ![](images/bb97743672d40cb7804e3e6934b504f9a2b761ef.png) = ![](images/ab25342443c2a7f2768e57642ee37664060e73e4.png) = ![](images/4ef37e95f0ad5b8805168711b847cd991616c273.png) = ![](images/1707a4191524b7593c2435f2f097620bd969cda7.png) = ![](images/123fa53e9751f83eee3e10c3f7cb77737e5e1345.png) = ![](images/579bb1c727cf8c94b928f4e370101a6b5c1f83ff.png). 

![](images/55c07a8ba0b41992f2702408d9821b1727b02e9c.png) ![](images/8774ca35b6e628888a4670e4539d47857e5e5841.png) (*n* + *k*)(*k* - 1) ≤ *nk* + *k*(*k* - 1) - 1 ![](images/8774ca35b6e628888a4670e4539d47857e5e5841.png) *nk* - *n* + *k*2 - *k* ≤ *nk* + *k*2 - *k* - 1 ![](images/8774ca35b6e628888a4670e4539d47857e5e5841.png) *n* ≥ 1.

Now we can show that it is always optimal to push the initial pyramid to the left as far as possible, probably removing some pillars on positions less than *k*. That way the leftmost pillar will have height *h*1 = *min*(*k*, *H*). The total number of sand packs required to build it is ![](images/126f87a36b27ef1ac7c5339d46496e7bb3b03a52.png). This pattern will also include all the integers from 1 to *k* and will have the minimal width you can achieve. Monotonicity of this function can be proven in the similar manner.

Finally, the answer can be calculated using the following algorithm:

1. Find the maximum *k* such that ![](images/01535cb4710389dc0a7eb06a0fdfd0b983e6873b.png), where *h*1 = *min*(*k*, *H*). Solve the equation or just do the binary search;
2. Output the width of resulting truncated pyramid plus the minimal number of additional pillars it will take to distribute leftover sand packs.

You should also take into consideration the upper bound on *k* to avoid multiplying huge numbers. It's about ![](images/5a721eaeca29e78b6228355588c4b4c108abb4d7.png), so 64-bit integer type will be enough for all the calculations.

Overall complexity: *O*(1) or ![](images/21cdfc8587975fb007b82c9da4f34241b79b0d6c.png).

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;

using namespace std;

const int INF = 2e9;
li n, h;

bool check(li maxh){
	li k = min(h, maxh);
	li cnt = maxh * maxh - k * (k - 1) / 2;
	return (cnt <= n);
}

li get(li maxh){
	li k = min(h, maxh);
	li cnt = maxh * maxh - k * (k - 1) / 2;
	li len = (2 * maxh - 1) - (k - 1);
	n -= cnt;
	return len + (n + maxh - 1) / maxh;
}

int main() {
	scanf("%lld%lld", &n, &h);
	li l = 1, r = INF;
	
	while (l < r - 1){
		li m = (l + r) / 2;
		
		if (check(m))
			l = m;
		else
			r = m;
	}
	
	printf("%lldn", check(r) ? get(r) : get(l));
	return 0;
}
```
[985E - Pencils and Boxes](../problems/E._Pencils_and_Boxes.md "Educational Codeforces Round 44 (Rated for Div. 2)")

 **Tutorial**
### [985E - Pencils and Boxes](../problems/E._Pencils_and_Boxes.md "Educational Codeforces Round 44 (Rated for Div. 2)")

At first you need to sort the sequence. Then if there exists some answer, there also exists an answer such that every box in it contains some segment of pencils.

Now it's pretty standard dp approach. Let *dp**i* be 1 if it's possible to distribute the first *i* pencils into boxes correctly, 0 otherwise, *dp*0 = 1 initially. Now you can come up with straightforward *O*(*n*2) implementation. Let's iterate over every ![](images/ddf9f786b0ff69667adb30f2a82bfead21f36c17.png) and set *dp**i* + 1 to 1 if for some *j* *dp**j* = 1, *i* - *j* + 1 ≥ *k* and *a**i* - *a**j* ≤ *d*.

Now we should optimize it a bit. Notice that the second and the third conditions actually form some segment of indices. You need to check if there is at least one 1 value on this segment. This can be maintained with two pointers, set, BIT, segment tree. Anything you can code to get update in point and sum/max on segment queries. 

Overall complexity: ![](images/4b2fa1e3d3d43bd9f28ff6c3140f816dc0e0621a.png).

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); i++) 

const int N = 500 * 1000 + 13;

int f[N];

void upd(int x){
    for (int i = x; i < N; i |= i + 1)
        ++f[i];
}

int sum(int x){
    int res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        res += f[i];
    return res;
}

int get(int l, int r){
	if (l > r) return 0;
	return sum(r) - sum(l - 1);
}

int main(){
	int n, k, dif;
	scanf("%d%d%d", &n, &k, &dif);
	vector<int> a(n);
	forn(i, n)
		scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	
	vector<int> dp(n + 1, 0);
	
	dp[0] = 1;
	upd(0);
	
	int l = 0;
	forn(i, n){
		while (l < i && a[i] - a[l] > dif)
			++l;
		dp[i + 1] = (get(l, i - k + 1) >= 1);
		if (dp[i + 1]) upd(i + 1);
	}
	
	puts(dp[n] ? "YES" : "NO");
}
```
[985F - Isomorphic Strings](../problems/F._Isomorphic_Strings.md "Educational Codeforces Round 44 (Rated for Div. 2)")

 **Tutorial**
### [985F - Isomorphic Strings](../problems/F._Isomorphic_Strings.md "Educational Codeforces Round 44 (Rated for Div. 2)")

Yes, authors also implemented hashes.

Note that if substrings *s* and *t* are isomophic, then position *pos* of first encounter of some character *s**i* in *s* must be position of first encounter of some character *t**j* in *t*. More over, if we sort all positions *pos**i**s* for all distict characters in *s* and sort all positions *pos**j**t* for *t*, then *pos**i**s* must be equal *pos**i**t* for any *i*. This observation gives us fact, that *f*(*s*[*pos**i**s*]) = *t*[*pos**i**t*].

So, to check isomorphism of *s* and *t* we need check for each *i*, that positions of all encounters of character *s*[*pos**i**s*] equal to posistions of all encounters of character *t*[*pos**i**t*].

To do that we can generate for each character boolean array with checked positions of its encounter and calculate prefix hashes on this arrays. Also we need precalculate order of first encounters *ord**k* for each suffix of string *s*. To do it fast note that in transition from *ord**k* + 1 to *ord**k* only *s**k* can change its relative order.

Result complexity is *O*(*n*·*A*) with quite big constant from hashing.

 **Solution (adedalic)**
```cpp
#include <bits/stdc++.h>

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int(a.size())

#define x first
#define y second

using namespace std;

const int B = 2;

typedef array<int, B> ht;

ht MOD, BASE;

inline int norm(int a, const int &MOD) {
	while(a >= MOD)
		a -= MOD;
	while(a < 0)
		a += MOD;
	return a;
}

inline int mul(int a, int b, const int &MOD) {
	return int(a * 1ll * b % MOD);
}

inline ht operator +(const ht &a, const ht &b) {
	ht ans;
	fore(i, 0, sz(ans))
		ans[i] = norm(a[i] + b[i], MOD[i]);
	return ans;
}

inline ht operator -(const ht &a, const ht &b) {
	ht ans;
	fore(i, 0, sz(ans))
		ans[i] = norm(a[i] - b[i], MOD[i]);
	return ans;
}

inline ht operator *(const ht &a, const ht &b) {
	ht ans;
	fore(i, 0, sz(ans))
		ans[i] = mul(a[i], b[i], MOD[i]);
	return ans;
}

int CMODS[] = {int(1e9) + 7, int(1e9) + 9, int(1e9) + 21, int(1e9) + 33, int(1e9) + 87, int(1e9) + 93, int(1e9) + 97, int(1e9) + 103};
int CBASE[] = {1009, 1013, 1019, 1021};

const int N = 200 * 1000 + 555;

int n, m;
char s[N];
int x[N], y[N], len[N];

inline bool read() {
	if(!(cin >> n >> m))
		return false;
	assert(scanf("%s", s) == 1);
	
	fore(i, 0, m) {
		assert(scanf("%d%d%d", &x[i], &y[i], &len[i]) == 3);
		x[i]--, y[i]--;
	}
	return true;
}
void setMods() {
	mt19937 rnd;
	unsigned int seed = n;
	fore(i, 0, n)
		seed = (seed * 3) + s[i];
	fore(i, 0, m) {
		seed = (seed * 3) + x[i];
		seed = (seed * 3) + y[i];
		seed = (seed * 3) + len[i];
	}
	rnd.seed(seed);
	
	set<int> mids;
	while(sz(mids) < sz(MOD))
		mids.insert(rnd() % 8);
	vector<int> vmids(mids.begin(), mids.end());
	fore(i, 0, sz(MOD)) {
		MOD[i] = CMODS[vmids[i]];
		BASE[i] = CBASE[i];
	}
}

ht pBase[N];
ht ph[27][N];
vector<int> ord[N];

ht getHash(int id, int l, int r) {
	return ph[id][r] - ph[id][l] * pBase[r - l];
}

inline void solve() {
	setMods();
	
	pBase[0] = {1, 1};
	fore(i, 1, N)
		pBase[i] = pBase[i - 1] * BASE;
		
	fore(c, 0, 26) {
		ph[c][0] = {0, 0};
		fore(i, 0, n) {
			int val = (s[i] == c + 'a');
			ph[c][i + 1] = ph[c][i] * BASE + ht{val, val};
		}
	}
	
	vector<int> curOrd(26, 0);
	iota(curOrd.begin(), curOrd.end(), 0);
	for(int i = n - 1; i >= 0; i--) {
		ord[i] = curOrd;
		auto it = find(ord[i].begin(), ord[i].end(), int(s[i] - 'a'));
		ord[i].erase(it);
		ord[i].insert(ord[i].begin(), int(s[i] - 'a'));
		curOrd = ord[i];
	}
	
	fore(q, 0, m) {
		int s1 = x[q], s2 = y[q];
		bool ok = true;
		
		fore(i, 0, 26) {
			if(getHash(ord[s1][i], s1, s1 + len[q]) != 
				getHash(ord[s2][i], s2, s2 + len[q])) {
				ok = false;
				break;
			}
		}
		puts(ok ? "YES" : "NO");
	}
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	if(read()) {
		solve();
	}
	return 0;
}
```
[985G - Team Players](../problems/G._Team_Players.md "Educational Codeforces Round 44 (Rated for Div. 2)")

 **Tutorial**
### [985G - Team Players](../problems/G._Team_Players.md "Educational Codeforces Round 44 (Rated for Div. 2)")

Let's solve this task in several steps.

At first, let's calculate allall — sum of all triples. For each player ii consider three cases: 

* j<k<ij<k<i — there are exactly (i2)(i2) ways to choose triple;
* j<i<kj<i<k — there are i⋅(n−i−1)i⋅(n−i−1) ways;
* i<j<ki<j<k — there are (n−i−12)(n−i−12) ways.

At second, let's calculate sub1sub1 — sum over all triples j<k<ij<k<i such that exists pair (j,i)(j,i) or (k,i)(k,i). To calculate it we need for each ii iterate over all neighbors x<ix<i of ii. Again some cases: 

* if x=j<k<ix=j<k<i then there are exactly (i−j−1)(i−j−1) ways to choose kk;
* if j<x=k<ij<x=k<i, there are xx ways to choose jj.

 But we calculated some triples twice, so we need to subtract triples j<k<ij<k<i where both (j,i)(j,i) and (k,i)(k,i) exists. It is easy to calculate sorting adjacency lists of all ii.At third, let's calculate sub2sub2 — sum over all triple j<k<ij<k<i where exists pair (j,k)(j,k), but pairs (j,i)(j,i) and (k,i)(k,i) are not. sub2=sub02−sub12−sub22+sub122sub2=sub20−sub21−sub22+sub212. 

* sub02sub20 is a sum of all triples j<k<ij<k<i where pair (j,k)(j,k) exists. It can be calculated while iterating ii in increasing order.
* sub12sub21 is a sum of all triples j<k<ij<k<i where pairs (j,k)(j,k) and (j,i)(j,i) exists. It can be calculated while iterating (j,i)(j,i) and asking sum on segment of adjacency list of jj (O(1)O(1) with prefix sums for each vertex jj).
* sub22sub22 is a sum of all triples j<k<ij<k<i where pairs (j,k)(j,k) and (k,i)(k,i) exists. It can be calculated while iterating (k,i)(k,i) and asking sum on prefix of adjacency list of kk (same O(1)O(1)).
* sub122sub212 is a sum of all triples j<k<ij<k<i where all pairs (j,k)(j,k), (j,i)(j,i) and (k,i)(k,i) exists. It is modification of calculating number of triangles in graph. It can be done in O(MM−−√)O(MM) and will be explained below.

Then result res=all−sub1−sub2res=all−sub1−sub2.

The algorithm of finding all triangles in the given graph GG is following:

Let's call vertex heavy if |G(v)|≥M−−√|G(v)|≥M and light otherwise. For each heavy vertex vv precalculate hasv[i]hasv[i] — boolean array of adjacency of vertex vv. It's cost O(NM−−√)O(NM) of memory and time but memory can be reduced by using bitsets.

To calculate number of triangles j<k<ij<k<i let's iterate over ii. There are two cases: 

* if ii is heavy, then just iterate over all edges (j,k)(j,k) and check hasi[j]hasi[j] and hasi[k]hasi[k]. This part works with O(MM−−√)O(MM) time since there are O(M−−√)O(M) heavy vertices.
* if ii is light, then iterate over all pair (j,k)(j,k), where j,k∈G(i)j,k∈G(i) (at first fix kk, then iterate j<kj<k). To check existence of edge (j,k)(j,k) consider two more cases:
	+ if kk is heavy, just check hask[j]hask[j]. It works in O(1)O(1).
	+ if kk is light, just check in some global array curHascurHas all neighbors of kk, check all jj with curHas[j]curHas[j] and uncheck neighbors of kk. Checking in array curHascurHas require O(|G(k)|)O(|G(k)|) time and will be done O(|G(k)|)O(|G(k)|) times. So it will be O(∑|G(v)|2)=O(M−−√∑|G(v)|)=O(MM−−√)O(∑|G(v)|2)=O(M∑|G(v)|)=O(MM) in total. Similarly, iterating pairs j,k∈G(i)j,k∈G(i) works with O(∑|G(i)|2)=O(MM−−√)O(∑|G(i)|2)=O(MM) in total.

So comlexity of algorithm and all task is O(MM−−√)O(MM).

 **Solution (adedalic)**
```cpp
#include <bits/stdc++.h>

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int(a.size())

using namespace std;

typedef unsigned long long uli;

const int N = 200 * 1000 + 555;

int n, m;
uli a, b, c;
vector<int> g[N];

inline bool read() {
	if(!(cin >> n >> m))
		return false;
	assert(cin >> a >> b >> c);
	fore(i, 0, m) {
		int u, v;
		assert(scanf("%d%d", &u, &v) == 2);
		
		g[u].push_back(v);
		g[v].push_back(u);
	}
	return true;
}

vector<uli> ps[N];

inline uli getSum(int v, int l, int r) {
	return ps[v][r] - ps[v][l];
}

const int MX = 700;
int id[N];

const int B = 1111;
bitset<N> has[B];
int szh = 0;

inline void solve() {
	memset(id, -1, sizeof id);
	szh = 0;
	fore(v, 0, n) {
		sort(g[v].begin(), g[v].end());
		
		ps[v].assign(sz(g[v]) + 1, 0);
		fore(i, 0, sz(g[v]))
			ps[v][i + 1] = ps[v][i] + g[v][i];
		
		if(sz(g[v]) >= MX) {
			assert(szh < B);
			id[v] = szh++;
			
			for(int to : g[v])
				has[id[v]][to] = 1;
		}
	}
	
	uli all = 0;
	fore(v, 0, n) {
		uli lw = v, gr = n - v - 1;
		all += a * v * (gr * (gr - 1) / 2);
		all += b * v * (lw * gr);
		all += c * v * (lw * (lw - 1) / 2);
	}
	
	uli sub1 = 0;
	fore(v, 0, n) {
		for(int to : g[v]) {
			if(to > v)
				break;
			
			uli cnt = to;
			uli sum = cnt * (cnt - 1) / 2;
			sub1 += a * sum + cnt * (b * to + c * v);
			
			cnt = v - to - 1;
			sum = (2 * to + cnt + 1) * cnt / 2;
			sub1 += b * sum + cnt * (a * to + c * v);
		}
		
		uli sum = 0;
		fore(i, 0, sz(g[v])) {
			if(g[v][i] > v)
				break;
			
			uli cnt = i;
			sub1 -= a * sum + cnt * (b * g[v][i] + c * v);
			sum += g[v][i];
		}
	}
	all -= sub1;
	
	uli sub2 = 0;
	uli cntE = 0, sumE = 0;
	fore(v, 0, n) {
		sub2 += sumE + cntE * c * v;
		for(int to : g[v]) {
			if(to > v)
				break;
			
			cntE++;
			sumE += a * to + b * v;
		}
	}
	
	fore(v, 0, n) {
		for(int to : g[v]) {
			if(to > v)
				break;
			
			int pos = int(lower_bound(g[to].begin(), g[to].end(), to) - g[to].begin());
			sub2 -= a * getSum(to, 0, pos) + pos * (b * to + c * v);
			
			int pos2 = int(lower_bound(g[to].begin(), g[to].end(), v) - g[to].begin());
			sub2 -= b * getSum(to, pos, pos2) + (pos2 - pos) * (a * to + c * v);
		}
	}
	
	vector<char> curh(n + 5, 0);
	fore(v, 0, n) {
		if(id[v] == -1) {
			fore(i2, 0, sz(g[v])) {
				int u2 = g[v][i2];
				if(u2 > v)
					break;
				
				if(id[u2] != -1) {
					fore(i1, 0, i2) {
						int u1 = g[v][i1];
						if(has[id[u2]][u1])
							sub2 += a * u1 + b * u2 + c * v;
					}
				} else {
					for(int to : g[u2]) {
						if(to > u2)
							break;
						curh[to] = 1;
					}
					fore(i1, 0, i2) {
						int u1 = g[v][i1];
						if(curh[u1])
							sub2 += a * u1 + b * u2 + c * v;
					}
					for(int to : g[u2]) {
						if(to > u2)
							break;
						curh[to] = 0;
					}
				}
			}
		} else {
			fore(u2, 0, v) {
				if(!has[id[v]][u2])
					continue;
				for(int u1 : g[u2]) {
					if(u1 > u2)
						break;
					if(has[id[v]][u1])
						sub2 += a * u1 + b * u2 + c * v;
				}
			}
		}
	}
	all -= sub2;
	cout << all << endl;
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	cout << fixed << setprecision(10);

	if(read()) {
		solve();
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
#endif
	}
	return 0;
}
```
