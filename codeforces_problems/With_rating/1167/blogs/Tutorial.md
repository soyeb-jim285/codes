# Tutorial

[1167A - Telephone Number](../problems/A._Telephone_Number.md "Educational Codeforces Round 65 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1167A - Telephone Number](../problems/A._Telephone_Number.md "Educational Codeforces Round 65 (Rated for Div. 2)")

To solve this problem, we just need to find the first occurrence of the digit 8, let's denote it as x. 

Now if n−x≥10 then answer is YES, otherwise NO.

 **Solution (Roms)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int n;
string s;

int main(){
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; ++t){
        cin >> n >> s;
        int pos = n;
        for(int i = 0; i < n; ++i)
            if(s[i] == '8'){
                pos = i;
                break;
            }
            
        if(n - pos >= 11)
            cout << "YESn";
        else
            cout << "NOn";
    }
	return 0;
}
```
[1167B - Lost Numbers](../problems/B._Lost_Numbers.md "Educational Codeforces Round 65 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**
### [1167B - Lost Numbers](../problems/B._Lost_Numbers.md "Educational Codeforces Round 65 (Rated for Div. 2)")

The key fact that allows us to solve this problem is that if we analyze the pairwise products of special numbers, we will see that all of them (considering that we always multiply two different numbers) are unique. So, if we, for example, know that ai⋅aj=x, then there are only two possibilities for the values of ai and aj: x is uniquely expressed as the product of two distinct special numbers A and B, and either ai=A, aj=B, or ai=B, aj=A. This allows us to guess three numbers using two queries: we ask ai⋅aj and aj⋅ak, we uniquely determine aj as the only number that is suitable for the both pairs, and then we express ai=ai⋅ajaj and ak=aj⋅akaj.

Of course, there are easier ways to solve this problem, considering there are only 6 special numbers. For example, you could use four queries ai⋅ai+1 (for all i∈[1,4]) and try all 6! permutations, and the model solution uses exactly this approach.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

vector<int> p = {4, 8, 15, 16, 23, 42};
int ans[4];

int main()
{
	for(int i = 0; i < 4; i++)
	{
		cout << "? " << i + 1 << " " << i + 2 << endl;
		cout.flush();
		cin >> ans[i];
	}
	do
	{
		bool good = true;
		for(int i = 0; i < 4; i++)
			good &= (p[i] * p[i + 1] == ans[i]);
		if(good) break;
	}
	while(next_permutation(p.begin(), p.end()));
	cout << "!";
	for(int i = 0; i < 6; i++)
		cout << " " << p[i];
	cout << endl;
	cout.flush();
	return 0;
}
```
[1167C - News Distribution](../problems/C._News_Distribution.md "Educational Codeforces Round 65 (Rated for Div. 2)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1167C - News Distribution](../problems/C._News_Distribution.md "Educational Codeforces Round 65 (Rated for Div. 2)")

The first intention after reading the problem is to reformulate it in graph theory terms. Let people be vertices, edge between two vertices x and y exists if x and y have some group in common. Basically, if person x starts distributing the news, everyone in his connectivity component recieves it. Thus, the task is to calculate the number of vertices of each vertex component.

As of now, the graph can have up to O(n2) edges (consider the case where everyone is in the same group). Let's reduce the number of edges without changing connectivity components. For each group you know for sure that people in it are in the same component. Let's connect not just every pair of vertices in it, but every pair of neighbouring ones in each group. It's easy to see that they are still in the same component.

This graph will have O(m∑i=1ki) edges which is a much smaller number. You can use dfs or dsu to find the components and their sizes.

Overall complexity: O(n+m∑i=1ki).

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1000043;
vector<int> g[N];

int color[N];
int siz[N];
int n, m;
int cc = 0;

int dfs(int x)
{
	if(color[x])
		return 0;
	color[x] = cc;
	int ans = (x < n ? 1 : 0);
	for(auto y : g[x])
		ans += dfs(y);
	return ans; 
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; j++)
		{
			int x;
			scanf("%d", &x);
			--x;
			g[x].push_back(i + n);
			g[i + n].push_back(x);
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(!color[i])
		{
			cc++;
			siz[cc] = dfs(i);
		}
		printf("%d ", siz[color[i]]);
	}
}
```
 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

const int N = 500 * 1000 + 13;

int n, m;
int rk[N], p[N];

int getP(int a){
	return (a == p[a] ? a : p[a] = getP(p[a]));
}

void unite(int a, int b){
	a = getP(a), b = getP(b);
	if (a == b) return;
	if (rk[a] < rk[b]) swap(a, b);
	p[b] = a;
	rk[a] += rk[b];
}

int main(){
	scanf("%d%d", &n, &m);
	forn(i, n) p[i] = i, rk[i] = 1;
	
	forn(i, m){
		int k;
		scanf("%d", &k);
		int lst = -1;
		forn(j, k){
			int x;
			scanf("%d", &x);
			--x;
			if (lst != -1)
				unite(x, lst);
			lst = x;
		}
	}
	
	forn(i, n)
		printf("%d ", rk[getP(i)]);
	puts("");
}
```
[1167D - Bicolored RBS](../problems/D._Bicolored_RBS.md "Educational Codeforces Round 65 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1167D - Bicolored RBS](../problems/D._Bicolored_RBS.md "Educational Codeforces Round 65 (Rated for Div. 2)")

Let d(s) be nested depth of RBS s. There is an interesting fact that max. From the other side we can always reach equation \max(d(r), d(b)) = \left\lceil \frac{d(s)}{2} \right\rceil using some approaches.

Let's look at prefix of length i of string s. Let o_s(i) be number of opening bracket in the prefix, c_s(i) — number of closing brackets. Then we can define balance of the i-th prefix of s as bal_s(i) = o_s(i) - c_s(i).

The author's approach is next: 

Let's define level of pair of brackets (matched in natural way) as bal_s(i - 1), where i is position of opening bracket of this pair. Then we will color in red all pairs with even level and in blue — with odd level.

—— Proof of \max(d(r), d(b)) \ge \left\lceil \frac{d(s)}{2} \right\rceil:

It can be shown that d(s) = \max\limits_{1 \le i \le n}(bal_s(i)) and exists such pos that d(s) = bal_s(pos).

After any coloring of s we can define number of opening/closing red (blue) brackets of pos-th prefix of s as o_r(pos) (o_b(pos)) and c_r(pos) (c_b(pos)) respectively. Since o_s(pos) = o_r(pos) + o_b(pos) and c_s(pos) = c_r(pos) + c_b(pos), then \max(bal_r(pos), bal_b(pos)) = \max(o_r(pos) - c_r(pos), bal_b(pos)) \\\ = \max((o_s(pos) - o_b(pos)) - (c_s(pos) - c_b(pos)), bal_b(pos)) = \max((o_s(pos) - c_s(pos)) - (o_b(pos) - c_b(pos)), bal_b(pos)) \\\ = \max(bal_s(pos) - bal_b(pos), bal_b(pos)) \ge \left\lceil \frac{bal_s(pos)}{2} \right\rceil = \left\lceil \frac{d(s)}{2} \right\rceil.

Finally, \max(d(a), d(b)) = \max(\max\limits_{1 \le i \le n}(bal_r(i)), \max\limits_{1 \le i \le n}(bal_b(i))) \\\ = \max\limits_{1 \le i, j \le n}(\max(bal_r(i), bal_b(j))) \ge \max(bal_r(pos), bal_b(pos)) \ge \left\lceil \frac{d(s)}{2} \right\rceil

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

int n;
string s;

inline bool read() {
	if(!(cin >> n))
		return false;
	cin >> s;
	return true;
}

inline void solve() {
	string t(n, '0');
	
	int bal = 0;
	fore(i, 0, n) {
		if(s[i] == ')')
			bal--;
		
		t[i] = char('0' + (bal & 1));
		
		if(s[i] == '(')
			bal++;
	}
	
	cout << t << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	
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
[1167E - Range Deleting](../problems/E._Range_Deleting.md "Educational Codeforces Round 65 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1167E - Range Deleting](../problems/E._Range_Deleting.md "Educational Codeforces Round 65 (Rated for Div. 2)")

Lets find the maximum number $pref$ such that all values $1, 2, \dots, pref$ form the non-descending order array. It can be done the following way. Let values $1, 2, \dots, x$ form the non-descending order array. Then values $1, 2, \dots, x, x+1$ will form the non-descending order array if the first occurrence of $x+1$ in array $a$ is after the last occurrence of $x$. In similar manner we can find the minimum number $suf$ such that all values $suf, suf+1, \dots, x$ form the non-descending order array.

Now let's find out how to get the minimum number $s$ such that all values $1, 2, \dots, p, s, s + 1, \dots, x$ form the non-descending order array if we fixed the value $p$. We denote this value $s$ for some fixed value $p$ as $f(p)$. Firstly, conditions $s > p$, $suf \le s$ and $p \le pre$ should hold. Secondly, there should be no such a pair $(m, r)$ that conditions $1 \le m < r \le n$, $1 \le a_r, \le p$ and $s \le a_m \le x$ hold. Since the condition $p \le pre$ is satisfied, it means that $s$ must be greater than $\max\limits_{1 \le i \le lst} a_i$, where $lst$ is the last occurrence of $p$ in array $a$.

In this way the answer is $\sum\limits_{i=1}^{pref} (x - f(i) + 1)$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 99;
int n, x;
int a[N];
vector <int> pos[N];
int prefMax[N];

int main() {
	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; ++i){
		scanf("%d", a + i);
		pos[a[i]].push_back(i);	
		prefMax[i] = max(a[i], (i > 0 ? prefMax[i - 1] : a[i]));
	}
	
	int p = 1;
	int lst = n + 5;
	for(int i = x; i >= 1; --i){
		if(pos[i].empty()){
		    p = i;
		    continue;
		}
		if(pos[i].back() > lst) break;
		p = i;
		lst = pos[i][0];
	}	

	long long res = 0;
	lst = -1;
	for(int l = 1; l <= x; ++l){
		int r = max(l, p - 1);
		if(lst != -1) r = max(r, prefMax[lst]);
		res += x - r + 1;
		if(!pos[l].empty()){
    		if(pos[l][0] < lst) break;
    		lst = pos[l].back();
		}
	}	

	cout << res << endl;
	return 0;
}
```
[1167F - Scalar Queries](../problems/F._Scalar_Queries.md "Educational Codeforces Round 65 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1167F - Scalar Queries](../problems/F._Scalar_Queries.md "Educational Codeforces Round 65 (Rated for Div. 2)")

Let's define some functions at first: indicator function $I(x) = 1$ if $x$ is true and $0$ otherwise. $lower(l, r, x)$ is a number of $a_j$ that $l \le j \le r$ and $a_j < x$. Good observation: $lower(l, r, x) = \sum_{j = l}^{j = r}{I(a_j < x)}$.

Another observation: $f(l, r) = \sum\limits_{i = l}^{i = r}{a_i \cdot (lower(l, r, a_i) + 1})$.

Now, it's time to transform what we'd like to calculate: $$\sum_{1 \le l \le r \le n}{f(l, r)} = \sum_{1 \le l \le r \le n}{\sum_{i = l}^{i = r}{a_i \cdot (lower(l, r, a_i) + 1})} = \sum_{1 \le l \le r \le n}{(\sum_{i = l}^{i = r}{a_i \cdot lower(l, r, a_i)} + \sum_{i = l}^{i = r}{a_i})} = \\\ = \sum_{1 \le l \le r \le n}{\sum_{i = l}^{i = r}{a_i \cdot lower(l, r, a_i)}} + \sum_{i = 1}^{i = n}{a_i \cdot i \cdot (n - i + 1)}$$

Since transformation of the second sum was standard, we'll look at the first sum: $$\sum_{1 \le l \le r \le n}{\sum_{i = l}^{i = r}{a_i \cdot lower(l, r, a_i)}} = \sum_{i = 1}^{i = n}{\sum_{1 \le l \le i \le r \le n}{a_i \cdot lower(l, r, a_i)}} = \sum_{i = 1}^{i = n}{a_i \sum_{1 \le l \le i \le r \le n}{lower(l, i, a_i) + lower(i, r, a_i)}} = \\\ = \sum_{i = 1}^{i = n}{a_i \sum_{1 \le l \le i}{ \sum_{i \le r \le n}{lower(l, i, a_i) + lower(i, r, a_i)}}} = \sum_{i = 1}^{i = n}{a_i \left( (n - i + 1) \sum_{1 \le l \le i}{lower(l, i, a_i)} + i \sum_{i \le r \le n}{lower(i, r, a_i)} \right) }$$

So, we can iterate over $i$ and we'd like to calculate this two sums fast enough. So, more transformations: $$\sum_{1 \le l \le i}{lower(l, i, a_i)} = \sum_{1 \le l \le i}{\sum_{j = l}^{j = i}{I(a_j < a_i)}} = \sum_{j = 1}^{j = i}{\sum_{l = 1}^{l = j}{I(a_j < a_i)}} = \sum_{j = 1}^{j = i}{I(a_j < a_i) \cdot j}$$

So, while iterating over $i$ we need to make queries of two types: set value $i$ in position $a_i$ and calculate $\sum_{a_j < a_i}{j}$. It can be done by BIT with coordinate compression.

$\sum_{i \le r \le n}{lower(i, r, a_i)}$ can be calculated in the same way iterating over $i$ in reverse order.

Result complexity is $O(n \log{n})$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

typedef long long li;

const int MOD = int(1e9) + 7;

int add(int a, int b) {
	a += b;
	while(a >= MOD)
		a -= MOD;
	while(a < 0)
		a += MOD;
	return a;
}
int mul(int a, int b) {
	return int(a * 1ll * b % MOD);
}

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

vector<li> f;
void inc(int pos, int val) {
	for(; pos < sz(f); pos |= pos + 1)
		f[pos] += val;
}
li sum(int pos) {
	li ans = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		ans += f[pos];
	return ans;
}

vector<int> S[2];

inline void solve() {
	fore(k, 0, 2) {
		S[k].assign(n, 0);
		f.assign(n, 0);
		
		vector<int> dx(a.begin(), a.end());
		sort(dx.begin(), dx.end());
		
		fore(i, 0, n) {
			int pos = int(lower_bound(dx.begin(), dx.end(), a[i]) - dx.begin());
			S[k][i] = int(sum(pos) % MOD);
			inc(pos, i + 1);
		}
		reverse(a.begin(), a.end());
	}
	
	reverse(S[1].begin(), S[1].end());
	int ans = 0;
	fore(i, 0, n) 
		ans = add(ans, mul(a[i], add(mul(i + 1, n - i), add(mul(S[0][i], n - i), mul(S[1][i], i + 1)))));
	
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
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
[1167G - Low Budget Inception](../problems/G._Low_Budget_Inception.md "Educational Codeforces Round 65 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1167G - Low Budget Inception](../problems/G._Low_Budget_Inception.md "Educational Codeforces Round 65 (Rated for Div. 2)")

Let's solve the problem for a single query at first. There are two possible types of collisions: between two buildings and between a building and a ray. 

Obviously, if the collision of the second type happens, then it's the building which is the closest to the bend point (from either left or right). 

The less obvious claim is that among all buildings collisions, the closest is the biggest angle one. Let's boil down some possibilities of colliding buildings. Let two buildings be the same distance $D$ from the bend point $x$. Then they will collide and the collision point will $(x - D, 1)$. Two buildings also collide if the left one is $D + 1$ from $x$ and the right one is $D$. Then the point of collision is $(x - D + 1, 1)$. And for the opposite case the point of collision is also $(x - D + 1, 1)$. These points can be easily proven by checking the distances to upper corners of each building. No other two buildings will collide.

Now that we know this, we can transition to solving a problem of checking if there exists such a pair that the distances to $x$ from them differ by at most one. Finding such a pair with minimal $D$ is enough. Obviously, this can be done with some sort of two pointers. However, that's not the intended solution.

Let's constuct bitset of 7000 positions to the left of the bend and to the right of the bend. AND of these bitsets will give you the pairs such that the distance $D$ is the same for them. However, you can put 1 in points $y - 1$ and $y$ for each building to the left and $y$ and $y + 1$ for each building to the right. This way AND will give you the exact pairs you need. Use _Find_first to find the closest one.

Let collision happen on distance $D$. Then the collision of the first type will have angle $2 \cdot arctan D$ and the collision of the second type will have angle $arctan D$. The answer is the maximum of these two values. Be careful with cases where $D = 0$.

How to process lots of queries. Let's just move the bitsets to the right while going through queries in ascending order. Bitsets can be updated in $(d / 32)$ for each query and only $n$ buildings will be added to them in total.

Overall complexity: $O(md / 32 + n)$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;

const int INF = int(1e9);
const li INF64 = li(1e18);

const int N = 200 * 1000 + 555;
const int D = 7077;

int n, d, m;
int a[N], qs[N];

inline bool read() {
	if(scanf("%d%d", &n, &d) != 2)
		return false;
	fore(i, 0, n)
		scanf("%d", &a[i]);
	
	assert(scanf("%d", &m) == 1);
	fore(i, 0, m)
		scanf("%d", &qs[i]);
	return true;
}

bitset<D> L, R, cur;
int dist[N];
set<int> has;

void shiftL(int s, int t, int &uk) {
	L <<= t - s;
	for(; uk < n && a[uk] < t; uk++) {
		if(t - a[uk] - 1 < D)
			L[t - a[uk] - 1] = 1;
		if(t - a[uk] < D)
			L[t - a[uk]] = 1;
	}
}

void shiftR(int s, int t, int &uk) {
	R >>= t - s;
	if(!has.count(t))
		R[0] = 0;
	
	for(; uk < n && a[uk] < t + D; uk++) {
		if(a[uk] - t >= 0) {
			R[a[uk] - t] = 1;
			if(a[uk] - t + 1 >= 0)
				R[a[uk] - t + 1] = 1;
		}
	}
}

inline void solve() {
	fore(i, 0, m) {
		dist[i] = INF;
		int pos = int(lower_bound(a, a + n, qs[i]) - a);
		if(pos > 0)
			dist[i] = qs[i] - a[pos - 1] - 1;
		if(pos < n)
			dist[i] = min(dist[i], a[pos] - qs[i]);
	}
	has = set<int>(a, a + n);
	
	int uL = 0, uR = 0;
	L.reset();
	R.reset();
	fore(i, 0, m) {
		shiftL(i > 0 ? qs[i - 1] : -D, qs[i], uL);
		shiftR(i > 0 ? qs[i - 1] : -D, qs[i], uR);
		
		double ans = atan2(1, dist[i]);

		cur = L & R;
		int pos = (int)cur._Find_first();
		if(pos < D) {
			int ds = pos;
			ans = max(ans, 2 * atan2(1, ds));
		}
		printf("%.15fn", ans);
	}
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
