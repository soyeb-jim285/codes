# Tutorial

[1499A - Domino on Windowsill](../problems/A._Domino_on_Windowsill.md "Educational Codeforces Round 106 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1499A - Domino on Windowsill](../problems/A._Domino_on_Windowsill.md "Educational Codeforces Round 106 (Rated for Div. 2)")

We can prove that if we have k1+k2 white cells on the board then we can place any w white dominoes as long as 2w≤k1+k2.

The proof is the following: if k1≥k2 let's place one domino at position ((1,k1−1),(1,k1)), otherwise let's place domino at position ((2,k2−1),(2,k2)). Then we can solve the placement of w−1 dominoes in k1−2 cells in the first row and k2 cells of the second row recursively (or, analogically, k1 and k2−2).

At the end, either all dominoes are placed or k1<2 and k2<2. If k1=0 or k2=0 then, since 2w≤k1+k2, then w=0 or we successfully placed all dominoes. If k1=1 and k2=1 then we, possibly, need to place one domino more — and we can place it vertically.

We can prove that we can place any b dominoes as long as 2b≤(n−k1)+(n−k2) in the same manner.

As a result, all we need to check is that 2w≤k1+k2 and 2b≤(n−k1)+(n−k2).

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k1, k2) = readLine()!!.split(' ').map { it.toInt() }
        val (w, b) = readLine()!!.split(' ').map { it.toInt() }

        if (k1 + k2 >= 2 * w && (n - k1) + (n - k2) >= 2 * b)
            println("YES")
        else
            println("NO")
    }
}
```
[1499B - Binary Removals](../problems/B._Binary_Removals.md "Educational Codeforces Round 106 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1499B - Binary Removals](../problems/B._Binary_Removals.md "Educational Codeforces Round 106 (Rated for Div. 2)")

There are several different ways to solve this problem. In my opinion, the two easiest solutions are:

* notice that, in the sorted string, there is a prefix of zeroes and a suffix of ones. It means that we can iterate on the prefix (from which we remove all ones), and remove all zeroes from the suffix we obtain. If we try to remove two adjacent characters, then we cannot use this prefix;
* if there is a substring 11 before the substring 00 in our string, then from both of the substrings, at least one character remains, so if the first occurrence of 11 is earlier than the last occurrence of 00, there is no answer. Otherwise, the answer always exists.
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
    int i = s.find("11");
    int j = s.rfind("00");
    cout << (i != -1 && j != -1 && i < j ? "NO" : "YES") << endl;
  }
}
```
[1499C - Minimum Grid Path](../problems/C._Minimum_Grid_Path.md "Educational Codeforces Round 106 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1499C - Minimum Grid Path](../problems/C._Minimum_Grid_Path.md "Educational Codeforces Round 106 (Rated for Div. 2)")

Suppose we decided to make exactly k−1 turns or, in other words, our path will consist of exactly k segments. Since we should finish at point (n,n) and vertical and horizontal segments alternates, then it means that length1+length3+length5+⋯=n and legth2+length4+length6+⋯=n.

From the other side we should minimize k∑i=1ci⋅lengthi. But it means that we can minimize c1⋅length1+c3⋅length3+… and c2⋅length2+c4⋅length4+… independently.

How to minimize c1⋅length1+c3⋅length3+… if we know that length1+length3+length5+⋯=n and lengthi≥1? It's easy to prove that it's optimal to assign all lengthi=1 except minimum ci and assign to this minimum ci the remaining part lengthi=n−cntOdds+1.

In other words, to calculate the optimal path consisting of k segments, we need to know the sum of ci on odd and even positions among c1,…,ck and also minimum ci among odd and even positions. Then we can drive out the answer as a quite easy formula sumOdd+minOdd⋅(n−cntOdd) + sumEven+minEven⋅(n−cntEven).

Finally, we should iterate over all k from 2 to n and find the minimum answer among all variants. It's easy to recalculate sums and minimums when we make transition form k to k+1.

Complexity is O(n).

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val c = readLine()!!.split(' ').map { it.toInt() }

        val mn = intArrayOf(1e9.toInt(), 1e9.toInt())
        val rem = longArrayOf(n.toLong(), n.toLong())
        var sum = 0L
        var ans = 1e18.toLong()
        for (i in c.indices) {
            mn[i % 2] = minOf(mn[i % 2], c[i])
            rem[i % 2]--
            sum += c[i]
            if (i > 0) {
                val cur = sum + rem[0] * mn[0] + rem[1] * mn[1]
                ans = minOf(ans, cur)
            }
        }
        println(ans)
    }
}
```
[1499D - The Number of Pairs](../problems/D._The_Number_of_Pairs.md "Educational Codeforces Round 106 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1499D - The Number of Pairs](../problems/D._The_Number_of_Pairs.md "Educational Codeforces Round 106 (Rated for Div. 2)")

Let's represent a as Ag and b as Bg, where g=gcd(a,b) and gcd(A,B)=1. By definition lcm(a,b)=abg, so we can represent lcm(a,b) as Ag⋅Bgg=ABg. 

Now we can rewrite the equation from the statement as follows: c⋅ABg−d⋅g=x⟹g(c⋅AB−d)=x. Since the left-hand side is divisible by g, the right-hand side should also be divisible. So we can iterate over g as divisors of x. If the right-hand side of c⋅AB=xg+d is not divisible by c then we can skip such g. AB=xg+dc (let's denote as k). If k has some prime divisor p then exactly one of A and B should be divisible by p because gcd(A,B)=1 (A and B have no common divisors). So there are 2the number of prime divisors of k pairs of A and B for current value of g.

We can precalculate the minimum prime divisor for each number up to 2⋅107 (the maximum value of k that you may need) in O(2⋅107loglog(2⋅107)) using Eratosthenes sieve. Now we can solve the problem in O(√xlogx) for each testcase, but that's not fast enough. To speed up this approach, we can precalculate the number of prime divisors for each number up to 2⋅107. Let's denote mindi as the minimum prime divisor of i and vali as the number of prime divisors of i. Then vali=vali/mindi plus 1 if mindi≠mindi/mindi. Now, to solve the problem, we only need to iterate over the divisors of x, so the time complexity is O(√x) per testcase.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 2e7 + 13;

int main() {
  vector<int> mind(N, -1), val(N);
  mind[1] = 1;
  for (int i = 2; i < N; ++i) if (mind[i] == -1)
    for (int j = i; j < N; j += i) if (mind[j] == -1)
      mind[j] = i;
  for (int i = 2; i < N; ++i) {
    int j = i / mind[i];
    val[i] = val[j] + (mind[i] != mind[j]);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int c, d, x;
    scanf("%d%d%d", &c, &d, &x);
    int ans = 0;
    for (int i = 1; i * i <= x; ++i) {
      if (x % i != 0) continue;
      int k1 = x / i + d; 
      if (k1 % c == 0) ans += 1 << val[k1 / c];
      if (i * i == x) continue;
      int k2 = i + d;
      if (k2 % c == 0) ans += 1 << val[k2 / c]; 
    }
    printf("%dn", ans);
  }
}
```
[1499E - Chaotic Merge](../problems/E._Chaotic_Merge.md "Educational Codeforces Round 106 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1499E - Chaotic Merge](../problems/E._Chaotic_Merge.md "Educational Codeforces Round 106 (Rated for Div. 2)")

First, let's try to calculate the number of merging sequences just for some fixed pair of strings x and y.

Imagine we build a merge letter by letter. So far i letters are in the merge already. For the (i+1)-th letter we can pick a letter from either string x or string y (put a 0 or a 1 into the merging sequence, respectively). What constraints our choice? Easy to see that it's only the i-th letter of the merge. So we can come up with the following dynamic programming.

dp[i][j][c] is the number of merging sequences such that i characters from x are taken, j characters from y are taken and the last character of the merge is c. c can be either just a letter (a dimension of size 26) or an indicator of a string the last character was taken from (0 for string x and y from string y). Since we know how many characters are taken from each string, we can easily decide the last taken character from that indicator. For each transition we can just take a character from either of the strings.

The sum of dp[|x|][|y|][i] over all i will be the total number of merging sequences.

Now for the substrings. Recall the following definition of a substring: b is a substring of a if you can remove some characters from the beginning of a (possibly, none or all) and some characters from the end of a (possibly, none or all) to get the string b.

What if we incorporated that definition into our dynamic programming? Let dp[i][j][c] be the number of merging sequences that end exactly before the i-th character of x, exactly before the j-th character of y and the last character is still c.

How to remove some characters from the beginning? That actually is the same as attempting to start the merge from every state of dp. So, if we are currently in some state dp[i][j][c], then we can act as if we have just taken the i-th character of x or the j-th character of y as the first character of the merge.

How to remove some characters from the end? Since dp[i][j][c] is the number of merging sequences that end exactly there, why not just sum up all the values of dynamic programming into the answer? We will count the sequences that end in all possible positions of both strings.

That is almost the answer to the task. The only issue we have is that we forgot the condition that asks us to get a non-empty substring from each string. Well, there are multiple ways to resolve the issue.

We can remove bad sequences afterwards: their count is the number of chaotic substrings of x multiplied by all possible empty substrings of y (there are |y|+1 of them) plus the same thing for y and x. These can be counted with two pointers. 

Alternatively, we can add an extra dimension or two to the dp to indicate if we have ever taken a character from x and from y. So we get dp[i][j][c][flx][fly] with flx and fly being binary flags that tell if a character from x and from y was ever taken. That way we can only push the states with both flags set to true to the answer.

Overall complexity: O(|x|⋅|y|).

 **Solution 1 (awoo)**
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

int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(2, 0)));
	int ans = 0;
	forn(i, n + 1) forn(j, m + 1){
		if (i < n) dp[i + 1][j][0] = add(dp[i + 1][j][0], 1);
		if (j < m) dp[i][j + 1][1] = add(dp[i][j + 1][1], 1);
		if (0 < i && i < n && s[i - 1] != s[i]) dp[i + 1][j][0] = add(dp[i + 1][j][0], dp[i][j][0]);
		if (0 < j && i < n && t[j - 1] != s[i]) dp[i + 1][j][0] = add(dp[i + 1][j][0], dp[i][j][1]);
		if (0 < i && j < m && s[i - 1] != t[j]) dp[i][j + 1][1] = add(dp[i][j + 1][1], dp[i][j][0]);
		if (0 < j && j < m && t[j - 1] != t[j]) dp[i][j + 1][1] = add(dp[i][j + 1][1], dp[i][j][1]);
		ans = add(ans, dp[i][j][0]);
		ans = add(ans, dp[i][j][1]);
	}
	forn(i, n){
		int j = i;
		while (j + 1 < n && s[j] != s[j + 1]) ++j;
		int len = j - i + 1;
		int val = (len * 1ll * (len + 1) / 2) % MOD * (m + 1) % MOD;
		ans = add(ans, -val);
		i = j;
	}
	forn(i, m){
		int j = i;
		while (j + 1 < m && t[j] != t[j + 1]) ++j;
		int len = j - i + 1;
		int val = (len * 1ll * (len + 1) / 2) % MOD * (n + 1) % MOD;
		ans = add(ans, -val);
		i = j;
	}
	printf("%dn", ans);
	return 0;
}
```
 **Solution 2 (awoo)**
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

int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(m + 1, vector<vector<int>>(2, vector<int>(4, 0))));
	int ans = 0;
	forn(i, n + 1) forn(j, m + 1){
		if (i < n) dp[i + 1][j][0][1] = add(dp[i + 1][j][0][1], 1);
		if (j < m) dp[i][j + 1][1][2] = add(dp[i][j + 1][1][2], 1);
		forn(mask, 4){
			if (0 < i && i < n && s[i - 1] != s[i]) dp[i + 1][j][0][mask | 1] = add(dp[i + 1][j][0][mask | 1], dp[i][j][0][mask]);
			if (0 < j && i < n && t[j - 1] != s[i]) dp[i + 1][j][0][mask | 1] = add(dp[i + 1][j][0][mask | 1], dp[i][j][1][mask]);
			if (0 < i && j < m && s[i - 1] != t[j]) dp[i][j + 1][1][mask | 2] = add(dp[i][j + 1][1][mask | 2], dp[i][j][0][mask]);
			if (0 < j && j < m && t[j - 1] != t[j]) dp[i][j + 1][1][mask | 2] = add(dp[i][j + 1][1][mask | 2], dp[i][j][1][mask]);
		}
		ans = add(ans, dp[i][j][0][3]);
		ans = add(ans, dp[i][j][1][3]);
	}
	printf("%dn", ans);
	return 0;
}
```
[1499F - Diameter Cuts](../problems/F._Diameter_Cuts.md "Educational Codeforces Round 106 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1499F - Diameter Cuts](../problems/F._Diameter_Cuts.md "Educational Codeforces Round 106 (Rated for Div. 2)")

The task is obviously solved by dynamic programming, so our first reaction should be to start looking for meaningful states for it. Obviously, one of the states is the vertex which subtree we are processing. We can choose the root for the tree arbitrarily, let it be vertex 1. What can be the other helpful state?

Consider the method to find the diameter of the subtree of vertex v. The diameter can be one of the following paths: either the longest path that is completely in some subtree of v or the concatenation of the longest paths that start in vertex v and end in different subtrees.

The diameter is the longest path. Thus, the diameter being less than or equal to k means that all paths should have length less than or equal to k.

If we can guarantee that no path that is completely in some subtree of v have length greater than k, then we will only have to worry about not concatenating long paths from different subtrees. Phrase it the other way around: if we never concatenate the paths from the different subtrees in such a way that their total length is greater than k, then no diameter will be greater than k.

Thus, we can attempt to have dp[v][len] — the number of ways to cut some edges in the subtree of v in such a way that there is no path of length greater than k and the longest path starting at vertex v has length len.

Now for the transitions. For the simplicity, let vertex v have exactly two children. It's not too hard to merge their dp's. Iterate over the length i of the first child, the length j of the second child. If (i+1)+(j+1)≤k, then you can concatenate their longest paths and the longest path for v will be of length max(i,j)+1. You can also cut either of the edges from v to the first child or to the second child.

The approach is good, however, it's not clear how to make it work on a larger number of children. Also, the complexity sounds pretty bad.

Instead of merging children to each other, let's merge each child to the dp of v one by one. dp[v][len] can store the current maximum length over all processed children. When processing a new child, you can choose to cut or not to cut the edge to it. So you can iterate over the current longest path from v and the longest path from that child.

So far, the only way to estimate the complexity is to say that each child has to merge its dp to the parent in O(k2), thus making the algorithm O(nk2). That's obviously too slow.

The trick that makes the solution fast is to iterate not to k but to the height of the subtree of v and the subtree of a child. Surely, that is allowed, since the path just can't grow longer than that value.

Consider the even worse option: not the height but the size of the subtree. It's easy to see that the size is always greater or equal than the height. Interpret the merge the following way: enumerate the vertices inside all the subtrees of the processed children and the vertices inside the subtree of the new child. Iterating up to the size of the subtree is the same number of moves as going over the vertices in it. The merge will go over all the pairs of vertices such that the first vertex of the pair is in the first set and the second vertex is in the second set. Thus, each pair of vertices of the tree will be processed exactly once (in lca of these vertices). There are O(n2) such pairs, thus, such dp's work in O(n2).

Overall complexity: O(n2).

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

int k;
vector<vector<int>> g;
vector<vector<int>> dp;

int dfs(int v, int p = -1){
	dp[v][0] = 1;
	int h = 0;
	for (int u : g[v]) if (u != p){
		int nh = dfs(u, v);
		vector<int> tmp(max(h, nh + 1) + 1);
		forn(i, h + 1) forn(j, nh + 1){
			if (i + j + 1 <= k)
				tmp[max(i, j + 1)] = add(tmp[max(i, j + 1)], mul(dp[v][i], dp[u][j]));
			if (i <= k && j <= k)
				tmp[i] = add(tmp[i], mul(dp[v][i], dp[u][j]));
		}
		h = max(h, nh + 1);
		forn(i, h + 1){
			dp[v][i] = tmp[i];
		}
	}
	return h;
}

int main() {
	int n;
	scanf("%d%d", &n, &k);
	g.resize(n);
	dp.resize(n, vector<int>(n, 0));
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0);
	int ans = 0;
	forn(i, k + 1) ans = add(ans, dp[0][i]);
	printf("%dn", ans);
	return 0;
}
```
[1499G - Graph Coloring](../problems/G._Graph_Coloring.md "Educational Codeforces Round 106 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1499G - Graph Coloring](../problems/G._Graph_Coloring.md "Educational Codeforces Round 106 (Rated for Div. 2)")

Let's split all edges of the graph into several paths and cycles (each edge will belong to exactly one path or cycle). Each path and each cycle will be colored in an alternating way: the first edge will be red, the second — blue, the third — red, and so on (or vice versa). Since the graph is bipartite, each cycle can be colored in an alternating way. The main idea of the solution is to add the edges one by one, maintain the structure of cycles and paths, and make sure that for each vertex, at most one path starts/ends in it. If we are able to maintain this invariant, then the value of |r(v)−b(v)| for every vertex will be minimum possible — each cycle going through a vertex covers an even number of edges incident to it (half of them will be red, half of them will be blue); so, if the degree of a vertex is odd, one path will have this vertex as an endpoint, and |r(v)−b(v)|=1; otherwise, it won't be an endpoint of any path, so |r(v)−b(v)|=0.

Okay, how do we maintain this structure? Let's add edges one by one (even the original edges of the graph) and rebuild the structure in online mode. For each vertex, we will maintain the indices of the paths that have this vertex as an endpoint. If some vertex has 2 or more paths as its endpoints, we can choose two of them and link them together. Whenever we add an edge from x to y, we just create a new path and check if we can link together some paths that have x or y as their endpoints.

How do we link the paths together? If we try to link a path with itself, it means that we try to close a cycle — and when we do it, we just forget about the resulting cycle, its structure won't change in future queries. When we link a path with some other path, we might need to reverse and/or repaint the paths before merging them into one. There are (at least) two possible data structures we can use to do this:

* either an implicit-key treap that supports reversing and repainting;
* or a deque with small-to-large merging: whenever we try to link two paths together, we repaint and/or reverse the smaller one.

Both of those methods give a solution in O((m+q)log(m+q)) or O((m+q)log2(m+q)), depending on your implementation. The model solution uses deques and small-to-large merging.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 1000043;

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
        if(y % 2 == 1)
            z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int global_hash = 0;

void reverse(deque<pair<int, int>>& d)
{
    stack<pair<int, int>> s;
    while(!d.empty())
    {
        s.push(d.back());
        d.pop_back();
    }
    while(!s.empty())
    {
        d.push_front(s.top());
        s.pop();
    }
}

void safe_push_front(deque<pair<int, int>>& d, int c, int& res)
{
    int z = d.front().first ^ 1;
    res = add(res, mul(binpow(2, c), z));
    d.push_front(make_pair(z, c));
}

void safe_push_back(deque<pair<int, int>>& d, int c, int& res)
{
    int z = d.back().first ^ 1;
    res = add(res, mul(binpow(2, c), z));
    d.push_back(make_pair(z, c));
}

deque<pair<int, int>> ds[N];

struct path
{
    int s;
    int t;
    int d;
    int c;

    path() {};
    path(int s, int t, int d, int c) : s(s), t(t), d(d), c(c) {};

    void push_front(int i)
    {
        safe_push_front(ds[d], i, c);
    }

    void push_back(int i)
    {
        safe_push_back(ds[d], i, c);
    }

    void pop_front()
    {
        ds[d].pop_front();
    }

    void pop_back()
    {
        ds[d].pop_back();
    }

    int front()
    {
        return ds[d].front().second;
    }

    int back()
    {
        return ds[d].back().second;
    }

    void reverse()
    {
        ::reverse(ds[d]);
        swap(s, t);
    }

    int size()
    {
        return ds[d].size();
    }
};

path link_to_left(path x, path y)
{
    path z = x;
    while(y.size() > 0)
    {
        z.push_back(y.front());
        y.pop_front();
    }
    z.t = y.t;
    return z;
}

path link_to_right(path x, path y)
{
    path z = y;
    while(x.size() > 0)
    {
        z.push_front(x.back());
        x.pop_back();
    }
    z.s = x.s;
    return z;
}

int cur = 0;

path make(int x, int y, int i)
{
    int cost = i;
    ds[cur].push_back(make_pair(0, cost));
    return path(x, y, cur++, 0);    
}

set<int> paths;
vector<int> paths_v[N];
path ps[N];

path merge(path x, path y, int v)
{
    if(x.size() > y.size())
        swap(x, y);
    if(y.s == v)
    {
        if(x.t != v)
            x.reverse();
        return link_to_right(x, y);    
    }
    else
    {
        if(x.s != v)
            x.reverse();
        return link_to_left(y, x);
    }    
}

int cur2 = 0;       

void modify(vector<int>& v, int x, int y)
{
    for(int i = 0; i < v.size(); i++)
        if(v[i] == x)
            v[i] = y;
}   

void reassign(path p, int x, int y)
{
    modify(paths_v[p.s], x, y);
    modify(paths_v[p.t], x, y);    
}

void merge_paths(int x, int y, int v)
{
    if(x == y)
    {                         

    }
    else
    {
        global_hash = sub(global_hash, ps[x].c);
        global_hash = sub(global_hash, ps[y].c);
        ps[cur2++] = merge(ps[x], ps[y], v);
        paths.erase(x);
        paths.erase(y);
        paths.insert(cur2 - 1);
        reassign(ps[x], x, cur2 - 1);
        reassign(ps[y], y, cur2 - 1);
        global_hash = add(global_hash, ps[cur2 - 1].c);   
    }
}

void relax(int v)
{
    while(paths_v[v].size() >= 2)
    {
        int x = paths_v[v].back();
        paths_v[v].pop_back();
        int y = paths_v[v].back();
        paths_v[v].pop_back();
        merge_paths(x, y, v);
    }
}

void add_edge(int x, int y, int i)
{
    //cerr << x << " " << y << " " << i << endl;
    int c = cur2;
    ps[cur2++] = make(x, y, i);
    paths_v[x].push_back(c);
    paths_v[y].push_back(c);
    paths.insert(c);
    relax(x);
    relax(y);
}

void print_coloring()
{
    vector<int> ans;
    for(auto x : paths)
    {
        for(auto y : ds[ps[x].d])
        {
            if(y.first == 1)
                ans.push_back(y.second);
        }
    }
    printf("%d", int(ans.size()));
    for(auto x : ans)
        printf(" %d", x);
    puts("");
    fflush(stdout);
}

int e = 0;

void process_query()
{
    int t;
    scanf("%d", &t);
    if(t == 1)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        y += 200001;
        add_edge(x, y, ++e);
        printf("%dn", global_hash);
        fflush(stdout);
    }
    else
        print_coloring();
}

void print_info()
{
    cerr << "Pathsn";
    for(auto x : paths)
        cerr << x << " start: " << ps[x].s << " " << " end: " << ps[x].t << endl;
    cerr << "Verticesn";
    for(int i = 0; i < N; i++)
        if(!paths_v[i].empty())
        {
            cerr << i << ": ";
            for(auto x : paths_v[i])
                cerr << x << " ";
            cerr << endl;
        }

}
        
int main()
{
    int n1, n2, m;
    scanf("%d %d %d", &n1, &n2, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        y += 200001;
        add_edge(x, y, ++e);
    }
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        //print_info();
        process_query();
    }
}
```
