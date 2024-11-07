# Tutorial

Thank you for participating! I hope you enjoyed the tasks.

One of the testers ([redpanda](https://codeforces.com/profile/redpanda "Expert redpanda")) did a wonderful [video analysis](https://codeforces.com/https://youtu.be/-btzjr-u4dM) tasks A-C, I highly recommend watching it.

[1982A - Soccer](../problems/A._Soccer.md "Codeforces Round 955 (Div. 2, with prizes from NEAR!)")

 **Tutorial**
### [1982A - Soccer](../problems/A._Soccer.md "Codeforces Round 955 (Div. 2, with prizes from NEAR!)")

In all cases where the first team initially led the score, and then the second team, there will be a moment when the score is equal, so it is enough to check only this condition. If it is met, the answer is "NO", otherwise the answer is "YES".

Let's demonstrate how events could have unfolded without an equal score, if the condition is not met. Let x1>y1 and x2>y2, then the events could have occurred as follows:

 x1 : y1(x1+1) : y1

(x1+2) : y1

...

x2 : y1

x2 : (y1+1)

x2 : (y1+2)

...

x2 : y2

 **Solution (74TrAkToR)**
```cpp
t = int(input())
for T in range(t):
	la, lb = map(int, input().split())
	ra, rb = map(int, input().split())
	if la > lb:
		la, lb, ra, rb = lb, la, rb, ra
	if la < lb and rb < ra:
		print("NO")
	else:
		print("YES")
```
[1982B - Collatz Conjecture](../problems/B._Collatz_Conjecture.md "Codeforces Round 955 (Div. 2, with prizes from NEAR!)")

 **Tutorial**
### [1982B - Collatz Conjecture](../problems/B._Collatz_Conjecture.md "Codeforces Round 955 (Div. 2, with prizes from NEAR!)")

Let's write down what happens in the problem and try to speed it up. The first observation: we will perform operations until x≠1, after which the answer can be found using the formula ans=1+k%(y−1). Indeed, after x becomes equal to 1, if we continue applying operations to it, it will change as follows:

1→2→...→(y−1)→1→2→...→(y−1)→1→...

The second optimization is to group the operations that only add one, so instead of 1 we will add the next value to x in one action min(k,⌈xy⌉⋅y−x). After this (if we added at least 1), we should try to divide the number by y (if it is divisible).

If we use these two optimizations, our solution will work in O(logx) for one set of input data, since in one action x decreases to ⌈x+1y⌉, and therefore x becomes 1 in no more than O(logx) actions.

 **Solution (FelixArg)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
	long long x, y, k;
	cin >> x >> y >> k;
	while (k > 0 && x != 1) {
		long long ost = (x / y + 1) * y - x;
                ost = max(1ll, ost);
                ost = min(ost, k);
                x += ost;
		while (x % y == 0) {
			x /= y;
		}
		k -= ost;
	}
	cout << x + k % (y - 1) << 'n';
}
 
int main()
{
#ifdef FELIX
	auto _clock_start = chrono::high_resolution_clock::now();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int tests = 1;
	cin >> tests;
	for (int test = 0; test < tests; test++){
		solve();
	}
 
#ifdef FELIX
	cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
		chrono::high_resolution_clock::now()
			- _clock_start).count() << "ms." << endl;
#endif
	return 0;
}
```
[1982C - Boring Day](../problems/C._Boring_Day.md "Codeforces Round 955 (Div. 2, with prizes from NEAR!)")

 **Hint 1**All the numbers ai are positive, can it help somehow?

 **Hint 2**Try using dynamic programming.

 **Tutorial**
### [1982C - Boring Day](../problems/C._Boring_Day.md "Codeforces Round 955 (Div. 2, with prizes from NEAR!)")

Solution 1:

Let dp[i] — the maximum number of rounds won by Egor for the first i elements (top cards). It is possible to come up with a solution in O(n2) right now. For each state of the dynamic programming i, you can either skip the next card (not take it in any winning segment), or iterate over the length of the segment that will start with the next card. If you calculate prefix sums and compute the sum over a segment in O(1), the solution works exactly in O(n2).

Let's try to optimize the transitions in such a dynamic.

First, it can be noticed that all ai are positive, which means that the sum of the segment (a,b) will be less than (a,b+1). This means that the first suitable segment (with a sum ≥l) can be found using binary search or two pointers.

Secondly, if the segment has a suitable sum (from l to r), it does not make sense to increase its length, as this can only worsen the answer.

Thus, for each state of the dynamic programming, there are only O(1) transitions, so the entire problem can be solved in O(n) or O(nlogn).

Solution 2:

Let's try to solve the problem greedily. Let's look for a segment (a,b) in the prefix such that the sum of all its elements is not less than l and not greater than r, and among all such segments, we will take the segment with the minimum b. After that, we will consider that the array starts from the (b+1)-th element and continue to search for the next segment in the same way.

How to find (a,b)? Let's start by finding the minimum prefix k (which is also the segment (1,k)) such that the sum of the elements in it is ≥l. If this sum is also not greater than r, then this prefix is the segment we need (a,b). Otherwise, we know that the sum of the elements in any subsegment of this prefix that does not contain the last element ak is less than l, so we can try to find a subsegment that ends at k, for this, we can iterate over the left boundary from 1 to k. At the same time, the sum of the elements in the iterated segment will decrease and it may happen again that at some point it becomes <l, in this case, we already know that we will not find the required segment with the right boundary k, so it needs to be increased (again until the sum becomes ≥l). By repeating these actions, we will either find the required segment (a,b), or the right boundary will become equal to n. The algorithm is nothing but "two pointers", we keep two boundaries l and r and move them only to the right, so in total, this all works in O(n).

 **Solution 1 (FelixArg)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 1000000007;
 
void solve(){
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
 
	vector<long long> pref(n + 1);
	for (int i = 0; i < n; i++){
		pref[i + 1] = pref[i] + a[i];
	}
 
	vector<int> dp(n + 1);
	int s = 0;
	int j = -1;
	for (int i = 0; i < n; i++){
		dp[i + 1] = max(dp[i + 1], dp[i]);
		if (j < i){
			j = i;
			s = 0;
		}
		while(j < n && s < l){
			s += a[j++];
		}
		if (s >= l && s <= r){
			dp[j] = max(dp[j], dp[i] + 1);
		}
		s -= a[i];
	}
 
	cout << dp[n] << 'n';
}
 
int main()
{
#ifdef FELIX
	auto _clock_start = chrono::high_resolution_clock::now();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tests = 1;
	cin >> tests;
	for (int test = 0; test < tests; test++){
		solve();
	}
#ifdef FELIX
	cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
		chrono::high_resolution_clock::now()
			- _clock_start).count() << "ms." << endl;
#endif
	return 0;
}
```
 **Solution 2 (74TrAkToR)**
```cpp
t = int(input())
for T in range(t):
	n, l, r = map(int, input().split())
	a = [int(x) for x in input().split()]
	ans = 0
	cur = 0
	L, R = 0, 0
	while L < n:
		while R < n and cur < l:
			cur += a[R]
			R += 1
		if l <= cur and cur <= r:
			ans += 1
			L = R
			cur = 0
		else:
			cur -= a[L]
			L += 1
	print(ans)
```
[1982D - Beauty of the mountains](../problems/D._Beauty_of_the_mountains.md "Codeforces Round 955 (Div. 2, with prizes from NEAR!)")

 **Hint 1**How does the difference between heights change if we choose a specific submatrix?

 **Hint 2**It is worth reducing the problem to a mathematical construction. Maybe something from number theory can help?

 **Tutorial**
### [1982D - Beauty of the mountains](../problems/D._Beauty_of_the_mountains.md "Codeforces Round 955 (Div. 2, with prizes from NEAR!)")

First, let's calculate the current difference between the heights of different types of mountains, denoted as D.

Then, for each submatrix of size k×k, we will calculate how the difference in the sums of heights of different types of mountains changes. That is, for each submatrix, we will calculate the difference in the number of zeros and ones in it, let these values be di and there will be q=(n−k+1)⋅(m−k+1). This can be done using two-dimensional prefix sums or a "sliding window".

After that, formally we can write the following equation:

c1⋅d1+c2⋅d2+⋯+cq⋅dq=D

, where c1, c2, ..., cq — are constants c that Nikita chose for a specific submatrix (0 if we did not transform using this submatrix). This is very similar to a Diophantine equation, in fact, it is, but with q unknowns.

What can be said about the existence of a solution to this equation in integers? For this, it is sufficient that 

Dmodgcd(d1,d2,…,dq)=0

It is worth mentioning that it is necessary to carefully handle the case when all di=0, and also not to forget about the case when D is initially equal to 0.

In total, the solution is in O(n⋅m+logA)

 **Solution (FelixArg)**
```cpp
import math
 
def solve():
    n, m, k = map(int, input().split())
    a = [[int(x) for x in input().split()] for j in range(n)]
    s = [input() for i in range(n)]
    pref = [[0 for i in range(m + 1)] for j in range(n + 1)]
    diff = 0
    for i in range(n):
        cur = 0
        for j in range(m):
            if s[i][j] == '1':
                cur += 1
                diff += a[i][j]
            else:
                diff -= a[i][j]
            pref[i + 1][j + 1] = pref[i][j + 1] + cur
    if diff == 0:
        print("YES")
        return
    g = 0
    for i in range(n - k + 1):
        for j in range(m - k + 1):
            f = pref[i + k][j + k] - pref[i + k][j] - pref[i][j + k] + pref[i][j]
            f = abs(k * k - 2 * f)
            g = math.gcd(g, f)
    if g == 0 or diff % g != 0:
        print("NO")
    else:
        print("YES")
 
 
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
```
[1982E - Number of k-good subarrays](../problems/E._Number_of_k-good_subarrays.md "Codeforces Round 955 (Div. 2, with prizes from NEAR!)")

 **Hint**Try using the divide-and-conquer approach.

 **Tutorial**
### [1982E - Number of k-good subarrays](../problems/E._Number_of_k-good_subarrays.md "Codeforces Round 955 (Div. 2, with prizes from NEAR!)")

Let f(n,k) be a function to solve the problem, which will return three values (l,r,ans) such that:

* l — for the first l numbers (i.e. from 0 to l−1) bit(x)≤k holds, while bit(l)>k or l≥n;
* r — for the last r numbers (i.e. from n−r to n−1) bit(x)≤k holds, while bit(n−r−1)>k or n−r−1<0;
* ans — the answer for the pair (n,k).

Let's use the "divide and conquer" approach. Divide the segment from 0 to n into two segments:

1. from 0 to 2m−1, where m is the maximum such that 2m<n;
2. from 2m to n−1.

It can be noticed that instead of calculating the function on the segment from 2k to n−1, it is possible to calculate it from 0 to n−1−2m, but with a smaller k.

More formally, f(n,k) can be recalculated through f(2m,k) and f(n−2m,k−1).

Based on the pair of triples (l1,r1,ans1), which is obtained after calculating f(2m,k) and (l2,r2,ans2), which is obtained after calculating f(n−2m,k−1), it is quite trivial to recalculate the triple for f(n,k) using the formula in O(1).

However, the solution still works in O(n) time, as we will have a complete binary tree of recursive calls.

To fix this, it is only necessary to precalculate all f(2m,k) for each possible k and m. For f(2m,k), it can be noticed that it is recalculated through f(2m−1,k) and f(2m−1,k−1), so all values can be calculated using dynamic programming.

After this, in the recursive function, we always calculate f(2m,k) in O(1), and for the next call, the first argument is halved, so now everything works in O(logn) for one test case.

In total, the solution is in O(logn) for the test case.

 **Solution (FelixArg)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1000000007;
 
map<pair<long long, int>, tuple<int, long long, long long>> mem;
 
tuple<int, long long, long long> calc(long long n, int k){
	if (k < 0){
		return tuple{0, 0ll, 0ll};
	}
	if (n == 1){
		return tuple{1, 1ll, 1ll};
	}
	int bit = 63 - __builtin_clzll(n);
	long long mid = (1ll << bit);
	if (mid == n){
		mid >>= 1;
		if (mem.count({n, k})){
			return mem[{n, k}];
		}
	}
	auto [f1, s1, e1] = calc(mid, k);
	auto [f2, s2, e2] = calc(n - mid, k - 1);
 
	int sub1 = (e1 % MOD) * ((e1 + 1) % MOD) % MOD * 500000004 % MOD;
	f1 = (f1 * 1ll - sub1 + MOD) % MOD;
	int sub2 = (s2 % MOD) * ((s2 + 1) % MOD) % MOD * 500000004 % MOD;
	f2 = (f2 * 1ll - sub2 + MOD) % MOD;
 
	long long p = (e1 + s2) % MOD;
	int f_cur = (f1 * 1ll + f2 + (p * 1ll * ((p + 1) % MOD) % MOD * 500000004 % MOD)) % MOD;
	long long s_cur = s1;
	long long e_cur = e2;
	if (s1 == e1 && s1 != 0){
		s_cur = (s1 + s2);
	}
	if (s2 == e2 && s2 != 0){
		e_cur = (e1 + e2);
	}
	if ((mid << 1) == n){
		mem[{n, k}] = tuple{f_cur, s_cur, e_cur};
	}
	return tuple{f_cur, s_cur, e_cur};
};
 
void solve(){
	long long n;
	int k;
	cin >> n >> k;
	cout << get<0>(calc(n, k)) << 'n';
}
 
int main()
{
#ifdef FELIX
	auto _clock_start = chrono::high_resolution_clock::now();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int tests = 1;
	cin >> tests;
	for (int test = 0; test < tests; test++){
		solve();
	}
 
#ifdef FELIX
	cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
		chrono::high_resolution_clock::now()
			- _clock_start).count() << "ms." << endl;
#endif
	return 0;
}
```
[1982F - Sorting Problem Again](../problems/F._Sorting_Problem_Again.md "Codeforces Round 955 (Div. 2, with prizes from NEAR!)")

 **Hint**If you maintain a set of such indexes i that ai<ai−1, then can this help in any way?

 **Tutorial**
### [1982F - Sorting Problem Again](../problems/F._Sorting_Problem_Again.md "Codeforces Round 955 (Div. 2, with prizes from NEAR!)")

Let's maintain a set s of positions i such that ai<ai−1, and also a segment tree (or any other data structure that allows changing the value at a position and finding the minimum/maximum on a segment). Recalculating the set and the segment tree is quite simple for each change in the array a.

To answer a query, let's notice a few facts:

* If s is empty, then the array a is completely sorted.
* If s is not empty, then we can find the minimum and maximum elements from this set, denote them as posmin, posmax. With these elements, we can easily answer queries. Similarly to the previous point, we can say that the prefix of size posmin and the suffix of size n−1−posmax are sorted in non-decreasing order.

Now, at the very least, we need to sort the segment (l,r) such that l≤posmin, r>posmax. How can we find exactly these l and r? First, let's find l. To do this, we find the minimum on the segment (posmin−1,posmax), this value will be somewhere in the prefix of the entire array, so we need to find the position in the prefix between which elements it should be inserted. But we also know that the prefix is sorted, so we can use binary search (as in insertion sort) and find the position for this value. This position will be our l.

For r, everything is similar, we find the maximum on the segment (posmin−1,posmax) and also find its position in the sorted suffix.

In conclusion, to find the answer after changing the array, we need to find the maximum/minimum positions in s, the maximum/minimum on the segment, and perform 2 binary searches on the prefix and suffix. All of this works in O(logn).

Complexity: O((n+q)⋅logn)

It is also worth noting that some solutions with O((n+q)⋅log2n) can also fit within the time limit if they are very carefully written and use a non-recursive segment tree.

 **Solution (FelixArg)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 1000000007;
 
struct SegTree{
	vector<int> mn, mx;
	int n;
	SegTree(int _n): n(_n){
		mx.assign(2 * n, -inf);
		mn.resize(2 * n, inf);
	}
 
	void upd(int pos, int val){
		mx[pos + n] = val;
		mn[pos + n] = val;
		pos = (pos + n) >> 1;
		for (;pos > 0; pos >>= 1){
			mx[pos] = max(mx[pos << 1], mx[(pos << 1) | 1]);
			mn[pos] = min(mn[pos << 1], mn[(pos << 1) | 1]);
		}
	}
 
	pair<int,int> get(int l, int r){
		pair<int,int> res = {-inf, inf};
		l += n;
		r += n + 1;
		for (;l < r; l >>= 1, r >>= 1){
			if (l & 1) {
				res.first = max(res.first, mx[l]);
				res.second = min(res.second, mn[l++]);
			}
			if (r & 1) {
				res.first = max(res.first, mx[--r]);
				res.second = min(res.second, mn[r]);
			}			
		}
		return res;
	}
};
 
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
 
	SegTree tree(n);
	set<int> st;
	for (int i = 0; i < n; i++){
		tree.upd(i, a[i]);
		if (i > 0 && a[i] < a[i - 1]){
			st.insert(i);
		}
	}
 
	function<int(int, int)> find_pref = [&](int pos, int x){
		if (pos < 0){
			return 0;
		}
		int l = 0, r = pos;
		while(l <= r){
			int m = l + (r - l) / 2;
			if (a[m] > x){
				r = m - 1;
			}
			else{
				l = m + 1;
			}
		}
		return r + 1;
	};
 
	function<int(int, int)> find_suff = [&](int pos, int x){
		if (pos >= n){
			return n - 1;
		}
		int l = pos, r = n - 1;
		while(l <= r){
			int m = l + (r - l) / 2;
			if (a[m] >= x){
				r = m - 1;
			}
			else{
				l = m + 1;
			}
		}
		return r;
	};
 
	function<void()> query = [&](){
		if (st.empty()){
			cout << -1 << ' ' << -1 << 'n';
			return;
		}
		int l = *st.begin() - 1;
		int r = *(--st.end());
 
		auto [mx, mn] = tree.get(l, r);
 
		cout << find_pref(l - 1, mn) + 1 << ' ' << find_suff(r + 1, mx) + 1 << 'n';
	};
 
	query();
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		int pos, val;
		cin >> pos >> val;
		pos--;
		if (pos > 0 && a[pos] < a[pos - 1]){
			st.erase(pos);
		}
		if (pos + 1 < n && a[pos + 1] < a[pos]){
			st.erase(pos + 1);
		}
		a[pos] = val;
		tree.upd(pos, val);
		if (pos > 0 && a[pos] < a[pos - 1]){
			st.insert(pos);
		}
		if (pos + 1 < n && a[pos + 1] < a[pos]){
			st.insert(pos + 1);
		}
		query();
	}
}
 
int main()
{
#ifdef FELIX
	auto _clock_start = chrono::high_resolution_clock::now();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tests = 1;
	cin >> tests;
	for (int test = 0; test < tests; test++){
		solve();
	}
#ifdef FELIX
	cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
		chrono::high_resolution_clock::now()
			- _clock_start).count() << "ms." << endl;
#endif
	return 0;
}
```
