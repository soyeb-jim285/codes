# Tutorial

[1093A - Dice Rolling](../problems/A._Dice_Rolling.md "Educational Codeforces Round 56 (Rated for Div. 2)")

 **Tutorial**
### [1093A - Dice Rolling](../problems/A._Dice_Rolling.md "Educational Codeforces Round 56 (Rated for Div. 2)")

It is enough to print ⌊xi2⌋ for each query, where ⌊xy⌋ is x divided by y rounded down.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int x;
		cin >> x;
		cout << x / 2 << endl;
	}
	return 0;
}
```
[1093B - Letters Rearranging](../problems/B._Letters_Rearranging.md "Educational Codeforces Round 56 (Rated for Div. 2)")

 **Tutorial**
### [1093B - Letters Rearranging](../problems/B._Letters_Rearranging.md "Educational Codeforces Round 56 (Rated for Div. 2)")

The only case when the answer is -1 is when all letters of the string are equal. Why is it so? Because if we have at least two different letters we can place the first one at the first position of the string and the second one at the last position of the string. Then it is clearly that the obtained string is good. We can implement this solution by the following way: sort si and if si,1=si,|si| (the first letter equals to the last one) then the answer is -1 otherwise the answer is si.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		if (s[0] == s.back()) cout << -1 << endl;
		else cout << s << endl;
	}
	return 0;
}
```
[1093C - Mishka and the Last Exam](../problems/C._Mishka_and_the_Last_Exam.md "Educational Codeforces Round 56 (Rated for Div. 2)")

 **Tutorial**
### [1093C - Mishka and the Last Exam](../problems/C._Mishka_and_the_Last_Exam.md "Educational Codeforces Round 56 (Rated for Div. 2)")

Let's present the following greedy approach. The numbers will be restored in pairs $(a_1, a_n)$, $(a_2, a_{n - 1})$ and so on. Thus, we can have some limits on the values of the current pair (satisfying the criteria about sort). Initially, $l = 0, r = 10^{18}$ and they are updated with $l = a_i, r = a_{n - i + 1}$. Let $l$ be minimal possible in the answer. Take $a_i = max(l, b_i - r)$ and $r = b_i - l$. That way $l$ was chosen in such a way that both $l$ and $r$ are within the restrictions and $l$ is also minimal possible. If $l$ was any greater than we would move both $l$ limit up and $r$ limit down leaving less freedom for later choices.

Overall complexity: $O(n)$.

Funnily enough, I coded some naive solution just to test main correct and with restriction of $10^9$ on numbers it passed all tests in 300 ms at max. After I saw that I guessed why it worked in $O(MAXVAL)$ but it looked fun nonetheless.

 **Solution (PikMike)**
```cpp
n = int(input())
l, r = 0, 10**18
b = list(map(int, input().split()))
a = [0 for i in range(n)]
for i in range(n // 2):
	a[i] = max(l, b[i] - r)
	a[-i - 1] = b[i] - a[i]
	l, r = a[i], a[-i - 1]
print(*a)
```
 **Naive (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const long long INF64 = 1'000'000'000'000'000'000ll;
const int N = 200 * 1000 + 13;

int n;
long long a[N], b[N];

void brute(int x, long long l, long long r){
	if (x == n / 2){
		forn(i, n)
			printf("%lld ", a[i]);
		puts("");
		exit(0);
	}
	
	for (long long i = l; i <= b[x] / 2; ++i) if (b[x] - i <= r){
		a[x] = i;
		a[n - x - 1] = b[x] - i;
		brute(x + 1, i, b[x] - i);
	}
}

int main() {
	scanf("%d", &n);
	forn(i, n / 2)
		scanf("%lld", &b[i]);
	brute(0, 0, INF64);
	return 0;
}
```
[1093D - Beautiful Graph](../problems/D._Beautiful_Graph.md "Educational Codeforces Round 56 (Rated for Div. 2)")

 **Tutorial**
### [1093D - Beautiful Graph](../problems/D._Beautiful_Graph.md "Educational Codeforces Round 56 (Rated for Div. 2)")

Let's denote a way to distribute numbers as a painting. Let's also call the paintings that meet the constraints good paintings (and all other paintings are bad).

We can solve the problem for each connected component of the graph independently and multiply the answers. Let's analyze a painting of some connected component. If some vertex has an odd number written on it, then we should write even numbers on all adjacent vertices, and vice versa. So in fact we need to check if the component is bipartite, and if it is, divide it into two parts. The number of good paintings is 2a+2b, where a is the size of the first part, and b is the size of the second part, because we write 2's into all vertices of one part, and 1's or 3's into all vertices of another part.

 **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 999;
const int MOD = 998244353;

int n, m;
vector <int> g[N];
int p2[N];
int cnt[2];
int col[N];
bool bad;

void dfs(int v, int c){
	col[v] = c;
	++cnt[c];
	for(auto to : g[v]){
		if(col[to] == -1) dfs(to, 1 - c);
		if((col[v] ^ col[to]) == 0)
			bad = true;
	}
}

int main() {
    p2[0] = 1;
    for(int i = 1; i < N; ++i)
    	p2[i] = (2 * p2[i - 1]) % MOD;
    	
    int tc;
    scanf("%d", &tc);
    while(tc--){
    	scanf("%d%d", &n, &m);
    	for(int i = 0; i < n; ++i)
    	    g[i].clear();
    	
    	for(int i = 0; i < m; ++i){
    		int u, v;
    		scanf("%d %d", &u, &v);
    		--u, --v;
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
    	
    	int res = 1;
    	for(int i = 0; i < n; ++i) col[i] = -1;
    	for(int i = 0; i < n; ++i){
    	    if(col[i] != -1) continue;
            bad = false;
            cnt[0] = cnt[1] = 0;
            dfs(i, 0);
    	    if(bad){
    		    puts("0");
    		    break;
    	    }
    	    int cur = (p2[cnt[0]] + p2[cnt[1]]) % MOD;
    	    res = (res * 1LL * cur) % MOD;
    	}
    	
    	if(!bad) printf("%dn", res);
    }
    
    return 0;
}
```
[1093E - Intersection of Permutations](../problems/E._Intersection_of_Permutations.md "Educational Codeforces Round 56 (Rated for Div. 2)")

 **Tutorial**
### [1093E - Intersection of Permutations](../problems/E._Intersection_of_Permutations.md "Educational Codeforces Round 56 (Rated for Div. 2)")

At first, time limit was not that tight for the problem. We didn't want any sqrt, bitset or straight up nm solution to pass (and it's close to none to pass). Jury solution works faster than twice the time limit so we decided 6 seconds is alright.

The task is purely about implementation. You renumerate numbers in permutations so that the queries are (segment of values, segment of positions) and then have the structure to make update in point and sum on rectangle. 

Renumeration in my case was making the first permutation into identity one and changing the numbers in second appropriately. 

You can choose the structure you want, I'll tell about the one I use when the queries are offline. For online the common technique is having n BITs, each with treap in it (ordered_set template from pbds is usually enough). For offline you can precalculate the values to fall into each BIT beforehand and do BIT on these values inside. Preprocess all the update and get queries (x,y), adding y into all the BITs x will fall into. Then sort them and leave only unique occurrences.

Overall complexity: O((n+m)⋅log2n).

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;

int n, m;
int a[N], b[N], pos[N];

vector<int> f[N];
vector<int> vals[N];

void addupd(int x, int y){
	for (int i = x; i < N; i |= i + 1)
		vals[i].push_back(y);
}

void addget(int x, int y){
	if (x < 0 || y < 0) return;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		vals[i].push_back(y);
}

void upd(int x, int y, int val){
	for (int i = x; i < N; i |= i + 1)
		for (int j = lower_bound(vals[i].begin(), vals[i].end(), y) - vals[i].begin(); j < int(f[i].size()); j |= j + 1)
			f[i][j] += val;
}

int get(int x, int y){
	if (x < 0 || y < 0) return 0;
	int res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = lower_bound(vals[i].begin(), vals[i].end(), y) - vals[i].begin(); j >= 0; j = (j & (j + 1)) - 1)
			res += f[i][j];
	return res;
}

struct query{
	int t, la, ra, lb, rb;
	query(){};
};

query q[N];

int main() {
	scanf("%d%d", &n, &m);
	
	forn(i, n){
		scanf("%d", &a[i]);
		--a[i];
		pos[a[i]] = i;
	}
	
	forn(i, n){
		scanf("%d", &b[i]);
		--b[i];
		b[i] = pos[b[i]];
	}
	
	forn(i, m){
		scanf("%d", &q[i].t);
		if (q[i].t == 1){
			scanf("%d%d%d%d", &q[i].la, &q[i].ra, &q[i].lb, &q[i].rb);
			--q[i].la, --q[i].ra, --q[i].lb, --q[i].rb;
		}
		else{
			scanf("%d%d", &q[i].lb, &q[i].rb);
			--q[i].lb, --q[i].rb;
		}
	}
	
	vector<int> tmp(b, b + n);
	
	forn(i, n) addupd(i, b[i]);
	forn(i, m){
		if (q[i].t == 1){
			addget(q[i].rb, q[i].ra);
			addget(q[i].lb - 1, q[i].ra);
			addget(q[i].rb, q[i].la - 1);
			addget(q[i].lb - 1, q[i].la - 1);
		}
		else{
			addupd(q[i].lb, b[q[i].lb]);
			addupd(q[i].rb, b[q[i].rb]);
			swap(b[q[i].lb], b[q[i].rb]);
			addupd(q[i].lb, b[q[i].lb]);
			addupd(q[i].rb, b[q[i].rb]);
		}
	}
	
	forn(i, n) b[i] = tmp[i];
	
	forn(i, N){
		sort(vals[i].begin(), vals[i].end());
		vals[i].resize(unique(vals[i].begin(), vals[i].end()) - vals[i].begin());
		f[i].resize(vals[i].size(), 0);
	}
	
	forn(i, n)
		upd(i, b[i], 1);
	
	forn(i, m){
		if (q[i].t == 1){
			int res = 0;
			res += get(q[i].rb, q[i].ra);
			res -= get(q[i].lb - 1, q[i].ra);
			res -= get(q[i].rb, q[i].la - 1);
			res += get(q[i].lb - 1, q[i].la - 1);
			printf("%dn", res);
		}
		else{
			upd(q[i].lb, b[q[i].lb], -1);
			upd(q[i].rb, b[q[i].rb], -1);
			swap(b[q[i].lb], b[q[i].rb]);
			upd(q[i].lb, b[q[i].lb], 1);
			upd(q[i].rb, b[q[i].rb], 1);
		}
	}
	return 0;
}
```
[1093F - Vasya and Array](../problems/F._Vasya_and_Array.md "Educational Codeforces Round 56 (Rated for Div. 2)")

 **Tutorial**
### [1093F - Vasya and Array](../problems/F._Vasya_and_Array.md "Educational Codeforces Round 56 (Rated for Div. 2)")

Let's try dynamic programming approach to this problem. Let dpcnt,lst be the number of ways to replace all −1 with numbers from 1 to k in such a way that array a1…cnt is good and the last number of that array is lst.

Let sdpcnt=k∑i=1dpcnt,i.

Then initially it's dpcnt,lst=sdpcnt−1 if acnt equals to −1 or lst. However, we could include incorrect states — such that segment [acnt−len+1…acnt] consist of the same value. It happens when:

1. cnt≥len, as we should have at least len elements;
2. segment [acnt−len+1…acnt] has all its elements either equal to −1 or lst.

If both of these conditions hold then you should subtract all the bad states from dpcnt,lst. The number of them is sdpcnt−len−dpcnt−len,lst.

 **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forn(i, n) fore(i, 0, n)
#define nfor(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define for1(i, n) for(int i = 1; i < int(n); ++i)

#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define x first
#define y second

#define correct(x, y, xmax, ymax) ((x) >= 0 && (x) < (xmax) && (y) >= 0 && (y) < (ymax))
#define max(a, b) ((a > b)? a : b)
#define min(a, b) ((a < b)? a : b)
#define abs(a) ((a < 0) ? -a : a)
#define sqr(a) (a * a)

using namespace std;

const int N = int(1e5);
const int M = 105;
const int MOD = 998244353;

int sum(int a, int b){
	return (a + b) % MOD;	
}

int n, k, len;
int a[N];
int dp[N][M];
int sumdp[N];
int cnt[M][N];

int main() {
	scanf("%d %d %d", &n, &k, &len);
	forn(i, n){ 	
		scanf("%d", a + i);
		if(a[i] != -1) --a[i];
	}
    forn(i, k) 
        forn(j, n)
            cnt[i][j + 1] = cnt[i][j] + (a[j] == i || a[j] == -1);
            
	forn(i, n){ 
		forn(j, k){
			if(!(a[i] == -1 || a[i] == j))
				continue;
			
			int add = 1;
			if(i > 0) add = sumdp[i - 1];
			dp[i][j] = add;
			
			bool ok = i + 1 >= len;
			int l = max(0, i - len + 1);
			int r = i + 1;
			ok &= (r - l == cnt[j][r] - cnt[j][l]); 
			if(!ok) continue;
			
			if(i + 1 == len){
				dp[i][j] = sum(dp[i][j], MOD - 1);
				continue;
			}
			
			add = sum(dp[i - len][j], MOD - sumdp[i - len]);
			dp[i][j] = sum(dp[i][j], add);
		}
		forn(j, k) sumdp[i] = sum(sumdp[i], dp[i][j]);
	}
	
	printf("%dn", sumdp[n - 1]);

	return 0;
}
```
[1093G - Multidimensional Queries](../problems/G._Multidimensional_Queries.md "Educational Codeforces Round 56 (Rated for Div. 2)")

 **Tutorial**
### [1093G - Multidimensional Queries](../problems/G._Multidimensional_Queries.md "Educational Codeforces Round 56 (Rated for Div. 2)")

Let's rewrite the formula of distance between two points as follows:

$\sum \limits_{i = 1}^{k} |a_{x, i} - a_{y, i}| = \sum \limits_{i = 1}^{k} c_i (a_{x, i} - a_{y, i}) = \sum \limits_{i = 1}^{k} c_i a_{x, i} - \sum \limits_{i = 1}^{k} c_i a_{y, i}$, where $c_i = 1$ if $a_{x, i} \ge a_{y, i}$, otherwise $c_i = -1$.

Consider what will happen if we change some $c_i$ to the opposite value. The result of this formula obviously won't increase, so we may try all possible values of $c_i$ and pick maximum result.

This allows us to consider every option to set values of $c_i$ (there are $2^k$ such options) separately, and when we fix a set of values of $c_i$, find two points that maximize the distance if it is expressed with fixed $c_i$. To do so, we have to find the point having maximum $\sum \limits_{i = 1}^{k} c_i a_{x, i}$ and having minimum $\sum \limits_{i = 1}^{k} c_i a_{x, i}$.

So actually our problem is reduced to the following: we have $2^k$ arrays, we want to process some queries in the form "change an element of some array" and "find maximum and minimum on some segment of some array". This can be done simply by building a segment tree over each array, and then we will get the solution having $O((n + q) 2^k \log n)$ time complexity.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 200043;
const int INF = int(1e9);

int T[4 * N][32];
int A[4 * N][5];
int n, k;

void build(int v, int l, int r)
{
	if(l == r - 1)
	{
		for(int i = 0; i < (1 << k); i++)
		{
			int cur = 0;
			for(int j = 0; j < k; j++)
				if(i & (1 << j))
					cur += A[l][j];
				else
					cur -= A[l][j];
			T[v][i] = cur;
		}
	}
	else
	{
		int m = (l + r) / 2;
		build(v * 2 + 1, l, m);
		build(v * 2 + 2, m, r);
		for(int i = 0; i < (1 << k); i++)
			T[v][i] = min(T[v * 2 + 1][i], T[v * 2 + 2][i]);
	}
}

int query(int v, int l, int r, int L, int R, int x)
{
	if(L >= R) return INF;
	if(L == l && R == r)
		return T[v][x];
	int m = (l + r) / 2;
	return min(query(v * 2 + 1, l, m, L, min(R, m), x), query(v * 2 + 2, m, r, max(L, m), R, x));
}

void upd(int v, int l, int r, int z)
{
	if(l == r - 1)
	{
		for(int i = 0; i < (1 << k); i++)
		{
			int cur = 0;
			for(int j = 0; j < k; j++)
				if(i & (1 << j))
					cur += A[l][j];
				else
					cur -= A[l][j];
			T[v][i] = cur;
		}
	}
	else
	{
		int m = (l + r) / 2;
		if(z < m)
			upd(v * 2 + 1, l, m, z);
		else
			upd(v * 2 + 2, m, r, z);
		for(int i = 0; i < (1 << k); i++)
			T[v][i] = min(T[v * 2 + 1][i], T[v * 2 + 2][i]);
	}
}

int main() 
{ 
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	int q;
	scanf("%d", &q);
	build(0, 0, n);
	for(int i = 0; i < q; i++)
	{
		int t;
		scanf("%d", &t);
		if(t == 1)
		{
			int z;
			scanf("%d", &z);
			--z;
			for(int j = 0; j < k; j++)
				scanf("%d", &A[z][j]);
			upd(0, 0, n, z);
		}
		else
		{
			int ans = 0;
			int l, r;
			scanf("%d %d", &l, &r);
			--l;
			for(int i = 0; i < (1 << (k - 1)); i++)
			{
				int x = query(0, 0, n, l, r, i);
				int y = query(0, 0, n, l, r, ((1 << k) - 1) ^ i);
				ans = max(ans, abs(x + y));
			}
			printf("%dn", ans);
		}
	}
	return 0;
}
```
 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;
const int INF = 1e9;

struct point{
	int a[5];
	point(){};
	int& operator[](int x){
		return a[x];
	}
};

int n, k;
point a[N];

int t[32][4 * N];

int apply(point& p, int mask){
	int res = 0;
	forn(i, k){
		res += (mask & 1 ? p[i] : -p[i]);
		mask >>= 1;
	}
	return res;
}

void build(int v, int l, int r){
	if (l == r - 1){
		forn(mask, 1 << k)
			t[mask][v] = apply(a[l], mask);
		return;
	}
	
	int m = (l + r) / 2;
	
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	
	forn(mask, 1 << k)
		t[mask][v] = min(t[mask][v * 2], t[mask][v * 2 + 1]);
}

void upd(int v, int l, int r, int pos, point& val){
	if (l == r - 1){
		forn(mask, 1 << k)
			t[mask][v] = apply(val, mask);
		return;
	}
	
	int m = (l + r) / 2;
	
	if (pos < m)
		upd(v * 2, l, m, pos, val);
	else
		upd(v * 2 + 1, m, r, pos, val);
	
	forn(mask, 1 << k)
		t[mask][v] = min(t[mask][v * 2], t[mask][v * 2 + 1]);
}

int bst[32];

void get(int v, int l, int r, int L, int R){
	if (L >= R)
		return;
	
	if (l == L && r == R){
		forn(mask, 1 << k)
			bst[mask] = min(bst[mask], t[mask][v]);
		return;
	}
	
	int m = (l + r) / 2;
	
	get(v * 2, l, m, L, min(m, R));
	get(v * 2 + 1, m, r, max(m, L), R);
}

int main() {
	scanf("%d%d", &n, &k);
	forn(i, n) forn(j, k)
		scanf("%d", &a[i][j]);
	build(1, 0, n);
	
	int m;
	scanf("%d", &m);
	forn(_, m){
		int t;
		scanf("%d", &t);
		if (t == 1){
			int i;
			scanf("%d", &i);
			--i;
			point tmp;
			forn(j, k)
				scanf("%d", &tmp[j]);
			upd(1, 0, n, i, tmp);
		}
		else{
			int l, r;
			scanf("%d%d", &l, &r);
			--l, --r;
			forn(mask, 1 << k)
				bst[mask] = INF;
			get(1, 0, n, l, r + 1);
			
			int ans = 0;
			forn(mask, 1 << k)
				ans = max(ans, abs(bst[(1 << k) - 1 - mask] + bst[mask]));
			printf("%dn", ans);
		}
	}
	return 0;
}
```
