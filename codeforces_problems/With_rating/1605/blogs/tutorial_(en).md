# tutorial_(en)

Thank you for participating! We hope you enjoyed the contest.

[1605A - A.M. Deviation](../problems/A._A.M._Deviation.md "Codeforces Round 754 (Div. 2)")

Authored and prepared by [JeevanJyot](https://codeforces.com/profile/JeevanJyot "Master JeevanJyot")

 **Hint 1**What happens to the value of d(a1,a2,a3) if you perform an operation on a1 and a3?

 **Hint 2**What happens if you perform an operation on a1 and a2?

 **Hint 3**Can we use negative values to improve the worst answer?

 **Solution**
### [1605A - A.M. Deviation](../problems/A._A.M._Deviation.md "Codeforces Round 754 (Div. 2)")

→ Applying the operation on a1 and a3 (irrespective of which element is incremented and which one is decremented) does not change the value of a1+a3−2⋅a2.

→ Incrementing a1 (or a3) by 1 and decrementing a2 by 1 causes the value of a1+a3−2⋅a2 to increase by 3.

→ Decrementing a1 (or a3) by 1 and incrementing a2 by 1 causes the value of a1+a3−2⋅a2 to decrease by 3.

This effectively means that we can add or subtract any multiple of 3 by performing some number of operations. Also, the value of a1+a3−2⋅a2 will never change modulo 3. Thus,

* If a1+a3−2⋅a2≡0 mod3, then the minimum value of d(a1,a2,a3)=|0|=0
* If a1+a3−2⋅a2≡1 mod3, then the minimum value of d(a1,a2,a3)=|1|=1
* If a1+a3−2⋅a2≡2 mod3, then the minimum value of d(a1,a2,a3)=|2−3|=|−1|=1

In simpler words, if a1+a3−2⋅a2 is divisible by 3 the answer is 0, otherwise it is 1.

Time Complexity: O(1)

 **Solution [c++] (JeevanJyot)**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int32_t main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int a, b, c; cin >> a >> b >> c;
        cout << ((a + c - 2 * b) % 3 == 0 ? 0 : 1) << "n"; 
    }        
    return 0;
}
```
 **Solution [Kotlin] (ExplodingFreeze)**
```cpp
fun main(args: Array<String>) {
    repeat(readLine()!!.toInt()) {
        println(Math.min(readLine()!!.split(" ").map { it.toInt() }.sum() % 3, 1))
    }
}
```
 **Solution [Python] (AshishGup)**
```cpp
t=int(input())
for i in range(t):
    a,b,c=[int(x) for x in input().split()]
    print(0 if ((a+b+c)%3 == 0) else 1)
```
[1605B - Reverse Sort](../problems/B._Reverse_Sort.md "Codeforces Round 754 (Div. 2)")

Authored by [Ashishgup](https://codeforces.com/profile/Ashishgup "Grandmaster Ashishgup") and prepared by [JeevanJyot](https://codeforces.com/profile/JeevanJyot "Master JeevanJyot").

 **Hint 1**What can you say about the number of $0$s and $1$s that are in positions where they should not be in the final string?

 **Hint 2**What is the minimum number of operations required to sort the string given this relationship between the number of such $0$s and $1$s?

 **Solution**
### [1605B - Reverse Sort](../problems/B._Reverse_Sort.md "Codeforces Round 754 (Div. 2)")

Any binary string $s$ can be sorted in at most $1$ operation!

Let the number of $0$s in $s$ be $cnt_0$ and the number of $1$s in $s$ be $cnt_1$.

The first $cnt_0$ positions of the final sorted string will be $0$ and the remaining $cnt_1$ positions will be $1$ (since it is sorted in non-decreasing order).

Key observation: For every $1$ that is in the first $cnt_0$ positions of $s$, there is a $0$ that is in the last $cnt_1$ positions of $s$ (Why?).

If the string is not already sorted, in one operation pick the subsequence consisting of all $1$s among the first $cnt_0$ positions of $s$ as well as all $0$s among the last $cnt_1$ positions of $s$. It can be shown that this will correctly sort the string since the number of such $0$s and $1$s are equal.

Time complexity: $\mathcal{O}(n)$ 

 **Solution [c++] (JeevanJyot)**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int32_t main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        string s; cin >> s;
        if(is_sorted(s.begin(), s.end()))
        {
            cout << 0 << "n";
            continue;
        }
        
        string t = s;
        sort(t.begin(), t.end());
        cout << 1 << "n";
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != t[i])
                ans.push_back(i+1);
        }
        cout << ans.size() << " ";
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " n"[i+1 == ans.size()];
    }        
    return 0;
}
```
 **Solution [Kotlin] (ExplodingFreeze)**
```cpp
fun main(args: Array<String>) {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!
        if("10" in s) {
            println(1);
            val res = s.toCharArray().sorted().withIndex().filter { it.value != s[it.index] }.map { it.index + 1 }
            println("${res.size} ${res.joinToString(" ")}");
        } else {
            println(0);
        }
        
    }
}
```
 **Solution [Python] (AshishGup)**
```cpp
q = int(input())
for tc in range(q):
    n = int(input())
    s = input()
    t = ''.join(sorted(s))
    ans = []
    for i in range(len(s)):
        if s[i] != t[i]: 
            ans.append(i)
    val = 1 if len(ans) > 0 else 0
    print(val)
    if val > 0:
        print(len(ans), end = " ")
    for elem in range(len(ans)):
        print(ans[elem] + 1, end = " ")
    print()
```
[1605C - Dominant Character](../problems/C._Dominant_Character.md "Codeforces Round 754 (Div. 2)")

Authored by [Ashishgup](https://codeforces.com/profile/Ashishgup "Grandmaster Ashishgup") and prepared by [JeevanJyot](https://codeforces.com/profile/JeevanJyot "Master JeevanJyot").

 **Hint 1**Think about small substrings.

 **Hint 2**What are the strings that satisfy the given conditions?

 **Hint 3**If you got WA on pretest 2, then you're probably not checking 7 length strings.

 **Solution**
### [1605C - Dominant Character](../problems/C._Dominant_Character.md "Codeforces Round 754 (Div. 2)")

Tl;dr: The following are all the possible minimal substrings (there aren't that many) which satisfy the given conditions: "aa", "aba", "aca", "abca", "acba", "abbacca", "accabba". Any other string that satisfies the condition contains at least one of these as a substring, and hence is not the optimal substring for the answer.

Claim: If a substring exists which satisfies the given conditions, then the length of the shortest such substring is at most $7$. Otherwise the solution does not exist.

Proof: Let us consider that the solution exists. We will try to prove this by breaking this into the following cases:

Case 1: There exist two such "a" whose distance is less than or equal to $2$, where distance is the absolute difference of their indices.

* In this case where there are two such "a" whose distance is less than $2$, then either these two "a" are present consecutive or there is only one single letter between these two "a". All these minimal substrings are "aa", "aba" and "aca"which satisfies all the given conditions.

Hence we can say that the shortest length of such substring that satisfies the given conditions is at most $3$ in this case.

Case 2: There exists no two such "a" whose distance is less than or equal to $2$.

* In this case all the consecutive occurrences of "a" are present at a distance at least $3$. Then in order for the number of "a" to be bigger than that of "b" and "c" the string must look like "a??a??a??a??a".
* Let us define "??" as a block. Now if there is any block consisting of different characters $i.e$ "bc" or "cb" then the substring "a??a" will satisfy all the given conditions and hence the minimal length will be $4$.
* Notice that there must be at least one block of "bb" and atleast one block of "cc", otherwise "a" will not be in a majority. Hence, there must exist 2 consecutive blocks equal to "bb" and "cc" or "cc" and "bb" in the string (otherwise all blocks would be of the same character). Hence we can pick the substring "abbacca" or "accabba" which satisfies the given conditions. The minimal length is, therefore, $7$ in this case.

Therefore we can say that the shortest length of such substring that satisfies the given conditions is at most $7$ in this case.

Thus, it suffices to only check all substrings of length up to $7$ and find the smallest among them that satisfies the given conditions (or report that it does not exist).

Time Complexity: $\mathcal{O}(7 \cdot n)$

 **Solution [c++] (AshishGup)**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "n"
#define int long long
 
const int N = 1e6 + 5;
 
int n;
string s;
 
int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		int ans = 1e9;
		for(int i = 0; i < n; i++)
		{
			vector<int> f(3, 0);
			f[s[i] - 'a']++;
			for(int j = i + 1; j < min(n, i + 7); j++)
			{
				f[s[j] - 'a']++;
				if(f[0] > f[1] && f[0] > f[2])
					ans = min(ans, j - i + 1);
			}
		}
		if(ans == 1e9)
			ans = -1;
		cout << ans << endl;
	}
	return 0;
}
```
 **Solution [Kotlin] (ExplodingFreeze)**
```cpp
fun main(args: Array<String>) {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!
        var ans = 8;
        for(i in 0..n-1) {
            val cnt = IntArray(3) {0}
            for(j in i..Math.min(i + 6, n - 1)) {
                cnt[s[j] - 'a']++;
                if(j > i && cnt[0] > Math.max(cnt[1], cnt[2]))
                    ans = Math.min(ans, j - i + 1);
            }
        }
        if(ans > 7)
            ans = -1;
        println(ans)
    }
}
```
[1605D - Treelabeling](../problems/D._Treelabeling.md "Codeforces Round 754 (Div. 2)")

Authored and prepared by [the_hyp0cr1t3](https://codeforces.com/profile/the_hyp0cr1t3 "Master the_hyp0cr1t3").

 **Hint 1**When is u⊕v≰min(u,v)?

 **Hint 2**If u⊕v≰min(u,v) for any u that is adjacent to v, the player cannot make move and will lose.

 **Hint 3**Can you relabel the nodes in such a way that u⊕v≰min(u,v) for any u and v which share an edge? Think bipartite.

 **Hint 4**The number of occurrences of (almost) every 'class' of nodes of the same kind is a unique power of 2.

 **Hint 5**Thinking about the binary representation of a number is often useful in competitive programming.

 **Solution**
### [1605D - Treelabeling](../problems/D._Treelabeling.md "Codeforces Round 754 (Div. 2)")

If the most significant bits (MSBs) of two integers $x$ and $y$ are the same, say $\mathrm{MSB}_x = \mathrm{MSB}_y = b$, then the $b$-th bit will be unset in $x \oplus y$. Since $min(x, y)$ will have this bit set, it will be greater than $x \oplus y$. Thus, if $\mathrm{MSB}_x = \mathrm{MSB}_y$ then $x \oplus y \leq min(x, y)$.

If a node in the tree is adjacent only to nodes whose MSB differs from its MSB, then the player who plays this node will win.

It turns out that not only is it always possible to make it such that no two nodes sharing an edge have the same MSB, it is also necessary to do so in order to maximize the number of winnning starting nodes for Eikooc. Consequently, starting at any node will guarantee a win for her.

Why is it necessary if it is always possible? $ \\\ $ Assume there exists at least two nodes in the tree that are adjacent to each other, having the same MSB. We prove that there will be at least one losing node for Eikooc to start on, which is suboptimal. $ \\\ $ Consider a connected component of nodes in the tree of size at least two, all having the same MSB. Since this connected component also forms a tree, it must have at least one leaf node. Any node in the component which is adjacent to at least one of these leaf nodes will be losing for Eikooc (since Sushi can just move the token to a leaf node and Eikooc will have no moves to play).

How do you construct it and is it always possible to do so (if so, why)? $ \\\ $ We aim to relabel the nodes of the tree in such a way that for every node $v$ in the tree and all nodes $u$ adjacent to it, $\mathrm{MSB}_v \neq \mathrm{MSB}_u$. $ \\\ $ Think bipartite. In the [bipartite colouring](https://codeforces.com/https://cses.fi/book/book.pdf#page=122) of a tree, no two adjacent nodes have the same colour. If we are able to relabel the nodes in such a way that all nodes with the same MSB belong to the same colour, we are done. $ \\\ $ Key observation: There are $2^i$ occurrences of integers from $1$ to $n$ with the $i$-th bit as MSB (0-indexed) for each $i$ from $0$ to $\mathrm{MSB}_n - 1$, and all such groups of integers are disjoint (since each integer has exactly one MSB). $ \\\ $ Let the number of white and black nodes be $w$ and $b$ respectively and WLOG let $w \leq b$ (we can swap the colours otherwise). Since all nodes are coloured either white or black, $w + b = n$. Under these constraints, it is then easy to show that $w \leq \frac{n}{2}$. Consequently, $\mathrm{MSB}_w \lt \mathrm{MSB}_n$. Since $\mathrm{MSB}_w \lt \mathrm{MSB}_n$, $w$ can possibly only have those bits set which lie in the range $[0, \mathrm{MSB}_n - 1]$. Can you connect the dots? $ \\\ $ Consider the binary representation of $w$. We can assign all integers from $1$ to $n$ having the $i$-th bit as MSB to a white node if the $i$-th bit is set in $w$, and assign all the remaining integers to black nodes. In doing so, no two nodes having the same MSB will belong to different colours. This ensures that no such pair is adjacent. This is also guaranteed to always be possible since the binary representation of $w$ only spans the first $\mathrm{MSB}_n - 1$ bits and we also have access to groups of sizes comprising all powers of two upto $\mathrm{MSB}_n - 1$.

Time complexity: $\mathcal{O}(n)$

 **Solution [c++] (the_hyp0cr1t3)**
```cpp
/**
 * the_hyp0cr1t3
 * 24.09.2021 01:19:28
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
 
template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int Q; cin >> Q;
 
    while(Q--) []() {
        int i, j, k, n;
        cin >> n;
        vector<vector<int>> g(n);
        for(i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            g[--u].push_back(--v); g[v].push_back(u);
        }
 
        int lg = 32 - __builtin_clz(n);
        vector<vector<int>> vals(lg);
        for(i = 1; i <= n; i++)
            vals[31 - __builtin_clz(i)].push_back(i);
 
        vector<int> col(n);
        Y([&](auto dfs, int v, int p) -> void {
            for(auto& x: g[v]) if(x ^ p) {
                col[x] = col[v] ^ 1;
                dfs(x, v);
            }
        })(0, -1);
 
        int w = accumulate(col.begin(), col.end(), 0);
        if(w > n - w) {
            w = n - w;
            for(auto& x: col) x ^= 1;
        }
 
        vector<int> ans(n);
        for(i = j = k = 0; k < lg; k++) {
            for(auto x: vals[k]) {
                if(w >> k & 1) {
                    while(!col[i]) i++;
                    ans[i++] = x;
                } else {
                    while(col[j]) j++;
                    ans[j++] = x;
                }
            }
        }
 
        for(i = 0; i < n; i++)
            cout << ans[i] << " n"[i + 1 == n];
    }();
 
} // ~W
```
 **Solution [c++] (AshishGup)**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "n"
 
const int N = 2e5 + 5;
 
int n;
int msb[N], ans[N];
vector<int> nodes[2];
vector<int> g[N];
 
void precompute()
{
	int bit = 1, cnt = 1, nxt = 2;
	for(int i = 1; i < N; i++)
	{
		msb[i] = bit;
		cnt--;
		if(cnt == 0)
			cnt = nxt, bit++, nxt *= 2;
	}
}
 
void dfs(int u, int par, int col)
{
	nodes[col].push_back(u);
	for(auto &v: g[u])
	{
		if(v == par)
			continue;
		dfs(v, u, col ^ 1);
	}
}
 
 
int32_t main()
{
	IOS;
	precompute();
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 1; i <= n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0, 0);
		vector<vector<int> > v(20);
		for(int i = 1; i <= n; i++)
			v[msb[i]].push_back(i);
		for(int i = 19; i >= 0; i--)
		{
			int cur = 0;
			if(nodes[cur ^ 1].size() > nodes[cur].size())
				cur ^= 1;
			for(auto &it:v[i])
			{
				int node = nodes[cur].back();
				nodes[cur].pop_back();
				ans[node] = it;
			}
		}
		for(int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}
```
 **Solution [Kotlin] (ExplodingFreeze)**
```cpp
fun dfs(x: Int, p: Int, curcol: Int, adj: Array<MutableList<Int>>, col: Array<Int>) {
    col[x] = curcol
    adj[x]
        .filter { it != p }
        .forEach { dfs(it, x, curcol xor 1, adj, col) }
}
 
fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    repeat(t) {
        val n = readLine()!!.toInt()
        val adj = Array(n) { mutableListOf<Int>() }
        repeat(n - 1) {
            val (u, v) = readLine()!!.split(" ").map { it.toInt() }
            adj[u - 1].add(v - 1);
            adj[v - 1].add(u - 1);
        }
        val col = Array<Int>(n) {0}
        dfs(0, -1, 0, adj, col)
        var s = Array(2) { mutableListOf<Int>() }
        (0..n-1).forEach { s[col[it]].add(it) }
        if(s[0].size < s[1].size)
            s[0] = s[1].also { s[1] = s[0] }
        val highestBit = Array(20) { mutableListOf<Int>() }
        (1..n).forEach { highestBit[it.takeHighestOneBit().countTrailingZeroBits()].add(it - 1) }
        val ans = Array<Int>(n) {-1}
        (19 downTo 0).forEach { currentBit ->
            val largerSet = if(s[0].size >= s[1].size) 0 else 1
            highestBit[currentBit].forEach { it ->
                ans[it] = s[largerSet].last()
                s[largerSet].removeLast()
            }
        }
        val pos = Array<Int>(n) {-1}
        (0..n-1).forEach { pos[ans[it]] = it };
        (0..n-1).forEach { print ("${pos[it] + 1} ") }
        println()
    }
}
```
[1605E - Array Equalizer](../problems/E._Array_Equalizer.md "Codeforces Round 754 (Div. 2)")

Authored and prepared by [JeevanJyot](https://codeforces.com/profile/JeevanJyot "Master JeevanJyot").

 **Hint 1**How would you solve the problem for one query?

 **Hint 2**Assume the value of b1 to be some variable, say x.

 **Hint 3**Try finding the number of operations applied at each index in terms of x.

 **Solution**
### [1605E - Array Equalizer](../problems/E._Array_Equalizer.md "Codeforces Round 754 (Div. 2)")

Firstly let's observe that only the differences $b_i - a_i$ matter, and not the individual values of $a_i$ and $b_i$. So let us create two more arrays $A$ and $B$ where initially $A_i = 0$ and $B_i = b_i - a_i$ for all $i$. The problem reduces to making $A$ equal to $B$.

Let's have a few definitions for ease of explanation. We define operation "add" $k$ to $i$ as: perform the increment operation at $i$ (and multiples of $i$), $k$ times, if $k > 0$, otherwise perform the decrement operation at $i$ (and multiples of $i$), $k$ times. In both cases, the number of operations performed is $|k|$.

Let's first solve the problem for only one value of $B_1$. We notice that problem can be solved using a simple greedy approach. We iterate over the elements from left to right. Let the index of the current element be $u$.

* Initial arrays: 

| - | 1 | 2 | 3 | 4 | 5 | 6 | $\cdots$ |
| --- | --- | --- | --- | --- | --- | --- | --- |
| $A$ | $0$ | $0$ | $0$ | $0$ | $0$ | $0$ | $\cdots$ |
| $B$ | $B_1$ | $B_2$ | $B_3$ | $B_4$ | $B_5$ | $B_6$ | $\cdots$ |
| add | - | - | - | - | - | - | $\cdots$ |
* At $u = 1$: Applying the operation at $i = 1$ alone can change the value of $A_1$. Thereby we "add" $B_1$ at $i = 1$ to make $A_1 = B_1$. The remaining array also gets modified accordingly. Resulting arrays: 

| - | 1 | 2 | 3 | 4 | 5 | 6 | $\cdots$ |
| --- | --- | --- | --- | --- | --- | --- | --- |
| $A$ | $B_1$ | $B_1$ | $B_1$ | $B_1$ | $B_1$ | $B_1$ | $\cdots$ |
| $B$ | $B_1$ | $B_2$ | $B_3$ | $B_4$ | $B_5$ | $B_6$ | $\cdots$ |
| add | $B_1$ | - | - | - | - | - | $\cdots$ |
* At $u = 2$: Applying the operation at $i = 1$ and $i = 2$ only can change the value of $A_2$. But since we have already made $A_1 = B_1$, we will only apply operations at $i = 2$. We "add" $B_2 - B_1$ at $i = 2$. Resulting arrays: 

| - | 1 | 2 | 3 | 4 | 5 | 6 | $\cdots$ |
| --- | --- | --- | --- | --- | --- | --- | --- |
| $A$ | $B_1$ | $B_2$ | $B_1$ | $B_2$ | $B_1$ | $B_2$ | $\cdots$ |
| $B$ | $B_1$ | $B_2$ | $B_3$ | $B_4$ | $B_5$ | $B_6$ | $\cdots$ |
| add | $B_1$ | $B_2 - B_1$ | - | - | - | - | $\cdots$ |
* At $u = 3$: Applying the operation at $i = 1$ and $i = 3$ only can change the value of $A_3$. But since we have already made $A_1 = B_1$, we will only apply operations at $i = 3$. We "add" $B_3 - B_1$ at $i = 3$. Resulting arrays: 

| - | 1 | 2 | 3 | 4 | 5 | 6 | $\cdots$ |
| --- | --- | --- | --- | --- | --- | --- | --- |
| $A$ | $B_1$ | $B_2$ | $B_3$ | $B_2$ | $B_1$ | $B_3 + B_2 - B_1$ | $\cdots$ |
| $B$ | $B_1$ | $B_2$ | $B_3$ | $B_4$ | $B_5$ | $B_6$ | $\cdots$ |
| add | $B_1$ | $B_2 - B_1$ | $B_3 - B_1$ | - | - | - | $\cdots$ |
* At $u = 4$: Applying the operation at $i = 1$, $i = 2$ and $i = 4$ only can change the value of $A_4$. But since we have already made $A_1 = B_1$ and $A_2$ = B_2, we will only apply operations at $i = 4$. We "add" $B_4 - B_2$ at $i = 4$. Resulting arrays: 

| - | 1 | 2 | 3 | 4 | 5 | 6 | $\cdots$ |
| --- | --- | --- | --- | --- | --- | --- | --- |
| $A$ | $B_1$ | $B_2$ | $B_3$ | $B_2$ | $B_1$ | $B_3 + B_2 - B_1$ | $\cdots$ |
| $B$ | $B_1$ | $B_2$ | $B_3$ | $B_4$ | $B_5$ | $B_6$ | $\cdots$ |
| add | $B_1$ | $B_2 - B_1$ | $B_3 - B_1$ | $B_4 - B_2$ | - | - | $\cdots$ |

 And so on...So we iterate from left to right and at every index $u$, we "add" $(B_u -$ current value of $A_u)$ at $i = u$. The final answer will be summation of absolute value of these values (i.e. the values written in the "add" row).

However, in the original problem, we have to solve the problem for multiple values of $B_1$. So let us assume the value of $B_1$ to be equal to some variable, say $x$. Let us try to use the same approach with the variable $x$.

* Initial arrays: 

| - | 1 | 2 | 3 | 4 | 5 | 6 | $\cdots$ |
| --- | --- | --- | --- | --- | --- | --- | --- |
| $A$ | $0$ | $0$ | $0$ | $0$ | $0$ | $0$ | $\cdots$ |
| $B$ | $x$ | $B_2$ | $B_3$ | $B_4$ | $B_5$ | $B_6$ | $\cdots$ |
| add | - | - | - | - | - | - | $\cdots$ |
* At $u = 1$: We "add" $x$ at $i = 1$. Resulting arrays: 

| - | 1 | 2 | 3 | 4 | 5 | 6 | $\cdots$ |
| --- | --- | --- | --- | --- | --- | --- | --- |
| $A$ | $x$ | $x$ | $x$ | $x$ | $x$ | $x$ | $\cdots$ |
| $B$ | $x$ | $B_2$ | $B_3$ | $B_4$ | $B_5$ | $B_6$ | $\cdots$ |
| add | $x$ | - | - | - | - | - | $\cdots$ |
* At $u = 2$: We "add" $B_2 - x$ at $i = 2$. Resulting arrays: 

| - | 1 | 2 | 3 | 4 | 5 | 6 | $\cdots$ |
| --- | --- | --- | --- | --- | --- | --- | --- |
| $A$ | $x$ | $B_2$ | $x$ | $B_2$ | $x$ | $B_2$ | $\cdots$ |
| $B$ | $x$ | $B_2$ | $B_3$ | $B_4$ | $B_5$ | $B_6$ | $\cdots$ |
| add | $x$ | $B_2 - x$ | - | - | - | - | $\cdots$ |
* At $u = 3$: We "add" $B_3 - x$ at $i = 3$. Resulting arrays: 

| - | 1 | 2 | 3 | 4 | 5 | 6 | $\cdots$ |
| --- | --- | --- | --- | --- | --- | --- | --- |
| $A$ | $x$ | $B_2$ | $B_3$ | $B_2$ | $x$ | $B_3 + B_2 - x$ | $\cdots$ |
| $B$ | $x$ | $B_2$ | $B_3$ | $B_4$ | $B_5$ | $B_6$ | $\cdots$ |
| add | $x$ | $B_2 - x$ | $B_3 - x$ | - | - | - | $\cdots$ |
* At $u = 4$: We "add" $B_4 - B_2$ at $i = 4$. Resulting arrays: 

| - | 1 | 2 | 3 | 4 | 5 | 6 | $\cdots$ |
| --- | --- | --- | --- | --- | --- | --- | --- |
| $A$ | $x$ | $B_2$ | $B_3$ | $B_4$ | $x$ | $B_3 + B_2 - x$ | $\cdots$ |
| $B$ | $x$ | $B_2$ | $B_3$ | $B_4$ | $B_5$ | $B_6$ | $\cdots$ |
| add | $x$ | $B_2 - x$ | $B_3 - x$ | $B_4 - B_2$ | - | - | $\cdots$ |

 And so on...Every cell in the "add" row here will be of the form: $c \cdot x + d$. The final answer will be the summation of absolute values of these values written in the "add" row.

Also we know,

$$ |c \cdot x + d| = \begin{cases} c \cdot x + d & x \ge -\frac{d}{c} \\\ -(c \cdot x + d) & x \lt -\frac{d}{c} \end{cases} $$

Note that the above equalities hold only when $c \gt 0$. So if $c$ is negative in any term, then we can multiply the entire term with $-1$ to make it positive since $|c \cdot x + d| = |- c \cdot x - d|$.

Now, we can store the values of $-\frac{d}{c}$ for each index in sorted order. And for each query, we can find out, using binary search, which of the absolute value terms will have a positive sign and which of those will have a negative sign. So we can finally calculate the answer using prefix and suffix sums.

Bonus: It turns out that the value of coefficient of $x$ in the "add" value for the $u$-th index is $c_u = \mu(u)$ where $\mu$ is the mobious function. So $-1 \le c_u \le 1$.

Time Complexity: $\mathcal{O}(n \log n + q \log n)$

$$ \cdots $$

 **Solution [c++] (JeevanJyot)**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define endl "n"
#define sz(w) (int)(w.size())
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const long long INF = 1e18;
 
const int N = 2e5+5; 
 
int n, m, a[N], b[N], c[N], add[N], mob[N];
 
void mobius() 
{
    mob[1] = 1;
    for(int i = 2; i < N; i++)
    {
        mob[i]--;
        for(int j = i + i; j < N; j += i) 
        {
          mob[j] -= mob[i];
        }
    }
}
 
int32_t main()
{
    IOS;
    mobius();
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++)
        c[i] = b[i] - a[i];
    c[1] = 0;
    vector<int> z;
    for(int i = 1; i <= n; i++)
    {
        int d = c[i];
        for(int j = i; j <= n; j += i)
        {
            c[j] -= d;
        }
        add[i] = d;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(mob[i] == 0)
            ans += abs(add[i]);
        else if(mob[i] == -1)
            z.push_back(-add[i]);
        else 
            z.push_back(add[i]);
    }
    sort(z.begin(), z.end());
    vector<int> pref = z;
    for(int i = 1; i < sz(z); i++)
        pref[i] = pref[i-1] + z[i];
    auto sum = [&pref](int l, int r)
    {
        if(r < 0) return 0LL;
        int res = pref[r];
        if(l-1 >= 0)
            res -= pref[l-1];
        return res;
    };
    int q; cin >> q;
    while(q--)
    {
        int x; cin >> x;
        x -= a[1];
        int lo = 0, hi = sz(z)-1;
        while(lo <= hi)
        {
            int mid = (lo+hi)/2;
            if(z[mid] <= -x)
                lo = mid+1;
            else
                hi = mid-1;
        }
        swap(lo, hi);
        int res = sum(hi, sz(z)-1) + (sz(z)-hi) * x;
        res -= (sum(0, lo) + (lo+1)*x);
        cout << ans+res << endl;
    }
    return 0;
}
```
[1605F - PalindORme](../problems/F._PalindORme.md "Codeforces Round 754 (Div. 2)")

Authored by [ExplodingFreeze](https://codeforces.com/profile/ExplodingFreeze "Master ExplodingFreeze") and [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Legendary Grandmaster antontrygubO_o") and prepared by [ExplodingFreeze](https://codeforces.com/profile/ExplodingFreeze "Master ExplodingFreeze").

 **Hint 1**How can you check if an array is good?

 **Hint 2**Is there any relation between a bad array and a good array?

 **Hint 3**How can we define a unique good subsequence of a bad array?

 **Hint 4**Can we somehow count the number of bad arrays using this?

 **Hint 5**Can we modify our choice of subsequence such that we can easily count the number of ways of choosing the remaining elements?

 **Solution**
### [1605F - PalindORme](../problems/F._PalindORme.md "Codeforces Round 754 (Div. 2)")

$\textbf{Solution Outline:}$

For any bad array, there is $\textbf{exactly one}$ maximum even length good subsequence (possibly the empty subsequence).

It can be proven that there exists at most one element in the bad array that doesn't belong to this subsequence, but is a submask of its OR. If such an element exists, we add it to the subsequence. After performing this step if needed, we have a good subsequence of this bad array such that all other elements of this array have one or more bits active which aren't present anywhere in this subsequence. We will call this the "best" subsequence from now on. Clearly a bad array also has $\textbf{exactly one}$ best subsequence.

By noting that the best subsequence is still a good array (place the extra element in the middle of the PalindORme of even length), we can use dp to count the number of bad arrays of length $n$ with exactly $k$ bits on in total using its best subsequence of length $n' \lt n$ with exactly $k' \lt k$ bits on in total in $O(n ^ 4)$.

$\textbf{Full Editorial:}$

Let $S$ be the multiset of elements of the initial array $a_1, a_2, \ldots, a_n$. We want to check if we can construct a PalindORme from these elements. 

Out of the $n$ conditions of the form $b_{1}$ $|$ $b_{2} $ $|$ $ \ldots $ $|$ $ b_{i} = b_{{n - i + 1}} $ $|$ $ \ldots $ $|$ $ b_{{n - 1}} $ $|$ $ b_{n} $, it intuitively makes sense to tackle them in increasing order of $i$, so we will try to do that.

* For $i = 1$, we want to find two elements $x, y$ in $S$ such that $x = y$. We place these elements as $b_1$ and $b_n$ and erase them from $S$.
* For $i = 2$, we want to find two elements $x, y$ in $S$ such that $b_1$ $|$ $x$ $=$ $b_1$ $|$ $y$. We place these elements as $b_2$ and $b_{n - 1}$ and erase them from $S$.
* Generalizing, for any $i$, we want to find two elements $x, y$ in $S$ such that $b_{1}$ $|$ $b_{2} $ $|$ $ \ldots $ $|$ $ b_{i - 1}$ $|$ $x$ $=$ $b_{1}$ $|$ $b_{2} $ $|$ $ \ldots $ $|$ $ b_{i - 1}$ $|$ $y$. We place these elements as $b_i$ and $b_{n + 1 - i}$ and erase them from $S$.

But what if there exists multiple pairs $(x_1, y_1), (x_2, y_2), \ldots (x_k, y_k)$ that satisfy the property in a given step, which do we take? 

It is optimal to take any of them. Clearly if $mask$ $|$ $x_j$ = $mask$ $|$ $y_j$, then $mask$ $|$ $z$ $|$ $x_j$ = $mask$ $|$ $z$ $|$ $y_j$ is also true for any $z$. So regardless of which of these pairs we take, all other pairs will remain good in future steps.

So we obtain the following simple algorithm to check if a PalindORme is good:


```cpp
  
mask = 0  
good = true  
while |S| > 1:  
    if there exists any two elements x, y in S such that mask | x = mask | y  
        mask = mask | x  
        erase x and y from S  
    else  
        good = false  
        break  
end while  

```
This algorithm is equivalent to placing elements at positions $i$ and $(n + 1 - i)$ of the PalindORme in the $i$-th iteration of the loop. Taking any two elements is optimal since a pair that satisfies the property for $mask$ will also clearly satisfy it for $mask$ $|$ $x$.

Let us consider the multiset $S$ corresponding to the elements of a bad array:

* This algorithm will fail to find any such pair of elements after some number of steps.
* The pairs which have been selected till this point will constitute a good array (possibly of length 0).
* For the given bad array, the number of pairs taken as well as the bits on in the mask will always be the same when the algorithm fails regardless of the two elements selected in each step.
* Since we cannot add any two more elements to this good array, this is the longest even length good subsequence of the bad array. Due to the previous point, we can also see that it is the only good subsequence of this length.
* There can exist at most one element among the remaining elements not in the subsequence which is a submask of $mask$, otherwise there would exist a pair such that $mask$ $|$ $x$ $=$ $mask$ $|$ $y$ $=$ $mask$.
* If such an element exists, we can add it to the subsequence. The best subsequence still remains a good array since we can place this element in the center position of resulting PalindORme.
* After performing this step if needed, we have a good subsequence of this bad array such that all elements of this array not in the subsequence have one or more bits active which aren't on in $mask$ and therefore not present in the subsequence. We will call this the "best" subsequence from now on. Clearly a bad array also has $\textbf{exactly one}$ best subsequence (possibly of length 0).

So every bad array of length $n$ with $k$ bits on in total can be mapped to a best subsequence (which is a good array) with length $n' \lt n$ with $k' \lt k$ bits on in total. The remaining $n - n'$ elements will then need to be chosen such that they have the remaining $k - k'$ bits on in total while possessing distinct values when OR'd with $mask$.

So we obtain a dp to count the number of bad arrays $-$ $cnt\\_bad_{\text{length}, \text{bits on in total}}$, where $cnt\\_bad_{i, j} = \sum\limits_{i' = 0}^{i - 1} \sum\limits_{j' = 0}^{j - 1} f(i, j, i', j')\cdot(cnt\\_good_{i', j'})$.

Here $f(i, j, i', j')$ is the number of bad arrays of length $i$ with exactly $j$ bits on in total, that have a good array of length $i' \lt i$ with exactly $j' \lt j$ bits on in total as their best subsequence.

Since the total number of arrays of length $x$ with exactly $y$ bits on in total can be easily calculated using some basic combinatorial formulas and inclusion exclusion, we can rewrite this as:

$cnt\\_bad_{i, j}$ $=$ $\sum\limits_{i' = 0}^{i - 1} \sum\limits_{j' = 0}^{j - 1} f(i, j, i', j')\cdot(cnt\\_total_{i', j'} - cnt\\_bad_{i', j'})$ 

giving us a dp with $O(n ^ 2)$ states and $O(n ^ 4)$ transitions.

$f(i, j, i', j')$ is made of the following components:

1. The number of ways of placing the best subsequence in the bad array. 


	 
	
	* Since there are no values in common between the best subsequence and the remaining values of the array, the answer is just $n \choose n'$.
2. The number of ways of choosing which $j'$ of the $j$ bits were from the good array. 


	 
	
	* All ways are possible, so it is just $j \choose j'$
3. The number of different arrays of length $i - i'$ with the remaining $j - j'$ bits set in total such that each element has one or more of the $j - j'$ bits set and all elements have distinct values when OR'd with $mask$, i.e, the remaining $j$ bits. 


	 
	
	* We can observe that the second can be broken into the product of two easier parts: 
	
	
		 
		
		+ The number of different arrays of $i - i'$ distinct positive numbers with exactly $j - j'$ bits set in total. We can first find the number of ways of permuting $i - i'$ positive numbers with $\textbf{up to}$ $k$ bits set in total as $^{2^k - 1} P_{i - i'}$. Then we just need to perform simple inclusion-exclusion to get the answer for exactly $k$ bits set in total.
		+ The number of ways of setting the remaining $j'$ bits for these numbers. Since $mask$ is effectively the OR of all elements in the good array, all the $j'$ bits are already set in $mask$. So any setting of these $j'$ bits for these numbers doesn't doesn't affect the values when OR'd with $mask$. So the number of ways is just $2^{(i - i')\cdot(j')}$.

Since these three components are independent of each other, $f(i, j, i', j')$ is just the product of them.

However, as you may have observed, the "bad" arrays counted by this dp doesn't line up with the actual definition of bad arrays in one case - When a "bad" array has an even length best subsequence and a single remaining element with one or more bits that aren't set in this subsequence. This is clearly a good array but is counted as bad by our dp. (Example: good array [1, 1] combined with remaining element array [2] resulting in [1, 2, 1] (or [1, 1, 2] / [2, 1, 1]) which is clearly a good array but is counted as bad by our dp.)

This is however necessary since this is the only type of good array that is never the best subsequence of any bad array. Counting it as a good array in our dp would lead to overcounting when it was used as a best subsequence.

But then how do we then recover the correct number of actual bad arrays of length $n$ with exactly $j$ bits set? We can notice that this case occurs for best subsequences of length $i - 1$ when $i$ is odd. So when counting the number of bad arrays of length $n$ we can just skip best subsequences of length $n - 1$ if $n$ is odd. Since $n$ is the largest array size we are concerned with, good arrays of size $n$ will never be a best subsequence of a larger bad array and as such won't lead to overcounting.

As a final note, remember that we have the number of bad arrays for $n$ with $\textbf{exactly}$ $j$ bits set while we need the number of bad arrays with $\textbf {up to}$ $j$ bits set. This can be easily obtained by multiplying the answer for a given $j$ with the number of ways of choosing $j$ of the $k$ bits and summing these values up for each $j$. In short, we want $\sum_{j = 0}^{k} {k \choose j} \cdot cnt\\_good_{n, j}$.

Time Complexity: $\mathcal{O}(n ^ 4)$

$$ \cdots $$

 **Solution [c++] (ExplodingFreeze)**
```cpp
#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;
 
const int maxn = 105;
 
int t, n, k, MOD, modinv[maxn], fact[maxn], invfact[maxn], cnt_distinct_positive[maxn][maxn], cnt_total[maxn][maxn], cnt_bad[maxn][maxn], pow2[maxn * maxn];
// cnt_distinct_positive[i][j] = ways of choosing i distinct positive values with a combined of exactly j bits on.
// cnt_total[i][j] = total number of arrays of length i with exactly j bits on in total
// cnt_bad[i][j] = number of bad arrays of length i with exactly j bits on in total
 
int mod_expo(int x, int p)
{
    if(!p)
        return 1;
    int res = mod_expo(x, p / 2);
    res *= res;
    res %= MOD;
    if(p & 1)
        res *= x;
    return res % MOD;
}
 
int mod_inv(int x)
{
    return mod_expo(x, MOD - 2);
}
 
// O(1) with O(n) precalc needed
int fast_nCr(int x, int r)
{
    assert(x < maxn && r >= 0 && r <= x);
    int num = fact[x];
    int denom = (invfact[r] * invfact[x - r]) % MOD;
    return (num * denom) % MOD;
}
 
// O(x - r)
int slow_nPr(int x, int r)
{
    assert(r >= 0 && r < maxn);
    int res = 1;
    for(int j = 1; j <= r; j++)
    {
        res *= (x - j + 1 + MOD) % MOD;
        res %= MOD;
    }
    return res;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> MOD;
    fact[0] = invfact[0] = 1;
    for(int i = 1; i < maxn; i++)
    {
        modinv[i] = mod_inv(i);
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = mod_inv(fact[i]);
    }
    pow2[0] = 1;
    for(int i = 1; i <= n * k; i++)
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            // The number of ways of selecting i distinct positive values with upto j bits set in total
            cnt_distinct_positive[i][j] = slow_nPr((mod_expo(2, j) - 1 + MOD) % MOD, i);
            // The number of ways of selecting i non-negative values with upto j bits set
            cnt_total[i][j] = pow2[i * j];
            // Inclusion exclusion to get the count for exactly j bits for both values.
            for(int l = 0; l < j; l++)
            {
                cnt_distinct_positive[i][j] += (MOD - ((fast_nCr(j, l) * cnt_distinct_positive[i][l])) % MOD);
                cnt_distinct_positive[i][j] %= MOD;
                cnt_total[i][j] += (MOD - ((fast_nCr(j, l) * cnt_total[i][l])) % MOD);
                cnt_total[i][j] %= MOD;
            }
        }
    }
    // An empty array is good.
    cnt_total[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= k; j++)
        {
            cnt_bad[i][j] = 0;
            // i' <=> a, j' <=> b
            for(int a = 0; a < i; a++)
                for(int b = 0; b < j; b++)
                {
                    // The only case where this incorrect addition of "bad" arrays of size $i$ occurs is when we consider good 
                    // arrays of size $i - 1$ for odd $i$ during this process. So while calculating the answer for $n$ in the 
                    // problem we just have to skip good arrays of size $n - 1$ if $n$ is odd. 
                    if(i == n && (n & 1) && a == i - 1)
                        continue;
                    // f(i, j, i', j')
                    int cur_bad = 1;
                    // The number of ways of good arrays of length $i'$ distinct positive values with exactly $j'$ bits set in total:
                    cur_bad *= (cnt_total[a][b] - cnt_bad[a][b] + MOD) % MOD;
                    cur_bad %= MOD;
                    // The number of ways of selecting $i - i'$ distinct positive values with exactly $j - j'$ bits set in total. 
                    cur_bad *= cnt_distinct_positive[i - a][j - b];
                    cur_bad %= MOD;
                    // The number of ways of distributing the $i - i'$ values among the existing good array of length $i'$:
                    cur_bad *= fast_nCr(i, a);
                    cur_bad %= MOD;
                    // The number of ways of choosing which $j'$ of the $j$ bits were from the good array.
                    cur_bad *= fast_nCr(j, b);
                    cur_bad %= MOD;
                    // The number of ways of choosing the remaining $j'$ bits of each of the $i - i'$ distinct values.
                    cur_bad *= pow2[(i - a) * b];
                    cur_bad %= MOD;
                    cnt_bad[i][j] += cur_bad;
                    cnt_bad[i][j] %= MOD;
                }
        }
    int ans = 0;
    for(int j = 0; j <= k; j++)
    {
        int cnt_good = (cnt_total[n][j] - cnt_bad[n][j] + MOD) % MOD;
        // The number of ways of choosing the j bits from the k total bits.
        ans += (fast_nCr(k, j) * cnt_good) % MOD;
        ans %= MOD;
    }
    cout << ans << "n";
    return 0;
}
```
 **Solution [c++] (antontrygubO_o)**
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
 
using namespace __gnu_pbds;
using namespace std;
 
using ll = long long;
using ld = long double;
 
typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
 
#define mp make_pair
 
int MOD;
 
int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}
 
int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}
 
int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}
 
int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}
 
int inv(int n)
{
    return po(n, MOD-2);
}
 
 
mt19937 rnd(time(0));
 
 
const int LIM = 40000;
 
vector<int> facs(LIM), invfacs(LIM);
 
vector<vector<int>> C(400, vector<int>(400));
vector<int> degs(LIM);
 
void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
 
    for (int i = 0; i<400; i++)
    for (int j = 0; j<=i; j++)
    {
        C[i][j] = mul(facs[i], mul(invfacs[j], invfacs[i-j]));
    }
    degs[0] = 1;
    for (int i = 1; i<LIM; i++) degs[i] = mul(2, degs[i-1]);
}
 
 
 
int solve1(int n, int k)
{
    vector<vector<int>> ch_diff(n+1, vector<int>(k+1));
 
    //Choose len distinct nonzero numbers from 1 to 2^k-1 such that each bit is present somewhere
 
    for (int len = 1; len<=n; len++)
    {
        for (int bits = 1; bits<=k; bits++)
        {
            int tot = sub(degs[bits], 1);
            ch_diff[len][bits] = 1;
            for (int i = 0; i<len; i++) {
                ch_diff[len][bits] = mul(ch_diff[len][bits], sub(tot, i));
            }
            //ch[len][bits] = mul(ch[len][bits], invfacs[len]);
 
            for (int bits1 = 1; bits1<bits; bits1++)
            {
                ch_diff[len][bits] = sub(ch_diff[len][bits], mul(ch_diff[len][bits1], C[bits][bits1]));
            }
        }
    }
 
    ch_diff[0][0] = 1;
 
    /*cout<<"CH_DIFF:"<<endl;
 
    for (int len = 0; len<=n; len++)
    {
        cout<<len<<": ";
        for (int bits = 0; bits<=k; bits++)
        {
            //cout<<sub(po(po(2, bits), len), dp_part[len][bits])<<' ';
            cout<<ch_diff[len][bits]<<' ';
        }
        cout<<endl;
    }*/
 
 
 
    vector<vector<int>> ch(n+1, vector<int>(k+1));
 
    //Choose len numbers from 0 to 2^k-1 such that each bit is present somewhere
 
    for (int len = 0; len<=n; len++)
    {
        for (int bits = 0; bits<=k; bits++)
        {
            ch[len][bits] = degs[bits*len];
 
            for (int bits1 = 0; bits1<bits; bits1++)
            {
                ch[len][bits] = sub(ch[len][bits], mul(ch[len][bits1], C[bits][bits1]));
            }
        }
    }
 
    /*cout<<"CH:"<<endl;
 
    for (int len = 1; len<=n; len++)
    {
        cout<<len<<": ";
        for (int bits = 0; bits<=k; bits++)
        {
            //cout<<sub(po(po(2, bits), len), dp_part[len][bits])<<' ';
            cout<<ch[len][bits]<<' ';
        }
        cout<<endl;
    }*/
 
 
    vector<vector<int>> dp_part(n+1, vector<int>(k+1));
 
    //Choose len numbers from 0 to 2^k-1 such that each bit is present somewhere and it's impossible to permutate
 
    for (int len = 1; len<=n; len++)
    {
        for (int bits = 0; bits<=k; bits++)
        {
            int ans = 0;
            for (int sz_bad = 1; sz_bad<=len; sz_bad++)
                for (int bits_bad = 1; bits_bad<=bits; bits_bad++)
                {
                    int good_rem = sub(ch[len-sz_bad][bits-bits_bad], dp_part[len-sz_bad][bits-bits_bad]);
                    //good arrays of length len-sz_bad on exactly bits-bits_bad bits
                    int adding = mul(ch_diff[sz_bad][bits_bad], good_rem);
 
                    adding = mul(adding, C[len][sz_bad]);
                    adding = mul(adding, C[bits][bits_bad]);
                    adding = mul(adding, degs[(bits-bits_bad)*sz_bad]);
                    ans = add(ans, adding);
                }
            dp_part[len][bits] = ans;
        }
    }
 
    /*cout<<"DP_PART:"<<endl;
 
    for (int len = 1; len<=n; len++)
    {
        cout<<len<<": ";
        for (int bits = 0; bits<=k; bits++)
        {
            //cout<<sub(po(po(2, bits), len), dp_part[len][bits])<<' ';
            cout<<dp_part[len][bits]<<' ';
        }
        cout<<endl;
    }*/
 
 
    int answer = 0;
 
    int min_sz_bad = 1; if (n%2==1) min_sz_bad = 2;
 
    for (int bits = 0; bits<=k; bits++)
    {
        int subans = 0;
        for (int sz_bad = min_sz_bad; sz_bad<=n; sz_bad++)
            for (int bits_bad = 1; bits_bad<=bits; bits_bad++)
            {
                int good_rem = sub(ch[n-sz_bad][bits-bits_bad], dp_part[n-sz_bad][bits-bits_bad]);
                //good arrays of length len-sz_bad on exactly bits-bits_bad bits
                int adding = mul(ch_diff[sz_bad][bits_bad], good_rem);
 
                adding = mul(adding, C[n][sz_bad]);
                adding = mul(adding, C[bits][bits_bad]);
                adding = mul(adding, degs[(bits-bits_bad)*sz_bad]);
                subans = add(subans, adding);
                //cout<<bits<<' '<<sz_bad<<' '<<bits_bad<<": "<<subans<<endl;
            }
        subans = sub(ch[n][bits], subans);
        subans = mul(subans, C[k][bits]);
        //cout<<ch[n][bits]<<' '<<subans<<endl;
        answer = add(answer, subans);
 
    }
    return answer;
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n, k; cin>>n>>k>>MOD;
    init();
    cout<<solve1(n, k)<<endl;
 
}
```
 **Solution [Kotlin] (ExplodingFreeze)**
```cpp
fun mod_expo(base: Int, pow: Int, MOD: Int): Long {
    if(pow == 0) {
        return 1;
    }
    var res = mod_expo(base, pow / 2, MOD)
    res = (res * res) % MOD
    if(pow % 2 == 1) {
        res = (res * base) % MOD;
    }
    return res;
}
 
fun mod_inv(base: Int, MOD: Int): Long {
    return mod_expo(base, MOD - 2, MOD)
}
 
fun fast_nCr(n: Int, r: Int, fact: Array<Long>, invfact: Array<Long>, MOD: Int): Long {
    val num = fact[n];
    val denom = (invfact[r] * invfact[n - r]) % MOD;
    return (num * denom) % MOD;
}
 
fun slow_nPr(n: Int, r: Int, MOD: Int): Long {
    var res = 1L;
    for(i in 1..r) {
        res *= (n - i + 1 + MOD) % MOD;
        res %= MOD;
    }
    return res;
}
 
fun main(args: Array<String>) {
    val (n, k, MOD) = readLine()!!.split(" ").map { it.toInt() }
    val fact = Array<Long>(Math.max(n, k) + 1) { 1L }
    val invfact = Array<Long>(Math.max(n, k) + 1) { 1L }
    for(i in 1..Math.max(n, k)) {
        fact[i] = (fact[i - 1] * i) % MOD
        invfact[i] = mod_inv(fact[i].toInt(), MOD)
    }
    val pow2 = Array<Long>(n * k + 1) { 1 }
    for(i in 1..n*k) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
    val cntDistinctPositive = Array(n + 1) { Array<Long>(k + 1) { 0L } }
    val cntTotal = Array(n + 1) { Array<Long>(k + 1) { 0L } }
    val cntBad = Array(n + 1) { Array<Long>(k + 1) { 0L } }
    for(i in 0..n) {
        for(j in 0..k) {
            cntDistinctPositive[i][j] = slow_nPr((mod_expo(2, j, MOD).toInt() - 1 + MOD) % MOD, i, MOD)
            cntTotal[i][j] = pow2[i * j]
            for(l in 0..j-1) {
                cntDistinctPositive[i][j] += (MOD - ((fast_nCr(j, l, fact, invfact, MOD) * cntDistinctPositive[i][l])) % MOD)
                cntDistinctPositive[i][j] = cntDistinctPositive[i][j] % MOD
                cntTotal[i][j] += (MOD - ((fast_nCr(j, l, fact, invfact, MOD) * cntTotal[i][l])) % MOD);
                cntTotal[i][j] = cntTotal[i][j] % MOD
            }
        }
    }
    cntTotal[0][0] = 1
    for(i in 1..n) {
        for(j in 0..k) {
            cntBad[i][j] = 0
             for(a in 0..i-1) {
                for(b in 0..j-1) {
                    if(i == n && n % 2 == 1 && a == i - 1) {
                        continue;
                    }
                    var curBad = (cntTotal[a][b] - cntBad[a][b] + MOD) % MOD
                    curBad *= (cntDistinctPositive[i - a][j - b])
                    curBad = curBad % MOD
                    curBad *= fast_nCr(i, a, fact, invfact, MOD)
                    curBad = curBad % MOD
                    curBad *= fast_nCr(j, b, fact, invfact, MOD)
                    curBad = curBad % MOD
                    curBad *= pow2[(i - a) * b]
                    curBad = curBad % MOD
                    cntBad[i][j] += curBad
                    cntBad[i][j] = cntBad[i][j] % MOD
                }
            }
        }
    }
    var ans = 0L
    for(j in 0..k) {
        val cntGood = (cntTotal[n][j] - cntBad[n][j] + MOD) % MOD
        ans += (fast_nCr(k, j, fact, invfact, MOD) * cntGood) % MOD
    }
    println(ans % MOD)
}
```
