# Editorial_(en)

[1175A - From Hero to Zero](../problems/A._From_Hero_to_Zero.md "Educational Codeforces Round 66 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1175A - From Hero to Zero](../problems/A._From_Hero_to_Zero.md "Educational Codeforces Round 66 (Rated for Div. 2)")

It's always optimal to divide by $k$ whenever it's possible, since dividing by $k$ equivalent to decreasing $n$ by $\frac{n}{k}(k - 1) \ge 1$.

The only problem is that it's too slow to just subtract $1$ from $n$ each time, since in the worst case we can make $O(n)$ operations (Consider case $n = 10^{18}$ and $k = \frac{n}{2} + 1$).

But if we'd look closer then we can just replace $x$ times of subtract $1$ with one subtraction of $x$. And to make $n$ is divisible by $k$ we should make $x = (n \mod{k})$ subtractions.

 **Solution (Roms)**
```cpp
#include<bits/stdc++.h>

using namespace std;

long long n, k;

int main(){
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; ++i){
    	cin >> n >> k;
    	long long res = 0;
    	while(n > 0){
    	    if(n % k == 0){
    	        n /= k;
    	        ++res;
    	    }
    	    else{
    	        long long rem = n % k;
    	        res += rem;
    	        n -= rem;
    	    }
    	}
    	
    	cout << res << endl;
    }
	return 0;
}
```
[1175B - Catch Overflow!](../problems/B._Catch_Overflow!.md "Educational Codeforces Round 66 (Rated for Div. 2)")

Idea: [awoo](https://codeforces.com/profile/awoo "Master awoo")

 **Tutorial**
### [1175B - Catch Overflow!](../problems/B._Catch_Overflow!.md "Educational Codeforces Round 66 (Rated for Div. 2)")

One can notice (or actually derive using some maths) that the answer is the sum of products of nested for loops iterations for every "add" command.

Let's learn to simulate that in linear complexity. Maintain the stack of multipliers: on "for $n$" push the top of stack multiplied by $n$ to the stack, on "end" pop the last value, on "add" add the top of the stack to the answer.

The problem, however, is the values are really large. Notice that once you add the value greater or equal to $2^{32}$ to the answer, it immediately becomes "OVERFLOW!!!". Thus let's push not the real multiplier to the stack but min(multiplier, $2^{32}$). That way the maximum value you can achieve is about $2^{32} \cdot 50000$, which fits into the 64-bit integer.

Overall complexity: $O(n)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++) 

using namespace std;

const long long INF = 1ll << 32;

int main(){
	int l;
	cin >> l;
	
	stack<long long> cur;
	cur.push(1);
	
	long long res = 0;
	forn(_, l){
		string t;
		cin >> t;
		if (t == "for"){
			int x;
			cin >> x;
			cur.push(min(INF, cur.top() * x));
		}
		else if (t == "end"){
			cur.pop();
		}
		else{
			res += cur.top();
		}
	}
	
	if (res >= INF)
		cout << "OVERFLOW!!!" << endl;
	else
		cout << res << endl;
}
```
[1175C - Electrification](../problems/C._Electrification.md "Educational Codeforces Round 66 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1175C - Electrification](../problems/C._Electrification.md "Educational Codeforces Round 66 (Rated for Div. 2)")

First observation: $k$ closest points to any point $x$ form a contiguous subsegment $a_i, \dots, a_{i + k - 1}$, so $f_k(x) = \min(|a_{i - 1} - x|, |a_{i + k} - x|)$.

Second observation: for any contiguous subsegment $a_i, \dots, a_{i + k - 1}$ all points $x$ this subsegment closest to, also form a contiguous segment $[l_i, r_i]$. And, because of the nature of $f_k(x)$, value of $f_k(x)$ is minimal in borders $l_i$ and $r_i$.

So, all we need is to check all $l_i$ and $r_i$. But what is a value of $r_i$? It's such point, that $|a_i - r_i| \le |a_{i + k} - r_i|$, but $|a_i - (r_i + 1)| > |a_{i + k} - (r_i + 1)|$. So, it's just in the middle of segment $[a_i, a_{i + k}]$. Note, that $r_i + 1 = l_{i + 1}$ and $f_k(l_{i + 1}) \ge f_k(r_i)$, so it's enough to check only $r_i$-s.

In result, all we need is to find minimal possible value $|a_{i + k} - a_i|$ and resulting $x = a_i + \frac{a_{i + k} - a_{i}}{2}$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

int n, k;
vector<int> a;

inline bool read() {
	if(!(cin >> n >> k))
		return false;
	a.resize(n);
	fore(i, 0, n)
		cin >> a[i];
	return true;
}

inline void solve() {
	pair<int, int> ans = {int(1e9) + 7, -1};
	fore(i, 0, n - k) {
		int dist = a[i + k] - a[i];
		ans = min(ans, make_pair(dist, a[i] + dist / 2));
	}
	
	cout << ans.second << endl;
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
[1175D - Array Splitting](../problems/D._Array_Splitting.md "Educational Codeforces Round 66 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1175D - Array Splitting](../problems/D._Array_Splitting.md "Educational Codeforces Round 66 (Rated for Div. 2)")

Let's denote $S(k)$ as $\sum\limits_{i = k}^{n}{a_i}$ (just a suffix sum). And let $p_i$ be the position where starts the $i$-th subarray (obviously, $p_1 = 1$ and $p_i < p_{i + 1}$). Then we can make an interesting transformation: $$\sum_{i=1}^{n}{a_i \cdot f(i)} = 1 \cdot (S(p_1) - S(p_2)) + 2 \cdot (S(p_2) - S(p_3)) + \dots + k \cdot (S(p_k) - 0) = \\\ = S(p_1) + (2 - 1) S(p_2) + (3 - 2) S(p_3) + \dots + (k - (k - 1))) S(p_k) = \\\ = S(p_1) + S(p_2) + S(p_3) + \dots + S(p_k).$$ So, our task is equivalent to choosing sum of all array $S(1)$ and $k - 1$ different suffix sums. And we want to maximize their total sum.

That's why we can just greedily take $k - 1$ maximum suffix sums along with sum of all array.

 **Solution (Roms)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 300009;

int n, k;
int a[N];

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	
	long long sum = 0;
	vector <long long> v;
	for(int i = n - 1; i >= 0; --i){
	    sum += a[i];
	    if(i > 0) v.push_back(sum);
	}
	
	long long res = sum;
	
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	
	
	for(int i = 0; i < k - 1; ++i)
	    res += v[i];
	    
	cout << res << endl;
	return 0;
}
```
[1175E - Minimal Segment Cover](../problems/E._Minimal_Segment_Cover.md "Educational Codeforces Round 66 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1175E - Minimal Segment Cover](../problems/E._Minimal_Segment_Cover.md "Educational Codeforces Round 66 (Rated for Div. 2)")

Let's take a look at a naive approach at first.

That approach is greedy. Let's find such an interval which starts to the left or at $x$ and ends as much to the right as possible. Set $x$ to its right border. Continue until either no interval can be found or $y$ is reached.

The proof basically goes like this. Let there be some smaller set of intervals which cover the query, these can be sorted by left border (obviously their left borders are pairwise distinct). Compare that set to the greedy one, take a look at the first position where best set's interval has his $r$ less than the greedy set's $r$. You can see that choosing interval greedily will still allow to have the rest of best set intervals, making the greedy choice optimal.

Let's implement it in $O(nlogn + nm)$. For each position from $0$ to $5 \cdot 10^5$ you can precalculate the index of such an interval that it starts to the left or at this position and ends as much to the right as possible. To do this sort all intervals by their left border, then iterate over positions, while maintaining the maximum right border achieved by intervals starting to the left or at the current position. The query is now straightforward.

Now there are two main ways to optimize it.

You can do it binary lifting style: for each interval (or position) precalculate the index of the interval taken last after taking $2^k$ intervals greedily and use this data to answer queries in $O(\log n)$.

You can also do it path compression style. Let's process the queries in the increasing order of their right borders. Now do greedy algorithm but for each interval you use remember the index of the last reached interval. Now the part with answering queries is $O(n + m)$ in total because each interval will be jumped from no more than once.

Overall complexity: $O((n + m) \log n)$ / $O(n \log n + m \log m)$.

 **Solution 1 (PikMike)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define forn(i, n) for(int i = 0; i < int(n); i++) 

const int N = 500 * 1000 + 13;
const int LOGN = 18;

int n, m;
pair<int, int> a[N], q[N];

int nxt[N];
int up[LOGN][N];

int main(){
	scanf("%d%d", &n, &m);
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	forn(i, m)
		scanf("%d%d", &q[i].x, &q[i].y);
	
	sort(a, a + n);
	
	int lst = 0;
	pair<int, int> mx(0, -1);
	forn(i, N){
		while (lst < n && a[lst].x == i){
			mx = max(mx, make_pair(a[lst].y, lst));
			++lst;
		}
		nxt[i] = (mx.x <= i ? -1 : mx.y);
	}
	
	forn(i, n)
		up[0][i] = nxt[a[i].y];
	for (int j = 1; j < LOGN; ++j) forn(i, n){
		if (up[j - 1][i] == -1)
			up[j][i] = -1;
		else
			up[j][i] = up[j - 1][up[j - 1][i]];
	}
	
	forn(i, m){
		int x = nxt[q[i].x];
		
		if (x == -1){
			puts("-1");
			continue;
		}
		
		int res = 1;
		for (int j = LOGN - 1; j >= 0; --j){
			int y = up[j][x];
			if (y == -1)
				continue;
			if (a[y].y < q[i].y){
				res += (1 << j);
				x = y;
			}
		}
		
		if (a[x].y >= q[i].y)
			printf("%dn", res);
		else if (up[0][x] == -1)
			puts("-1");
		else
			printf("%dn", res + 1);
	}
}
```
 **Solution 2 (PikMike)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define forn(i, n) for(int i = 0; i < int(n); i++) 

const int N = 500 * 1000 + 13;

int n, m;
pair<int, int> a[N], q[N];

int nxt[N];
int ans[N];

pair<int, int> p[N];

pair<int, int> get(int x, int r){
	if (x == -1)
		return make_pair(-1, -1);
	if (a[x].y >= r)
		return make_pair(x, 0);
	auto res = get(p[x].x, r);
	if (res.x == -1)
		p[x] = make_pair(-1, -1);
	else
		p[x] = make_pair(res.x, p[x].y + res.y);
	return p[x];
}

int main(){
	scanf("%d%d", &n, &m);
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	forn(i, m)
		scanf("%d%d", &q[i].x, &q[i].y);
	sort(a, a + n);
	
	int lst = 0;
	pair<int, int> mx(0, -1);
	forn(i, N){
		while (lst < n && a[lst].x == i){
			mx = max(mx, make_pair(a[lst].y, lst));
			++lst;
		}
		nxt[i] = (mx.x <= i ? -1 : mx.y);
	}
	
	vector<int> perm(m);
	iota(perm.begin(), perm.end(), 0);
	sort(perm.begin(), perm.end(), [](int a, int b){
		return q[a].y < q[b].y;
	});
	
	forn(i, n)
		p[i] = make_pair(nxt[a[i].y], nxt[a[i].y] == -1 ? -1 : 1);
	
	for (auto i : perm){
		int x = nxt[q[i].x];
		auto res = get(x, q[i].y).y;
		ans[i] = (res == -1 ? -1 : res + 1);
	}
	
	forn(i, m)
		printf("%dn", ans[i]);
}
```
[1175F - The Number of Subpermutations](../problems/F._The_Number_of_Subpermutations.md "Educational Codeforces Round 66 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1175F - The Number of Subpermutations](../problems/F._The_Number_of_Subpermutations.md "Educational Codeforces Round 66 (Rated for Div. 2)")

At first, let's represent permutations in the next form. We assign to all numbers from $1$ to $n$ random 128-bit strings, so the $i$-th number gets the string $h_i$. Then the permutation of length $len$ can be hashed as $h_1 \oplus h_2 \oplus \dots \oplus h_{len}$, where $\oplus $ is bitwise exclusive OR (for example, $0110 \oplus 1010 = 1100$). This representation is convenient because if we have two sets of numbers with a total number of elements equal to $len$ (let's represent them as $s_1, s_2, \dots s_m$ and $t_1, t_2, \dots t_k$, $k + m = len$), we can easily check whether their union is a permutation of length $len$ (condition $h_{s_1} \oplus h_{s_2} \oplus \dots \oplus h_{s_m} \oplus h_{t_1} \oplus h_{t_2} \oplus \dots h_{t_k} = h_1 \oplus h_2 \oplus \dots \oplus h_{len}$ must be hold). 

Let's denote $f(l, r)$ as $h_{a_l} \oplus h_{a_l + 1} \oplus \dots \oplus h_{a_r}$.

Now let's iterate over position $i$ such that $a_i = 1$ and calculate the number of permutations that contain this element. To do it, let's iterate over the right boundary $r$ and suppose, that maximum element of permutation $len$ (and its length at the same time) is one of positions $i + 1, i + 2, \dots , r$. If it's true, then the subpermutation should be on the positions $r - len + 1, r - len + 2, \dots , r$. And to check that this segment is a subpermutation we should just compare $f(r - len + 1, r)$ and $h_1 \oplus h_2 \oplus \dots \oplus h_{len}$.

Thus, we will calculate all permutations in which the position of the maximum is to the right of the position of the $1$. To calculate all permutations we need to reverse array $a$ and repeat this algorithm, and then add the number of ones in the array $a$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pt;

const int N = int(3e5) + 99;
const pt zero = make_pair(0, 0);

int n;
int a[N];
pt hsh[N], sumHsh[N];

void upd(pt &a, pt b){
    a.first ^= b.first;
    a.second ^= b.second;
}

int calc(int pos){
	set <int> sl, sr;
	set<pt> s;
	int r = pos + 1, l = pos - 1;
	pt curr = hsh[0], curl = zero;
	s.insert(zero);
	sr.insert(0), sl.insert(0);
	
	int res = 0;	
	while(r < n && !sr.count(a[r])){
		sr.insert(a[r]);
		upd(curr, hsh[a[r]]);
		++r;

		while(l >= 0 && !sl.count(a[l]) && a[l] < *sr.rbegin()){
			sl.insert(a[l]);
			upd(curl, hsh[a[l]]);
			s.insert(curl);
			--l;	
		}

		pt need = sumHsh[*sr.rbegin()];
		upd(need, curr);
		if(s.count(need)) ++res;
	}	

	return res;
}	

int main() {
    long long x = 0;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		--a[i];	
		x ^= a[i];
	}
	
	
	mt19937_64 rnd(time(NULL));
	for(int i = 0; i < N; ++i){
		hsh[i].first = rnd() ^ x;
		hsh[i].second = rnd() ^ x;
		sumHsh[i] = hsh[i];
		if(i > 0) upd(sumHsh[i], sumHsh[i - 1]);
	}
	
	int res = 0;
		
	for(int tc = 0; tc < 2; ++tc){
		for(int i = 0; i < n; ++i)
			if(a[i] == 0)
				res += calc(i) + (tc == 0);
		reverse(a, a + n);
	}
	cout << res << endl;

	return 0;
} 
```
[1175G - Yet Another Partiton Problem](../problems/G._Yet_Another_Partiton_Problem.md "Educational Codeforces Round 66 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1175G - Yet Another Partiton Problem](../problems/G._Yet_Another_Partiton_Problem.md "Educational Codeforces Round 66 (Rated for Div. 2)")

Important note: the author solution is using both linear Convex hull trick and persistent Li Chao tree. As mentioned in commentaries, applying the Divide-and-Conquer technique can help get rid of Li Chao tree. More about both structures you can read in [this article](https://codeforces.com/https://cp-algorithms.com/geometry/convex_hull_trick.html).

Let's try to write standard dp we can come up with (arrays will be 0-indexed). Let $dp[k][i]$ be the minimal weight if we splitted prefix of length $i$ in $k$ subsegments. Then we can calculate it as: $dp[k][i] = \min\limits_{0 \le j < i}(dp[k - 1][j] + (i - j) \cdot \max\limits_{j \le k < i}(a[k]))$ [1]. Maximums on segments are inconvenient, let's try to group segments $[j, i)$ by the value of $\max{}$. 

So, we can find such sequence of borders $j_0 = i - 1 > j_1 > j_2 > \dots$, where for each $j \in (j_{l + 1}, j_l]$ $\max\limits_{j \le k < i}(a[k]) = a[j_l]$. In other words, $j_0 = i - 1$ and $j_{l + 1}$ is the closest from the left position, where $a[j_{l + 1}] \ge a[j_l]$. Note, that we can maintain this sequence with stack of maximums.

Ok, then for each interval $(j_{l + 1}, j_l]$ equation [1] transforms to: $$\min_{j_{l+1} < j \le j_l}(dp[k - 1][j] + (i - j) \cdot a[j_l]) = a[j_l] \cdot i + \min_{j_{l+1} < j \le j_l}(-j \cdot a[j_l] + dp[k - 1][j]) = \\\ = a[j_l] \cdot y + \min_{j_{l+1} < j \le j_l}(-j \cdot x + dp[k - 1][j]) |_{y = i, x = a[j_l]}.$$

Why did we use variables $x$ and $y$? Because there are two problems: $y$ is needed because we iterate over $i$ and can't recalculate everything; $x$ is needed because sequence $j_l$ is changing over time, so do the $a[j_l]$. But what we can already see: we can maintain for each segment Convex hull with linear functions — so we can take $f_l = \min\limits_{j_{l+1} < j \le j_l}(\dots)$ in logarithmic time. Moreover, we can store values $a[j_l] \cdot y + f_l$ in other Convex hull to take minimum over all segments in logarithmic time.

The problems arise when we try modificate structures while iterating $i$. Fortunately, segments $j_l$ change not at random, but according to stack of maximums. So all we should handle are: 

* to merge segment on top of the stack $(j_1, j_0]$ with current segment $(j_0, i]$ (in case when $a[i] > a[j_0]$);
* to erase segment on top of the stack along with its value $a[j_0] \cdot y + f_0$;
* to insert new segment on top of the stack along with its value $a[j_0] \cdot y + f_0$.

To handle the third type is easy, since all Convex hulls can insert elements. There will be at most $O(n)$ such operations on a single layer $k$ and we can ask value $f_0$ in $O(\log{n})$ and insert a line with $O(\log{A})$.

To handle the second type is harder, but possible, since we can make Convex hull persistent and store its versions in the stack. Persistent Convex hull — persistent Li Chao tree. There will be also $O(nk)$ operations in total and they cost us $O(1)$.

To handle the first type is trickiest part. Note, that all line coefficients of one convex hull are strictly lower than all line coefficients of the other. So, we can use linear Convex hulls to make insertions to back in amortized $O(1)$. But to merge efficiently, we should use Small-to-Large technique, that's why we should be able also push front in $O(1)$, and, moreover, still be able to ask minimum in $O(\log{n})$. And here comes the hack — $deque$ in C++, which can push/pop front/back in amortized $O(1)$ and also have random access iterator to make binary search possible. So, each element of every segment will be transfered $O(\log{n})$ times with cost of amortized $O(1)$ on a single layer $k$.

In the end, result complexity is $O(n k (\log{C} + \log{n}))$. Space complexity is $O(n \log{A})$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) (int)((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<li, li> pt;

const int INF = int(1e9);
const li INF64 = li(1e9);

pt operator -(const pt &a, const pt &b) {
    return {a.x - b.x, a.y - b.y};
}
li operator *(const pt &a, const pt &b) {
    return a.x * b.x + a.y * b.y;
}
li operator %(const pt &a, const pt &b) {
    return a.x * b.y - a.y * b.x;
}
pt rotate(const pt &p) {
    return {-p.y, p.x};
}

struct LinearHull {
    deque<pt> pts, vecs;

    void addRight(const pt &l) {
        while(!vecs.empty() && vecs.back() * (l - pts.back()) < 0) {
            vecs.pop_back();
            pts.pop_back();
        }
        if(!pts.empty())
            vecs.push_back(rotate(l - pts.back()));
        pts.push_back(l);
    }
    void addLeft(const pt &l) {
        while(!vecs.empty() && vecs.front() * (l - pts.front()) < 0) {
            vecs.pop_front();
            pts.pop_front();
        }
        if(!pts.empty())
            vecs.push_front(rotate(pts.front() - l));
        pts.push_front(l);
    }

    li getMin(const pt &x) {
        auto it = lower_bound(vecs.begin(), vecs.end(), x, [](const pt &a, const pt &b) {
            return a % b > 0;
        });
        return x * pts[it - vecs.begin()];
    }
};

typedef unique_ptr<LinearHull> pHull;

void mergeHulls(pHull &a, pHull &b) {
    if(sz(b->pts) >= sz(a->pts)) {
        for(auto &p : a->pts)
            b->addRight(p);
    } else {
        for(auto it = b->pts.rbegin(); it != b->pts.rend(); it++)
            a->addLeft(*it);
        swap(a, b);
    }
}

const int M = 1000 * 1000 + 555;
int szn = 0;
struct node {
    pt line;
    node *l, *r;

    node() : line(), l(nullptr), r(nullptr) {}
    node(pt line, node *l, node *r) : line(move(line)), l(l), r(r) {}
} nodes[M];

typedef node* tree;

tree getNode(const pt &line, tree l, tree r) {
    assert(szn < M);
    nodes[szn] = node(line, l, r);
    return &nodes[szn++];
}
tree copy(tree v) {
    if(v == nullptr) return v;
    return getNode(v->line, v->l, v->r);
}

li f(const pt &line, int x) {
    return line * pt{x, 1};
}

tree addLine(tree v, int l, int r, pt line) {
    if(!v)
        return getNode(line, nullptr, nullptr);
    int mid = (l + r) >> 1;
    bool lf = f(line, l) < f(v->line, l);
    bool md = f(line, mid) < f(v->line, mid);

    if(md)
        swap(v->line, line);

    if(l + 1 == r)
        return v;
    else if(lf != md)
        v->l = addLine(copy(v->l), l, mid, line);
    else
        v->r = addLine(copy(v->r), mid, r, line);
    return v;
}

li getMin(tree v, int l, int r, int x) {
    if(!v) return INF64;
    if(l + 1 == r)
        return f(v->line, x);
    int mid = (l + r) >> 1;

    if(x < mid)
        return min(f(v->line, x), getMin(v->l, l, mid, x));
    else
        return min(f(v->line, x), getMin(v->r, mid, r, x));
}

int n, k;
vector<li> a;

inline bool read() {
    if(!(cin >> n >> k))
        return false;
    a.resize(n);

    fore(i, 0, n)
        cin >> a[i];
    return true;
}

struct state {
    int pos;
    pHull hull;
    tree v;

    state() : pos(-1), hull(nullptr), v(nullptr) {}
};

vector<li> d[2];

inline void solve() {
    int maxn = (int)*max_element(a.begin(), a.end()) + 3;
    fore(k, 0, 2)
        d[k].resize(n + 1, INF64);

    d[0][0] = 0;
    fore(_k, 1, k + 1) {
        szn = 0;

        int ck = _k & 1;
        int nk = ck ^ 1;

        vector< state > st;

        fore(i, 0, sz(d[ck])) {
            d[ck][i] = INF64;
            if(!st.empty())
                d[ck][i] = getMin(st.back().v, 0, maxn, i);

            if(i >= sz(a))
                continue;

            state curVal;
            curVal.pos = i;
            curVal.hull = make_unique<LinearHull>();
            curVal.hull->addRight({-i, d[nk][i]});
            curVal.v = nullptr;

            while(!st.empty() && a[st.back().pos] < a[i]) {
                mergeHulls(st.back().hull, curVal.hull);
                st.pop_back();
            }
            if(!st.empty())
                curVal.v = st.back().v;

            li val = curVal.hull->getMin({a[i], 1});
            curVal.v = addLine(copy(curVal.v), 0, maxn, {a[i], val});

            st.push_back(move(curVal));
        }
    }
    cout << d[k & 1][n] << endl;
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
