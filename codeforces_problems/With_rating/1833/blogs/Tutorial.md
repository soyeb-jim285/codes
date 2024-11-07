# Tutorial

[1833A - Musical Puzzle](../problems/A._Musical_Puzzle.md "Codeforces Round 874 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), prepared: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1833A - Musical Puzzle](../problems/A._Musical_Puzzle.md "Codeforces Round 874 (Div. 3)")

Let's construct the melody sequentially. In the first step, we can record the notes $s_1$ and $s_2$. In the next step, we need to record $s_2$ and $s_3$, because there must be a common symbol when gluing and so on. 

That is, we need to have recorded melodies $s_i$+$s_{i+1}$ for all $1 \le i < n$. We only need to count how many different ones among them, because we don't need to record one melody twice.

 **Solution**
```cpp
def solve():
    n = int(input())
    s = input()
    cnt = set()
    for i in range(1, n):
        cnt.add(s[i - 1] + s[i])
    print(len(cnt))


t = int(input())
for _ in range(t):
    solve()
```
[1833B - Restore the Weather](../problems/B._Restore_the_Weather.md "Codeforces Round 874 (Div. 3)")

Idea: [myav](https://codeforces.com/profile/myav "Pupil myav"), prepared: [myav](https://codeforces.com/profile/myav "Pupil myav")

 **Tutorial**
### [1833B - Restore the Weather](../problems/B._Restore_the_Weather.md "Codeforces Round 874 (Div. 3)")

Let's solve the problem using a greedy algorithm. 

Based on the array $a$, form an array of pairs {temperature, day number} and sort it in ascending order of temperature. Also sort the array $b$ in ascending order. Now, the values $a[i].first$ and $b[i]$ are the predicted and real temperature on day $a[i].second$.

Indeed, consider the minimum temperatures $b[1]$ and $a[1].first$. The difference between them is $t = |b[1] - a[1].first|$. If we consider the value $|b[i] - a[1].first|$ or $|b[1] - a[i].first|$ at $i \gt 1$, there will be at least $t$ since $a[1] \le a[i]$ and $b[1] \le b[i]$. 

Since it is guaranteed that it is possible to rearrange the elements in the array $b$, and the elements $b[1]$ and $a[1].first$ have the smallest difference, it is definitely not greater than $k$.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
void  solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>>a(n);
    vector<int>b(n), ans(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    for(auto &i : b) cin >> i;
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        ans[a[i].second] = b[i];
    }
    for(auto &i : ans) cout << i << ' ';
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}
```
[1833C - Vlad Building Beautiful Array](../problems/C._Vlad_Building_Beautiful_Array.md "Codeforces Round 874 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), prepared: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1833C - Vlad Building Beautiful Array](../problems/C._Vlad_Building_Beautiful_Array.md "Codeforces Round 874 (Div. 3)")

If all the numbers in the array already have the same parity, then for each $i$ it is sufficient to assign $b_i=a_i$.

Otherwise, it is impossible to make all the numbers even by leaving them positive, because the parity changes only when subtracting an odd number, and we cannot make the minimum odd number an even number. 

It remains only to make all numbers odd, that is, subtract odd numbers from even numbers. This can be done if the minimum number in the array is odd, because we can subtract it from every even number.

 **Solution**
```cpp
def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    if a[0] % 2 == 1:
        print("YES")
        return
    for i in range(n):
        if a[i] % 2 == 1:
            print("NO")
            return
    print("YES")


t = int(input())
for _ in range(t):
    solve()
```
[1833D - Flipper](../problems/D._Flipper.md "Codeforces Round 874 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40"), prepared: [Aris](https://codeforces.com/profile/Aris "Candidate Master Aris")

 **Tutorial**
### [1833D - Flipper](../problems/D._Flipper.md "Codeforces Round 874 (Div. 3)")

In these constraints we could solve the problem for $O(n^2)$. Let us note that there can be no more than two candidates for the value $r$. Since the first number in the permutation will be either $p_{r+1}$ if $r < n$, or $p_r$ if $r = n$. Then let's go through the value of $r$ and choose the one in which the first number in the resulting permutation is as large as possible. Next, if $p_n = n$, then we can have two candidates for $r$ is $n, n-1$, but note that it is always advantageous to put $r = n$ in that case, since it will not spoil the answer. Then we can go through $l$ and get the solution by the square, but we can do something smarter. 

Notice now that the answer already contains all the numbers $p_i$ where $i > r$. And then we write $p_r, p_{r-1}, \ldots, p_l$ where $l$ is still unknown, and then $p_1, p_2, \ldots, p_{l-1}$. In that case, let's write $p_r$ as $l \le r$ and then write $p_{r-1}, p_{r-2}, \ldots$ as long as they are larger than $p_1$. Otherwise, we immediately determine the value of $l$ and finish the answer to the end. Thus, constructively we construct the maximal permutation.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back



void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto &e : p) cin >> e;

    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (p[min(n-1, r+1)] <= p[min(n-1, i+1)]) {
            r = i;
        }
    }
    vector<int> ans;
    for (int i = r + 1; i < n; ++i) ans.eb(p[i]);
    ans.eb(p[r]);
    for (int i = r-1; i >= 0; --i) {
        if (p[i] > p[0]) {
            ans.eb(p[i]);
        } else {
            for (int j = 0; j <= i; ++j) {
                ans.eb(p[j]);
            }
            break;
        }
    }
    for (auto e : ans) cout << e << ' ';
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
```
[1833E - Round Dance](../problems/E._Round_Dance.md "Codeforces Round 874 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), prepared: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1833E - Round Dance](../problems/E._Round_Dance.md "Codeforces Round 874 (Div. 3)")

Let's build an undirected graph, draw the edges $i \to a_i$. Let's split this graph into connectivity components, denote their number by $k$. There could not be more than $k$ round dances.

Since the degree of each vertex is no more than two, the connectivity components are simple cycles and bamboos. If we connect the vertices of degree one in each bamboo, we get a partition into $k$ round dances.

Now let's try to get the minimum number of round dances. Nothing can be done with cycles, and all bamboos can be combined into one. If you get $b$ bamboos and $c$ cycles, then the answer is $\langle c + \min(b, 1), c + b \rangle$.

Time complexity is $O(n)$.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<set<int>> g(n);
    vector<set<int>> neighbours(n);
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        g[i].insert(a[i]);
        g[a[i]].insert(i);
    }
    for (int i = 0; i < n; ++i) {
        d[i] = g[i].size();
    }
    int bamboos = 0, cycles = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            vector<int> component = {i};
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v: g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                        component.push_back(v);
                    }
                }
            }
            bool bamboo = false;
            for (int j: component) {
                if (d[j] == 1) {
                    bamboo = true;
                    break;
                }
            }
            if (bamboo) {
                bamboos++;
            } else {
                cycles++;
            }
        }
    }
    cout << cycles + min(bamboos, 1) << ' ' << cycles + bamboos << 'n';
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        solve();
    }
}
```
[1833F - Ira and Flamenco](../problems/F._Ira_and_Flamenco.md "Codeforces Round 874 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40"), prepared: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

 **Tutorial**
### [1833F - Ira and Flamenco](../problems/F._Ira_and_Flamenco.md "Codeforces Round 874 (Div. 3)")

Reformulate the definition of magnificent dance. A dance $[x_1, x_2, \ldots, x_m]$ is called magnificent if there exists such a non-negative integer $d$ that $[x_1 - d, x_2 - d, \ldots, x_m - d]$ forms a permutation.

Let's build an array $b$ such that it is sorted, all the numbers in it are unique and each number from $a$ occurs in $b$. For each element $b_i$, set $c_i$ as its number of occurrences in the array $a$. This process is called coordinate compression. For example, if $a = [4, 1, 2, 2, 3]$, then $b = [1, 2, 3, 4]$, $ c = [1, 2, 1, 1]$.

Let the constructed array $b$ has length $k$. In every magnificent dance there is a dancer with a minimum level. Let's fix this minimal level in the array $b$, let its index be $i$, then the desired magnificent dance exists if $i + m \le k$ and $b_{i + m} = b_i + m - 1$.

If the desired magnificent dance exists, the number of such dances must be added to the answer, which is equal to $c_i \cdot c_{i + 1} \cdot \ldots \cdot c_{i + m}$. How to quickly calculate such a number?

1. Let's build prefix products $p_i = c_1 \cdot c_2 \cdot \ldots \cdot p_{i - 1}$. Then by Fermat's small theorem $c_i \cdot c_{i + 1} \cdot \ldots \cdot c_{i + m} = p_{i + m} \cdot p_i^{(10^9 + 7) - 2}$. Time complexity is $O(n \log C)$.
2. Let's build a segment tree on a product modulo. Time complexity is $O(n \log n)$ and we don't use that the module is prime.
3. We will use the idea of building a queue on two stacks, but we will support prefix products modulo in these stacks. Time complexity is $O(n)$ and we don't use that the module is prime.
 **Solution**
```cpp
/*
         `)
        _ 
      (( }/  ,_
      )))__ /
     (((---'
        '
        )|____.---- )
       /  `       (
      / '  `      )
     /  '    `   /
    /   '       _/
   /   _!____.-'
  /_.-'/    
     |`_    |`_
*/
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ipair;

const int MAXN = 200200;
const int MAXK = MAXN;
const int MOD = 1000000007;

inline int add(int a, int b) {
	return (a + b >= MOD ? a + b - MOD : a + b);
}

inline int mul(int a, int b) {
	return 1LL * a * b % MOD;
}

int n, m, k;
int arr[MAXN], brr[MAXN], cnt[MAXK];

void build() {
	sort(arr, arr + n);
	memcpy(brr, arr, sizeof(int) * n);
	k = unique(arr, arr + n) - arr;
	for (int j = 0; j < k; ++j)
		cnt[j] = upper_bound(brr, brr + n, arr[j]) - lower_bound(brr, brr + n, arr[j]);
}

inline void push(stack<ipair> &S, int x) {
	S.emplace(x, mul(x, S.empty() ? 1 : S.top().second));
}

int solve() {
	if (k < m) return 0;
	stack<ipair> S1, S2;
	for (int j = 0; j < m; ++j)
		push(S1, cnt[j]);
	int ans = 0;
	for (int j = m; j <= k; ++j) {
		if (arr[j - 1] - arr[j - m] == m - 1)
			ans = add(ans, mul(S1.empty() ? 1 : S1.top().second, S2.empty() ? 1 : S2.top().second));
		if (S2.empty()) {
			for (; !S1.empty(); S1.pop())
				push(S2, S1.top().first);
		}
		S2.pop();
		push(S1, cnt[j]);
	}
	return ans;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		build();
		cout << solve() << endl;
	}
}
```
[1833G - Ksyusha and Chinchilla](../problems/G._Ksyusha_and_Chinchilla.md "Codeforces Round 874 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40"), prepared: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

 **Tutorial**
### [1833G - Ksyusha and Chinchilla](../problems/G._Ksyusha_and_Chinchilla.md "Codeforces Round 874 (Div. 3)")

Let's hang the tree by the vertex $1$. This problem can be solved by dynamic programming. 

1. $dpc_v$ — the ability to cut a subtree of $v$ if the edges in all children of $v$ must be cut off.
2. $dpo_v$ — the ability to cut a subtree of $v$ if exactly one edge needs to be saved from $v$ to the child.
3. $dp_v$ — ability to cut a subtree of $v$ if an edge above $v$ is cut off.

Obviously, the answer will be $dp_1$. Recalculation in such dynamics is offered to the reader as an exercise.

There is a simpler greedy solution. Let's call light a vertex that is not a leaf and whose children are all leaves. Let's call heavy a vertex that is not a leaf and that has a light child.

If there is a light vertex with at least three children, the desired cut does not exist. If the light vertex $v$ has exactly one child, we will cut off all children from its parent except $v$. If the light vertex $v$ has exactly two children, we cut the edge into the parent $v$.

It is easy to understand that in this way the desired cut is restored uniquely. This problem can be solved by an elegant DFS, but the author considers BFS easier to understand.

First, let's count the number of children and the number of light children for each vertex. We will store all light vertices in the queue and process them sequentially. Cutting edges will change the number of children and the number of light children at some vertices. It should be handled carefully.

This solution works for $O(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ipair;

const int MAXN = 200200;

int n;
vector<ipair> gr[MAXN];
vector<int> res;
queue<int> qu;
int par[MAXN], ipar[MAXN], deg[MAXN], hard[MAXN];

void init() {
	res.clear();
	while (!qu.empty()) qu.pop();
	memset(deg, 0, sizeof(int) * n);
	memset(hard, 0, sizeof(int) * n);
	for (int v = 0; v < n; ++v)
		gr[v].clear();
}

void dfs(int v, int p, int ip) {
	par[v] = p;
	ipar[v] = ip;
	for (auto [u, i]: gr[v]) {
		if (u == p) continue;
		dfs(u, v, i);
		++deg[v];
		hard[v] += (deg[u] > 0);
	}
}

void build() {
	dfs(0, -1, -1);
}

bool rempar(int v) {
	int u = par[v];
	if (u == -1) return true;
	par[v] = -1;
	res.push_back(ipar[v]);
	--deg[u], --hard[u];
	if (deg[u]) {
		if (!hard[u]) qu.push(u);
		return true;
	}
	if (par[u] == -1) return false;
	--hard[par[u]];
	if (!hard[par[u]]) qu.push(par[u]);
	return true;
}

bool solve() {
	if (n % 3) return false;
	for (int v = 0; v < n; ++v)
		if (!hard[v] && deg[v]) qu.push(v);
	while (!qu.empty()) {
		int v = qu.front(); qu.pop();
		if (deg[v] > 2) return false;
		if (deg[v] == 2) {
			if (!rempar(v)) return false;
		} else if (deg[v] == 1) {
			if (par[v] == -1) return false;
			for (auto [u, i]: gr[par[v]]) {
				if (u == par[par[v]] || u == v || par[u] == -1) continue;
				if (!deg[u]) return false;
				res.push_back(i);
				par[u] = -1;
			}
			if (!rempar(par[v])) return false;
		}
	}
	return true;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n, init();
		for (int i = 1; i < n; ++i) {
			int v, u; cin >> v >> u, --v, --u;
			gr[v].emplace_back(u, i);
			gr[u].emplace_back(v, i);
		}
		build();
		if (!solve()) {
			cout << -1 << endl;
			continue;
		}
		cout << res.size() << endl;
		for (int id: res)
			cout << id << ' ';
		cout << endl;
	}
}
```
