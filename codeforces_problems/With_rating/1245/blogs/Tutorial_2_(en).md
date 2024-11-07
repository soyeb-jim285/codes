# Tutorial_2_(en)

[1245A - Good ol' Numbers Coloring](../problems/A._Good_ol'_Numbers_Coloring.md "Codeforces Round 597 (Div. 2)")

 **Tutorial**
### [1245A - Good ol' Numbers Coloring](../problems/A._Good_ol'_Numbers_Coloring.md "Codeforces Round 597 (Div. 2)")

If $\gcd(a, b) \neq 1$, print "Infinite". This is correct because any integer that isn't divisible by $\gcd(a, b)$ will not be expressible in the form $ax + by$ since $ax + by$ is always divisible by $\gcd(a, b)$. 

Otherwise, print "Finite". To show that this is correct, we will prove that any integer greater than $ab$ is colored white. Let $x$ be an integer greater than $ab$. Consider the set $S = \{x, x - a, x - 2a, \ldots, x - (b - 1) a\}$. If, for any $y \in S$, $y$ is divisible by $b$, we are done. Otherwise, by the pigeonhole principle, there exists distinct $x - sa, x - ta \in S$ such that they have the same remainder when divided by $b$, thus $b$ divides $(x - sa) - (x - ta) = a (t - s)$. WLOG, let $s < t$. Thus, $0 < t - s$ and $b$ divides $t - s$, since $\gcd(a, b) = 1$. But $t - s \leq t < b$. However, it is not possible for $b$ to divide any integer $x$ such that $0 < x < b$, thus we arrive at a contradiction.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    
    return a;
}

int main()
{
    int t;
    for (cin >> t; t--;)
    
    {
        int a, b;
        cin >> a >> b;
        
        if (gcd(a, b) == 1)
            cout << "Finite" << 'n';
        else
            cout << "Infinite" << 'n';
    }
    
    return 0;
}
```
[1245B - Restricted RPS](../problems/B._Restricted_RPS.md "Codeforces Round 597 (Div. 2)")

 **Tutorial**
### [1245B - Restricted RPS](../problems/B._Restricted_RPS.md "Codeforces Round 597 (Div. 2)")

Let $A$, $B$, $C$ be the number of rocks, papers, and scissors in Bob's sequence, respectively. It is easy to see that Alice can win at most $w := \min(A, b) + \min(B, c) + \min(C, a)$ hands.

So if $2w < n$, Alice can't win.

Otherwise, Alice can always win. One way to construct a winning sequence of hands for Alice is as follows: 

1. Create a sequence of length $n$.
2. For Bob's first $\min(A, b)$ rock hands, put a paper hand in the corresponding position in our sequence.
3. For Bob's first $\min(B, c)$ paper hands, put a scissors hand in the corresponding position in our sequence.
4. For Bob's first $\min(C, a)$ scissors hands, put a rock hand in the corresponding position in our sequence.
5. Just fill in the other elements of the sequence by the remaining hands that Alice has.

By construction, Alice uses exactly $a$ rock hands, $b$ paper hands, and $c$ scissors hands. Also, Alice beats Bob exactly $w$ times. Since $2w \ge n$, Alice wins.

 **Solution**
```cpp
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    for (cin >> q; q--;)
    {
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        
        vector<int> count(26);
        for (char x : s)
        	count[x - 'A']++;
        
        int wins = min(a, count['S' - 'A']) + min(b, count['R' - 'A']) + min(c, count['P' - 'A']);
        
        if (2 * wins < n)
        {
        	cout << "NO" << 'n';continue;
        }
        
        cout << "YES" << 'n';
        string t;
        for (int i = 0; i != n; ++i)
        {
        	if (s[i] == 'S' && a)
        	{
        		t += 'R';
        		a--;
        	}
        	else if (s[i] == 'R' && b)
        	{
        		t += 'P';
        		b--;
        	}
        	else if (s[i] == 'P' && c)
        	{
        		t += 'S';
        		c--;
        	}
        	else
        		t += '_';
        }
        for (int i = 0; i != n; ++i)
        {
        	if (t[i] != '_')
        		continue;
        	
        	if (a)
        	{
        		t[i] = 'R';
        		a--;
        	}
        	else if (b)
        	{
        		t[i] = 'P';
        		b--;
        	}
        	else
        	{
        		t[i] = 'S';
        		c--;
        	}
        }
        cout << t << 'n';
    }
    
    return 0;
}
```
[1245C - Constanze's Machine](../problems/C._Constanze's_Machine.md "Codeforces Round 597 (Div. 2)")

 **Tutorial**
### [1245C - Constanze's Machine](../problems/C._Constanze's_Machine.md "Codeforces Round 597 (Div. 2)")

If $s$ has any 'm' or 'w', the answer is 0. Otherwise, we can do dp.

Define $dp_i$ to be the number of strings that Constanze's machine would've turned into the first $i$ characters of $s$. Then, $dp_0 = dp_1 = 1$. For $i > 1$, transition is $dp_i = dp_{i - 1} + dp_{i - 2}$ if both $s_i = s_{i - 1}$ and $s_i$ is either 'u' or 'n', and simply $dp_i = dp_{i - 1}$ otherwise. Answer is $dp_{|s|}$.

Alternatively, notice that the maximum cardinality segment consisiting of $k$ letters 'u' or 'n' multiplies the answer by the $k$-th term of Fibonacci sequence. Thus, you can precalculate it and some sort of two iterators.

 **Solution**
```cpp
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

const int MOD = 1000000007;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    for (char x : s)
    {
        if (x == 'w' || x == 'm')
        {
            cout << 0 << 'n';
            return 0;
        }
    }
    
    int n = s.size();
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1];
        if (s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n'))
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }
    
    cout << dp[n] << 'n';
    
    return 0;
}
```
 **Solution (Arpa)**
```cpp
// In the name of Allah.
// We're nothing and you're everything.
// Ya Ali!
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int maxn = 1e5 + 14, mod = 1e9 + 7;

int n, fib[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    fib[0] = fib[1] = 1;
    for(int i = 2; i < maxn; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    string s;
    cin >> s;
    n = s.size();
    if(s.find('m') != -1 || s.find('w') != -1)
        return cout << "0n", 0;
    int ans = 1;
    for(int i = 0, j = 0; i < n; i = j){
        while(j < n && s[j] == s[i])
            j++;
        if(s[i] == 'n' || s[i] == 'u')
            ans = (ll) ans * fib[j - i] % mod;
    }
    cout << ans << 'n';
}
```
[1245D - Shichikuji and Power Grid](../problems/D._Shichikuji_and_Power_Grid.md "Codeforces Round 597 (Div. 2)")

 **Tutorial**
### [1245D - Shichikuji and Power Grid](../problems/D._Shichikuji_and_Power_Grid.md "Codeforces Round 597 (Div. 2)")

Claim. Let $i$ be such that $c_i$ is minimum, then there is an optimal configuration with a power station in City $i$.

Proof. Consider an optimal configuration. Let's say that City $u$ and City $v$ are in the same component if they are connected or City $v$ is connected to a City $w$ such that City $w$ is in the same component as City $u$. Consider the cities that are in the same component as City $i$. Exactly one of these cities have a power station, since having a power station in one of these cities is enough to provide electricity to all of them. Let City $j$ be the one with a power station. If $i = j$, then we are done. Otherwise, there are three cases: $c_i < c_j$, $c_i = c_j$, $c_i > c_j$. The first case leads to a contradiction since having a power station in City $i$ would be more optimal. The third case also leads to a contradiction since $c_i$ is minimum. For the remaining case, having a power station in City $i$ would be just as optimal.

Let $i$ be such that $c_i$ is minimum. Build a power station in City $i$. For $j \neq i$, define $C_j := min(c_j, (k_i + k_j) \cdot D(i, j))$ where $D(i, j)$ is the manhattan distance between City $i$ and City $j$. Notice that the problem has been reduced to a similar problem, except that there is one less city, and $c$ values have been changed to the corresponding $C$ values. Thus, we can keep reducing until there are no cities left.

Alternatively, you can think of it the following way. Let's call a connection between City $u$ and City $v$, an undirected edge $(u, v)$ with the weight $(k_u + k_v) \cdot D(u, v)$. Create a dummy City $0$ and connect each City $u$ to it with an edge $(0, u)$ with the weight $c_u$. The problem now is to find a minimal spanning tree of this graph. Prim's algorithm can do this in $O(n^2)$.

 **Solution**
```cpp
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    pair<int, int> pos[n];
    for (int i = 0; i != n; ++i)
        cin >> pos[i].first >> pos[i].second;
    int c[n];
    for (int i = 0; i != n; ++i)
        cin >> c[i];
    int k[n];
    for (int i = 0; i != n; ++i)
        cin >> k[i];
    
    long long ans = 0;
    vector<int> power_plants;
    vector<pair<int, int>> connections;
    
    vector<bool> done(n);
    vector<int> parent(n, -1);
    for (int _n = n; _n--;)
    {
        int mi = 2000000000;
        int u = -1;
        for (int i = 0; i != n; ++i)
        {
            if (done[i])
                continue;
            
            if (c[i] < mi)
            {
                mi = c[i];
                u = i;
            }
        }
        
        ans += mi;
        done[u] = 1;
        if (parent[u] == -1)
            power_plants.push_back(u);
        else
            connections.push_back(make_pair(min(parent[u], u), max(parent[u], u)));
        
        for (int i = 0; i != n; ++i)
            if (1LL * (k[u] + k[i]) * (abs(pos[u].first - pos[i].first) + abs(pos[u].second - pos[i].second)) < c[i])
            {
                c[i] = (k[u] + k[i]) * (abs(pos[u].first - pos[i].first) + abs(pos[u].second - pos[i].second));
                parent[i] = u;
            }
    }
    
    cout << ans << 'n';
    cout << power_plants.size() << 'n';
    sort(power_plants.begin(), power_plants.end());
    for (int x : power_plants)
        cout << x + 1 << ' ';
    cout << 'n';
    cout << connections.size() << 'n';
    for (pair<int, int> x : connections)
        cout << x.first + 1 << ' ' << x.second + 1 << 'n';
    
    return 0;
}
```
 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

int main(){
    int n;
    scanf("%d", &n);
    vector<int> x(n), y(n);
    forn(i, n)
        scanf("%d%d", &x[i], &y[i]);
    vector<int> c(n), k(n);
    forn(i, n)
        scanf("%d", &c[i]);
    forn(i, n)
        scanf("%d", &k[i]);
    
    ++n;
    vector<int> p(n, -1);
    vector<int> d(n, int(1e9));
    vector<bool> used(n);
    
    forn(i, n - 1){
        d[i] = c[i];
        p[i] = n - 1;
    }
    used[n - 1] = true;
    
    long long ans = 0;
    vector<int> vv;
    vector<pair<int, int>> ee;
    
    forn(_, n - 1){
        int v = -1;
        forn(i, n) if (!used[i] && (v == -1 || d[v] > d[i]))
            v = i;
        
        if (p[v] == n - 1)
            vv.push_back(v + 1);
        else
            ee.push_back(make_pair(v + 1, p[v] + 1));
        ans += d[v];
        
        used[v] = true;
        forn(i, n) if (!used[i]){
            long long dist = (k[v] + k[i]) * 1ll * (abs(x[v] - x[i]) + abs(y[v] - y[i]));
            if (dist < d[i]){
                d[i] = dist;
                p[i] = v;
            }
        }
    }
    
    printf("%lldn", ans);
    printf("%dn", int(vv.size()));
    for (auto it : vv)
        printf("%d ", it);
    puts("");
    printf("%dn", int(ee.size()));
    for (auto it : ee)
        printf("%d %dn", it.first, it.second);
}
```
[1245E - Hyakugoku and Ladders](../problems/E._Hyakugoku_and_Ladders.md "Codeforces Round 597 (Div. 2)")

 **Tutorial**
### [1245E - Hyakugoku and Ladders](../problems/E._Hyakugoku_and_Ladders.md "Codeforces Round 597 (Div. 2)")

To make implementation easier, flatten the board into an array $a$ such that the $i$-th tile on the path is $a_i$. Define a function $f$ as follows: $f(i) = i$ if $a_i$ has no ladder, otherwise $f(i) = j$ where $j$ is such that the ladder from $a_i$ leads to $a_j$. Then, do dp.

Define $dp_i$ to be the minimum expected number of turns before the game ends when the player is at $a_i$. Then, $dp_{100} = 0$ since $a_{100}$ is the Goal. Next, use the formula $dp_i = 1 + \sum_{r = 1}^{6} \frac{1}{6} \cdot \min(dp_{g(i, r)}, dp_{f(g(i, r))})$ where $g(i, r) = i + r$ if $i + r \leq 100$ and $g(i, r) = i$ otherwise. Thus, for $95 \leq i \leq 99$, transition should be $dp_i = \frac{6}{100 - i} \cdot \left( 1 + \sum_{r = 1}^{100 - i} \frac{1}{6} \cdot \min(dp_{i + r}, dp_{f(i + r)}) \right)$. And for $i < 95$, transition is the same as the formula. Answer is $dp_1$.

Alternatively, instead of doing dp, we can use numerical methods. Initialize $\textrm{expected}_{100} = 0$ and $\textrm{expected}_1 = \textrm{expected}_2 = \cdots = \textrm{expected}_{99} = 1$. Then, repeat the following several times: from $i=99$ to $i=1$, assign $1 + \sum_{r = 1}^{6} \frac{1}{6} \cdot \min(\textrm{expected}_{g(i, r)}, \textrm{expected}_{f(g(i, r))})$ to $\textrm{expected}_i$. After each iteration, $\textrm{expected}_1$ will get closer to the answer. For this problem, 1000 iterations is more than enough to get AC using this method.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int grid[10][10];
    for (int i = 0; i != 10; ++i)
        for (int j = 0; j != 10; ++j)
            cin >> grid[i][j];
    
    int flat[10][10];
    for (int i = 0; i != 10; ++i)
        for (int j = 0; j != 10; ++j)
                flat[i][j] = (9 - i) * 10 + ((i & 1) ? j : 9 - j);
    
    int d = 1;
    int x = 9;
    int y = 0;
    int arr[100];
    for (int i = 0; i != 100; ++i)
    {
        arr[i] = flat[x - grid[x][y]][y];
        
        if (y + d == -1 || y + d == 10)
        {
            d *= -1;
            x--;
        }
        else
            y += d;
    }
    
    double dp[100];
    dp[99] = 0;
    for (int i = 98; i >= 0; --i)
    {
        dp[i] = 1;
        
        int c = 6;
        for (int r = 1; r <= 6; ++r)
        {
            if (i + r >= 100)
                continue;
            dp[i] += min(dp[i + r], dp[arr[i + r]]) / 6;
            c--;
        }
        
        dp[i] = 6 * dp[i] / (6 - c);
    }
    
    cout << setprecision(10) << fixed << dp[0] << 'n';
    
    return 0;
}
```
[1245F - Daniel and Spring Cleaning](../problems/F._Daniel_and_Spring_Cleaning.md "Codeforces Round 597 (Div. 2)")

 **Tutorial**
### [1245F - Daniel and Spring Cleaning](../problems/F._Daniel_and_Spring_Cleaning.md "Codeforces Round 597 (Div. 2)")

Claim. Let $x$, $y$ be nonnegative integers. If $x + y = x \oplus y$, then $x * y = 0$, where $x * y$ is the bitwise AND of $x$ and $y$.

Proof. Recall that bitwise XOR is just addition in base two without carry. So if addition is to be equal to addition in base two without carry, then there must be no carry when added in base two, which is what we wanted.

Define a function $f$ as follows: let $l$ and $r$ be nonnegative integers, then $f(l, r)$ should be the number of pairs of integers $(x, y)$ such that the following conditions are satisfied: 

* $l \leq x < r$
* $l \leq y < r$
* $x + y = x \oplus y$

Notice that $f(0, r) = 2r - 1 + f(1, r)$.

Claim. Let $l$ and $r$ be positive integers. Then, $f(2l, 2r) = 3 \cdot f(l, r)$.

Proof. Let $x$, $y$ be positive integers. Suppose we want the following conditions to be satisfied: 

* $2l \leq x < 2r$
* $2l \leq y < 2r$
* $x + y = x \oplus y$

 Consider the binary representations of $x$ and $y$. There are three ways to choose the rightmost bits of $x$ and $y$: $(0, 0)$, $(0, 1)$, and $(1, 0)$. And the number of ways to choose the other bits is always $f(l, r)$. Thus, $f(2l, 2r) = 3 \cdot f(l, r)$.What if $l$ and $r$ are not both even? Define a function $g$ as follows: let $x$ and $n$ be nonnegative integers, then $g(x, n)$ should be the number of integers $y$ such that the following conditions are satisfied: 

* $0 \leq y < n$
* $x + y = x \oplus y$

 Then, if $l$ is odd, $f(l + 1, r) = f(l, r) - 2 \cdot (g(l, r) - g(l, l))$, or $f(l, r) = f(l + 1, r) + 2 \cdot (g(l, r) - g(l, l))$. Similarly, if $r$ is odd, $f(l, r - 1) = f(l, r) - 2 \cdot (g(r - 1, r) - g(r - 1, l)$, or $f(l, r) = f(l, r - 1) + 2 \cdot (g(r - 1, r) - g(r - 1, l))$.Now all that remains is to implement $g$ efficiently. Define a function $\textrm{LSB}$ as follows: let $n$ be a positive integer, then $\textrm{LSB}(n)$ should be the least significant 1-bit of $n$. Next, define a function $h$ as follows: let $x$ and $n$ be positive integers, then $h(x, n)$ should be the number of integers $y$ such that the following conditions are satisfied: 

* $n - \textrm{LSB}(n) \leq y < n$
* $x + y = x \oplus y$

 Then, $g(x, n) = h(x, n) + g(x, n - \textrm{LSB}(n))$ if $n > 0$ and $g(x, n) = 0$ otherwise. Moreover, it is easy to implement $h$ so that its time complexity is logarithmic with respect to $n$. **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;

int f(int a, int b)
{
    int ret = 0;
    int zeroes = 0;
    
    for (int i = 1; i <= b; i <<= 1)
    {
        if (b & i)
        {
            b ^= i;
            
            if (!(a & b))
                ret += 1 << zeroes;
        }
        
        if (!(a & i))
            zeroes++;
    }
    
    return ret;
}

long long rec(int a, int b)
{
    if (a == b)
        return 0;
    if (a == 0)
        return 2 * b - 1 + rec(1, b);
    
    long long ret = 0;
    if (a & 1)
    {
        ret += 2 * (f(a, b) - f(a, a));
        a++;
    }
    if (b & 1)
    {
        ret += 2 * (f(b - 1, b) - f(b - 1, a));
        b--;
    }
    
    return ret + 3 * rec(a / 2, b / 2);
}

int main()
{
    int t;
    for (cin >> t; t--;)
    {
        int a, b;
        cin >> a >> b;
        cout << rec(a, b + 1) << 'n';
    }
    
    return 0;
}
```
