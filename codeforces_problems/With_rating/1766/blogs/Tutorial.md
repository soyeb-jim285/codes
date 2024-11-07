# Tutorial

[1766A - Extremely Round](../problems/A._Extremely_Round.md "Educational Codeforces Round 139 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1766A - Extremely Round](../problems/A._Extremely_Round.md "Educational Codeforces Round 139 (Rated for Div. 2)")

There are many ways to solve this problem.

The most naive one (iterating through all numbers from $1$ to $n$ in each test case and checking if they are extremely round) fails, since it is $O(tn)$, but you can optimize it by noticing that extremely round numbers are rare. So, for example, we can iterate through all numbers from $1$ to $999999$ once, remember which ones are extremely round, store them into an array, and while answering the test case, only check the numbers from the array we have created.

There is also a solution in $O(1)$ per test case with a formula, try to invent it yourself.

 **Solution (BledDest)**
```cpp
def check(x):
    s = str(x)
    cnt = 0
    for c in s:
        if c != '0':
            cnt += 1
    return cnt == 1

a = []
for i in range(1, 1000000):
    if check(i):
        a.append(i)
t = int(input())
for i in range(t):
    n = int(input())
    ans = 0
    for x in a:
        if x <= n:
            ans += 1
    print(ans)
```
[1766B - Notepad#](../problems/B._Notepad_.md "Educational Codeforces Round 139 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1766B - Notepad#](../problems/B._Notepad_.md "Educational Codeforces Round 139 (Rated for Div. 2)")

Why does the problem ask us only to check if we can do less than $n$ operations instead of just asking the minimum amount? That must be making the problem easier, so let's focus our attention on that.

What if it was $\le n$ instead of $< n$? Well, then the problem would be trivial. You can type the word letter by letter and be done in $n$ operations. So we only have to save one operation. In order to save at least one operation, we have to use the copy operation and copy more than one character in that.

Let's take a closer look at any of the copy operations we do. Basically, it has to be a substring that has at least two non-intersection occurrences in the string. Thus, if the string has any substring that has length at least two that appears at least twice in the string, we can copy it, and the answer will be "YES".

That's still not enough to solve the problem — we'd have to check all substrings, which is $O(n^2)$.

Let's think further. Imagine we found a substring that works. Let it have length $k$. Notice how you can remove its last character, obtaining a substring of length $k-1$, and it will still occure in the same set of positions (possibly, even more occurrences will be found). Remove characters until the substring has length $2$. Thus, if any appropriate substring exists, an appropriate substring of length $2$ also exists.

Finally, we can check if there exists a substring of length $2$ that appears at least twice in the string so that the occurrences are at least $2$ apart. That can be done with a set/hashset or a map/hashmap. Some implementations might require careful handling of the substrings of kind "aa", "bb" and similar.

Overall complexity: $O(n)$ or $O(n \log n)$ per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	s = input()
	cur = {}
	for i in range(n - 1):
		t = s[i:i+2]
		if t in cur:
			if cur[t] < i - 1:
				print("YES")
				break
		else:
			cur[t] = i
	else:
		print("NO")
```
[1766C - Hamiltonian Wall](../problems/C._Hamiltonian_Wall.md "Educational Codeforces Round 139 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1766C - Hamiltonian Wall](../problems/C._Hamiltonian_Wall.md "Educational Codeforces Round 139 (Rated for Div. 2)")

Why is there a constraint of each column having at least one black cell? Does the problem change a lot if there were white columns? Well, if such a column was inbetween some black cells, then the answer would be "NO". If it was on the side of the grid, you could remove it and proceed to solve without it. So, that doesn't really change the problem other than removing some casework.

Let's try to fix a start. Find a column that has only one black cell in it. If there are no such columns, the answer is immediately "YES". Otherwise, the path will always go through it in known directions: to the left and to the right (if both of them exist). Let's solve the problem separately for the left part of the path and for the right one — find a path that starts to the left of it and covers everything to the left and the same for the right part.

Consider the right part.

If the next column also has one black cell, then we can determine where to go uniquely. If this cell is on the opposite row, then the answer is "NO". Otherwise, go there and proceed further.

Let it have two black cells now. Find the entire two black row rectangle of maximum size that starts there. If there's nothing after it, you can easily traverse it any way you like. Otherwise, you have to traverse it in such a way that you end up in its last column, then go to the right from there. Turns out, there's only one way to achieve that. Go up/down to another row, go right, up/down to another row, right and so on. Now you just have to check if you end up in the correct row.

Thus, you can simulate the path to the left and to the right and check if you never get stuck.

Overall comlexity: $O(n)$ per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	s = [input() for i in range(2)]
	pos = -1
	for i in range(n):
		if s[0][i] != s[1][i]:
			pos = i
	if pos == -1:
		print("YES")
		continue
	ok = True
	cur = 0 if s[0][pos] == 'B' else 1
	for i in range(pos + 1, n):
		if s[cur][i] == 'W':
			ok = False
		if s[cur ^ 1][i] == 'B':
			cur ^= 1
	cur = 0 if s[0][pos] == 'B' else 1
	for i in range(pos - 1, -1, -1):
		if s[cur][i] == 'W':
			ok = False
		if s[cur ^ 1][i] == 'B':
			cur ^= 1
	print("YES" if ok else "NO")
```
[1766D - Lucky Chains](../problems/D._Lucky_Chains.md "Educational Codeforces Round 139 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1766D - Lucky Chains](../problems/D._Lucky_Chains.md "Educational Codeforces Round 139 (Rated for Div. 2)")

Suppose, $\gcd(x + k, y + k) = g$. It means that $(y + k) - (x + k) = (y - x)$ is also divisible by $g$, or $\gcd(x + k, y - x) = h$ is divisible by $g$. And backward: if $\gcd(x + k, y - x) = h$, then $(x + k) + (y - x) = (y + k)$ is also divisible by $h$, or $\gcd(x + k, y + k) = g$ is divisible by $h$. 

Since $h$ is divisible by $g$ and $g$ is divisible by $h$, so $h = g$. In other words, we proved that $\gcd(x + k, y + k) = \gcd(x + k, y - x)$.

Now, knowing the equivalence above, we can understand that we are looking for the smallest $k \ge 0$ such that $\gcd(x + k, y - x) > 1$. In other words, we are searching $k$ such that $x + k$ is divisible by some $d > 1$, where $d$ is some divisor of $(y - x)$.

The problem is that there are a handful of divisors for some $(y - x)$. But we can note that we can consider only prime divisors of $(y - x)$: if $d | (y - x)$ and $d$ is composite then there is some prime $p | d$, thus $p | (y - x)$.

It's easy to prove that there are no more than $\log_2{n}$ prime divisors of some $n$. Now the question is how to find all these prime divisors.

Note that if you know only one prime divisor for each value from $1$ to $n$, then you can find all prime divisors for all $k \le n$ in $O(\log{k})$. The prime divisors $p_i$ are next: 

* $p_1 = minD[k]$, $k_1 = \frac{k}{minD[k]}$;
* $p_2 = minD[k_1]$, $k_2 = \frac{k_1}{minD[k_1]}$;
* $p_3 = minD[k_2]$, $k_3 = \frac{k_2}{minD[k_2]}$;
* and so on until $k_i > 1$.

The final step is to calculate a prime divisor $minD[i]$ for each value from $1$ to $A$, where $A \ge \max(y_i)$ or $A \ge 10^7$. We can do it by slight modifications of Sieve of Eratosthenes: at the step, where you have some prime $p$ and want to "throw out" all values $k \cdot p$, set $minD[kp] = p$ for each $kp$ (plus set $minD[p] = p$).

As a result, we, firstly, calculate Sieve in $O(N \log{\log{N}})$ and, secondly, calculate answer for each pair $(x_i, y_i)$ in $O(\log{N})$.

Note that the input and output is large, so you should you tricks to speed up your input and output.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

typedef long long li;

const int INF = int(1e9);
const int N = int(1e7) + 5;

int mind[N];

void precalc() {
	fore (i, 0, N)
		mind[i] = i;
	
	for (int p = 2; p < N; p++) {
		if (mind[p] != p)
			continue;
		for (int d = 2 * p; d < N; d += p)
			mind[d] = min(mind[d], p);
	}
}

int x, y;

inline bool read() {
	if(!(cin >> x >> y))
		return false;
	return true;
}

vector<int> getPrimes(int v) {
	vector<int> ps;
	while (v > 1) {
		if (ps.empty() || ps.back() != mind[v])
			ps.push_back(mind[v]);
		v /= mind[v];
	}
	return ps;
}

inline void solve() {
	int d = y - x;
	if (d == 1) {
		cout << -1 << 'n';
		return;
	}
	
	int r = INF;
	for (int p : getPrimes(d))
		r = min(r, ((x + p - 1) / p) * p);
	cout << r - x << 'n';
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	precalc();
	
	int t; cin >> t;
	while (t--) {
		read();
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
[1766E - Decomposition](../problems/E._Decomposition.md "Educational Codeforces Round 139 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1766E - Decomposition](../problems/E._Decomposition.md "Educational Codeforces Round 139 (Rated for Div. 2)")

Let's assume that we don't have any zeroes in our array. We'll deal with them later.

The key observation is that the number of sequences in the decomposition is not more than $3$. To prove this, we can use the fact that each element $3$ will be appended to the first subsequence in the decomposition; so, if the second/third subsequence in the decomposition ends with the number $2$ or $1$, all such numbers can be appended to that subsequence, thus they won't create any new subsequences. So, if we consider the combination of the last elements in the subsequences of the decomposition, there are only $3^3 + 3^2 + 3^1 + 3^0 = 40$ such combinations (even less in practice).

Okay, now let's try to use the fact that the number of such combinations is small. There are many ways to abuse it, but, in my opinion, the most straightforward one (and also a bit slow, but fast enough to easily pass the time limit) is to run the following dynamic programming: $dp_{i,c}$, where $i$ is the index of the element we are processing, and $c$ is the vector representing the combination of last elements of subsequences in the decomposition.

But it's not clear what do we store in this dynamic programming. The model solution stores the total number of subsequences added to the decomposition, if right now the state of decomposition is $c$, we process the $i$-th element, and we consider all possible stopping points (i. e. we will consider the number of subsequences added while processing the elements $a[i..i], a[i..i+1], a[i..i+2], \dots, a[i..n]$). So, our dynamic programming automatically sums up the answers for all possible right borders of the segment we decompose. Transitions in this dynamic programming is easy: we need to see how does the element $a_i$ alter the state of decomposition $c$ (let it change it to $c'$), take the value of $dp_{i+1, c'}$, and if the element $a_i$ forms a new subsequence, let's account for it by increasing $dp_{i,c}$ by $n-i+1$, because this increase will affect $n-i+1$ different right endpoints of the segment we decompose.

And now it's easy to see how to add zeroes to our solution. We can just assume they don't change the state of decomposition, they simply add a new subsequence which won't take any other elements. So, in our transitions, processing $0$ means that $c' = c$, but the size of decomposition increases.

To actually get the answer to the problem, we need to consider all possible starting points of the segment, so we sum up $dp_{i,o}$ (where $o$ is the empty vector) for all $i \in [1, n]$.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 300043;

int n;
int v[N];
map<vector<int>, long long> dp[N];

pair<int, vector<int>> go(vector<int> a, int x)
{
    if(x == 0)
        return {1, a};
    else
    {
        bool f = false;
        for(int i = 0; i < a.size() && !f; i++)
            if((a[i] & x) > 0)
            {
                f = true;
                a[i] = x;
            }
        int c = 0;
        if(!f)
        {
            c = 1;
            a.push_back(x);
        }
        return {c, a};
    }
}

long long calc(int i, vector<int> a)
{
    if(i == n) return 0ll;
    if(dp[i].count(a)) return dp[i][a];
    auto p = go(a, v[i]);
    return (dp[i][a] = p.first * 1ll * (n - i) + calc(i + 1, p.second));
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    long long ans = 0;
    for(int i = 0; i < n; i++)
        ans += calc(i, vector<int>(0));
    printf("%lldn", ans);    
}
```
[1766F - MCF](../problems/F._MCF.md "Educational Codeforces Round 139 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1766F - MCF](../problems/F._MCF.md "Educational Codeforces Round 139 (Rated for Div. 2)")

This problem is solved using minimum cost flows (duh).

Suppose all arcs have even capacity. Then we can just divide each arc's capacity by $2$ and solve a usual minimum cost flow problem. However, when we have arcs with odd capacity, it's not that simple. We will deal with them as follows: split an arc with capacity $2k+1$ into two arcs: one with capacity $2k$, the other with capacity $1$, and somehow enforce that the second arc must be saturated. We cannot divide all arcs by $2$ now, because that would lead to non-integer capacities; instead, we will exclude these arcs with capacity $1$ and somehow handle the fact that they must be saturated, and only then divide all capacities by $2$.

Okay, how do we handle the edges we deleted? For each vertex, let's check if the number of such arcs connected to it is even. If it is not — the total flow for this vertex cannot be $0$, so it's impossible to find the answer (the only case when it might be possible is if this vertex is the source or the sink; in this case, we need to check that both of these vertices have an odd number of arcs we want to delete connected to them, and consider an additional arc $1 \rightarrow n$ with capacity $1$ and weight $0$ to make it even). 

If for each vertex, the number of odd arcs connected to it is even, let's consider how much excess flow these arcs bring into the vertices. For example, if a vertex has $4$ ingoing odd arcs, it has $4$ units of flow going into it, which will be lost if we remove the edges we want to ignore. To handle this, add a new source and a new sink to our network (let's call them $s$ and $t$), and process excess flow going into the vertex using an arc from $s$ to that vertex (in the previous example, we can add an arc from $s$ to the vertex with capacity $2$ — not $4$ since we divide all capacities by $2$). Similarly, excess flow going outside the vertex can be processed with an arc from that vertex to $t$. We need to make sure that all these edges must be saturated.

Okay, what about actually running the flow from $1$ to $n$? We can do it as in "flow with lower bounds" problem by adding an arc $n \rightarrow 1$ with infinite capacity... Wait a minute, this may cause a negative cycle to appear! If your implementation of mincost flow handles them, you can use this approach; but if you don't want to mess with negative cycles, instead do the following:

* add an arc $s \rightarrow 1$ and an arc $n \rightarrow t$, both with infinite capacities, to make sure that flow can go from $1$ to $n$;
* since these arcs don't have to be saturated, but other arcs going from $s$ or into $t$ must be saturated, set the costs of these "other" arcs to $-10^9$.

Okay, that's it — we just need to find the minimum cost flow in the resulting network. The constraints are low enough so any minimum cost flow algorith can pass.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

const int N = 243;

struct edge
{
    int y, c, w, f;
    edge() {};
    edge(int y, int c, int w, int f) : y(y), c(c), w(w), f(f) {};
};

vector<edge> e;
vector<int> g[N];

int rem(int x)
{
    return e[x].c - e[x].f;
}

void add_edge(int x, int y, int c, int w)
{
    g[x].push_back(e.size());
    e.push_back(edge(y, c, w, 0));
    g[y].push_back(e.size());
    e.push_back(edge(x, 0, -w, 0));
}

int n, m, s, t, v;

pair<int, long long> MCMF()
{
    int flow = 0;
    long long cost = 0;
    while(true)
    {
        vector<long long> d(v, (long long)(1e18));
        vector<int> p(v, -1);
        vector<int> pe(v, -1);
        queue<int> q;
        vector<bool> inq(v);
        q.push(s);
        inq[s] = true;
        d[s] = 0;
        while(!q.empty())
        {
            int k = q.front();
            q.pop();
            inq[k] = false;
            for(auto ei : g[k])
            {
                if(rem(ei) == 0) continue;
                int to = e[ei].y;
                int w = e[ei].w;
                if(d[to] > d[k] + w)
                {
                    d[to] = d[k] + w;
                    p[to] = k;
                    pe[to] = ei;
                    if(!inq[to])
                    {
                        inq[to] = true;
                        q.push(to);
                    }
                }
            }
        }
        if(p[t] == -1 || d[t] >= 0) break;
        flow++;
        cost += d[t];
        int cur = t;
        while(cur != s)
        {
            e[pe[cur]].f++;
            e[pe[cur] ^ 1].f--;
            cur = p[cur];
        }
    }
    return make_pair(flow, cost);
}

void no_answer()
{
    cout << "Impossible" << endl;
    exit(0);
}

int main()
{                              
    cin >> n >> m;
    vector<int> excess_flow(n, 0);
    vector<int> orc(m);
    for(int i = 0; i < m; i++)
    {
        int x, y, c, w;
        cin >> x >> y >> c >> w;
        orc[i] = c;
        --x;
        --y;
        add_edge(x, y, c / 2, w);
        if(c % 2 == 1)
        {
            excess_flow[x]--;
            excess_flow[y]++;
        }
    }
    s = n;
    t = n + 1;
    v = n + 2;
    int total_excess = 0;
    if(excess_flow[0] % 2 == -1)
    {
        excess_flow[0]--;
        excess_flow[n - 1]++;
    }
    for(int i = 0; i < n; i++)
    {
        if(excess_flow[i] % 2 != 0)
            no_answer();
        int val = abs(excess_flow[i]) / 2;
        if(excess_flow[i] > 0)
        {
            total_excess += val;
            add_edge(s, i, val, -int(1e9));
        }
        if(excess_flow[i] < 0)
        {
            add_edge(i, t, val, -int(1e9));
        }
    }
    add_edge(s, 0, 100000, 0);
    add_edge(n - 1, t, 100000, 0);
    auto ans = MCMF();
    bool good_answer = true;
    for(int x = 0; x < e.size(); x++)
        if(e[x].w == -int(1e9) && rem(x) != 0)
            good_answer = false;
    if(!good_answer)
        no_answer();
    cout << "Possible" << endl;
    for(int i = 0; i < 2 * m; i += 2)
    {
        if(i) cout << " ";
        cout << e[i].f * 2 + orc[i / 2] % 2;
    }
    cout << endl;
}
```
