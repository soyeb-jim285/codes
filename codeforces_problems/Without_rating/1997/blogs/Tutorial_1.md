# Tutorial_1

[1997A - Strong Password](../problems/A._Strong_Password.md "Educational Codeforces Round 168 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1997A - Strong Password](../problems/A._Strong_Password.md "Educational Codeforces Round 168 (Rated for Div. 2)")

The time it takes to type a string can actually be calculated as follows: $2 \cdot |s| - p$, where $|s|$ is the number of characters in the string, and $p$ is the number of pairs of adjacent equal characters (usually a character takes $2$ seconds to type, but the right character in every pair of adjacent equal characters takes only $1$, so each pair reduces the total time by $1$). Since we always add a new character, $|s|$ will increase by $1$ no matter what; so we need to minimize $p$.

Now there are two cases:

* if there is a pair of adjacent equal characters in the string, we can decrease $p$ by $1$ by "breaking" it as follows: choose any character different from the characters in that pair, and insert it between them. It's easy to see that we can "break" at most one such pair, so we can't do better;
* otherwise, $p$ is already $0$, so we just need to keep it equal to $0$. For example, we can choose any character not equal to the last character in the string, and append it to the right of it.

There are other solutions as well, like iterating on all possible characters and all possible insertion positions.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	int idx = -1;
	for(int i = 0; i + 1 < n; i++)
		if(s[i] == s[i + 1])
			idx = i;
	if(idx == -1)
	{
		if(s.back() == 'a') cout << (s + "b") << endl;
		else cout << (s + "a") << endl;
	}
	else
	{
		string t = "a";
		if(s[idx] == 'a') t = "b";
		cout << s.substr(0, idx + 1) + t + s.substr(idx + 1) << endl;
	}
}
 
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
		solve();
}
```
[1997B - Make Three Regions](../problems/B._Make_Three_Regions.md "Educational Codeforces Round 168 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1997B - Make Three Regions](../problems/B._Make_Three_Regions.md "Educational Codeforces Round 168 (Rated for Div. 2)")

Since the chosen cell should split a connected region into $3$ non-empty parts, this cell should share a side with all $3$ of them. But any cell has at most $3$ neighbor cells (because there are only $2$ rows), and they should be split from each other by blocked cells.

From the above, we can conclude how a pattern of a "good" cell should look like. In fact, there are only $2$ of them (on the layouts below, white cells are free, dark grey cells are blocked, and the red cell is a "good" cell):

 

|  |  |
| --- | --- |

 These patterns are the only possible ones: all $3$ neighbors of a "good" cell should be free (otherwise there will be less than $3$ regions connected to it); and both of the "corner" cells should be blocked (if at least one of them is free, two regions will merge into one, so there will be less than $3$ regions). 

So the problem becomes to calculate the number of the above patterns inside the given grid.

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
    vector<string> s(2);
    for (auto& x : s) cin >> x;
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
      bool ok = true;
      ok &= (s[0][i] == '.' && s[1][i] == '.');
      ok &= (s[0][i - 1] != s[1][i - 1]);
      ok &= (s[0][i + 1] != s[1][i + 1]);
      ok &= (s[0][i - 1] == s[0][i + 1]);
      ans += ok;
    }
    cout << ans << 'n';
  }
}
```
[1997C - Even Positions](../problems/C._Even_Positions.md "Educational Codeforces Round 168 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1997C - Even Positions](../problems/C._Even_Positions.md "Educational Codeforces Round 168 (Rated for Div. 2)")

Let's define a balance of a bracket sequence as the $\texttt{number_of_opening_brackets} - \texttt{number_of_closing_brackets}$.

It's a well-known fact that for RBS the balance of all its prefixes must be greater than or equal to zero and the balance of the whole string must be exactly zero. So, if we want to restore RBS from $s$ we shouldn't break that rule.

Next, let's define $S_{o}$ as the sum of positions of the opening brackets in RBS and $S_{c}$ as the sum of positions of the closing brackets in RBS.

It turns out that the cost defined in the statement is just $S_c - S_o$. Moreover, you can see that $S_c - S_o = 2 S_c - \frac{n (n + 1)}{2}$. It means that in order to minimize the cost, we should minimize $S_c$, or we should try to place closing brackets on the smaller positions.

The most interesting part is that it's enough to come up with the right strategy. Let's iterate from left to right, maintaining the current balance and place the closing brackets whenever we can: 

* if the current balance is $0$ we can't place a closing bracket, since it will make the balance negative, so we place an opening bracket;
* if the current balance is bigger than $0$ we place a closing bracket.

Since we need to calculate the cost of the RBS, we can replace the balance counter with a stack containing positions of opening brackets that don't have a pair yet. Each time we meet an opening bracket, we'll push its position to the top of the stack, and each time we meet a closing bracket, we'll take one bracket from the top of the stack. The current balance is just the size of the stack.

Here is a sketch of the proof, why the strategy above is correct.

Firstly, the strategy creates RBS, because after processing a prefix of even length the current balance will be equal to either $0$ or $2$, while after an odd length prefix it will be always $1$. At the start, the balance is $0$ and we make it $1$, then it either becomes $0$ or $2$, and in both cases we return it to $1$ and so on. Since the last character is always a closing bracket, the total balance will return to $0$.

Secondly, to prove that the strategy minimizes the cost, we can use a standard technique of proof by contradiction: suppose there is a better answer, look at the first position of the difference: it will be ) in our string and ( in the answer. Then just find the next ) in the answer and swap them. The answer will stay RBS, while $S_c$ will decrease — contradiction.

 **Solution (adedalic)**
```cpp
import java.util.LinkedList
 
fun main() {
    repeat(readln().toInt()) {
        val n = readln().toInt()
        val s = readln()
 
        var ans = 0L
        val bracketPositions = LinkedList<Int>()
        for (i in s.indices) {
            var c = s[i]
            if (c == '_') {
                c = if (bracketPositions.isEmpty()) '(' else ')'
            }
            if (c == ')') {
                ans += i - bracketPositions.pollLast()
            }
            else
                bracketPositions.addLast(i)
        }
        println(ans)
    }
}
```
[1997D - Maximize the Root](../problems/D._Maximize_the_Root.md "Educational Codeforces Round 168 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1997D - Maximize the Root](../problems/D._Maximize_the_Root.md "Educational Codeforces Round 168 (Rated for Div. 2)")

We can clearly say that if some value $k$ can be obtained at the root, then any value from $a_1$ to $k$ can also be obtained. Using that fact, we can use binary search to solve the problem.

Let's fix some value $\mathit{mid}$ in binary search and check if it is possible to apply an operation from the statement $\mathit{mid}$ times to the root. Let's write the following recursive function: $\mathit{check}(v, x)$ — the function that checks whether it is possible to obtain at least $x$ at all vertices from the subtree of $v$ (including $v$ itself) simultaneously (i. e. we had to make $x$ operations above the current vertex, can the subtree of $v$ "support" them?).

Let the current state be $(v, x)$, then there are three cases of transitions: 

* $v$ is a leaf, then $x \le a_v$ should hold;
* $v$ is not a leaf and $x \le a_v$, then the vertex $v$ is ok, and we have to check its subtree (i. e. $\mathit{check}(u, x)$ should be true for all $u$ that are children of $v$).
* $v$ is not a leaf and $x > a_v$, then we have to apply the operation $(x - a_v)$ times to the vertex $v$, and that adds an additional constraint on the subtree of $v$; specifically, $\mathit{check}(u, x + (x - a_v))$ should be true for all $u$ that are children of $v$.

Be careful with overflows: $x$ might grow exponentially, so you should, for example, return from the function when $x$ becomes very large.

When we check a single value of $mid$, this recursive function is called once for each vertex in the tree, so the total time complexity of this solution is $O(n\log{A})$, where $A$ is an upper bound of the values of the array $a$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9;
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        g[p - 1].push_back(i);
    }
    
    auto check = [&](auto&& self, int v, int x) -> bool {
      if (x > INF) return false;
      bool isLeaf = true;
      if (v) x += max(0, x - a[v]);
      for (auto u : g[v]) {
        isLeaf = false;
        if (!self(self, u, x)) return false;
      }
      return (!isLeaf || x <= a[v]);
    };
    
    int l = 1, r = INF;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(check, 0, mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    
    cout << a[0] + l - 1 << 'n';
  }
}
```
[1997E - Level Up](../problems/E._Level_Up.md "Educational Codeforces Round 168 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1997E - Level Up](../problems/E._Level_Up.md "Educational Codeforces Round 168 (Rated for Div. 2)")

I would like to describe two different intended solutions to this problem.

Solution One.

Let's start with the following idea. How many times can the character's level increase for a fixed $k$? Given that there are $n$ monsters, even if we fight all of them, the level will not exceed $\frac{n}{k}$. That is, if we sum over all $k$, the level will change no more than $O(n \log n)$ times (harmonic series).

Let's simulate the process for each $k$ and find out when the level changed. Suppose the character's level became $x$ after fighting monster $i$. Then the level will become $x + 1$ after fighting the $k$-th monster with a level greater than or equal to $x$ after position $i$. That is, if we had an array of positions of monsters with a level greater than or equal to $x$, we could find the position of the level change from it. Unfortunately, it is not possible to keep all such arrays in memory.

Instead, let's try to use a more powerful data structure. Now, suppose we want to add or remove positions from the structure and be able to query the $k$-th position greater than $i$. Such structures exist. We can use a segment tree, a BIT, or an ordered_set from pbds.

How can we reduce the problem to using this structure? The idea is as follows. Previously, we had the idea to iterate over $k$ and inside that iterate over the current character level. Let's do the opposite. We will iterate over the character level on the outside. And inside, we will update the level for all such $k$ for which the character has not reached the end of the monsters yet.

It turns out that this will be a prefix of the $k$. Why is that? For each $x$, the character reaches level $x$ at some $k$ no later than at $k + 1$. Suppose this is not the case. Consider the first such $x$ where the character reached level $x$ at $k$ later than at $k + 1$. That is, he reached level $x - 1$ earlier or at the same time. This means that he will encounter at least all the same monsters at $k$ as at $k + 1$ (since the segment of monsters will start no later and end no earlier). Since at $k + 1$, the character must have encountered at least $k + 1$ monsters of level at least $x$, at $k$ he will definitely encounter at least $k$. Thus, this cannot happen.

Then the implementation is as follows. For each $k$, we will maintain the position at which the character reached the current level $x$. Then, for the prefix of $k$, for which this position is within the array, we will update it with the new position for level $k + 1$. For this, we will store the positions of all monsters of level at least $x$ in the data structure. After processing level $x$, we will remove all monsters of this level from the structure. To find the new position, we need to make such queries to the structure: either find the $k$-th position after the current saved one (in the segment tree or Fenwick tree), or find the first (using order_of_key) and move $k - 1$ positions from it (using find_by_order) (in ordered_set).

We can answer the queries within the simulation. For each $k$, we will store all queries related to it and sort them in ascending order of $i$. Since within each $k$ we move in the order of increasing level, and thus position, we can answer the queries in that order. While the position of the query is less than or equal to the position where the level will become $x + 1$, we answer the queries by checking that the monster's level at that position is not less than $x$.

Overall complexity: $O(n \log^2 n)$.

Solution Two.

Let's still simulate level increases directly.

We will use the square root heuristics. If $k$ is greater than or equal to some constant $B$, then the character will definitely fight all monsters of level at least $\frac{n}{B}$, simply because he cannot become greater than this level himself. That is, if we choose $B$ on the order of $1000$, for example, we only need to know whether the character is fighting a monster, only for monsters of level no higher than $200$.

We will solve the problem for all $k$ less than $1000$ in $O(n)$. That is, we will honestly go through the monsters, maintaining the character's level and a counter of fights until the level increases.

For larger $k$, we will solve the problem as follows. We will sum the indices of all characters of each level from $1$ to $200$ into separate arrays. We will consider whom the character fought at the end of the game for each level separately. It is obvious that for each level of monsters $x$, the character fought a prefix of these monsters. Since the character's level increases monotonically, at some point the character's level will exceed $x$, and all monsters of level $x$ will flee.

Moreover, if the character fought a monster for some $k$, he will also fight it for $k + 1$ (by the proof from the previous solution).

Thus, to find out which new monsters the character will fight at level $k$, we can do the following. We will iterate over monster levels up to $200$ and for the first fleeing monster of this level, we will check whether the character will fight it now. For this, we need to find out how many monsters the character fought before this monster. If his level is not less than this number divided by $k$ (rounded down), then he will fight it. Among all the first monsters the character will fight, we will find the minimum. For it, our solution is definitely correct. For the others, this is not necessarily true, because the character's level may increase due to fights to the left of this position.

If no such monsters are found, then for this $k$ we have found all. Otherwise, in some data structure, we will mark that the character is fighting with the leftmost found monster.

Thus, we need a data structure that can answer prefix sum queries and update an element at a certain position. There are quite a few such structures. However, we have a large number of queries: for each fight, we need to make $200$ queries, that is, a total of $n \cdot 200$ queries. However, there are not so many updates: each position will be updated in the structure no more than once, that is, no more than $n$ updates. Therefore, we would like to have a structure that balances these operations. For example, let the query be $O(1)$, and the update be $O(\sqrt{n})$.

We will divide the array into blocks of size $O(\sqrt{n})$. For each block, we will store the sum of elements up to its left boundary. And for each position within each block, we will store the sum up to the left boundary of the block. Then, to query the prefix sum up to $i$, we need to add the sum up to the left position of the block $\frac{i}{\sqrt{n}}$ and the sum from $i$ to the start of this block. To update at position $i$, we need to add one to the first sum for each block from $\frac{i}{\sqrt{n}} + 1$ to the end. And also for each position from $i$ to the end of its block.

Queries can be answered as follows. For each monster, we will keep track of the first $k$ at which we will fight it. Then it is sufficient to check that the $k$ from the query is not less than this value.

Overall complexity: $O(n \sqrt{n})$.

 **Solution 1 (awoo)**
```cpp
#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
struct query{
	int i, j;
};
 
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	forn(i, n) cin >> a[i];
	vector<vector<query>> q(n + 1);
	forn(j, m){
		int i, x;
		cin >> i >> x;
		--i;
		q[x].push_back({i, j});
	}
	forn(i, n + 1){
		sort(q[i].begin(), q[i].end(), [](const query &a, const query &b){
			return a.i > b.i;
		});
	}
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int i, int j){
		return a[i] > a[j];
	});
	
	vector<int> cur(n + 1);
	vector<char> ans(m);
	ordered_set<int> alive(ord.begin(), ord.end());
	for (int lvl = 1; lvl <= n; ++lvl){
		for (int k = 1; k <= n; ++k){
			if (cur[k] >= n) break;
			int x = alive.order_of_key(cur[k]);
			int nxt = x + k - 1 >= int(alive.size()) ? n : *alive.find_by_order(x + k - 1);
			while (!q[k].empty() && q[k].back().i <= nxt){
				ans[q[k].back().j] = (a[q[k].back().i] >= lvl);
				q[k].pop_back();
			}
			cur[k] = nxt + 1;
		}
		while (!ord.empty() && a[ord.back()] == lvl){
			alive.erase(ord.back());
			ord.pop_back();
		}
	}
	
	for (auto x : ans) cout << (x ? "YES" : "NO") << 'n';
	return 0;
}
```
 **Solution 2 (awoo)**
```cpp
#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
struct query{
	int i, j;
};
 
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	forn(i, n) cin >> a[i];
	vector<vector<query>> q(n + 1);
	forn(j, m){
		int i, x;
		cin >> i >> x;
		--i;
		q[x].push_back({i, j});
	}
	forn(i, n + 1) sort(q[i].begin(), q[i].end(), [](const query &a, const query &b){
		return a.i > b.i;
	});
	
	int P = min(1000, n + 1);
	
	vector<char> ans(m);
	for (int k = 1; k < P; ++k){
		int cur = 1;
		int cnt = 0;
		forn(i, n){
			bool fl = false;
			if (a[i] >= cur){
				++cnt;
				fl = true;
				if (cnt == k){
					++cur;
					cnt = 0;
				}
			}
			while (!q[k].empty() && q[k].back().i == i){
				ans[q[k].back().j] = fl;
				q[k].pop_back();
			}
		}
	}
	
	vector<int> sum1(n), sum2(n);
	int p2 = ceil(sqrt(n + 2));
	
	auto add = [&](int i){
		int bl = i / p2;
		for (int j = bl + 1; j * p2 < n; ++j)
			++sum1[j];
		for (int j = i; j < (bl + 1) * p2 && j < n; ++j)
			++sum2[j];
	};
	
	int mx = n / P + 5;
	vector<vector<int>> pos(mx);
	forn(i, n){
		if (a[i] < mx)
			pos[a[i]].push_back(i);
		else
			add(i);
	}
	for (auto &it : pos) reverse(it.begin(), it.end());
	
	for (int k = P; k <= n; ++k){
		while (true){
			int mn = n;
			int who = -1;
			forn(lvl, mx) if (!pos[lvl].empty()){
				int i = pos[lvl].back();
				if (mn < i) continue;
				int cnt = sum1[i / p2] + sum2[i];
				if (a[i] >= cnt / k + 1){
					mn = i;
					who = lvl;
				}
			}
			if (who == -1) break;
			add(mn);
			pos[who].pop_back();
		}
		for (auto it : q[k]){
			int lvl = a[it.i];
			ans[it.j] = (lvl >= mx || pos[lvl].empty() || pos[lvl].back() > it.i);
		}
	}
	
	for (auto x : ans) cout << (x ? "YES" : "NO") << 'n';
	return 0;
}
```
[1997F - Chips on a Line](../problems/F._Chips_on_a_Line.md "Educational Codeforces Round 168 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1997F - Chips on a Line](../problems/F._Chips_on_a_Line.md "Educational Codeforces Round 168 (Rated for Div. 2)")

The operations described in the statement are kinda similar to the identities for Fibonacci numbers, so maybe the solution will be connected to them.

Let's assign each chip placement a weight: if chips are placed in points $x_1, x_2, \dots, x_n$ (repeating if multiple chips are in the same position), the weight of this placement is $f_{x_1} + f_{x_2} + \dots + f_{x_k}$, where $f_i$ is the $i$-th Fibonacci number ($f_1 = f_2 = 1$; $f_{i+2} = f_i + f_{i+1}$).

We can show that two placements can be transformed into each other if and only if their weights are identical. First of all, the operations described in the statement don't change the weight, so two placements with different weights cannot be transformed into each other. To show how to transform two placements with identical weight into each other, let's bring them into "canonical" form as follows:

* while there is a chip with coordinate $i > 2$, convert it into two chips with coordinates $i-1$ and $i-2$;
* if all remaining chips are in points $1$ and $2$, move all chips from $2$ to $1$.

After performing this sequence of actions, we will transform a placement of chips into the form "all chips are in point $1$, and the number of these chips is equal to the weight of the placement". And since all operations we apply are invertible (for every operation, there is an operation which "rolls it back"), we can transform any placement to any other placement with the same weight through this "canonical form".

So, instead of counting the placements, let's group them according to their weights and work with them. For every possible weight of a placement (which is an integer from $1$ to $f_x \cdot n$), we need to answer two questions:

* Is it true that the minimum cost of a placement of this weight is exactly $m$?
* How many placements with this weight are there?

The former is simple: this is just checking that the minimum number of Fibonacci numbers used to represent an integer is equal to $m$. We can precalculate this minimum number of Fibonacci numbers to represent each integer with a simple dynamic programming.

The latter is a bit more tricky: we need to count the number of ways to represent the given number as a sum of exactly $n$ Fibonacci numbers from $f_1$ to $f_x$, where the order of these Fibonacci numbers does not matter. There are different ways to calculate it, the model solution uses a dynamic programming which uses $O(f_x \cdot n^2 \cdot x)$ time and $O(f_x \cdot n^2)$ memory.

Let $dp_{i,j}$ be the number of ways to partition the integer $i$ into $j$ Fibonacci numbers. Initially, we will consider the situation when we can't use any Fibonacci numbers, so $dp_{0,0} = 1$ and everything else is $0$. And then we will "add" Fibonacci numbers one by one, so first we will update our dynamic programming in such a way that we can only use $f_1$; then, only $f_1$ and/or $f_2$; and so on.

Let's show how to "update" our dynamic programming when we can use a new number $k$ in partitions. The simple way to do this is as follows: for every $dp_{i,j}$, iterate on the number $c$ of new elements we will use, and get a partition of integer $i + c \cdot k$ into $j+c$ numbers. However, that is too slow.

Instead, let's iterate on the states of our dynamic programming in ascending order of $i$, and in each state, add at most one element to the partition (so, increase $dp_{i+k,j+1}$ by $dp_{i,j}$). At the first glance, it only allows us to use one element equal to $k$; however, when we consider the state $dp_{i+k,j+1}$ we updated, it will already store both the partitions which didn't use elements equal to $k$, and the partitions which used at least one element equal to $k$ (which came from the state $dp_{i,j}$); and by transitioning from $dp_{i+k,j+1}$ to $dp_{i+2k,j+2}$, we will "expand" all these partitions.

If the previous paragraph is a bit unclear to you, you can try viewing it as a three-state dynamic programming of the form "let $dp_{i,j,k}$ be the number of partitions of $i$ into $j$ Fibonacci numbers from $f_1$ to $f_k$", where we dropped the third state of our dynamic programming in favor of maintaining only one layer and being more memory efficient.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
const int MOD = 998244353;
 
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
 
int main()
{
 	int n, x, m;
 	cin >> n >> x >> m;
 	vector<int> fib = {0, 1};
 	for(int i = 2; i <= 30; i++)
 		fib.push_back(fib[i - 1] + fib[i - 2]);
 
 
 	int max_sum = fib[x] * n;
 	vector<vector<int>> dp(max_sum + 1, vector<int>(n + 1));
 	dp[0][0] = 1;
 	for(int i = 1; i <= x; i++)
 		for(int j = 0; j < max_sum; j++)
 			for(int k = 0; k < n; k++)
 			{
 			 	if(j + fib[i] <= max_sum)
 			 		dp[j + fib[i]][k + 1] = add(dp[j + fib[i]][k + 1], dp[j][k]);
 			}
	
	vector<int> cost(max_sum + 1, 1e9);
	cost[0] = 0;
	for(int j = 1; j <= max_sum; j++)
		for(int i = 1; i <= 30; i++)
			if(j >= fib[i])
				cost[j] = min(cost[j], cost[j - fib[i]] + 1);
 
	int ans = 0;
	for(int i = 0; i <= max_sum; i++)
		if(cost[i] == m)
			ans = add(ans, dp[i][n]);
	cout << ans << endl;
}
```
