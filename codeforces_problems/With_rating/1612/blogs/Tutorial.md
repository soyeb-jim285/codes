# Tutorial

[1612A - Distance](../problems/A._Distance.md "Educational Codeforces Round 117 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1612A - Distance](../problems/A._Distance.md "Educational Codeforces Round 117 (Rated for Div. 2)")

There is a solution in $O(1)$, but in fact, a solution that checks all points with $x$-coordinate from $0$ to $50$ and $y$-coordinate from $0$ to $50$ is fast enough. There's no need to check any other points, since $d(A, C) + d(B, C) = d(A, B)$ implies that point $C$ is on one of the shortest paths between $A$ and $B$.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    x, y = map(int, input().split())
    xc = -1
    yc = -1
    for j in range(0, 51):
        for k in range(0, 51):
            if 2 * (j + k) == x + y and 2 * (abs(x - j) + abs(y - k)) == x + y:
                xc, yc = j, k
    print(xc, yc)
```
[1612B - Special Permutation](../problems/B._Special_Permutation.md "Educational Codeforces Round 117 (Rated for Div. 2)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), preparation: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1612B - Special Permutation](../problems/B._Special_Permutation.md "Educational Codeforces Round 117 (Rated for Div. 2)")

There are many different constructions that give the correct answer, if it exists. In my opinion, one of the most elegant is the following one.

$a$ should always be present in the left half, and $b$ should be present in the right half, but the exact order of elements in each half doesn't matter. So, it will never be wrong to put $a$ in the first position, and $b$ in the second position.

As for the remaining elements, we want elements of the left half to be as big as possible (since they shouldn't be less than $a$), and elements of the right half — as small as possible (since they shouldn't be greater than $b$). Let's put the elements $n$, $n - 1$, $n - 2$, ..., $1$ (excluding $a$ and $b$) on positions $2$, $3$, $4$, ..., $n-1$, respectively, so the elements in the left half are as big as possible, and the elements in the right half are as small as possible.

After constructing a permutation according to these rules, we should check if it meets the constraints (and print it if it does).

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    n, a, b = map(int, input().split())
    p = [a]
    for j in range(n, 0, -1):
        if j != a and j != b:
            p.append(j)
    p.append(b)
    if(len(p) == n and min(p[0:n//2]) == a and max(p[n//2:n]) == b):
        print(*p)
    else:
        print(-1)
```
[1612C - Chat Ban](../problems/C._Chat_Ban.md "Educational Codeforces Round 117 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh"), preparation: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1612C - Chat Ban](../problems/C._Chat_Ban.md "Educational Codeforces Round 117 (Rated for Div. 2)")

This is a pretty obvious binary search problem. If we get banned after $y$ messages, we also get banned after $y+1$, $y+2$ and so on messages (and vice versa, if we don't get banned after $y$ messages, we also don't get banned after $y-1$, $y-2$ and so on messages).

For simplicity, let's split the problem into two parts: when we check if we're getting banned after $y$ messages, let's handle cases $y < k$ and $y \ge k$ separately.

Recall that the sum of the arithmetic progression consisting of integers $1$, $2$, ..., $y$ is $\frac{y(y+1)}{2}$. Let it be $cnt(y)$.

The first case is pretty simple: the number of emotes we send with $y$ messages when $y < k$ is $\frac{y(y+1)}{2}$ which is $cnt(y)$. So we only need to check if $cnt(y) \ge x$.

The second case is a bit harder but still can be done using arithmetic progression formulas. Firstly, we send all messages for $y \le k$ (the number of such messages is $cnt(k)$). Then, we need to add $(k - 1) + (k - 2) + \ldots + (y - k)$ messages. This number equals to $cnt(k - 1) - cnt(2k - 1 - y)$ (i.e. we send all messages from $k-1$ to $1$ and subtract messages from $1$ to $2k - 1 - y$ from this amount). The final condition is $cnt(k) + cnt(k - 1) - cnt(2k - 1 - y) \ge x$.

Time complexity: $O(\log{k})$ per test case.

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

long long get(int x) {
    return x * 1ll * (x + 1) / 2;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int t;
    cin >> t;
    while (t--) {
        int k;
        long long x;
        cin >> k >> x;
        long long l = 1, r = 2 * k - 1;
        long long res = 2 * k - 1;
        bool over = false;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid >= k) {
                over = (get(k) + get(k - 1) - get(2 * k - 1 - mid) >= x);
            } else {
                over = (get(mid) >= x);
            }
            if (over) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << res << endl;
    }
    
    return 0;
}
```
[1612D - X-Magic Pair](../problems/D._X-Magic_Pair.md "Educational Codeforces Round 117 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh"), preparation: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1612D - X-Magic Pair](../problems/D._X-Magic_Pair.md "Educational Codeforces Round 117 (Rated for Div. 2)")

This problem has a GCD-based solution.

Firstly, lets' try to solve it naively. Always suppose that $a > b$. If this is not true, let's swap $a$ and $b$. Firstly, if $b > a - b$, let's do $b := a - b$. Okay, now let's subtract $b$ from $a$ until $b \ge a - b$ again and repeat this algorithm till $a = 0$ or $b = 0$. If, after some step, we get $a = x$ or $b = x$, we are done, and the answer is YES. If $a = 0$ or $b = 0$, and we didn't get $x$ then the answer is NO.

Okay, we can see that we always subtract the minimum possible $b$ from $a$ and trying to maintain this condition. It can be proven that this algorithm yields all possible integers that are obtainable by any sequence of the operations from the problem statement (either in $a$ or in $b$).

Now we have to speed up this solution somehow. Obviously, most operations are redundant for us in this particular problem. The first thing is that we can skip all operations till $b$ becomes greater than $a - b$. The number of such operations is $\lfloor\frac{a - b}{2b}\rfloor$. And the second thing is that we can skip all operations till we get $x$ in $a$. The number of such operations is $\lfloor\frac{a-x}{b}\rfloor$. For simplicity, this part can be also written as $\lfloor\frac{a-x}{2b}\rfloor$. This doesn't affect the time complexity much, but the formula for the final number of operations we can skip will be simpler. This number equals $cnt = max(1, \lfloor\frac{a-max(b, x)}{2b}\rfloor)$ (in fact, we take the minimum between two values written above, because we don't want to skip any of these two cases). So, we can transform the pair $(a, b)$ to the pair $(a - b * cnt, b)$ and continue this algorithm.

There are also simpler approaches using the same idea but in a cooler way.

Time complexity: $O(\log{a})$ per test case.

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

bool get(long long a, long long b, long long x) {
    if (a == x || b == x) return true;
    if (a < b) swap(a, b);
    if (b > a - b) b = a - b;
    if (x > max(a, b) || a == 0 || b == 0) return false;
    long long cnt = max(1ll, (a - max(x, b)) / (2 * b));
    return get(a - b * cnt, b, x);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int t;
    cin >> t;
    while (t--) {
        long long a, b, x;
        cin >> a >> b >> x;
        if (get(a, b, x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
```
[1612E - Messages](../problems/E._Messages.md "Educational Codeforces Round 117 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1612E - Messages](../problems/E._Messages.md "Educational Codeforces Round 117 (Rated for Div. 2)")

First of all, let's rewrite the answer using expectation linearity. The expected number of students who read their respective messages is equal to $F_1 + F_2 + \dots + F_n$, where $F_i$ is a random value which is $1$ if the $i$-th student reads the message $m_i$, and $0$ if the $i$-th student doesn't do it.

Let's analyze the expected value of $F_i$. Suppose Monocarp pins the messages $c_1, c_2, \dots, c_t$. There are three cases:

* if $m_i \notin [c_1, c_2, \dots, c_t]$, then the $i$-th student won't read the message $m_i$, so $F_i = 0$;
* if $m_i \in [c_1, c_2, \dots, c_t]$ and $t \le k_i$, then the $i$-th student will definitely read the message $m_i$, so $F_i = 1$;
* if $m_i \in [c_1, c_2, \dots, c_t]$ and $t > k_i$, then $F_i = \frac{k_i}{t}$.

If we iterate on the number of messages we pin $t$, we can calculate the sum of $F_i$ for each message (considering that we pin it), sort all of the messages and pick $t$ best of them. So, we have a solution working in $O(n^2 \log n)$.

The only thing we need to improve this solution sufficiently is the fact that we don't have to consider the case $t > 20$. Since every $k_i$ is not greater than $20$, the sum of $F_i$ for a message in the case $t = 20$ is the same as this sum of $F_i$ in the case $t = 21$, but multiplied by the coefficient $\frac{20}{21}$ — and we pick $21$ best values, their sum multiplied by $\frac{20}{21}$ is not greater than the sum of $20$ best values. The same holds for $t = 22$ and greater.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

const int N = 200043;
const int K = 20;
vector<int> idx[N];
int m[N], k[N];

bool frac_greater(pair<int, int> a, pair<int, int> b)
{
    return a.first * b.second > a.second * b.first;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &m[i], &k[i]);
        idx[m[i]].push_back(i);
    }

    vector<int> cert;
    pair<int, int> ans = {0, 1};
    for(int i = 1; i <= K; i++)
    {
        vector<int> score(N);
        for(int j = 0; j < n; j++)
            score[m[j]] += min(i, k[j]);
        vector<pair<int, int>> aux;
        for(int j = 0; j < N; j++)
            aux.push_back(make_pair(score[j], j));
        sort(aux.rbegin(), aux.rend());
        pair<int, int> cur_ans = {0, i};
        vector<int> cur_cert;
        for(int j = 0; j < i; j++)
        {
            cur_ans.first += aux[j].first;
            cur_cert.push_back(aux[j].second);
        }
        if(frac_greater(cur_ans, ans))
        {
            ans = cur_ans;
            cert = cur_cert;
        }
    }
    cout << cert.size() << endl;
    shuffle(cert.begin(), cert.end(), mt19937(time(NULL)));
    for(auto x : cert) cout << x << " ";
    cout << endl;
}
```
[1612F - Armor and Weapons](../problems/F._Armor_and_Weapons.md "Educational Codeforces Round 117 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1612F - Armor and Weapons](../problems/F._Armor_and_Weapons.md "Educational Codeforces Round 117 (Rated for Div. 2)")

Among two armor sets, one with the greater index is always better. The same can be said about two different weapons. So, it is always optimal to use and obtain the best possible weapon or armor.

This observation allows us to model this problem with dynamic programming or shortest paths: let $dp_{x,y}$ be the minimum time in which Monocarp can obtain the armor $x$ and the weapon $y$; and in each transition, we either get the best weapon we can or the best armor we can. Similarly, we can build a graph where the vertices represent these pairs $(x, y)$, and the edges represent getting the best possible weapon/armor, and find the shortest path from $(1, 1)$ to $(n, m)$ using BFS.

Unfortunately, it is $O(nm)$. But we can modify the BFS in the following fashion: let's analyze each layer of BFS (a layer is a set of vertices with the same distance from the origin). In each layer, there might be some redundant vertices: if two vertices $(x, y)$ and $(x', y')$ belong to the same layer, $x' \le x$ and $y' \le y$, then the vertex $(x', y')$ is redundant.

If we filter each layer, removing all redundant vertices from it and continuing BFS only from non-redundant ones, the solution will be fast enough. To prove it, let's analyze the constraints on the answer. Suppose $n \ge m$. The answer can be bounded as $O(\log m + \frac{n}{m})$, since we can reach the pair $(m, m)$ in $O(\log m)$ steps using something similar to Fibonacci sequence building, and then go from $(m, m)$ to $(n, m)$ in $\frac{n}{m}$ steps. And the number of non-redundant states on each layer is not greater than $m$ (because, of two states with the same weapon or the same armor set, at least one is redundant). So, if we don't continue BFS from redundant vertices, it will visit at most $O(m \cdot (\log m + \frac{n}{m})) = O(m \log m + n)$ vertices. There might be another logarithm in the asymptotic complexity of the solution, if you use something like a set to store all combinations that synergize well, but this implementation is still fast enough.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int n, m;

#define x first
#define y second

typedef pair<int, int> comb;

comb norm(const comb& a)
{
    return make_pair(min(a.x, n), min(a.y, m));
}

bool good(const comb& a)
{
    return a.x == n || a.y == m;
}

bool comp(const comb& a, const comb& b)
{
    if(a.x != b.x)
        return a.x > b.x;
    return a.y > b.y;
}

int main()
{
    scanf("%d %d", &n, &m);
    int v;
    scanf("%d", &v);
    set<comb> s;
    for(int i = 0; i < v; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        s.insert(make_pair(x, y));
    }
    int steps = 0;
    vector<comb> cur;
    cur.push_back(make_pair(1, 1));
    while(true)
    {
        if(cur[0] == make_pair(n, m))
            break;
        vector<comb> ncur;
        for(auto x : cur)
        {
            int sum = x.x + x.y;
            if(s.count(x))
                sum++;
            comb z = x;
            z.x = sum;
            ncur.push_back(norm(z));
            z = x;
            z.y = sum;
            ncur.push_back(norm(z));
        }
        sort(ncur.begin(), ncur.end(), comp);
        int mx = 0;
        vector<comb> ncur2;
        for(auto x : ncur)
        {
            if(x.y <= mx) continue;
            mx = max(mx, x.y);
            ncur2.push_back(x);
        }
        cur = ncur2;
        steps++;
    }
    printf("%dn", steps);
}
```
[1612G - Max Sum Array](../problems/G._Max_Sum_Array.md "Educational Codeforces Round 117 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic"), preparation: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1612G - Max Sum Array](../problems/G._Max_Sum_Array.md "Educational Codeforces Round 117 (Rated for Div. 2)")

Firstly, let's prove that at first and last positions of $a$ the most frequent elements should be placed (but not necessary the same). WLOG, let's prove that $c_{a_1} \ge c_{a_i}$ for any $i > 1$. 

By contradiction, let's $p$ be the smallest index such that $c_{a_1} < c_{a_p}$. What happens if we swap them? Since $p$ is the first such index then there are no $a_i = a_p$ for $i < p$, so "contribution" of $a_p$ will increase by exactly $inc = (c_{a_p} - 1) \cdot (p - 1)$. From the other side, contribution of $a_1$ consists of two parts: pairs with elements from $(p, n]$ and from $(1, p)$. For all elements from $(p, n]$ decrease will be equal to $dec_1 = c_{a_1}[p + 1, n] \cdot (p - 1)$ and from elements in $(1, p)$ $dec_2 \le c_{a_1}[2, p - 1] \cdot (p - 1)$.

So, the total decrease $dec$ after moving $a_1$ to position $p$ equal to $dec = dec_1 + dec_2 \le (c_{a_1} - 1) \cdot (p - 1)$. The total difference in such case is equal to $inc - dec \ge (p - 1) \cdot (c_{a_p} - c_{a_1}) > 0$. So, our placement is not optimal — contradiction.

Let's suggest that there is exactly one $e$ with maximum $c_{e}$. According to what we proved earlier, both $a_1$ and $a_n$ must be equal to $e$. Contribution of the first and last elements will be equal to: $(n - 1)$ for pair $(1, n)$ and for each element $i$ ($1 < i < n$) with $a_i = e$ we add $(i - 1) + (n - i) = (n - 1)$ for pairs $(1, i)$ and $(i, n)$. So, the total contribution of $a_1 = a_n = e$ is equal to $(n - 1) \cdot (c_e - 1)$.

Note that this contribution is independent of positions of other $e$ in the array $a$, so that's why we can cut first and last elements of $a$ and solve the task recursively.

Unfortunately, in the initial task we may have several $e_1, e_2, \dots, e_k$ with maximum $c_{e_i}$. But we in the similar manner can prove that the first (and last) $k$ elements $a_1, \dots, a_k$ should be some permutation of $e_1, \dots e_k$. Now, let's prove that any permutation of first and last $k$ elements is optimal.

Suppose, positions of $e_i$ are $l_i$ ($1 \le l_i \le k$) and $r_i$ ($n - k + 1 \le r_i \le n$). Then the contribution of $e_i$ is equal to $(c_{e_i} - 1) \cdot (r_i - l_i)$. The total contribution of all $e_i$ is $\sum\limits_{i=1}^{k}{(c_{e_i} - 1) \cdot (r_i - l_i)}$ $=$ $(c_{e_1} - 1) (\sum\limits_{i=1}^{k}r_i - \sum\limits_{i=1}^{k}{l_i})$ $=$ $(c_{e_1} - 1)((n - k)k + \frac{k(k + 1)}{2} - \frac{k(k+1)}{2}) = (c_{e_1} - 1) k (n - k)$. This contribution doesn't depend on chosen $l_i$ and $r_i$, so any permutation of first $k$ elements and any permutation of last $k$ elements give optimal answer.

As a result, the algorithm is following: 

* Find all maximums $e_1, \dots, e_k$ in $c$.
* If $c_{e_1} = 1$ then any permutation of remaining elements has $f(a) = 0$ (there are $k!$ such permutations).
* Otherwise, add $(c_{e_1} - 1) k (n - k)$ to the total balance, and multiply the number of variants by $(k!)^2$.
* Cut prefix and suffix by making $c_{e_i} = c_{e_i} - 2$ for each $e_i$ (obviously, $n = n - 2k$) and repeat the whole process.

We can implement the algorithm fast if we keep the number of $c_i$ equal to each $val$ from $0$ to $C$ ($C \le 10^6$). So the total complexity is $O(n + C)$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.x << " " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    fore(i, 0, sz(v)) {
        if(i) out << " ";
        out << v[i];
    }
    return out;
}

const int INF = int(1e9);
const li INF64 = li(1e18);

const int MOD = int(1e9) + 7;

int norm(int a) {
    while (a >= MOD)
        a -= MOD;
    while (a < 0)
        a += MOD;
    return a;
}
int mul(int a, int b) {
    return int(a * 1ll * b % MOD);
}

const int MX = int(1e6) + 55;
int n;
li total;
int cnt[MX];

inline bool read() {
    if(!(cin >> n))
        return false;
    total = 0;
    fore (i, 0, n) {
        int k; cin >> k;
        cnt[k]++;
        total += k;
    }
    return true;
}

int fact[MX];

inline void solve() {
    fact[0] = 1;
    fore (i, 1, MX)
        fact[i] = mul(fact[i - 1], i);
    
    int ansSum = 0;
    int ansCnt = 1;
    
    for (int lvl = MX - 1; lvl > 1; lvl--) {
        ansCnt = mul(ansCnt, mul(fact[cnt[lvl]], fact[cnt[lvl]]));
        
        //each color gives (lvl - 1) * (r_i - l_i)
        // or (lvl - 1) * (sum r_i - sum l_i)
        // l_i is permutation of [0,..., cnt[lvl]), so sum l_i = (cnt[lvl] - 1) * cnt[lvl] / 2
        // r_i is permutation of [total - cnt[lvl],..., total), so sum = cnt[lvl] * (total - cnt[lvl]) + (cnt[lvl] - 1) * cnt[lvl] / 2
        
        ansSum = norm(ansSum + mul(mul(lvl - 1, cnt[lvl]), (total - cnt[lvl]) % MOD));
        
        total -= 2 * cnt[lvl];
        cnt[lvl - 2] += cnt[lvl];
    }
    
    ansCnt = mul(ansCnt, fact[cnt[1]]);
    
    cout << ansSum << " " << ansCnt << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    
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
