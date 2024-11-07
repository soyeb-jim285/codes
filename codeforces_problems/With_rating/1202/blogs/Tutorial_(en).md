# Tutorial_(en)

[1202A - You Are Given Two Binary Strings...](../problems/A._You_Are_Given_Two_Binary_Strings....md "Educational Codeforces Round 70 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1202A - You Are Given Two Binary Strings...](../problems/A._You_Are_Given_Two_Binary_Strings....md "Educational Codeforces Round 70 (Rated for Div. 2)")

Multiplying by power of $2$ is "shift left" binary operation (you, probably, should know it). Reverse $x$ and $y$ for the simplicity and look at leftmost $1$ in $y$ (let's denote its position as $pos_y$).

If you move it to $0$ in $x$ then you make the $rev_k$ lexicographically bigger than the reverse of $x$. So you should move it to $1$ in $x$ too. You can choose any $1$ with position $\ge pos_y$.

Let $pos_x$ be the minimum position of $1$ in $x$, such that $pos_x \ge pos_y$. You must move $pos_y$ to $pos_x$, otherwise the $1$ in $pos_x$ still be present in $rev_k$ and it will be not optimal.

So, the solution is next: reverse $x$ and $y$, find $pos_y$, find $pos_x \ge pos_y$, print $pos_x - pos_y$.

 **Solution (adedalic)**
```cpp
fun main(args: Array<String>) {
    val T = readLine()!!.toInt()
    for (tc in 1..T) {
        val x = readLine()!!.reversed()
        val y = readLine()!!.reversed()

        val posY = y.indexOf('1')
        val posX = x.indexOf('1', posY)
        println(posX - posY)
    }
}
```
[1202B - You Are Given a Decimal String...](../problems/B._You_Are_Given_a_Decimal_String....md "Educational Codeforces Round 70 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1202B - You Are Given a Decimal String...](../problems/B._You_Are_Given_a_Decimal_String....md "Educational Codeforces Round 70 (Rated for Div. 2)")

All you need to know to solve this task is the minimal number of steps to move from any digit $a$ to any digit $b$ for fixed $x$ and $y$ (let's denote it as $ds[a][b]$). Shortest path? BFS? Floyd? Of course, you can use it, but you can think a little harder and save nerves and time.

Since order of choosing operations $x$ and $y$ doesn't matter for transferring from $a$ to $b$, so only number of $x$-s and $y$-s are matter. Let's denote them as $cnt_x$ and $cnt_y$. Since adding any fixed value $10$ times are meaningless, so $cnt_x, cnt_y < 10$.

Now you can, for each $x < 10$, for each $y < 10$, for each $a < 10$ iterate over all possible $cnt_x < 10$ and $cnt_y < 10$. Digit $b$ you'd move to is equal to $(a + cnt_x \cdot x + cnt_y \cdot y) \mod 10$. Just relax value of $ds[a][b]$ by $cnt_x + cnt_y$.

Now you can, for each $x$ and $y$, calculate the answer by iterating over string $s$ by summing $ds[s[i]][s[i + 1]] - 1$ (number of inserted values is less by one than number of steps).

But, it will work only in C++, since the language is fast and $2 \cdot 10^8$ basic operations are executed in less than 0.5 second. 

But the model solution is written in Kotlin. How is it? The string $s$ can be long, but there are only $10 \times 10$ different neighbouring digits, so you can just one time precalculate $cf[a][b]$ — the number of such $i$ that $s[i] = a$ and $s[i + 1] = b$. And calculate the answer not by iterating over $s$ but by multiplying $ds[a][b]$ by $cf[a][b]$.

The result complexity is $O(|s| + A^5)$, where $A = 10$. But $O(A^2(n + A^3))$ will pass on fast languages like C++.

P.S.: There are no real problem with I/O — both Python and Kotlin read one string up to $2 \cdot 10^6$ in less than 0.5 seconds.

 **Solution (adedalic)**
```cpp
const val INF = 1e9.toInt()

fun main(args: Array<String>) {
    val s = readLine()!!.map { it - '0' }
    val cf = Array(10) {Array(10) {0}}
    for (i in 1 until s.size)
        cf[s[i - 1]][s[i]]++

    for (x in 0..9) {
        for (y in 0..9) {
            val ds = Array(10) {Array(10) {INF + 7}}

            for (v in 0..9) {
                for (cx in 0..9) {
                    for (cy in 0..9) {
                        if (cx + cy == 0)
                            continue

                        val to = (v + cx * x + cy * y) % 10
                        ds[v][to] = minOf(ds[v][to], cx + cy)
                    }
                }
            }

            var res = 0
            for (v in 0..9) {
                for (to in 0..9) {
                    if (ds[v][to] > INF && cf[v][to] > 0) {
                        res = -1
                        break
                    }
                    res += (ds[v][to] - 1) * cf[v][to]
                }
                if (res == -1)
                    break
            }

            print("$res ")
        }
        println()
    }
}
```
[1202C - You Are Given a WASD-string...](../problems/C._You_Are_Given_a_WASD-string....md "Educational Codeforces Round 70 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1202C - You Are Given a WASD-string...](../problems/C._You_Are_Given_a_WASD-string....md "Educational Codeforces Round 70 (Rated for Div. 2)")

The problem asks us to maintain the bounding box while inserting the character of one of $4$ types between every adjacent characters in $s$. Of course, we can do it, but do we really need to do it in such cumbersome way? 

Let's think a little. Inserting 'W' or 'S' doesn't affect the width of the bounding box, and 'A' or 'D' doesn't affect the height. So, they are absolutely independent! And we can divide our WASD-string on WS-string and AD-string. Moreover, inserting 'W' or 'S' in WS-string and 'A' or 'D' in AD-string is almost same thing, so we don't even need to write different code for different string!

How to handle only WS-string? Let's replace 'W' as $+1$ and 'S' as $-1$ and suppose that we started in position $0$. Then the position, where we go after $i$ commands, is just prefix sum of first $i$ elements ($i \ge 0$). Then the length of the bounding box is (maximum position - minimum position + 1). The maximum (minimum) position is a maximum (minimum) element in array of prefix sums $pSum$.

What the inserted value do? It add $\pm 1$ to suffix of $pSum$. Let's choose, for example, $+1$. The $+1$ can't decrease the maximum, but can increase the minimum, so we need to place it somewhere before all minimums in $pSum$ (or before the first minimum). But, if we place it before any of maximum elements then we will increase it and prevent decreasing the length of bounding box. So we need to place $+1$ somewhere after all maximums on $pSum$ (or after the last maximum). And here goes the solution: find position $firstMin$ of the first minimum in $pSum$ and position $lastMax$ of the last maximum. If $lastMax < firstMin$ then we can insert $+1$ and decrease the length of bounding box (but, since, we insert command that move robot, we can't achieve bounding box of length $< 2$).

What to do with $-1$? Just multiply $pSum$ by $-1$ and now we can insert $+1$ instead of $-1$ in absolutely same manner.

What to do with AD-string? Denote 'A' as $+1$ and 'D' as $-1$ and everything is absolutely the same.

 **Solution (adedalic)**
```cpp
const val INF = 1e9.toInt()

fun main(args: Array<String>) {
    val T = readLine()!!.toInt()
    for (tc in 1..T) {
        val s = readLine()!!
        val alp = arrayOf("WS", "AD")
        val aDir = arrayOf(
                s.filter { alp[0].indexOf(it) != -1 },
                s.filter { alp[1].indexOf(it) != -1 }
        )

        val baseW = arrayOf(INF, INF)
        val bestW = arrayOf(INF, INF)

        for (k in 0..1) {
            val pSum = arrayListOf(0)
            for (c in aDir[k]) {
                val add = if (c == alp[k][0]) +1 else -1
                pSum.add(pSum.last() + add)
            }

            for (tp in 0..1) {
                val firstMin = pSum.withIndex().minBy { it.value }!!.index
                val lastMax = pSum.withIndex().reversed().maxBy { it.value }!!.index

                val curBase = pSum[lastMax] - pSum[firstMin] + 1
                var curBest = curBase
                if (curBase > 2 && lastMax < firstMin)
                    --curBest

                baseW[k] = minOf(baseW[k], curBase)
                bestW[k] = minOf(bestW[k], curBest)

                for (i in pSum.indices)
                    pSum[i] = -pSum[i]
            }
        }

        println("${minOf(baseW[0] * 1L * bestW[1], baseW[1] * 1L * bestW[0] )}")
    }
}
```
[1202D - Print a 1337-string...](../problems/D._Print_a_1337-string....md "Educational Codeforces Round 70 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1202D - Print a 1337-string...](../problems/D._Print_a_1337-string....md "Educational Codeforces Round 70 (Rated for Div. 2)")

Let's consider the following string $1333 \dots 3337$. If digit $3$ occurs $x$ times in it, then string have $\frac{x (x-1)}{2}$ subsequences $1337$. 

Let's increase the number of digits $3$ in this string while condition $\frac{x (x-1)}{2} \le n$ holds ($x$ is the number of digits $3$ in this string). The length of this string will not exceed $45000$ because $\frac{45000 (45000-1)}{2} > 10^9$. The value $rem = n - \frac{x (x-1)}{2}$ will not exceed $45000$ as well.

All we have to do is increase the number of subsequences $1337$ in the current string by $rem$. So if we add $rem$ digits $7$ after the first two digits $3$ we increase the number of subsequences $1337$ by $rem$. The string $s$ will look like this: $133{77 \dots 77}{33 \dots 33}7$, where sequence ${77\dots77}$ consists of exactly $rem$ digits $7$ and sequence ${33\dots33}$ consists of exactly $x-2$ digits $3$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int tc = 0; tc < t; ++tc){
    	int n;
    	cin >> n;
    	int len = 2;
    	while(len * (len + 1) / 2 <= n)
    		++len;
    
    	n -= len * (len - 1) / 2;
    	assert(n >= 0);
    	assert(n <= 45000);
    	
    	string s = "133";
    	while(n > 0){
    		--n;
    		s += "7";
    	}
    
    	len -= 2;
    	while(len > 0){
    		--len;
    		s += "3";
    	}
    	s += "7";
    	cout << s << endl;
    }
	return 0;
} 
```
[1202E - You Are Given Some Strings...](../problems/E._You_Are_Given_Some_Strings....md "Educational Codeforces Round 70 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1202E - You Are Given Some Strings...](../problems/E._You_Are_Given_Some_Strings....md "Educational Codeforces Round 70 (Rated for Div. 2)")

Let's look at any occurrence of arbitrary pair $s_i + s_j$. There is exactly one special split position, where the $s_i$ ends and $s_j$ starts. So, instead of counting occurrences for each pair, we can iterate over the position of split and count the number of pairs. This transformation is convenient, since any $s_i$, which ends in split position can be paired with any $s_j$ which starts here. 

So, all we need is to calculate for each suffix the number of strings $s_i$, which starts here, and for each prefix — the number of strings $s_i$, which ends here. But calculating the prefixes can be transformed to calculating suffixes by reversing both $t$ and all $s_i$.

Now we need, for each position $pos$, calculate the number of strings $s_i$ which occur from $pos$. It can be done by Aho-Corasick, Suffix Array, Suffix Automaton, Suffix Tree, but do we really need them since constrains are pretty low? The answer is NO. We can use sqrt-heuristic!

Let's divide all $s_i$ in two groups: short and long. The $s_i$ is short if $|s_i| \le MAG$. There are no more than $\frac{\sum{|s_i|}}{MAG}$ long strings and, for each such string, we can find all its occurrences with z-function (or prefix-function). It will cost as $O(\frac{\sum{|s_i|}}{MAG} \cdot |t| + \sum{|s_i|})$.

What to do with short strings? Let's add them to trie! The trie will have $O(\sum{|s_i|})$ vertices, but only $MAG$ depth. So we can, for each $pos$, move down through the trie, while counting the occurrences, using only $s[pos..(pos + MAG)]$ substring. It will cost us $O(|t| \cdot MAG)$.

So, if we choose $MAG = \sqrt{\sum{|s_i|}}$ we can acquire $O(\sum{|s_i|} + |t| \sqrt{\sum{|s_i|}})$ complexity, using only basic string structures.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

const int INF = int(1e9) + 7;
const li INF64 = li(1e18) + 7;

const int N = 500005;
const int A = 27;
const int MAG = 500;

struct node {
    node *to[A];
    int cnt;
} nodes[N];
int szn = 0;

typedef node* vt;

vt getNode() {
    assert(szn < N);
    fore(i, 0, A)
        nodes[szn].to[i] = NULL;
    nodes[szn].cnt = 0;
    return &nodes[szn++];
}

void addWord(vt v, const string &s) {
    fore(i, 0, sz(s)) {
        int c = s[i] - 'a';
        if (!v->to[c])
            v->to[c] = getNode();
        v = v->to[c];
    }
    v->cnt++;
}

int calcCnt(vt v, const string &s, int pos) {
    assert(v->cnt == 0);
    int ans = 0;
    while(pos < sz(s)) {
        int c = s[pos] - 'a';
        if (!v->to[c])
            break;
        v = v->to[c];
        ans += v->cnt;
        pos++;
    }
    return ans;
}

vector<int> zf(string s) {
    vector<int> z(sz(s), 0);
    for (int i = 1, l = 0, r = 0; i < sz(s); ++i) {
        if(i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < sz(s) && s[i + z[i]] == s[z[i]])
            z[i]++;

        if(i + z[i] > r)
            l = i, r = i + z[i];
    }
    return z;
}

string t;
int n;
vector<string> s;

inline bool read() {
    if(!(cin >> t))
        return false;
    cin >> n;
    s.resize(n);
    fore(i, 0, n)
        cin >> s[i];
    return true;
}

inline void solve() {
    vector<int> cnt[2];
    fore(k, 0, 2) {
        cnt[k].assign(sz(t) + 1, 0);
        szn = 0;
        vt root = getNode();

        forn(i, n) {
            if (sz(s[i]) > MAG) {
                auto z = zf(s[i] + t);
                fore(j, 0, sz(t))
                    cnt[k][j] += (z[sz(s[i]) + j] >= sz(s[i]));
            } else {
                addWord(root, s[i]);
            }
        }

        fore(i, 0, sz(t))
            cnt[k][i] += calcCnt(root, t, i);

        reverse(all(t));
        fore(i, 0, n)
            reverse(all(s[i]));
    }

    li ans = 0;
    fore(i, 0, sz(t) + 1)
        ans += cnt[0][i] * 1ll * cnt[1][sz(t) - i];
    cout << ans << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cerr << fixed << setprecision(15);

    if(read()) {
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}
```
[1202F - You Are Given Some Letters...](../problems/F._You_Are_Given_Some_Letters....md "Educational Codeforces Round 70 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1202F - You Are Given Some Letters...](../problems/F._You_Are_Given_Some_Letters....md "Educational Codeforces Round 70 (Rated for Div. 2)")

Let's introduce the slightly naive solution. Iterate over all values for periods and check the possibility of each one being correct.

The conditions for some period $k$ can be formulated the following way. $g = n / k$ ($n = a + b$ is the total length of the string) is the number of full periods of length $k$. Let's find at least one such pair $cnt_a$ and $cnt_b$ such that $cnt_a + cnt_b = x$ and the remainder part of the string can be filled with $a - cnt_a \cdot g$ letters 'A' and $b - cnt_b \cdot g$ letters 'B'. By easy construction one can deduce that the conditions of $a - cnt_a \cdot g \le cnt_a$ and $b - cnt_b \cdot g \le cnt_b$ are enough. Thus $cnt_a$ should be greater or equal to $\frac{a}{g + 1}$ and $cnt_b \ge \frac{b}{g + 1}$.

In order to move to the faster solution one should also remember that both remainder parts $a - cnt_a \cdot g$ and $b - cnt_b \cdot g$ should be non-negative.

Let's learn how to solve the problem for the whole range of lengths which all have the number of full periods equal to the same value $g$. Let this range be $[l; r]$. From the aforementioned formulas one can notice that the restrictions on both $cnt_a$ and $cnt_b$ don't depend on the length itself but only on value of $g$. To be more specific:

$$\frac{a}{g + 1} \le cnt_a \le \frac{a}{g}$$ $$\frac{b}{g + 1} \le cnt_b \le \frac{b}{g}$$

The lowest and the highest values for $cnt_a$ and $cnt_b$ will be the following:

$$a_{low} = \lceil \frac{a}{g + 1} \rceil$$ $$a_{high} = \lfloor \frac{a}{g} \rfloor$$ $$b_{low} = \lceil \frac{b}{g + 1} \rceil$$ $$b_{high} = \lfloor \frac{b}{g} \rfloor$$

It is claimed that every value between $a_{low} + b_{low}$ and $a_{high} + b_{high}$ exists if the values are valid ($a_{low} \le a_{high}$ and $b_{low} \le b_{high}$).

The full proof about the given conditions being sufficient and the existence of every value on that range is left to the reader. Some kind of a hint might be the suggestion to check how the inequalities change on the transition from some period $k$ to $k + 1$.

Restrict the values by $l$ and $r$ to count each answer on exactly one range of lengths. Finally, the value of $min(r, a_{high} + b_{high}) - max(l, a_{low} + b_{low}) + 1$ is added to the answer.

The number of ranges with the same $g$ is $O(\sqrt n)$.

Overall complexity: $O(\sqrt n)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	
	int n = a + b;
	int ans = 0;
	int l = 1;
	while (l <= n){
		int g = n / l;
		
		if (a < g || b < g){
			l = n / g + 1;
			continue;
		}
		
		int r = n / g;
		
		int a_low = (a + g) / (g + 1);
		int a_high = a / g;
		int b_low = (b + g) / (g + 1);
		int b_high = b / g;
		
		if (a_low <= a_high && b_low <= b_high)
			ans += max(0, min(r, a_high + b_high) - max(l, a_low + b_low) + 1);
		l = r + 1;
	}
	
	printf("%dn", ans);
}
```
