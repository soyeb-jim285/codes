# Tutorial_1_(en)

[1041A - Heist](../problems/A._Heist.md "Codeforces Round 509 (Div. 2)")

 **Tutorial**
### [1041A - Heist](../problems/A._Heist.md "Codeforces Round 509 (Div. 2)")

Let $x$ — the minimal number from the given numbers and $y$ — the maximal. So we consider that $x$ and $y$ were minimal and maximal keyboard numbers before the heist. All given numbers are distinct, so the answer is $y - x + 1 - n$ (initial number of the keyboards is $(y - x + 1)$ minus the remaining number of keyboards $n$).

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int mn = 1e9, mx = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    cout << max(0, (mx-mn)-n+1);    
}
```
[1041B - Buying a TV Set](../problems/B._Buying_a_TV_Set.md "Codeforces Round 509 (Div. 2)")

 **Tutorial**
### [1041B - Buying a TV Set](../problems/B._Buying_a_TV_Set.md "Codeforces Round 509 (Div. 2)")

Firstly let's make $x$ and $y$ coprime. To do so, we calculate $g = gcd(x, y)$ and then divide both numbers by $g$.

Then the pair $(w, h)$ is included in the answer if the following conditions are met: $w \le a$, $h \le b$, and there exists some positive integer $k$ such that $w = kx$ and $h = ky$. Furthermore, each such pair is uniquely determined by this integer $k$. So we can reduce our task to counting the number of positive integers $k$ such that $kx \le a$ and $ky \le b$, and that is just $min(\lfloor \frac{a}{x} \rfloor, \lfloor \frac{b}{y} \rfloor)$.

 **Solution** 
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll gc = __gcd(c, d);
    c /= gc;
    d /= gc;
    cout << min(a/c, b/d);
}
```
[1041C - Coffee Break](../problems/C._Coffee_Break.md "Codeforces Round 509 (Div. 2)")

 **Tutorial**
### [1041C - Coffee Break](../problems/C._Coffee_Break.md "Codeforces Round 509 (Div. 2)")

Let put in set the pairs in the following format: $a_i$ — the time for $i$-th break and the number of this break in the input data. So, we got pairs sorted by $a_i$.

While set contains elements we will determine the breaks, which should be done in a single day. For the next day the first break should be dine in the time, which is at the beginning of the set (let this time is $x$). So, next break should be done after at least $d$ minutes. We should find a pair in the set, where the first element not less than $x + d + 1$. It can be done with $lower\\_bound$. In the same way, we can find the next breaks in this day. With help of the second elements of pairs, we can easily remember the answer days for breaks. Also, we should erase from set all considered pairs. If for some pair we cannot find the needed element, we should go to the next day.

 **Solution** 
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;

set<pair<int, int> > q;

int ans[N], n, a[N], m, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        q.insert({a[i], i});
    }
    int cnt = 0;
    while(!q.empty()){
        ++cnt;
        int pos = q.begin()->second;
        ans[pos] = cnt;
        q.erase(q.begin());
        while(true){
            auto it = q.lower_bound({a[pos]+1+k, 0});
            if (it == q.end())
                break;
            pos = it->second;
            q.erase(it);
            ans[pos] = cnt;
        }
    }
    cout << cnt << "n";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}
```
[1041D - Glider](../problems/D._Glider.md "Codeforces Round 509 (Div. 2)")

 **Tutorial**
### [1041D - Glider](../problems/D._Glider.md "Codeforces Round 509 (Div. 2)")

At first, let's prove that it is always optimal to jump out at the beginning of any ascending air flows: if his point of jump is out of any air flow, he can move his point to $+1$ — answer will not decrease, in the same way, if his point of jump in some air flow but not in its beginning, he can move his point to $-1$.

Next observation: height of glider is non-ascending function for the fixed point of jump, so we can for each optimal point of jump use binary search of the answer. Let glider jump out at position $x$ and we need to calculate its height at some position $y \ge x$, then height is equal to $h - (y - x) + sum(x,y)$, where $sum(x,y)$ is a total length of all flows of segment $[x, y]$ and can be calculated using prefix sums (yes, and $lower\\_bound$).

Result complexity — $O(n \log(10^9) \log(n))$ of time and $O(n)$ of memory.

Of course, you can note that this task can be solved with two pointers technique, what is faster, but it is not necessary since built in $lower\\_bound$ function is fast enough (unlike some $set$ or segment tree, which should be written optimally).

On the other hand, java-users need to do some extra work by writing its own $lower\\_bound$ function for $int[]$ since $binary\\_search(List<>)$ will cause a slowdown.

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

const int N = 200 * 1000 + 555;

int n, h;
pt a[N];

inline bool read() {
	if(!(cin >> n >> h))
		return false;
	fore(i, 0, n)
		assert(scanf("%d%d", &a[i].x, &a[i].y) == 2);
	sort(a, a + n);
	return true;
}

int ps[N];

int getH(int lf, int rg) {
	int l = int(lower_bound(a, a + n, pt(lf, -1)) - a);
	int r = int(lower_bound(a, a + n, pt(rg, -1)) - a);
	
	int sum = ps[r] - ps[l];
	if(l > 0)
		sum += max(0, a[l - 1].y - lf);
	
	assert(rg - lf - sum >= 0);
	return rg - lf - sum;
}

inline void solve() {
	ps[0] = 0;
	fore(i, 0, n)
		ps[i + 1] = ps[i] + (a[i].y - a[i].x);	
	
	int ans = 0;
	fore(i, 0, n) {
		int lx = a[i].y + 1;
		
		int lf = -(h + 1), rg = lx;
		while(rg - lf > 1) {
			int mid = (lf + rg) / 2;
			if(getH(mid, lx) > h)
				lf = mid;
			else
				rg = mid;
		}
		assert(getH(rg, lx) == h);
		ans = max(ans, lx - rg);
	}
	cout << ans << endl;
}

int main() {
	if(read()) {
		solve();
	}
	return 0;
}
```
[1041E - Tree Reconstruction](../problems/E._Tree_Reconstruction.md "Codeforces Round 509 (Div. 2)")

 **Tutorial**
### [1041E - Tree Reconstruction](../problems/E._Tree_Reconstruction.md "Codeforces Round 509 (Div. 2)")

First of all, if there exists some $b_i < n$, then the answer is clearly NO. Then let's consider that every $b_i = n$ and analyze only the values of $a_i$ (and furthermore, let's sort all values of $a_i$ beforehand).

Suppose that we have constructed a tree satisfying all the requirements and rooted it at vertex $n$. Then for any $k$ such that $1 \le k \le n - 1$ there exist no more than $k$ subtrees containing only vertices with indices not exceeding $k$ (because there are no more than $k$ vertices that can be the roots of such subtrees). So, if for some constant $k$ the number of $a_i \le k$ is greater than $k$, then the answer is NO since it would imply that there are more than $k$ subtrees containing only values not greater then $k$.

Now we consider only the case such that for every $k \in [1, n - 1]$ the number of $i$ such that $a_i \le k$ is not greater than $k$. In this case the answer is YES; let's prove it with an algorithm that constructs a tree meeting the constraints.

Actually, we can always build a bamboo (a tree where no vertex has degree greater than $2$, or simply a path) according to these constraints. Let's put vertex $n$ at one of the ends of the bamboo and start building a bamboo from the other end. It's obvious that if we make some vertex $x$ a leaf, then the array $a$ will contain only values not less than $x$. So, if we consider values of $a_i$ to be sorted, then the leaf has index $a_1$.

Then let's repeat the following process for every $i \in [2, n - 1]$:

* if $a_i > a_{i - 1}$, then let's use the vertex with index $a_i$ as the parent of the previous vertex;
* otherwise, let's find any index $j$ such that $j < a_i$ and index $j$ is not used yet, and use vertex with index $j$ as the parent of the previous vertex (there will be at least one such vertex since for every $k \in [1, n - 1]$ the number of $i$ such that $a_i \le k$ is not greater than $k$).

It's easy to prove that the bamboo we construct in such a way meets the constraints given in the statement.

 **Solution** 
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 200043;

int cnt[N];

int main()
{                
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if(y != n)
		{
			puts("NO");
			return 0;
		}
		cnt[x]++;
	}
	int cur = 0;
	for(int i = 1; i < n; i++)
	{
		cur += cnt[i];
		if(cur > i)
		{
			puts("NO");
			return 0;
		}
	}
	int last = -1;
	puts("YES");
	set<int> unused;
	for(int i = 1; i < n; i++)
		unused.insert(i);
	for(int i = 1; i < n; i++)
	{
		if(cnt[i] > 0)
		{
			unused.erase(i);
			if(last != -1)
				printf("%d %dn", last, i);
			last = i;
			cnt[i]--;
		}
		while(cnt[i] > 0)
		{
			printf("%d %dn", last, *unused.begin());
			last = *unused.begin();
			cnt[i]--;
			unused.erase(unused.begin());
		}
	}
	printf("%d %dn", last, n);
}
```
[1041F - Ray in the tube](../problems/F._Ray_in_the_tube.md "Codeforces Round 509 (Div. 2)")

 **Tutorial**
### [1041F - Ray in the tube](../problems/F._Ray_in_the_tube.md "Codeforces Round 509 (Div. 2)")

At first, $y$ coordinates don't matter. Let $dx$ be signed difference between $x$ coordinates of $B$ and $A$, then on the first line all points with coordinates $x_A + dx \cdot (2k)$ will be chosen, and on the second line all points with coordinates $x_A + dx \cdot (2k + 1)$ will be chosen.

Let's prove that it is always optimal to take $dx = 2^l$ where $l \ge 0$. Let $dx$ is not a power of two, then $dx = m \cdot 2^l$, where $m$ is odd. Note that $dx / m$ hits all points which is hitted by $dx$ that why answer will not decrease. 

So, we need to check only $dx = 2^l$, number of such $dx$ is equal to $O(\log(10^9))$.

For the fixed $dx$ note that ray hits both points on the same line iff $x_1 \equiv x_2 \mod{(2 \cdot dx)}$. Analogically, the ray hits both points on the different lines iff $x_1 + dx \equiv x_2 \mod{(2 \cdot dx)}$.

That's why we can split all point on the equivalent classes modulo $2 \cdot dx$ and take the size of the biggest class. We can do it by sort and two pointers or by $map$.

Result complexity is $O(n \log{(10^9)} \log n)$ time and $O(n)$ memory.

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

const int N = 100 * 1000 + 555;

int n[2], y[2];
int x[2][N];

inline bool read() {
	fore(k, 0, 2) {
		if(!(cin >> n[k] >> y[k]))
			return false;
		fore(i, 0, n[k])
			assert(scanf("%d", &x[k][i]) == 1);
	}
	return true;
}

inline void solve() {
	int ans = 2;
	for(int dx = 1; dx < int(1e9); dx *= 2) {
		int mod = 2 * dx;
		map<int, int> cnt;
		
		int add[2] = {0, dx};
		fore(k, 0, 2) {
			fore(i, 0, n[k])
				cnt[(x[k][i] + add[k]) & (mod - 1)]++;
		}
		
		for(auto curAns : cnt)
			ans = max(ans, curAns.second);
	}
	cout << ans << endl;
}

int main() {
	if(read()) {
		solve();
	}
	return 0;
}
```
