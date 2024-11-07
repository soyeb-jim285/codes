# Tutorial

[1359A - Berland Poker](../problems/A._Berland_Poker.md "Educational Codeforces Round 88 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1359A - Berland Poker](../problems/A._Berland_Poker.md "Educational Codeforces Round 88 (Rated for Div. 2)")

There are many different ways to solve this problem. The easiest one, in my opinion, is to iterate on the number of jokers the winner has (let it be $a_1$) and the number of jokers the runner-up has (let it be $a_2$). Then the following conditions should be met:

* $a_1 \ge a_2$ (the winner doesn't have less jokers than the runner-up);
* $a_1 \le \frac{n}{k}$ (the number of jokers in the winner's hand does not exceed the number of cards in his hand);
* $a_1 + a_2 \le m$ (the number of jokers for these two players does not exceed the total number of jokers);
* $a_1 + (k - 1)a_2 \ge m$ (it is possible to redistribute remaining jokers among other players so that they have at most $a_2$ jokers).

Iterating on $a_1$ and $a_2$, then checking these constraints gives us a $O(n^2)$ solution. It is possible to get a constant-time solution using some greedy assumptions and math (the first player should get as many jokers as possible, while the remaining jokers should be evenly distributed among other players).

 **Solution 1 (BledDest)**
```cpp
t = int(input())

for i in range(t):
    n, m, k = map(int, input().split())
    d = n // k
    a1 = min(m, d)
    a2 = (m - a1 + k - 2) // (k - 1)
    print(a1 - a2)
```
 **Solution 2 (BledDest)**
```cpp
t = int(input())

for i in range(t):
    n, m, k = map(int, input().split())
    ans = 0
    d = n // k
    for a1 in range(m + 1):
        for a2 in range(a1 + 1):
            if(a1 > d):
                continue
            if(a1 + a2 > m):
                continue
            if(a1 + (k - 1) * a2 < m):
                continue
            ans = max(ans, a1 - a2)
    print(ans)
```
[1359B - New Theatre Square](../problems/B._New_Theatre_Square.md "Educational Codeforces Round 88 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1359B - New Theatre Square](../problems/B._New_Theatre_Square.md "Educational Codeforces Round 88 (Rated for Div. 2)")

Notice that rows can be solved completely separately of each other. Each tile takes either one or two squares but it's always in the same row.

So let's take a look at a single row. There are sequences of dot characters separated by some asterisks. Once again each of these sequences can be solved independently of the others.

Thus, we have these empty strips of empty squares $1 \times k$ which, when solved, can be summed up into the whole answer.

There are two cases, depending on if a $1 \times 2$ is cheaper than two $1 \times 1$ tiles. 

If it is then we want to use of many $1 \times 2$ tiles as possible. So given $k$, we can place $\lfloor \frac k 2 \rfloor$ $1 \times 2$ tiles and cover the rest $k - 2 \cdot \lfloor \frac k 2 \rfloor = k~mod~2$ squares with $1 \times 1$ tiles.

If it isn't cheaper then we want to cover everything with $1 \times 1$ tiles and never use $1 \times 2$ ones. So all $k$ should be $1 \times 1$.

The easier way to implement this might be the following. Let's update the price of the $1 \times 2$ tile with the minimum of $y$ and $2 \cdot x$. This way the first algorithm will produce exactly the same result of the second one in the case when a $1 \times 2$ tile isn't cheaper than two $1 \times 1$ ones.

Overall complexity: $O(nm)$ per testcase.

 **Solution (pikmike)**
```cpp
t = int(input())
for _ in range(t):
	n, m, x, y = map(int, input().split())
	ans = 0
	y = min(y, 2 * x)
	for __ in range(n):
		s = input()
		i = 0
		while i < m:
			if s[i] == '*':
				i += 1
				continue
			j = i
			while j + 1 < m and s[j + 1] == '.':
				j += 1
			l = j - i + 1
			ans += l % 2 * x + l // 2 * y
			i = j + 1
	print(ans)
```
[1359C - Mixing Water](../problems/C._Mixing_Water.md "Educational Codeforces Round 88 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**So there are two kinds of stops to consider: k hot and k cold cup and (k+1) hot and k cold cups.

The first case is trivial: the temperature is always h+c2. In the second case the temperature is always strictly greater than h+c2. Thus, if t≤h+c2, then the answer is 2.

Let's show that otherwise the answer is always achieved through the second case.

The temperature after (k+1) hot cups and k cold cups is tk=(k+1)⋅h+k⋅c2k+1. The claim is that t0>t1>…. Let's prove that by induction.

 **Proof 1**t0=h,t1=2⋅h+c3. c<h, thus t0>t1.

Now compare tk and tk+1.

 tk>tk+1 (k+1)⋅h+k⋅c2k+1>(k+2)⋅h+(k+1)⋅c2k+3 k⋅(h+c)+h2k+1>(k+1)⋅(h+c)+h2k+3 2k⋅(k⋅(h+c)+h)+3k⋅(h+c)+3h>2k⋅((k+1)⋅(h+c)+h)+(k+1)⋅(h+c)+h 2k⋅(k⋅(h+c)+h−(k+1)⋅(h+c)−h)>(k+1)⋅(h+c)+h−3k⋅(h+c)−3h 2k⋅(−(h+c))>(−2k+1)⋅(h+c)−2h 2h>(h+c) h>cWe can also show that this series converges to h+c2:

 **Proof 2**I'm sorry that I'm not proficient with any calculus but my intuition says that it's enough to show that ∀k tk>h+c2 and ∀ε∃k tk<h+c2 with k≥0.

So the first part is:

 (k+1)⋅h+k⋅c2k+1>h+c2 k⋅(h+c)+h2k+1>h+c2 2k⋅(h+c)+2h>(2k+1)⋅(h+c) 2h>h+c h>cAnd the second part is:

 (k+1)⋅h+k⋅c2k+1<h+c2+ε k⋅(h+c)+h2k+1<h+c2+ε 2k⋅(h+c)+2h<(2k+1)⋅(h+c)+(2k+1)⋅ε 2h<(h+c)+(2k+1)⋅ε h<c+(2k+1)⋅ε h−cε<2k+1So that claim makes us see that for any t greater than h+c2 the answer is always achieved from the second case.

That allows us to find such k, that the value of tk is exactly t. However, such k might not be integer. (k+1)⋅h+k⋅c2k+1=t↔ k⋅(h+c)+h2k+1=t↔ k⋅(h+c)+h=2kt+t↔ k⋅(h+c−2t)=t−h↔ k=t−hh+c−2t.

The only thing left is to compare which side is better to round k to. It seems some implementations with float numbers might fail due to precision errors. However, it's possible to do these calculations completely in integers.

Let's actually rewrite that so that the denominator is always positive k=h−t2t−h−c. Now we can round this value down and compare k and k+1.

So the optimal value is k if |k⋅(h+c)+h2k+1−t|≤|(k+1)⋅(h+c)+h2k+3−t|. So |(k⋅(h+c)+h)−t⋅(2k+1)|⋅(2k+3)≤|((k+1)⋅(h+c)+h)−t⋅(2k+3)|⋅(2k+1). Otherwise, the answer is k+1.

You can also find the optimal k with binary search but the formulas are exactly the same and you have to rely on monotonosity as well. Also, these formulas can get you the better understanding for the upper bound of the answer.

Overall complexity: O(1) or O(logh) per testcase.

 **Solution (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;


int main() {
	int tc;
	scanf("%d", &tc);
	forn(_, tc){
		int h, c, t;
		scanf("%d%d%d", &h, &c, &t);
		if (h + c - 2 * t >= 0)
			puts("2");
		else{
			int a = h - t;
			int b = 2 * t - c - h;
			int k = 2 * (a / b) + 1;
			long long val1 = abs(k / 2 * 1ll * c + (k + 1) / 2 * 1ll * h - t * 1ll * k);
			long long val2 = abs((k + 2) / 2 * 1ll * c + (k + 3) / 2 * 1ll * h - t * 1ll * (k + 2));
			printf("%dn", val1 * (k + 2) <= val2 * k ? k : k + 2);
		}
	}
	return 0;
}
```
[1359D - Yet Another Yet Another Task](../problems/D._Yet_Another_Yet_Another_Task.md "Educational Codeforces Round 88 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1359D - Yet Another Yet Another Task](../problems/D._Yet_Another_Yet_Another_Task.md "Educational Codeforces Round 88 (Rated for Div. 2)")

Alice wants to choose such a segment $[l; r]$ that $\sum \limits_{l \le i \le r} a_i - \max \limits_{l \le i \le r} a_i$ is maximum possible. 

There is a well-known problem where you have to find a segment with maximum $\sum \limits_{l \le i \le r} a_i$. That problem is solved with Kadane algorithm. Let's learn how to reduce our problem to that one.

Notice that the values in the array are unusually small. Let's iterate over the maximum value on segment. Let $mx$ be the current value. If we make all $a_i$ such that $a_i > mx$ equal to $-\infty$, then it will never be optimal to take them in a segment. Find the maximum sum subarray in that modified array and update the answer with its $sum - mx$.

Notice that you can ignore the fact if there is a value exactly equal to $mx$ on the maximum sum segment. If there isn't then you'll update the answer with a smaller value than the actual one. Let the actual maximum on the maximum sum segment be some $y$. You can see that for any value between $y$ and $mx$ the maximum sum segment will always be that chosen one. Thus, when you reach $y$, you'll update the answer with the correct value.

Overall complexity: $O(\max a_i \cdot n)$.

 **Solution (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int INF = 1e9;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	forn(i, n) scanf("%d", &a[i]);
	long long ans = 0;
	forn(mx, 31){
		long long cur = 0;
		long long best = 0;
		forn(i, n){
			int val = (a[i] > mx ? -INF : a[i]);
			cur += val;
			best = min(best, cur);
			ans = max(ans, (cur - best) - mx);
		}
	}
	printf("%lldn", ans);
	return 0;
}
```
[1359E - Modular Stability](../problems/E._Modular_Stability.md "Educational Codeforces Round 88 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1359E - Modular Stability](../problems/E._Modular_Stability.md "Educational Codeforces Round 88 (Rated for Div. 2)")

We claim that the array is stable if and only if all elements are divisible by its minimum. The proof of this fact will be at the end of the editorial.

To calculate the number of stable arrays now, we need to iterate on the minimum in the array and choose the remaining elements so that they are multiples of it. If the minimum is $i$, then the resulting elements should be divisible by $i$. There are $d = \lfloor\frac{n}{i}\rfloor$ such numbers between $1$ and $n$, and we have to choose $k - 1$ elements out of $d - 1$ (since $i$ is already chosen). The number of ways to do it can be calculated by precomputing factorials modulo $998244353$, since it is a binomial coefficient.

Proof of the claim at the beginning of the editorial:

On the one hand, since $(x \bmod a) \bmod (ba) = (x \bmod (ba)) \bmod a = x \bmod a$, if all elements in the array are divisible by some element, nothing depends on the order of these elements.

On the other hand, suppose there exists an element $a_i$ such that it is not divisible by $a_1$. Let's take $x = a_i$ and two following reorders of the array $a$: $[a_1, a_2, \dots, a_k]$ and $[a_i, a_1, a_2, \dots, a_{i - 1}, a_{i + 1}, \dots, a_k]$. For the first array, we get $x \bmod a_1 = a_i \bmod a_1$, which is non-zero; and for the second array, $a_i \bmod a_i = 0$, so the result is zero.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 500043;
const int MOD = 998244353;

int fact[N];

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
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
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

void precalc()
{
	fact[0] = 1;
	for(int i = 1; i < N; i++)
		fact[i] = mul(i, fact[i - 1]);
}

int C(int n, int k)
{
	if(k > n) return 0;
	return divide(fact[n], mul(fact[n - k], fact[k]));
}

int main()
{
	int n, k;
	cin >> n >> k;
	int ans = 0;
	precalc();
	for(int i = 1; i <= n; i++)
	{
		int d = n / i;
		ans = add(ans, C(d - 1, k - 1));
	}
	cout << ans << endl;
}
```
[1359F - RC Kaboom Show](../problems/F._RC_Kaboom_Show.md "Educational Codeforces Round 88 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1359F - RC Kaboom Show](../problems/F._RC_Kaboom_Show.md "Educational Codeforces Round 88 (Rated for Div. 2)")

Let $f(t)$ be true if it's possible to have a collision before time $t$. That function is monotonous, thus let's binary search for $t$.

For some fixed $t$ car $i$ can end up in any point from $(x_i, y_i)$ to $s_i \cdot t$ units along the ray $((x_i, y_i), (x_i + dx_i, y_i + dy_i))$. That makes it a segment.

So the collision can happen if some pair of segments intersects. Let's learn how to find that out.

The general idea is to use sweep line. So let's add the events that the $i$-th segment $(x1_i, y1_i, x2_i, y2_i)$ such that $x1_i < x2_i$ opens at $x1_i$ and closes at $x2_i$. There were no vertical segments, so $x1_i$ and $x2_i$ are always different. 

At every moment of time $T$ we want to maintain the segments ordered by their intersection with the line $x = T$. Note that if two segments change their order moving along the sweep line, then they intersect.

So we can maintain a set with a custom comparator that returns if one segment intersects the current line lower than the other one.

When adding a segment to set, you want to check it's intersections with the next segment in the order and the previous one. When removing a segment, you want to check the intersection between the next and the previous segment in the order. If any check triggers, then return true immediately. It's easy to show that if the intersection happens between some pair of segments, then the intersection between only these pairs of segment also happens.

Now for the implementation details. Precision errors play a huge role here since we use binary search and also store some stuff dependant on floats in the set.

The solution I want to tell requires no epsilon comparisons, thus it calculates the answer only with the precision of binary search.

So the first issue rises when we have to erase elements from the set. Notice that we can make a mistake when we are adding the segment and there is a segment with almost the same intersection point. That will not make the answer incorrect (that's not trivial to show but it's possible if you consider some cases). If you can find it later to remove, then it's not an issue at all. However, that will probably mess up the lower_bound in the set. 

Thus, let's save the pointer to each element in the set and remove it later by that pointer.

The second issue comes when you have to check the intersection of two segments. The error might appear when one segment $((x_i, y_i), (nx_i, ny_i))$ (let the first point be the original $(x_i, y_i)$ and the second point be calculated depending on $t$) has it's intersection point with segment $((x_j, y_j), (nx_j, ny_j))$ at exactly $(x_i, y_i)$. So the slightest miscalculations could matter a lot.

Let's learn to intersect in such a way that no epsilon comparisons are required. Firstly, we can store lines in the set instead of segments. Second, we can check the intersection of rays first and only then proceed to check the intersection of segments.

So two rays intersect if: 

* their lines intersect — easy to check in integers;
* the intersection point lies in the correct direction of both rays — the intersection point is always a pair of fractions $(\frac{Dx}{D}, \frac{Dy}{D})$ and you want to compare the signs of $dx_i$ and $\frac{Dx}{D} - x_i$.

Finally, if all the checks hold, then you can compare maximum of distances from $(x_i, y_i)$ and $(x_j, y_j)$ to the intersection point and $t$. If $t$ is greater or equal then they intersect in time. There is no way to make that comparison in integers. However, it's precision only depends on the precision of $t$ as in the error here can't affect the answer greatly.

Overall complexity: $O(n \log n \log maxt)$.

 **Solution (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define x first
#define y second

using namespace std;

const double INF = 1e13;

struct line{
	int A, B, C;
	line(){}
	line(int x1, int y1, int x2, int y2){
		A = y1 - y2;
		B = x2 - x1;
		C = -A * x1 - B * y1;
		// A is guaranteed to be non-zero
		if (A < 0) A = -A, B = -B, C = -C;
		int g = __gcd(A, __gcd(abs(B), abs(C)));
		A /= g, B /= g, C /= g;
	}
};

bool operator ==(const line &a, const line &b){
	return a.A == b.A && a.B == b.B && a.C == b.C;
}

double x;

bool operator <(const line &a, const line &b){
	double val1 = (-a.A * x - a.C) / a.B;
	double val2 = (-b.A * x - b.C) / b.B;
	return val1 < val2;
}

struct car{
	int x, y, dx, dy, s;
	line l;
	double vx, vy;
};

int n;
vector<car> a(n);

long long det(int a, int b, int c, int d){
	return a * 1ll * d - b * 1ll * c;
}

bool inter(const line &a, const line &b, long long &D, long long &Dx, long long &Dy){
	D = det(a.A, a.B, b.A, b.B);
	if (D == 0) return false;
	Dx = -det(a.C, a.B, b.C, b.B);
	Dy = -det(a.A, a.C, b.A, b.C);
	return true;
}

int sg(int x){
	return x < 0 ? -1 : 1;
}

int sg(long long a, long long b, int c){
	// sign of a/b-c
	if (b < 0) a = -a, b = -b;
	return a - c * b < 0 ? -1 : (a - c * b > 0);
}

bool inter(int i, int j, double &len){
	if (i == -1 || j == -1)
		return false;
	long long D, Dx, Dy;
	if (!inter(a[i].l, a[j].l, D, Dx, Dy))
		return false;
	if (sg(Dx, D, a[i].x) != 0 && sg(a[i].dx) != sg(Dx, D, a[i].x))
		return false;
	if (sg(Dx, D, a[j].x) != 0 && sg(a[j].dx) != sg(Dx, D, a[j].x))
		return false;
	double x = Dx / double(D);
	double y = Dy / double(D);
	double di = (a[i].x - x) * (a[i].x - x) + (a[i].y - y) * (a[i].y - y);
	double dj = (a[j].x - x) * (a[j].x - x) + (a[j].y - y) * (a[j].y - y);
	return len * len >= di / a[i].s && len * len >= dj / a[j].s;
}

vector<set<pair<line, int>>::iterator> del;
set<pair<line, int>> q;

void get_neighbours(int i, int &l, int &r){
	l = r = -1;
	auto it = q.lower_bound({a[i].l, -1});
	if (it != q.end())
		r = it->y;
	if (!q.empty() && it != q.begin()){
		--it;
		l = it->y;
	}
}

bool check(double t){
	vector<pair<double, pair<int, int>>> cur;
	del.resize(n);
	forn(i, n){
		double x1 = a[i].x;
		double x2 = a[i].x + a[i].vx * t;
		if (x1 > x2) swap(x1, x2);
		cur.push_back({x1, {i, 0}});
		cur.push_back({x2, {i, 1}});
	}
	q.clear();
	
	sort(cur.begin(), cur.end());
	for (auto &qr : cur){		
		x = qr.x;
		int i = qr.y.x;
		int l, r;
		
		if (qr.y.y == 0){
			get_neighbours(i, l, r);
			
			if (r != -1 && a[i].l == a[r].l)
				return true;
			if (inter(i, l, t))
				return true;
			if (inter(i, r, t))
				return true;
			
			del[i] = q.insert({a[i].l, i}).x;
		}
		else{			
			q.erase(del[i]);
			get_neighbours(i, l, r);
			
			if (inter(l, r, t))
				return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	a.resize(n);
	forn(i, n){
		scanf("%d%d%d%d%d", &a[i].x, &a[i].y, &a[i].dx, &a[i].dy, &a[i].s);
		a[i].l = line(a[i].x, a[i].y, a[i].x + a[i].dx, a[i].y + a[i].dy);
		double d = sqrt(a[i].dx * a[i].dx + a[i].dy * a[i].dy);
		a[i].vx = a[i].dx / d * a[i].s;
		a[i].vy = a[i].dy / d * a[i].s;
		a[i].s *= a[i].s;
	}
	double l = 0, r = INF;
	bool ok = false;
	forn(_, 100){
		double m = (l + r) / 2;
		if (check(m)){
			ok = true;
			r = m;
		}
		else{
			l = m;
		}
	}
	if (!ok)
		puts("No show :(");
	else
		printf("%.15lfn", l);
	return 0;
}
```
