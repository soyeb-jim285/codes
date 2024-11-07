# Tutorial_(en)

[1823A - A-characteristic](../problems/A._A-characteristic.md "Codeforces Round 868 (Div. 2)")

 **Editorial**
### [1823A - A-characteristic](../problems/A._A-characteristic.md "Codeforces Round 868 (Div. 2)")

Note that the $A$-characteristic depends only on the number of $1$-s. Let the number of $1$-s be equal to $x$, then the number of $-1$-s is equal to $n - x$, and the $A$-characteristic is equal to $f(x) = \frac{(x - 1) \cdot x}{ 2} + \frac{(n - x - 1) \cdot (n - x)}{2}$.

Let's iterate over all $x$ from $0$ to $n$, and check if there is such $x$ that $f(x) = k$. Then print $x$ numbers $1$ and $n - x$ numbers $-1$.

 **Solution C++**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k, x = -1;
        cin >> n >> k;
        for (int i = 0; i <= n; i++) {
            if (i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2 == k) {
                x = i;
            }
        }
        if (x == -1)
            cout << "NOn";
        else {
            cout << "YESn";
            for (int i = 0; i < n; i++) {
                if (i < x)
                    cout << 1 << ' ';
                else
                    cout << -1 << ' ';
            }
            cout << 'n';
        }
    }

    return 0;
}
```
 **Solution Python**
```cpp
for tt in range(int(input())):
    n, k = map(int, input().split())
    x = -1

    for i in range(0, n + 1):
        if i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2 == k:
            x = i

    if x == -1:
        print("NO")
    else:
        print("YES")
        for i in range(0, n):
            if i < x:
                print("1 ", end = '')
            else:
                print("-1 ", end = '')
        print("")
```
[1823B - Sort with Step](../problems/B._Sort_with_Step.md "Codeforces Round 868 (Div. 2)")

 **Editorial**
### [1823B - Sort with Step](../problems/B._Sort_with_Step.md "Codeforces Round 868 (Div. 2)")

Let's fix a number $0 \le x < k$ and consider all indices $i$ such that $i \bmod k = x$. Note that numbers in these positions can be reordered however we want, but they can't leave this set of positions, since $i \bmod k$ stay the same. Moreover, in the sorted permutation these positions must contain numbers $j$ such that $(j - 1) \bmod k = x$. In total, itm means that the permutation can be sorted if $(p[i] - 1) \bmod k = i \bmod k$ holds for all $i$.

By preliminary exchange, we can swap two elements from different sets. Therefore, if the last equality fails for exactly two elements, they can be swapped, making sorting possible. Otherwise, the answer is $-1$.

 **Solution C++**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector <int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }

        int bad = 0;
        for (int i=0; i<n; i++) {
            if (p[i] % k != i % k) {
                bad++;
            }
        }

        if(bad == 0)
            cout << 0 << 'n';
        else if(bad == 2)
            cout << 1 << 'n';
        else
            cout << -1 << 'n';
    }

    return 0;
}
```
 **Solution Python**
```cpp
for tt in range(int(input())):
    n, k = map(int, input().split())
    p = list(map(int, input().split()))
    for i in range(0, n):
        p[i] -= 1

    bad = 0
    for i in range(0, n):
        if p[i] % k != i % k:
            bad += 1

    if bad == 0:
        print(0)
    elif bad == 2:
        print(1)
    else:
        print(-1)
```
[1823C - Strongly Composite](../problems/C._Strongly_Composite.md "Codeforces Round 868 (Div. 2)")

 **Editorial**
### [1823C - Strongly Composite](../problems/C._Strongly_Composite.md "Codeforces Round 868 (Div. 2)")

Let's understand criteria for a number $x$ being strongly composite. Let's factorize the number $x = {p_1}^{d_1} \cdot {p_2}^{d_2} \cdot \dots \cdot {p_m}^{d_m}$. The number of all divisors of $x$ is $D = \prod\limits_{i = 1}^{m} (d_i + 1)$.

Since the number of prime divisors is $m$, then the number of composite divisors of $x$ is $D - m - 1$. Then a number $x$ is strongly composite if $m \le D - m - 1$ or $2 \cdot m + 1 \le D$. Since $m$ is the number of $d_i + 1 \ge 2$, then $D \ge 2^m$.

Consider a weakened condition for a strongly composite number: $2 \cdot m + 1 \le 2^m$. If $m = 1$, then the condition is satisfied only if $d_1 \ge 2$. If $m = 2$, then the condition is satisfied only if $\max{(d_1, d_2)} \ge 2$. If $m \ge 3$, then the condition is always satisfied.

In summary, a number is not strongly composite if it is either a prime or the product of two distinct primes.

Now let's solve the problem. Let's split all numbers into primes. Assume we have pairs $(p_i, c_i)$, where $p_i$ is a prime number and $c_i$ is the number of its occurrences. We can take either two same prime numbers or three of any prime numbers. 

The optimal strategy is to create the maximum number of pairs of same prime numbers $\sum\limits_i{\left\lfloor \frac{c_i}{2} \right\rfloor}$, and when there will be only $r = \sum\limits_i{(c_i \bmod 2)}$ different prime numbers remaining. We can merge these remaining primes in triples to get extra $\left\lfloor \frac{r}{3} \right\rfloor$ strongly composite numbers.

If, after merging triples, we have some primes left, we can add them to any already strongly composite number, and it won't change its total number.

 **Solution C++**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        map <int,int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (int j = 2; j * j <= x; j++) {
                while (x % j == 0) {
                    x /= j;
                    a[j]++;
                }
            }
            if (x != 1) {
                a[x]++;
            }
        }

        int res = 0, rem = 0;

        for (pair <int, int> p : a) {
            int num = p.first;
            int cnt = p.second;
            res += cnt / 2;
            rem += cnt % 2;
        }

        res += rem / 3;
        cout << res << 'n';
    }

    return 0;
}
```
 **Solution Python**
```cpp
def is_prime(x):
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i += 1
    return True

def is_strongly_composite(x):
    m = []
    i = 2
    while i * i <= x:
        while x % i == 0:
            x = x // i
            m.append(i)
        i += 1
    if not x == 1:
        m.append(i)
    return (len(m) >= 3 or (len(m) == 2 and m[0] == m[1]))

for tt in range(int(input())):
    n = int(input())
    lst = list(map(int, input().split()))
    a = {}
    for x in lst:
        i = 2
        while i * i <= x:
            while x % i == 0:
                x = x // i
                if i in a:
                    a[i] += 1
                else:
                    a[i] = 1
            i += 1
        if x != 1:
            if x in a:
                a[x] += 1
            else:
                a[x] = 1

    res, rem = 0, 0

    for num in a:
        cnt = a[num]
        res += cnt // 2
        rem += cnt % 2

    res += rem // 3
    print(res)
```
 **Notes**There were initially more complex version of this task. Can you solve it?

You are given n integers a1,a2,…,an (ai>1). You can perform the following operation with array a any number of times:

 1. choose two indices i and j (i<j);
2. erase elements ai and aj from a;
3. insert element ai⋅aj in a.

After performing one such operation, the length of a decreases by one.

Let's say that array a is good, if it contains only strongly composite numbers.

What is the minimum number of operation you need to perform to make array a good?

[1823D - Unique Palindromes](../problems/D._Unique_Palindromes.md "Codeforces Round 868 (Div. 2)")

 **Editorial**
### [1823D - Unique Palindromes](../problems/D._Unique_Palindromes.md "Codeforces Round 868 (Div. 2)")

Let us estimate the possible number of unique palindromes $P$: 

* for $n = 1$: $P = 1$;
* for $n = 2$: $P = 2$ (in both cases: if symbols are equal and if not);
* for $n \ge 3$: $3 \le P \le n$. Any combination of the first three characters gives $P = 3$. If you add a character to the string, $P$ will increase by either $0$ or $1$. This can be proven by contradiction. Assume $P_{new} - P_{old} \ge 2$. Choose $2$ of any new palindromes. The shorter one is both a suffix and a prefix of the larger one (since both are palindromes), but we've added all the palindromes. So the smaller one was added earlier.
	+ An example of a string with $P = 3$: abcabc....
	+ An example of a string with $P = n$: aaaaaa....

 For solving the task for only one condition $k = 1$, let's combine the ideas: let's build a string aaa...aaabcabc...By choosing the prefix of appropriate length that consists of a characters, we can achieve all the values of $3 \le P \le n$. Print $k - 3$ characters a and then characters abc until the end of the string.

Let solve the initial task for $k > 1$ conditions. Firstly, we build the answer for the first condition. After that, assume we have answer for first $t$ conditions. If $c_{t + 1} - c_{t} > x_{t + 1} - x_{t}$, then we can't build an answer by lemma. Otherwise, we can do the following: take a symbol, that wasn't used and append it $c_{t + 1} - c_{t}$ times to answer; then append symbols ...abcabca.... The final string will look as following, where | symbol shows conditions boundaries: 

 aaaaaaaaabcabcab|dddddcabcabca|eeebcab Note that, in order not to create unnecessary palindromes, if we finished the previous abcabc... block with some character (for example, a), the next abcabc... block should start with the next character (b).

 **Solution C++**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector <int> x(k), c(k);
        for (int i = 0; i < k; i++)
            cin >> x[i];
        for (int i = 0; i < k; i++)
            cin >> c[i];

        if (c[0] < 3 || c[0] > x[0]) {
            cout << "NOn";
            continue;
        }

        string s;

        char cur = 'a';
        for (int i = 0; i < c[0] - 3; i++)
            s.push_back('a');

        for (int i = c[0] - 3; i < x[0]; i++) {
            s.push_back(cur);
            cur++;
            if (cur == 'd') cur = 'a';
        }

        bool good = true;
        for (int j = 1; j < k; j++) {
            int dx = x[j] - x[j - 1];
            int dc = c[j] - c[j - 1];
            if (dc > dx) {
                good = false;
                break;
            }

            for (int i = 0; i < dc; i++)
                s.push_back('c' + j);
            for (int i = dc; i < dx; i++) {
                s.push_back(cur);
                cur++;
                if (cur == 'd') cur = 'a';
            }
        }

        if (good)
            cout << "YES" << endl << s << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
```
 **Solution Python**
```cpp
for tt in range(int(input())):
    n, k = map(int, input().split())
    x = list(map(int, input().split()))
    c = list(map(int, input().split()))

    if c[0] < 3 or c[0] > x[0]:
        print("NO")
        continue

    s = ""
    cur = 'a'

    for i in range(0, c[0] - 3):
        s += "a"

    for i in range(c[0] - 3, x[0]):
        s += cur
        cur = chr(ord(cur) + 1)
        if cur == 'd':
            cur = 'a'

    good = True
    for j in range(1, k):
        dx = x[j] - x[j - 1]
        dc = c[j] - c[j - 1]
        if dc > dx:
            good = False
            break

        for i in range(0, dc):
            s += chr(ord('c') + j)
        for i in range(dc, dx):
            s += cur
            cur = chr(ord(cur) + 1)
            if cur == 'd':
                cur = 'a'

    if good:
        print("YES")
        print(s)
    else:
        print("NO")
```
 **Notes**There were initially simpler version of this problem with k=1, but it coincided with other problem.

Also, how does checker in this problem works?

[1823E - Removing Graph](../problems/E._Removing_Graph.md "Codeforces Round 868 (Div. 2)")

 **Editorial**
### [1823E - Removing Graph](../problems/E._Removing_Graph.md "Codeforces Round 868 (Div. 2)")

The solution requires knowledge of the Sprague-Grundy theory. Recall that $a \oplus b$ means the bitwise exclusive or operation, and $\operatorname{mex}(S)$ is equal to the minimum non-negative number that is not in the set $S$.

The fact that $l \neq r$ is important.

The given graph is a set of cycles, and the game runs independently in each cycle. If we can calculate nim-value for a cycle of each size, then nim-value of the whole game is equal to XOR of these values.

To calculate nim-value for the cycle of length $x$ ($cycle[x]$), we need to take $\operatorname{mex}$ of nim-values from all transitions. But since all transitions transform a cycle to a chain, then we will calculate nim-values for chains as well, or $cycle[x] = \operatorname{mex}(chain[x - r], chain[x - r + 1], \dots, chain[x - l])$.

To calculate nim-value for the chain $chain[x]$, we need to consider all possible transitions. We can either cut off from the end of the chain, or from the middle of the chain. In either case, we end up with two smaller chains (maybe one of them is empty), which are themselves independent games, so $chain[x] = \operatorname{mex}{\{chain[a] \oplus chain[b] \mid \forall a, b \ge 0 : x - r \le a + b \le x - l\}}$.

Implementing this directly requires $O(n^3)$ time. A more accurate implementation with recalculations requires $O(n^2)$ time. For a complete solution, something needs to be noticed in nim-values.

Consider an example. Let $l = 4$, $r = 14$.

 

| index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| $chain$ | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 2 | 2 | 2 | 2 | 3 | 3 | 3 | 3 | 4 | 4 | 4 | 4 |
| $cycle$ | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 2 | 2 | 2 | 2 | 3 | 3 | 3 | 3 | 4 | 4 | 0 | 0 |
|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | $\uparrow$ |  |
|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | $l + r$ | | |  |

 * $chain[x]$ on $[0, l - 1]$ is obviously equal to $0$;
* $chain[x] = \left\lfloor \frac{x}{l} \right\rfloor$ on segment $[0, r + l - 1]$ (proof is below);
* $chain[x] > 0$ for all $x \ge l$: since $l < r$ you can always split the chain $x$ in two equal chains $a$. This transition adds nim-value $chain[a] \oplus chain[a] = 0$ into $\operatorname{mex}$, that's why $chain[x] = \operatorname{mex}{\{\dots\}} > 0$.
* $cycle[x]$ is equal to $chain[x]$ up to $r + l - 1$: it's because $cycle[x]$ is equal to $\operatorname{mex}{\{chain[0], chain[1], \dots, chain[x - l]\}}$;
* $cycle[x] = 0$ for $x \ge l + r$, it's because $chain[x] > 0$ for $x \ge l$.

So, if $x \le r + l - 1$, then $cycle[x] = \left\lfloor \frac{x}{l} \right\rfloor$, otherwise $cycle[x] = 0$. We have to calculate the sizes of all cycles in the graph and calculate XOR of those values. If it is zero, the winner is Bob, otherwise, winner is Alice.

Let's prove that $chain[x] = \left\lfloor \frac{x}{l} \right\rfloor$ on segment $[0, r + l - 1]$: 

1. $chain[x] \ge \left\lfloor \frac{x}{l} \right\rfloor$: there are transitions to pairs of chains $(a, b)$ where $a = 0$ and $b$ is any number from $[0, x - l]$. Their nim-value is equal to $chain[0] \oplus chain[b]$ $=$ $chain[b]$, so $chain[x] \ge \operatorname{mex}{\{chain[b] \mid 0 \le b \le x - l\}} = \left\lfloor \frac{x}{l} \right\rfloor$.
2. $chain[x]$ is exactly equal to $\left\lfloor \frac{x}{l} \right\rfloor$: we can prove that for any pair of chains $(a, b)$ with $a + b \le x - l$ value $chain[a] \oplus chain[b]$ $\le$ $\left\lfloor \frac{x}{l} \right\rfloor - 1$: $$chain[a] \oplus chain[b] \le chain[a] + chain[b] = \left\lfloor \frac{a}{l} \right\rfloor + \left\lfloor \frac{b}{l} \right\rfloor \le \left\lfloor \frac{a + b}{l} \right\rfloor \le \left\lfloor \frac{x - l}{l} \right\rfloor = \left\lfloor \frac{x}{l} \right\rfloor - 1$$
 **Solution C++**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector < vector <int> > g(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int res=0, size;
    vector <int> used(n);

    function <void(int)> dfs = [&] (int v) {
        used[v] = true;
        size++;
        for (int to : g[v]) {
            if (!used[to])
                dfs(to);
        }
    };

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            size = 0;
            dfs(i);
            if (size <= l + r - 1) {
                res ^= size / l;
            }
        }
    }

    if (res)
        cout << "Alicen";
    else
        cout << "Bobn";

    return 0;
}
```
 **Solution Python**
```cpp
from sys import setrecursionlimit
import threading

def main():
    n, l, r = map(int, input().split())

    g = [[] for i in range(0, n)]
    for i in range(0, n):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        g[a].append(b)
        g[b].append(a)

    res = 0
    used = [False for i in range(0, n)]

    def dfs(v):
        used[v] = True
        size = 1
        for to in g[v]:
            if not used[to]:
                size += dfs(to)
        return size

    for i in range(0, n):
        if not used[i]:
            size = dfs(i)
            if size <= l + r - 1:
                res ^= size // l

    if res:
        print("Alice")
    else:
        print("Bob")

setrecursionlimit(10 ** 9)
threading.stack_size(2 ** 27)
thread = threading.Thread(target=main)
thread.start()
```
[1823F - Random Walk](../problems/F._Random_Walk.md "Codeforces Round 868 (Div. 2)")

 **Editorial**
### [1823F - Random Walk](../problems/F._Random_Walk.md "Codeforces Round 868 (Div. 2)")

Let $deg(v)$ be the number of neighbors of vertex $v$. Let's fix a vertex $v$ and its neighboring vertices $c_1, \dots, c_{deg(v)}$. According to the linearity of the expected values: $$e_v = \sum_{u \in \{c_1, \dots, c_{deg(v)}\}} \frac{e_u}{deg(u)}$$ This gives the system of equations, which, however, cannot be directly solved.

Solution by Igor_Parfenov:

Let's solve the subproblem: given a bamboo with vertices numbered in order from $1$ to $n$, and $s = 1$ and $t = n$. It is easy to see that the equation is satisfied by the expected values $\{n - 1, 2 \cdot (n - 2), 2 \cdot (n - 3), \dots , 6, 4, 2, 1\}$.

Now let's solve the problem. Consider the path from $s$ to $t$ (it is the only one in the tree). The chip must go through it, but at the vertices of the path, it can go to third-party vertices. Let us represent a tree as non-intersecting trees whose roots are vertices lying on the path from $s$ to $t$, and all other vertices do not lie on this path. Let's place the numbers $\{n - 1, n - 2, \dots, 2, 1, 0\}$ at the vertices of the path. Let's now fix a tree rooted at vertex $v$ in the path, and let its number be equal to $x$. Then we can see that the equation is satisfied by the values of the mathematical expectation $e_u = x \cdot deg(u)$. Separately, you need to make $e_t = 1$.

Solution by adedalic:

Let's take a path from $s$ to $t$ and call it $r_0, r_1, \dots, r_k$, where $r_0 = s$ and $r_k = t$. Now we will assume that each of the vertices $r_i$ form its own rooted subtree. Consider a leaf $v$ in an arbitrary subtree: $e_v = \frac{1}{deg(p)} e_p$, where $p$ is the ancestor of $v$.

Now, by induction on the subtree size, we prove that for any vertex $v$ in any subtree $r_i$ the expected value is $e_v = \frac{deg(v)}{deg(p)} e_p$. For the leafs, it's obvious. Further, by the inductive hypothesis: $$ e_v = \sum_{to \neq p}{\frac{1}{deg(to)} e_{to}} + \frac{1}{deg(p)} e_p = \sum_{to \neq p}{\frac{deg(to)}{deg(to) \cdot deg(v)} e_v} + \frac{1}{deg(p)} e_p = \frac{deg(v) - 1}{deg(v)} e_v + \frac{1}{deg(p)} e_p $$ $$ \frac{1}{deg(v)} e_v = \frac{1}{deg(p)} e_p \leftrightarrow e_v = \frac{deg(v)}{deg(p)} e_p$$.

Now consider the vertices on the path: $$e_{r_0} = 1 + \sum_{to \neq r_1}{\frac{1}{deg(to)} e_{to}} + \frac{1}{deg(r_1)} e_{r_1} = 1 + \frac{deg(r_0) - 1}{deg(r_0)} e_{r_0} + \frac{1}{deg(r_1)} e_{r_1} $$ $$ e_{r_0} = deg(r_0) \left( 1 + \frac{1}{deg(r_1)} e_{r_1} \right) $$

$$ e_{r_1} = \frac{1}{deg(r_0)} e_{r_0} + \sum_{to \neq r_0; to \neq r_2}{\frac{1}{deg(to)} e_{to}} + \frac{1}{deg(r_2)} e_{r_2} = \left( 1 + \frac{1}{deg(r_1)} e_{r_1} \right) + \frac{deg(r_1) - 2}{deg(r_1)} e_{r_1} + \frac{1}{deg(r_2)} e_{r_2}$$ $$ e_{r_1} = deg(r_1) \left( 1 + \frac{1}{deg(r_2)} e_{r_2} \right) $$ And so on. For $r_{k - 1}$ we get: $$ e_{r_{k-1}} = deg(r_{k-1}) \left( 1 + 0 \right) = deg(r_{k - 1}) $$ Now let's expand: $$ e_{r_{k-2}} = deg(r_{k-2}) \left( 1 + \frac{1}{deg(r_{k-1})} e_{r_{k-1}} \right) = deg(r_{k-2}) (1 + 1) = 2 \cdot deg(r_{k-2}) $$ $$ e_{r_{k-3}} = deg(r_{k-2}) \left( 1 + 2 \right) = 3 \cdot deg(r_{k-2}) $$ $$ e_{r_{k-i}} = i \cdot deg(r_{k-i}) $$

That's all. For any vertex $v$ in the subtree of $r_i$ we get $e_v = (k - i) \cdot deg(v)$.

 **Solution C++**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 998244353;
 
int main(){
    int n, s, t;
    cin >> n >> s >> t;
    s--, t--;
 
    vector < vector <int> > g(n);
    vector <int> previous(n, -1);
    vector <int> inPath(n);
    vector <long long> res(n);
 
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    function <void (int, int)> dfs = [&] (int v, int p) {
        for (int to : g[v]) {
            if (to == p) continue;
            previous[to] = v;
            dfs(to, v);
        }
    };
 
    function <void (int, int, long long)> dfs2 = [&] (int v, int p, long long k) {
        res[v] = k * (long long)g[v].size();
        for (int to : g[v]) {
            if (to == p) continue;
            dfs2(to, v, k);
        }
    };
 
    dfs(s, -1);
 
    int ptr = t;
    inPath[t] = true;
 
    while (ptr != s) {
        res[previous[ptr]] = res[ptr] + 2;
        ptr = previous[ptr];
        inPath[ptr] = true;
    }
 
    for (int v = 0; v < n; v++) {
        if (inPath[v]) {
            res[v] = res[v] / 2 * (long long)g[v].size();
            for (int to : g[v]) {
                if (!inPath[to]) {
                    dfs2(to, v, res[v] / (int)g[v].size());
                }
            }
        }
    }
 
    res[t]++;
 
    for (long long i : res)
        cout << i % mod << ' ';
    cout<<'n';
 
    return 0;
}
```
 **Solution Python**
```cpp
from sys import setrecursionlimit
import threading
 
mod = 998244353
 
def main():
    n, s, t = map(int, input().split())
    s -= 1
    t -= 1
    
    g = [[] for i in range(0, n)]
    previous = [-1 for i in range(0, n)]
    inPath = [False for i in range(0, n)]
    res = [0 for i in range(0, n)]
    
    for i in range(0, n - 1):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        g[a].append(b)
        g[b].append(a)
    
    def dfs(v, p):
        for to in g[v]:
            if to == p:
                continue
            previous[to] = v
            dfs(to, v)
    
    def dfs2(v, p, k):
        res[v] = k * len(g[v])
        for to in g[v]:
            if to == p:
                continue
            dfs2(to, v, k)
    
    dfs(s, -1)
    
    ptr = t
    inPath[t] = True
    
    while ptr != s:
        res[previous[ptr]] = res[ptr] + 2
        ptr = previous[ptr]
        inPath[ptr] = True
    
    for v in range(0, n):
        if inPath[v]:
            res[v] = res[v] // 2 * len(g[v])
            for to in g[v]:
                if not inPath[to]:
                    dfs2(to, v, res[v] // len(g[v]))
    
    res[t] += 1
    
    for i in res:
        print(i % mod, end = ' ')
    print("")
 
setrecursionlimit(10 ** 9)
threading.stack_size(2 ** 27)
thread = threading.Thread(target=main)
thread.start()
```
