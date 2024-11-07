# Tutorial

[1832A - New Palindrome](../problems/A._New_Palindrome.md "Educational Codeforces Round 148 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1832A - New Palindrome](../problems/A._New_Palindrome.md "Educational Codeforces Round 148 (Rated for Div. 2)")

Let's look at the first $\left\lfloor\frac{|s|}{2}\right\rfloor$ characters. If all these characters are equal, then there is no way to get another palindrome. Otherwise, there are at least two different characters, you can swap them (and the characters symmetrical to them on the right half of the string), and get a palindrome different from the given one.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    s = s.substr(0, s.size() / 2);
    int k = unique(s.begin(), s.end()) - s.begin();
    cout << (k == 1 ? "NO" : "YES") << 'n';
  }
}
```
[1832B - Maximum Sum](../problems/B._Maximum_Sum.md "Educational Codeforces Round 148 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1832B - Maximum Sum](../problems/B._Maximum_Sum.md "Educational Codeforces Round 148 (Rated for Div. 2)")

The first instinct is to implement a greedy solution which removes either two minimums or one maximum, according to which of the options removes elements with smaller sum. Unfortunately, this doesn't work even on the examples (hint to the participants of the round: if your solution gives a different answer on the examples, most probably you should try to find an error in your solution, not send messages to the author that their answers are definitely wrong).

Okay, we need something other. Let's notice that the order of operations does not matter: deleting two minimums and then maximum is the same as choosing the other way around. So, we can iterate on the number of operations $m$ when we remove the two minimums; then the resulting array is the array $a$ from which we removed $2m$ minimums and $(k-m)$ maximums.

How to quickly calculate the sum of remaining elements? First of all, sorting the original array $a$ won't hurt, since the minimums then will always be in the beginning of the array, and the maximums will be in the end. After the array $a$ is sorted, every operation either deletes two leftmost elements, or one rightmost element. So, if we remove $2m$ minimums and $(k-m)$ maximums, the elements that remain form the segment from the position $(2m+1)$ to the position $(n-(k-m))$ in the sorted array; and the sum on it can be computed in $O(1)$ with prefix sums.

Time complexity: $O(n \log n)$.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n, k = map(int, input().split())
	a = sorted(list(map(int, input().split())))
	ans = 0
	pr = [0] * (n + 1)
	for i in range(n):
		pr[i + 1] = pr[i] + a[i]
	for i in range(k + 1):
		ans = max(ans, pr[n - (k - i)] - pr[2 * i])
	print(ans)
```
[1832C - Contrast Value](../problems/C._Contrast_Value.md "Educational Codeforces Round 148 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1832C - Contrast Value](../problems/C._Contrast_Value.md "Educational Codeforces Round 148 (Rated for Div. 2)")

Let's rephrase the problem in the following form: let the elements of the array be points on a coordinate line. Then the absolute difference between two adjacent elements of the array can be represented as the distance between two points, and the contrast of the entire array is equal to the total distance to visit all points in the given order.

In this interpretation, it becomes obvious that removing any set of points does not increase contrast. Since the resulting contrast should be equal to the original one, we can only remove elements from the array that do not decrease the contrast.

First of all, let's look at consecutive equal elements, it is obvious that you can delete all of them except one, and the contrast of the array will not change. In some languages, you can use a standard function to do this — for example, in C++ you can use unique.

After that, let's look at such positions $i$ that $a_{i - 1} < a_i < a_{i + 1}$; you can delete the $i$-th element, because $|a_{i - 1} - a_i| + |a_i - a_{i + 1}| = |a_{i - 1} - a_{i + 1}|$. Similarly, for positions $i$, where $a_{i - 1} > a_i > a_{i + 1}$, the element can be removed. In all other cases, removing the element will decrease the contrast.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    n = unique(a.begin(), a.end()) - a.begin();
    int ans = n;
    for (int i = 0; i + 2 < n; ++i) {
      ans -= (a[i] < a[i + 1] && a[i + 1] < a[i + 2]);
      ans -= (a[i] > a[i + 1] && a[i + 1] > a[i + 2]);
    }
    cout << ans << 'n';
  }
}
```
[1832D1 - Red-Blue Operations (Easy Version)](../problems/D1._Red-Blue_Operations_(Easy_Version).md "Educational Codeforces Round 148 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1832D1 - Red-Blue Operations (Easy Version)](../problems/D1._Red-Blue_Operations_(Easy_Version).md "Educational Codeforces Round 148 (Rated for Div. 2)")

Let's try applying the operation to a single element multiple times. You can see that when you apply an operation an odd number of times, the element always gets larger. Alternatively, applying an operation an even amount of times always makes it smaller (or equal in case of $0$). Thus, generally, we would want to apply an odd number of operations to as many elements as we can.

Let's start by investigating an easy case: $k \le n$. Since there are so few operations, you can avoid subtracting from any element at all. Just one operation to each of $k$ elements. Which elements should get this operation? Obviously, $k$ smallest elements. If you don't pick at least one of them, it'll remain as the minimum of the array. If you do, the minimum will get larger than any of them. Another greedy idea is where to apply each operation to. We should add $k$ to the minimum element, $k-1$ to the second minimum and so on. You can show that it is always optimal by contradiction.

What if $k > n$? Then we have to subtract from some elements. First, recognize that there's no more than one element that will become smaller in the optimal answer. Consider an answer where at least two elements get smaller and move the later operation from one to another. Now both of them become larger.

Moreover, for parity reasons, if $k \bmod 2 = n \bmod 2$, you can increase all elements. Otherwise, you have to decrease exactly one.

Another greedy idea. You somewhat want the pair of operations (increase, decrease) to change the element as small as possible. In particular, you can always make the change equal to $-1$. To show it, you can look at some decreasing operation such that an increasing operation goes right before it and they are applied to different elements. You can swap them. They remain the same types. However, both elements get only larger. In the end, all adjacent increasing and decreasing operations go to the same element.

Now, let's think of the answer as the following sequence: adjacent pairs of (increase, decrease) and the separate increase operations that are applied no more than once to each element. Since all blocks do $-1$, only the values in the lone increase operations affect the answer value. Obviously, we would want these lone increases to be $k, k - 1, \dots, k - t$, where $t$ is the number of changed elements ($n-1$ or $n$). Once again, you can show that you can always rearrange the operations to obtain that.

Finally, the answer looks like this: add $k$ to the minimum, $k-1$ to the second minimum, $k - (n - (n + k) \bmod 2) - 1$ to the maximum or the second maximum depending on the parity. Before that, add $-1$ to some elements. Since we know where to apply the last operations, let's apply them first. Then we want to apply $-1$'s to make the minimum as large as possible. Well, we should always apply it to the current maximum. First, the minimum would remain as the original minimum. Then all elements will become equal to it at some point. Then we will be spreading the $-1$'s equally among the elements. So every $n$ additional operations, the minimum will be decreasing by $1$.

For the easy version, you can simulate this process. Sort the array, apply the last increase operations, find the minimum and the sum of the array, then calculate the result based on that. Let $a' = [a_1 + k, a_2 + k - 1, \dots]$. Let $s = \sum_{i = 1}^n (a' - \min a')$. Then the first $s$ operations of $-1$ will not change the minimum. The rest $\frac{k - (n - (n - k) \bmod 2)}{2} - s$ operations will decrease it by $1$ every $n$ operations. So it will get decreased by $\left\lceil\frac{\max(0, \frac{k - (n - (n - k) \bmod 2)}{2} - s)}{n}\right\rceil$.

Overall complexity: $O(n \cdot q \cdot \log n)$.

[1832D2 - Red-Blue Operations (Hard Version)](../problems/D2._Red-Blue_Operations_(Hard_Version).md "Educational Codeforces Round 148 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1832D2 - Red-Blue Operations (Hard Version)](../problems/D2._Red-Blue_Operations_(Hard_Version).md "Educational Codeforces Round 148 (Rated for Div. 2)")

Read the editorial to the easy version to get the general idea of the solution.

Now, we should only optimize the calculations.

First, the sorting can obviously be done beforehand. Now we want to get the minimum and the sum after applying the last increase operations. Consider $(n + k) \bmod 2 = 0$ and $k > n$, the other cases are similar. The minimum is that: $\min_{i=1}^n a_i - (i - 1) + k = k + \min_{i=1}^n a_i - (i - 1)$. Notice how the second part doesn't depend on $k$ and precalculate it.

You can calculate prefix minimum array over $a'$.

This surely helps with the case of $k < n$. The resulting minimum is $\min(\mathit{pref}_k + k, a_{k+1})$ (since $a$ is sorted, the first element after the changed prefix is the smallest).

For $k \bmod 2 = n \bmod 2$, the minimum is $\mathit{pref}_n + k$.

For $k \bmod 2 \neq n \bmod 2$, the minimum is $\min(\mathit{pref}_{n-1} + k, a_n)$.

The sum is similar: $\sum_{i=1}^n a_i - (i - 1) + k = n \cdot k + \sum_{i=1}^n a_i - (i - 1)$. As easy to precalculate.

The rest is the same.

Overall complexity: $O(n \log n + q)$.

 **Solution (awoo)**
```cpp
n, q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
pr = [10**9 for i in range(n + 1)]
for i in range(n):
	pr[i + 1] = min(pr[i], a[i] - i)
s = sum(a) - n * (n - 1) // 2
ans = []
for k in map(int, input().split()):
	if k < n:
		ans.append(min(pr[k] + k, a[k]))
		continue
	if k % 2 == n % 2:
		ns = s - pr[n] * n
		ans.append(pr[n] + k - (max(0, (k - n) // 2 - ns) + n - 1) // n)
	else:
		nmn = min(pr[n - 1], a[n - 1] - k)
		ns = (s + (n - 1) - k) - nmn * n
		ans.append(nmn + k - (max(0, (k - (n - 1)) // 2 - ns) + n - 1) // n)
print(*ans)
```
[1832E - Combinatorics Problem](../problems/E._Combinatorics_Problem.md "Educational Codeforces Round 148 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1832E - Combinatorics Problem](../problems/E._Combinatorics_Problem.md "Educational Codeforces Round 148 (Rated for Div. 2)")

Unfortunately, it looks like the constraints were insufficient to cut the convolution solutions off. So it's possible to solve this problem using a very fast convolution implementation, but the model approach is different from that.

One of the properties of Pascal's triangle states that $\binom{x}{y} = \binom{x-1}{y} + \binom{x-1}{y-1}$. Using it, we can rewrite the formula for $b_i$ as follows:

$$b_i = (\sum\limits_{j=1}^{i} \binom{i - j + 1}{k} \cdot a_j)$$

$$b_i = (\sum\limits_{j=1}^{i} \binom{i-j}{k} \cdot a_j) + (\sum\limits_{j=1}^{i} \binom{i-j}{k-1} \cdot a_j)$$

Now, the first sum is almost the same as $b_i$, but with $i$ decreased by $1$. So, it is just $b_{i-1}$.

What does the second sum stand for? It's actually $b_{i-1}$, but calculated with $k-1$ instead of $k$. upd: The only exception is $k = 1$, for which the last term in the summation has coefficient $\binom{0}{0} = 1$, that's why it is equal to $b_i$ calculated with $k = 0$, not $b_{i-1}$.

Now, let $c_{i,j}$ be equal to the value of $b_i$ if we solve this problem with $k = j$. The formula transformations we used show us that $c_{i,j} = c_{i-1,j} + c_{i-1,j-1}$ (upd: When $j = 1$, the formula is $c_{i,j} = c_{i-1,j} + c_{i,j-1}$ instead), so we can use dynamic programming to calculate $c_{i,k}$ in $O(nk)$. But we need some base values for our dynamic programming. It's quite easy to see that $c_{0,j} = 0$; but what about $c_{i,0}$?

$$c_{i,0} = \sum\limits_{j=1}^{i} \binom{i - j + 1}{0} \cdot a_j$$

And since $\binom{i - j + 1}{0} = 1$, then

$$c_{i,0} = \sum\limits_{j=1}^{i} a_j$$

So, in order to obtain $c_{i,0}$, we can just build prefix sums on the array $a$.

In fact, it's possible to show that transitioning from the $j$-th layer of dynamic programming to the $(j+1)$-th is also just applying prefix sums; then the solution would become just replacing $a$ with prefix sums of $a$ exactly $k+1$ times. This observation was not needed to get AC, but it allows us to write a much shorter code.

Solution complexity: $O(nk)$.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int x, int y, int mod = MOD)
{
	return ((x + y) % mod + mod) % mod;
}

int mul(int x, int y, int mod = MOD)
{
	return (x * 1ll * y) % mod;
}

int binpow(int x, int y, int mod = MOD)
{
	int z = add(1, 0, mod);
	while(y > 0)
	{
		if(y % 2 == 1) z = mul(z, x, mod);
		y /= 2;
		x = mul(x, x, mod);
	}
	return z;
}

vector<int> psum(vector<int> v)
{
	vector<int> ans(1, 0);
	for(auto x : v) ans.push_back(add(ans.back(), x));
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	cin >> a[0];
	int x, y, m, k;
	cin >> x >> y >> m >> k;
	for(int i = 1; i < n; i++)
		a[i] = add(mul(a[i - 1], x, m), y, m);
	
	for(int i = 0; i <= k; i++)
		a = psum(a);
	long long ans = 0;
	
	for(int i = 1; i <= n; i++)
		ans ^= (a[i + 1] * 1ll * i);
	cout << ans << endl;
}
```
[1832F - Zombies](../problems/F._Zombies.md "Educational Codeforces Round 148 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1832F - Zombies](../problems/F._Zombies.md "Educational Codeforces Round 148 (Rated for Div. 2)")

First of all, let's rephrase the problem a bit. For each entrance, we will have two time segments: the segment when it is guarded, and the segment when the corresponding generator works. The zombies will arrive through that entrance at every moment not belonging to these two segments; so, if we want to maximize the number of zombies, we want to minimize the length of the unions of these pairs of segments for the entrances; and since the lengths of the segments are fixed, minimizing the union means maximizing the intersection. So, we need to choose the time segments for the generators and assign entrances to generators so that the sum of intersections of segment pairs for each entrance is the maximum possible.

Okay, now we work with the sum of intersections. Suppose there are multiple generators (for which we have already chosen their time segments) and an entrance; is there an easy method how to choose the optimal generator for the entrance? In fact, there is. We need to look at the centers of all segments (both for the generators and the entrance), and choose the generator for which the distance from the center of the entrance-segment to the center of the segment from that generator is the minimum possible (this only works because all generators have the same working time). Mathematically, if the segments for the generators are denoted as $[L_j, R_j)$, and the segment borders for the entrance are $[l_j, r_j)$, we need to choose the generator that minimizes the value of $|(L_j + R_j) - (l_j + r_j)|$, since it also minimizes the distance between the centers of the segments.

Do you see where this is going? In fact, this observation allows us to use exchange argument DP. Suppose the segments for the generators are already chosen; we can sort the entrances according to the values $(l_j + r_j)$ for each entrance, and then split the sorted order of entrances into several groups: all entrances in the first group are optimal to hook up to the first generator, all entrances in the second group are optimal to hook up to the second generator, and so on. But since the segments of the generators are not fixed, we will instead split the sorted order of the entrances into $k$ groups, and for each group, optimally choose the segment for the respective generator. So, this leads us to the following dynamic programming: $dp_{i,j}$ — the maximum possible sum of intersections if we have split the first $i$ entrances in sorted order into $j$ groups. The transitions in this dynamic programming are quite simple: we can just iterate on the next group, transitioning from $dp_{i,j}$ to $dp_{i',j+1}$.

Unfortunately, there are still two issues with this solution:

* How to reduce the number of transitions from $O(n^3)$ to something like $O(n^2 \log n)$ or $O(n^2)$?
* How to choose the best generator placement for a group of entrances, preferably either in $O(1)$ or $O(\log n)$ per one segment of entrances?

Okay, the solution to the first issue is not that difficult. Intuitively, it looks like the running time of this dynamic programming can be improved with some of the well-known DP optimizations. The two that probably come to mind first are divide-and-conquer optimization and aliens trick. Both of them seem to work, but unfortunately, we can prove only one of them (the proof is in the paragraph below). You can choose any of these two optimizations.

Proof that D&C optimization works

We can prove this via quadrangle inequality: let $cost[l..r]$ be the total intersection for the entrances from $l$ to $r$ if the generator for them is chosen optimally, and $opt[l..r]$ be the optimal starting moment of the generator for entrances from $l$ to $r$. We have to show that $cost[a..c] + cost[b..d] \ge cost[a..d] + cost[b..c]$, where $a \le b \le c \le d$.

Suppose $opt[a..d] = opt[b..c]$. Then, if we take all entrances $[c+1..d]$ from the first group and add them to the second group, then choosing $opt[a..d]$ as the starting point for these two groups gives us the total intersection equal to exactly $cost[a..d] + cost[b..c]$. So, in this case, $cost[a..c] + cost[b..d] \ge cost[a..d] + cost[b..c]$.

Now suppose $opt[a..d] < opt[b..c]$ (the case $opt[a..d] > opt[b..c]$ is similar). Let's again try to move all entrances $[c+1..d]$ from the first group to the second group. If the resulting sum of intersections (without shifting the starting points for the generators) did not decrease, we have shown that $cost[a..c] + cost[b..d] \ge cost[a..d] + cost[b..c]$. Otherwise, at least one entrance from $[c+1..d]$ is closer to $opt[a..d]$ than to $opt[b..c]$ (in terms of distance between the segment centers). This means that since the centers of the segments in $[b..c]$ are not greater than the center of the segments in $[c+1..d]$, then the segments from $[b..c]$ are also closer to $opt[a..d]$ than to $opt[b..c]$. So, the optimal starting moment for $[b..c]$ can be shifted to $opt[a..d]$, and we arrive at the case we analyzed in the previous paragraph.

End of proof

The solution to the second issue is a bit more complex. First of all, notice that the only possible starting moments for generators we are interested in are of the form $l_i$ and $r_i - m$, so there are only $2n$ of them. Then let's try to understand how to evaluate the sum of intersections for the generator starting at some fixed moment and a segment of entrances. The model solution does some very scary stuff with logarithmic data structures, but the participants of the round showed us a much easier way: create a $2n \times n$ matrix, where the number in the cell $(i, j)$ is the intersection of the segment for the $i$-th starting moment of the generator, and the segment when the $j$-th entrance (in sorted order) is guarded; then, for a segment of entrances and a fixed starting moment of the generator, the total intersection can be calculated in $O(1)$ using prefix sums on this matrix.

Unfortunately, trying each starting moment for every group of segments is still $O(n^3)$. But it can be improved using something like Knuth optimization: let $opt_{l,r}$ be the optimal starting point of the generator for the group of entrances $[l..r]$; then $opt_{l,r}$ is between $opt_{l,r-1}$ and $opt_{l+1,r}$, so calculating these optimal starting points in the style of Knuth optimization gives us $O(n^2)$. However, there's one last nasty surprise waiting for us: if we are not careful about choosing optimal starting moments, it's possible that $opt_{l,l} > opt_{l+1,l+1}$ (for example, if the segment for the entrance $l$ includes the segment for the generator $l+1$), which breaks the initialization of Knuth optimization. To resolve this issue, we can initialize the values of $opt_{l,l}$ in a monotonic way, choosing $opt_{l+1,l+1}$ only from values not less than $opt_{l,l}$.

Implementing all of this results in a solution that works in $O(n^2 \log n)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct seg{
	int l, r;
};

int n;
vector<long long> dp_before, dp_cur;
vector<vector<long long>> bst;

void compute(int l, int r, int optl, int optr){
	if (l > r) return;
	int mid = (l + r) / 2;
	pair<long long, int> best = {-1, -1};
	for (int k = optl; k <= min(mid, optr); k++)
		best = max(best, {(k ? dp_before[k - 1] : 0) + bst[k][mid], k});
	dp_cur[mid] = best.first;
	int opt = best.second;
	compute(l, mid - 1, optl, opt);
	compute(mid + 1, r, opt, optr);
}

struct node{
    long long c0;
    int c1;
};

vector<node> f;

void update(int x, int a, int b){
	for (int i = x; i < int(f.size()); i |= i + 1){
		f[i].c0 += b;
		f[i].c1 += a;
	}
}

void update(int l, int r, int a, int b){
	update(l, a, b);
	update(r, -a, -b);
}

long long get(int pos, int x){
	long long res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		res += f[i].c0 + f[i].c1 * 1ll * pos;
	return res;
}

int main() {
	int k, x, m;
	scanf("%d%d%d%d", &n, &k, &x, &m);
	vector<seg> a(n);
	forn(i, n) scanf("%d%d", &a[i].l, &a[i].r);
	sort(a.begin(), a.end(), [&](const seg &a, const seg &b){
		return a.l + a.r < b.l + b.r;
	});
	
	vector<int> pos;
	forn(i, n){
		pos.push_back(a[i].l);
		pos.push_back(a[i].r - m);
	}
	sort(pos.begin(), pos.end());
	pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
	int cds = pos.size();
	
	vector<array<int, 4>> npos(n);
	forn(i, n){
		npos[i][0] = lower_bound(pos.begin(), pos.end(), a[i].l - m) - pos.begin();
		npos[i][1] = lower_bound(pos.begin(), pos.end(), a[i].l) - pos.begin();
		npos[i][2] = lower_bound(pos.begin(), pos.end(), a[i].r - m) - pos.begin();
		npos[i][3] = lower_bound(pos.begin(), pos.end(), a[i].r) - pos.begin();
	}
	
	vector<long long> pr(n + 1);
	forn(i, n) pr[i + 1] = pr[i] + x - (m + a[i].r - a[i].l);
	
	auto upd = [&](int i){
		if (a[i].r - a[i].l >= m){
			update(npos[i][0], npos[i][1], 1, m - a[i].l);
			update(npos[i][1], npos[i][2], 0, m);
			update(npos[i][2], npos[i][3], -1, a[i].r);
		}
		else{
			update(npos[i][0], npos[i][2], 1, m - a[i].l);
			update(npos[i][2], npos[i][1], 0, a[i].r - a[i].l);
			update(npos[i][1], npos[i][3], -1, a[i].r);
		}
	};
	
	bst.resize(n, vector<long long>(n, -1));
	vector<vector<int>> opt(n, vector<int>(n));
	forn(r, n) for (int l = r; l >= 0; --l){
		if (l == r) f.assign(cds, {0, 0});
		upd(l);
		int L = (l == r ? (l == 0 ? 0 : opt[l - 1][l - 1]) : opt[l][r - 1]);
		int R = (l == r ? int(pos.size()) - 1 : opt[l + 1][r]);
		for (int k = L; k <= R; ++k){
			long long cur = pr[r + 1] - pr[l] + get(pos[k], k);
			if (cur > bst[l][r]){
				bst[l][r] = cur;
				opt[l][r] = k;
			}
		}
	}
	
	dp_before.resize(n);
	dp_cur.resize(n);
	for (int i = 0; i < n; i++)
		dp_before[i] = bst[0][i];

	for (int i = 1; i < k; i++){
		compute(0, n - 1, 0, n - 1);
		dp_before = dp_cur;
	}
	
	printf("%lldn", dp_before[n - 1]);
	return 0;
}
```
