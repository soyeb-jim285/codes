# Tutorial

[1728A - Colored Balls: Revisited](../problems/A._Colored_Balls:_Revisited.md "Educational Codeforces Round 135 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1728A - Colored Balls: Revisited](../problems/A._Colored_Balls:_Revisited.md "Educational Codeforces Round 135 (Rated for Div. 2)")

Let's prove that the color with the maximum value of $cnt$ is one of the possible answers. 

Let the color $x$ have the maximum value of $cnt$; if there are several such colors, choose any of them. Let's keep taking the balls of two different colors out of the bag without touching the balls of color $x$ for as long as possible.

After such operations, two cases exist. In one case, only balls of color $x$ are left — then everything is fine. In other case, there are balls of color $x$ and some color $y$ (let $cnt_y$ be the remaining number of balls of this color). Since initially $cnt_x$ was one of the maximums, $cnt_y \le cnt_x$. However, the number of remaining balls is odd, which means $cnt_y \ne cnt_x$ and $cnt_y < cnt_x$. Therefore, we can keep taking the balls of colors $y$ and $x$ until only balls of color $x$ are left.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    cout << max_element(a.begin(), a.end()) - a.begin() + 1 << 'n';
  }
}
```
[1728B - Best Permutation](../problems/B._Best_Permutation.md "Educational Codeforces Round 135 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1728B - Best Permutation](../problems/B._Best_Permutation.md "Educational Codeforces Round 135 (Rated for Div. 2)")

Let $x_i$ be the value of the variable $x$ after $i$ steps. Note that $x_{n-1}$ should be less than $p_n$ for $x_n$ to be not equal to $0$. It means that $x_n$ does not exceed $2p_n - 1$. It turns out that for $n \ge 4$ there is always a permutation such that $x_n$ is equal to $2n - 1$.

The only thing left is to find out how to build such a permutation. There are many suitable permutations, let's consider one of the possible options. For an even $n$, a suitable permutation is $[2, 1, 4, 3, \ dots, n - 2, n - 3, n - 1, n]$. You can see that $x$ in such a permutation changes as follows: $[0, 2, 0, 4, 0, \dots, n - 2, 0, n - 1, 2n - 1]$. For an odd $n$, there is a similar permutation $[1, 3, 2, 5, 4, \dots, n - 2, n - 3, n - 1, n]$, where $x$ changes as follows: $[0, 1, 4, 0, 5, 0, \dots, n-2, 0, n - 1, 2n - 1]$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    for (int i = n & 1; i < n - 2; i += 2) swap(p[i], p[i + 1]);
    for (int &x : p) cout << x << ' ';
    cout << 'n';
  }
}
```
[1728C - Digital Logarithm](../problems/C._Digital_Logarithm.md "Educational Codeforces Round 135 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1728C - Digital Logarithm](../problems/C._Digital_Logarithm.md "Educational Codeforces Round 135 (Rated for Div. 2)")

First, why can you always make the arrays similar? Applying a digital logarithm to any number will eventually make it equal to $1$. Thus, you can at least make all numbers into $1$s in both arrays.

Then notice the most improtant thing — applying the digital logarithm to a number greater than $1$ always makes this number smaller.

Thus, if a number appears in only one of the arrays, you will have to do one of the followings two things: 

* decrease some greater number to make it equal to this one;
* decrease this number.

What if there is no greater number at all? This is the case for the largest number in both arrays altogether. If it appears in only one of the arrays, you must always decrease. If it appears in both, though, why decrease it further? Worst case, you will decrease it in one array, then you'll have to decrease it in the other array as well. This is never more optimal than just matching one occurrence in both arrays to each other and removing them from the arrays.

So, the proposed solution is the following. Consider the largest element in each array. If they are equal, remove both. If not, apply digital logarithm to the larger of them. Continue until the arrays are empty.

What's the estimated complexity of this algorithm? Each number in the first array will be considered at most the number of times you can decrease it with a digital logarithm operation plus one. That is at most $2+1$ — a number greater than $9$ always becomes a single digit and a single digit always becomes $1$. Same goes for the second array. So the complexity is basically linear.

To implement it efficiently, you will have to use some data structure that provides three operations: 

* peek at the maximum;
* remove the maximum;
* insert a new element.

The perfect one is a heap — priority_queue in C++.

Overall complexity: $O(n \log n)$ per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	forn(_, t){
		int n;
		scanf("%d", &n);
		vector<int> a(n), b(n);
		forn(i, n) scanf("%d", &a[i]);
		forn(i, n) scanf("%d", &b[i]);
		priority_queue<int> qa(a.begin(), a.end());
		priority_queue<int> qb(b.begin(), b.end());
		int ans = 0;
		while (!qa.empty()){
			if (qa.top() == qb.top()){
				qa.pop();
				qb.pop();
				continue;
			}
			++ans;
			if (qa.top() > qb.top()){
				qa.push(to_string(qa.top()).size());
				qa.pop();
			}
			else{
				qb.push(to_string(qb.top()).size());
				qb.pop();
			}
		}
		printf("%dn", ans);
	}
	return 0;
}
```
[1728D - Letter Picking](../problems/D._Letter_Picking.md "Educational Codeforces Round 135 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1728D - Letter Picking](../problems/D._Letter_Picking.md "Educational Codeforces Round 135 (Rated for Div. 2)")

What do we do, when the array loses elements only from the left or from the right and the constraints obviously imply some quadratic solution? Well, apply dynamic programming, of course.

The classic $dp[l][r]$ — what is the outcome if only the letters from positions $l$ to $r$ (non-inclusive) are left. $dp[0][n]$ is the answer. $dp[i][i]$ is the base case — the draw (both strings are empty). Let $-1$ mean that Alice wins, $0$ be a draw and $1$ mean that Bob wins.

How to recalculate it? Let's consider a move of both players at the same time. From some state $[l; r)$, first, Alice goes, then Bob. The new state becomes $[l', r')$, Alice picked some letter $c$, Bob picked some letter $d$. What's that pick exactly? So, they both got a letter, prepended it to their own string. Then continued the game on a smaller string $s$ and prepended even more letters to the string. Thus, if we want to calculate $[l, r)$ from $[l', r')$, we say that we append letters $c$ and $d$. Now it's easy. If $dp[l'][r']$ is not a draw, then the new letters change nothing — the result is still the same. Otherwise, the result of the game is the same as the comparison of letters $c$ and $d$.

How to perform both moves at once? First, we iterate over the Alice's move: whether she picks from $l$ or from $r$. After that we iterate over the Bob's move: whether he picks from $l$ or from $r$. Since we want $dp[l][r]$ to be the best outcome for Alice, we do the following. For any Alice move, we choose the worse of the Bob moves — the maximum of $dp[l'][r']$. Among the Alice's moves we choose the better one — the minimum one.

Overall complexity: $O(n^2)$ per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int comp(char c, char d){
	return c < d ? -1 : (c > d ? 1 : 0);
}

int main() {
	int t;
	cin >> t;
	forn(_, t){
		string s;
		cin >> s;
		int n = s.size();
		vector<vector<int>> dp(n + 1, vector<int>(n + 1));
		for (int len = 2; len <= n; len += 2) forn(l, n - len + 1){
			int r = l + len;
			dp[l][r] = 1;
			{
				int res = -1;
				if (dp[l + 1][r - 1] != 0)
					res = max(res, dp[l + 1][r - 1]);
				else
					res = max(res, comp(s[l], s[r - 1]));
				if (dp[l + 2][r] != 0)
					res = max(res, dp[l + 2][r]);
				else
					res = max(res, comp(s[l], s[l + 1]));
				dp[l][r] = min(dp[l][r], res);
			}
			{
				int res = -1;
				if (dp[l + 1][r - 1] != 0)
					res = max(res, dp[l + 1][r - 1]);
				else
					res = max(res, comp(s[r - 1], s[l]));
				if (dp[l][r - 2] != 0)
					res = max(res, dp[l][r - 2]);
				else
					res = max(res, comp(s[r - 1], s[r - 2]));
				dp[l][r] = min(dp[l][r], res);
			}
		}
		if (dp[0][n] == -1)
			cout << "Alicen";
		else if (dp[0][n] == 0)
			cout << "Drawn";
		else
			cout << "Bobn";
	}
	return 0;
}
```
[1728E - Red-Black Pepper](../problems/E._Red-Black_Pepper.md "Educational Codeforces Round 135 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1728E - Red-Black Pepper](../problems/E._Red-Black_Pepper.md "Educational Codeforces Round 135 (Rated for Div. 2)")

Let's start by learning how to answer a query $(1, 1)$ — all red pepper and black pepper options are available.

Let's iterate over all options to put the peppers and choose the maximum of them. First, let's use the red pepper for all dishes. Now we want to select some $k$ of them to use black pepper instead of red pepper. Which ones do we choose? When we switch from the red pepper to the black pepper, the total tastiness changes by $-a_i + b_i$ for the $i$-th dish. They are completely independent of each other, so we want to choose $k$ largest of these values.

Let $d_1, d_2, \dots, d_n$ be the sequence of values of $-a_i + b_i$ in a non-increasing order.

Thus, $k$ black peppers will yield the result of $\sum \limits_{i=1}^{n} a_i + \sum \limits_{i=1}^{k} d_i$. We can answer a query $(1, 1)$ by looking for a maximum in the sequence.

Now consider an arbitrary query. Let $p_1, p_2, \dots, p_t$ be all options for the amount of available black peppers for the query. Naively, we could iterate over all of them and choose the maximum one.

However, notice an interesting thing about the sequence of the answers. By definition, it is non-strictly convex. In particular, one idea that can be extracted from this is the following. Find the position of an arbitrary maximum in this sequence. Then everything to the left of is is non-increasing. Everything to the right of it is non-increasing.

Thus, for a query, it's enough to consider only two options: the one closest to the maximum from the left and from the right.

Now we only have to learn how to get these options fast enough. For a query $(x, y)$ we want to solve what's called a diophantine equation $ax + by = n$. An arbitrary solution can be obtained by using extended Euclid algorithm. Let it be some $(a, b)$. Then we would want to check the answer for $ax$ black peppers. The amount of solutions to the equation is either infinite or zero. If it's infinite, all solutions will be of the form $ax + k \cdot \mathit{lcm}(x, y)$ for any integer $k$. Remember that not all the solutions will be in a range $[0, n]$.

Finally, find the two solutions that are the closest to the maximum, check that they are in the range $[0, n]$ and print the best answer of them.

Overall complexity: $O(n \log n + q \log X)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

long long gcd(long long a, long long b, long long& x, long long& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long x1, y1;
	long long d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

bool find_any_solution(long long a, long long b, long long c, long long &x0, long long &y0, long long &g) {
	g = gcd(abs(a), abs(b), x0, y0);
	if (c % g) {
		return false;
	}
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n), b(n);
	forn(i, n) scanf("%d%d", &a[i], &b[i]);
	long long cur = accumulate(b.begin(), b.end(), 0ll);
	vector<int> difs(n);
	forn(i, n) difs[i] = a[i] - b[i];
	sort(difs.begin(), difs.end(), greater<int>());
	vector<long long> bst(n + 1);
	forn(i, n + 1){
		bst[i] = cur;
		if (i < n)
			cur += difs[i];
	}
	int mx = max_element(bst.begin(), bst.end()) - bst.begin();
	int m;
	scanf("%d", &m);
	forn(_, m){
		int x, y;
		scanf("%d%d", &x, &y);
		long long x0, y0, g;
		if (!find_any_solution(x, y, n, x0, y0, g)){
			puts("-1");
			continue;
		}
		long long l = x * 1ll * y / g;
		long long red = x0 * 1ll * x;
		red = red + (max(0ll, mx - red) + l - 1) / l * l;
		red = red - max(0ll, red - mx) / l * l;
		long long ans = -1;
		if (red <= n) ans = max(ans, bst[red]);
		red -= l;
		if (red >= 0) ans = max(ans, bst[red]);
		printf("%lldn", ans);
	}
	return 0;
}
```
[1728F - Fishermen](../problems/F._Fishermen.md "Educational Codeforces Round 135 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1728F - Fishermen](../problems/F._Fishermen.md "Educational Codeforces Round 135 (Rated for Div. 2)")

Suppose we have fixed some order of fishermen and calculated the values of $b_i$. Then, we have the following constraints on $b_i$:

* all values of $b_i$ are pairwise distinct;
* for every $i$, $a_i$ divides $b_i$.

Not every possible array $b$ meeting these constraints can be achieved with some order of fishermen, but we can show that if we choose an array $b$ with the minimum possible sum among the arrays meeting these two constraints, there exists an ordering of fishermen which yields this array $b$. The proof is simple — suppose the ordering of fishermen is the following one: the first fisherman is the one with minimum $b_i$, the second one — the one with the second minimum $b_i$, and so on. It's obvious that if we generate the values of $b$ according to this order, they won't be greater than the values in the array we have chosen. And if some value is less than the value in the chosen array $b$, it means that we haven't chosen the array with the minimum possible sum. So, we can rephrase the problem as the following one: for each $a_i$, choose the value of $b_i$ so that it is divisible by $a_i$, all $b_i$ are distinct, and their sum is minimized.

Using the pigeonhole principle, we can show that for every $a_i$, we need to consider only the values of $b_i$ among $[a_i, 2 \cdot a_i, 3 \cdot a_i, \dots, n \cdot a_i]$. So, we can formulate the problem as an instance of the weighted bipartite matching: build a graph with two parts, where the left part contains $n$ nodes representing the values of $a_i$, the right part represents the values of the form $k \cdot a_i$ where $1 \le k \le n$, and there exists an edge between a vertex in the left part representing the number $x$ and a vertex in the right part representing the number $y$ with cost $y$ if and only if $y = k \cdot x$ for some integer $k \in [1, n]$. Note that we don't add the edge if $k > n$ because we need to ensure that the size of the graph is $O(n^2)$.

Okay, now we need to solve this weighted matching problem, but how? The number of vertices is $O(n^2)$, and the number of edges is $O(n^2)$ as well, so mincost flow will run in $O(n^4)$ or $O(n^3 \log n)$, which is too much. Instead, we can notice that the cost of the edges incident to the same vertex in the right part is the same, so we can swap the parts of the graph, sort the vertices of the new left part (representing the numbers $k \cdot a_i$) according to their costs, and run the classical Kuhn's algorithm in sorted order. Kuhn's algorithm in its original implementation will always match a vertex if it is possible, so it obtains the minimum total cost for the matching if we do it in sorted order.

But this is still $O(n^4)$! What should we do? Well, there are some implementations of Kuhn's algorithm which can run on graphs of size about $10^5$ (sometimes even $10^6$). Why can't we use one of these? Unfortunately, not all optimizations that can be used in Kuhn's algorithm go together well with the fact that the vertices of the left part have their weights. For example, greedy initialization of matching won't work. So we need to choose optimizations carefully.

The model solution uses the following optimization of Kuhn's algorithm: if you haven't found an augmenting path, don't reset the values representing which vertices were visited by the algorithm. With this optimization, Kuhn's algorithm works in $O(M(E + V))$, where $M$ is the size of the maximum matching, $E$ is the number of edges, and $V$ is the number of vertices. So, this results in a solution with complexity of $O(n^3)$.

I think it's possible to show that some other optimizations of Kuhn can also work, but the one I described is enough.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

const int N = 1003;

int n;
int a[N];
vector<int> g[N * N];
int mt[N];
bool used[N * N];
vector<int> val;

bool kuhn(int x)
{
    if(used[x]) return false;
    used[x] = true;
    for(auto y : g[x])
        if(mt[y] == -1 || kuhn(mt[y]))
        {
            mt[y] = x;
            return true;
        }
    return false;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++)
        for(int j = 1; j <= n; j++)
            val.push_back(a[i] * j);
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    int v = val.size();
    long long ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 1; j <= n; j++)
        {
            int k = lower_bound(val.begin(), val.end(), a[i] * j) - val.begin();
            g[k].push_back(i);
        }
    for(int i = 0; i < n; i++) mt[i] = -1;
    for(int i = 0; i < v; i++)
    {
        if(kuhn(i))
        {
            ans += val[i];
            for(int j = 0; j < v; j++) used[j] = false;
        }
    }
    cout << ans << endl;
}
```
[1728G - Illumination](../problems/G._Illumination.md "Educational Codeforces Round 135 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1728G - Illumination](../problems/G._Illumination.md "Educational Codeforces Round 135 (Rated for Div. 2)")

Let's start without the queries. How to calculate the number of ways for the given $n$ lanterns?

First, it's much easier to calculate the number of bad ways — some point of interest is not illuminated. If at least one point of interest is not illuminated, then all lanterns have power lower than the distance from them to this point of interest. More importantly, it's less than $d$. Thus, the number of good ways is $(d+1)^n$ minus the number of bad ways.

Let's use inclusion-exclusion. For a mask of non-illuminated points of interest, let's calculate the number of ways to assign the powers to the lanterns in such a way that at least these points of interest are not illuminated. All other points can be either illuminated or not. Let's call it $\mathit{ways}[\mathit{mask}]$. With the values for all masks, the answer is the sum of $\mathit{ways}[\mathit{mask}] \cdot (-1)^{\mathit{popcount(mask)}}$ over all masks.

How to calculate the value for the mask? First, let's do it in $O(nm)$ for each mask. Each lantern can have any power from $0$ to the distance to the closest point of interest inside the mask non-inclusive. Thus, we can iterate over the lanterns and find the closest point to each of them, then multiply the number of ways for all lanterns.

Let's calculate it the other way around. Initialize the answers for the masks with $1$. Then iterate over the lantern and the point of interest that will be the closest non-illuminated one to this lantern. Let the distance between them be some value $d$. Which masks will this pair affect? Let the lantern be to the right of that point of interest. The opposite can be handled similarly.

All points to the left of the chosen point can be in either state. All points between the chosen one and the lantern must be illuminated. All points to the right of the lantern and with distance smaller than $d$ must also be illumunated. All point to the right of these can be in either state. Thus, the masks look like "**..**1000..000**..**", where 1 denotes the chosen non-illuminated point.

All masks that correspond to this template will be multiplied by $d$. You have to be careful when there are two points of interest with the same distance $d$ to some lantern — one to the left of it and one to the right of it. In particular, in one case, you should force illumination on all points with distance $<d$. In another case, you should force illumination on all points with distance $\le d$.

How to multiply fast enough? We'll use a technique called sum-over-subsets. Let's express the template in terms of submasks. For a template "***100000***", all submasks of "111100000111" will be multiplied by $d$. However, we accidentally multiplied masks of form "***000000***" too. Let's cancel them by dividing the submasks of "111000000111" by $d$. Record all multiplications for all pairs, them force push them into submasks with sum-over-subsets (well, product-over-subsets in this case :)).

Now we have the values of $\mathit{ways}[\mathit{mask}]$ for all masks in basically $O(nm + 2^m \cdot m)$, give or take the time to find the points that must be forced illuminated (extra $O(\log m)$ from lower_bound or two pointers, which is not really faster).

Now for the queries. How does the answer change after an extra lantern is added? Again, let's iterate over the closest point of interest and find the mask template. All masks corresponding to this template will get multiplied by $d$. Thus, the answer will change by the sum of values of these masks, multiplied by $d$, including the inclusion-exclusion coefficient. How to handle that? Well, yet another sum-over-subsets. Just collect the sum of values over the submasks beforehand and use these during the query. That gives us an $O(m)$ per query.

Overall complexity: $O(nm + qm + 2^m \cdot m)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int MOD = 998244353;

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return a * 1ll * b % MOD;
}

int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int main() {
	int D, n, m;
	
	scanf("%d%d%d", &D, &n, &m);
	
	vector<int> inv(D + 1);
	forn(i, D + 1) inv[i] = binpow(i, MOD - 2);
	
	vector<int> b(n);
	forn(i, n) scanf("%d", &b[i]);
	
	vector<int> a(m);
	forn(i, m) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	
	int fl = (1 << m) - 1;
	vector<int> ways(1 << m, 1);
	forn(i, m) forn(j, n){
		int d = abs(b[j] - a[i]);
		int mask;
		if (b[j] > a[i]){
			int r = lower_bound(a.begin(), a.end(), b[j] + d) - a.begin();
			mask = fl ^ ((1 << r) - 1) ^ ((1 << (i + 1)) - 1);
		}
		else{
			int l = lower_bound(a.begin(), a.end(), b[j] - d) - a.begin();
			mask = fl ^ ((1 << i) - 1) ^ ((1 << l) - 1);
		}
		ways[mask] = mul(ways[mask], d);
		mask ^= (1 << i);
		ways[mask] = mul(ways[mask], inv[d]);
	}
	
	forn(i, m) for (int mask = fl; mask >= 0; --mask) if ((mask >> i) & 1){
		ways[mask ^ (1 << i)] = mul(ways[mask ^ (1 << i)], ways[mask]);
	}
	
	ways[0] = binpow(D + 1, n);
	forn(mask, 1 << m){
		ways[mask] = mul(ways[mask], __builtin_popcount(mask) & 1 ? MOD - 1 : 1);
	}
	forn(i, m) forn(mask, 1 << m) if (!((mask >> i) & 1)){
		ways[mask ^ (1 << i)] = add(ways[mask ^ (1 << i)], ways[mask]);
	}
	
	int q;
	scanf("%d", &q);
	forn(_, q){
		int x;
		scanf("%d", &x);
		int ans = binpow(D + 1, n + 1);
		forn(i, m){
			int d = abs(x - a[i]);
			int mask;
			if (x > a[i]){
				int r = lower_bound(a.begin(), a.end(), x + d) - a.begin();
				mask = fl ^ ((1 << r) - 1) ^ ((1 << (i + 1)) - 1);
			}
			else{
				int l = lower_bound(a.begin(), a.end(), x - d) - a.begin();
				mask = fl ^ ((1 << i) - 1) ^ ((1 << l) - 1);
			}
			ans = add(ans, mul(add(ways[mask], -ways[mask ^ (1 << i)]), d));
		}
		printf("%dn", ans);
	}
	
	return 0;
}
```
