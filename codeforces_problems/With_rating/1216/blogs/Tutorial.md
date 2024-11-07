# Tutorial

All problems except the problem F are invented by [fcspartakm](https://codeforces.com/profile/fcspartakm "Candidate Master fcspartakm"). The problem F idea belongs to [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest").

[1216A - Prefixes](../problems/A._Prefixes.md "Codeforces Round 587 (Div. 3)")

 **Tutorial**
### [1216A - Prefixes](../problems/A._Prefixes.md "Codeforces Round 587 (Div. 3)")

The problem can be solved like this: firstly let's iterate over all $i$ from $1$ to $\frac{n}{2}$. If characters $s_{2i-1}$ and $s_{2i}$ are the same then we obviously need to replace one of them with the other character. We can see that such replacements are enough to make the string suitable.

 **Solution**
```cpp
n, s = int(input()), list(input())
ans = 0
for i in range(0, n, 2):
	if (s[i] == s[i + 1]):
		s[i] = chr(1 - ord(s[i]) + 2 * ord('a'))
		ans += 1
print(ans)
print(''.join(s))
```
[1216B - Shooting](../problems/B._Shooting.md "Codeforces Round 587 (Div. 3)")

 **Tutorial**
### [1216B - Shooting](../problems/B._Shooting.md "Codeforces Round 587 (Div. 3)")

We can see that because the multiplier $x$ in the formula $(a_i \cdot x + 1)$ is the position of the number and we want to minimize the sum of such formulas, the following greedy solution comes up to mind: because we want to count greater values as earlier as possible, let's sort the array $a$ in non-increasing order (saving initial indices of elements), calculate the answer and print the permutation of indices in order from left to right.

 **Solution**
```cpp
n, a = int(input()), list(map(int, input().split()))
res = []
ans = 0
for i in range(n):
	pos = -1
	for j in range(n):
		if (pos == -1 or a[j] > a[pos]): pos = j
	res.append(pos + 1)
	ans += i * a[pos] + 1
	a[pos] = 0
print(ans)
print(' '.join([str(x) for x in res]))
```
[1216C - White Sheet](../problems/C._White_Sheet.md "Codeforces Round 587 (Div. 3)")

 **Tutorial**
### [1216C - White Sheet](../problems/C._White_Sheet.md "Codeforces Round 587 (Div. 3)")

There are at least two solution to the problem. I'll describe both of them.

The first solution: firstly let's notice that the point we search can have non-integer coordinates, but if the answer exists then there will be the answer such that its point has at most half-integer coordinates. So let's multiply all coordinates by two and solve the problem with integer coordinates. The second thing is that for some $x$ there is only two points we need to check — top point with this $x$ and bottom point with this $x$. The same for some $y$. So we can iterate over all possible values of $x$ and check if the point $(x, y_1)$ lies outside of both black rectangles. The same with point $(x, y_2)$. Then do the same for points $(y, x_1)$ and $(y, x_2)$. $x$ should be in range $[x_1; x_2]$ and $y$ should be in range $[y_1; y_2]$. Time complexity is linear on size of the white rectangle.

The second solution is most tricky but has the better time complexity. Let $wb_1$ be the intersection of white rectangle and the first black rectangle, $wb_2$ the same but with the second black rectangle and $inter$ be the intersection of $wb_1$ and $wb_2$. Then it is obvious that the answer exists if $wb_1$ and $wb_2$ doesn't cover the whole white rectangle ($sq(w) > sq(wb_1) + sq(wb_2) - sq(inter)$). Time complexity: $O(1)$.

 **Solution 1**
```cpp
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>

#define forn(i, n) for(int i=0;i<n;++i)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define x first
#define y1 ________y1
#define y second
#define ft first
#define sc second
#define pt pair<int, int>

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;

using namespace std;

const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;

inline void read() {	
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
    x1 *= 2, y1 *= 2;
    x2 *= 2, y2 *= 2;
    x3 *= 2, y3 *= 2;
    x4 *= 2, y4 *= 2;
    x5 *= 2, y5 *= 2;
    x6 *= 2, y6 *= 2;
}

inline bool ok(int x, int y, int x1, int y1, int x2, int y2) {
	return x < x1 || x2 < x || y < y1 || y2 < y;
}

inline void solve() {
	for (int x = x1; x <= x2; x++) {
		if (ok(x, y1, x3, y3, x4, y4) && ok(x, y1, x5, y5, x6, y6)) {
			cout << "YES" << endl;
			return;
		}
		if (ok(x, y2, x3, y3, x4, y4) && ok(x, y2, x5, y5, x6, y6)) {
			cout << "YES" << endl;
			return;
		}
	}
	for (int y = y1; y <= y2; y++) {
		if (ok(x1, y, x3, y3, x4, y4) && ok(x1, y, x5, y5, x6, y6)) {
			cout << "YES" << endl;
			return;
		}
		if (ok(x2, y, x3, y3, x4, y4) && ok(x2, y, x5, y5, x6, y6)) {
			cout << "YES" << endl;
			return;
		}	
	}
	cout << "NO" << endl;
}

int main () {
#ifdef fcspartakm
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    srand(time(NULL));
    cerr << setprecision(10) << fixed;
    
    read();
    solve();
 
    //cerr << "TIME: " << clock() << endl;
}
```
 **Solution 2**
```cpp
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

typedef long long li;
typedef unsigned long long uli;
typedef pair<int, int> pii;
typedef long double ld;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define vi vector<int>
#define x first
#define y second

const int INF = 2e9;
const li INF64 = 1e18;
const int M = 2 * 1000 * 1000;
const int N = 300 * 1000 + 100;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = 3.14159265359;

pair<pii, pii> intersect(pii a, pii b, pii c, pii d) {
	int lf, rg, up, dn;
	lf = max(min(a.x, b.x), min(c.x, d.x));
	rg = min(max(a.x, b.x), max(c.x, d.x));
	up = min(max(a.y, b.y), max(c.y, d.y));
	dn = max(min(a.y, b.y), min(c.y, d.y));

	if (rg <= lf || up <= dn) return { {0, 0}, {0, 0} };

	return { { lf, dn }, { rg, up } };
}

li square(pii a, pii b) {
	return 1ll * abs(a.x - b.x) * abs(a.y - b.y);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<pii> p(6);

	forn(i, 6)
		cin >> p[i].x >> p[i].y;

	pair<pii, pii> wb1 = intersect(p[0], p[1], p[2], p[3]);
	pair<pii, pii> wb2 = intersect(p[0], p[1], p[4], p[5]);
	pair<pii, pii> inter = intersect(wb1.x, wb1.y, wb2.x, wb2.y);

	li swhite = square(p[0], p[1]);
	li swb1 = square(wb1.x, wb1.y);
	li swb2 = square(wb2.x, wb2.y);
	li sinter = square(inter.x, inter.y);

	if (swhite > swb1 + swb2 - sinter) cout << "YESn";
	else cout << "NOn";
}
```
[1216D - Swords](../problems/D._Swords.md "Codeforces Round 587 (Div. 3)")

 **Tutorial**
### [1216D - Swords](../problems/D._Swords.md "Codeforces Round 587 (Div. 3)")

Firstly, let's notice that for the fixed value of $z$ our problem is reduced to the following: we are given $n$ numbers $a_1, a_2, \dots, a_n$. We need to choose such values $k_1, k_2, \dots, k_n$ that $a_1 + k_1 \cdot z = a_2 + k_2 \cdot z = \dots = a_n + k_n \cdot z$. And among all such values $k_1, k_2, \dots, k_n$ we need to choose values in a way to minimize $\sum\limits_{i=1}^{n}k_i$. And the sum of $k_i$ is $y$! Of course, for the fixed value $z$ the minimum sum of $k_i$ can be only one.

Let's start with $z=1$. It is obvious that if the maximum value in the array $a$ is $mx$ the value $k_i$ equals $mx - a_i$ (for $z=1$). Assume that each $k_i$ from $1$ to $n$ has some divisor $d$. Then if we multiply $z$ by $d$ and divide each $k_i$ by $d$ the answer will only become better. How to calculate this value of $z$ fast? We can see that this value equals to $gcd(k_1, k_2, \dots, k_n)$! And it can be proven that this value of $z$ is always optimal and we can easily determine $y$ for such $z$.

Time complexity: $O(n + \log max(a_i))$.

 **Solution**
```cpp
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>

#define forn(i, n) for(int i=0;i<n;++i)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define x first
#define y1 ________y1
#define y second
#define ft first
#define sc second
#define pt pair<int, int>

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;

using namespace std;

const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 200 * 1000 + 13;

int n;
int a[N];

inline void read() {	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

inline int gcd(int a, int b) {
	while (a != 0 && b != 0) {
		if (a > b) {
			a %= b;
		} else {
			b %= a;
		}
	}
	return max(a, b);
}

inline void solve() {
	int ma = *max_element(a, a + n);
    li sum = 0;
    for (int i = 0; i < n; i++) {
    	sum += a[i];
    }
    int g = ma - a[0];
    for (int i = 1; i < n; i++) {
    	g = gcd(g, ma - a[i]);
    }    
    li ans = (ma * 1ll * n - sum) / g;
    cout << ans << ' ' << g << endl;
}

int main () {
#ifdef fcspartakm
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    srand(time(NULL));
    cerr << setprecision(10) << fixed;
    
    read();
    solve();
 
    //cerr << "TIME: " << clock() << endl;
}
```
[1216E1 - Numerical Sequence (easy version)](../problems/E1._Numerical_Sequence_(easy_version).md "Codeforces Round 587 (Div. 3)")

 **Tutorial**
### [1216E1 - Numerical Sequence (easy version)](../problems/E1._Numerical_Sequence_(easy_version).md "Codeforces Round 587 (Div. 3)")

Let's take a look on the upper bound of the number $n$, where $n$ is the maximum possible number of block which can be asked. If we assume that each number has length $1$ then the sum of lengths will be equal to $1 + 2 + \dots + n$. And as we know this value equals $\frac{n(n+1)}{2}$. So the maximum value of $n$ is not greater than $O(\sqrt{k})$.

Now we can just iterate over all $i$ from $1$ to $n$ (where $n$ is no more than $5 \cdot 10^4$) and carry the length of the last block. If this length is greater than or equal to $k$ ($0$-indexed) then let's decrease $k$ by this length, increase the length of the last block and continue. Otherwise our answer lies in the current block. So then let's iterate over all $j$ from $1$ to $i$ and if the decimal length of $j$ is greater than or equal to $k$ then decrease $k$ by this length otherwise our answer lies in the current number $j$ and we just need to print $j_k$ ($0$-indexed).

Time complexity: $O(\sqrt{k})$ per query.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	
	while (q--) {
		long long k;
		cin >> k;
		--k;
		long long lst = 0;
		long long nxtpw = 1;
		int numlen = 0;
		for (long long i = 1; ; ++i) {
			if (i == nxtpw) {
				++numlen;
				nxtpw *= 10;
			}
			lst += numlen;
			if (k >= lst) {
				k -= lst;
			} else {
				long long nxtpw = 1;
				int numlen = 0;
				for (long long j = 1; j <= i; ++j) {
					if (j == nxtpw) {
						++numlen;
						nxtpw *= 10;
					}
					if (k >= numlen) {
						k -= numlen;
					} else {
						cout << to_string(j)[k] << endl;
						break;
					}
				}
				break;
			}
		}
	}
	
	return 0;
}
```
[1216E2 - Numerical Sequence (hard version)](../problems/E2._Numerical_Sequence_(hard_version).md "Codeforces Round 587 (Div. 3)")

 **Tutorial**
### [1216E2 - Numerical Sequence (hard version)](../problems/E2._Numerical_Sequence_(hard_version).md "Codeforces Round 587 (Div. 3)")

This problem idea is not very hard. Now $n$ can be up to $10^9$ so we need to find the number of block $i$ faster. Let's do binary search on it! Now using some shitty pretty formulas we can determine if the total sum of lengths of blocks from $1$ to $i$ is greater than or equal to $k$ or not.

And more about these formulas: let's iterate over all possible length of numbers from $1$ to $len(i)$ and carry the sum of lengths $add$ of numbers with length less than the current length $l$. We know that the number of numbers (he-he) of length $l$ is exactly $cnt = 10^{l+1}-10^l$ ($cnt = i - 10^l + 1$ for $l=len(i)$). Let's add $add \cdot cnt + \frac{cnt(cnt+1)}{2} \cdot cnt$ to the total sum of lengths and increase $add$ by $cnt \cdot len$.

What does $add \cdot cnt$ means? This formula means that we have exactly $cnt$ blocks ending with numbers of length $l$ and we need to add sum of lengths of all numbers with length less than $l$ exactly $cnt$ times. And what does $\frac{cnt(cnt+1)}{2} \cdot cnt$ means? It is the sum sums of lengths of all numbers of length $l$ (i.e. previously we added sum of lengths of numbers with length less than $l$ and now we add sum of sums of lengths of numbers with length $l$).

When we found the number of block $i$, let's decrease $k$ by the total length of all blocks from $1$ to $i-1$ and continue solving the problem. 

This part was pretty hard to understand. And the easiest part: when we determined the number of block $i$ we can easily determine the number $j$ from $1$ to $i$ such that our answer lies in the number $j$. Let's iterate over all lengths from $1$ to $len(i)$ (here we go again) and for the current length $l$ let $cnt = 10^{l+1}-10^l$ ($cnt = j - 10^l + 1$ for $l=len(j)$). And now all we need is to increase the sum of lengths by $cnt \cdot len$.

After determining $j$ decrease $k$ by sum of lengths of numbers from $1$ to $j-1$ and print $j_k$.

Time complexity: $O(\log^2{n})$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

long long get(long long r) {
	return (r + 1) * r / 2;
}

long long sumto(long long r, int need) {
	long long pw = 1;
	long long sum = 0;
	long long add = 0;
	for (int len = 1; ; ++len) {
		if (pw * 10 - 1 < r) {
			long long cnt = pw * 10 - pw;
			if (need) {
				sum += add * cnt + get(cnt) * len;
				add += cnt * len;
			} else {
				sum += cnt * len;
			}
		} else {
			long long cnt = r - pw + 1;
			if (need) {
				sum += add * cnt + get(cnt) * len;
			} else {
				sum += cnt * len;
			}
			break;
		}
		pw *= 10;
	}
	return sum;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int q;
	cin >> q;
	while (q--) {
		long long k;
		cin >> k;
		--k;
		
		long long l = 1	, r = 1e9;
		long long res = -1;
		while (r - l >= 0) {
			long long mid = (l + r) >> 1;
			if (sumto(mid, 1) > k) {
				res = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		k -= sumto(res - 1, 1);
		
		l = 1, r = res;
		long long num = -1;
		while (r - l >= 0) {
			int mid = (l + r) >> 1;
			if (sumto(mid, 0) > k) {
				num = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		
		cout << to_string(num)[k - sumto(num - 1, 0)] << endl;
	}
	
	return 0;
}
```
[1216F - Wi-Fi](../problems/F._Wi-Fi.md "Codeforces Round 587 (Div. 3)")

 **Tutorial**
### [1216F - Wi-Fi](../problems/F._Wi-Fi.md "Codeforces Round 587 (Div. 3)")

Firstly, I know that this problem has very pretty linear solution and its author can describe it if he wants. I'll describe my own solution without any data structures but std::set.

Let $dp_i$ be the total cost to connect all rooms from $i$ to $n-1$ to the Internet ($0$-indexed). Initially $dp_{n} = 0$, all other values are $+\infty$. Let's iterate over all $i$ from $n-1$ to $0$ and make some transitions. After all the answer will be $dp_0$.

The first transition is the easier: update $dp_i$ with $dp_{i + 1} + i + 1$ (just connect the current room directly). To do other transitions, let's carry two sets $mins$ and $vals$ and one array of vectors $del$ of length $n$. Set $mins$ carries all values $dp_{i + 1}, dp_{i + 2}, \dots, dp_{i + k + 1}$. Initially it carries $dp_n = 0$. Set $vals$ carries the minimum cost to cover some suffix of rooms that also covers the room $i$. Array of vectors $rem$ helps us to carry the set $vals$ efficiently. First of all, if $i + k + 2 \le n$ then let's remove $dp_{i + k + 2}$ from $mins$. Then let's remove all values of $del_i$ from $vals$. Then if $vals$ is not empty, let's update $dp_i$ with the minimum value of $vals$. Then if $s_i = $ '1' then let $val$ be the minimum value of $mins$ plus $i + 1$. Update $dp_i$ with $val$ and insert $val$ into $vals$. Also let's add $val$ into $del_{i - k - 1}$ if $i - k - 1 \ge 0$. And after we make all we need with the current $i$, add the value $dp_i$ to the set $mins$.

Time complexity: $O(n \log n)$.

It can be optimized to $O(n)$ solution with some advanced data structures as a queue with minimums.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	vector<long long> dp(n + 1);
	multiset<long long> mins, vals;
	mins.insert(0);
	vector<vector<long long>> del(n);
	for (int i = n - 1; i >= 0; --i) {
		dp[i] = i + 1 +  dp[i + 1];
		if (i + k + 2 <= n) mins.erase(mins.find(dp[i + k + 2]));
		for (auto it : del[i]) vals.erase(vals.find(it));
		if (!vals.empty()) dp[i] = min(dp[i], *vals.begin());
		if (s[i] == '1') {
			long long val = (mins.empty() ? 0 : *mins.begin()) + i + 1;
			dp[i] = min(dp[i], val);
			vals.insert(val);
			if (i - k - 1 >= 0) del[i - k - 1].push_back(val);
		}
		mins.insert(dp[i]);
	}
	
	cout << dp[0] << endl;
	
	return 0;
}
```
