# Tutorial

[1790A - Polycarp and the Day of Pi](../problems/A._Polycarp_and_the_Day_of_Pi.md "Codeforces Round 847 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1790A - Polycarp and the Day of Pi](../problems/A._Polycarp_and_the_Day_of_Pi.md "Codeforces Round 847 (Div. 3)")

In the problem, you had to find the largest common prefix(LCP) of the first $30$ characters of the number $\pi$ and the string $n$. To do this, we will go from the beginning and compare the characters until we find a non-matching one, or until the string $n$ ends.

 **Solution**
```cpp
t = int(input())
pi = '31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679'
for _ in range(t):
    n = input() + '#'
    for i in range(len(n)):
        if pi[i] != n[i]:
            print(i)
            break
```
[1790B - Taisia and Dice](../problems/B._Taisia_and_Dice.md "Codeforces Round 847 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

 **Tutorial**
### [1790B - Taisia and Dice](../problems/B._Taisia_and_Dice.md "Codeforces Round 847 (Div. 3)")

It is easy to find the value on the cube that the cat stole, it is equal $mx = s - r$. All other values must be no more than $mx$. Let's try to get $r$ by taking $mx$ $\lfloor\frac{r}{mx}\rfloor$ times and adding the remainder there if it is non-zero.

We could not get more than $n - 1$ cubes this way, because otherwise $(n - 1)mx > r$, but we are guaranteed that the answer exists. Now, until we get the $n-1$ cube, let's find the cube with the maximum value, reduce it by $1$ and add the cube with the value of $1$.

We can definitely get $n - 1$ dice, because otherwise $r < n - 1$, but we are guaranteed that the answer exists. It remains only to add a cube with the value of $mx$ to our $n-1$ cubes.

We obtained a solution with $O(n^2)$ asymptotics.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

int n, s1, s2;
vector<int> res;

void solve() {
	res.clear();
	int d = s1 - s2;
	for (; s2 >= d; s2 -= d)
		res.push_back(d);
	if (s2) res.push_back(s2);
	for (int i = 0; i < res.size() && res.size() + 1 < n;) {
		if (res[i] == 1) {
		    ++i;
		    continue;
		}
		--res[i];
		res.push_back(1);
	}
	res.push_back(d);
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> s1 >> s2;
		solve();
		sort(res.begin(), res.end());
		for (int x: res)
			cout << x << ' ';
		cout << endl;
	}
}
```
[1790C - Premutation](../problems/C._Premutation.md "Codeforces Round 847 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1790C - Premutation](../problems/C._Premutation.md "Codeforces Round 847 (Div. 3)")

When Kristina writes sequences on the whiteboard, she removes an element with each index exactly once. Thus, the first element of the permutation will be deleted only once — on the first step. All sequences except one will start with it

To solve the problem, find a sequence $p_i$ such that: 

* it starts with some element $y$
* all sequences other than this one begin with some element $x$

Then this permutation will describe the sequence of numbers remaining after removing the $1$th element, and the first element itself will be equal to the number $x$. The initial permutation will look like [$x, y = p_{i1}, p_{i2}, \dots, p_{in}$].

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
int n;

void solve(){
    cin >> n;
    vector<vector<int>>perm(n, vector<int>(n - 1));
    vector<int>p(n, 0);
    vector<int>cnt(n + 1, 0);
    for(int i = 0; i < n; i++){
        p[i] = i + 1;
        for(int j = 0; j < n - 1; j++){
            cin >> perm[i][j];
            if(j == 0) cnt[perm[i][j]]++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(cnt[i] == n - 1){
            p[0] = i;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(perm[i][0] != p[0]){
            for(int j = 0; j < n - 1; j++){
                p[j + 1] = perm[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++) cout << p[i] << ' ';
    cout << endl;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```
[1790D - Matryoshkas](../problems/D._Matryoshkas.md "Codeforces Round 847 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1790D - Matryoshkas](../problems/D._Matryoshkas.md "Codeforces Round 847 (Div. 3)")

First, for each size, let's count $cnt_s$ — the number of dolls of this size.

Then, let's create a set, in which for each doll of size $s$ we add the numbers $s$ and $s + 1$. This will allow you to process all the segments, as well as the dimensions adjacent to them.

We will iterate over the set in ascending order of size. Let $x$ be the number of matryoshkas of the current size, $y$ — of the previous one considered ($0$ at the beginning). If the numbers do not match, then you need to close (if $x < y$), or open (if $x > y$) $|x - y|$ segments. It is enough to add only the opening of the segments to the answer.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    set<int> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        b.insert(a[i]);
        b.insert(a[i] + 1);
    }
    int last = 0;
    int res = 0;
    for (auto x: b) {
        int c = cnt[x];
        res += max(0, c - last);
        last = c;
    }
    cout << res << 'n';
}

int main(int argc, char* argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}
```
[1790E - Vlad and a Pair of Numbers](../problems/E._Vlad_and_a_Pair_of_Numbers.md "Codeforces Round 847 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1790E - Vlad and a Pair of Numbers](../problems/E._Vlad_and_a_Pair_of_Numbers.md "Codeforces Round 847 (Div. 3)")

Consider the answer by bits. We know that if the $i$th bit of the number $x$ is zero, then these bits are the same for $a$ and $b$, otherwise they differ. Then let's first make $a = x$, $b = 0$. Note that $a\oplus b$ is already equal to $x$, but $\frac{a+b}{2}$ is not yet. So we need to dial another $x$ with matching bits, we will add them to both integers greedily, going from the highest bit to the lowest, skipping those bits that are already one in $a$. If after this algorithm $a$ and $b$ do not satisfy the conditions, then the answer is $-1$. In total, this solution works for $\mathcal{O}(\log{x})$.

You can see that in the solution above, we actually just added $\frac{x}{2}$ to both numbers, which could only be done with one set of bits, so if the answer exists, the pair $a= \frac{3\cdot x}{2} fits$, $b = \frac{x}{2}$.

 **Solution**
```cpp
t = int(input())
for _ in range(t):
    x = int(input())
    a = x
    b = 0
    for i in range(32, -1, -1):
        if x & (1 << i) > 0:
            continue
        if 2 * x - a - b >= (2 << i):
            a += 1 << i
            b += 1 << i
    if a + b == 2 * x and a ^ b == x:
        print(a, b)
    else:
        print(-1)
```
[1790F - Timofey and Black-White Tree](../problems/F._Timofey_and_Black-White_Tree.md "Codeforces Round 847 (Div. 3)")

Idea: [molney](https://codeforces.com/profile/molney "Candidate Master molney")

 **Tutorial**
### [1790F - Timofey and Black-White Tree](../problems/F._Timofey_and_Black-White_Tree.md "Codeforces Round 847 (Div. 3)")

Let's store for each vertex the minimum distance from it to the nearest black one, let's call it $d[v]$. We will also store the global answer, which for obvious reasons does not increase, we will call it $ans$.

Let's now color the vertex $c_i$, let's set $d[c_i] = 0$ and run a depth first search from it. This DFS will visit only the vertices $v$ with $d[v]<ans$. Let us consider the vertex $v$ and its neighbour $u$. If we can relax $d[u]$ through $d[v]+ 1$, let's do it and start from $u$. Otherwise, $u$ has a closer black neighbour, let's try to update the answer through it $ans = min(ans, d[v] +1 +d[u])$. Also, do not forget to update the answer via $d[v]$ from all black vertices $v$ that we visited.

The correctness of the algorithm is obvious, let's evaluate its time complexity. It is easy to notice that after the first $\lceil \sqrt n\rceil$ operations, $ans \le\lceil \sqrt n\rceil$. We enter only the vertices, $d$ from which, firstly, does not exceed $ans$, and secondly, was relaxed by the parent (that is, decreased by at least $1$).

So, we allowed ourselves a complete tree bypassing for the first $\lceil\sqrt n\rceil$ operations, and then amortized performed no more than $n\lceil\sqrt n\rceil$ operations. The final asymptotics will be $O(n\sqrt n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200200;
const int INF = 1e9;

int n, ANS = INF;
int crr[MAXN], dist[MAXN], res[MAXN];
bool clr[MAXN];
vector<int> gr[MAXN];

void init() {
	ANS = INF;
	for (int v = 0; v < n; ++v)
		gr[v].clear();
	fill(dist, dist + n, INF);
	memset(clr, 0, n);
}

void dfs(int v, int p) {
	if (dist[v] >= ANS) return;
	if (clr[v]) ANS = min(ANS, dist[v]);
	for (int u: gr[v]) {
		if (u == p) continue;
		if (dist[v] + 1 < dist[u]) {
			dist[u] = dist[v] + 1;
			dfs(u, v);
		} else ANS = min(ANS, dist[v] + 1 + dist[u]);
	}
}

void solve() {
	dist[*crr] = 0;
	dfs(*crr, -1);
	clr[*crr] = true;
	for (int i = 1; i < n; ++i) {
		dist[crr[i]] = 0;
		dfs(crr[i], -1);
		clr[crr[i]] = true;
		res[i] = ANS;
	}
}

int main() {
	int gorilla; cin >> gorilla;
	while (gorilla--) {
		cin >> n >> *crr, --(*crr);
		init();
		for (int i = 1; i < n; ++i)
			cin >> crr[i], --crr[i];
		for (int i = 1; i < n; ++i) {
			int v, u; cin >> v >> u, --v, --u;
			gr[v].push_back(u);
			gr[u].push_back(v);
		}
		solve();
		for (int i = 1; i < n; ++i)
			cout << res[i] << ' ';
		cout << 'n';
	}
}
```
[1790G - Tokens on Graph](../problems/G._Tokens_on_Graph.md "Codeforces Round 847 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> token(n), boni(n);
    vector<vector<int>> g(n);
    vector<int> good(n);
    int m;
    cin >> m;
    int p, b;
    cin >> p >> b;
    for(int i = 0; i < p; i++)
    {
        int x;
        cin >> x;
        --x;
        token[x] = 1;
    }
    for(int i = 0; i < b; i++)
    {
        int x;
        cin >> x;
        --x;
        boni[x] = 1;
    }
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 0; i < n; i++)
        for(auto x : g[i])
            if(boni[i] && boni[x]) good[i] = 1;
    set<int> good_tokens;
    set<int> not_so_good_tokens;
    for(int i = 0; i < n; i++)
        for(auto x : g[i])
        {
            if(token[i] && good[x]) good_tokens.insert(i);
            else if(token[i] && boni[x]) not_so_good_tokens.insert(i);
        }
    vector<int> d(n, int(1e9));
    queue<int> q;
    d[0] = 0;
    q.push(0);
    while(!q.empty())
    {
        int k = q.front();
        q.pop();
        for(auto x : g[k])
        {
            if(d[x] > d[k] + 1)
            {
                d[x] = d[k] + 1;
                if(boni[x]) q.push(x);
            }
        }
    }
    bool has_ans = false;
    for(int i = 0; i < n; i++)
    {
        if(!token[i] || d[i] > n) continue;
        has_ans |= (!good_tokens.empty() && (*good_tokens.begin() != i || *good_tokens.rbegin() != i));
        int cnt = not_so_good_tokens.size();
        if(not_so_good_tokens.count(i)) cnt--;
        has_ans |= d[i] <= 1 + cnt;
    }
    cout << (has_ans ? "YES" : "NO") << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tc = 1;
    cin >> tc;
    for(int i = 0; i < tc; i++)
    {
        solve();
    }
}
```
