# Tutorial

[1821A - Matching](../problems/A._Matching.md "Educational Codeforces Round 147 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1821A - Matching](../problems/A._Matching.md "Educational Codeforces Round 147 (Rated for Div. 2)")

In a positive integer, the first digit is from $1$ to $9$, and every next digit can be any. This allows us to implement the following combinatorial approach:

* calculate the number of different values for the first digit, which is $0$ if the first character of $s$ is 0, $1$ if the first character of $s$ is any other digit, or $9$ if the first character of $s$ is ?;
* calculate the number of different values for each of the other digits, which is $1$ if the corresponding character of $s$ is a digit, or $10$ if it is ?;
* multiply all these values.
 **Solution (BledDest)**
```cpp
  
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		string s;
		cin >> s;
		int ans = 1;
		if(s[0] == '0') ans = 0;
		if(s[0] == '?') ans = 9;
		for(int j = 1; j < s.size(); j++)
			if(s[j] == '?')
				ans *= 10;
		cout << ans << endl;
	}
}

```
[1821B - Sort the Subarray](../problems/B._Sort_the_Subarray.md "Educational Codeforces Round 147 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1821B - Sort the Subarray](../problems/B._Sort_the_Subarray.md "Educational Codeforces Round 147 (Rated for Div. 2)")

Let's find the leftmost and the rightmost position in which the arrays a and a′ differ. Since only the elements in the chosen subsegment might change, the subarray we sorted should contain these two positions.

Let's start with the subarray from the leftmost "different" position to the rightmost one, and then expand it to get the longest subarray which meets the conditions. Suppose we want to expand it to the left. Let the current left border be L; how to decide if we can make it L−1 or less? If a′L<aL−1, then we cannot include L−1 in the subarray we sort, since otherwise the order of these two elements would have changed. Otherwise, aL−1 is not greater than any element in the subarray we have chosen, so we can include it and reduce L by 1. We do this until it's impossible to reduce L further.

The same goes for the right border: we expand it to the right until we find an element which is less than the previous element, and we cannot include this element in the subarray.

 **Solution (BledDest)**
```cpp
  
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		vector<int> a1(n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a1[i]);
		int diffl = -1, diffr = -1;
		for(int j = 0; j < n; j++)
		{
			if(a[j] != a1[j])
			{
				diffr = j;
				if(diffl == -1)
					diffl = j;
			}
		}
		while(diffl > 0 && a1[diffl - 1] <= a1[diffl])
			diffl--;
		while(diffr < n - 1 && a1[diffr + 1] >= a1[diffr])
			diffr++;
		printf("%d %dn", diffl + 1, diffr + 1);
	}
}

```
[1821C - Tear It Apart](../problems/C._Tear_It_Apart.md "Educational Codeforces Round 147 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1821C - Tear It Apart](../problems/C._Tear_It_Apart.md "Educational Codeforces Round 147 (Rated for Div. 2)")

The resulting string looks like a single letter repeated a number of times. That sounds too vague. Let's fix the exact letter $c$ that will be left. Since the size of the alphabet is only $26$, we can afford that.

The letters now separate into letters $c$ and other letters. And all other letters can be treated as indistinguishable from each other. Let's make letter $c$ into a binary $1$ and any other letter into a binary $0$. Our goal is to remove all zeros from the string with the given operations.

First, notice that it doesn't help you to removes ones. If some operation contains both ones and zeros, then taking ones out of it doesn't make any zeros in it adjacent. At the same time, these ones can only help you separate adjacent zeros later.

Thus, we have some blocks of zeros, separated by the blocks of ones. We want to remove only zeros. Notice how these blocks can be solved completely independently of each other. If you solve block $1$ in $\mathit{cnt}_1$ operations, block $2$ in $\mathit{cnt}_2$ operations, ..., block $k$ in $\mathit{cnt}_k$ operations, then you can solve the entire string in $\max(\mathit{cnt}_1, \mathit{cnt}_2, \dots, \mathit{cnt}_k)$ operations. Since the blocks are separated by the blocks of ones, you can combine the first operations for all blocks into one big operation and so on.

The only thing left is to calculate the number of operations for a single block. Let it have length $l$. Basically, in one operation, you can decrease its length to $\lfloor \frac l 2 \rfloor$. You can see that the longer the block, the greater answer it has. So you can find the longest block first, then calculate the answer for it. You can either use this iterative formula or notice that it's a logarithm of $l$ in base $2$ and calculate that however you want.

To find the lengths of the blocks of zeros, you can use two pointers.

Overall complexity: $O(|\mathit{AL}| \cdot n)$ per testcase.

This problem can also be solved in $O(n \log n)$ on an arbitrarily large alphabet. Basically, when you fix a letter, you can tell the lengths of the blocks of other letters by looking at the occurrences of the letter. For occurrences $i_1, i_2, \dots, i_k$, the lengths of the blocks are $i_1 - 1, i_2 - i_1, \dots, i_k - i_{k-1}, n - i_{k}$. So we can calculate the answer for a letter in $O(\mathit{number\ of\ its\ occurrences})$. The total of that for all letters is $O(n)$.

 **Solution (awoo)**
```cpp
  
for _ in range(int(input())):
	s = input()
	n = len(s)
	ans = n
	for x in range(26):
		c = chr(x + ord('a'))
		i = 0
		cur = 0
		while i < n:
			j = i
			while j < n and (s[j] == c) == (s[i] == c):
				j += 1
			if s[i] != c:
				cur = max(cur, j - i)
			i = j
		if cur == 0:
			ans = 0
			break
		pw = 0
		while (1 << pw) <= cur:
			pw += 1
		ans = min(ans, pw)
	print(ans)

```
[1821D - Black Cells](../problems/D._Black_Cells.md "Educational Codeforces Round 147 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1821D - Black Cells](../problems/D._Black_Cells.md "Educational Codeforces Round 147 (Rated for Div. 2)")

Let's look at what's happening in the task: in the end the pointer will move into some position $p$ and some segments on the prefix $[0, p]$ will be colored. Note that it's optimal to stop only inside some segment (or $l_i \le p \le r_i$ for some $i$), and if we colored $x$ segments (including the last segment $[l_i, p]$ that may be colored partially) the answer will be equal to $p + 2 \cdot x$.

Let's prove that it's not optimal to skip segments with length $len = r[i] - l[i] + 1 \ge 2$. By contradiction, suppose the optimal answer $a$ has a skipped segment $[l_i, r_i]$. If we color that segment instead, we will make $2$ more moves for pressing and releasing Shift, but we can make at least $len$ right move less. So the new answer $a' = a + 2 - len \le a$ — the contradiction.

Now we are ready to write a solution. Let's iterate over $i$ — the last segment we will color (and therefore the segment where we stop). At first, let's imagine we colored the whole segment $[l_i, r_i]$ as well. Let $s$ be the total length of all segments on prefix $[0, r_i]$ that are longer than $1$ and $c$ be the number of segments of length $1$ on this prefix.

There are three cases: 

* if $s + c < k$, stopping inside the $i$-th segment is not enough;
* if $s < k$ but $s + c \ge k$, we will color all "long" segments plus several short ones. The current answer will be equal to $r_i + 2 ((i - c) + (k - s))$, where $r_i$ is where we stop, $(i - c)$ is the number of long segments and $(k - s)$ is the number of short segments we need;
* if $s \ge k$, then we don't need any short segments. More over, we can stop even before reaching $r_i$. So, the current answer will be equal to $r_i - (s - k) + 2 (i - c)$, where $r_i - (s - k)$ is the exact position to stop to get exactly $k$ black cells and $(i - c)$ is the number of long segments.

 Note that $i$ is $1$-indexed in calculations above, and we can stop the first moment we met the situation $s \ge k$.The answer is the minimum among the answers we've got in the process. Since it's easy to update values $s$ and $c$ when we move from $i$ to $i + 1$, the total complexity is $O(n)$.

 **Solution (adedalic)**
```cpp
  
fun main() {
    repeat(readln().toInt()) {
        val (n, k) = readln().split(' ').map { it.toInt() }
        val l = readln().split(' ').map { it.toInt() }
        val r = readln().split(' ').map { it.toInt() }

        var ans = 2e9.toInt()
        var cntShort = 0
        var lenLong = 0
        for (i in 0 until n) {
            val curLen = r[i] - l[i] + 1
            if(curLen > 1)
                lenLong += curLen
            else
                cntShort++

            if (lenLong < k) {
                if (lenLong + cntShort >= k) {
                    val cntSegs = (i + 1 - cntShort) + (k - lenLong)
                    ans = minOf(ans, r[i] + 2 * cntSegs)
                }
            }
            else {
                ans = minOf(ans, r[i] - (lenLong - k) + 2 * (i + 1 - cntShort))
                break
            }
        }
        if (ans == 2e9.toInt())
            ans = -1
        println(ans)
    }
}

```
[1821E - Rearrange Brackets](../problems/E._Rearrange_Brackets.md "Educational Codeforces Round 147 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1821E - Rearrange Brackets](../problems/E._Rearrange_Brackets.md "Educational Codeforces Round 147 (Rated for Div. 2)")

First, let's define the cost of an RBS a bit clearer. The absolute smallest cost of removing each pair of brackets is the number of bracket pairs it's inside of. That can actually be achieved — just remove the pairs right to left (according to the positions of the opening brackets in pairs). So you can instead say that the total cost is the sum of balance values after all closing brackets. Or before all opening brackets — these are actually the same.

From that, we can code a classic dp. Imagine we are not moving brackets, but instead doing that in two separate movements: put a bracket in some buffer and place it in the string. We'd love to use $\mathit{dp}[\mathit{pos}][\mathit{open}][\mathit{close}][\mathit{moves}]$ — the smallest answer if we processed $\mathit{pos}$ brackets, $\mathit{open}$ opening brackets are in the buffer, $\mathit{close}$ closing brackets in the buffer and $\mathit{moves}$ are performed. Sadly, that doesn't really allow moving brackets to the left, since you would have to first place the bracket, then put in it the buffer. Does that actually break anything? Apparently, no. You can make these buffer states from $-k$ to $k$, and think of negative values as taking a loan. These states are enough to determine the current balance of the string. Thus, enough to both update the states and check if the string stops being an RBS after placing a closing bracket. 

Overall complexity: $O(nk^3)$. 

We can do it faster, but our proof isn't that convincing.

Start by showing that there exists an optimal answer such that each move leaves the sequence an RBS. Consider a sequence of moves that ends up being an RBS. First, you can basically rearrange the moves (maybe adjusting the exact positions is required). Second, there exists a move that, performed first, leaves an RBS. Make it and propagate the proof. You can show that such a move exists by studying some cases. 

Then I found it more intuitive to switch to another representation — you can look at the forest induced by the bracket sequence. The roots of the trees in it are the topmost opening and closing brackets of the RBS. Their children are the inner topmost brackets for each of them, and so on. With that representation, the answer is actually the sum of depths of all vertices.

Now for the moves. Let's move an opening bracket to the right. We won't move it after its corresponding closing bracket to not break an RBS. How will it change the tree? It will turn some children of the corresponding vertex into the children of its parent. Thus, it will decrease their depths by one, and the depths of their descendants as well. How about to the left? That will turn some children of its parent into its own children, increasing their depths (and the depths of their descendants) by one. Similar analysis can be performed for the closing brackets. 

The claim is that, in the optimal answer, you should only move opening brackets and only to the right. Then they decrease the answer independently of each other. It's pretty clear that the best position to move each bracket to is as much to the right as possible — place it next to its respective closing bracket. That will decrease the answer by the size of the subtree (excluding the vertex itself).

Finally, we want to choose $k$ vertices that have the largest sum of their subtrees. That can be just done greedily — pick $k$ largest ones.

You don't have to build the tree explicitly for that — the size of the subtree is half of the number of brackets between an opening bracket and a corresponding closing one. So, everything can be processed with a stack.

Overall complexity: $O(n)$ or $O(n \log n)$.

 **Solution 1 (awoo)**
```cpp
  
#include <bits/stdc++.h>

using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); i++) 

const long long INF64 = 1e18;

long long dp[2][11][11][6];

int main(){
	int t;
	cin >> t;
	while (t--){
		int k;
		cin >> k;
		string s;
		cin >> s;
		int n = s.size();
		forn(balo, 2 * k + 1) forn(balc, 2 * k + 1) forn(mv, k + 1) dp[0][balo][balc][mv] = INF64;
		dp[0][k][k][0] = 0;
		int act = 0;
		forn(ii, n){
			int i = ii & 1;
			int ni = i ^ 1;
			forn(balo, 2 * k + 1) forn(balc, 2 * k + 1) forn(mv, k + 1)
				dp[ni][balo][balc][mv] = INF64;
			forn(mv, k + 1) forn(balo, 2 * k + 1) forn(balc, 2 * k + 1) if (dp[i][balo][balc][mv] != INF64){
				int bal = act - balo + balc;
				if (balo >= 0 && mv < k)
					dp[i][balo - 1][balc][mv + 1] = min(dp[i][balo - 1][balc][mv + 1], dp[i][balo][balc][mv] + bal);
				if (balc >= 0 && mv < k && bal > 0)
					dp[i][balo][balc - 1][mv + 1] = min(dp[i][balo][balc - 1][mv + 1], dp[i][balo][balc][mv]);
				if (s[ii] == '('){
					dp[ni][balo][balc][mv] = min(dp[ni][balo][balc][mv], dp[i][balo][balc][mv] + bal);
					if (balo + 1 <= 2 * k)
						dp[ni][balo + 1][balc][mv] = min(dp[ni][balo + 1][balc][mv], dp[i][balo][balc][mv]);
				}
				else{
					if (bal > 0)
						dp[ni][balo][balc][mv] = min(dp[ni][balo][balc][mv], dp[i][balo][balc][mv]);
					if (balc + 1 <= 2 * k)
						dp[ni][balo][balc + 1][mv] = min(dp[ni][balo][balc + 1][mv], dp[i][balo][balc][mv]);
				}
			}
			act += (s[ii] == '(' ? 1 : -1);
		}
		printf("%lldn", *min_element(dp[n & 1][k][k], dp[n & 1][k][k] + k + 1));
	}
}

```
 **Solution 2 (awoo)**
```cpp
  
for _ in range(int(input())):
	k = int(input())
	s = input()
	n = len(s)
	st = []
	cnt = [0 for i in range(n + 1)]
	ans = 0
	for i in range(n):
		if s[i] == '(':
			ans += len(st)
			st.append(i)
		else:
			cnt[(i - st.pop()) // 2] += 1
	for i in range(n, -1, -1):
		t = min(k, cnt[i])
		ans -= t * i
		k -= t
	print(ans)

```
[1821F - Timber](../problems/F._Timber.md "Educational Codeforces Round 147 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1821F - Timber](../problems/F._Timber.md "Educational Codeforces Round 147 (Rated for Div. 2)")

People say that this problem can be bashed with generating functions. Sadly, I know nothing about them, so I'll explain the more adhoc solution I managed to come up.

Let's investigate the general form of some placement of trees. Imagine we fixed some position $x_1, x_2, \dots, x_m$ for them. How to check if it's possible to cut them all down? Well, it's a simple greedy problem. Process trees left to right. If a tree can fall down to the left, make it fall to the left. Otherwise, if it can fall down to the right, make it fall to the right. Otherwise, no answer.

Try a harder problem. Consider the spots the fallen trees take. How many constructions can these spots be induced by after the greedy algorithm is performed? First, these taken spots are actually segments of length $k+1$. Each tree can fall either from the left or the right side of the segment. To determine the answer, one has to look at the number of free spots to the left of each fallen tree. If there're at least $k$ free spots, then the tree can only fall from the left side of that segment. Otherwise, it can fall both ways. Thus, for $x$ trees that have less than $k$ free spots to the left of them, the answer is $2^x$.

We can't really iterate over the constructions, so let's try yet another related problem. Would be cool if we could fix the exact number of trees that have more than $k$ free cells to the left of them. I don't really know how to do that. But I know how to fix at least the amount. Let that be at least $x$ trees. For $x$ trees, make their segments of length $2k+1$ — $k+1$ for the tree itself and $k$ extra cells to the left of it. For the rest $m-x$ trees, make their segments of length $k+1$. Then we have to place them on the given $n$ spots. The path is as follows. Rearrange the long and the short segments among each other — $\binom{m}{x}$. Then use stars and bars to choose the amount of space between the segments — $\binom{n-x\cdot(2k+1)-(m-x)\cdot(k+1)+m}{m}$. Finally, multiply by $2^{m-x}$ to fix the side for the short segments.

Initially, we thought that we could just use PIE to calculate the exact answer from that — $\sum\limits_{x=0}^m f(x) \cdot (-1)^x$. And the results of this formula coincided with the naive solution, so we thought that everything should be fine. But unfortunately, even though the formula is right, using PIE in the described way is incorrect. Let us show you the correct way.

Let $F(x)$ be the number of ways to choose the segments for the trees in such a way that $x$ fixed segments are "long" (i. e. at least of length $2k+1$). To calculate $F(x)$, we use the familiar stars and bars concept: $\binom{n-x\cdot(2k+1)-(m-x)\cdot(k+1)+m}{m}$ (we already had this formula earlier).

Now, let $G(x)$ be the number of ways to choose the segments for the trees in such a way that $x$ fixed segments are "long", and all other segments are "short". The formula for $G(x)$ is a straightforward application of PIE: $G(x) = \sum\limits_{y=0}^{m-x} (-1)^y \binom{m-x}{y} F(x+y)$, where we iterate on $y$ — the number of segments that should be short, but are definitely long.

The answer to the problem can be calculated as $\sum\limits_{x=0}^{m} 2^{m-x} \binom{m}{x} G(x)$ — we choose which $x$ segments are "long", and all others should be "short". Expanding $G(x)$ gives us the following formula:

$$\sum\limits_{x=0}^m \sum\limits_{y=0}^{m-x} (-1)^y 2^{m-x} \binom{m}{x} \binom{m-x}{y} F(x+y)$$

which, after expanding binomial coefficients into factorials and getting rid of $(m-x)!$, becomes

$$\sum\limits_{x=0}^m \sum\limits_{y=0}^{m-x} (-1)^y 2^{m-x} \frac{m!}{x! y! (m-x-y)!} F(x+y)$$

We introduce the substitution variable $z = x + y$, and the formula becomes

$$\sum\limits_{z=0}^m \sum\limits_{y=0}^{z} (-1)^y 2^{m-z+y} \frac{m!}{(z-y)! y! (m-z)!} F(z)$$

By multiplying both the numerator and the denominator by $z!$, we then get

$$\sum\limits_{z=0}^m \sum\limits_{y=0}^{z} (-1)^y 2^{m-z+y} \binom{m}{z} \binom{z}{y} F(z)$$

$$\sum\limits_{z=0}^m \binom{m}{z} 2^{m-z} F(z) \sum\limits_{y=0}^{z} (-2)^y \binom{z}{y} F(z)$$

And $\sum\limits_{y=0}^{z} (-2)^y \binom{z}{y}$ is just $(1-2)^z$. Thus, the answer is equal to $\sum\limits_{z=0}^m (-1)^z \binom{m}{z} 2^{m-z} F(z)$.

Overall complexity: $O(n)$. 

 **Solution (awoo)**
```cpp
  
#include <bits/stdc++.h>
 
using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

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

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	
	vector<int> fact(2 * n + 1), rfact(2 * n + 1);
	fact[0] = 1;
	for (int i = 1; i <= 2 * n; ++i) fact[i] = mul(fact[i - 1], i);
	rfact[2 * n] = binpow(fact[2 * n], MOD - 2);
	for (int i = 2 * n - 1; i >= 0; --i) rfact[i] = mul(rfact[i + 1], i + 1);
	auto cnk = [&](int n, int k){
		if (k < 0 || n < 0 || k > n) return 0;
		return mul(fact[n], mul(rfact[k], rfact[n - k]));
	};
	auto snb = [&](int n, int k){
		return cnk(n + k, k);
	};
	
	int pw2 = 1;
	int ans = 0;
	for (int i = m; i >= 0; --i){
		int cur = 0;
		if (n - (m - i) * 1ll * (k + 1) - i * 1ll * (2 * k + 1) >= 0)
			cur = mul(snb(n - (m - i) * (k + 1) - i * (2 * k + 1), m), mul(pw2, cnk(m, i)));
		ans = add(ans, i & 1 ? -cur : cur);
		pw2 = mul(pw2, 2);
	}
	
	printf("%dn", ans);
}

```
