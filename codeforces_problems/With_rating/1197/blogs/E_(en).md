# E_(en)

[1197A - DIY Wooden Ladder](../problems/A._DIY_Wooden_Ladder.md "Educational Codeforces Round 69 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1197A - DIY Wooden Ladder](../problems/A._DIY_Wooden_Ladder.md "Educational Codeforces Round 69 (Rated for Div. 2)")

Since all planks have length at least $1$ so we can take any $n - 2$ planks as steps. So, all we need is to maximize the length of base planks. We can take the first and second maximum as base, then the answer is minimum among second maximum - 1 and $n - 2$.

 **Solution (adedalic)**
```cpp
fun main(args: Array<String>) {
    val T = readLine()!!.toInt()
    for (tc in 1..T) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.sortedDescending()
        println(minOf(a[1] - 1, n - 2))
    }
}
```
[1197B - Pillars](../problems/B._Pillars.md "Educational Codeforces Round 69 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1197B - Pillars](../problems/B._Pillars.md "Educational Codeforces Round 69 (Rated for Div. 2)")

Suppose we have a disk that is smaller than both of its neighbours. Then it's impossible to collect all the disks on the same pillar: eventually we will put this disk on the same pillar with one of its neighbours, and then we can't put the other neighbouring disk on the same pillar since it is greater than the middle disk.

Okay, and what if there is no disk that is strictly smaller than both of its neighbours? Let $k$ be the index of the largest disk. $a_{k - 1} < a_k$, that implies $a_{k - 2} < a_{k - 1}$, and so on. $a_{k + 1} < a_k$, $a_{k + 2} < a_{k + 1}$, and so on. It means that the array $a$ is sorted in ascending until the index $k$, and after that it is sorted in descending order. If this condition is met, then we can collect all the disks on the pillar $k$ one by one, starting with the disk having radius $n - 1$ and ending with the disk having radius $1$.

So the only thing that we need to check is the following condition: array $a$ is sorted in ascending order until $a_k = n$, and then it is sorted in descending order.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	int pos = max_element(a.begin(), a.end()) - a.begin();
	bool res = true;
	for(int i = 0; i < pos; i++)
		res &= (a[i] < a[i + 1]);
	for(int i = pos; i < n - 1; i++)
		res &= (a[i] > a[i + 1]);

	if(res)
		puts("YES");
	else
		puts("NO");
}
```
[1197C - Array Splitting](../problems/C._Array_Splitting.md "Educational Codeforces Round 69 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1197C - Array Splitting](../problems/C._Array_Splitting.md "Educational Codeforces Round 69 (Rated for Div. 2)")

Let's carefully look at the coefficients with which the elements of the array will be included in the answer. 

If pair of adjacent elements $a_i$ and $a_{i+1}$ belong to different subarrays then element $a_i$ will be included in the answer with coefficient $1$, and element $a_{i+1}$ with coefficient $-1$. So they add value $a_{i} - a_{i+1}$ to the answer.

If element belongs to subarray with length $1$ then it will be included in the sum with coefficient $0$ (because it will be included with coefficient $1$ and $-1$ simultaneously). Elements at positions $1$ and $n$ will be included with coefficients $-1$ and $1$ respectively.

So initially our answer is $a_n - a_1$. All we have to do is consider $n-1$ values $a_1 - a_2, a_2 - a_3, \dots , a_{n-1} - a_n$ and add up the $k-1$ minimal ones to the answer.

 **Solution (Roms)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

int n, k;
int a[N];

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	
	vector <int> v;
	for(int i = 1; i < n; ++i) v.push_back(a[i - 1] - a[i]);
	
	sort(v.begin(), v.end());
	
	int res = a[n - 1] - a[0];
	for(int i = 0; i < k - 1; ++i) res += v[i];
	
	cout << res << endl;
 	return 0;
}
```
[1197D - Yet Another Subarray Problem](../problems/D._Yet_Another_Subarray_Problem.md "Educational Codeforces Round 69 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1197D - Yet Another Subarray Problem](../problems/D._Yet_Another_Subarray_Problem.md "Educational Codeforces Round 69 (Rated for Div. 2)")

At first let's solve this problem when $m = 1$ and $k = 0$ (it is the problem of finding subarray with maximum sum). For each position from $1$ to $n$ we want to know the value of $maxl_i = \max\limits_{1 \le j \le i + 1} sum(j, i)$, where $sum(l, r) = \sum\limits_{k = l}^{k \le r} a_k$, and $sum(x+1, x) = 0$. 

We will calculate it the following way. $maxl_i$ will be the maximum of two values: 

* $0$ (because we can take segments of length $0$);
* $a_i + maxl_{i-1}$.

The maximum sum of some subarray is equal to $\max\limits_{1\le i \le n} maxl_i$.

So, now we can calculate the values of $best_i = \max\limits_{0 \le len, i - len \cdot m \ge 0} (sum(i-len \cdot m + 1, i) - len * k)$ the same way. 

$best_i$ is the maximum of two values: 

* 0;
* $sum(i - m + 1, i) - k + best_{i-m}$.

After calculating all values $best_i$ we can easily solve this problem. At first, let's iterate over the elements $best_i$. When we fix some element $best_i$, lets iterate over the value $len = 1, 2, \dots, m$ and update the answer with value $best_i + sum(i - len, i - 1) - k$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

int n, m, k;
int a[N];
long long bst[N];
long long psum[N];

long long sum(int l, int r){
    l = max(l, 0);
	return psum[r] - (l == 0? 0 : psum[l - 1]);
}

int main() {
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		psum[i] = a[i] + (i == 0? 0 : psum[i - 1]);
	}

	long long res = 0;
	for(int len = 1; len <= m && len <= n; ++len)
			res = max(res, sum(0, len - 1) - k);
	for(int i = 0; i < n; ++i){
		if(i + 1 >= m){
			long long nbst = sum(i - m + 1, i) - k;
			if(i - m >= 0) nbst += bst[i - m];
			bst[i] = max(bst[i], + nbst);
		}

		for(int len = 0; len < m && i + len < n; ++len)
			res = max(res, bst[i] + sum(i + 1, i + len) - k * (len > 0));
	}	

	cout << res << endl;
	return 0;
}                             	
```
[1197E - Culture Code](../problems/E._Culture_Code.md "Educational Codeforces Round 69 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1197E - Culture Code](../problems/E._Culture_Code.md "Educational Codeforces Round 69 (Rated for Div. 2)")

Let's, at first, sort all matryoshkas by increasing its inner volume $in_i$. Then each nested subset will appear as subsequence in its "canonical" order. Now we'll write the DP with $d[i] = (x, y)$ — the minimum extra space $x$ and number of such subsequences $y$ among all nested subsets, where the $i$-th doll is minimal. Why minimal (not maximal, for example)? It's just easier transitions (and easier proof). 

There are two main cases. If there isn't $j$, such that $out_i \le in_j$ then we can't put the $i$-th doll inside any other. So, $d[i] = (in_i, 1)$.

Otherwise, we must put the $i$-th doll inside other doll (otherwise, the subset won't be a big enough). If we put the $i$-th doll inside the $j$-th doll then we extra space of such subset is equal to $d[j].first - (out_i - in_i)$. Since we minimize the extra space, then $$d[i].first = \min\limits_{out_i \le in_j}{(d[j].first - (out_i - in_i))} = \min\limits_{out_i \le in_j}{(d[j].first)} - (out_i - in_i).$$

Since we sorted all matryoshkas, so there is a position $pos$ such that $\forall j \ge pos : out_i \le in_j$ and $d[i].first = \min\limits_{j = pos}^{n}{(d[j].first)} - (out_i - in_i)$. The $d[i].second$ is just a sum from all minimums.

As you can see: we can store $d[i]$ in Segment Tree with minimum + number of minimums. Why in the second transition we will build only big enough subsets? It's because not big enough subsets are not optimal in terms of minimality of extra space.

The result complexity is $O(n \log(n))$.

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

const int INF = int(1e9) + 555;
const li INF64 = li(1e18);
const ld EPS = 1e-9;

const int MOD = int(1e9) + 7;

int norm(int a) {
	if(a >= MOD) a -= MOD;
	if(a < 0) a += MOD;
	return a;
}

pt combine(const pt &a, const pt &b) {
	if(a.x < b.x)
		return a;
	if(a.x > b.x)
		return b;
	return {a.x, norm(a.y + b.y)};
}

int n;
vector<pt> p;

inline bool read() {
	if(!(cin >> n))
		return false;
	p.resize(n);
	fore(i, 0, n)
		cin >> p[i].x >> p[i].y;
	
	return true;
}

vector<pt> T;

void setVal(int pos, const pt &val) {
	T[pos += n] = val;
	for(pos >>= 1; pos > 0; pos >>= 1)
		T[pos] = combine(T[2 * pos], T[2 * pos + 1]);
}

pt getMin(int l, int r) {
	pt ans = {INF, 0};
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l & 1)
			ans = combine(T[l++], ans);
		if(r & 1)
			ans = combine(T[--r], ans);
	}
	return ans;
}

inline void solve() {
	auto comp = [](const pt &a, const pt &b) {
		if(a.y != b.y)
			return a.y < b.y;
		return a.x < b.x;
	};
	
	sort(p.begin(), p.end(), comp);
	
	T.assign(2 * n, {INF, 0});
	for (int i = n - 1; i >= 0; i--) {
		int pos = int(lower_bound(p.begin(), p.end(), pt(0, p[i].x), comp) - p.begin());
		
		if(pos >= n) {
			setVal(i, {p[i].y, 1});
			continue;
		}
		pt bst = getMin(pos, n);
		setVal(i, {bst.x - (p[i].x - p[i].y), bst.y});
	}
	
	cout << getMin(0, n).y << endl;
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
[1197F - Coloring Game](../problems/F._Coloring_Game.md "Educational Codeforces Round 69 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1197F - Coloring Game](../problems/F._Coloring_Game.md "Educational Codeforces Round 69 (Rated for Div. 2)")

Suppose there is only one strip and we want to count the number of ways to paint it. We can do it with some dynamic programming: let $dp_{i, r_1, r_2, r_3}$ be the number of ways to paint first $i$ cells of the strip so that $r_1$ denotes the result of the game if it starts in the last cell ($r_1 = 0$ if the player that makes a turn from this state loses, or $r_1 = 1$ if he wins), $r_2$ — the result if the game starts in the second-to-last, and so on. Then, if we paint the next cell, we can easily determine the result of the game starting in it, using the values of $r_i$ and the set of possible moves: if there is a value $r_i = 0$ such that we can move the chip $i$ cells backwards from the cell we just painted, then that cell is a winning one (if the game starts in it, the first player wins), otherwise it is a losing one.

This dynamic programming works too slow since the strip can be very long, but we can skip long uncolored segments converting the transitions of this dp into matrix-vector multiplication: each possible combination of values of ($r_1$, $r_2$, $r_3$) can be encoded as a number from $0$ to $7$, and we may construct a $8 \times 8$ transition matrix $T$: $T_{i, j}$ will be equal to the number of ways to color one cell so that the previous values of ($r_1$, $r_2$, $r_3$) have code $i$, and the next values have code $j$. To model painting $k$ consecutive uncolored segments, we may compute $T^k$ with fast exponentiation method. Now we can solve the problem for one strip.

What changes if we try to apply the same method to solve the problem with many strips? Unfortunately, we can't analyze each cell as "winning" or "losing" now, we need more information. When solving a problem related to a combination of acyclic games, we may use Sprague-Grundy theory (you can read about it here: [https://cp-algorithms.com/game_theory/sprague-grundy-nim.html](https://codeforces.com/https://cp-algorithms.com/game_theory/sprague-grundy-nim.html)). Instead of marking each cell as "winning" or "losing", we can analyze the Grundy value of each cell. When considering a strip, we should count the number of ways to color it so that its Grundy is exactly $x$ (we should do it for every possible value of $x$), which can help us to solve the initial problem with the following dynamic programming: $z_{i, j}$ is the number of ways to color $i$ first strips so that the Grundy value of their combination is exactly $j$.

The only thing that's left to consider is how do we count the number of ways to color a single strip so that its Grundy value is fixed. We can to it by modifying the method described in the first paragraph: let $dp_{i, r_1, r_2, r_3}$ be the number of ways to paint $i$ first cells so that the Grundy value of the last cell is $r_1$, the value of the previous-to-last cell is $r_2$, and so on. Since we have only $3$ possible moves, the Grundy values are limited to $3$, and each possible combination of values of ($r_1$, $r_2$, $r_3$) can be encoded as a number from $0$ to $63$. The transition matrix $T$ that allows us to skip long uncolored segments will be a $64 \times 64$ one, so if we will just exponentiate it every time we want to skip a segment, we'll get TL — but we can optimize it by precalculating $T$, $T^2$, $T^4$, ..., $T^{2^{30}}$ and using matrix-vector multiplication instead of matrix-matrix multiplication every time we skip an uncolored segment.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
	return (x + y) % MOD;
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

typedef vector<int> vec;
typedef vector<vec> mat;

vec mul(const mat& a, const vec& b)
{
	int n = a.size();
	int m = b.size();
	vector<int> c(m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			c[i] = add(c[i], mul(b[j], a[i][j]));
	return c;
}

mat add(const mat& a, const mat& b)
{
	int n = a.size();
	int m = a[0].size();
	mat c(n, vec(m, 0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			c[i][j] = add(a[i][j], b[i][j]);
	return c;
}

mat mul(const mat& a, const mat& b)
{
	int x = a.size();
	int y = b.size();
	int z = b[0].size();
	mat c(x, vec(z, 0));
	for(int i = 0; i < x; i++)
		for(int j = 0; j < y; j++)
			for(int k = 0; k < z; k++)
				c[i][k] = add(c[i][k], mul(a[i][j], b[j][k]));
	return c;
}

mat binpow(mat a, int d)
{
	int n = a.size();
	mat c = mat(n, vec(n, 0));
	for(int i = 0; i < n; i++) c[i][i] = 1;
	while(d > 0)
	{
		if(d % 2 == 1) c = mul(c, a);
		a = mul(a, a);
		d /= 2;
	}
	return c;
}

int f[3][3];

int extend(int color, vector<int> last_numbers)
{
	vector<int> used(4, 0);
	for(int i = 0; i < 3; i++)
		if(f[color][i])
			used[last_numbers[i]] = 1;
	for(int i = 0; i <= 3; i++)
		if(used[i] == 0)
			return i;
	return 3;
}

vector<int> extend_state(int color, vector<int> last_numbers)
{
	int z = extend(color, last_numbers);
	last_numbers.insert(last_numbers.begin(), z);
	last_numbers.pop_back();
	return last_numbers;
}

vector<int> int2state(int x)
{
	vector<int> res;
	for(int i = 0; i < 3; i++)
	{
		res.push_back(x % 4);
		x /= 4;
	}
	return res;
}

int state2int(const vector<int>& x)
{
	int res = 0;
	int deg = 1;
	for(auto y : x)
	{
		res += deg * y;
		deg *= 4;
	}
	return res;
}

mat form_matrix(int color)
{
	mat res(64, vec(64, 0));
	for(int i = 0; i < 64; i++)
	{
		int j = state2int(extend_state(color, int2state(i)));
		res[j][i] = add(res[j][i], 1);
	}
	return res;
}

mat color_matrices[3];
mat full_matrix;

vector<pair<int, int> > colored[1043];
int len[1043];
int dp[1043][4];

mat full_pows[31];

void precalc_pows()
{
	full_pows[0] = full_matrix;
	for(int i = 0; i <= 30; i++)
		full_pows[i + 1] = mul(full_pows[i], full_pows[i]);
}

vec powmul(int d, vec b)
{
	for(int i = 0; i <= 30; i++)
	{
		if(d % 2 == 1) 
			b = mul(full_pows[i], b);
		d /= 2;
	}
	return b;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> len[i];
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		--x;
		--y;
		--c;
		colored[x].push_back(make_pair(y, c));
	}
	for(int i = 0; i < n; i++)
		sort(colored[i].begin(), colored[i].end());
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> f[i][j];
	
	for(int i = 0; i < 3; i++)
		color_matrices[i] = form_matrix(i);
	full_matrix = color_matrices[0];
	for(int i = 1; i < 3; i++)
		full_matrix = add(full_matrix, color_matrices[i]);
	precalc_pows();
		
	dp[0][0] = 1;
	for(int i = 0; i < n; i++)
	{
		vec cur(64);
		cur[state2int({3, 3, 3})] = 1;
		int last = 0;
		for(auto x : colored[i])
		{
			cur = powmul(x.first - last, cur);
			cur = mul(color_matrices[x.second], cur);
			last = x.first + 1;
		}
		cur = powmul(len[i] - last, cur);
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 64; k++)
			{
				vector<int> s = int2state(k);
				dp[i + 1][j ^ s[0]] = add(dp[i + 1][j ^ s[0]], mul(dp[i][j], cur[k]));
			}
	}
	cout << dp[n][0] << endl;
}
```
