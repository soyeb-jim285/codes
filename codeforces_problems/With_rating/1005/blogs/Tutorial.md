# Tutorial


### [1005A - Tanya and Stairways](../problems/A._Tanya_and_Stairways.md "Codeforces Round 496 (Div. 3)")

The answer contains such elements $a_i$ that $a_{i+1}=1$. Also add to the answer the last element $a_n$.

 **Code in C++ for details**
```cpp
int n;
cin >> n;
vector<int> a;
int p = -1;
forn(i, n) {
    int x;
    cin >> x;
    if (x == 1 && p != -1)
        a.push_back(p);
    p = x;    
}
a.push_back(p);
cout << a.size() << endl;
for (int i: a)
    cout << i << " ";
```
 
### [1005B - Delete from the Left](../problems/B._Delete_from_the_Left.md "Codeforces Round 496 (Div. 3)")

Let's find the value $w$ — the length of the longest common suffix of $s$ and $t$. You can easily find it in one linear loop: just compare the last letters of $s$ and $t$. If they are equal then compare before the last letters of $s$ and $t$. And so on.

The last $w$ letters of $s$ and $t$ are two equal strings which will be the result of after optimal moves. So the answer is $|s|+|t|-2 \cdot w$.

 **Code in C++ for details**
```cpp
string s, t;
cin >> s >> t;
int w = 0;
while (true) {
    int i = s.length() - w - 1;
    int j = t.length() - w - 1;
    if (i >= 0 && j >= 0 && s[i] == t[j])
        w++;
    else
        break;
}
cout << s.length() + t.length() - 2 * w << endl;
```
 
### [1005C - Summarize to the Power of Two](../problems/C._Summarize_to_the_Power_of_Two.md "Codeforces Round 496 (Div. 3)")

You should delete only such $a_i$ for which there is no such $a_j$ ($i \ne j$) that $a_i+a_j$ is a power of $2$.

For each value let's find the number of its occurrences. You can use simple $map$ standard data-structure. Do $c[a[i]] := c[a[i]]+1$ for each element $a[i]$.

Now you can easily check that $a_i$ doesn't have a pair $a_j$. Let's iterate over all possible sums $s=2^0, 2^1, \dots, 2^{30}$ and for each $s$ find calculate $s-a[i]$. If for some $s$: $c[s-a[i]] \ge 2$ or $c[s-a[i]] = 1$ && $s-a[i] \ne a[i]$ then a pair $a_j$ exists.

Note that in C++ solutions, it's better to first check that $s-a[i]$ is a key in $c$, and only after it calculate $c[s - a[i]]$. This needs to be done, since in C++ when you access a key using the "square brackets" operator, a default mapping key-value is created on the absence of the key. This increases both the running time and the memory consumption.

 **Code in C++ for details**
```cpp
int n;
cin >> n;
vector<int> a(n);
map<int,int> c;
forn(i, n) {
    cin >> a[i];
    c[a[i]]++;
}
int ans = 0;
forn(i, n) {
    bool ok = false;
    forn(j, 31) {
        int x = (1 << j) - a[i];
        if (c.count(x) && (c[x] > 1 || (c[x] == 1 && x != a[i])))
            ok = true;
    }
    if (!ok)
        ans++;
}
cout << ans << endl;
```
 
### [1005D - Polycarp and Div 3](../problems/D._Polycarp_and_Div_3.md "Codeforces Round 496 (Div. 3)")

There are multiple approaches to solve this problem. We will use dynamic programming approach.

Let's calculate values of the array $z[0 \dots n]$, where $z[i]$ is the answer for prefix of the length $i$. Obviously, $z[0] := 0$, since for the empty string (the prefix of the length $0$) the answer is $0$.

For $i>0$ you can find $z[i]$ in the following way.

Let's look in the last digit of the prefix of length $i$. It has index $i-1$. Either it doesn't belong to segment divisible by $3$, or it belongs.

If it doesn't belongs, it means we can't use the last digit, so $z[i] = z[i-1]$. If it belongs we need to find shortest $s[j \dots i-1]$ that is divisible by $3$ and try to update $z[i]$ with the value $z[j]+1$. It means that we "bite off" the shortest divisible by $3$ suffix and reduce the problem to a previous.

A number is divisible by $3$ if and only if sum of its digits is divisible by $3$. So the task is to find the shortest suffix of $s[0 \dots i-1]$ with sum of digits divisible by $3$. If such suffix is $s[j \dots i-1]$ then $s[0 \dots j-1]$ and $s[0 \dots i-1]$ have the same remainder of sum of digits modulo $3$.

Let's maintain $fin[0 \dots 2]$ — array of the length $3$, where $fin[r]$ is the length of the longest processed prefix with sum of digits equal to $r$ modulo $3$. Use $fin[r]=-1$ if there is no such prefix. It is easy to see that $j=fin[r]$ where $r$ is the sum of digits on the $i$-th prefix modulo $3$.

So to find the maximal $j \le i-1$ that substring $s[j \dots i-1]$ is divisible by $3$, just check that $fin[r] \ne -1$ and use $j=fin[r]$, where $r$ is the sum of digits on the $i$-th prefix modulo $3$.

It means that to handle case that the last digit belongs to divisible by $3$ segment, you should try to update $z[i]$ with value $z[fin[r]] + 1$. In other words, just do if (fin[r] != -1) z[i] = max(z[i], z[fin[r]] + 1).

Sequentially calculating the values of $z [0 \dots n] $, we obtain a linear $O(n)$ solution.

 **Code in C++ for details**
```cpp
string s;
cin >> s;
int n = s.length();

int r = 0;
vector<int> fin(3, -1);
fin[0] = 0;

vector<int> z(n + 1);
for (int i = 1; i <= n; i++) {
    r = (r + s[i - 1] - '0') % 3;
    z[i] = z[i - 1];
    if (fin[r] != -1)
        z[i] = max(z[i], z[fin[r]] + 1);
    fin[r] = i;
}

cout << z[n] << endl;
```
 
### [1005E1 - Median on Segments (Permutations Edition)](../problems/E1._Median_on_Segments_(Permutations_Edition).md "Codeforces Round 496 (Div. 3)")

The segment $p[l \dots r]$ has median equals $m$ if and only if $m$ belongs to it and $less=greater$ or $less=greater-1$, where $less$ is number of elements in $p[l \dots r]$ that strictly less than $m$ and $greater$ is number of elements in $p[l \dots r]$ that strictly greater than $m$. Here we've used a fact that $p$ is a permutation (on $p[l \dots r]$ there is exactly one occurrence of $m$).

In other words, $m$ belongs $p[l \dots r]$ and the value $greater-less$ equals $0$ or $1$.

Calculate prefix sums $sum[0 \dots n]$, where $sum[i]$ the value $greater-less$ on the prefix of the length $i$ (i.e. on the subarray $p[0 \dots i-1]$). For fixed value $r$ it is easy to calculate number of such $l$ that $p[l \dots r]$ is suitable. At first, check that $m$ met on $[0 \dots r]$. Valid values $l$ are such indices that: no $m$ on $[0 \dots l-1]$ and $sum[l]=sum[r]$ or $sum[r]=sum[l]+1$.

Let's maintain number of prefix sums $sum[i]$ to the left of $m$ for each value. We can use just a map $c$, where $c[s]$ is number of such indices $l$ that $sum[l]=s$ and $l$ is to the left of $m$.

So for each $r$ that $p[0 \dots r]$ contains $m$ do ans += c[sum] + c[sum - 1], where $sum$ is the current value $greater-less$.

Time complexity is $O(n \log n)$ if a standard map is used or $O(n)$ if classical array for $c$ is used (remember about possible negative indices, just use an offset).

 **Code in C++ for details**
```cpp
int n, m;
cin >> n >> m;
vector<int> p(n);
forn(i, n)
    cin >> p[i];
map<int,int> c;
c[0] = 1;
bool has = false;
int sum = 0;
long long ans = 0;
for (int r = 0; r < n; r++) {
    if (p[r] < m)
        sum--;
    else if (p[r] > m)
        sum++;

    if (p[r] == m)
        has = true;
    if (has)
        ans += c[sum] + c[sum - 1];
    else
        c[sum]++;
}
cout << ans << endl;
```
 
### [1005E2 - Median on Segments (General Case Edition)](../problems/E2._Median_on_Segments_(General_Case_Edition).md "Codeforces Round 496 (Div. 3)")

Let's define a function greaterCount($m$) — number of subarrays with median greater or equal than $m$. In this case, the answer on the problem is greaterCount($m$) $-$ greaterCount($m + 1$).

The subarray $a[l \dots r]$ has median greater or equal than $m$, if and only if $notLess>less$, where $notLess$ is the number equal or greater than $m$ elements, and $less$ is the number of less than $m$ elements.

In other words, instead of processing $a[l \dots r]$ you can use the sequence $x[l \dots r]$ containing $-1$ or/and $+1$. An element $x[i]=-1$, if $a[i]<m$. An element $x[i]=+1$, if $a[i] \ge m$. Now, the median of $a[l \dots r]$ is greater or equal than $m$ if and only if $x[l] + x[l+1] + \dots + x[r] > 0$.

Let's iterate over $a$ from left to right. Maintain the current partial sum $sum=x[0]+x[1]+\dots+x[i]$. Additionally, in the array $s$ let's maintain the number of partial sum for each its value. It means that before increase of $i$ you should do s[sum]++. So if $i$ is the index of the right endpoint of a subarray (i.e. $r=i$), then number of suitable indices $l$ is number of such $j$ that $x[0]+x[1]+\dots+x[j]<sum$. In other words, find sum of all $s[w]$, where $w<sum$ — it is exactly number of indices with partial sum less than $sum$.

Each time partial sum changes on $-1$ or $+1$. So the value "sum of all $s[w]$, where $w<sum$" is easy to recalculate on each change. If you decrease $sum$, just subtract the value $s[sum]$. If you increase $sum$, before increasing just add $s[sum]$.

Since indices in $s$ can be from $-n$ to $n$, you can use 0-based indices using an array $s[0 \dots 2 \cdot n]$. In this case, initialize $sum$ as $n$ but not as $0$ (it makes $sum$ to be non-negative on each step).

This solution works in $O(n)$.

 **Code in C++ for details**
```cpp
long long greaterCount(int m) {
    vector<int> s(2 * n + 1);
    int sum = n;
    long long result = 0;
    s[sum] = 1;
    long long add = 0;
    forn(i, n) {
        if (a[i] < m)
            sum--, add -= s[sum];
        else
            add += s[sum], sum++;
        result += add;
        s[sum]++;
    }
    return result;
}

cin >> n >> m;
a = vector<int>(n);
forn(i, n)
    cin >> a[i];
cout << greaterCount(m) - greaterCount(m + 1) << endl;
```
 
### [1005F - Berland and the Shortest Paths](../problems/F._Berland_and_the_Shortest_Paths.md "Codeforces Round 496 (Div. 3)")

Use BFS to precalculate an array $d$ — the array of the shortest path lengths from the Capital.

The condition to minimize sum of distances in each tree is equal to the fact that each tree is a shortest path tree. Let's think about them as about oriented outgoing from the Capital trees. Moving along edges of such trees, you always move by shortest paths.

An edge $(u,v)$ can be included into such a tree if and only if $d[u]+1=d[v]$ (since original edges are bidirectional, you should consider each of them twice: as $(u,v)$ and as $(v,u)$). Let's focus only on edges for which $d[u]+1=d[v]$. Call them "red" edges.

To build a tree for each city (except the Capital) you should choose exactly one red edge finishing in this city. That's why the number of suitable trees is a product of numbers of incoming edges over all vertices (cities).

But we need to find only $k$ of such trees. Let's start from some such tree and rebuild it on each step. As initial tree you can choose the first incoming red edge into each vertex (except the City). Actually, we will do exactly increment operation for number in a mixed radix notation.

To rebuild a tree iterate over vertices and if the current used red edge is not the last for the vertex, use the next and stop algorithm. Otherwise (the last red edge is used), use the first red edge for this vertex (and go to the next vertex) and continue with the next vertex. Compare this algorithm with simple increment operation for long number.

 **Code in C++ for details**
```cpp
int n, m, k;
cin >> n >> m >> k;
vector<vector<int>> g(n);
vector<int> a(m), b(m);
forn(i, m) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
}

queue<int> q;
q.push(0);
vector<int> d(n, INT_MAX);
d[0] = 0;

while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v: g[u])
        if (d[v] == INT_MAX) {
            d[v] = d[u] + 1;
            q.push(v);
        }
}

vector<vector<int>> inc(n);
forn(i, m) {
    if (d[a[i]] + 1 == d[b[i]])
        inc[b[i]].push_back(i);
    if (d[b[i]] + 1 == d[a[i]])
        inc[a[i]].push_back(i);
}

vector<int> f(n);
vector<string> result;

forn(i, k) {
    string s(m, '0');
    for (int j = 1; j < n; j++)
        s[inc[j][f[j]]] = '1';
    result.push_back(s);

    bool ok = false;
    for (int j = 1; j < n; j++)
        if (f[j] + 1 < inc[j].size()) {
            ok = true;
            f[j]++;
            break;
        } else
            f[j] = 0;
    if (!ok)
        break;
}

cout << result.size() << endl;
forn(i, result.size())
    cout << result[i] << endl;
```
