# Tutorial_(en)

Hope you liked the problems!

[1856A - Tales of a Sort](../problems/A._Tales_of_a_Sort.md "Codeforces Round 890 (Div. 2) supported by Constructor Institute")

 **Hints****Hint 1**How many operations are needed to make ai≤ai+1 if initially, ai>ai+1?

 **Tutorial**
### [1856A - Tales of a Sort](../problems/A._Tales_of_a_Sort.md "Codeforces Round 890 (Div. 2) supported by Constructor Institute")

Suppose we have performed $k$ operations and have gotten the array $b$. Then $b_i := \max(0, a_i - k)$ for all $i$ from $1$ to $n$.

If $b$ is sorted, then $b_i \le b_{i + 1}$ for all $i$ from $1$ to $n - 1$. In other words, $\max(0, a_i - k) \le \max(0, a_{i + 1} - k)$. Let's find for which $k$ this inequality holds.

Suppose $a_i \le a_{i + 1}$. Then $\max(0, a_i - k) \le \max(0, a_{i + 1} - k)$ is true for any $k \ge 0$.

Now suppose $a_i > a_{i + 1}$. Then $\max(0, a_i - k) \le \max(0, a_{i + 1} - k)$ is true only if $k \ge a_i$.

For the array to be sorted after $k$ operations, $\max(0, a_i - k) \le \max(0, a_{i + 1} - k)$ must hold for all $1 \le i < n$. From the statements above, we can see that the smallest $k$ for which this is true is equal to the maximum value of $a_{i}$ over all $1 \le i < n$ such that $a_{i} > a_{i + 1}$. If no such $i$ exists, the answer is $0$, since the array is already sorted.

Complexity: $\mathcal{O}(n)$

Note: there are at least two other solutions: 

* The solution above is also equivalent to finding the maximum value of $a_{i}$ over all $1 \le i < j \le n$ such that $a_i > a_j$, which leads to a $\mathcal{O}(n^2)$ solution.
* Alternatively, you can do binary search on the answer to get a $\mathcal{O}(n \log A)$ solution, where $A$ is the maximum possible value of $a_i$.
 **Solution**
```cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = 'n';
typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            ans = max(ans, a[i]);
        }
    }
    
    cout << ans << nl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
```
 **Feedback*** Good problem 


[*281*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*91*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*18*](https://codeforces.com/data/like?action=like "I like this")
[1856B - Good Arrays](../problems/B._Good_Arrays.md "Codeforces Round 890 (Div. 2) supported by Constructor Institute")

 **Hints****Hint 1**Consider the case n=1 separately.

 **Hint 2**Count the number of elements equal to 1.

 **Hint 3**Find the sum of the array.

 **Hint 4**When there are a lot of elements equal to 1 and the sum is not very big, the answer is no.

 **Tutorial**
### [1856B - Good Arrays](../problems/B._Good_Arrays.md "Codeforces Round 890 (Div. 2) supported by Constructor Institute")

Suppose $b$ didn't have to consist of only positive integers. Then, one simple strategy would be to to decrease each of $a_2, a_3, \ldots a_n$ by $1$ and increase $a_1$ by $n - 1$. Except for $n = 1$, when it is impossible to get a good array.

When $b$ has to consist of only positive integers, we can't decrease elements that are equal to $1$. But to make $b_i \neq a_i$, we also have to increase them by at least $1$. 

Let $cnt_1$ be the number of elements in $a$ that are equal to $1$. To not change the sum of the array, we have to decrease the other $n - cnt_1$ elements by at least $cnt_1$. For this to be possible, their sum must be equal to at least $(n - cnt_1) + cnt_1 = n$, since each of the $n - cnt_1$ elements must remain positive. So, $a_1 + a_2 + \ldots + a_n$ has to be equal to at least $cnt_1 + (n - cnt_1) + cnt_1 = cnt_1 + n$.

So, if $a_1 + \ldots + a_n < cnt_1 + n$, a good array doesn't exist. If $n = 1$, a good array also doesn't exist.

Now suppose $a_1 + \ldots + a_n \ge cnt_1 + n$ and $n \neq 1$. We will prove that if this is the case, a good array must exist.

If $cnt_1 \le \frac{n}{2}$, we increase all $a_i = 1$ by $1$ and decrease $cnt_1$ elements that are $\ge 2$ by $1$ and apply the simple strategy described above for the other $n - 2 \cdot cnt_1$ elements $\ge 2$, so in this case, a good array exists.

If $cnt_1 > \frac{n}{2}$, we increase all $a_i = 1$ by $1$ and decrease each element $\ge 2$ by at least $1$, so $b_i \neq a_i$ holds for all $1 \le i \le n$, so in this case, a good array also exists.

Complexity: $\mathcal{O}(n)$

 **Solution**
```cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = 'n';
typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    ll sum_a = 0, cnt_1 = 0;
    for (int x: a) {
        sum_a += x;
        if (x == 1) cnt_1++;
    }
    
    if (sum_a >= cnt_1 + n && n > 1) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
```
 **Feedback*** Good problem 

 
[*383*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*67*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*84*](https://codeforces.com/data/like?action=like "I like this")
[1856C - To Become Max](../problems/C._To_Become_Max.md "Codeforces Round 890 (Div. 2) supported by Constructor Institute")

 **Hints****Hint 1**Binary search on the answer.

 **Hint 1.1**Check if it is possible to have max(a1,…,an)≥x for some x.

 **Hint 2**Fix some possible index that will be the position of the maximum in the final array.

 **Tutorial**
### [1856C - To Become Max](../problems/C._To_Become_Max.md "Codeforces Round 890 (Div. 2) supported by Constructor Institute")

We will do binary search on the answer. The lower bound can be set to $0$, while $\max(a_1, \ldots a_n) + k$ is clearly enough for the upper bound.

Let $b$ be some resulting array after performing at most $k$ operations.

Suppose for some $x$ we want to check if we can get $\max(b_1, \ldots b_n) \ge x$ in at most $k$ operations. That is, there must exist some index $i$ such that $b_i \ge x$. So, let's iterate $i$ from $1$ to $n$ and check if it possible to have $b_i \ge x$ in at most $k$ operations.

Let $f(i, y)$ be the minimum number of operations needed to make $b_i \ge y$. Then: 

* $f(i, y) = 0$ for all $y \le a_i$,
* $f(i, y) = y - a_i + f(i + 1, y - 1)$ for all $1 \le i < n$ and $y > a_i$,
* $f(i, y) = +\infty$ for $i = n$ and all $y > a_i$.

It is easy to see that calculating $f(i, x)$ takes $\mathcal{O}(n)$ time for one call in the worst case.

Thus, our check consists of comparing $f(i, x)$ and $k$ for all $i$ from $1$ to $n$. If at least one of the values is $\le k$, it is possible to have some $b_i \ge x$ in at most $k$ operations and we increase the lower bound in the binary search after updating the current answer. Otherwise, it is impossible and we decrease the upper bound.

Complexity: $\mathcal{O}(n^2 \cdot \log A)$, where A is the maximum possible value of $a_i$ and $k$.

Notes: 

* You can get a $\mathcal{O}(n^2 \cdot \log n)$ solution by setting the lower bound in the binary search to $\max(a_1, \ldots, a_n)$ and the upper bound to $\max(a_1, \ldots, a_n) + n$.
* There exists a $\mathcal{O}(n^2)$ dp solution that relies on the fact that the answer lies in the range $[ \max(a_1, \ldots, a_n); \max(a_1, \ldots, a_n) + n ]$
 **Solution**
```cpp
#include <bits/stdc++.h>
 
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())
 
const char nl = 'n';
typedef long long ll;
typedef long double ld;
 
using namespace std;
 
void solve() {
    ll n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    ll lb = 0, ub = *max_element(all(a)) + k, ans = 0;
    while (lb <= ub) {
        ll tm = (lb + ub) / 2;
        bool good = false;
        
        for (int i = 0; i < n; i++) {
            vector<ll> min_needed(n);
            min_needed[i] = tm;
            
            ll c_used = 0;
            for (int j = i; j < n; j++) {
                if (min_needed[j] <= a[j]) break;
                
                if (j + 1 >= n) {
                    c_used = k + 1;
                    break;
                }
                
                c_used += min_needed[j] - a[j];
                min_needed[j + 1] = max(0LL, min_needed[j] - 1);
            }
            
            if (c_used <= k) good = true;
        }
        
        if (good) {
            ans = tm;
            lb = tm + 1;
        } else {
            ub = tm - 1;
        }
    }
    
    cout << ans << nl;
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) solve();
}
```
 **Feedback*** Good problem 

 
[*623*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*60*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*90*](https://codeforces.com/data/like?action=like "I like this")
[1856D - More Wrong](../problems/D._More_Wrong.md "Codeforces Round 890 (Div. 2) supported by Constructor Institute")

 **Hints****Hint 1**What can you say about index j if the number of inversion in [pi,pi+1,…,pj−1] is the same as in [pi,pi+1,…,pj]?

 **Hint 2**Define a function to calculate f(l,r)= the position of the maximum in [pl,pl+1,…,pr].

 **Hint 3**Divide and conquer.

 **Tutorial**
### [1856D - More Wrong](../problems/D._More_Wrong.md "Codeforces Round 890 (Div. 2) supported by Constructor Institute")

Let $q(l, r)$ be be the number of inversions in the subarray $[p_l, p_{l + 1}, \ldots p_r]$. If $l = r$, we have $q(l, r) = 0$, otherwise, $q(l, r) = $ is equal to the result of the query "? l r".

Let $f(l, r)$ calculate the index of the maximum value in $p_l, p_{l+1}, \ldots, p_r$. If $l = r$, we have $f(l, r) = l$.

Suppose $l < r$. Let $i := f(l, m)$ and $j := f(m + 1, r)$, where $m := \lfloor \frac{l + r}{2} \rfloor$. Let's compare $q(l, j - 1)$ and $q(l, j)$. 

If they are equal, $p_j$ is greater than all the elements in the subarray $[p_l, p_{l + 1}, \ldots, p_m]$, so $f(l, r) = j$.

If $q(l, j - 1) < q(l, j)$, $p_j$ is not greater that all the elements in the subarray $[p_l, p_{l + 1}, \ldots, p_m]$, and thus, the maximum on the whole subarray is $p_i$, so $f(l, r) = i$.

Note that the case $q(l, j - 1) > q(l, j)$ is impossible, since all inversions in the subarray $[p_l, p_{l + 1}, \ldots, p_{j - 1}]$ remain as inversions for the subarray $[p_l, p_{l + 1}, \ldots, p_j]$. 

To find the values of $q(l, j - 1)$ and $q(l, j)$, we will use $(j - 1 - l)^2 + (j - l)^2 \le (r - l)^2 + (r - l)^2 = 2 \cdot (r - l)^2$ coins.

Let $g_n$ be the number of coins needed to find the maximum on a subarray of length $n$. We will prove by induction that $g_n \le 4 \cdot n^2$ for all natural $n$.

Base case: $n = 1$, $g_1 := 0 \le 4 \cdot n^2 = 4$.

Induction step: let $m := \lceil \frac{n}{2} \rceil$. From the statements above, we have: $$g_n \le 2 \cdot (n - 1)^2 + g_{m} + g_{n - m} \le$$ $$2 \cdot (n - 1)^2 + 4 \cdot (m^2 + (n - m)^2) =$$ $$6n^2 + 8m^2 + 2 - 8nm - 4n =$$ $$4n^2 + 2 \cdot (n^2 - 4nm + 4m^2) + 2 - 4n =$$ $$4n^2 + 2 \cdot (n - 2m)^2 + 2 - 4n \le$$ $$4n^2 + 2 \cdot 1 + 2 - 4n =$$ $$4n^2 + 4 - 4n \le 4n^2$$

Thus, to calculate $f(1, n)$, the answer to our problem, we will use $g_n \le 4 \cdot n^2$ coins, which comfortably fits into the problem's $5 \cdot n^2$ coin limit.

Complexity: $\mathcal{O}(n)$

 **Solution**
```cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = 'n';
typedef long long ll;
typedef long double ld;

using namespace std;

int query(int l, int r) {
    if (l == r) return 0;
    cout << "? " << l << ' ' << r << endl;
    
    int res;
    cin >> res;
    return res;
}

// Finds max on p[l; r]
int solve(int l, int r) {
    if (l == r) return l;
    
    int m = (l + r) / 2;
    int a = solve(l, m);
    int b = solve(m + 1, r);
    
    int r1, r2;
    r1 = query(a, b - 1);
    r2 = query(a, b);
    
    if (r1 == r2) {
        return b;
    } else {
        return a;
    }
}

void solve() {
    int n;
    cin >> n;
    
    int ans = solve(1, n);
    cout << "! " << ans << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
```
 **Feedback*** Good problem 

 
[*255*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*14*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*20*](https://codeforces.com/data/like?action=like "I like this")
[1856E1 - PermuTree (easy version)](../problems/E1._PermuTree_(easy_version).md "Codeforces Round 890 (Div. 2) supported by Constructor Institute")

 **Hints****Hint 1**Fix the value of lca(u,v).

 **Hint 2**You can solve the problem independently for each value of lca(u,v).

 **Hint 3**Do dynamic programming.

 **Hint 4**For each subtree of lca(u,v), we only care about how many vertices are > or < less than alca(u,v).

 **Hint 5**This dynamic programming solution can actually be made to work in O(n2).

 **Tutorial**
### [1856E1 - PermuTree (easy version)](../problems/E1._PermuTree_(easy_version).md "Codeforces Round 890 (Div. 2) supported by Constructor Institute")

Let's consider the subproblem of maximizing the number of suitable pairs for some fixed $\operatorname{lca}(u, v) = x$. Then, we want to maximize the number of pairs $(u, v)$ such that $a_u < a_x < a_v$ and $u$ and $v$ are in different subtrees of $x$. So for each subtree of $x$, we only care about the number of vertices with $a_v > a_{x}$ and about the number of vertices with $a_v < a_x$.

Suppose vertex $x$ has $m$ subtrees and the $i$-th of them has $s_i$ vertices in it and $b_i$ vertices less with $a_v < a_x$. We will prove later that a suitable permutation $a$ exists for all possible correct values of $b_i$ (that is $0 \le b_i \le s_i$).

Then, the total number of suitable pairs (and the value we are trying to maximize) is equal to: $(s_1 - b_1) \cdot(0 + b_2 + \ldots + b_m) + (s_2 - b_2) \cdot(b_1 + 0 + \ldots + b_m) + \ldots + (s_m - b_m) \cdot(b_1 + b_2 + \ldots + 0)$.

Let $dp[i][B]$ be the maximum possible number of suitable pairs such that $u$ and $v$ lie in the first $i$ subtrees and $b_1 + b_2 + \cdots + b_i = B$ ($0 \le b_j \le s_j$ for all $1 \le j \le i$). Also define $S_i := s_1 + s_2 + \ldots + s_i$. Then: 

* $dp[1][B] := 0$ for $0 \le B \le s_1$.
* $dp[i][B] := \max\limits_{\max(0, B - S_{i-1}) \le b_i \le \min(s_i, B)}{(dp[i - 1][B - b_i] + b_i \cdot (S_{i-1} - (B - b_i)) + (s_i - b_i) \cdot (B - b_i))}$ for $2 \le i \le m$ and $0 \le B \le S_{i}$.

 In the statement above: 

* The limits for $b_i$ are $\max(0, B - S_{i-1}) \le b_i \le \min(s_i, B)$ because:
	+ $0 \le b_i \le s_i$ must hold,
	+ $0 \le B - b_i \le S_{i - 1}$ must hold.
* $dp[i - 1][B - b_i]$ is the number of suitable pairs $(u, v)$ in the first $i - 1$ subtrees.
* $b_i \cdot (S_{i-1} - (B - b_i))$ is the number of suitable pairs $(u, v)$ where $u$ lies in the $i$-th subtree and $v$ lies in the first $i - 1$ subtrees.
* $(s_i - b_i) \cdot (B - b_i)$ is the number of suitable pairs $(u, v)$ where $v$ lies in the $i$-th subtree and $u$ lies in the first $i - 1$ subtrees.

The maximum possible number of suitable pairs is equal to $\max\limits_{0 \le B \le S_m}{dp[m][B]}$.

Let's calculate the complexity of this dynamic programming subproblem. To do that, it's easier to consider iterating over $b_i$ and then iterating over all suitable values of $B$. Then, from the condition $0 \le b_i \le s_i$ we get $s_i + 1$ values of $b_i$, and from the condition $0 \le B - b_i \le S_{i - 1} \implies b_i \le B \le b_i + S_{i - 1}$ we get $S_{i - 1} + 1$ suitable values of $B$ for each $b_i$. 

Taking into account that the $dp[i][B]$ array has $m \cdot (S_m + 1)$ values, adding everything up, the number of "operations" we get is equal to:

$$m \cdot (S_m + 1) + (s_2 + 1) \cdot (S_1 + 1) + (s_3 + 1) \cdot (S_2 + 1) + \ldots + (s_m + 1) \cdot (S_{m - 1} + 1) = $$

$$m \cdot (S_m + 1) + (s_2 \cdot S_1 + s_3 \cdot S_2 + \ldots + s_m \cdot S_{m-1}) + (s2 + \ldots + s_m) + (S_1 + \ldots + S_{m-1}) + (m - 1) \le $$

$$m \cdot S_m + m + (s_2 \cdot S_1 + s_3 \cdot S_2 + \ldots + s_m \cdot S_{m-1}) + S_m + (m - 1) \cdot S_m + m = $$

$$2m \cdot (S_m + 1) + (s_2 \cdot S_1 + s_3 \cdot S_2 + \ldots + s_m \cdot S_{m-1}) \le $$

$$2mn + (s_2 \cdot S_1 + s_3 \cdot S_2 + \ldots + s_m \cdot S_{m-1})$$

Returning to the original problem, let's solve the subproblem for each $x$ from $1$ to $n$ and add up the results. This is the upper bound on the answer, and we will prove a bit later that a suitable permutation $a$ exists.

Let's change our notation a bit: 

* $m_x$ is the number of subtrees of vertex $x$.
* $s_{x,i}$ is the size of the $i$-th subtree of vertex $x$.
* $S_{x,i}$ is equal to $s_{x,1} + s_{x,2} + \ldots + s_{x,i}$.
* $b_{x,i}$ is the number of vertices in the $i$-th subtree for which $a_v < a_x$.

Adding up the number of "operations" for all subproblems, we get:

$$\displaystyle\sum_{x=1} ^{n} (2m_xn + s_{x,2} \cdot S_{x,1} + s_{x,3} \cdot S_{x,2} + \ldots + s_{x,m_x} \cdot S_{x,m_x-1}) = $$ $$2n \cdot (n - 1) + \displaystyle\sum_{x=1} ^{n} (s_{x,2} \cdot S_{x,1} + s_{x,3} \cdot S_{x,2} + \ldots + s_{x,m_x} \cdot S_{x,m_x-1})$$

Consider an undirected graph with $n$ vertices where there are initially no edges. You can think of the value of $s_{x,j} \cdot S_{x,j-1}$ as the number of edges added between each vertex of the first $j-1$ subtrees of $x$ and the $j$-th subtree of $x$. Since each pair of $(x, j)$ accounts for a unique set of edges of size $s_{x,j} \cdot S_{x,j-1}$, the sum $\sum_{x=1} ^{n} (\ldots)$ can be bounded above by $\frac{n \cdot (n - 1)}{2}$, the maximum number of unique edges in a graph with $n$ vertices:

$$2n \cdot (n - 1) + \displaystyle\sum_{x=1} ^{n} (s_{x,2} \cdot S_{x,1} + s_{x,3} \cdot S_{x,2} + \ldots + s_{x,m_x} \cdot S_{x,m_x-1}) \le$$

$$2n \cdot (n - 1) + \frac{n \cdot (n - 1)}{2}$$

So we get a complexity of $\mathcal{O}(n^2)$.

You can read more about this complexity analysis in section 7 of this [Codeforces blog](https://codeforces.com/blog/entry/100910). 

$ $

We solve independently for each value of $\operatorname{lca}(u,v)$ and add up the answers to get an upper bound for $f(a)$. We will prove by constructing $a$ that this bound is achievable.

Let $g(x, L)$ be a function that takes a vertex $x$ and a set of integers $L$, assigns some value from $L$ to $a_x$, and then calls $g(y, L_y)$ for all children of $x$ (direct descendants), where the sets $L_y$ do not intersect and their union is equal to $L \setminus \{ a_x \}$.

How it works: 

1. Let $y_{1}, \ldots y_{m_x}$ be the children of vertex $x$ and $L_{y_i}$ initially be empty sets. Suppose that for vertex $x$ it is optimal to have the values of $b_{x,1}, b_{x,2}, \ldots, b_{x,m_x}$ be equal to $c_1, c_2, \ldots, c_{m_x}$ respectively.
2. For each $i$ from $1$ to $m_x$, take the $c_i$ smallest values from $L$, remove them from $L$, and add them to the set $L_{y_i}$.
3. Set $a_x$ to the smallest value in $L$ and remove it from the set.
4. For each $i$ from $1$ to $m_x$, take the $s_i - c_i$ smallest values from $L$, remove them from $L$, and add them to the set $L_{y_i}$.
5. For each $i$ from $1$ to $m_x$, call $g(y_i, L_{y_i})$.

Calling $g(x, \{1, 2, \ldots n \})$ constructs an optimal permutation $a$ for the given tree.

Complexity: $\mathcal{O}(n^2)$

Note: you can change $dp[i][B]$ to $dp[B]$ and iterate $B$ from $S_i$ to $0$. This improves the memory usage, but does not change the time complexity.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = 'n';
typedef long long ll;
typedef long double ld;

using namespace std;

const int maxn = 1000000;

vector<int> g[maxn];
int s[maxn];
ll ans = 0;

void dfs(int v, int p = -1) {
    vector<ll> a;
    s[v] = 1;
    
    for (int u: g[v]) {
        if (u == p) continue;
        dfs(u, v);
        s[v] += s[u];
        
        a.push_back(s[u]);
    }
    
    vector<ll> dp(s[v]);
    ll cs = 0;
    for (int x: a) {
        for (ll i = cs + x; i >= 0; i--) {
            for (ll pr = min(cs, i); pr >= max(0LL, i - x); pr--) {
                ll j = i - pr;
                dp[i] = max(dp[i], dp[pr] + j * (cs - pr) + pr * (x - j));
            }
        } 
        cs += x;
    }
    
    ans += *max_element(all(dp));
    dp.clear();
    a.clear();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        g[x - 1].push_back(i);
    }
    
    dfs(0);
    
    cout << ans << nl;
}
```
 **Feedback*** Good problem 

 
[*218*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*38*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*33*](https://codeforces.com/data/like?action=like "I like this")
[1856E2 - PermuTree (hard version)](../problems/E2._PermuTree_(hard_version).md "Codeforces Round 890 (Div. 2) supported by Constructor Institute")

 **Hints****Hint 0**Read hints for the easy version.

 **Hint 1**For each lca(u,v), we actually need to do subset sum on the subtree sizes.

 **Hint 2**If there is a very subtree that is bigger than the sum of the sizes of the other subtrees, you don't have to do subset sum.

 **Hint 3**Optimize subset sum to O(s√s), where s is the sum of the sizes of the subtrees for some fixed lca(u,v). 

 **Hint 4**Use bitset to optimize subset sum even more.

 **Tutorial**
### [1856E2 - PermuTree (hard version)](../problems/E2._PermuTree_(hard_version).md "Codeforces Round 890 (Div. 2) supported by Constructor Institute")

First of all, the most important takeaways from the editorial for the easy version: 

* For each $x$ from $1$ to $n$, you can solve $n$ independent subproblems of maximizing the number of suitable pairs for a fixed value of $\operatorname{lca}(u, v) = x$, and then add up the results to get the final answer.
* For each subproblem, the number of suitable pairs of vertices can be calculate based on the sizes of all the child subtrees $s_{x,i}$ and the number of vertices with $a_v < a_x$ in each of them, which we will call $b_{x,i}$.

Consider the subproblem for some $x$. Let $m_x$ be the number of child subtrees of vertex $x$. Suppose some optimal values of $b_{x,1}, b_{x,2}, \ldots b_{x,m_x}$ that maximize the number of suitable pairs are $c_1, c_2, \ldots c_{m_x}$ respectively.

$ $

Claim: there exists an optimal solution where $c_i = 0$ or $c_i = s_{x,i}$ for all $i$ from $1$ to $m_x$.

Proof: let's consider some optimal solution $c_1, c_2, \ldots c_{m_x}$ where $0 < c_i < s_{x,i}$ for some $i$. Suppose $D$ is the number of suitable pairs of vertices such that both $u$ and $v$ don't lie in the $i$-th child's subtree. Then, the total number of suitable pairs is equal to: $$D + c_i \cdot \sum_{j \neq i}{(s_{x, j} - c_j)} + (s_{x, i} - c_i) \cdot \sum_{j \neq i} c_j$$ If we define $C_1 := \sum_{j \neq i}{(s_{x, j} - c_j)}$ and $C_2 := \sum_{j \neq i} c_j$, we get an even simpler formula: $$D + c_i \cdot C_1 + (s_{x, i} - c_i) \cdot C_2 =$$ $$(D + C_2 \cdot s_{x,i}) + c_i \cdot (C_1 - C_2)$$

The values of $(D + C_2 \cdot s_{x,i})$, $C_1$, and $C_2$ don't depend on the value of $c_i$, so we can freely change it to anything from $[0; s_{x, i}]$ to maximize the value of the formula. So: 

* If $C_1 \ge C_2$, the value of the formula will not decrease if we set $c_i$ to $s_{x,i}$.
* If $C_1 \le C_2$, the value of the formula will not decrease if we set $c_i$ to $0$.

Since at least one of this conditions has to be true, we can always take some optimal solution with $k$ indices such that $0 < c_i < s_{x, i}$ and get an optimal solution with $k - 1$ such indices. We repeat this process until $k$ becomes $0$, which means that $c_i = 0$ or $c_i = s_{x, i}$ for all $i$ from $1$ to $m_x$, as was stated in the claim. 

$ $

Consider an optimal solution $c_1, c_2, \ldots c_{m_x}$ where $c_i$ is equal to either $0$ or $s_{i, x}$. Let $S_1$ be the sum of $s_{i, x}$ over all $i$ such that $c_i = 0$ and $S_2$ be the sum of $s_{i, x}$ over all $i$ such that $c_i = s_{x, i}$. Then, the number of suitable pairs is equal to: $$S_1 \cdot S_2$$

If we define $S$ as $s_{x, 1} + s_{x, 2} + \ldots s_{x,m_x}$, we can see that $S_2$ is equal to $S - S_1$, so we are actually maximizing the value of: $$S_1 \cdot (S - S_1)$$

To do this, we can iterate $S_1$ from $0$ to $S$, find if it is possible to choose some subset of indices $I \subseteq \{1, 2, \ldots, m_x \}$ such that $\displaystyle\sum_{i \in I}{s_{x,i}} = S_1$, and update the current best answer if such a set $I$ exists.

Doing this efficiently is known as the subset sum problem (or some variation of it). One of the simplest ways to solve it in this particular case with a $\mathcal{O}(m_x \cdot S)$ dynamic programming solution: $dp[j][S_1]$ is equal to $1$ if there exists a set of indices $I \subseteq \{ 1, 2, \ldots, j \}$ such that $\displaystyle\sum_{i \in I}{s_{x,i}} = S_1$ and is equal to $0$ otherwise. We will proceed to optimize it.

The first standard optimization will bring the complexity down to $\mathcal{O}(S \sqrt S)$, you can read about it in Section 3 of this [Codeforces blog](https://codeforces.com/blog/entry/100910) or in the "Subset Sum Speedup 1" section of this [Codeforces blog](https://codeforces.com/blog/entry/98663).

$ $

Since we are trying to maximize the value of $S_1 \cdot (S - S_1)$, the optimal choice will also minimize the value of $| (S - S_1) - S_1 | = | S - 2S_1 |$.

Claim: denote $\max(s_{x,1}, \ldots, s_{x,m_x})$ as $M_x$. If $M_x \ge \frac{S}{2}$, the smallest possible value of $| S - 2S_1 |$ is achieved with $S_1 = M_x$ or $S_1 = S - M_x$.

Proof: it is clearly possible to get $S_1 = M_x$. Suppose it is possible to get some value of $S_1$ in the segment $[S - M_x + 1; M_x - 1]$. Then, $M_x$ did not contribute to the sum $S_1$, and so $S_1 + M_x$ can't exceed $S$. But $S_1 + M_x \ge S - M_x + 1 + M_x = S + 1$, so we get a contradiction, hence it is not possible to get some $S_1 \in [S - M_x + 1; M_x - 1]$.

So if we have $M_x \ge \frac{S}{2}$, we actually don't have to run the dynamic programming part. We will now analyze the complexity of the solution with this optimization.

$ $

Let's now define $S_x$ as $s_{x, 1} + \ldots + s_{x, m_x}$. Let's also call a vertex $x$ heavy if $M_x \ge \frac{S_x}{2}$ and light otherwise. 

Suppose that vertex $x$ has $k$ light ancestors on it's path to the root: 

* Every subtree of a light vertex $v$ has at most $\frac{S_v}{2}$ vertices in it.
* Every subtree of a heavy vertex $v$ has at most $S_v - 1$ vertices in it.

 Since there are $k$ light ancestors, we can conclude that $S_x \le \frac{S_1}{2^k} = \frac{n}{2^k}$.For each $k$ from $0$ to $n$, let $L_k$ be the set of light vertices with exactly $k$ light ancestors (a vertex doesn't count as it's own ancestor): 

* Note that if two light vertices $u$ and $v$ are in the same set $L_k$, one can't be the ancestor of the other. So, the sum $\sum_{x \in L_{k}} S_x$ does not exceed $n$.
* $S_x \le \frac{n}{2^k}$ for all $x \in L_{k}$.

For some $k$, let's calculate the total number of "operations" taken in the dynamic programming part for all $x \in L_k$. To do that, we: 

* Iterate over the number of vertices in the set $L_{k}$, let's call it $p$, from $0$ to $n$.
* Let $d_1, d_2, \ldots, d_p$ be the sizes of the subtrees of vertices in $L_{k}$. Then we need to maximize the value of: $$d_1 \sqrt d_1 + d_2 \sqrt d_2 + \ldots + d_p \sqrt d_p$$ over all $d_1, d_2, \ldots, d_p$ such that $1 \le d_n \le \frac{n}{2^k}$ and $d_1 + \ldots + d_n \le n$.

You might have noticed that the above process can be simplified by allowing $d_i$ to be equal to $0$. In that case, the number of vertices $p$ is equal to the number of positive integers in $d_1, d_2, \ldots, d_n$, and we need to maximize:

$$d_1 \sqrt d_1 + d_2 \sqrt d_2 + \ldots + d_n \sqrt d_n$$

over all integer $d_1, d_2, \ldots , d_n$ such that $0 \le d_n \le \frac{n}{2^k}$ and $d_1 + \ldots + d_n \le n$.

Let $t := \left\lfloor \frac{n}{2^k} \right\rfloor$. We'll assume $t \ge 1$, otherwise, $d_i$ is equal to $0$ for all $1 \le i \le n$ and the sum is always equal to $0$.

Lemma 1: it is optimal to have $d_1 + d_2 + \ldots + d_n = n$.

Proof: if we can increase some $d_i$, it is clearly optimal to do so.

Lemma 2: suppose the maximum is achieved on the set of values $e_1, e_2, \ldots, e_n$. Then there does not exist a pair of indices $i$ and $j$ such that $0 < e_i \le e_j < t$.

Proof: define $f(x) := \left( x + 1 \right) \sqrt {x + 1} - x \sqrt x$. Note that $f(x)$ is a monotonically increasing function for all $x \ge 0$. You can prove it by, for example, analyzing it's derivative: $\frac{3}{2} (\sqrt {x + 1} - \sqrt x)$. 

If we decrease $e_i$ by $1$ and increase $e_j$ by $1$, the sum changes by: $$(e_j + 1) \sqrt {e_j + 1} + (e_i - 1) \sqrt {e_i - 1} - e_j \sqrt e_j - e_i \sqrt e_i =$$ $$ f(e_j) - f(e_i - 1) > 0$$

By doing this, we haven't broken any constraints on the values of $e_i$, but have increased the total sum, so the previous values of $e$ couldn't have been optimal.

This lemma gives us the nice property that the optimal values of $e_1, e_2, \ldots, e_n$ look something like $t, \ldots, t, y, 0, \ldots, 0$; where $0 < y < t$.

With this we can conclude that the total number of "operations" performed for all vertices in $L_k$ is at most: $$\left\lceil \frac{n}{t} \right\rceil \cdot t \sqrt t \le \left( \frac{n}{t} + 1 \right) \cdot t \sqrt t \le (n + t) \sqrt t \le 2n \sqrt t$$

Adding this up over all $k$ with $t \ge 1$, we get: $$2n \cdot \left(\sqrt{\left\lfloor \frac{n}{1} \right\rfloor} + \sqrt{\left\lfloor \frac{n}{2} \right\rfloor} + \sqrt{\left\lfloor \frac{n}{4} \right\rfloor} + \sqrt{\left\lfloor \frac{n}{8} \right\rfloor} + \ldots + 1 \right) \le$$ $$2n \cdot \left( \sqrt{\frac{n}{1}} + \sqrt{\frac{n}{2}} + \sqrt{\frac{n}{4}} + \sqrt{\frac{n}{8}} + \ldots \right) =$$ $$2n \sqrt n \cdot \left(1 + \frac{1}{\sqrt{2}} + \frac{1}{\sqrt{4}} + \frac{1}{\sqrt{8}} + \ldots \right) $$

We can notice that the sum in the brackets in bounded by the sum of an infinite geometric progression with a sum of $\frac{\sqrt{2}}{\sqrt{2} - 1} \le 4$, so the total sum is: $$\le 2n \sqrt n \cdot 4 = 8n \sqrt n = \mathcal{O}(n \sqrt n)$$

Finally, we will also use bitsets to speed up our dynamic programming part and bring the complexity down to $\mathcal{O}(\frac{n \sqrt n}{w})$, where $w$ is the word size, usually $32$ or $64$.

You can learn about bitsets in this [Codeforces blog](https://codeforces.com/blog/entry/73558). To get a simple variable length bitset in C++, refer to this [comment](https://codeforces.com/blog/entry/100910?#comment-896093).

Complexity: $\mathcal{O}(\frac{n \sqrt n}{w})$.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = 'n';
typedef long long ll;
typedef long double ld;

using namespace std;

const int maxn = 1000000;

vector<int> g[maxn];
int s[maxn];
ll ans = 0;
vector<ll> b;
ll closest;

template <int len = 1>
void subset_sum(int n) {
    if (n >= len) {
        subset_sum<std::min(len*2, maxn)>(n);
        return;
    }
    
    bitset<len> dp;
    
    dp[0] = 1;
    for (ll x: b) {
        dp = dp | (dp << x);
    }
    
    ll cv = n;
    closest = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[i] && abs(i - (n - i)) < cv) {
            closest = i;
            cv = abs(i - (n - i));
        }
    }
}

ll solve(vector<ll> &a) {
    if (a.empty()) return 0;
    
    sort(allr(a));
    ll cs = 0;
    for (ll x: a) cs += x;
    
    if (a[0] * 2 >= cs) {
        return a[0];
    }
    
    int n = gsize(a);
    a.push_back(0);
    
    b.clear();
    int pi = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            ll cnt = i - pi;
            ll x = a[i - 1];
            
            ll j = 1;
            while (j < cnt) {
                b.push_back(x * j);
                cnt -= j;
                j *= 2;
            }            
            b.push_back(x * cnt);

            pi = i;
        }
    }
    
    subset_sum(cs);
    return closest;
}

void dfs(int v, int p = -1) {
    vector<ll> a;
    s[v] = 1;
    
    for (int u: g[v]) {
        if (u == p) continue;
        dfs(u, v);
        s[v] += s[u];
        
        a.push_back(s[u]);
    }
    
    ll x = solve(a);
    ans += x * (s[v] - 1 - x);
    a.clear();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        g[x - 1].push_back(i);
    }
    
    dfs(0);
    
    cout << ans << nl;
}
```
 **Feedback*** Good problem 

 
[*101*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*8*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*200*](https://codeforces.com/data/like?action=like "I like this")
**UPD: Tutorial for E1 has been added.**

**UPD2: Tutorial for E2 has been added.**

