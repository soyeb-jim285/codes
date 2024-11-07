# Tutorial_1_(en)

[1195A - Drinks Choosing](../problems/A._Drinks_Choosing.md "Codeforces Round 574 (Div. 2)")

Idea: [budalnik](https://codeforces.com/profile/budalnik "International Master budalnik")

Preparation: [budalnik](https://codeforces.com/profile/budalnik "International Master budalnik")

 **Tutorial**
### [1195A - Drinks Choosing](../problems/A._Drinks_Choosing.md "Codeforces Round 574 (Div. 2)")

Let's take a look on a students. If two students have the same favorite drink, let's take one set with this drink. Let the number of such students (which we can satisfy as pairs) be $good$. Because the number of sets is $\lceil\frac{n}{2}\rceil$ we always can do it. So there are students which are the only with their favorite drinks remain. It is obvious that if we take one set we can satisfy at most one student (and one of the others will gain not his favorite drink). Let the number of such students (which remain after satisfying pairs of students) be $bad$. Then the answer is $good + \lceil\frac{bad}{2}\rceil$.

 **Solution**
```cpp
// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n, k;
	cin >> n >> k;
	map<int, int> have;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		have[num]++;
	}
	int cnt = 0;
	int ans = 0;
	for (pii p : have) {
		cnt += p.ss % 2;
		ans += p.ss / 2 * 2;
	}
	ans += (cnt + 1) / 2;
	cout << ans << "n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " msn";
#endif
}
```
[1195B - Sport Mafia](../problems/B._Sport_Mafia.md "Codeforces Round 574 (Div. 2)")

Idea: ?

Preparation: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") and [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot")

 **Tutorial**
### [1195B - Sport Mafia](../problems/B._Sport_Mafia.md "Codeforces Round 574 (Div. 2)")

In fact, we need to solve the following equation: $\frac{x(x+1)}{2} - (n - x) = k$ and when we will find $x$ we need to print $n-x$ as the answer. $\frac{x(x+1)}{2}$ is the number of candies Alya will put into the box with $x$ turns (sum of arithmetic progression). This equation can be solved mathematically. The only problem is getting the square root, it can be avoided with binary search or taking square root in non-integer numbers and checking some amount of integers in small range nearby the obtained root. The other solution is the binary search by $x$. 

 **Solution (binary search)**
```cpp
#include <iostream>
#include <cmath>

int main() {
    long long n, k;
    std::cin >> n >> k;
    long long l = -1, r = n + 1;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if ((n - m) * (n - m + 1) / 2 - m > k)
            l = m;
        else
            r = m;
    }
    std::cout << r;
    return 0;
}
```
 **Solution (formula)**
```cpp
#include <iostream>
#include <cmath>

int main() {
    long long n, k;
    std::cin >> n >> k;
    std::cout << static_cast<long long>(round(n + 1.5 - sqrt(2 * (n + k) + 2.75)));
    return 0;
}
```
[1195C - Basketball Exercise](../problems/C._Basketball_Exercise.md "Codeforces Round 574 (Div. 2)")

Idea: [meshanya](https://codeforces.com/profile/meshanya "Grandmaster meshanya")

Preparation: [tsarn](https://codeforces.com/profile/tsarn "Master tsarn")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> inp;
	for (int i = 0; i < 2; ++i) {
		inp.push_back(vector<int>());
		for (int j = 0; j < n; ++j) {
			int num;
			cin >> num;
			inp[i].push_back(num);
		}
	}

	pll d = {0, 0};

	for (int i = 0; i < n; ++i) {
		pll next = {max(d.ff, d.ss + inp[0][i]), max(d.ss, d.ff + inp[1][i])};
		d = next;
	}

	cout << max(d.ff, d.ss) << "n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " msn";
#endif
}
```
[1195D1 - Submarine in the Rybinsk Sea (easy edition)](../problems/D1._Submarine_in_the_Rybinsk_Sea_(easy_edition).md "Codeforces Round 574 (Div. 2)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

Preparation: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1195D1 - Submarine in the Rybinsk Sea (easy edition)](../problems/D1._Submarine_in_the_Rybinsk_Sea_(easy_edition).md "Codeforces Round 574 (Div. 2)")

Let's take a look into some number $a = a_1, a_2, \dots, a_{len}$, where $len$ is the length of each number in the array. We know that in $n$ cases it will be the first argument of the function $f(a, b)$ (where $b$ is some other number), and in $n$ cases it will be the second argument. What it means? It means that $a_1$ will have multiplier $10^{2len-1} \cdot 10^{2len-2} \cdot n$, $a_2$ will have multiplier $10^{2len-3} \cdot 10^{2len-4} \cdot n$, and so on. If we take a look closer, $a$ will add to the answer exactly $f(a, a) \cdot n$. So the final answer is $n\sum\limits_{i=1}^{n} f(a_i, a_i)$. Don't forget about modulo and overflow (even $64$-bit datatype can overflow in this problem, because $f(10^9, 10^9)$ has $20$ digits in decimal notation).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}

int mul(int a, int b) {
	return a * 1ll * b % MOD;
}

int len;
vector<int> pw10;

int f(int a) {
	int pos = 0;
	int res = 0;
	while (a > 0) {
		int cur = a % 10;
		a /= 10;
		res = add(res, mul(cur, pw10[2 * pos]));
		res = add(res, mul(cur, pw10[2 * pos + 1]));
		++pos;
	}
	return res;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	pw10 = vector<int>(30);
	pw10[0] = 1;
	for (int i = 1; i < 30; ++i) {
		pw10[i] = mul(pw10[i - 1], 10);
	}
	
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		len = to_string(a).size();
		ans = add(ans, mul(n, f(a)));
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1195D2 - Submarine in the Rybinsk Sea (hard edition)](../problems/D2._Submarine_in_the_Rybinsk_Sea_(hard_edition).md "Codeforces Round 574 (Div. 2)")

Idea: [meshanya](https://codeforces.com/profile/meshanya "Grandmaster meshanya")

Preparation: [sava-cska](https://codeforces.com/profile/sava-cska "Grandmaster sava-cska")

 **Tutorial**
### [1195D2 - Submarine in the Rybinsk Sea (hard edition)](../problems/D2._Submarine_in_the_Rybinsk_Sea_(hard_edition).md "Codeforces Round 574 (Div. 2)")

Let $cnt_{len}$ be the number of $a_i$ with length $len$. We will calculate each number's contribution in the answer separately.

When we calculate the contribution of the current number in the answer, let's iterate over all lengths $l$ from $1$ to $L$ where $L$ is the maximum length of some number in the array and add the following value to the answer: $cnt_{l} \cdot (fl_{a_i, l} + fr_{a_i, l})$.

The function $fl_{x, l}$ means that we merge the number $x$ with some (it does not matter) number of length $l$ and digits of $x$ will be on odd positions in the resulting number (except some leading digits which will be on odd and on even position as well). And the function $fr_{x, l}$ does almost the same thing but it counts digits of $x$ on even positions.

Time complexity is $O(n)$ with the constant factor $L^2$.

 **Solution**
```cpp
// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const int MOD = 998244353;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

int f(vector<int> const& a, int l) {
	int res = 0;
	int p = 1;
	for (int i = 0; i < max(szof(a), l); ++i) {
		if (i < l) {
			p = mult(p, 10);
		}
		if (i < szof(a)) {
			add(res, mult(a[i], p));
			p = mult(p, 10);
		}
	}
	return res;
}

int f(int l, vector<int> const& b) {
	int res = 0;
	int p = 1;
	for (int i = 0; i < max(l, szof(b)); ++i) {
		if (i < szof(b)) {
			add(res, mult(b[i], p));
			p = mult(p, 10);
		}
		if (i < l) {
			p = mult(p, 10);
		}
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr;
	const int MAXL = 11;
	vector<int> of_len(MAXL);
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		int l = 0;
		int tmp = num;
		while (tmp) {
			++l;
			tmp /= 10;
		}
		of_len[l]++;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		vector<int> digits;
		int tmp = arr[i];
		while (tmp) {
			digits.push_back(tmp % 10);
			tmp /= 10;
		}
		for (int l = 1; l < MAXL; ++l) {
			int sum = f(digits, l);
			add(ans, mult(sum, of_len[l]));


			sum = f(l, digits);
			add(ans, mult(sum, of_len[l]));
		}
	}

	cout << ans << "n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " msn";
#endif
}
```
[1195E - OpenStreetMap](../problems/E._OpenStreetMap.md "Codeforces Round 574 (Div. 2)")

Idea: [budalnik](https://codeforces.com/profile/budalnik "International Master budalnik")

Preparation: [ima_ima_go](https://codeforces.com/profile/ima_ima_go "Specialist ima_ima_go")

 **Tutorial**
### [1195E - OpenStreetMap](../problems/E._OpenStreetMap.md "Codeforces Round 574 (Div. 2)")

There is almost nothing to say about this problem. It is pretty standard data structure problem.

Let $mn_{i, j}$ be the minimum value over all values $h_{i, j}, h_{i - 1, j}, \dots, h_{i - a + 1}{j}$. If $i$ is less than $a$ then its value does not matter for us because the corresponding submatrix is not counted in the answer. These values can be calculated using std::deque or minimum queue. You can read more about it here: [https://cp-algorithms.com/data_structures/stack_queue_modification.html](https://codeforces.com/https://cp-algorithms.com/data_structures/stack_queue_modification.html).

After building such matrix $mn$ we can actually calculate the answer. Let's iterate over all rows of the matrix (starting from row $a$) $i$ and carry the floating window of width $b$ of values $mn_{i, j}$. And when the size of the queue with minimums reaches $b$ we know the minimum on the corresponding submatrix that ends in the current element and we can add it to the answer.

Time complexity: $O(nm)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

long long n, m, a, b, g, x, y, z;
vector<deque<long long> > deq;
vector<vector<long long> > mi;
vector<int> power;
const long long MAX_V = 1000000000000000ll;

void ins(deque<long long>& de, long long val) {
    while(!de.empty() && de.back() > val) {
        de.pop_back();
    }
    de.push_back(val);
}

void del(deque<long long>& de, long long val) {
    if (!de.empty() && de.front() == val) {
        de.pop_front();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> a >> b;
    cin >> g >> x >> y >> z;
    mi.resize(n);
    deq.resize(m);
    for (int i = 0; i < n; i++) {
        mi[i].resize(m);
        for (int j = 0; j < m; j++) {
            mi[i][j] = g;
            g = (g * x + y) % z;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < a; j++) {
            ins(deq[i], mi[j][i]);
        }
    }
    deque<long long> real_deq;
    for (int i = 0; i < b; i++) {
        ins(real_deq, deq[i].front());
    }
    long long ans = 0;
    ans += real_deq.front();
    for (int i = b; i < m; i++) {
        del(real_deq, deq[i - b].front());
        ins(real_deq, deq[i].front());
        ans += real_deq.front();
    }
    for (int i = a; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            ins(deq[j], mi[i][j]);
            del(deq[j], mi[i - a][j]);
        }
        deque<long long> real_d;
        for (int j = 0; j < b; j++) {
            ins(real_d, deq[j].front());
        }
        ans += real_d.front();
        for (int j = b; j < m; j++) {
            del(real_d, deq[j - b].front());
            ins(real_d, deq[j].front());
            ans += real_d.front();
        }
    }
    cout << ans << "n";
}
```
[1195F - Geometers Anonymous Club](../problems/F._Geometers_Anonymous_Club.md "Codeforces Round 574 (Div. 2)")

Idea: [craborac](https://codeforces.com/profile/craborac "International Grandmaster craborac")

Preparation: [budalnik](https://codeforces.com/profile/budalnik "International Master budalnik")

 **Tutorial**
### [1195F - Geometers Anonymous Club](../problems/F._Geometers_Anonymous_Club.md "Codeforces Round 574 (Div. 2)")

Suppose we want to compute the Minkowski sum of two polygons $a$ and $b$. Let's denote two sequences of free vectors:

* $u_1$, $u_2$, ..., $u_{k_a}$ such that free vector $u_i$ is congruent to the bound vector starting in $i$-th vertex of the first polygon and ending in the $(i + 1)$-th vertex of this polygon (if $i = k_a$, then we use the $1$st point as the $(i + 1)$-th one);
* $v_1$, $v_2$, ..., $v_{k_b}$ such that free vector $v_i$ is congruent to the bound vector starting in $i$-th vertex of the second polygon and ending in the $(i + 1)$-th vertex of this polygon (if $i = k_b$, then we again use the $1$st point as the $(i + 1)$-th one).

It's impossible to choose a pair of vectors from the same sequence in such a way that they are parallel, since there are no three points lying on the same line in the same polygon (but it may be possible to find a pair of antiparallel vectors belonging to the same sequence).

Let's try to analyze how we can construct such sequence for the resulting polygon. For example, let's pick some side of the first polygon (let vector $u_i$ denote this side of the polygon) and analyze how this side can affect the resulting polygon. There are two cases:

* there is a vector $v_j$ such that it is parallel (not antiparallel) to $u_i$. Then this vector represents a side of the second polygon. If we construct the Minkowski sum of these two sides (the side represented by $u_i$ in the first polygon and the side represented by $v_j$ in the second polygon), then we will get a segment having length equal to $|u_i| + |v_j|$. The line coming through this segment divides the plane into two halfplanes, and all points belonging to the Minkowski sum of these polygons will be contained in the same halfplane. That's because all points of the first polygon belong to the same halfplane (if we divide the plane by the line coming through the side represented by $u_i$), and all points of the second polygon belong to the same halfplane (if we divide the plane by the line coming through the side represented by $v_j$) — moreover, both these halfplanes are either upper halfplanes (and then the whole resulting polygon belongs to the upper halfplane) or lower halfplanes (then result belongs to the lower halfplane). So, the resulting polygon will have a side represented by the free vector equal to $u_i + v_j$ (obviously, there can be only one such side);
* there is no such vector in the second sequence such that it is parallel to $u_i$. Then there exists exactly one vertex of the second polygon such that if we draw a line parallel to $u_i$ through this vertex, the whole second polygon will be contained in the upper halfplane or the lower halfplane (depending on whether the first polygon belongs to the upper halfplane or the lower halfplane in respect to the side parallel to $u_i$). Actually, this case can be analyzed as the case where $v_j$ exists, but has zero length: the resulting polygon will have a side represented by the vector $u_i$.

So, for every vector in the sequences constructed by the given polygons, there will be a vector parallel to it in the resulting sequence of vectors. It is quite obvious that every vector in the resulting sequence is also parallel to some vector from the first two sequences. It means that the number of sides in the Minkowski sum is equal to the number of vectors in these two sequences, but all parallel vectors count as one.

This fact can be extended to computing the Minkowski sum of multiple polygons: the resulting polygon will have the number of sides equal to the number of vectors in all sequences for given polygons, if we count all parallel vectors as one. Now we can solve the problem in such a way: construct the sequences of vectors for the given polygons and divide these vectors into equivalence classes in such a way that vectors belong to the same class if and only if they are parallel. The answer to each query is equal to the number of equivalence classes such that at least one vector belonging to this class is contained in at least one sequence on the segment of polygons; this can be modeled as the query "count the number of distinct values on the given segment of the given array". This problem can be solved with Mo's algorithm, mergesort tree or persistent segment tree.

 **Solution**
```cpp
// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

struct point {
	int x, y;
	point(int _x, int _y) : x(_x), y(_y) {}

	point operator-(point const& other) const {
		return point(x - other.x, y - other.y);
	}

	point& operator/=(int num) {
		x /= num;
		y /= num;
		return *this;
	}

	bool operator<(point const& other) const {
		return x < other.x || (x == other.x && y < other.y);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<vector<point>> polys;
	vector<point> vecs;
	vector<int> borders;
	borders.push_back(0);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		borders.push_back(borders.back() + k);
		polys.push_back({});
		for (int j = 0; j < k; ++j) {
			int x, y;
			cin >> x >> y;
			polys.back().push_back(point(x, y));
		}

		for (int j = 0; j < k; ++j) {
			int next = (j + 1) % k;
			point v = polys[i][next] - polys[i][j];
			int tmp = __gcd(abs(v.x), abs(v.y));
			v /= tmp;
			vecs.push_back(v);
		}
	}

	vector<int> arr;
	map<point, int> inds;
	for (auto v : vecs) {
		if (!inds.count(v)) {
			int tmp = szof(inds);
			inds[v] = tmp;
		}
		arr.push_back(inds[v]);
	}

	vector<int> next(szof(vecs));
	vector<int> last(szof(inds), INF);
	for (int i = szof(vecs) - 1; i >= 0; --i) {
		next[i] = last[arr[i]];
		last[arr[i]] = i;
	}


	vector<vector<pii>> here(szof(vecs));
	int q;
	cin >> q;
	vector<int> ans(q);
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		l = borders[l];
		r = borders[r];
		here[l].push_back({r, i});
	}

	int bpv = 1;
	while (bpv < szof(vecs)) {
		bpv *= 2;
	}

	vector<int> segtree(bpv * 2);

	function<void(int, int)> segtree_set = [&](int pos, int val) {
		pos += bpv;
		segtree[pos] = val;
		pos /= 2;
		while (pos) {
			segtree[pos] = segtree[pos * 2] + segtree[pos * 2 + 1];
			pos /= 2;
		}
	};

	function<int(int, int, int, int, int)> segtree_get = [&](int v, int vl, int vr, int l, int r) {
		if (vr <= l || r <= vl) {
			return 0;
		}
		if (l <= vl && vr <= r) {
			return segtree[v];
		}
		int vm = (vl + vr) / 2;
		return segtree_get(v * 2, vl, vm, l, r) + segtree_get(v * 2 + 1, vm, vr, l, r);
	};

	for (int i = 0; i < szof(inds); ++i) {
		segtree_set(last[i], 1);
	}

	for (int i = 0; i < szof(vecs); ++i) {
		for (auto p : here[i]) {
			ans[p.ss] = segtree_get(1, 0, bpv, i, p.ff);
		}
		segtree_set(i, 0);
		if (next[i] != INF) {
			segtree_set(next[i], 1);
		}
	}

	for (int num : ans) {
		cout << num << "n";
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " msn";
#endif
}

```
