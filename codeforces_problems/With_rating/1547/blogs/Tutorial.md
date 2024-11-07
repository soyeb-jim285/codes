# Tutorial

[1547A - Shortest Path with Obstacle](../problems/A._Shortest_Path_with_Obstacle.md "Codeforces Round 731 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1547A - Shortest Path with Obstacle](../problems/A._Shortest_Path_with_Obstacle.md "Codeforces Round 731 (Div. 3)")

Let's suppose that the forbidden cell does not affect the shortest path. In that case, the answer would be |xA−xB|+|yA−yB|.

The forbidden cell blocks the shortest path if and only if it belongs to every shortest path. In other words, if there is only one shortest path and the forbidden cell belongs to it. So, the answer differs from |xA−xB|+|yA−yB| if and only if A and B are in one row or column and F is between them. In that case, the answer is |xA−xB|+|yA−yB|+2 (i.e. greater by 2).

In order to check that point R lays between P and Q on a straight line, just check min(P,Q)<R<max(P,Q).

So, the correct solution looks like this:


```cpp
vector<int> a(2), b(2), f(2);  
cin >> a[0] >> a[1];  
cin >> b[0] >> b[1];  
cin >> f[0] >> f[1];  
int ans = abs(a[0] - b[0]) + abs(a[1] - b[1]);  
if ((a[0] == b[0] && a[0] == f[0] && min(a[1], b[1]) < f[1] && f[1] < max(a[1], b[1]))  
        || (a[1] == b[1] && a[1] == f[1] && min(a[0], b[0]) < f[0] && f[0] < max(a[0], b[0])))  
    ans += 2;  
cout << ans << endl;  

```
 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        vector<int> a(2), b(2), f(2);
        cin >> a[0] >> a[1];
        cin >> b[0] >> b[1];
        cin >> f[0] >> f[1];
        int ans = abs(a[0] - b[0]) + abs(a[1] - b[1]);
        if ((a[0] == b[0] && a[0] == f[0] && min(a[1], b[1]) < f[1] && f[1] < max(a[1], b[1]))
                || (a[1] == b[1] && a[1] == f[1] && min(a[0], b[0]) < f[0] && f[0] < max(a[0], b[0])))
            ans += 2;
        cout << ans << endl;
    }
}
```
[1547B - Alphabetical Strings](../problems/B._Alphabetical_Strings.md "Codeforces Round 731 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1547B - Alphabetical Strings](../problems/B._Alphabetical_Strings.md "Codeforces Round 731 (Div. 3)")

For a start, let's find the position of the letter 'a' in string $s$. If this position does not exist, then the answer would be 'NO'. Suppose that this position exists and equals $\text{pos}_a$. Let's create two pointers $L$ and $R$. Initially $L := \text{pos}_a,~R := L$. We will try to build string $s$ using the algorithm from the statement. Suppose that we have built substring $s[L..R]$ in $i$ iterations. Consider the next letter of the Latin alphabet $c_i$. Let's look at cases: 

1. find position $pos$ of the letter $c_i$ in $s$ (if it does not exist then 'NO');
2. if $pos = L - 1$ then make an assignment $L := L - 1$ and process the next letter $c_i$;
3. if $pos = R + 1$ then make an assignment $R := R + 1$ and process the next letter $c_i$;
4. otherwise string $s$ is not alphabetical and the answer is 'NO'.

 So, if we have built the string in $n$ iteration, then string $s$ is alphabetical and the answer is 'YES'. **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        string s;
        cin >> s;
        size_t L = s.find('a');
        if (L == string::npos) {
            cout << "NO" << endl;
            continue;
        }
        size_t n = s.length(), R = L;
        bool yes = true;
        for (size_t i = 1; i < n; i++) {
            size_t pos = s.find(char('a' + i));
            if (pos == string::npos || (pos != L - 1 && pos != R + 1)) {
                yes = false;
                break;
            } else {
                L = min(L, pos);
                R = max(R, pos);
            }
        }
        cout << (yes ? "YES" : "NO") << endl;
    }
}
```
[1547C - Pair Programming](../problems/C._Pair_Programming.md "Codeforces Round 731 (Div. 3)")

Idea: [geranazavr555](https://codeforces.com/profile/geranazavr555 "Headquarters, geranazavr555"), [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1547C - Pair Programming](../problems/C._Pair_Programming.md "Codeforces Round 731 (Div. 3)")

The solution is that if we can do something, let's do it. It doesn't make sense not to act, because neither adding a new row nor modifying an existing one can prevent the existing row from being changed in the future. Therefore, we will iterate over the actions and eagerly act Monocarp or Polycarp.

Let's create two pointers $i$ and $j$ in arrays $a$ and $b$ — index of possible action of Monocarp and Polycarp and $c$ — the current length of the file.

Suppose that $a_i = 0$ or $b_j = 0$ on current iteration. Then we take the appropriate zero element and increase $c$ by one. We can do that because appending a new line cannot make a new answer prefix incorrect if the previous prefix was correct.

Suppose that $a_i \ne 0$ and $b_j \ne 0$. If $a_i > c$ and $b_j > c$ then there is no answer because we can potentially do only two actions and both make the answer incorrect. If one number is greater than $c$ and the other is less than or equals then we take the one that less than or equals $c$.

If one of the sequences $a$ or $b$ ends then only one potential action needs to be checked at each iteration.

 **Solution**
```cpp
#include <iostream>
#include <vector>

typedef std::vector<int> vi;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int k, n, m;
        std::cin >> k >> n >> m;

        vi a(n), b(m);
        for (int i = 0; i < n; i++)
            std::cin >> a[i];
        for (int i = 0; i < m; i++)
            std::cin >> b[i];

        int pos1 = 0, pos2 = 0;
        vi res;
        bool ok = true;
        while (pos1 != n || pos2 != m) {
            if (pos1 != n && a[pos1] == 0) {
                res.push_back(0);
                k++;
                pos1++;
            } else if (pos2 != m && b[pos2] == 0) {
                res.push_back(0);
                k++;
                pos2++;
            } else if (pos1 != n && a[pos1] <= k) {
                res.push_back(a[pos1++]);
            } else if (pos2 != m && b[pos2] <= k) {
                res.push_back(b[pos2++]);
            } else {
                std::cout << -1 << 'n';
                ok = false;
                break;
            }
        }

        if (ok) {
            for (int cur : res)
                std::cout << cur << ' ';
            std::cout << std::endl;
        }
    }

    return 0;
}
```
[1547D - Co-growing Sequence](../problems/D._Co-growing_Sequence.md "Codeforces Round 731 (Div. 3)")

Idea: [doreshnikov](https://codeforces.com/profile/doreshnikov "Candidate Master doreshnikov")

 **Tutorial**
### [1547D - Co-growing Sequence](../problems/D._Co-growing_Sequence.md "Codeforces Round 731 (Div. 3)")

In order to build lexicographically minimal co-growing with $x_i$ sequence, it is enough to build its elements iteratively, beginning from $y_1$ and minimizing the $i$-th element assuming that $y_1, \ldots, y_{i - 1}$ have already been found.

Assign $y_1 = 0$. According to the statement, all elements of the sequence are non-negative, so $y_1$ cannot be less than zero. It turns out that $y_i = 0$ is the minimal possible first element. The existence of an answer with $y_1 = 0$ follows from the construction algorithm described below.

Let's use mathematical induction and construct $y_i$ under the assumption that all the previous elements of the sequence have already been constructed. In order to satisfy the condition for the growth of the final sequence, the number $x_i \oplus y_i$ must contain one bits at all places (but not necessarily limited to them), on which there are one bits in the number $x_{i - 1} \oplus y_{i - 1}$. Let's denote $x_{i - 1} \oplus y_{i - 1}$ for $t$ and find out what bits can be in $y_i$ to satisfy this condition: 

* If in $t$ stands $0$ bit then independently from $x_i$ in $y_i$ at the same spot we can place any bit because there is no limit on the corresponding bit in $x_i \oplus y_i$;
* If in $t$ stands $1$ bit and in $x_i$ — $0$ then the corresponding bit in $y_i$ should be equal $1$, so that in $x_i \oplus y_i$ the corresponding bit also equals one;
* If in $t$ and in $x_i$ stands $1$ bit then in $y_1$ should be $0$ bit at the corresponding place for the same reasons.

The bit transformation described above can be given by the expression $y_i = \left(t\,|\,x_i\right) \oplus x_i$. Indeed, this expression gives us bit 'one' at the fixed position if and only if at that place in $t$ stands $1$ bit and in $x_i$ stands $0$ bit. For the full solution, it remains only to apply this formula in a loop from $2$ to $n$.

 **Solution**
```cpp
def f(x, y):
    return x & ~y

t = int(input())
for tt in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    ans = [0] * n
    for i in range(1, n):
        ans[i] = f(ans[i - 1] ^ a[i - 1], a[i])
    print(" ".join(map(str, ans)))
```
[1547E - Air Conditioners](../problems/E._Air_Conditioners.md "Codeforces Round 731 (Div. 3)")

Idea: [geranazavr555](https://codeforces.com/profile/geranazavr555 "Headquarters, geranazavr555"), [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1547E - Air Conditioners](../problems/E._Air_Conditioners.md "Codeforces Round 731 (Div. 3)")

Let's calculate two arrays $L$ and $R$, where:

* $L_i$ is the temperature in cell $i$ if we take only air conditioners with numbers less than or equal to $i$;
* $R_i$ is the temperature in cell $i$ if we take only air conditioners with numbers greater than or equal to $i$;

Let's show how to calculate array $L$. We will calculate values from left to right using DP and next formula: $L_i = \min(L_{i+1}+1, c_i)$, where $c_i$ is the temperature of air conditioner in cell $i$ (or infinity if there is no air conditioner in this cell). Indeed, the value of $L_i$ is either determined by the air conditioner in this cell (i.e. equals $c_i$) or by some air conditioner to the left, but this means that we should take the answer from the previous cell and increase it by $1$. The full code for calculating $L$ looks like this:


```cpp
vector<long long> L(n, INT_MAX);  
p = INT_MAX;  
forn(i, n) {  
    p = min(p + 1, c[i]);  
    L[i] = p;  
}  

```
In exactly the same way (but from right to left) we will calculate $R$:


```cpp
vector<long long> R(n, INT_MAX);  
p = INT_MAX;  
for (int i = n - 1; i >= 0; i–) {  
    p = min(p + 1, c[i]);  
    R[i] = p;  
}  

```
The answer for cell $i$ is $\min(L[i], R[i])$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        forn(i, k)
            cin >> a[i];
        vector<int> t(k);
        forn(i, k)
            cin >> t[i];
        vector<long long> c(n, INT_MAX);
        forn(i, k)
            c[a[i] - 1] = t[i];

        long long p;

        vector<long long> L(n, INT_MAX);
        p = INT_MAX;
        forn(i, n) {
            p = min(p + 1, c[i]);
            L[i] = p;
        }

        vector<long long> R(n, INT_MAX);
        p = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            p = min(p + 1, c[i]);
            R[i] = p;
        }

        forn(i, n)  
            cout << min(L[i], R[i]) << " ";
        cout << endl;
    }
}
```
[1547F - Array Stabilization (GCD version)](../problems/F._Array_Stabilization_(GCD_version).md "Codeforces Round 731 (Div. 3)")

Idea: [doreshnikov](https://codeforces.com/profile/doreshnikov "Candidate Master doreshnikov")

 **Tutorial**
### [1547F - Array Stabilization (GCD version)](../problems/F._Array_Stabilization_(GCD_version).md "Codeforces Round 731 (Div. 3)")

First, note that the array stabilizes if and only if it consists of equal elements, and the number the array $a$ will be consisted of is $T = \gcd(a_1, \ldots, a_n)$. Indeed, at the $i$-th step a number equal to $\gcd(a_j, \ldots, a_{(j + i) \mod n})$ will be written at the $j$-th position in the array.

This is easy to prove by induction: if at the previous step the adjacent elements in the array were equal to $\gcd$ of the numbers on adjacent segments of length $i - 1$ in the original array, then their greatest common divisor will be the greatest common divisor of the union of these two segments (GCD is an [idempotent](https://codeforces.com/https://tinyurl.com/2965u55w) operation).

Thus, the algorithm will stop in no more than $n$ steps, since after $n$ steps all numbers will be equal exactly to $T$. If we divide all the numbers $a_i$ by $T$ before starting the algorithm, then the number of steps won't change, but the array will stabilize at the number $1$.

Since the numbers in the array after the $k$-th step will be exactly equal to $\gcd$ of all segments of length $k + 1$ of the original array $a$, it follows that the number of steps after which all values become the same is exactly equal to the length of the maximum segment of the original array on which $\gcd > 1$.

There are several ways to find the length of such a segment. For example, you can use range GCD query and binary search. The following method is based on the factorization of numbers, in other words, on their decomposition into prime factors. Factorization in this problem could be done using both the sieve of Eratosthenes or factoring each number independently in $\mathcal{O}(\sqrt{a_i})$.

After all the numbers have been factorized, iterate over each $i$ and each prime $p$ in its factorization. In linear time we can go left and right from $i$, finding the maximum segment of numbers that contain the same factor $p$. Then we can update the answer with the length of this segment and move onto the next prime in the factorization of $a_i$ or go to $i + 1$, if all primes have already been iterated through.

Note that if a segment of numbers divisible by $p$ contains indices from $l$ to $r$, then we iterate through it $r - l + 1$ times. In order to avoid reiteration on each segment, we remove $p$ from the factorizations of all numbers on the segment after considering only one.

The resulting solution works in $\mathcal{O}\left(n \cdot \mathtt{MAX\\_P}\right)$, where $\mathtt{MAX\\_P}$ — the maximum number of different primes in factoriztion of $a_i$. Considering that $a_i \leq 10^6$, $\mathtt{MAX\\_P} = 8$, so the solution fits into the time limit.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const unsigned int MAX_A = 1'000'000;
vector<unsigned int> sieve(MAX_A + 1);
vector<unsigned int> prime;

unsigned int gcd(unsigned int a, unsigned int b) {
    return b == 0 ? a : gcd(b, a % b);
}

unsigned int solve() {

    unsigned int n;
    cin >> n;
    vector<unsigned int> a(n);
    for (unsigned int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unsigned int common = a[0];
    vector<set<unsigned int>> facts(n);
    for (unsigned int i = 1; i < n; i++) {
        common = gcd(common, a[i]);
    }
    for (unsigned int i = 0; i < n; i++) {
        unsigned int t = a[i] / common;
        while (t != 1) {
            facts[i].insert(sieve[t]);
            t /= sieve[t];
        }
    }

    unsigned int answer = 0;
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int p : facts[i]) {
            int l = (i + n - 1) % n, r = i;
            unsigned int cnt = 0;
            while (facts[l].count(p) > 0) {
                facts[l].erase(p);
                l--; cnt++;
                if (l < 0) {
                    l = n - 1;
                }
            }
            while (facts[r].count(p) > 0) {
                if (r != i) {
                    facts[r].erase(p);
                }
                ++r %= n; cnt++;
            }
            answer = max(answer, cnt);
        }
        facts[i].clear();
    }

    return answer;

}

int main() {

    sieve[1] = 1;
    for (unsigned int i = 2; i <= MAX_A; i++) {
        if (sieve[i] == 0) {
            sieve[i] = i;
            prime.push_back(i);
        }
        for (unsigned int j = 0; j < prime.size() && prime[j] <= sieve[i] && i * prime[j] <= MAX_A; j++) {
            sieve[i * prime[j]] = prime[j];
        }
    }

    unsigned int t;
    cin >> t;
    for (unsigned int i = 0; i < t; i++) {
        cout << solve() << 'n';
    }

}
```
[1547G - How Many Paths?](../problems/G._How_Many_Paths_.md "Codeforces Round 731 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1547G - How Many Paths?](../problems/G._How_Many_Paths_.md "Codeforces Round 731 (Div. 3)")

The first motivation for solving this problem is to write a lot of standard code like "find strongly connected components", do some DP over the condensed graph (the graph of strongly connected components), and so on.

In fact, this problem can be solved much more elegantly with less code if you have a little better understanding of how depth-first search works.

Consider a usual depth-first search on a digraph that is started from the vertex $1$. This will be a normal depth-first search, which will paint vertices using three colors: white (the vertex has not yet been found by the search), gray (the vertex is processing by DFS), and black (the vertex has already been processed by the DFS completely, that is, completely bypassed its subtree of the depth-first search tree).

Here's the pseudocode:


```cpp
dfs(u):  
    color[u] = GRAY  
    for v in g[u]:  
        if color[v] == WHITE:  
            dfs(v)  
    color[u] = BLACK  

```
The following statements are true:

* there is a cycle in the digraph reachable from $s$ if and only if the root call dfs(s) visits in the line if color [v] == WHITE when color[v] == GRAY;
* moreover, for each reachable cycle from $s$ there is at least one vertex that will execute the previous item (then the vertex $v$ belongs to the cycle);
* if the root call dfs(s) visits in the line if color[v] == WHITE, when color [v] == BLACK, then there is more than one path (the opposite is not true).

It is clear that there are infinite paths from $s$ to $u$ if and only if there is a vertex $v$ on some path from $s$ to $u$ such that $v$ is in a cycle. Thus, we mark all such vertices $v$ for which color[v] == GRAY at the moment of execution of the line if color [v] == WHITE. The fact is true: All vertices reachable from those noted in the previous phrase are those and only those vertices that an infinite number of paths lead to them.

A similar fact is also true for finding vertices to which at least two paths (but a finite number) lead. Let's mark all such vertices $v$ for which color[v] == BLACK at the moment of execution of the line if color [v] == WHITE. The fact is true: Let's find all reachable vertices from those marked in the previous phrase. Let's discard those up to which we have already determined that the number of paths is infinite. The remaining reachable vertices are those and only those to which there are at least two paths (and their finite number).

So the solution looks like this:

* let's make a depth-first search from the root, mark during it those vertices that were gray when trying to go to them (group A) and were black when trying to go to them (group B);
* mark the vertices reachable from the group A (let's call them AA);
* mark the vertices reachable from the group B (let's call them BB);
* the answer for the vertex is:
	+ $0$ if it is not reachable from $s$ (this determines the first DFS);
	+ $-1$, if it is from AA;
	+ $2$ if it is from BB (but not from AA);
	+ $1$, if it is not from AA and not from BB.

In the author's solution, only one dfs function was used with an additional boolean parameter to determine its mode.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int n;
vector<vector<int>> g;
set<int> s[2];

void dfs(int u, vector<int>& color, bool use_s) {
    color[u] = 1;
    for (int v: g[u])
        if (color[v] == 0)
            dfs(v, color, use_s);
        else if (use_s)
            s[color[v] - 1].insert(v);
    color[u] = 2;
}

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int m;
        cin >> n >> m;
        g = vector<vector<int>>(n);
        forn(i, 2)
            s[i] = set<int>();
        forn(i, m) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].push_back(y);
        }
        vector<int> color = vector<int>(n);
        dfs(0, color, true);
        vector<vector<int>> c(2, vector<int>(n));
        forn(i, 2)
            for (auto u: s[i])
                dfs(u, c[i], false);
        forn(i, n) {
            int ans = 0;
            if (color[i] != 0) {
                ans = 1;
                if (c[0][i])
                    ans = -1;
                else if (c[1][i])
                    ans = 2;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}
```
