# Tutorial

[1454A - Special Permutation](../problems/A._Special_Permutation.md "Codeforces Round 686 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1454A - Special Permutation](../problems/A._Special_Permutation.md "Codeforces Round 686 (Div. 3)")

There are many possible solutions. One of them is just to print $2, 3, \ldots, n, 1$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cout << (i + 1) % n + 1 << " ";
		}
		cout << endl;
	}
	
	return 0;
}
```
[1454B - Unique Bid Auction](../problems/B._Unique_Bid_Auction.md "Codeforces Round 686 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1454B - Unique Bid Auction](../problems/B._Unique_Bid_Auction.md "Codeforces Round 686 (Div. 3)")

This is a simple implementation problem. Let's calculate two values for each $i$ from $1$ to $n$: $cnt_i$ — the number of occurrences of $i$ in $a$ and $idx_i$ — any position of $i$ in $a$.

Then, let's iterate through $i$ from $1$ to $n$ and, if $cnt_i = 1$, just print $idx_i$ (because if it is the only such element then we found the winner). If we didn't find any such element, we have to print -1.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> cnt(n + 1), idx(n + 1);
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			++cnt[x];
			idx[x] = i + 1;
		}
		int ans = -1;
		for (int i = 0; i <= n; ++i) {
			if (cnt[i] == 1) {
				ans = idx[i];
				break;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1454C - Sequence Transformation](../problems/C._Sequence_Transformation.md "Codeforces Round 686 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1454C - Sequence Transformation](../problems/C._Sequence_Transformation.md "Codeforces Round 686 (Div. 3)")

Firstly, let's remove all consecutive equal elements (just keep one occurrence of each such element). For example, the array $[1, 1, 2, 3, 3, 3, 2]$ becomes $[1, 2, 3, 2]$.

Now, the answer for each $a_i$ is almost the number of its occurrences plus one. Why is it so? Because we need to remove all segments of elements between every pair of consecutive occurrences of $a_i$. The number of such segments is the number of occurrences of $a_i$ minus one. There is also a segment before the first occurrence of $a_i$ and a segment after the last occurrence of $a_i$. But the first segment doesn't exist for the first element and the last segment doesn't exist for the last element.

So, after removing consecutive elements, let's calculate for each $a_i$ the number of its occurrences plus one, subtract one from the value of the first element and from the value of the last element. Then the answer is the minimum among these values for all $a_i$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		vector<int> res(n + 1, 1);
		n = unique(a.begin(), a.end()) - a.begin();
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			res[a[i]] += 1;
		}
		res[a[0]] -= 1;
		res[a[n - 1]] -= 1;
		int ans = 1e9;
		for (int i = 0; i < n; ++i) {
			ans = min(ans, res[a[i]]);
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1454D - Number into Sequence](../problems/D._Number_into_Sequence.md "Codeforces Round 686 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1454D - Number into Sequence](../problems/D._Number_into_Sequence.md "Codeforces Round 686 (Div. 3)")

Consider $n$ in this canonical form ${p_1}^{a_1} \cdot {p_2}^{a_2} \cdot \ldots \cdot {p_k}^{a_k}$ (just find the prime factorization of $n$).

Let $i$ be such an index that $a_i$ is the maximum among all values of $a$. Then the answer length can not exceed $a_i$. This is because if the answer has greater length, then some number doesn't have $p_i$ in its representation (thus, there will be problems with divisibility because we are considering primes). So, let's create the answer of length $a_i$ consisting of $p_i$. Then let's just multiply the last element by all other primes in their degrees. So, we satisfied the divisibility rule and the length of the answer is the maximum possible.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
	
		vector<pair<int, long long>> val;
		for (long long i = 2; i * i <= n; ++i) {
			int cnt = 0;
			while (n % i == 0) {
				++cnt;
				n /= i;
			}
			if (cnt > 0) {
				val.push_back({cnt, i});
			}
		}
		if (n > 1) {
			val.push_back({1, n});
		}
	
		sort(val.rbegin(), val.rend());
		vector<long long> ans(val[0].first, val[0].second);
		for (int i = 1; i < int(val.size()); ++i) {
			for (int j = 0; j < val[i].first; ++j) {
				ans.back() *= val[i].second;
			}
		}
	
		cout << ans.size() << endl;
		for (auto it : ans) cout << it << " ";
		cout << endl;
	}
	
	return 0;
}
```
[1454E - Number of Simple Paths](../problems/E._Number_of_Simple_Paths.md "Codeforces Round 686 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1454E - Number of Simple Paths](../problems/E._Number_of_Simple_Paths.md "Codeforces Round 686 (Div. 3)")

Because our graph is just a tree with an additional edge, consider it as a cycle with trees hanged on cycle vertices.

Consider some tree hung on a vertex $v$ on a cycle. There is only one path between each pair of its vertices (including the root which is a vertex $v$). So, if the tree has $cnt_v$ vertices, then $\frac{cnt_v(cnt_v-1)}{2}$ paths are added to the answer. What about paths that go out of a tree? Let's assume that there are $cnt_v \cdot (n - cnt_v)$ such paths (yeah, we counted only a half of actual paths from this component but this is fine). When we consider other trees, we will take into account the other half of paths.

This information can lead us to the conclusion that the only information we need to know about trees hanged on cycle vertices is the number of vertices in these trees. So, if we know $cnt_v$ for each vertex on a cycle, we can just calculate the answer as $\sum\limits_{v \in cycle} \frac{cnt_v(cnt_v-1)}{2} + cnt_v \cdot (n - cnt_v)$. So how to find values $cnt_v$?

Of course, there is a simple and straight-forward solution "just extract and mark all cycle vertices and run dfs from every vertex of a cycle", but there is another approach without any graph algorithms that works very well for such kind of graphs. Initially, let $cnt_v = 1$ for each $v$ from $1$ to $n$. Let's create a queue containing all leafs of the graph. Let's take the leaf $x$, get its parent $p$, add $cnt_p := cnt_p + cnt_x$ and remove the vertex $x$ with all edges incident to it. After that, if $p$ became a leaf, let's add it to the queue.

We can see that after processing all leafs only cycle vertices remain in the graph, and $cnt_v$ is exactly the number of the vertices in a tree (and we can just calculate the answer using the formula above).

This approach can be implemented in $O(n \log n)$ or in $O(n)$, there is almost no difference, but $O(n \log n)$ one can be written a bit simpler than a linear one.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<set<int>> g(n);
		for (int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			g[x].insert(y);
			g[y].insert(x);
		}
		vector<int> val(n, 1);
		queue<int> leafs;
		for (int i = 0; i < n; ++i) {
			if (g[i].size() == 1) {
				leafs.push(i);
			}
		}
		while (!leafs.empty()) {
			int v = leafs.front();
			leafs.pop();
			int to = *g[v].begin();
			val[to] += val[v];
			val[v] = 0;
			g[v].clear();
			g[to].erase(v);
			if (g[to].size() == 1) {
				leafs.push(to);
			}
		}
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += val[i] * 1ll * (val[i] - 1) / 2;
			ans += val[i] * 1ll * (n - val[i]);
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1454F - Array Partition](../problems/F._Array_Partition.md "Codeforces Round 686 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1454F - Array Partition](../problems/F._Array_Partition.md "Codeforces Round 686 (Div. 3)")

Let's fix the length of the first block (iterate through $i$ from $0$ to $n-3$). Let's also try to maximize the length of the third block using the second pointer. So, initially the length of the first block is $1$ and the maximum in the block is $a_0$ (after that, its length will be $2$ and the maximum will be $max(a_0, a_1)$, and so on). Let's move the left border of the third block $r$ while $a_r \le a_0$ and the second block have at least one element.

After we expanded the third block, consider some cases: if its maximum is less than $a_0$, then we don't need to consider this partition (we expanded the third block as much as we can but didn't find the required maximum). Otherwise, its maximum fits our conditions. Then let's find the minimum in the second block. Let it be $mn$. If $mn < mx$, this partition is also bad. If $mn = mx$, this partition is good, and we can just print it. Otherwise, $mn > mx$, and we need to fix the second block somehow. I claim that we only need to expand it by at most one element. Let's see why is it true. Consider we want to expand it to the right (the other case just uses the same logic). If we expanded our block by one element to the right and the new value in it is less than $mx$, then this partition is bad, and we can not use it (this is also the reason why we are trying to maximize the length of the third block). Otherwise, this value is always $mx$, because the first and the third blocks didn't have values greater than $mx$.

There are some cases in the implementation we need to consider carefully: first, we need to find the minimum in the second block fast enough. This can be done if we store it as a multiset (set with repetitions). Second, we can remove the only maximum in the third (or the first) block by expanding the second one. This can be handled easily if we just store all three blocks (not only the second one) as multisets. And the last case is that we sometimes need to move the left border of the third block to the right. This happens when we expand the first block and the second block becomes empty. So, this happens only $O(n)$ times in total.

Total time complexity of this solution is $O(n \log n)$.

There is also another solution from Gassa:

Let us start solving by asking the following question: in which segments will the maximal values end up?

Consider the maximum value $m$ in the whole array. If there are at least three of them, a valid answer is to pick any maximum except the first and the last as the middle segment. For example, "3 2 3 1 3 2 3" ($m = 3$) can be partitioned as "3 2[3]1 3 2 3" or as "3 2 3 1[3]2 3", where the middle segment is marked with square brackets. Otherwise, all $m$ should end up in the middle segment, so that maximums to the left and to the right are less. For example, in "1 2 3 1 3 2 1", we have to put both threes into the middle segment.

Let us now calculate the minimum value $v$ on the middle segment, considering the numbers between those equal to $m$. For example, in "1 2[3 1 3]2 1" the value $v = \min (3, 1, 3) = 1$. All numbers greater than $v$ should also go into the middle segment, and everything between them, which can result in $v$ decreasing even more. We have to expand the borders of the middle segment until the minimum value is such $v$ that there are only values not greater than $v$ left outside. Continuing with the example, we see that in "1 2[3 1 3]2 1", the middle segment should be expanded to "1[2 3 1 3 2]1". Conversely, if the maximum $m$ was unique, then $v = m$, and we didn't have to expand the middle segment at this stage. For example, in "1 2 3 2 1", the current state is "1 2[3]2 1".

If the maximums to the left and to the right are exactly $v$, we found an answer. Otherwise, any possible middle segment contains the middle segment that we now got. So we have to expand the middle segment, either to the left or to the right. As a result, the value $v$ may become smaller, which can cause another expansion.

What's left is to decide where to expand when we have a choice. We would like to do it greedily. Indeed, consider three values: the minimum on middle segment $v$, the maximum on left segment $u$ and the maximum on right segment $w$. When we expand the middle segment, each of them can only decrease. And if we find an answer, the equation $u = v = w$ will be satisfied. So, as we make the minimum of these three values smaller, we have less and less opportunities to make them equal. Thus we can pick the side of expansion after which the value $\min (u, v, w)$ is larger, and if these are equal, pick any.

For example, in the state "1 3[5 4 5]2 3 1", we have $u = 3$, $v = 4$, and $w = 3$. If we expand to the left, we get "1[3 5 4 5]2 3 1" where $u = 1$, $v = 3$, and $w = 3$. If we expand to the right, we get "1 3[5 4 5 2]3 1" where $u = 3$, $v = 2$, and $w = 3$. Our algorithm will pick expanding to the right, however, there is no valid answer in this example anyway.

Implementation: let us precalculate the maximums on all prefixes and all suffixes of the array. Then we can expand the middle segment by one element in $O (1)$, and the total running time is linear.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

bool found;

void shift(multiset<int> &l, multiset<int> &r, int val) {
	l.erase(l.find(val));
	r.insert(val);
}

void check(const multiset<int> &lf, const multiset<int> &mid, const multiset<int> &rg) {
	if (found || lf.empty() || mid.empty() || rg.empty()) {
		return;
	}
	if (*lf.rbegin() == *mid.begin() && *mid.begin() == *rg.rbegin()) {
		found = true;
		cout << "YES" << endl;
		cout << lf.size() << " " << mid.size() << " " << rg.size() << endl;
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		
		found = false;
		multiset<int> lf, mid(a.begin(), a.end()), rg;
		int r = n - 1;
		for (int l = 0; l < n - 2; ++l) {
			shift(mid, lf, a[l]);
			while (r - 1 >= l && a[r] <= *lf.rbegin()) {
				shift(mid, rg, a[r]);
				--r;
			}
			
			while (r - 1 < l) {
				shift(rg, mid, a[r + 1]);
				++r;
			}
			
			check(lf, mid, rg);
			
			shift(lf, mid, a[l]);
			check(lf, mid, rg);
			shift(mid, lf, a[l]);
			
			if (rg.empty()) continue;
			
			shift(rg, mid, a[r + 1]);
			check(lf, mid, rg);
			shift(mid, rg, a[r + 1]);
		}
		if (!found) {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}
```
 **Solution (Gassa)**
```cpp
// Author: Ivan Kazmenko (gassa@mail.ru)
module solution;
import std.algorithm;
import std.conv;
import std.range;
import std.stdio;
import std.string;

void main ()
{
	auto tests = readln.strip.to !(int);
	foreach (test; 0..tests)
	{
		auto n = readln.strip.to !(int);
		auto a = readln.splitter.map !(to !(int)).array;
		auto x = a.dup;
		foreach (i; 1..n)
		{
			x[i] = max (x[i], x[i - 1]);
		}
		auto y = a.dup;
		foreach_reverse (i; 0..n - 1)
		{
			y[i] = max (y[i], y[i + 1]);
		}

		auto v = a.maxElement;
		auto maxPlaces = n.iota.filter !(i => a[i] == v).array;
		int lo = maxPlaces[$ / 2];
		int hi = lo + 1;

		while (true)
		{
			if (lo == 0 || hi == n)
			{
				writeln ("NO");
				break;
			}
			if (x[lo - 1] == v && y[hi] == v)
			{
				writeln ("YES");
				writeln (lo, " ", hi - lo, " ", n - hi);
				break;
			}
			int u = (lo - 1 == 0) ? int.min :
			    min (x[lo - 2], a[lo - 1]);
			int w = (hi + 1 >= n) ? int.min :
			    min (y[hi + 1], a[hi]);
			if (u > w)
			{
				v = min (v, a[lo - 1]);
				lo -= 1;
			}
			else
			{
				v = min (v, a[hi]);
				hi += 1;
			}
		}
	}
}
```
