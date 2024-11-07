# Tutorial

[1716A - 2-3 Moves](../problems/A._2-3_Moves.md "Educational Codeforces Round 133 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1716A - 2-3 Moves](../problems/A._2-3_Moves.md "Educational Codeforces Round 133 (Rated for Div. 2)")

If $n = 1$, the answer is $2$ (we can't get $1$, so we can move by $3$ to the right and by $2$ to the left). If $n = 2$ or $n = 3$, the answer is obviously $1$. Otherwise, the answer is always $\lceil\frac{n}{3}\rceil$. We can't get the answer less than this value (because we need at least $\lceil\frac{n}{3}\rceil$ moves to get to the point greater than or equal to $n$) and we can always get this answer by the recurrence.

 **Solution (vovuh)**
```cpp
for _ in range(int(input())):
    n = int(input())
    print(1 + (n == 1) if n <= 3 else (n + 2) // 3)
```
[1716B - Permutation Chain](../problems/B._Permutation_Chain.md "Educational Codeforces Round 133 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1716B - Permutation Chain](../problems/B._Permutation_Chain.md "Educational Codeforces Round 133 (Rated for Div. 2)")

Ideally, we would want the fixedness values to be $n, n - 1, n - 2, \dots, 0$. That would make a chain of length $n + 1$.

However, it's impossible to have fixedness of $n - 1$ after one swap. The first swap always makes a permutation with fixedness $n - 2$.

Okay, how about $n, n - 2, n - 3, \dots, 0$ then? That turns out to always be achievable.

For example, swap elements $1$ and $2$, then elements $2$ and $3$, then $3$ and $4$ and so on.

Overall complexity: $O(n^2)$ per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	p = [i + 1 for i in range(n)]
	print(n)
	for i in range(n):
		print(*p)
		if i < n - 1:
			p[i], p[i + 1] = p[i + 1], p[i]
```
[1716C - Robot in a Hallway](../problems/C._Robot_in_a_Hallway.md "Educational Codeforces Round 133 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1716C - Robot in a Hallway](../problems/C._Robot_in_a_Hallway.md "Educational Codeforces Round 133 (Rated for Div. 2)")

Let's first consider the possible paths across the grid that visit all cells. You can immediately think of two of them. The first one is: go right to the wall, turn into the other row and return. Let's call it a hook. The second one is: go down, go right, go up, go right and so on. Let's call it a snake.

Turns out, these two are basically the two extremes of all paths. You can start with a snake and turn into a hook when you wish. You can see that once you move right twice in a row, you can only continue with a hook. And as long as you didn't move right twice, you are just doing a snake.

Let's fix some path across the grid. What will its minimum time be? Calculate it iteratively. If you want to enter the next cell, and it's still locked, wait until it isn't. So there are some seconds of waiting (possibly, zero) before each cell.

However, why not instead do the following. Let's calculate the sum of waiting time required and wait for that amount of seconds before starting to move. All cells will be visited at the same time as before or even later. Thus, they will surely be unlocked if they were in the original plan.

So the goal is to calculate the minimum amount of time required to wait in the start, then add the movement time to it.

Once again, the path is fixed. Let the $k$-th cell of the path be $(x_k, y_k)$. If you start after waiting for $t$ seconds, then you reach the $k$-th cell at time $t + k$ ($k$ is $1$-indexed). Thus, the $k$-th cell should have $a_{x_k, y_k} \le t + k - 1$. If all cells satisfy this condition, then the path can be done after waiting for $t$ seconds at the start.

Let's rewrite it into $t \ge a_{x_k, y_k} - k + 1$. So, the condition tells us that $t$ should be greater or equal than this value for all cells. In other words, $t$ should be greater or equal than the maximum of the values over all cells.

Study the formula. Imagine we have some path with a known length and want to append a cell to it. That's pretty simple. Just update the maximum with the value with the corresponding cell and increase the length.

What if we wanted to prepend a cell to it? Turns out, it's not that hard as well. Every cell in the path gets its value $k$ increased by $1$. From the formula, you can see that this actually decreases the value of each cell by $1$. So the maximum decreases by $1$ as well. The only thing left is to update the maximum with the value of the new first cell. Well, and increase the length again.

Finally, let's learn how to choose the best path. We can iterate over the length of the snake part. The hook part is determined uniquely.

It's easy to maintain the maximum on the snake. Just append the new cell to the path.

How to glue up the hook part to that?

Well, actually, realize that the formula allows us to glue up two paths into one. Let path $1$ have length $n_1$ and maximum $\mathit{mx}_1$ and path $2$ have length $n_2$ and maximum $\mathit{mx}_2$. To make path $2$ start after path $1$, we just decrease its maximum by $n_1$. The resulting path has length $n_1 + n_2$ and maximum $\max(\mathit{mx}_1, \mathit{mx}_2 - n_1)$.

Let's look closer into what the hooks look like. They start in some column $j$, traverse all the way right, then left up to the same column $j$. If the snake part took both cells in its last column, then that's it. Otherwise, the hook has to take the final cell in the last column — column $j-1$.

If we manage to precalculate something for hooks that start in some column $j$ and end in column $j$, then we will be able to use that. Appending the final cell is not a hard task, since we know its index in the path ($k = 2 \cdot m$).

Let $\mathit{su}_{i,j}$ be the waiting time required for a hook that starts in cell $(i, j)$ and ends in a cell $(3 - i, j)$ as if the path started with the hook (cell $(i, j)$ is the first one).

$\mathit{su}_{i,j}$ can be calculated from $\mathit{su}_{i,j+1}$. Prepend it with a cell $(i, j)$ and append it with a cell $(3 - i, j)$.

The only thing left is to find the best answer. I found the most convenient to start with a snake of length $1$ (only cell $(1, 1)$) and progress it two steps at the time: 

1. update the answer;
2. progress the snake to the other cell of the current column;
3. update the answer;
4. progress the snake into the next column.

Overall complexity: $O(m)$ per testcase.

 **Solution (awoo)**
```cpp
INF = 2 * 10**9

for _ in range(int(input())):
	m = int(input())
	a = [[int(x) for x in input().split()] for i in range(2)]
	su = [[-INF for j in range(m + 1)] for i in range(2)]
	for i in range(2):
		for j in range(m - 1, -1, -1):
			su[i][j] = max(su[i][j + 1] - 1, a[i][j], a[i ^ 1][j] - (2 * (m - j) - 1))
	pr = a[0][0] - 1
	ans = INF
	for j in range(m):
		jj = j & 1
		ans = min(ans, max(pr, su[jj][j + 1] - 2 * j - 1, a[jj ^ 1][j] - 2 * m + 1))
		pr = max(pr, a[jj ^ 1][j] - 2 * j - 1)
		ans = min(ans, max(pr, su[jj ^ 1][j + 1] - 2 * j - 2))
		if j < m - 1:
			pr = max(pr, a[jj ^ 1][j + 1] - 2 * j - 2)
	print(ans + 2 * m)
```
[1716D - Chip Move](../problems/D._Chip_Move.md "Educational Codeforces Round 133 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1716D - Chip Move](../problems/D._Chip_Move.md "Educational Codeforces Round 133 (Rated for Div. 2)")

Let's calculate dynamic programming $dp_{s, i}$ — the number of ways to achieve $i$ in $s$ moves. From the state $(s, i)$, you can make a transition to the states $(s+1, j)$, where $i < j$ and $j - i$ is divisible by $k + s$.

Let's try to estimate the maximum number of moves, because it seems that there can't be very many of them. For $m$ moves, the minimum distance by which a chip can be moved is $k+ (k + 1) + \dots + (k + m - 1)$ or $\frac{(k + k + m - 1) \cdot m}{2}$. From here one can see that the maximum number of transitions does not exceed $\sqrt{2n}$ (maximum at $k=1$). So it remains to make transitions in dynamic programming faster than $O(n)$ from a single state for a fast enough solution. Let's use the fact that $j \equiv i \pmod{k+s}$. Let's iterate over the value of $j$ and maintain the sum of dynamic programming values with smaller indices for each remainder modulo $k + s$ in a separate array.

The final complexity of such a solution is $O(n\sqrt{n})$.

It remains to solve the memory problem, because with the existing limits, it is impossible to save the entire $dp$ matrix of size $n^{\frac{3}{2}}$. However, this is easy to solve if you notice that only the previous layer is used for transitions in dp, i.e. it is enough to store $dp_s$ to calculate $dp_{s+1}$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> dp(n + 1), ans(n + 1);
  dp[0] = 1;
  for (int mn = 0; mn + k <= n; mn += k++) {
    vector<int> sum(k);
    for (int i = mn; i <= n; ++i) {
      int cur = dp[i];
      dp[i] = sum[i % k];
      (sum[i % k] += cur) %= MOD;
      (ans[i] += dp[i]) %= MOD;
    }
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}
```
[1716E - Swap and Maximum Block](../problems/E._Swap_and_Maximum_Block.md "Educational Codeforces Round 133 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1716E - Swap and Maximum Block](../problems/E._Swap_and_Maximum_Block.md "Educational Codeforces Round 133 (Rated for Div. 2)")

Let's carefully analyze the operation denoted in the query. Since the length of the array is always divisible by $2^{k+1}$, every element will be swapped with some other element. The elements can be split into two groups — the ones whose positions increase by $2^k$, and the ones whose positions decrease by $2^k$.

Let's find some trait of the elements which will allow us to distinguish the elements of one group from the elements of the other group. The first $2^k$ elements will be shifted to the right, the next $2^k$ elements will be shifted to the left, the next $2^k$ elements will be shifted to the right, etc. If we look at the binary representations of integers $0, 1, \dots, n-1$, then we can see that the first $2^k$ elements have $0$ in the $k$-th bit, the next $2^k$ elements have $1$ in the $k$-th bit, the next $2^k$ elements have $0$ in the $k$-th bit, and so on. So, if we consider the positions of elements as $0$-indexed, then the operation can be described as follows: "Let the position of the element be $i$. If the $k$-th bit in $i$ is $0$, $i$ gets increased by $2^k$, otherwise $i$ gets decreased by $2^k$". What does it look like? Actually, it is just $i \oplus 2^k$ (where $\oplus$ denotes XOR).

So, each query can be represented as "swap $a_i$ with $a_{i \oplus x}$ for some integer $x$". The combination of two queries can also be represented with a single query; in fact, the state of the array can be denoted as the XOR of all $2^k$ from the previous queries.

Now, let's try to solve the following problem: for every $x \in [0, 2^n-1]$, calculate the maximum sum of subsegment if every element $a_i$ is swapped with $a_{i \oplus x}$. To solve this problem, we can use a segment tree.

First of all, we need to understand how to solve the problem of finding the maximum sum on subsegment using a segment tree. To do this, we should store the following four values in each vertex of the segment tree:

* $\mathit{sum}$ — the sum of elements on the segment denoted by the vertex;
* $\mathit{pref}$ — the maximum sum of elements on the prefix of the segment denoted by the vertex;
* $\mathit{suff}$ — the maximum sum of elements on the suffix of the segment denoted by the vertex;
* $\mathit{ans}$ — the answer on the segment.

If some vertex of the segment tree has two children, these values for it can be easily calculated using the values from the children. So, we can "glue" two segments represented by the vertices together, creating a new vertex representing the concatenation of these segments.

Okay, but how do we apply XOR to this? For every vertex of the segment tree, let's create several versions; the $x$-th version of the vertex $v$ represents the segment corresponding to this vertex if we apply swapping query with $x$ to it. For a vertex $v$ representing the segment of length $2^k$, we can use the following relation to get all its versions (here, we denote $t(v, x)$ as the $x$-th version of $v$, and $v_l$ and $v_r$ as the children of $v$):

* if $x \ge 2^{k-1}$, then $t(v, x) = \mathit{combine}(t(v_r, x-2^{k-1}), t(v_l, x-2^{k-1}))$;
* else $t(v, x) = \mathit{combine}(t(v_l, x), t(v_r, x))$;

The function $\mathit{combine}$ here denotes the "glueing together" of two vertices we described above.

Now let's try to analyze how many versions of each vertex we need. For the root, we will need all $2^n$ versions. For its children, we need only $2^{n-1}$ versions. For the children of the children of the root, we need only $2^{n-2}$ versions, and so on; so, overall, the total number of versions is only $O(n 2^n)$, and each version can be constructed in $O(1)$, so the solution works in $O(n 2^n)$.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;     
const int K = 18;

struct node
{
    long long sum, pref, suff, ans;
    
    node(const node& l, const node& r)
    {                                                                                          
        sum = l.sum + r.sum;
        pref = max(l.pref, l.sum + r.pref);
        suff = max(r.suff, r.sum + l.suff);
        ans = max(max(l.ans, r.ans), l.suff + r.pref);
    }

    node(int x)
    {
        sum = x;
        pref = suff = ans = max(x, 0);
    }

    node() {};
};

int a[1 << K];
vector<node> tree[2 << K];  

void build(int v, int l, int r)
{
    tree[v].resize(r - l);
    if(l == r - 1)
    {
        tree[v][0] = node(a[l]);  
    }
    else
    {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        for(int i = 0; i < m - l; i++)
        {
            tree[v][i] = node(tree[v * 2 + 1][i], tree[v * 2 + 2][i]);
            tree[v][i + (m - l)] = node(tree[v * 2 + 2][i], tree[v * 2 + 1][i]);    
        }
    }
}

int main()
{            
    int n;
    scanf("%d", &n);
    int m = (1 << n);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    build(0, 0, m);
    int q;
    scanf("%d", &q);
    int cur = 0;
    for(int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        cur ^= (1 << x);
        printf("%lldn", tree[0][cur].ans);
    }
}
```
[1716F - Bags with Balls](../problems/F._Bags_with_Balls.md "Educational Codeforces Round 133 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1716F - Bags with Balls](../problems/F._Bags_with_Balls.md "Educational Codeforces Round 133 (Rated for Div. 2)")

The main idea of this problem is to use a technique similar to "contribution to the sum". We will model the value of $F^k$ as the number of tuples $(i_1, i_2, \dots, i_k)$, where each element is an index of a bag from which we have taken an odd ball. Let $G(t)$ be the number of ways to take balls from bags so that all elements from tuple $t$ are indices of bags with odd balls; then, the answer to the problem can be calculated as the sum of $G(t)$ over all possible tuples $t$.

First of all, let's obtain a solution in $O(k^2)$ per test case. We need to answer the following questions while designing a solution to the problem:

* How do we calculate $G(t)$ for a given tuple?
* How do we group tuples and iterate through them?

The first question is not that difficult. Every element from the tuple $(i_1, i_2, \dots, i_k)$ should be an index of a bag from which we have taken an odd ball; so, for every bag appearing in the tuple, we can take only a ball with odd number; but for every bag not appearing in the tuple, we can choose any ball. So, if the number of distinct elements in a tuple is $d$, then $G(t)$ for the tuple can be calculated as $\lceil \frac{m}{2}\rceil^d \cdot m^{n-d}$.

This actually gives as a hint for the answer to the second question: since $G(t)$ depends on the number of distinct elements in the tuple, let's try to group the tuples according to the number of distinct elements in them. So, the answer will be calculated as $\sum\limits_{i=1}^{k} H(i) \lceil \frac{m}{2}\rceil^i \cdot m^{n-i}$, where $H(i)$ is the number of tuples with exactly $i$ different elements.

How do we calculate $H(i)$? First of all, if $i > n$, then $H(i)$ is obviously $0$. Otherwise, we can use the following recurrence: let $dp_{i,j}$ be the number of tuples of $i$ elements with $j$ distinct ones; then:

* if $i = 1$ and $j = 1$, $dp_{i,j} = n$ (for a tuple with one element, there are $n$ ways to choose it);
* if $i = 1$ and $j \ne 1$, $dp_{i,j} = 0$;
* if $i > 1$ and $j = 1$, $dp_{i,j} = dp_{i-1,j}$ (there is only one distinct element, and it was already chosen);
* if $i > 1$ and $j > 1$, $dp_{i,j} = dp_{i-1,j} \cdot j + dp_{i-1,j-1} \cdot (n-j+1)$ (we either add an element which did not belong to the tuple, and there are $n-j+1$ ways to choose it, or we add an already existing element, and there are $j$ ways to choose it).

Obviously, this recurrence can be calculated in $O(k^2)$ with dynamic programming, so we get a solution in $O(k^2)$ per test case.

How do we speed this up? Let's change the way we calculate $H(i)$. Instead of considering tuples with values from $1$ to $n$, we will consider only tuples where values are from $1$ to $k$, and the first appearance of a value $i$ is only after the first appearance of the value $i-1$. So, these tuples actually represent a way to split a set of integers $\{1, 2, \dots, n\}$ into several subsets; so they are the Stirling numbers of the second kind, and we can calculate them in $O(k^2)$ with dynamic programming outside of processing the test cases.

How do we calculate $H(i)$ using these values? If we use $i$ distinct integers as the elements of the tuple, there are $n$ ways to choose the first one, $n-1$ ways to choose the second one, etc. — so $H(i) = S(k,i) \cdot \prod \limits_{j=0}^{i-1} (n-j)$, where $S(k, i)$ is the Stirling number of the second kind for the parameters $k$ and $i$. We can maintain the values of $\prod \limits_{j=0}^{i-1} (n-j)$ and $\lceil \frac{m}{2}\rceil^i \cdot m^{n-i}$ while iterating on $i$ from $1$ to $k$, and that gives us a way to solve the problem in $O(k)$ per test case.

Overall complexity: $O(k^2)$ for precalculation and $O(k)$ per test case.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;   
const int N = 2043;

int dp[N][N];

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}   

int sub(int x, int y)
{
    return add(x, -y);
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
        if(y % 2 == 1) z = mul(z, x);
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
    dp[1][1] = 1;
    for(int i = 1; i < N - 1; i++)
        for(int j = 1; j <= i; j++)
        {
            dp[i + 1][j] = add(dp[i + 1][j], mul(dp[i][j], j));
            dp[i + 1][j + 1] = add(dp[i + 1][j + 1], dp[i][j]);
        }
}

int solve(int n, int m, int k)
{
    int way1 = (m / 2) + (m % 2);
    int curA = n;
    int ans = 0;
    int ways_chosen = way1;
    int ways_other = binpow(m, n - 1);
    int invm = inv(m);
    for(int i = 1; i <= k; i++)
    {
        ans = add(ans, mul(mul(curA, dp[k][i]), mul(ways_chosen, ways_other)));
        curA = mul(curA, sub(n, i));
        ways_chosen = mul(way1, ways_chosen);
        ways_other = mul(ways_other, invm);
    }  
    return ans;
}   

int main()
{
    int t;
    cin >> t;
    precalc();
    for(int i = 0; i < t; i++)
    {
        int n, m, k;
        cin >> n >> m >> k;
        cout << solve(n, m, k) << endl;
    }
}
```
